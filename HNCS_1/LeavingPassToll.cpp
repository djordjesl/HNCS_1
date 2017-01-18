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
		dat << " Vehicle category: " << getCategory() << endl;
		dat << " Worker: " << user.getUsername() << endl;
		dat << " Relation: " << getOldLocation() << " - " << user.getLocation() << endl;
		dat << " You need to pay " << billing(user) << " BAM" << endl;
		if (speedingTicket())
			dat << " You drove too fast, you need to pay " << speedingTicket() << " BAM " << endl << endl;
		dat << " _______________Have a nice trip!________________" << endl;
	}
}
double LeavingPassToll::billing(User user)
{
	string temp;
	double a = 1, b = 1;
	int t;

	ifstream dat("Cjenovnik.txt", ios::in);
	if (!dat)
		cout << "Error!";
	else {
		getline(dat, temp);
		getline(dat, temp);
		getline(dat, temp);
		getline(dat, temp);

		while (getline(dat, temp, ':'))
		{
			if (temp == getOldLocation())
			{
				t = getCategory();
				while (t--)
					getline(dat, temp, ' ');
				a = atof(temp.c_str());
			}
			else if (temp == user.getLocation())
			{
				t = getCategory();
				while (t--)
					getline(dat, temp, ' ');
				b = atof(temp.c_str());
			}
			getline(dat, temp, '\n');
		}

		dat.close();
	}
	double c = b - a;
	return c;
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
int LeavingPassToll::getCategory()
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
		getline(dat, temp, '\n');
		getline(dat, temp, ':');
		getline(dat, temp, '\n');
		double cat = atof(temp.c_str());
		return cat;
	}
	return 0;
}