#include "EnteringPassToll.h"

void EnteringPassToll::printTicket(User user)
{
	ofstream dat("Ticket.txt", ios::out);
	if (!dat)
		cout << "Error!";
	else
	{
		dat << "___________Ticket of HNCS service______________" << endl << endl;
		dat << "Location: " << user.getLocation() << endl;
		dat << "Worker: " << user.getUsername() << endl << endl;
		time_t now = time(0);
		dat << "_______________Have a nice trip________________" << endl;

		// convert now to string form
		char* dt = ctime(&now);

		dat << "Date/Time: " << dt << endl;

	}

	dat.close();
}

void EnteringPassToll::printHelp()
{
	char text[255];
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
