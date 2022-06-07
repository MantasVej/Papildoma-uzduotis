#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm> 
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::vector;

/**
* Struktūra, kurioje saugoma informacija apie žodį
*/

struct Zodis {
	/**
	* Žodis
	*/
	string zodis;
	/**
	* Pasikartojimų skaičius
	*/
	int n;
	/**
	* Eilučių numeriai
	*/
	vector<int> eilutes;
};
void Zodziai(std::unordered_map <string, Zodis>& m, string);
void Skaitymas(std::unordered_map <string, Zodis>&, string);
void Isvedimas(std::unordered_map <string, Zodis>&);
void URL(std::unordered_set <string>&, string);