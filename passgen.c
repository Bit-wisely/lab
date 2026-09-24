#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define STRING_LENGTH 16

/*
 * Generates a random string containing uppercase letters, lowercase letters,
 * numbers, and special symbols that resembles a hashed password / secret token.
 */
void generate_random_string(char *output, int length)
{
    const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lower[] = "abcdefghijklmnopqrstuvwxyz";
    const char digits[] = "0123456789";
    const char symbols[] = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    // Combine all character sets into one pool
    char all[sizeof(upper) + sizeof(lower) + sizeof(digits) + sizeof(symbols)];
    snprintf(all, sizeof(all), "%s%s%s%s", upper, lower, digits, symbols);

    int upper_len = strlen(upper);
    int lower_len = strlen(lower);
    int digits_len = strlen(digits);
    int symbols_len = strlen(symbols);
    int all_len = strlen(all);

    // Guarantee at least one character from each required category
    output[0] = upper[rand() % upper_len];
    output[1] = lower[rand() % lower_len];
    output[2] = digits[rand() % digits_len];
    output[3] = symbols[rand() % symbols_len];

    // Fill the remaining characters randomly from the combined pool
    for (int i = 4; i < length; i++)
    {
        output[i] = all[rand() % all_len];
    }

    // Shuffle characters using Fisher-Yates algorithm for uniform distribution
    for (int i = length - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }

    output[length] = '\0';
}

int main(void)
{
    char password[STRING_LENGTH + 1];

    // Seed the pseudo-random number generator with the current time
    srand((unsigned int)time(NULL));

    generate_random_string(password, STRING_LENGTH);

    printf("==============================================\n");
    printf(" Generated 16-Character Random String / Hash \n");
    printf("==============================================\n");
    printf("Output : %s\n", password);
    printf("Length : %zu characters\n", strlen(password));
    printf("==============================================\n");

    return 0;
}
