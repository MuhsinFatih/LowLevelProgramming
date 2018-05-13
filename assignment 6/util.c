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
    char datename[32];
	struct tm* to;
	time_t t;
	t = time(NULL);
	to = localtime(&t);
	strftime(datename, sizeof(datename), "%Y%m%d", to);
	return datename;
}

int get_resources(char ** resources, char ** role_ids) {

}

bool logToFile(char * filename, char * tuid, char * txt) {
    FILE *f = fopen(filename, "w+");

    fprintf(f, "%s has access to:%s\n", tuid, txt);
    fclose(f);
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