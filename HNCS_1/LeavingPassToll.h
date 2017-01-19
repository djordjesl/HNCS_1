#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "User.h"
using namespace std;

class LeavingPassToll 
{
public:
	void printTicket(User);
	double billing(User);
	double speedingTicket();
	string getOldLocation();
	int getCategory();
	void printHelp();
	void setID(string);
private:
	string IDnew;
};