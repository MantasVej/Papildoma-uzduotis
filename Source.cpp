#include "Header.h"

int main()
{
	string dfailas = "tekstas.txt";
	string rfailas = "rezultatai.txt";
	std::unordered_map <string, Zodis> Tekstas;
	Skaitymas(Tekstas, dfailas);
	Isvedimas(Tekstas, rfailas);
	return 0;
}