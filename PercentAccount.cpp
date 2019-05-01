#include "PercentAccount.hpp"

percent_account::percent_account()
{
	term_month = 0;
	rate_year = 0.0;
}

percent_account::percent_account(const char * name, double amount,int term, double rate):deposit_account(name, amount)
{
	term_month = term;
	rate_year = rate;
}

void percent_account::output() const
{
	deposit_account::output();
	cout << setw(20) << left << "term:" << setw(50) << left << term_month << endl;
	cout << setw(20) << left << "rate:" << setw(50) << setprecision(2) << fixed << left << rate_year << endl;
	cout << setw(20) << left << "profit:" << setw(50) << setprecision(2) << fixed << left << percent_sum() << endl;
}

void percent_account::input()
{
	deposit_account::input();
	cout << "term (in month):\t";
	cin >> term_month;
	cin.ignore(1);
	cout << "rate (year):\t";
	cin >> rate_year;
	cin.ignore(1);

}

double percent_account::percent_sum() const
{
	return rate_year/1200*term_month*cash_amount;
}


