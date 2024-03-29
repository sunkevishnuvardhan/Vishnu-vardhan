#include <stdio.h>

// Function to encrypt a character using affine cipher
char encrypt(char ch, int a, int b) {
    if (isalpha(ch)) {
        // Determine the type of the character (uppercase or lowercase)
        int is_upper = isupper(ch);
        ch = tolower(ch);

        // Apply the affine cipher formula: E(x) = (ax + b) mod 26
        ch = ((a * (ch - 'a') + b) % 26 + 26) % 26 + 'a';

        // Convert the character back to uppercase if it was originally uppercase
        if (is_upper) {
            ch = toupper(ch);
        }
    }
    return ch;
}

// Function to encrypt a string using affine cipher
void affineCipher(char* text, int a, int b) {
    printf("Encrypted Text: ");
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", encrypt(text[i], a, b));
    }
    printf("\n");
}

int main() {
    char plaintext[100];
    int a, b;

    // Input plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Input the key values a and b
    printf("Enter the value of 'a' (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter the value of 'b': ");
    scanf("%d", &b);

    // Check if 'a' is coprime with 26
    if (a % 2 == 0 || a % 13 == 0) {
        printf("'a' must be coprime with 26. Please choose another value for 'a'.\n");
        return 1;
    }

    // Encrypt and output the ciphertext
    affineCipher(plaintext, a, b);

    return 0;
}
n
