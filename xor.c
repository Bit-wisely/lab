int main()
{
    int i;
    char message[] = "Hello World";
    int key = 5;

    for(i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] ^ key;
    }

    printf("XOR: %s\n", message);

    for(i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] ^ key;
    }

    printf("Original: %s\n", message);

    return 0;
}