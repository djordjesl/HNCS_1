#include"IzadavanjeRacuna.h"
#include"User.h"
#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
int main()
{
	string searchUsername = "Mirjana";
	string searchPassword = "dane";

	cout << "Hello user!" << endl;
	cout << "Username: ";
	cin >> searchUsername;
	cout << endl << "Password: ";
	cin >> searchPassword;

	User user(searchUsername, searchPassword);
	string text;
	int flag = 0;

	ifstream enter("User.txt", std::ios::in);
	if (enter)
	{
		while (getline(enter, text))
		{ // I changed this, see below
			if (text.find(searchUsername, 0) != string::npos && text.find(searchPassword, 0) != string::npos)
			{
				cout << "found: " << searchUsername << " " << searchPassword << endl;
				flag = 1;
			}
		}
		if (flag == 0)
			cout << "Wrong username/password" << endl;
	}
	else
		cout << "There is not like that database!";
	enter.close();
	getchar();
	getchar();
}