#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// SCOPE 1: Encrypt Function
// Yahan humne parameter ka naam 'fileToEncrypt' rakha hai.
// Ye variable sirf is function ke andar zinda hai.
void encryptdata(char *fileToEncrypt){ 

    FILE *source, *target;
    int ch;

    // Ab hum 'filename' ki jagah 'fileToEncrypt' use karenge
    source = fopen(fileToEncrypt, "r");
    if(source==NULL){
        printf("Your file %s not found. Make sure your file exists.\n", fileToEncrypt);
        return;
    }

    // DEBUG: Scope check
    printf("\n[Inside encryptdata Function]\n");
    printf("Processing variable: fileToEncrypt\n");

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

    remove(fileToEncrypt);
    rename("temp.txt", fileToEncrypt);

    printf("Your file is successfully Encrypted.\n");
}

// SCOPE 2: Decrypt Function
// Yahan humne parameter ka naam 'fileToDecrypt' rakha hai.
// Iska upar wale 'fileToEncrypt' se koi lena dena nahi hai.
void decryptdata(char *fileToDecrypt){ 
    FILE *source, *target; 
    int ch;

    source=fopen(fileToDecrypt, "r");
    if (source==NULL)
    {
        printf("%s not found. Check your file name!\n", fileToDecrypt);
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

    remove(fileToDecrypt);
    rename("temp.txt", fileToDecrypt);

    printf("Your file is successfully decrypted.\n");
}


int main(){

    // SCOPE 3: Main Function
    // Yahan humne variable ka naam 'userFilename' rakha hai.
    // Ye wo 'Original Parchi' hai jisme user ne naam likha hai.
    char userFilename[100];
    int option;
    char password[20];
    const char secretPass[] = "1234";
    
    FILE *validatefile;
    
    while (1)
    {
        printf("*********Cryptography data encryption**********\n");
        printf("Enter your filename (ex. data.txt): ");
        
        // User ka input 'userFilename' me store hoga
        scanf("%s", userFilename);
        
        validatefile=fopen(userFilename, "r");
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
    } 

    switch (option)
    {
    case 1:
        // CONCEPT: Pass by Reference (Address bhejna)
        // Hum 'userFilename' ka address bhej rahe hain.
        // Ye address 'encryptdata' function me 'fileToEncrypt' naam ke variable me copy ho jayega.
        encryptdata(userFilename);
        break;
    case 2: 
        // Yahan 'userFilename' ka address 'decryptdata' function me 'fileToDecrypt' me copy hoga.
        decryptdata(userFilename);
        break;
    }

    return 0;
}