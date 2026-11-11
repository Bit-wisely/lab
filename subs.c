#include<stdio.h>

char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";

char substitution[26] = "zyxwvutsrqponmlkjihgfedcba";

void encrypt()
{
    char plaintext[100];

    printf("Enter the message: ");
    scanf("%s", plaintext);

    for(int i = 0; plaintext[i] != '\0'; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(plaintext[i] == alphabet[j])
            {
                plaintext[i] = substitution[j];
                break;
            }
        }
    }

    printf("Encrypted message: %s\n", plaintext);
}

void decrypt()
{
    char ciphertext[100];

    printf("Enter Cipher text: ");
    scanf("%s", ciphertext);

    for(int i = 0; ciphertext[i] != '\0'; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(ciphertext[i] == substitution[j])
            {
                ciphertext[i] = alphabet[j];
                break;
            }
        }
    }

    printf("Decrypted message: %s\n", ciphertext);
}

int main()
{
    int choice;

    do
    {
        printf("\n 1. ENCRYPT 2. DECRYPT 3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                encrypt();
                break;

            case 2:
                decrypt();
                break;

            case 3:
                printf("exiting\n");
                break;

            default:
                printf("Invalid choise\n");
                break;
        }

    }while(choice != 3);

    return 0;
}
