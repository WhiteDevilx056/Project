#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define KEY_LEN 16
#define BUFFER_SIZE 256

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Generate a random alphanumeric key
void generateKey(char *key, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    key[length] = '\0';
}

// Single function for both Encryption and Decryption (XOR is symmetric)
void processFile(char *filename, const char *key) {
    FILE *source, *target;
    int ch;
    size_t keyLen = strlen(key);
    size_t i = 0;
    char tempFilename[] = "temp_processing.tmp";

    // Open in Binary mode for full file support (images, pdfs, etc.)
    source = fopen(filename, "rb");
    if (source == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        return;
    }

    target = fopen(tempFilename, "wb");
    if (target == NULL) {
        printf("Error: Unable to create temporary file.\n");
        fclose(source);
        return;
    }

    // XOR Logic: (Data ^ Key) = Encrypted; (Encrypted ^ Key) = Data
    while ((ch = fgetc(source)) != EOF) {
        ch = ch ^ key[i % keyLen];
        fputc(ch, target);
        i++;
    }

    fclose(source);
    fclose(target);

    // Atomic replacement
    if (remove(filename) == 0) {
        if (rename(tempFilename, filename) != 0) {
            printf("Error: Failed to rename temp file.\n");
        } else {
            printf("Success! File processed.\n");
        }
    } else {
        printf("Error: Failed to remove original file.\n");
        remove(tempFilename); // Cleanup
    }
}

int main() {
    char filename[BUFFER_SIZE];
    char key[BUFFER_SIZE]; // Large buffer for key input
    int option;

    printf("==========================================\n");
    printf("   Advanced XOR File Encryptor/Decryptor  \n");
    printf("==========================================\n");

    // 1. Get Filename with Buffer Overflow Protection
    while (1) {
        printf("Enter filename: ");
        if (fgets(filename, sizeof(filename), stdin) == NULL) return 0;
        
        // Remove newline character
        filename[strcspn(filename, "\n")] = 0;

        FILE *test = fopen(filename, "rb");
        if (test) {
            fclose(test);
            break;
        }
        printf("File not found! Please try again.\n");
    }

    // 2. Menu
    while (1) {
        printf("\n1. Encrypt (Generate New Key)\n");
        printf("2. Decrypt (Enter Existing Key)\n");
        printf("3. Exit\n");
        printf("Select option: ");
        
        if (scanf("%d", &option) != 1) {
            clearInputBuffer(); // Clear invalid input
            continue;
        }
        clearInputBuffer(); // Consume newline

        if (option == 3) {
            printf("Exiting...\n");
            return 0;
        }
        if (option == 1 || option == 2) break;
        printf("Invalid option.\n");
    }

    // 3. Process based on option
    if (option == 1) {
        // Encryption: Generate Key
        char genKey[KEY_LEN + 1];
        generateKey(genKey, KEY_LEN);
        
        printf("\n------------------------------------------\n");
        printf("GENERATED KEY: %s\n", genKey);
        printf("WARNING: Save this key! You need it to decrypt.\n");
        printf("------------------------------------------\n");
        
        processFile(filename, genKey);
        
    } else {
        // Decryption: Input Key
        printf("Enter the decryption key: ");
        if (fgets(key, sizeof(key), stdin) != NULL) {
            key[strcspn(key, "\n")] = 0; // Remove newline
            processFile(filename, key);
        }
    }

    return 0;
}