#pragma once
#include<string>
#include<iostream>
#include<fstream>
class User
{
public:
	User(std::string, std::string, std::string);
	std::string getUsername();
	std::string getPassword();
	std::string getLocation();
	bool checkAuthorisation();
	~User();
private:
	std::string username, password, location;
};

____