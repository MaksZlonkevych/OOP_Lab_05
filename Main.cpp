#include"PercentAccount.hpp"
#include"ProgrecivePercentAccount.hpp"

int main()
{
		//progrecive_percent_account da("ivanov", 2500.00,4,15.0);
		//percent_account da1("petrov",1500.00,12,12.0);
		////da.input();
		//da.output();
		////da1.input();
		//cout << "======================================================================" << endl;
		//da1.output();

	int account_number;
	int choose = 0;
	const int most_number = 1;
	cout << "amount of accounts:\t";
	cin >> account_number;
	cin.ignore(1);
	system("cls");
	deposit_account** account_list = new deposit_account*[account_number];
	for (size_t i = 0; i < account_number; i++)
	{	system("cls");
		cout << "1.\t simple deposit account\n2.\t progrecive deposit account" << endl;
		cin >> choose;
		cin.ignore(1);
		system("cls");
		switch (choose)
		{
		case 1: account_list[i] = new percent_account();
			break;
		case 2: account_list[i] = new progrecive_percent_account();
			break;
		default:cout << "error chooice" << endl; i--; system("pause"); continue;
		}
		
		account_list[i]->input();
		
	}
	system("cls");
	for (size_t i = 0; i < account_number; i++)
	{
		account_list[i]->output();
		cout << "______________________________________" << endl;
	}
	sort_desc(account_list, account_number);
	cout << "\n\nafter sort:\t"<<endl;
	for (size_t i = 0; i < account_number; i++)
	{
		account_list[i]->output();
		cout << "______________________________________" << endl;
	}
	cout << "\n\nmost profitable accounts:" << endl;
	for (size_t i = 0; i < most_number; i++)
	{
		account_list[i]->output();
	}
	delete[]account_list;
	system("pause>void");
		return 0;
}