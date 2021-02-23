#include <stdio.h>
#include <string.h>
#include "algorithms.h"

int main(void)
{
    char *action = getinput("cipher/decipher: ");
    if(strcmp(action, "cipher") == 0)
    {
        char *key = getinput("Key: ");
        cipher(key);
        free(key);
    }
    else if(strcmp(action, "decipher") == 0)
    {
        char *key = getinput("Key: ");
        decipher(key);
        free(key);
    }
    else
    {
        printf("Please Enter Cipher or Decipher.\n");
        return 1;
    }
    printf("Press Enter To Exit...");
    getchar();
}