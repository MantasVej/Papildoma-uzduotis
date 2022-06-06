#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;

struct Zodis {
	std::string zodis;
	int n;
};

void Skaitymas(std::unordered_map <string, Zodis>&, string);