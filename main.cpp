#include <iostream>
#include "User.h"
#include "fileHandling.h"

int main()
{
	/*
	
	0. Ask the user if they want to login or registrate 

	1. Login part
		1.1 Ask for username
		1.2 Ask for password (would be nice if it showed '*' instead of letters)
		1.3 Check the file for a login that mathes
		1.4 Give a succes/failure message
		1.5 Give the user an option to logut

	
	
	2. Registration part
		2.1 Ask for username --> check 
		2.2 If username available proceed
		2.3 Ask for password (would be nice if it showed '*' instead of letters)
		2.4 Ask User to confirm password
		2.5 If Password matches proceed
		2.6 Store user
		2.7 Ask user to login
	
	Classes:
		- User (username, password, login attemps?)
		- Login/registration page (login/registration, check if user in file, 
			handle invalid login).
	
	*/

	const std::string filename{ "Users.txt" };

	std::fstream file{ openOrCreateFile(filename) };

	std::string username0{ "0username_test" };
	std::string pwd0{ "pwd_test0" };
	writeUser(file, filename, username0, pwd0);

	std::string username1{ "2username_test" };
	std::string pwd1{ "pwd_test2" };
	writeUser(file, filename, username1, pwd1);

	std::string username2{ "3username_test" };
	std::string pwd2{ "pwd_test3" };
	writeUser(file, filename, username2, pwd2);

	return 0;
}