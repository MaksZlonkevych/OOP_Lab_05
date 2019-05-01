#pragma once
#include"Account.hpp"

class progrecive_percent_account : public deposit_account
{
private:
	const double percent_growth = 1.0;
	const double percent_limit = 30.0;
	int term_kvartal;
	double* rate_year_table;
public:
	progrecive_percent_account();
	progrecive_percent_account(const char * name, double amount, int term, double base_rate);
	virtual ~progrecive_percent_account() override;
	virtual void output() const override;
	virtual void input() override;
	virtual double percent_sum() const override;

};
