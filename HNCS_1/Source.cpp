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
	char position1=1,position2=1;

	cout << "Hello user!" << endl;
	cout << "Username: ";
	cin >> searchUsername;
	cout << "Password: ";
	cin >> searchPassword;
	cout << "Location: ";
	cin >> location;
	User user(searchUsername, searchPassword, location);
	// if some other character is entered write a error
	do{
	cout << "Entering pass toll (E) or Leaving pass tool (L): ";
	cin >> position1;
	if (user.checkAuthorisation())//checks if there is a user with that name and password
	{

		if (position1 == 'E')//entering pass toll
		{

			while (position2 != '0')
			{
				do {
					cout << "For help on the road (H), Give ticket to user (G), Log out(0)";
					cin >> position2;

					if (position2 == 'H')
						ept.printHelp();

					else if (position2 == 'G')
					{
						int x;
						do {
							cout << "Vehicle category I(1) II(2) III(3) IV(4): ";
							cin >> x;
						} while (x < 1 || x>4);

						ept.setCategory(x);
						ept.printTicket(user);
					}
				} while (position2 != 'G' && position2 != 'H' && position2 != '0');
			}
		}
		else if (position1 == 'L')//leaving pass toll
		{
			while (position2 != '0')
			{
				do {
					cout << "For help on the road (H), Give bill to user (B), Log out(0)";
					cin >> position2;

					if (position2 == 'H')
						lpt.printHelp();

					else if (position2 == 'B')
					{
						cout << "Enter ID: ";
						cin >> ID;
						lpt.setID(ID);
						lpt.printTicket(user);
					}
				} while (position2 != 'B' && position2 != 'H' && position2 != '0');
			}
		}
	}
		
	} while (position1 != 'E' && position1 != 'L' && position1!='0');
	
	getchar();
	getchar();
}
