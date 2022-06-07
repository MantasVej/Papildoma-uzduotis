#include "Header.h"

/**
* Žodzių pasikartojimo skaičiavimo funkcija
*/
void Zodziai(std::unordered_map <string, Zodis>& m, string failas) {
    Skaitymas(m, failas);
    Isvedimas(m);
}
/**
* Funkcija patikrina, ar jai paduotas kintamasis yra specialusis simbolis arba skaičius
*/
bool Simbolis(char s) {
    std::unordered_set <char> chars({ '.',',',':',';','?','!','"','(',')','[', ']','{','}','@','=','~','+','-','*','/','%','<','>', '©', '\''});
    if (chars.count(s) || (isdigit((unsigned char)s))) return true;
    else return false;
}
/**
* Skaito teksto failą po vieną eilutę, pašalina skaičius ir specialius simbolius,
* Skirtingus žodžius įrašo į unordered_map tipo konteinerį, suskaičiuoja kiek kartų žodis pasikartoja ir kuriose eilutėse
*/
void Skaitymas(std::unordered_map <string, Zodis>& m, string failas) {

    string eil;
    string elem;
    int i = 1;

    std::stringstream my_buffer;

    try {
        std::ifstream fd(failas);
        fd.exceptions(std::ifstream::failbit);
        my_buffer << fd.rdbuf();
        fd.close();
    }
    catch (std::exception& e) {
        cout << "Toks duomenu failas neegzistuoja.";
    } 
    while (my_buffer) {
        if (!my_buffer.eof()) {
            std::getline(my_buffer, eil);
            eil.erase(std::remove_if(eil.begin(), eil.end(), Simbolis), eil.end());
                std::stringstream s(eil);
                while (s >> elem) {
                    std::transform(elem.begin(), elem.end(), elem.begin(), [](auto c) { return std::tolower(c); });
                    if (!m.count(elem)) m[elem] = Zodis{ elem, 1, {i} };
                    else {
                        m[elem].n++;
                        if (m[elem].eilutes.back() != i) m[elem].eilutes.push_back(i);
                    }
                }
                i++;
        }
        else break;
    }
}
/**
* Išveda žodžius, kurie pasikartoja daugiau nei 1 kartą, kiek kartų jie pasikartoja ir kuriose eilutėse
*/
void Isvedimas(std::unordered_map <string, Zodis>& m) {
    std::ofstream fr("rezultatai.txt");
    fr << "--------------------------------------------------------------------------------------------------" << endl;
    fr << std::left << setw(25) << "Zodis" << " | " << std::right << setw(14) << "Pasikartojimai" << " | " << "Eiluciu numeriai" << endl;
    fr << "--------------------------------------------------------------------------------------------------" << endl;
    for (auto const& s : m) {
        if (s.second.n > 1) {
            fr << std::left << setw(25) << s.first << " | " << std::right << setw(14) << s.second.n << " | ";
            for (auto const& c : s.second.eilutes)
                fr << c << " ";
            fr << endl;
        }
    }
    fr << "----------------------------------------------------------------------------------------" << endl;
    fr.close();
}
/**
* Ieško tekste URL adresų, rastus skirtingus adresus įrašo į unordered_set tipo konteinerį, baigus paiešką adresai išvedami į ekraną
*/
void URL(std::unordered_set <string>& m, string failas) {
    string elem;
    std::stringstream my_buffer;

    try {
        std::ifstream fd(failas);
        fd.exceptions(std::ifstream::failbit);
        my_buffer << fd.rdbuf();
        fd.close();
    }
    catch (std::exception& e) {
        cout << "Toks duomenu failas neegzistuoja.";
    }
    while (my_buffer >> elem) {
        if (elem.find("www.") != string::npos) m.insert(elem);
    }
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "                                URL adresai tekste"                                      << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    for (auto const& s : m) {
        cout << s << endl;
        }
    cout << "---------------------------------------------------------------------------------------" << endl;
}