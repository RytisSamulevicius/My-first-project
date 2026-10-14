#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>

#include "studentas.h"

std::string pasirinktiFaila();
void printas(std::ofstream& failas, const studentas& A, int pasirinkimas, int w_vardas, int w_pavarde);
void skaiciavimas(studentas& B);
void skirstyti(const std::vector<studentas>& visi, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietiakai, int pasirinkimas);
void IrasytiIFaila(const std::string& failo_pavadinimas, const std::vector<studentas>& studentai, int pasirinkimas);        
bool lygintiPagalVarda(const studentas& a, const studentas& b);
bool lygintiPagalPavarde(const studentas& a, const studentas& b);
bool lygintiPagalGalutiniBala(const studentas& a, const studentas& b, int pasirinkimas);

template <typename K>
bool NuskaitytiFaila(const string & failo_pavadinimas, K& grupe)
{
    std::ifstream failas (failo_pavadinimas);
    if (!failas.is_open()){
        cout << "Nepavyko atidaryti failo " << failo_pavadinimas << "\n";
        return false;
    }
    std::stringstream buferis;
    buferis << failas.rdbuf();
    failas.close();

    grupe.clear();
    std::string eilute;
    std::getline(buferis, eilute);

    while(std::getline(buferis, eilute))
    {
        std::stringstream s(eilute);
        studentas S;
        s >> S.vardas >> S.pavarde;

        vector<int> rezultatai;

        int x;
        bool klaida = false;
        while(s >> x)
        {
            if(x < 1 || x > 10)
             {
                klaida = true;
                break;
             }
            rezultatai.push_back(x);
        }
        if (klaida || !s.eof())
        {
            cout << "Klaida faile: " << eilute << "\n";
            continue;
        }
        if (rezultatai.empty()) continue;

        S.exam = rezultatai.back();
        rezultatai.pop_back();
        S.paz = std::move(rezultatai);

        skaiciavimas(S);

        grupe.push_back(std::move(S));
        
    }
    return true;

}
#endif