#include "banking.h"
#include <iomanip>
#include <iostream>
using namespace std;
//Sets values for public variables using instances
Savings::Savings(double t_investment, double t_monthDeposit, double t_annualRate,
    int t_years) {
    this->m_initialDeposit = t_investment; // pointer called for investment
    this->m_monthlyDeposit = t_monthDeposit; // pointer called for deposit
    this->m_interestRate = t_annualRate;   // pointer called for interest rate
    this->m_numYears = t_years;   // pointer called for years
}
//Prints report without monthly deposit
void Savings::NoMonthlyDeposits() {
    //Print heading
    cout << " Balance and Interest w/out additional Monthly Deposits" << endl;
    cout <<
        "=========================================================================" <<
        endl;
    //Print content 
    cout << setw(10) << "Year"
        << setw(20) << "Year-End Balance"
        << setw(35) << "Year-End Earned Interest Rate" << endl;
    cout <<
        "-------------------------------------------------------------------------" <<
        endl;
    //Loop for given years and calculate interest earned
    int currentYear = 1;
    double yearEndBalance = this->m_initialDeposit;
    while (currentYear <= this->m_numYears) {
        //Calculate interest
        double interestEarned = yearEndBalance * this->m_interestRate / 100;

        //Add it to yearEndBalance for total
        yearEndBalance += interestEarned;
        //Print the results
        cout << right << setw(10) << currentYear << fixed << setprecision(2)
            << setw(20) << yearEndBalance
            << setw(35) << interestEarned << endl;
        //Incement year
        currentYear++;
    }
}
//Prints report with monthly deposit
void Savings::WithMonthlyDeposits() {
    //Print heading
    cout << " Balance and Interest w/out additional Monthly Deposits" << endl;
    cout <<
        "=========================================================================" <<
        endl;
    //Print content heading
    cout << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(35) << "Year End Earned Interest Rate" << endl;
    cout <<
        "-------------------------------------------------------------------------" <<
        endl;
    //Loop for given years and calculate interest earned 
    int currentYear = 1;
    double yearEndBalance = this->m_initialDeposit;
    while (currentYear <= this->m_numYears) {

        //Calulate interest monthly and find total interest
        int month = 1;
        double interestEarned = 0.0;
        double monthEndBalance = yearEndBalance;
        while (month <= 12) {

            //Add monthly deposit
            monthEndBalance += this->m_monthlyDeposit;
            //Calculate monthly interest, interest rate is for year so need to divide by 12
                double monthlyinterest = monthEndBalance * this->m_interestRate / (100 * 12);
            //Add the monthly interest to yearly interest earned
            interestEarned += monthlyinterest;
            // add the interest to monthEndBalance
            monthEndBalance += monthlyinterest;
            //Increase the month by 1 until reaches 12
            month++;
        }
        //After 12 months
        yearEndBalance = monthEndBalance;
        //Print the results
        cout << right << setw(10) << currentYear << fixed << setprecision(2)
            << setw(20) << yearEndBalance
            << setw(35) << interestEarned << endl;
        
        //Increment the year count
        currentYear++;
    }
}

