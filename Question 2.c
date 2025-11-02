#include <stdio.h>
#include <string.h>

#define MAX 100

void getCustomerInfo(char name[], char cnic[]) {
    printf("Enter Customer Name: ");
    getchar(); 
    gets(name);
    printf("Enter Customer CNIC: ");
    gets(cnic);
    printf("Customer details recorded successfully!\n");
}

void displayInventory(char products[][50], float prices[], int stock[], int count) {
    int i;
    printf("\n---------- Inventory ----------\n");
    printf("No.\tProduct\t\tPrice\tStock\n");
    printf("-------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("%d\t%-10s\t%.2f\t%d\n", i + 1, products[i], prices[i], stock[i]);
    }
}

void addToCart(char products[][50], float prices[], int stock[], int count,
               int cartQty[], float *total) {
    int choice, qty;

    displayInventory(products, prices, stock, count);
    printf("\nEnter product number to add to cart (0 to stop): ");
    scanf("%d", &choice);

    while (choice != 0) {
        if (choice < 1 || choice > count) {
            printf("Invalid choice!\n");
        } else {
            printf("Enter quantity: ");
            scanf("%d", &qty);
            if (qty > stock[choice - 1]) {
                printf("Not enough stock!\n");
            } else if (qty <= 0) {
                printf("Invalid quantity!\n");
            } else {
                cartQty[choice - 1] += qty;
                stock[choice - 1] -= qty;
                *total += prices[choice - 1] * qty;
                printf("%d x %s added to cart.\n", qty, products[choice - 1]);
            }
        }
        printf("\nEnter product number to add more (0 to stop): ");
        scanf("%d", &choice);
    }
}

void showInvoice(char name[], char cnic[], float total, float discountApplied) {
    printf("\n========== CUSTOMER INVOICE ==========\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("--------------------------------------\n");
    printf("Total Discount: %.2f PKR\n", discountApplied);
    printf("Final Amount:   %.2f PKR\n", total);
    printf("======================================\n");
    printf("Thank you for shopping with us!\n");
}

int main() {
    char name[50], cnic[20];
    char products[MAX][50] = {"Milk", "Bread", "Sugar", "Rice", "Tea"};
    float prices[MAX] = {180, 120, 150, 250, 500};
    int stock[MAX] = {20, 15, 10, 12, 8};
    int cartQty[MAX] = {0};

    int count = 5;
    int choice;
    float totalBill = 0.0, discountApplied = 0.0;

    printf("===== Supermarket Management System =====\n");

    do {
        printf("\n-------------------- MENU --------------------\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("0. Exit\n");
        printf("---------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getCustomerInfo(name, cnic);
                break;
            case 2:
                displayInventory(products, prices, stock, count);
                break;
            case 3:
                addToCart(products, prices, stock, count, cartQty, &totalBill);
                break;
            case 4: {
                printf("\nTotal Bill (without discount): %.2f PKR\n", totalBill);
                printf("Do you have a promo code? (Y/N): ");
                char ch;
                scanf(" %c", &ch);
                if (ch == 'Y' || ch == 'y') {
                    char code[20];
                    printf("Enter Promo Code: ");
                    scanf("%s", code);
                    if (strcmp(code, "Eid2025") == 0) {
                        discountApplied = totalBill * 0.25;
                        totalBill -= discountApplied;
                        printf("Promo applied! 25%% discount = %.2f PKR\n", discountApplied);
                    } else {
                        printf("Invalid promo code!\n");
                    }
                } else {
                    printf("No promo code applied.\n");
                }
                break;
            }
            case 5:
                showInvoice(name, cnic, totalBill, discountApplied);
                break;
            case 0:
                printf("Exiting system... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}

