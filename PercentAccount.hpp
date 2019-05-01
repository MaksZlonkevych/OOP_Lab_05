#pragma once
#include"Account.hpp"

class percent_account : public deposit_account
{
private:
	int term_month;
	double rate_year;
public:
	percent_account();
	percent_account(const char * name, double amount,int term, double rate);
	virtual void output() const override;
	virtual void input() override;
	virtual double percent_sum() const override;

};



