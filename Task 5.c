#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int i, j;
    char temp;
    j = strlen(str) - 1;
    for (i = 0; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

char toggleBits(char ch) {
    ch ^= (1 << 1);  
    ch ^= (1 << 4);  
    return ch;
}

void encodeMessage(char message[]) {
    int i;
    reverseString(message);  

    for (i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]); 
    }

    printf("\nEncoded Message: %s\n", message);
}

void decodeMessage(char message[]) {
    int i;

    for (i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);
    }

    reverseString(message);

    printf("\nDecoded Message: %s\n", message);
}

int main() {
    char message[200];
    int choice;

    printf("===== TCS Secure Message Utility =====\n");

    do {
        printf("\n------------ MENU ------------\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("0. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter message to encode: ");
                gets(message);
                encodeMessage(message);
                break;

            case 2:
                printf("Enter message to decode: ");
                gets(message);
                decodeMessage(message);
                break;

            case 0:
                printf("Exiting system... Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

