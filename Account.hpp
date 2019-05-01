#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

class deposit_account
{
private:
	char* owner_name;
protected:
	double cash_amount;

public:
	deposit_account();
	deposit_account(const char* name, double amount);
	virtual ~deposit_account();

	virtual void output() const;
	virtual void input();
	virtual double percent_sum()const =0;
};
void sort_desc(deposit_account** list, int count);

