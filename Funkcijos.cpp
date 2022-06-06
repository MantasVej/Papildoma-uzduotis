#include "Header.h"

bool Simbolis(char s) {
    std::unordered_set <char> chars({ '.',',',':',';','?','!','"','(',')','[', ']','{','}','@','=','~','+','-','*','/','%','<','>', '©', '\''});
    if (chars.count(s) || (isdigit((unsigned char)s))) return true;
    else return false;
}

void Skaitymas(std::unordered_map <string, Zodis>& m, string failas) {

    string eil;
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
    while (my_buffer) {
        if (!my_buffer.eof()) {
            std::getline(my_buffer, eil);
            eil.erase(std::remove_if(eil.begin(), eil.end(), Simbolis), eil.end());
                std::stringstream s(eil);
                while (s >> elem) {
                   // std::transform(elem.begin(), elem.end(), elem.begin(), [](auto c) { return std::tolower(c); });
                        if (!m.count(elem)) m[elem] = Zodis{ elem, 1 };
                        else m[elem].n++;
                }
        }
        else break;
    }
}

void Isvedimas(std::unordered_map <string, Zodis>& m, string failas) {
    std::ofstream fr(failas);
    for (auto const& s : m)
        fr << std::left << setw(25) << s.first << s.second.n << std::endl;
    fr.close();
}