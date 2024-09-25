#include <iostream>
using namespace std;

// Function Prototypes
void EncodeLargeNumber(int array[], int count);
void DecodeLargeNumber(int array[], int count);
void Reverse(int array[], int count);

int main() {
    int temp;
    int count = 0;
    int array[8];

    int num;
    do {
        cout << "\n\033[32mEnter a Number Between 10 and 99999999: \033[0m";
        cin >> num;
    } while (num < 10 || num > 99999999);

    // Append the number to the array in reverse order
    while (num > 0) {
        temp = num % 10;
        num = num / 10;
        array[count] = temp;
        count++;
    }

    // Reverse the array to get the digits in the correct order
    Reverse(array, count);

    // Display the initial array 
    cout << "\n\033[32mInput Code: \033[0m";
    for (int i = 0; i < count; i++) {
        cout << array[i];
    }
    cout << endl;

    int option;

    // Check if count is greater than or equal to 4 (if the count is greater than 4, it is a number with more than 4 digits and can be advanced encrypted)
    if (count >= 4) {
        EncodeLargeNumber(array, count); // Encrypted

        cout << "\n\033[32mEncoded Code: \033[0m"; // Display Encrypted Code
        for (int i = 0; i < count; i++) {
            cout << array[i];
        }

        cout << endl;

        // Display Menu
        cout << "\n---Menu---\n";
        cout << "\t1. Advanced Encrypt\n";
        cout << "\t2. Decrypt\n";
        cout << "\t3. Exit";

        do {
            cout << "\nChoose an Option: ";
            cin >> option;

            if (option < 1 || option > 3) {
                cout << "Invalid Option!\n";
            }
        } while (option < 1 || option > 3); // Option Validation 

        switch (option) {
            case 1:
                Reverse(array, count);
                cout << "\n\033[32mAdvance Encrypted: \033[0m"; // Advanced Encrypted
                for (int i = 0; i < count; i++) { // Display Advanced Encrypted Code
                    cout << array[i];
                }

                cout << "\n\nDo You Want to Decrypt\n"; // Sub Menu 1
                cout << "\t1. Yes\n";
                cout << "\t2. No\n";

                do {
                    cout << "Option: ";
                    cin >> option;
                    if (option < 1 || option > 2) {
                        cout << "Invalid Option!\n"; // Option Validation 
                    }
                } while (option < 1 || option > 2);

                switch (option) {
                    case 1:
                        Reverse(array, count); // Reverse Advanced Encrypted Code 
                        DecodeLargeNumber(array, count); // Decode Encrypted Code 

                        cout << "\n\033[32mAdvance Decrypted: \033[0m";
                        for (int i = 0; i < count; i++) {
                            cout << array[i];
                        }
                        cout << endl;
                        break;
                    case 2:
                        cout << "\n\033[31mProgram Terminated\033[0m\n";
                        return 0;
                }
                break;

            case 2:
                // Decrypt
                DecodeLargeNumber(array, count);
                cout << "\n\033[32mDecrypted Code: \033[0m";
                for (int i = 0; i < count; i++) {
                    cout << array[i];
                }

                cout << endl;
                break;
            case 3:
                cout << "\n\033[31mProgram Terminated\033[0m\n";
                return 0;
            default:
                cout << "\033[31mInvalid Option!\033[0m";
                break;
        }
    } else {
        Reverse(array, count);
        cout << "\n\033[32mEncoded Code: \033[0m";
        for (int i = 0; i < count; i++) {
            cout << array[i];
        }
        cout << endl;
    }

    return 0;
}

// Function to encode a large number
void EncodeLargeNumber(int array[], int count) {
    int digit = 1;

    for (int i = count - 1; i >= 0; i--) {
        array[i] = (array[i] + digit) % 10;
        digit++;
    }
}

// Function to decode a large number
void DecodeLargeNumber(int array[], int count) {
    int digit = 1;

    for (int i = count - 1; i >= 0; i--) {
        int temp = array[i] - digit;
        array[i] = (temp < 0) ? (array[i] + 10 - digit) : temp;
        // if short-hand property
        // (is_condition_true) ? (if_true_Do_This) : (If_Not_Do_This)
        digit++;
    }
}

// Function to reverse an array
void Reverse(int array[], int count) {
    int start = 0;
    int end = count - 1;

    while (start < end) {
        // Swap the elements at start and end positions
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;

        // Move the start and end pointers
        start++;
        end--;
    }
}
