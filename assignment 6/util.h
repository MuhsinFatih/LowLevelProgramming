#pragma once
#define true 1
#define false 0
#include <stdbool.h>



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