#include <iostream>
#include <string>
#include "banking.h"
using namespace std;
int main() {
    while (1) { // used while(1) as infinite loop in program for calculations
        //Show Menu
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: " << endl;
        cout << "Monthly Deposit: " << endl;
        cout << "Annual Interest: " << endl;
        cout << "Number of years: " << endl;
        cout << "Press any key to continue";
        cout << endl;
        //Gets the inputs from user
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: $";
        double investment, monthlydeposit, interestrate;
        int years;
        cin >> investment;
        cout << "Monthly Deposit: $";
        cin >> monthlydeposit;
        cout << "Annual Interest: %";
        cin >> interestrate;
        cout << "Number of years: ";
        cin >> years;

        //system("PAUSE");
        system("read -p 'Press Enter to continue . . .' var");

        //create object savings from inputs given
        Savings mySavings = Savings(investment, monthlydeposit, interestrate,
            years);
        cout << endl;
        //Calls the report methods
        mySavings.NoMonthlyDeposits();
        cout << endl;

        //Calls monthly deposit report
        //monthly deposit report must be >= $1
        if (monthlydeposit > 0) {
            mySavings.WithMonthlyDeposits();
        }

        //Restart the calculator
        cout << endl << "Do you want to try again? (y/n): ";
        string userInput;
        cin >> userInput;
        //break loop if user chooses to quit
        if (userInput != "y") {
            break; // break statement to end program
        }
        cout << endl;
    }
    return 0;
}

    