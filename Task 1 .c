#include <stdio.h>
#include <string.h>

#define MAX 100

void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    if (*count >= MAX) {
        printf("Inventory full! Cannot add more books.\n");
        return;
    }

    int new_isbn;
    printf("Enter ISBN: ");
    scanf("%d", &new_isbn);

    if (findBook(isbns, *count, new_isbn) != -1) {
        printf("Book with this ISBN already exists!\n");
        return;
    }

    isbns[*count] = new_isbn;
    printf("Enter Book Title: ");
    getchar(); 
    gets(titles[*count]); 
    printf("Enter Price: ");
    scanf("%f", &prices[*count]);
    printf("Enter Quantity: ");
    scanf("%d", &quantities[*count]);

    (*count)++;
    printf("Book added successfully!\n");
}

void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    int search_isbn, sold, index;
    printf("Enter ISBN to sell: ");
    scanf("%d", &search_isbn);

    index = findBook(isbns, count, search_isbn);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }

    printf("Enter number of copies sold: ");
    scanf("%d", &sold);

    if (sold <= 0) {
        printf("Invalid sale quantity!\n");
        return;
    }

    if (sold > quantities[index]) {
        printf("Not enough stock! Available: %d\n", quantities[index]);
        return;
    }

    quantities[index] -= sold;
    printf("Sale processed successfully!\n");
    printf("Remaining quantity of '%s': %d\n", titles[index], quantities[index]);
}

void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int found = 0;
    printf("\nLow Stock Report (Qty < 5)\n");
    printf("--------------------------------------\n");
    printf("ISBN\tTitle\t\tPrice\tQuantity\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("%d\t%s\t%.2f\t%d\n", isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No low-stock items.\n");
}

int findBook(int isbns[], int count, int search_isbn) {
    for (int i = 0; i < count; i++) {
        if (isbns[i] == search_isbn)
            return i;
    }
    return -1;
}


int main() {
    int isbns[MAX], quantities[MAX];
    float prices[MAX];
    char titles[MAX][50];
    int count = 0;  // tracks number of books
    int choice;

    do {
        printf("\n===== Liberty Books Inventory =====\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report (Qty < 5)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, titles, prices, quantities, count);
                break;
            case 3:
                lowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
