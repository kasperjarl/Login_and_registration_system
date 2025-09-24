#include <iostream>
#include <fstream>
#include <filesystem>
#include <string_view>
#include "invalidInput.h"
#include "fileHandling.h"

// the "biiiiiiiiiig" Q is: How do I create a "global" file if none exist


std::fstream openOrCreateFile(std::string filename)
{
	std::fstream file{ filename, file.binary | file.trunc | file.in | file.out };
	return file;
}


bool fileCouldBeOpened(std::fstream& file, std::string_view filename)
{
	if (!file.is_open())
	{
		std::cout << "Failed to open " << filename << '\n';
		return true;
	}
	std::cout << "File could be opened\n";
	return false;
	
}

// This does write to the file, but it OVERwrites
void writeUser(std::string_view filename, std::string_view username, std::string_view pwd)
{
	std::fstream file;

	// I want to use the func below to check if I can open the file... 
	if (fileCouldBeOpened())
	{
		std::cout << "\n--> trying to write the user <--\n";
		file.open(filename, std::ios::app);
		file << username << ":" << pwd << '\n';
		return;
	}	
}