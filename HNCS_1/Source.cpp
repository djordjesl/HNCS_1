#include"User.h"
#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
int main()
{
	string searchUsername;
	string searchPassword;
	string location;
	char position;
	char text[255];

	cout << "Hello user!" << endl;
	cout << "Username: ";
	cin >> searchUsername;
	cout << "Password: ";
	cin >> searchPassword;
	cout << "Location: ";
	cin >> location;
	// if some other character is entered write a error
	cout << "Entering pass toll (E) or Leaving pass tool (L): ";
	cin >> position;

	User user(searchUsername, searchPassword);
	if (user.checkAuthorisation())
	{
		if (position == 'E')
		{
			cout << "For help on the road (H), Give ticket to user (G), Log out(0)";
			cin >> position;
			if (position == 'H')
			{
				ifstream help("Help.txt", ios::in);
				if (help)
					while (help)
					{
						help.getline(text, 255, '\n');
						if (help) cout << text << endl;
					}
				else
					cout << "Not such database!";
				help.close();
			}
			else if(position == 'G')
			{
				ofstream dat("Ticket.txt", ios::out);
				if (!dat)
					cout << "Error!";
				else
				{
					dat << "___________Ticket of HNCS service______________" << endl << endl;
					dat << "Location: " << location << endl;
					dat << "Worker: " << user.getUsername() << endl << endl;
					time_t now = time(0);
					dat << "_______________Have a nice trip________________" << endl;
					
					// convert now to string form
					char* dt = ctime(&now);

					dat << "Date/Time: " << dt << endl;

				}
					
				dat.close();

			}
		}
	}

	getchar();
	getchar();
}