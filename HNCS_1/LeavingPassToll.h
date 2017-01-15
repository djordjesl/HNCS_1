#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "User.h"
#include "EnteringPassToll.h"
using namespace std;

class LeavingPassToll :public EnteringPassToll
{
public:
	void printTicket(User);
	double billing();
	double speedingTicket();
	string getOldLocation();
};
