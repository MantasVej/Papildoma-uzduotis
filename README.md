# Papildoma-uzduotis

Programos veikimas ir naudojimo instrukcija:

1. Programos source.cpp faile nurodamas failas iš kurio bus skaitomas tekstas.
2. Paleidžiama programa.
3. Programa po vieną eilutę skaito pateiktą tekstinį failą.
4. Iš eilutės pašalinami skaičiai ir specialieji simboliai (taškai, kableliai ir t.t.)
5. Tuomet kiekvienas skirtingas žodis yra įrašomas į unordered_map tipo konteinerį.
6. Jeigu atrandamas žodis, kuris jau buvo pasikartojęs anksčiau, į konteinerį jis nėra įrošomas, žodžio pasikartojimų skaičius n padidinamas vienetu.
7. Eilučių, kuriose pasikartoja žodis, numeriai įrašomi ir saugomi vektoriuje.
8. Informacija apie žodžius, kurie pasikartoja daugiau nei kartą, įrašoma į failą "rezultatai.txt".
9. Tada iš naujo skaitomas pradinis failas ir ieškoma skirtingų URL adresų.
10. Rasti unikalūs URL adresai įrašomi į unordered_set tipo konteinerį.
11. Baigus paieška URL adresai išvedami į ekraną.
