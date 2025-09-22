#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include "invalidInput.h"
#include "fileHandling.h"


std::fstream openOrCreateFile(std::string filename);


void checkFile(std::fstream& file, std::string_view filename);
void writeUser(std::fstream& file, std::string_view username, std::string_view pwd);