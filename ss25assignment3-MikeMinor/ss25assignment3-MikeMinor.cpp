#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

// Function declarations
void displayMainMenu();
void performArithmeticOperations();
void performNumberConversions();

void add(double, double);
void subtract(double, double);
void multiply(double, double);
void divide(double, double);

string decToBin(int);
string decToOct(int);
string decToHex(int);

int binToDec(string);
int octToDec(string);
int hexToDec(string);

bool isValidBinary(string);
bool isValidOctal(string);
bool isValidHex(string);

// Main
int main() {
    int choice;

    //Creates the main menu, nested if is there to handle incorrect menu options
    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            performArithmeticOperations();
            break;
        case 2:
            performNumberConversions();
            break;
        case 3:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    cout << "\n======= C++ Calculator =======\n";
    cout << "1. Arithmetic Operations\n";
    cout << "2. Number Base Conversions\n";
    cout << "3. Exit\n";
    cout << "==============================\n";
}

// Function to create sub-menu for if the arithmetic option is selected
void performArithmeticOperations() {
    int opChoice;
    double num1, num2;

    // sets the menu for the nested menu for arithmetic options and handling of incorrect selections
    do {
        cout << "\n--- Arithmetic Operations ---\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Return to Main Menu\n";
        cout << "Choose an operation: ";
        cin >> opChoice;

        if (opChoice >= 1 && opChoice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }

        switch (opChoice) {
        case 1:
            add(num1, num2);
            break;
        case 2:
            subtract(num1, num2);
            break;
        case 3:
            multiply(num1, num2);
            break;
        case 4:
            divide(num1, num2);
            break;
        case 5:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (opChoice != 5);
}

//function for addition (pretty straight forward, adds a and b as doubles and outputs results)
void add(double a, double b) {
    cout << "Result: " << a << " + " << b << " = " << a + b << endl;
}
//function for subtraction, same structure as above 
void subtract(double a, double b) {
    cout << "Result: " << a << " - " << b << " = " << a - b << endl;
}
//function for multiplication
void multiply(double a, double b) {
    cout << "Result: " << a << " * " << b << " = " << a * b << endl;
}
//function for division and error handling for if division by 0 is attempted
void divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero is not allowed.\n";
    }
    else {
        cout << "Result: " << a << " / " << b << " = " << a / b << endl;
    }
}

//Number Base Conversions creates the menu, similar as other nested menu for arithmetic
void performNumberConversions() {
    int convChoice;

    do {
        cout << "\n--- Number Base Conversions ---\n";
        cout << "1. Decimal to Binary\n";
        cout << "2. Decimal to Octal\n";
        cout << "3. Decimal to Hexadecimal\n";
        cout << "4. Binary to Decimal\n";
        cout << "5. Octal to Decimal\n";
        cout << "6. Hexadecimal to Decimal\n";
        cout << "7. Return to Main Menu\n";
        cout << "Choose a conversion: ";
        cin >> convChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        int decNum;
        string input;

        switch (convChoice) {
        case 1:
            cout << "Enter Decimal number: ";
            cin >> decNum;
            cout << "Binary: " << decToBin(decNum) << endl;
            break;
        case 2:
            cout << "Enter Decimal number: ";
            cin >> decNum;
            cout << "Octal: " << decToOct(decNum) << endl;
            break;
        case 3:
            cout << "Enter Decimal number: ";
            cin >> decNum;
            cout << "Hexadecimal: " << decToHex(decNum) << endl;
            break;
        case 4:
            cout << "Enter Binary number: ";
            cin >> input;
            if (isValidBinary(input))
                cout << "Decimal: " << binToDec(input) << endl;
            else
                cout << "Invalid Binary number.\n";
            break;
        case 5:
            cout << "Enter Octal number: ";
            cin >> input;
            if (isValidOctal(input))
                cout << "Decimal: " << octToDec(input) << endl;
            else
                cout << "Invalid Octal number.\n";
            break;
        case 6:
            cout << "Enter Hexadecimal number: ";
            cin >> input;
            if (isValidHex(input))
                cout << "Decimal: " << hexToDec(input) << endl;
            else
                cout << "Invalid Hexadecimal number.\n";
            break;
        case 7:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (convChoice != 7);
}

//Creates the logic for being able to convert the decimal number to binary, follows the simple algorithm for doing so as discussed in class
string decToBin(int num) {
    if (num == 0) return "0";
    string bin = "";
    while (num > 0) {
        bin = char((num % 2) + '0') + bin;
        num /= 2;
    }
    return bin;
}

//Same as above, except for decimal to octal conversion
string decToOct(int num) {
    if (num == 0) return "0";
    string oct = "";
    while (num > 0) {
        oct = char((num % 8) + '0') + oct;
        num /= 8;
    }
    return oct;
}

//Decimal to Hexadecimal
string decToHex(int num) {
    if (num == 0) return "0";
    string hex = "";
    char hexDigits[] = "0123456789ABCDEF";
    while (num > 0) {
        hex = hexDigits[num % 16] + hex;
        num /= 16;
    }
    return hex;
}

//Binary to Decimal, follows logic for going from binary to decimal as discussed in class
int binToDec(string bin) {
    int dec = 0;
    for (char c : bin) {
        dec = dec * 2 + (c - '0');
    }
    return dec;
}

//Octal to Decimal
int octToDec(string oct) {
    int dec = 0;
    for (char c : oct) {
        dec = dec * 8 + (c - '0');
    }
    return dec;
}

//Hexadecimal to Decimal
int hexToDec(string hex) {
    int dec = 0;
    for (char c : hex) {
        if (isdigit(c))
            dec = dec * 16 + (c - '0');
        else if (isalpha(c)) {
            c = toupper(c);
            dec = dec * 16 + (c - 'A' + 10);
        }
    }
    return dec;
}

//Input Validation, ensures whether the entry is in binary, octal, hexidecimal to ensure conversion can be performed
bool isValidBinary(string bin) {
    for (char c : bin) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

bool isValidOctal(string oct) {
    for (char c : oct) {
        if (c < '0' || c > '7') return false;
    }
    return true;
}

bool isValidHex(string hex) {
    for (char c : hex) {
        if (!isdigit(c) && !(toupper(c) >= 'A' && toupper(c) <= 'F'))
            return false;
    }
    return true;
}
