#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char instr[100], crypt[100], decrypt[100];
    int shift, k;

    printf("\nEnter your string: ");
    fgets(instr, sizeof(instr), stdin);

    printf("\nEnter the shift value: ");
    scanf("%d", &shift);

    printf("\nOriginal string is: %s", instr);

    for (k = 0; instr[k] != '\0'; k++)
    {
        char aa = tolower(instr[k]);

        if (aa >= 'a' && aa <= 'z')
        {
            aa = ((aa - 'a' + shift) % 26) + 'a';
        }

        crypt[k] = aa;
    }

    crypt[k] = '\0';

    printf("\nEncrypted string is: %s", crypt);

    for (k = 0; crypt[k] != '\0'; k++)
    {
        char aa = crypt[k];

        if (aa >= 'a' && aa <= 'z')
        {
            aa = ((aa - 'a' - shift + 26) % 26) + 'a';
        }

        decrypt[k] = aa;
    }

    decrypt[k] = '\0';

    printf("\nDecrypted string is: %s", decrypt);

    return 0;
}