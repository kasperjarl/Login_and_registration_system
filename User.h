#pragma once
#include <iostream>
#include "invalidInput.h"

class User
{
public:
	User();
	~User();

	void setName()
	{
		while (true)
		{
			std::cout << "Enter username: ";
			std::string username{};
			std::cin >> username;

			if (clearFailedExtraction())
			{
				std::cout << "Oops, invalid input. Please try again.\n";
				continue;
			}
			ignoreLine();
			m_username = username;
			break;
		}
	}

	void setPwd()
	{
		while (true)
		{
			std::cout << "Enter password: ";
			std::string pwd{};
			std::cin >> pwd;

			if (clearFailedExtraction())
			{
				std::cout << "Oops, invalid input. Please try again.\n";
				continue;
			}

			std::cout << "Confirm password: ";
			std::string c_pwd{};
			std::cin >> c_pwd;

			if (clearFailedExtraction())
			{
				std::cout << "Oops, invalid input. Please start over.\n";
				continue;
			}

			if (pwd == c_pwd)
			{
				std::cout << "\nUser created.\n";
				ignoreLine();
				m_pwd = pwd;
				break;
			}
			else
			{
				std::cout << "\nError: Passwords do not match. Try again.\n";
				continue;
			}
			
		}
	}

private:
	std::string m_username{};
	std::string m_pwd{};
	int m_loginAttempts{};
};

User::User()
{
	setName();
	setPwd();
}

User::~User()
{
}