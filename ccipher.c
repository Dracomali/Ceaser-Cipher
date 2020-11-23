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
    printf("exit        exit             exits the program");
    printf("help       -h                displays help menu\n\n");
    printf("Examples:\n");
    printf("         >: ccipher-e\n");
}

// encrypts data
void encrypt()
{
    //initializes empty character array the will become new word
    char wrd[255];
    int x = 0;

    // clears previous user input and prompts user for word
    memset(inpt, 0, strlen(inpt));
    memset(wrd, 0, strlen(wrd));
    printf(">Enter word: ");
    scanf("%s", inpt);

    // iterates through input, alpha, and beta character arrays
    for (int v = 0; inpt[v] != '\0' && v <= strlen(inpt); v++)
    {
        for (int c = 0; alpha[c] != '\0'; c++)
        {
                
            if (alpha[c] == inpt[v])
            {
                // adds corresponding letter to wrd starting from index 0
                wrd[x] = beta[c];
                x++;
            }      
                
        }
    }

    printf("%s\n", wrd);
}

// decrypts data
void decrypt()
{
    char wrd[255];
    int x = 0;

    // clears previous user input and prompts user for word
    memset(inpt, 0, strlen(inpt));
    memset(wrd, 0, strlen(wrd));
    printf(">Enter word: ");
    scanf("%s", inpt);

     for (int v = 0; inpt[v] != '\0' && v <= strlen(inpt); v++)
    {
        for (int c = 0; beta[c] != '\0'; c++)
        {
     
            if (beta[c] == inpt[v])
            {
                // adds corresponding letter to wrd starting from index 0
                wrd[x] = alpha[c];
                x++;
            }
        }
    }


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

        if (strcmp(inpt, "ccipher-e") == 0)
        {
            encrypt();
        }

        else if (strcmp(inpt, "ccipher-d") == 0)
        {
            decrypt();
        }

        else if (strcmp(inpt, "exit") == 0)
        {
            break;
        }

        else
        {
            help();
        }
    }

    return 0;
}

