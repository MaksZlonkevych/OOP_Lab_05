#include "Account.hpp"

deposit_account::deposit_account()
{
		owner_name = new char;
		owner_name[0] = '\0';
		cash_amount = 0.0;
}

deposit_account::deposit_account(const char * name, double amount)
{
	cash_amount = amount;
	owner_name = new char[strlen(name) + 1];
	strcpy(owner_name, name);

}

deposit_account::~deposit_account()
{
	//cout << "dtor\n";
	delete[] owner_name;
}

void deposit_account::output() const
{
	if(strlen(owner_name)>0)
	cout << setw(20) <<left<< "name:" << setw(50) <<left<< owner_name << endl;
	else
	cout << setw(20) << left << "name:" << setw(50) << left << "no name" << endl;
	cout << setw(20) <<left<< "amount:" << setw(50) << setprecision(2) << fixed <<left<< cash_amount << endl;
	
}

void deposit_account::input()
{
	char first_symbol;
	int name_length;
	cout << "name:\t";
	cin >> first_symbol;
	name_length = cin.rdbuf()->in_avail() + 1;
	owner_name = new char[name_length];
	owner_name[0] = first_symbol;
	cin.getline(owner_name+1, name_length);
	cout << "cash amount:\t";
	cin >> cash_amount;
	cin.ignore(1);
}


void sort_desc(deposit_account ** list, int count)
{
	//selected sort
	int idx_max;
	deposit_account* tmp;
	for (size_t i = 0; i < count; i++)
	{
		idx_max = i;
		for (size_t j = i + 1; j < count; j++)
		{
			if (list[j]->percent_sum() > list[idx_max]->percent_sum())
				idx_max = j;
		}
		tmp = list[i];
		list[i] = list[idx_max];
		list[idx_max] = tmp;
	}
}


