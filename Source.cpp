#include "Header.h"

int main()
{
	string failas = "tekstas.txt";
	std::unordered_map <string, Zodis> Tekstas;
	Skaitymas(Tekstas, failas);

	return 0;
}