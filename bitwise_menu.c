#include <stdio.h>

int main() {
    char str[] = "Hello World";
    int choices[] = {1, 2, 3};

    for (int c = 0; c < 3; c++) {
        int choice = choices[c];
        switch (choice) {
            case 1:
                printf("AND operation: ");
                for (int i = 0; str[i] != '\0'; i++) printf("%c", str[i] & 127);
                printf("\n");
                break;
            case 2:
                printf("OR operation: ");
                for (int i = 0; str[i] != '\0'; i++) printf("%c", str[i] | 127);
                printf("\n");
                break;
            case 3:
                printf("XOR operation: ");
                for (int i = 0; str[i] != '\0'; i++) printf("%c", str[i] ^ 127);
                printf("\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
