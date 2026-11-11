#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main()
{
    char instr[100], encrypt[100], decrypt[100];
    int shift, k;

    printf("Enter your string: ");
    fgets(instr, sizeof(instr), stdin);

    printf("Enter your key: ");
    scanf("%d", &shift);

    printf("\nOriginal string is: %s", instr);

    for (k = 0; instr[k] != '\0'; k++)
    {
        char aa = tolower(instr[k]);

        if (aa >= 'a' && aa <= 'z')
        {
            aa = ((aa - 'a' + shift) % 26) + 'a';
        }

        encrypt[k] = aa;
    }

    encrypt[k] = '\0';

    printf("\nEncrypted string is: %s", encrypt);

    for (k = 0; encrypt[k] != '\0'; k++)
    {
        char aa = encrypt[k];

        if (aa >= 'a' && aa <= 'z')
        {
            aa = ((aa - 'a' - shift + 26) % 26) + 'a';
        }

        decrypt[k] = aa;
    }

    decrypt[k] = '\0';

    printf("\nDecrypted string is: %s", decrypt);
}
