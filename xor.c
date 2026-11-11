#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "HelloWorld";
    char key = 'K';
    int len = strlen(str);

    printf("Original: %s\n", str);

    for (int i = 0; i < len; i++) {
        str[i] = str[i] ^ key;
    }
    printf("Encrypted: %s\n", str);

    for (int i = 0; i < len; i++) {
        str[i] = str[i] ^ key;
    }
    printf("Decrypted: %s\n", str);

    return 0;
}
