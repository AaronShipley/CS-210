// Aaron Shipley
// project 2
// CS210

# ifndef banking_h // defining banking header file
# define banking_h
#include<stdio.h>

class Savings {
public: // public members that can be accessed
    Savings(double t_investment, double t_monthDeposit, double t_annualRate, int t_years);
    void NoMonthlyDeposits();
    void WithMonthlyDeposits();

 // private members that can only be accessed within the class
private:
    double m_initialDeposit;
    double m_monthlyDeposit;
    double m_interestRate;
    int m_numYears;
};
#endif /* banking.h*/
