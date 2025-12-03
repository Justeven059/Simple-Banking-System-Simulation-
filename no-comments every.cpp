#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <limits>
using namespace std;

int main() {
    const int reqbalance = 1;
    long double reqdeposit = 0;
    long double reqwithdraw = 0;
    const int deposit = 2;
    const int withdraw = 3;
    long double balance = 200.00;

    const int correctPin = 123456;
    int userpin = 0;
    int choice = 0;
    long double amount = 0;
    int attempts = 0;
    const int maxAttempts = 3;

    time_t now;
    char* dt;

    cout << "Welcome to Every's ATM Machine \n";

    while (attempts < maxAttempts){
		cout << "Enter 6 Digit PIN: ";
		cin >> userpin;
		
        if (!cin) {
        cin.clear();             
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Enter 6 Digit PIN only.\n";
        userpin = 0;  
        attempts++;
        cout << "remaining attempts: " << maxAttempts - attempts << endl;
        continue;
        }

		if (userpin <= 000000 && userpin >= 999999) {
			cout << "PIN must be 6 digits.\n";
            attempts++;
            cout << "remaining attempts: " << maxAttempts - attempts << endl;   
            continue;       
		}

		if (userpin >= 999999){
			cout << "Wrong Type!\n";
            attempts++;
            cout << "remaining attempts: " << maxAttempts - attempts << endl;
            continue;           
		}

        if (userpin == correctPin) {
        break;
        }

        cout << "Access Denied!\n";
        attempts++;
        cout << "remaining attempts: " << maxAttempts - attempts << endl;
    }
    
    if (attempts == maxAttempts) {
    cout << "\nToo many attempts. Exited\n";
    return 0;
	}

    cout << "\nAccess Granted!\n";

    now = time(0);
    dt = ctime(&now);

    fstream fileln("transaction history.txt", ios::app);
    fileln << "Balance: " << balance << " PHP " << "(Login) " << dt;
    fileln.close();

    ifstream inFile("Account Balance.txt");
    if (inFile.is_open()) {
        inFile >> balance;
        inFile.close();
        cout << "Account Balance: " << balance << " PHP" << endl;
        cout << "Access date and time is " << dt << endl;
    } else {
        cout << "No Acoount Found Automatically Created One" << endl;
        fstream file("Account Balance.txt", ios::app);
        file.close();
    }

    do {
        cout << "--- Main Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (!cin) {
        cin.clear();             
        cin.ignore(1000, '\n');  
        cout << "Invalid input! choose number 1-5 only\n" << endl;
        continue;
        }

        switch (choice) {

        case 1:
            cout << "\nYour Balance is: " << balance << " PHP\n" << endl;
            break;

        case 2: {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;

            if (!cin) {
            cin.clear();             
            cin.ignore(1000, '\n');  
            cout << "Invalid input! choose the amount only\n" << endl;
            continue;
            }

            if (amount > 0) {
                balance += amount;
                cout << "Deposit successful. New Balance: " << balance << " PHP"<< endl;
                
                time_t now = time(0);
                char * dt = ctime(&now);

                fstream filedp("transaction history.txt", ios::app);
                filedp << "Balance: " << balance << " PHP " << "+" << amount << " PHP " << "(Deposited)" << " " << dt;
                filedp.close();

                ofstream outFile("Account Balance.txt");
                if (outFile.is_open()) {
                    outFile << balance << " PHP" << endl;
                    outFile.close();
                } else {
                    cout << "Unable to open file for writing." << endl;
                }

            } else {
                cout << "Invalid deposit amount." << endl;
            }
            break;
        }

        case 3: {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            if (!cin) {
            cin.clear();             
            cin.ignore(1000, '\n');  
            cout << "Invalid input! choose the amount only\n" << endl;
            continue;
            }

            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdrawal Successful. Remaining Balance: "
                     << balance << " PHP" << endl;

                time_t now = time(0);
                char * dt = ctime(&now);

                fstream filewd("transaction history.txt", ios::app);
                filewd << "Balance: " << balance << " PHP " << "-" << amount << " PHP " << "(Withdrawn)" << " " << dt;
                filewd.close();

                ofstream outFile("Account Balance.txt");
                if (outFile.is_open()) {
                    outFile << balance << " PHP" << endl;
                    outFile.close();
                } else {
                    cout << "Unable to open file for writing." << endl;
                }

            } else if (amount > balance) {
                cout << "Insufficient balance! You don't have enough money, WORK MORE!!\n";
            } else {
                cout << "Invalid withdrawal amount.\n";
            }
            break;
        }

        case 4: {
            ifstream file("transaction history.txt");
            string line;

            if (!file) {
            cout << "No data found!\n";
            break;
            }

            if (file.peek() == ifstream::traits_type::eof()) {
            cout << "File is empty!\n";
            file.close();
            break;
            }

            cout << "\n--- Transaction History ---\n";
            while (getline(file, line)) {
            cout << line << endl;
            }

            file.close();
            cout << "" << endl;
            break;
        }


        case 5:
            cout << "Thank you for using Every's ATM Machine!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    
    } while (choice != 5);
    
    cout << "Account Balance is: " << balance << " PHP" << endl;
    
    ofstream outFile("Account Balance.txt");
    if (outFile.is_open()) {
        outFile << balance << " PHP" << endl;
        outFile.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
    
    now = time(0);
    dt = ctime(&now);

    cout << "Logout date and time is " << dt << endl;

    fstream filelt("transaction history.txt", ios::app);
    filelt << "Balance: " << balance << " PHP " << "(Logout) " << dt;
    filelt.close();
    
    return 0;
}   