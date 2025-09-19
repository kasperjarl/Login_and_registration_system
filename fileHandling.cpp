#include <iostream>
#include <fstream>
#include <filesystem>
#include "invalidInput.h"
#include "fileHandling.h"

// the "biiiiiiiiiig" Q is: How do I create a "global" file if none exist


const std::string userfile_name{ "Users.txt" };

bool fileExists(const std::string& filename)
{
	return std::filesystem::exists(filename);
}

void start()
{
	if (fileExists(userfile_name))
	{
		std::cout << "File found!\n";
	}
	else
	{
		std::cout << "File does not exists.\n";
		std::cout << "Creating it now..\n";
		std::fstream file{ userfile_name };
	}

}

