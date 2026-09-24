#include <stdio.h>
#include <string.h>

int main()
{
    int key[2][2], inverse[2][2];
    char plaintext[100], ciphertext[100], decrypted[100];
    int i, j, len;

    printf("Enter 2x2 key matrix");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            scanf("%d", &key[i][j]);
    }

    printf("Enter inverse key matrix");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            scanf("%d", &inverse[i][j]);
    }

    printf("Enter plaintext (uppercase, even length): ");
    scanf("%s", plaintext);

    len = strlen(plaintext);

    // Encryption
    for (i = 0; i < len; i += 2)
    {
        int p1 = plaintext[i] - 'A';
        int p2 = plaintext[i + 1] - 'A';

        ciphertext[i] =
            ((key[0][0] * p1 + key[0][1] * p2) % 26) + 'A';

        ciphertext[i + 1] =
            ((key[1][0] * p1 + key[1][1] * p2) % 26) + 'A';
    }

    ciphertext[len] = '\0';

    printf("\nCiphertext: %s\n", ciphertext);

    // Decryption
    for (i = 0; i < len; i += 2)
    {
        int c1 = ciphertext[i] - 'A';
        int c2 = ciphertext[i + 1] - 'A';

        decrypted[i] =
            ((inverse[0][0] * c1 + inverse[0][1] * c2) % 26) + 'A';

        decrypted[i + 1] =
            ((inverse[1][0] * c1 + inverse[1][1] * c2) % 26) + 'A';
    }

    decrypted[len] = '\0';

    printf("Decrypted text: %s\n", decrypted);

    return 0;
}