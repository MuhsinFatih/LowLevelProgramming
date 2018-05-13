#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "db_helper.h"
#include <stdbool.h>
#include "util.h"
#include <time.h>
/***************************************************************************
  Instructions:
     1. You can choose either 1a or 1b. You do not to need to do both,
        just one. 
       a. Look at all accounts and determine which have access
	      to which resources.
	   b. Have your program read a person's TUid from STDIN
	      (i.e. accept it as a command line argument) and then
              determine the resources to which that TUid has access.

        Note that if someone has an expiration date that is in the
        past for a role in the person_roles table, you can stop any
        further processing for that role since it is no longer
        applicable.

        However, be careful. Make sure that you keep in mind that just
        because an individual has an expired role, it does not mean that
        all of their roles have expired. The unique combination here
        is the role_id in conjunction with the TUid, not just the TUid. 
        
	To help you get the data that you need from the database
	files, I've included in db_helper.c a function called
	getValue. Please see that file for a description of the
	function parameters and the details of the actions
	performed.

	If you decide to read a person's TUid from STDIN rather than
	evaluating all accounts, you will need to include a check that
	makes sure the TUid entered is valid. Valid TUids are 9
	characters long and may contain only alpha and numeric
	characters.

     2. In the previous step, you determined whether or not either the
	TUid entered or each TUid in the the list of all TUids in the
	database is entitled to each resource. Now you will need to
	log this information in either a log file or in a table in the
	database. Whichever you choose to do, all I am requiring you
	to log is the the list of TUid and resource ids for the
	resources to which they are entitled. I have given you the
	database table, named person_resource. 

	************************************************************
	***************** #3 is no longer required *****************
	************************************************************
     3. Lastly, for each resource, "send" to the resource a list of
	all entitled TUids. By "send", I mean write all of these 
        TUids to the file named after that resource (tumail, canvas,
	ldap). You should write one TUid per line.
	************************************************************
	************************************************************

     Additional Requirements:
        a. You are to create a new c source file (feel free to name it
           anything you'd like and you'll want to remember to include
	   db_helper.h) and include any functions that you write to
	   implement the functionality discussed above. Please attempt
	   to write modular code and do not just write a long stream of
	   code in the main function. You may add to the file
	   db_helper.c if you are implementing one of the functions I
	   defined in db_helper.h. Please note that you only need to
	   implement the functions that you find you need for the
	   assignment. Any others I defined in that header file do not
	   need to be implemented. I included way more than you will
	   need, just to give you a jump start if you wanted to look
	   further into it than is required.
	b. Use this main.c file and the main function only to test your
           code. Again, all of the actual functionality should be
	   written in a separate .c file (optionally include a .h with
	   all of your function declarations and global variable
	   declarations, if applicable). I've included one test to
	   grab the resource_id for the tumail resource. You should
	   include additional tests to demonstrate that your code
	   works end-to-end.

     Compiling your project:
        cd /path/to/extracted/project/files/
	gcc -o myProjectName db_helper.c yourFileName.c main.c

     BONUS POINTS (up to 25 possible):
	It is possible for you to earn bonus points by going beyond
	the basic requirements of this assignment. Some additional
	things you could do to earn bonus points are described below. 

	You can choose to do as many or as few of the below as
	you'd like. Also, if there is anything not described below
	that you would like to implement in your program that goes
	beyond the basic requirements, I am open to the possibility of
	awarding bonus points for this as well

        For anything beyond what's below, I recommend that you come
	speak with me or your TA in person about it prior to
	submitting the assignment or that at the very least you write
	both myself and your TA an email in which you should briefly
	describe the additional piece that you have added. Otherwise,
	I cannot guarantee that we will catch it when we grade your
	submission and award bonus points for it.
	   
	Optional functionality:
	   a. Instead of just assuming that the TUid is the id that the
	      resource accepts, look in the table resource_requirements
	      to see whether it wants the TUid or the AccessNet and
	      then send whichever each resource requires.
	   b. In addition to sending the person's id (i.e. the person's
	      TUid or AccessNet) also send the person's name. It is
	      okay to assume that either all accept preferred name or
	      all accept full name (first, middle, and last).
	   c. In addition to b, you may also choose to look in the
	      table resource_requirements to see whether or not the
	      resource wants the full name or the preferred name and
	      then send whichever is required by each resource.
       d. Rewrite/revise any number of the functions that I provided to
	      you. These were written with the sole purpose of
	      demonstrating specific concepts, which meant that I
	      needed to sacrifice efficiency and better organization of the
	      code in some places.
***************************************************************************/
int main(int argc, char **argv)
{
	
	char * tuid; int id_size = 0;
	char * accessNetId;
	char * name[2];
	char * surname;
	char * fullname;
	char * preferred_name;
	puts("Enter your tuid or accessnet ID:\n");
	getline(&tuid, &id_size, stdin);
	id_size = strlen(tuid);
	if(tuid[id_size-1] == '\n') tuid[id_size-1] = 0; // apparently getline function includes the newline character from stdin
	// determine tuid and accessnet id
	if(!is_stringNumeric(tuid)) {
		accessNetId = malloc(id_size);
		strcpy(accessNetId,tuid);
		if(!isValidAccessNetID(accessNetId)) die("invalid id!\n");
		tuid = getValue("person_ids", accessNetId, 1,0)[0];
	} else {
		if(!isValidTUID(tuid)) die("invalid id!\n");
		accessNetId = getValue("person_ids", tuid, 0, 1)[0];
	}

	preferred_name = getValue("person_names",tuid, 0,4)[0];
	makeFullName(tuid, fullname, name, surname);
	printStudentInfo(fullname, preferred_name, tuid, accessNetId);

	char ** role_ids = get_role_ids(tuid);

	int role_size = -1; while(role_ids[++role_size] != '\0');

	char **role_names = (char**) malloc(role_size * sizeof(char*) + 1);
	printf("%s, you are:\n", preferred_name);
	int i;
	for(i = 0;i < role_size;i++)
	{
		role_names[i] = getValue("roles",role_ids[i],0,1)[0];
		printf("\t%s\n", (role_names[i]));
	}

	// get resources
	char **resources = get_resources(role_size, role_ids);
	char *txt = malloc(255);
	printf("You have access to:\n");
	// get resource names
	char ** resource_names = malloc(role_size * sizeof(char*));
	for(i = 0;i < role_size + 1;i++) resource_names[i] = '\0';
	i = -1;
	while(resources[++i] != '\0'){
		resource_names[i] = getValue("resources",resources[i],0,1)[0];
		puts(resource_names[i]);
		strcat(txt, " ");
		strcat(txt, resources[i]);
	}
	
	char* filename = "logfile.log";
	if(logToFile(filename, tuid, txt)) {
		printf("Saved permissions in %s\n", filename);
	} else printf("There was a problem with the file. Make sure no other program is using the file and that file is not read-only\n");

	printf("I am not sure why, but although code runs successfully, sometimes it gives a segfault after the exit function. Code has finished\n");
	return 0;
}
