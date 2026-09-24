#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int isPrime(int n)
{
    int i;

    if (n <= 1)
        return 0;

    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int generatePrime()
{
    int num;

    do
    {
        num = rand() % 100 + 2;
    }
    while (!isPrime(num));

    return num;
}

int calculateE(int phi)
{
    int e = 2;

    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;

        e++;
    }

    return e;
}

int calculateD(int e, int phi)
{
    int d = 1;

    while ((d * e) % phi != 1)
    {
        d++;
    }

    return d;
}

int encrypt(int plaintext, int e, int n)
{
    int cipher = 1;

    for (int i = 0; i < e; i++)
    {
        cipher = (cipher * plaintext) % n;
    }

    return cipher;
}

int decrypt(int ciphertext, int d, int n)
{
    int plaintext = 1;

    for (int i = 0; i < d; i++)
    {
        plaintext = (plaintext * ciphertext) % n;
    }

    return plaintext;
}

int main()
{
    int p, q, n, phi, e, d;
    int plaintext = 88;
    int ciphertext, decryptedText;

    srand(time(NULL));

    p = generatePrime();

    do
    {
        q = generatePrime();
    }
    while (q == p);

    n = p * q;

    phi = (p - 1) * (q - 1);

    e = calculateE(phi);

    d = calculateD(e, phi);

    ciphertext = encrypt(plaintext, e, n);

    decryptedText = decrypt(ciphertext, d, n);

    printf("Plaintext: %d\n", plaintext);
    printf("Ciphertext: %d\n", ciphertext);
    printf("Decrypted text: %d\n", decryptedText);

    return 0;
}