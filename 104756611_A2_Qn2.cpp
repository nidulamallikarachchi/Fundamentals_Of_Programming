#include <iostream>
using namespace std;

const int MAX_DIGITS = 20;

// Function prototypes
int OddNumber(int array[], int count);
int EvenNumber(int array[], int count);
void CheckDigit(int odd_sum, int even_sum, int count, int array[]);

int main() {
    int credit_card[MAX_DIGITS];
    int count = 0;
    int digit;

    // Input credit card digits
    cout << "Enter credit card digits (up to " << MAX_DIGITS << " digits, or -1 to stop): ";
    while (count < MAX_DIGITS) {
        cin >> digit;

        if (digit == -1) {
            break;
        } else {
            credit_card[count] = digit;
            count++;
        }
    }

    // Display the credit card number in the standard form "xxxx xxxx xxxx xxxx"
    cout << "\nCredit Card Number: ";
    for (int i = 0; i < count; i++) {
        cout << credit_card[i];
        if ((i + 1) % 4 == 0 && i < count - 1) {
            cout << " ";
        }
    }

    cout << "\n\n";

    int oddSum = OddNumber(credit_card, count);
    cout << endl;
    int evenSum = EvenNumber(credit_card, count);
    cout << endl;

    int addition = oddSum+evenSum; 

    cout<<"Addition of Sums: "<<addition<<endl;

    int multiplication = addition*9;

    cout<<addition<<"x9 = "<< multiplication<<endl<<endl; 

    cout<<"Check Digit is: "<<multiplication%10<<endl<<endl; 

    CheckDigit(oddSum, evenSum, count, credit_card);

    return 0;
}

// Function to calculate the sum of odd-indexed digits and display them
int OddNumber(int array[], int count) {
    int odd_sum = 0;

    cout << "Odd Numbers: ";

    for (int i = 0; i < count-1; i += 2) {
        int temp = array[i] * 2;
        int quotient = temp / 10;
        int remainder = temp % 10;

        cout << array[i] << " ";

        odd_sum = odd_sum + remainder + quotient;
    }

    cout << endl;
    cout << "Sum of Odd-Digits: " << odd_sum << endl;

    return odd_sum;
}

// Function to calculate the sum of even-indexed digits and display them
int EvenNumber(int array[], int count) {
    int even_sum = 0;

    cout << "Even Numbers: ";

    for (int i = 1; i < count-1; i += 2) {
        cout << array[i] << " ";
        even_sum = even_sum + array[i];
    }

    cout << endl;
    cout << "Sum of Even-Digits: " << even_sum << endl;

    return even_sum;
}

// Function to check the validity of the credit card number
void CheckDigit(int odd_sum, int even_sum, int count, int array[]) {
    int sum = odd_sum + even_sum;

    int check_Digit = (sum * 9) % 10;

    if (check_Digit == array[count - 1]) {
        cout<<"Since The Check Digit is Equal to The Final Digit of the Credit Card\n\n"; 
        cout << "\033[1;32mThis is a Valid Credit Card Number\033[0m\n\n";
    } else {
        cout<<"Since The Check Digit is Not Equal to The Final Digit of the Credit Card\n\n";
        cout << "\033[1;31mThis is an Invalid Credit Card Number\033[0m\n\n";
    }
}
