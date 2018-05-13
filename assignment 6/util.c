#include "db_helper.h"
#include "util.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

bool is_stringAlphaNumeric(char *str) {
    do{
        if(!isalnum(*str)) return false;
    } while(*(++str) != '\0');
    return true;
}
bool is_stringNumeric(char *str) {
    do{
        if(!isnumber(*str)) return false;
    } while(*(++str) != '\0');
    return true;
}
bool isValidTUID(char* tuid) {
    return (is_stringNumeric(tuid) && strlen(tuid) == 9);
}

bool isValidAccessNetID(char *accessNet) {
    return is_stringAlphaNumeric(accessNet);
}

bool isValidName(char *name) {
    return is_stringAlphaNumeric(name);
}

void makeFullName(char * tuid, char * buffer, char **name, char * surname) {
    name[0] = getValue("person_names",tuid, 0,1)[0];
	name[1] = getValue("person_names",tuid, 0,2)[0];
	surname = getValue("person_names",tuid, 0,3)[0];
    char * fullnameFormatting = malloc(strlen("%%s%s%%s %%s") + 1);
	sprintf(fullnameFormatting, "%%s%s%%s %%s",name[1] != "\0" ? " " : "");
	sprintf(buffer, fullnameFormatting, name[0], name[1], surname);
}


void die(char * message) {
    puts(message);
    exit(0);
}

void printStudentInfo(char * fullname, char * preferred_name, char * tuid, char * accessNetId) {
    printf("Student Info:\n");
    printf("\tName&Surname: %s\n",fullname);
	printf("\tPreferred name: %s\n", preferred_name);
	printf("\ttuid: %s\n", tuid);
	printf("\taccessnet ID: %s\n", accessNetId);
}


char * getTimeAsString() {
    char *datename = malloc(9);
	struct tm* to;
	time_t t;
	t = time(NULL);
	to = localtime(&t);
	strftime(datename, sizeof(datename), "%Y%m%d", to);
	return datename;
}


bool logToFile(char * filename, char * tuid, char * txt) {
    FILE *f = fopen(filename, "w+");
    if(f==NULL) return false;
    fprintf(f, "%s has access to:%s\n", tuid, txt);
    fclose(f);
    return true;
}

char** get_role_ids(char* tuid) {

    char **bad_role_ids = getValue("person_roles", tuid, 0, 1);
    char **role_expiration_dates = getValue("person_roles", tuid, 0, 2);
	size_t role_size = -1; while(bad_role_ids[++role_size] != '\0');
    char** role_ids = (char**) malloc(role_size);

	bool * expiryList = (bool*) malloc(role_size * sizeof(bool));
	size_t i = 0;
	size_t c = 0;
	char *a = getTimeAsString();
	int t = atoi(a);
	while(bad_role_ids[i] != '\0') {
		puts(bad_role_ids[i]);
		expiryList[i] = t > atoi(role_expiration_dates[i]);
		if(expiryList[i]) {
            role_ids[c++] = bad_role_ids[i];
        }
		++i;
	}
    role_ids[c] = '\0';
    return role_ids;
}
char** get_resources(int *role_size, char** role_ids) {
    int i;
    char **resources = (char**) malloc((int)role_size * sizeof(char*) + 1);
	for(i = 0;i < (int)role_size + 1;++i){ resources[i] = '\0'; }
	size_t r = 0;
	for(i = 0;i < (int)role_size;i++)
	{
		char * role = role_ids[i];
		char ** newresource = getValue("resources_roles", role,1,0);
		int j = -1;
		while(newresource[++j] != '\0') {
			int k = -1;
			bool flag = true;
			while(resources[++k] != '\0') {
				if(!strcmp(resources[k], newresource[j])) {
					flag = false;
					break;
				}
			}
			if(flag) {
				resources[r++] = newresource[j];
				flag = true;
			}
		}
	}
    role_size = r;
    return resources;
}
// size_t get_size(void * anything, size_t typeSize) {
//     size_t i = 0;
//     void* newaddr = anything;
//     while(newaddr != NULL) {
//         newaddr = ((anyting)+(++i)*typeSize);
//     }
//     return i;
// }

// size_t get_size(void * anything) {
//     size_t i = 0;
//     void* newaddr = anything;
//     while(newaddr != NULL) {
//         newaddr = &(anything[++i]);
//     }
//     return i;
// }