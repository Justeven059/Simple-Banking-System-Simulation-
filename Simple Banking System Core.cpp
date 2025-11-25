/*
Justeven Curangcurang
Justeven's ATM Machine Simulator
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main (){
	const int reqbalance = 1;
	long double reqdeposit = 0;
	long double reqwithdraw = 0;
	const int deposit = 2;
	const int withdraw = 3;
	long double balance = 1000;
	const int correctuserpin = 1234;
	int userpin = 0;
	int menu = 0;
	
	cout << "Welcome to Justeven's ATM Machine \n";
	
	while (userpin != correctuserpin){
		cout << "Enter 4 Digit PIN ";
		cin >> userpin;
		
		if (userpin >= 0000 && userpin <= 9999){
			if(userpin > correctuserpin){
				cout <<"Access Denied!\n";
			}
			else if (userpin < correctuserpin){
				cout <<"Access Denied!\n";
			}
		}
		else if (userpin >= 9999){
			cout << "Wrong Type!\n";
		}
		else {
			cout <<"Wrong Type!\n";
		}
	}
	cout << "\n";
	cout << "--- Main Menu ---\n";
	cout << "1. Check Balance\n";
	cout << "2. Deposit Money\n";
	cout << "3. Withdraw Money\n";
	cout << "4. Exit\n";
	
	while (true){
		cout << "Enter your Choice: ";
		cin >> menu;	
		
		if (menu >= 1 && menu <= 1){
			cout << "Your Balance is: " << fixed << setprecision(2) << balance << "PHP\n" << endl;
			cout << "--- Main Menu ---\n";
			cout << "1. Check Balance\n";
			cout << "2. Deposit Money\n";
			cout << "3. Withdraw Money\n";
			cout << "4. Exit\n";
		}	
		else if (menu >= 2 && menu <= 2){
			cout << "Enter Amount to Deposit: ";
			cin >> reqdeposit;
			balance += reqdeposit;
			cout << "Deposit successful! Your New Balance is: " << fixed << setprecision(2) << balance << "PHP\n" << endl;
			cout << "--- Main Menu ---\n";
			cout << "1. Check Balance\n";
			cout << "2. Deposit Money\n";
			cout << "3. Withdraw Money\n";
			cout << "4. Exit\n";
		}
		else if (menu >= 3 && menu <= 3){
			cout << "Enter Amount to Withdraw: ";
			cin >> reqwithdraw;
			if (balance <= reqwithdraw){
				cout << "Insufficient balance, You don't have Enough Money, WORK MORE!! \n" << endl;
				cout << "--- Main Menu ---\n";
				cout << "1. Check Balance\n";
				cout << "2. Deposit Money\n";
				cout << "3. Withdraw Money\n";
				cout << "4. Exit\n";
			}
			else {
				balance -= reqwithdraw;
				cout << "Withdrawal is successful! Your New Balance is: " << fixed << setprecision(2) << balance << "PHP\n" << endl;
				cout << "--- Main Menu ---\n";
				cout << "1. Check Balance\n";
				cout << "2. Deposit Money\n";
				cout << "3. Withdraw Money\n";
				cout << "4. Exit\n";
			}
		}
		else if (menu >= 4 && menu <= 4){
			cout <<"Thank you for using Justeven's ATM Machine!";
			exit(0);
		}
		else {
			cout << "Try Again ";
		}
	}
	
	return 0;
}
