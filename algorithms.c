#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

char* getinput(char *question)
{
    #define CHUNK 200
    printf("%s", question);
    char *input = NULL;
    char tempbuf[CHUNK];
    size_t inputlen = 0, templen = 0;
    do
    {
        fgets(tempbuf, CHUNK, stdin);
        templen = strlen(tempbuf);
        input = realloc(input, inputlen + templen + 1);
        strcpy(input + inputlen, tempbuf);
        inputlen += templen;
    }
    while (templen == CHUNK - 1 && tempbuf[CHUNK - 2]!='\n');
    input[strlen(input) - 1] = 0;
    return input;
}

void cipher(char *alphabet)
{
    //Find Errors in Key
    if (strlen(alphabet) != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(alphabet[i]) == false)
        {
            printf("Key must only contain letters.\n");
            exit(1);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        alphabet[i] = toupper(alphabet[i]);
    }
    //Counts each character present in the alphabet by first initializing counter
    for (int i = 0; i < strlen(alphabet); i++)
    {
        for (int j = i + 1; j < strlen(alphabet); j++)
        {  
            if (alphabet[i] == alphabet[j])
            {  
                printf("Key must not contain repeated characters.\n");
                exit(1);
            }  
        }
    }
    //Asks User for Input
    char *plaintext = getinput("plaintext: ");
    //Reserves memory for ciphertext
    char *ciphertext = malloc(strlen(plaintext));
    //Sets plaintext as ciphertext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        ciphertext[i] = plaintext[i];
    }
    //Converts Each Letter individually
    for (int i = 0; i < strlen(ciphertext); i++)
    {
        //Checks if it is a Alphabetic Character(letter)
        if (isalpha(ciphertext[i]))
        {
            //Converts to uppercase
            ciphertext[i] = toupper(ciphertext[i]);
            //Applies Alphabet
            ciphertext[i] = alphabet[(int)ciphertext[i] - 65];
            //Checks if the input was lowercase, and if so converts it back
            if (islower(plaintext[i]))
            {
                ciphertext[i] = tolower(ciphertext[i]);
            }
        }
    }
    //Gives Result
    printf("ciphertext: %s\n", ciphertext);
    free(plaintext);
    free(ciphertext);
}

void decipher(char *alphabet)
{
    if (strlen(alphabet) != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(alphabet[i]) == false)
        {
            printf("Key must only contain letters.\n");
            exit(1);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        alphabet[i] = toupper(alphabet[i]);
    }
    //Counts each character present in the alphabet by first initializing counter
    for (int i = 0; i < strlen(alphabet); i++)
    {
        for (int j = i + 1; j < strlen(alphabet); j++)
        {  
            if (alphabet[i] == alphabet[j])
            {
                printf("Key must not contain repeated characters.\n");
                exit(1);
            }  
        }
    }
    char *jumbled = getinput("jumbled: ");
    int size = strlen(jumbled);
    char *deciphered = malloc(size);
    for(int i = 0; i < size; i++)
    {
        deciphered[i] = toupper(jumbled[i]);
    }
    for(int i = 0; i < size; i++)
    {
        if(isalpha(deciphered[i]))
        {
            for(int j = 0; j < 26; j++)
            {
                if(deciphered[i] == alphabet[j])
                {
                    deciphered[i] = j + 65;
                    break;
                }
            }
            if (islower(jumbled[i]))
                {
                    deciphered[i] = tolower(deciphered[i]);
                }
        }
    }
    printf("%s\n", deciphered);
    free(jumbled);
    free(deciphered);
}
