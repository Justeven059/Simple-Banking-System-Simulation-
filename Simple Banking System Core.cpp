#include <iostream>
#include <fstream>
using namespace std;

int main() {

    const int reqbalance = 1;
    long double reqdeposit = 0;
    long double reqwithdraw = 0;
    const int deposit = 2;
    const int withdraw = 3;
    long double balance = 5000;

    const int correctPin = 1234 ;   // FIXED invalid variable name
    int userpin = 0;
    int choice = 0;
    long double amount = 0;        // FIXED missing variable

    cout << "Welcome to Every's ATM Machine \n";

    cout << "Please Enter Your 4-Digit User PIN: ";   // FIXED cout <<
    cin >> userpin;

    if (userpin != correctPin) {   // FIXED invalid variable names
        cout << "Access Denied." << endl;
        return 0;
    }
    
    ifstream inFile("/storage/emulated/0/Download/every.txt"); // READ Balance
    if (inFile.is_open()) {
        inFile >> balance; // read the first value as int
        inFile.close();
        cout << "Stored Balance: " << balance << " PHP" << endl;
    } else {
        cout << "Unable to open file for reading. Using default value 0." << endl;
    }
    
    do {
        cout << "--- Main Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:   // CHECK BALANCE
            cout << "Your Balance is: " << balance << " PHP\n" << endl;
            break;

        case 2:   // DEPOSIT
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            if (amount > 0) {
                balance += amount;
                cout << "Deposit successful. New Balance: " << balance << endl;
            } else {
                cout << "Invalid deposit amount." << endl;
            }
            break;

        case 3:   // WITHDRAW
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdrawal Successful. Remaining Balance: "
                     << balance << endl;
            } else if (amount > balance) {
                cout << "Insufficient balance! You don't have enough money, WORK MORE!!\n";
            } else {
                cout << "Invalid withdrawal amount.\n";
            }
            break;

        case 4:   // EXIT
            cout << "Thank you for using Every's ATM Machine!";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    
    } while (choice != 4);
    
    ofstream outFile("/storage/emulated/0/Download/every.txt"); //Save Balance
    if (outFile.is_open()) {
        outFile << balance << endl;
        outFile << " PHP" << endl;
        outFile.close();
        cout << "The Stored Balance is: " << balance << " PHP" << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }

    return 0;
}
