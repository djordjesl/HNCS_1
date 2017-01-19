#include<iostream>
#include<ctime>
#include<fstream>
#include"User.h"
#include "EnteringPassToll.h"
#include "LeavingPassToll.h"
using namespace std;
int main()
{
	EnteringPassToll ept;
	LeavingPassToll lpt;

	string searchUsername;
	string searchPassword;
	string location;
	string ID;
	char position;

	cout << "Hello user!" << endl;
	cout << "Username: ";
	cin >> searchUsername;
	cout << "Password: ";
	cin >> searchPassword;
	cout << "Location: ";
	cin >> location;
	User user(searchUsername, searchPassword, location);
	// if some other character is entered write a error

	cout << "Entering pass toll (E) or Leaving pass tool (L): ";
	cin >> position;
	if (user.checkAuthorisation())//checks if there is a user with that name and password
	{

		if (position == 'E')//entering pass toll
		{

			while (position != '0')
			{
				cout << "For help on the road (H), Give ticket to user (G), Log out(0)";
				cin >> position;

				if (position == 'H')
					ept.printHelp();

				else if (position == 'G')
				{
					int x;
					cout << "Vehicle category: ";
					cin >> x;
					ept.setCategory(x);
					ept.printTicket(user);
				}
			}
		}
		else if (position == 'L')//leaving pass toll
		{
			while (position != '0')
			{
				cout << "For help on the road (H), Give bill to user (B), Log out(0)";
				cin >> position;

				if (position == 'H')
					lpt.printHelp();

				else if (position == 'B')
				{
					cout << "Enter ID: ";
					cin >> ID;
					lpt.setID(ID);
					lpt.printTicket(user);
				}
			}
		}
	}
	system("pause");
}
