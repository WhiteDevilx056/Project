#include<stdio.h>
#include<stdlib.h>

void encryptFile( char *filename){
    FILE *fps, *fpt;
    int ch;

    fps = fopen(filename, "r");
    if(fps ==NULL){
        printf("file not found\n");
        return;
    }
    fpt = fopen("temp.txt", "w");
    if(fpt == NULL){
        printf("Error while creating temp file\n");
        fclose(fps);
        return;
    }
    //logic: ch = ch + 100
    while((ch = fgetc(fps)) != EOF)
{
    ch =ch+100;
    fputc(ch,fpt);
}

fclose(fps);
fclose(fpt);
//replace original file with encrypted file
remove (filename);
rename("temp.txt", filename);

printf("File encrypted successfully\n");
}

void decryptFile( char *filename){

    FILE *fps, *fpt;
    int ch;

    fps = fopen(filename, "r");
    if(fps == NULL){

        printf("File not found.\n");
        return;
    }

    fpt = fopen("temp.txt", "w");
    if(fpt == NULL){
        printf("Sorry, File not found. \n");
        return;
    }

    while ((ch=fgetc(fps)) != EOF)
    {
        ch = ch - 100;
        fputc(ch, fpt);
    }
    fclose(fps);
    fclose(fpt);

    remove(filename);
    rename("temp.txt", filename);

    printf("File Decrypted successfully! \n");
}

int main(){
    char filename[100];
    printf("Enter the filename to process: ");
    scanf("%s", filename);
    int option;
    printf("Welcome to Data Protection Program!\n");
    printf("Choose an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    
    scanf("%d", &option);
    
    switch (option)
    {
    case 1:
    encryptFile(filename);
        
        break;

    case 2:
    decryptFile(filename);
         
        break;
    
    default:
        printf("Invalid option!\n");
        break;
   
}

}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Project: File-Guard (Secure Version)
 * Logic: ASCII Shifting with Password Protection
 * 
 * Features:
 * 1. Encrypt/Decrypt using fgetc/fputc
 * 2. Switch Case for menu
 * 3. Password Protection
 */

void encryptFile(char *filename) {
    FILE *source, *target;
    int ch;

    source = fopen(filename, "r");
    if (source == NULL) {
        printf("Error: Could not open file %s. Make sure it exists.\n", filename);
        return;
    }

    target = fopen("temp.txt", "w");
    if (target == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(source);
        return;
    }

    // Logic: ch = ch + 100
    while ((ch = fgetc(source)) != EOF) {
        ch = ch + 100;
        fputc(ch, target);
    }

    fclose(source);
    fclose(target);

    // Replace original file with encrypted file
    remove(filename);
    rename("temp.txt", filename);

    printf("Magic Done: File encrypted successfully.\n");
}

void decryptFile(char *filename) {
    FILE *source, *target;
    int ch;

    source = fopen(filename, "r");
    if (source == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    target = fopen("temp.txt", "w");
    if (target == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(source);
        return;
    }

    // Logic: ch = ch - 100
    while ((ch = fgetc(source)) != EOF) {
        ch = ch - 100;
        fputc(ch, target);
    }

    fclose(source);
    fclose(target);

    remove(filename);
    rename("temp.txt", filename);

    printf("Magic Done: File decrypted successfully.\n");
}

int main() {
    char filename[100];
    int choice;
    char password[20];
    const char secretPass[] = "1234"; // Yahan apna password set karein

    printf("--- File-Guard Project (Secure) ---\n");
    printf("Enter filename (e.g., data.txt): ");
    scanf("%s", filename);

    printf("\n1. Encrypt (Lock)\n2. Decrypt (Unlock)\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter Password to continue: ");
    scanf("%s", password);

    if (strcmp(password, secretPass) != 0) {
        printf("Access Denied! Wrong Password.\n");
        return 0;
    }

    switch (choice) {
        case 1:
            encryptFile(filename);
            break;
        case 2:
            decryptFile(filename);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
*/