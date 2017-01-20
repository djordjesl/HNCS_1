#include "LeavingPassToll.h"

void LeavingPassToll::printTicket(User user)
{
	string temp;
	int k = 1;
	ifstream dat("Ticket.txt", ios::in);
	if (!dat)
		cout << "Error!";
	else {
		while (getline(dat, temp))//reading line by line
			if (temp.find(IDnew, 0) != string::npos)//if ID found
				k = 0;
		dat.close();
		if (k)//if ID not found
			cout << "No such ID" << endl;
		else {
			ofstream dat("TicketExit.txt", ios::out);
			if (!dat)
				cout << "Error!";
			else
			{
				time_t now = time(0);
				// convert now to string form
				char* dt = ctime(&now);
				//print ticket in file
				dat << dt << endl;
				dat << "_________________Your bill_____________________ " << endl << endl;
				dat << " Vehicle category: " << getCategory() << endl;
				dat << " Worker: " << user.getUsername() << endl;
				dat << " Relation: " << getOldLocation() << " - " << user.getLocation() << endl;
				dat << " You need to pay " << billing(user) << " BAM" << endl;
				if (speedingTicket())
					dat << " You drove too fast, you need to pay " << speedingTicket() << " BAM " << endl << endl;
				dat << " _______________Have a nice trip!________________" << endl;
				dat.close();
			}
		}
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
		getline(dat, temp);//skip first 4 lines

		while (getline(dat, temp, ':'))//read after ':'
		{
			if (temp == getOldLocation())//get old location price
			{
				t = getCategory();
				while (t--)
					getline(dat, temp, ' ');
				a = atof(temp.c_str());//put it in a
			}
			else if (temp == user.getLocation())//get new location price
			{
				t = getCategory();
				while (t--)
					getline(dat, temp, ' ');
				b = atof(temp.c_str());//put it in b
			}
			getline(dat, temp, '\n');
		}

		dat.close();
	}
	double c = b - a;//price difference is how much you pay
	if (c < 0)
		return -c;
	return c;
}
double LeavingPassToll::speedingTicket()
{
	long int t1 = static_cast<long int>(time(NULL)), t2;//t1-leaving time
	string temp;
	ifstream dat("Ticket.txt", ios::in);
	if (!dat)
		cout << "Error!";
	else {
		while (temp.find(IDnew, 0) != string::npos)
			getline(dat, temp);
		getline(dat, temp, ':');
		getline(dat, temp, '\n');
		t2 = atol(temp.c_str());//t2-get entering time from file
		dat.close();
		if ((t1-t2) < 300000)//if time less than 5 minutes write ticket
			return 50.0;
	}
	return 0;
}
string LeavingPassToll::getOldLocation()
{
	string temp;
	ifstream dat("Ticket.txt", ios::in);
	if (!dat)
		cout << "Error!";
	else {
		while (temp.find(IDnew, 0) == string::npos)
			getline(dat, temp);
		getline(dat, temp);
		getline(dat, temp);
		getline(dat, temp);
		getline(dat, temp);//skip firt 4 lines
		getline(dat, temp, ':');
		getline(dat, temp, '\n');
		dat.close();
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
		while (temp.find(IDnew, 0) == string::npos)
			getline(dat, temp);
		getline(dat, temp);
		getline(dat, temp);
		getline(dat, temp);
		getline(dat, temp);
		getline(dat, temp);//skip first 5 lines
		getline(dat, temp, ':');
		getline(dat, temp, '\n');
		double cat = atof(temp.c_str());
		dat.close();
		return cat;
	}
	dat.close();
	return 0;
}

void LeavingPassToll::printHelp()
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
		cout << "No such database!";
	help.close();
}

void LeavingPassToll::setID(string ID)
{
	IDnew = ID;
}
