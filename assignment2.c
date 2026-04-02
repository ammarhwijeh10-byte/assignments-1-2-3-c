#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForEnter() {
    printf("\nPress Enter to go back...");
    getchar();
}

void showMainMenu() {
    printf("--------------\n");
    printf("MAIN MENU\n");
    printf("--------------\n");
    printf("1 - Add\n");
    printf("2 - Display\n");
    printf("3 - Delete\n");
    printf("0 - Exit\n");
    printf("--------------\n");
}

void addMenu() {
    clearScreen();
    printf("--------------\n");
    printf("ADD MENU\n");
    printf("--------------\n");
    printf("Option Add not implemented yet!\n");
    waitForEnter();
}

void displayMenu() {
    FILE *file;
    char line[200];
    int hasData = 0;

    clearScreen();
    printf("--------------\n");
    printf("DISPLAY MENU\n");
    printf("--------------\n");

    file = fopen("people.txt", "r");

    if (file == NULL) {
        printf("Error: could not open people.txt\n");
        waitForEnter();
        return;
    }

    printf("File opened successfully.\n\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        hasData = 1;
    }

    if (!hasData) {
        printf("The file is empty.\n");
    }

    fclose(file);
    waitForEnter();
}


void deleteMenu() {
    clearScreen();
    printf("--------------\n");
    printf("DELETE MENU\n");
    printf("--------------\n");
    printf("Option Delete not implemented yet!\n");
    waitForEnter();
}

void invalidOptionMenu() {
    clearScreen();
    printf("--------------\n");
    printf("INVALID OPTION\n");
    printf("--------------\n");
    printf("Please choose a valid option.\n");
    waitForEnter();
}

int main() {
    int option;

    do {
        clearScreen();
        showMainMenu();
        printf("Enter option: ");

        if (scanf("%d", &option) != 1) {
            option = -1;
        }

        while (getchar() != '\n');

        switch (option) {
            case 1:
                addMenu();
                break;
            case 2:
                displayMenu();
                break;
            case 3:
                deleteMenu();
                break;
            case 0:
                clearScreen();
                printf("EXIT!\n");
                break;
            default:
                invalidOptionMenu();
                break;
        }

    } while (option != 0);

    return 0;

}