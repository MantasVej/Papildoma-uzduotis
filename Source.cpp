#include "Header.h"

/**
* Programa skaičiuoja kiek kartų tekste pasikartoja kiekvienas žodis
* Randa URL adresus tekste
*/
int main()
{
	string failas = "tekstas.txt";
	std::unordered_map <string, Zodis> T;
	std::unordered_set <string> T1;
	Zodziai(T, failas);
	URL(T1, failas);
	return 0;
}