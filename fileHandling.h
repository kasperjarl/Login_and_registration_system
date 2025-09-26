#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include "invalidInput.h"
#include "fileHandling.h"


bool file_exists(const std::string& filename);

std::fstream openOrCreateFile(std::string filename);

bool fileCouldBeOpened(std::fstream& file, std::string_view filename);

void writeUser(std::fstream& file, std::string_view filename, std::string_view username, std::string_view pwd);

