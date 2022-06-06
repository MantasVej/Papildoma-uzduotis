#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm> 
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::endl;
using std::setw;
using std::string;

struct Zodis {
	std::string zodis;
	int n;
};

void Skaitymas(std::unordered_map <string, Zodis>&, string);
void Isvedimas(std::unordered_map <string, Zodis>&, string);