#include <iostream>
#include <fstream>
#include <filesystem>
#include <string_view>
#include "invalidInput.h"
#include "fileHandling.h"

// the "biiiiiiiiiig" Q is: How do I create a "global" file if none exist


bool file_exists(const std::string& filename)
{
	struct stat buffer {};
	//debug comment:
	//std::cout << "File exists: " << (stat(filename.c_str(), &buffer) == 0);
	return (stat(filename.c_str(), &buffer) == 0);
}

std::fstream openOrCreateFile(std::string filename)
{

	if (file_exists(filename))
	{
		std::fstream file;
		file.open(filename, std::fstream::out | std::ios::app);
		return file;
	}

	// This has not been tested since using "File_exists()" <--
	std::fstream file{ filename, file.binary | file.trunc | file.in | file.out };
	return file;
	
	
}


bool fileCouldBeOpened(std::fstream& file, std::string_view filename)
{
	if (!file.is_open())
	{
		std::cout << "Failed to open " << filename;
		return false;
	}
	std::cout << "File could be opened:\n";
	return true;
	
}

// It won't write the first line / first call. 
void writeUser(std::fstream& file, std::string_view filename, std::string_view username, std::string_view pwd)
{
	file.open(filename, std::fstream::out | std::ios::app); 

	if (fileCouldBeOpened(file, filename))
	{
		std::cout << "--> Writing: " << username << ":" << pwd << '\n' << '\n';
		file << username << ":" << pwd << '\n';
		file.close(); 
		return;
	}	

}