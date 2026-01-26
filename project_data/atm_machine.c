#include <stdio.h>

int main() {
    // 1. Initial Balance Fixed (Shuruwat ke paise)
    int balance = 5000; 
    int choice;
    int amount;

    printf("Welcome to Apna ATM!\n");

    // 2. Infinite Loop (Jab tak user Exit na kare, chalta rahega)
    while (1) {
        printf("\n----------------------------\n");
        printf("      ATM MENU OPTIONS      \n");
        printf("----------------------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money (Paise Jama Karein)\n");
        printf("3. Withdraw Money (Paise Nikalein)\n");
        printf("4. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Check Balance
                printf("\nYour Current Balance is: Rs. %d\n", balance);
                break;

            case 2: // Deposit
                printf("\nEnter amount to deposit: ");
                scanf("%d", &amount);
                if (amount > 0) {
                    balance = balance + amount; // Balance badhaya
                    printf("Success! Deposited: Rs. %d\n", amount);
                    printf("New Balance: Rs. %d\n", balance);
                } else {
                    printf("Invalid amount! Please enter positive value.\n");
                }
                break;

            case 3: // Withdraw
                printf("\nEnter amount to withdraw: ");
                scanf("%d", &amount);
                if (amount > 0 && amount <= balance) {
                    balance = balance - amount; // Balance ghataya
                    printf("Success! Withdrawn: Rs. %d\n", amount);
                    printf("Remaining Balance: Rs. %d\n", balance);
                } else if (amount > balance) {
                    printf("Insufficient Balance! (Aapke paas itne paise nahi hain)\n");
                } else {
                    printf("Invalid amount!\n");
                }
                break;

            case 4: // Exit
                printf("\nThank you for using Apna ATM. Goodbye!\n");
                return 0; // Program band

            default:
                printf("\nInvalid Option! Please choose between 1 to 4.\n");
        }
    }
    return 0;
}