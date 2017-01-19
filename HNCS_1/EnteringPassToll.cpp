#include "EnteringPassToll.h"

void EnteringPassToll::printTicket(User user)
{
	ofstream dat("Ticket.txt", ios::app);
	if (!dat)
		cout << "Error!";
	else
	{
		time_t now = time(0);
		// convert now to string form
		char* dt = ctime(&now);
		ID = now;

		dat << "ID:" << ID << endl;
		dat << dt << endl;
		dat << "___________Ticket of HNCS service______________" << endl << endl;
		dat << "Entering location:" << user.getLocation() << endl;
		dat << "Vehicle category:" << category << endl;
		dat << "Worker:" << user.getUsername() << endl << endl;
		dat << "_______________Have a nice trip________________" << endl<<endl;

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
void EnteringPassToll::setCategory(int x)
{
	category = x;
}