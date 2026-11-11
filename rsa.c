#include <stdio.h>

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    int p = 13, q = 11;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 7;
    int d = 103;

    long long msg = 9;
    long long c = power(msg, e, n);
    long long m = power(c, d, n);

    printf("p = %d, q = %d\n", p, q);
    printf("Public Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d, n): (%d, %d)\n", d, n);
    printf("Original message: %lld\n", msg);
    printf("Encrypted message: %lld\n", c);
    printf("Decrypted message: %lld\n", m);

    return 0;
}
