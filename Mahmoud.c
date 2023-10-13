#include <stdio.h>
#include <string.h>


#define Max 10


struct User {
    char username[50];
    char password[50];
};


struct User users[Max];


int num = 0;


void registerUser() {
    if (num >= Max) {
        printf("Sorry, maximum number of users.\n");
        return;
    }

    printf("Enter a username: ");
    scanf("%s", users[num].username);

    printf("Enter a password: ");
    scanf("%s", users[num].password);

    printf("Registration successful!\n");
    num++;
}


void loginUser() {
    char username[50];
    char password[50];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < num; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }

    printf("Login failed. Invalid username or password.\n");
}

int main() {
    int choice;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
