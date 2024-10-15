#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPassword(char pass[]);
int checkUsername(char username[]);

int main() {
    char pass[20];
    char username[20];

    printf("Enter your username: ");
    scanf("%s", username);


    
    printf("Enter your password: ");
    scanf("%s", pass);

    int passCheck = checkPassword(pass);
    int userCheck = checkUsername(username);
    
    if (passCheck && userCheck) {
        printf("Valid login. Congratulations, you have captured the flag!\n");
    } 
    
    else if(!userCheck) {
        printf("Username denied. Try again!\n");
    }

    else if(!passCheck) {
        printf("Password denied. Try again!\n");
    }

    return 0;
}

int checkPassword(char *pass) {
    int sum = 0;
    int length = strlen(pass);

    // Password must be 10 characters long
    if (length != 10) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        // All characters must be digits
        if (!isdigit(pass[i])) {
            return 0;
        }
        
        sum += (pass[i] - '0');
    }

    // Sum of all digits must be 69
    if(sum == 69) {
        return 1;
    }

    else {
        return 0;
    }
}

int checkUsername(char *username) {
    int length = strlen(username);

    // Username cannot be less than 4 characters long
    if (length <= 4) {
        return 0;
    }

    int atFlag = 0;

    // Username must contain an '@' character
    for(int i = 0; i < length; i++) {
        if (username[i] == '@') {
            atFlag = 1;
        }
    }

    if (!atFlag) {
        return 0;
    }

    // All characters must be lowercase letters
    for (int i = 0; i < length; i++) {
        if (!islower(username[i])) {
            if(username[i] == '@') {
                continue;
            }
            else {
                return 0;
            }
        }
    }

    return 1;
}
