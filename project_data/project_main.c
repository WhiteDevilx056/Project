#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void encryptdata(char *filename){ // POINTER: 'filename' holds the address of the string passed from main

    // CONCEPT:
    // 1. char *filename -> Ye RAM me us jagah ka address hai jahan file ka NAAM ("data.txt") rakha hai.
    // 2. FILE *source   -> Ye us 'Control Box' (Structure) ka address hai jo Hard Disk wali file ko handle karta hai.

    FILE *source, *target; // POINTER: These hold the memory addresses of the files
int ch;

    // fopen returns the address of the file structure
source = fopen(filename, "r");
    if(source==NULL){
        printf("Your file %s not found. Make sure your file exists.\n", filename);
        return;
    }

    // DEBUG: Ye proof hai ki dono address alag hain
    printf("\n--- POINTER ADDRESS CHECK ---\n");
    printf("filename pointer ka address: %p (Ye RAM me 'data.txt' kahan likha hai wo batata hai)\n", filename);
    printf("source pointer ka address:   %p (Ye RAM me File Control Box kahan hai wo batata hai)\n", source);
    printf("-----------------------------\n\n");

target = fopen("temp.txt", "w");
    if(target==NULL){

        printf("Error creating temp file.\n");
        
        fclose(source);
        return;
    }


    while ((ch=fgetc(source)) !=EOF){

        ch = ch+100;
        fputc(ch, target);
    }
    
    fclose(source);
    fclose(target);

    

    remove(filename);
    rename("temp.txt", filename);

printf("Your file is successfully Encrypted.\n");



}

void decryptdata(char *filename){ // POINTER: Receiving address of filename string
    FILE *source, *target; // POINTER: File handles
    int ch;

    source=fopen(filename, "r");
    if (source==NULL)
    {
        printf("%s not found. Check your file name!\n", filename);
        return;
    }
    
    target=fopen("temp.txt", "w");
    if ( target==NULL)
    {
        printf("Error creating temp file.\n");
       fclose(source);
        return;
    }
    
    while ((ch=fgetc(source)) != EOF)
    {
        ch = ch - 100;
        fputc(ch, target);
    }
    
    fclose(source);
    fclose(target);


    remove(filename);
    rename("temp.txt", filename);

    printf("Your file is successfully decrypted.\n");

    
}


int main(){


    char filename[100];
    int option;
    char password[20];
    const char secretPass[] = "1234";
    

    FILE *validatefile;
    
while (1)
{
    

printf("*********Cryptography data encryption**********\n");
    printf("Enter your filename (ex. data.txt): ");
    scanf("%s", filename);
    validatefile=fopen(filename, "r");
    if(validatefile==NULL){
        printf("------------>File does not exist.\n");
        printf("------------>Please enter a valid filename.\n");
        printf("**********************************************\n");
    } 
    
    else {
        fclose(validatefile);
        break;
    }
}

while (1)
{
    printf("Choose any option(1 - 3):\n");
    printf("Option 1 for Encrypt data:\nOption 2 for Decrypt data:\nOption 3 for Exit: ");
    scanf("%d", &option);

    if (option==3)
    {
        printf("Exiting the program.\n");
        return 0;
    }
    else if (option==1 || option==2)
    {
        break;
    }
    else
    {
        printf("Invalid option. Please choose again.\n");
    }
    
    printf("*************************************************\n");
}
   

int attempt = 0;
while (attempt < 3)
{
    printf("Enter the secret password: ");
    scanf("%s", password);

    if (strcmp(password, secretPass) == 0)
    {
        break;
    }
   
    printf("Incorrect password. Try again.\n");
    attempt++;

    if (attempt==3)
    {
        printf("Maximum attempts reached. Exiting program.\n");
        return 0;
    }
    

    
} // Loop yahan band hona chahiye


switch (option)
{
case 1:
    encryptdata(filename);
    break;
case 2: 
    decryptdata(filename);
    break;

}

return 0;






}