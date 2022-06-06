#include "Header.h"
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
                std::stringstream s(eil);
                while (s >> elem) {
                    if (!m.count(elem)) m[elem] = Zodis{ elem, 1 };
                    else m[elem].n++;
                }
        }
        else break;
    }
}