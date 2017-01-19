#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "User.h"
using namespace std;

class EnteringPassToll
{
public:
	void printTicket(User);
	void printHelp();
	void setCategory(int);
protected:
	int category;
	time_t ID;
};
