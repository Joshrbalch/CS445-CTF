#include <stdio.h>
#include <string.h>

int validate_serial(const char *serial) {
    int sum = 0;
    int length = strlen(serial);

    // Serial must be exactly 10 characters long
    if (length != 10) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        // All characters must be digits
        if (serial[i] < '0' || serial[i] > '9') {
            return 0;
        }
        
        sum += (serial[i] - '0');
    }

    // Check if the sum of the digits is equal to 69
    return sum == 69;
}

int main() {
    char user_input[20];
    
    printf("Enter your serial key: ");
    scanf("%19s", user_input);
    
    if (validate_serial(user_input)) {
        printf("Serial key is valid! Access Granted.\n");
    } 
    
    else {
        printf("Invalid serial key. Access Denied.\n");
    }

    return 0;
}
