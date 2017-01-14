#include<iostream>
#include<ctime>
#include<fstream>
#include"User.h"
#include "EnteringPassToll.h"
using namespace std;

int main()
{
	EnteringPassToll ept;


	string searchUsername;
	string searchPassword;
	string location;
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


	if (user.checkAuthorisation())
	{

		if (position == 'E')
		{
			cout << "For help on the road (H), Give ticket to user (G), Log out(0)";
			cin >> position;
			while (position != '0')
			{
				if (position == 'H')
					ept.printHelp();

				else if (position == 'G')
					ept.printTicket(user);
			}
		}
	}

	getchar();
	getchar();
}