#include <stdio.h>

#define ROWS 3
#define COLS 3

#define POWER_ON       1   
#define OVERLOAD       2   
#define MAINTENANCE    4   

void updateSector(int grid[ROWS][COLS]) {
    int row, col, choice, flag;
    printf("Enter sector coordinates (row and column): ");
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("\nChoose Status to Update:\n");
    printf("1. Power ON/OFF\n");
    printf("2. Overload ON/OFF\n");
    printf("3. Maintenance ON/OFF\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: flag = POWER_ON; break;
        case 2: flag = OVERLOAD; break;
        case 3: flag = MAINTENANCE; break;
        default:
            printf("Invalid option!\n");
            return;
    }

    int action;
    printf("1. Set (Turn ON)\n2. Clear (Turn OFF)\nEnter action: ");
    scanf("%d", &action);

    if (action == 1)
        grid[row][col] |= flag;  
    else if (action == 2)
        grid[row][col] &= ~flag; 
    else {
        printf("Invalid action!\n");
        return;
    }

    printf("Sector (%d, %d) updated successfully.\n", row, col);
}

void querySector(int grid[ROWS][COLS]) {
    int row, col;
    printf("Enter sector coordinates (row and column): ");
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid coordinates!\n");
        return;
    }

    int status = grid[row][col];
    printf("\n--- Sector (%d, %d) Status ---\n", row, col);
    printf("Power: %s\n", (status & POWER_ON) ? "ON" : "OFF");
    printf("Overload Warning: %s\n", (status & OVERLOAD) ? "YES" : "NO");
    printf("Maintenance Required: %s\n", (status & MAINTENANCE) ? "YES" : "NO");
    printf("------------------------------\n");
}

void runDiagnostic(int grid[ROWS][COLS]) {
    int r, c, overloadCount = 0, maintenanceCount = 0;

    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            if (grid[r][c] & OVERLOAD)
                overloadCount++;
            if (grid[r][c] & MAINTENANCE)
                maintenanceCount++;
        }
    }

    printf("\n===== System Diagnostic Report =====\n");
    printf("Total Sectors: %d\n", ROWS * COLS);
    printf("Overloaded Sectors: %d\n", overloadCount);
    printf("Maintenance Required: %d\n", maintenanceCount);
    printf("====================================\n");
}

void displayGrid(int grid[ROWS][COLS]) {
    int r, c;
    printf("\nCurrent Grid Data (bit values):\n");
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            printf("%d\t", grid[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int grid[ROWS][COLS] = {0}; 
    int choice;

    printf("===== IESCO Power Grid Monitoring System =====\n");

    do {
        printf("\n------------------ MENU ------------------\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Display Grid Data (Debug View)\n");
        printf("0. Exit\n");
        printf("-------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateSector(grid);
                break;
            case 2:
                querySector(grid);
                break;
            case 3:
                runDiagnostic(grid);
                break;
            case 4:
                displayGrid(grid);
                break;
            case 0:
                printf("Exiting system... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}

