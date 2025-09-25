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
		return false;
	}
	std::cout << "File could be opened\n";
	return true;
	
}

// This does write to the file, but it OVERwrites
void writeUser(std::fstream& file, std::string_view filename, std::string_view username, std::string_view pwd)
{
	file.open(filename, std::ios::app); // It won't write the first one. 

	if (fileCouldBeOpened(file, filename))
	{
		std::cout << "\n--> trying to write the user <--\n";
		file << username << ":" << pwd << '\n';
		file.close(); // can't open it again after. 
		return;
	}	

}