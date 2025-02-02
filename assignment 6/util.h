#pragma once
#define true 1
#define false 0
#include <stdbool.h>
#include <time.h>


bool is_stringAlphaNumeric(char *str);

bool is_stringNumeric(char *str);

/** 
 * @brief  Check if TUID is valid
 * @param  tuid: temple id number in format (example): 912086676
 * @retval returns true (1) if TUID is valid
 */
bool isValidTUID(char* tuid);

/** 
 * @brief  Check if accessnet id is valid
 * @param  *accessNet: accessnet id in format (example): tub56820
 * @retval returns true (1) if accessnet id is valid
 */
bool isValidAccessNetID(char *accessNet);

/** 
 * @brief  Check if name is valid
 * @param  *name: name as a string
 * @retval returns true (1) if name is valid
 */
bool isValidName(char *name);

/** 
 * @brief  construct full name using name array and surname
 * @param  buffer: address to write full name
 * @param  **name: name (*char[2])
 * @param  surname: surname (*char)
 * @retval None
 */
void makeFullName(char * tuid, char * buffer, char **name, char * surname);

void printStudentInfo(char * fullname, char * preferred_name, char * tuid, char * accessNetId);

/** 
 * @brief  get time in YYYYMMDD format
 * @note   
 * @retval time as string (YYMMDD)
 */
char * getTimeAsString();


/** 
 * @brief  get size of any array. Assumes the array is null terminated
 * @param  anyting: an array of any type
 * @param  typeSize: size of one item in the array
 * @retval size of array
 */
// size_t get_size(void * anything);

/** 
 * @brief  log tuid and resource id's to given file
 * @note   
 * @param  filename: file name relative to workspace path
 * @param  tuid: tuid of the person
 * @param  resource_ids: resources the person has access to
 * @retval 
 */
bool logToFile(char * filename, char * tuid, char * resource_ids);

/** 
 * @brief  return role ids
 * @note   
 * @param  tuid: 
 * @retval returns new pointer for role_ids
 */
char **get_role_ids(char* tuid);


char** get_resources(int *role_size, char** role_ids);