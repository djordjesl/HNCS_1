#include "User.h"


User::User(std::string username, std::string password, std::string location) : username(username), password(password), location(location){}

User::~User() {}

std::string User::getPassword()
{
	return password;
}

std::string User::getLocation()
{
	return location;
}

std::string User::getUsername()
{
	return username;
}

bool User::checkAuthorisation()
{
	std::string text;

	std::ifstream enter("User.txt", std::ios::in);

	if (enter)
	{
		while (getline(enter, text))
		{
			if (text.find(username, 0) != std::string::npos && text.find(password, 0) != std::string::npos)
			{
				enter.close();
				return true;
			}
		}

		std::cout << "Wrong username/password" << std::endl;
		enter.close();
		return false;
	}
	else
	{
		std::cout << "Database like that doesnt exist!";
		enter.close();
		return false;
	}
}