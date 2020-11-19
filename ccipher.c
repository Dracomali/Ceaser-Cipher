#include <stdio.h>
#include <string.h>

//defines boolean variables
#define TRUE 1
#define FALSE 0


// initializes variable keys
char alpha[30] = "abcdefghijklmnopqrstuvwxyz";
char beta[30] = "defghijklmnopqrstuvwxyzabc";
char inpt[255];

//prints help menu
void help()
{   
    printf("\n");
    printf("***         ALL OF THE COMMANDS    ***\n");
    printf("encrypt    -e                encyrpts typed data\n");
    printf("decrypt    -d                decrypts typed data\n");
    printf("help       -h                displays help menu\n\n");
    printf("Examples:\n");
    printf("         >: -e\n");
}

// encrypts data
void encrypt()
{
    //initializes empty character array the will become new word
    char wrd[255];
    int x = 0;

    // clears previous user input and prompts user for word
    memset(inpt, 0, strlen(inpt));
    printf(">Enter word: ");
    scanf("%s", inpt);

    // iterates through input, alpha, and beta character arrays
    for (int c = 0; alpha[c] != '\0'; c++)
    {
        for (int j = 0; beta[j] != '\0'; j++)
        {
            for (int v = 0; inpt[v] != '\0'; v++)
            {
                if (alpha[c] == inpt[v])
                {
                    // adds corresponding letter to wrd starting from index 0
                    wrd[x] = beta[c];
                    x++;
                }

                else
                {
                    break;
                }
                
                
                
            }
        }
    }

    // prints encrypted word
    printf("%s\n", wrd);

}


int main(void)
{ 
    // prompts user for input
    printf("Welcome to ccipher 0.0! This is a program to decode Caeser Ciphers.\n");
    
    
    while(TRUE)
    {
        memset(inpt, 0, strlen(inpt));
        printf(">:");
        scanf("%s", inpt);

        if (strcmp(inpt, "-e") == 0)
        {
            encrypt();
            break;
        }

        else if (strcmp(inpt, "-d") == 0)
        {
            printf("decrypt\n");
            break;
        }

        else
        {
            help();
        }
    }

    return 0;
}