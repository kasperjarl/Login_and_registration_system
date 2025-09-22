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


void checkFile(std::fstream& file, std::string_view filename)
{
	if (!file.is_open())
	{
		std::cout << "Failed to open " << filename << '\n';
	}
	else
	{
		std::cout << "File could be opened\n";
	}
}

void writeUser(std::fstream& file, std::string_view username, std::string_view pwd)
{
	file.write(username, username.size());
	std::cout "idk, using pwd here: " << pwd << '\n';
}