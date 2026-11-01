#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 2048
#define MAX_KEY 256

void remove_newline(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

int valid_key(const char *key)
{
    if (strlen(key) == 0)
        return 0;

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isalpha((unsigned char)key[i]))
            return 0;
    }

    return 1;
}

void veil_encrypt(const char *text, const char *key, char *result)
{
    int key_length = strlen(key);
    int key_index = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        unsigned char ch = (unsigned char)text[i];

        if (isalpha(ch))
        {
            int base = isupper(ch) ? 'A' : 'a';

            int p = toupper(ch) - 'A';
            int k = toupper((unsigned char)key[key_index % key_length]) - 'A';

            int encrypted = (p + k) % 26;

            result[i] = (char)(encrypted + base);

            key_index++;
        }
        else
        {
            result[i] = text[i];
        }
    }

    result[strlen(text)] = '\0';
}

void veil_decrypt(const char *text, const char *key, char *result)
{
    int key_length = strlen(key);
    int key_index = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        unsigned char ch = (unsigned char)text[i];

        if (isalpha(ch))
        {
            int base = isupper(ch) ? 'A' : 'a';

            int c = toupper(ch) - 'A';
            int k = toupper((unsigned char)key[key_index % key_length]) - 'A';

            int decrypted = (c - k + 26) % 26;

            result[i] = (char)(decrypted + base);

            key_index++;
        }
        else
        {
            result[i] = text[i];
        }
    }

    result[strlen(text)] = '\0';
}

int main(void)
{
    char text[MAX_TEXT];
    char key[MAX_KEY];
    char result[MAX_TEXT];

    int choice;

    printf("\n");
    printf("================================\n");
    printf("          VEIL-19 v1.0          \n");
    printf("     Personal Encoding System   \n");
    printf("================================\n");

    printf("\n");
    printf("[1] Encrypt\n");
    printf("[2] Decrypt\n");
    printf("[0] Exit\n");

    printf("\nSelect operation: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid choice.\n");
        return 1;
    }

    if (choice == 0)
    {
        printf("Exiting VEIL-19...\n");
        return 0;
    }

    if (choice != 1 && choice != 2)
    {
        printf("Invalid choice.\n");
        return 1;
    }

    getchar();

    printf("\nEnter your text: ");

    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

    remove_newline(text);

    printf("Enter secret key: ");

    if (fgets(key, sizeof(key), stdin) == NULL)
        return 1;

    remove_newline(key);

    if (!valid_key(key))
    {
        printf("\nError: Key must contain English letters only.\n");
        return 1;
    }

    if (choice == 1)
    {
        veil_encrypt(text, key, result);
        printf("\nEncrypted message:\n%s\n", result);
    }
    else
    {
        veil_decrypt(text, key, result);
        printf("\nDecrypted message:\n%s\n", result);
    }

    printf("\n================================\n");
    printf("         VEIL-19 COMPLETE       \n");
    printf("================================\n");

    return 0;
}
