#include "ProgrecivePercentAccount.hpp"

progrecive_percent_account::progrecive_percent_account()
{
	term_kvartal = 0;
	rate_year_table = nullptr;
}

progrecive_percent_account::progrecive_percent_account(const char * name, double amount, int term, double base_rate) :deposit_account(name, amount)
{
	term_kvartal = term;
	rate_year_table = new double[term_kvartal];
	rate_year_table[0] = base_rate;
	for (size_t i = 1; i < term_kvartal; i++)
	{
		rate_year_table[i] = rate_year_table[i - 1] + percent_growth;
		rate_year_table[i]	=rate_year_table[i] > percent_limit ? percent_limit : rate_year_table[i];
	}

}

progrecive_percent_account::~progrecive_percent_account()
{
	delete[] rate_year_table;
}

void progrecive_percent_account::output() const
{
	deposit_account::output();
	cout << setw(20) << left << "term(month):" << setw(50) << left << term_kvartal*3 << endl;
	cout << setw(20) << left << "rate:";
	for (size_t i = 0; i < term_kvartal; i++)
	{
		cout<< setw(10) << setprecision(2) << fixed << left << rate_year_table[i];
	}
	cout << endl;
	cout << setw(20) << left << "profit(by kvartal):";
	for (size_t i = 0; i < term_kvartal; i++)
	{
		cout << setw(10) << setprecision(2) << fixed << left << rate_year_table[i] / 1200 * 3 * cash_amount;
	}
	cout << endl;
	cout << setw(20) << left << "profit(total):" << setw(50) << setprecision(2) << fixed << left << percent_sum() << endl;
}

void progrecive_percent_account::input()
{
	double base_rate;
	deposit_account::input();
	cout << "term (in kvartal):\t";
	cin >> term_kvartal;
	cin.ignore(1);
	cout << "base rate (year):\t";
	cin >> base_rate;
	cin.ignore(1);
	rate_year_table = new double[term_kvartal];
	rate_year_table[0] = base_rate;
	for (size_t i = 1; i < term_kvartal; i++)
	{
		rate_year_table[i] = rate_year_table[i - 1] + percent_growth;
		rate_year_table[i] = rate_year_table[i] > percent_limit ? percent_limit : rate_year_table[i];
	}

}

double progrecive_percent_account::percent_sum() const
{
	double sum = 0.0;
	for (size_t i = 0; i < term_kvartal; i++)
	{
		sum+= rate_year_table[i] / 1200 * 3 * cash_amount;
	}
	return sum;
}


