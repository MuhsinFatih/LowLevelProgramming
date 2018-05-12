#include <stdlib.h>

char **split(char *s) {
    char *res[5];
    size_t k = 0, ri = 0;
    for(int i=0; i<strlen(s); ++i) {
        res[i] = (char*)malloc(50*sizeof(char));
        if(s[i] == ',') {
            ri = 0;
        } else {
            res[k][ri++] = s[i];
        }
        ++k;
    }
    return res;
}

int main() {
    char* test = "apple, banana, cherry";
    char ** asdf = split(test);
    for(int i = 0;i < 3;i++)
    {
        printf("%s\n", asdf);
    }

}