#include "LeavingPassToll.h"

void LeavingPassToll::printTicket(User user)
{
	ofstream dat("TicketExit.txt", ios::out);
	if (!dat)
		cout << "Error!";
	else
	{
		time_t now = time(0);
		// convert now to string form
		char* dt = ctime(&now);

		dat << dt << endl;
		dat << "_________________Your bill_____________________ " << endl << endl;
		dat << " Entering location: " << getOldLocation() << endl;
		dat << " Exit location: " << user.getLocation() << endl;
		dat << " You need to pay " << billing() << " BMK" << endl;
		if (speedingTicket())
			dat << " You drove too fast, you need to pay " << speedingTicket() << " BMK " << endl << endl;
		dat << " _______________Have a nice trip!________________" << endl;
	}
}

double LeavingPassToll::billing()
{

	return 1;
}

double LeavingPassToll::speedingTicket()
{

	return 1;
}

string LeavingPassToll::getOldLocation()
{
	string temp;
	ifstream dat("Ticket.txt", ios::in);
	if (!dat)
		cout << "Error!";
	else {
		getline(dat, temp, '\n');
		getline(dat, temp, '\n');
		getline(dat, temp, '\n');
		getline(dat, temp, '\n');
		getline(dat, temp, ':');
		getline(dat, temp, '\n');
		return temp;
	}
	return 0;
}