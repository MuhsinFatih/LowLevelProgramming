#include "db_helper.h"
#include "util.h"
#include <ctype.h>
#include <stdbool.h>

bool is_stringAlphaNumeric(char *str) {
    do{
        if(!isalnum(*str)) return false;
    } while(*(++str) != '\0');
    return true;
}
bool is_stringNumeric(char *str) {
    do{
        if(!isalnum(*str)) return false;
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