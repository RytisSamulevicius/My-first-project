#include "funkcijos.h"

#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <utility>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;

string pasirinktiFaila()
{
    int pasirinkimas;

    while (true)
    {
        cout << "\n -----Pasirinkite faila:-----\n";
        cout << "1 - studentai1000.txt\n";
        cout << "2 - studentai10000.txt\n";
        cout << "3 - studentai100000.txt\n";
        cout << "4 - studentai1000000.txt\n";
        cout << "5 - studentai10000000.txt\n";
        cout << "6 - Iveskite failo pavadinima paciam\n";
        cout << "0 - atsaukti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;
    
    
        if (cin.fail()) 
        {
           cin.clear();
           cin.ignore(10000, '\n');
           cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 0 iki 6.\n";
           continue;
        }

        switch (pasirinkimas)
         {
            case 1:
                return "studentai1000.txt";
            case 2:
                return "studentai10000.txt";
            case 3:
                return "studentai100000.txt";
            case 4:
                return "studentai1000000.txt";
            case 5:
                return "studentai10000000.txt";
            case 6:
            {
                string failo_pavadinimas;
                cout << "Iveskite failo pavadinima: ";
                cin >> failo_pavadinimas;
                return failo_pavadinimas;
            }
            case 0:
                return "";
            default:
                cout << "Neteisingas pasirinkimas. Pasirinkite nuo 0 iki 5.\n";
         }
    }    
}
void skaiciavimas( studentas& B)
{
    if (B.paz.empty()){
        B.vid_rez = 0.6 * B.exam;
        B.med_rez = 0.6 * B.exam;
        return;
    }
    vector <int> surikiuoti_paz = B.paz;
    std::sort(surikiuoti_paz.begin(), surikiuoti_paz.end());
    double mediana;
    int dydis = surikiuoti_paz.size();
    if (dydis%2==0)
        mediana=(surikiuoti_paz[dydis/2-1] + surikiuoti_paz[dydis/2]) / 2.0;
    else
        mediana=surikiuoti_paz[dydis/2];

    B.vid_rez=0.4*std::accumulate(B.paz.begin(), B.paz.end(), 0.0)/B.paz.size() + 0.6*B.exam;
    B.med_rez = 0.4*mediana + 0.6*B.exam;
}
void printas(std::ofstream& failas, const studentas& A, int pasirinkimas, int w_vardas, int w_pavarde){
    failas <<"|"<<left<<setw(w_vardas)<<A.vardas<<"|"<<left<<setw(w_pavarde)<<A.pavarde;
    failas <<std::fixed<<std::setprecision(2);
    if (pasirinkimas==1)
        failas<<"|"<<right<<setw(10)<<std::fixed<<std::setprecision(2)<<A.vid_rez;
    else if (pasirinkimas == 2)
        failas <<"|"<<right<<setw(10)<<std::fixed<<std::setprecision(2)<<A.med_rez;
    else
         failas<<"|"<<right<<setw(10)<<A.vid_rez<<"|"<<right<<setw(10)<<A.med_rez;

    failas<<"|\n";
}
void skirstyti (const vector<studentas>& visi, vector<studentas>& vargsiukai, vector<studentas>& kietiakai, int pasirinkimas)
{
    for (const studentas& s : visi) 
    {
        double galutinis;
        if (pasirinkimas == 1)
            galutinis = s.vid_rez;
        else
            galutinis = s.med_rez;

        if (galutinis < 5.0) 
            vargsiukai.push_back(s);
        else 
            kietiakai.push_back(s);
    }
}
bool NuskaitytiFaila(const string & failo_pavadinimas, vector<studentas>& grupe)
{

    std::ifstream failas (failo_pavadinimas);
    if (!failas.is_open()){
        cout << "Nepavyko atidaryti failo " << failo_pavadinimas << "\n";
        return false;
    }

    grupe.clear();
    string eilute;
    std::getline(failas, eilute);

    while(std::getline(failas, eilute))
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
        S.paz = rezultatai;

        skaiciavimas(S);

        grupe.push_back(std::move(S));
        
    }
    failas.close();
    return true;
    cout << "Failas uzdarytas\n";

}
void IrasytiIFaila(const string & failo_pavadinimas, const vector<studentas>& studentai, int pasirinkimas)
{
    std::ofstream failas(failo_pavadinimas);
    if (!failas.is_open()) {
        cout << "Nepavyko sukurti failo: " << failo_pavadinimas << "\n";
        return; 
    }
    
    failas <<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde";
    if (pasirinkimas == 1)
        failas <<right<<setw(15)<<"Gal.(vid)";
    else 
        failas <<right<<setw(15)<<"Gal.(med)";
    failas << "\n";

    failas << std::fixed << std::setprecision(2);
    for (const studentas& s : studentai) 
    {
        failas <<left<<setw(20)<<s.vardas<<setw(20)<<s.pavarde;
        if (pasirinkimas == 1)
            failas <<right<<setw(15)<<s.vid_rez;
        else 
            failas <<right<<setw(15)<<s.med_rez;
        failas << "\n";
    }
    if (!failas){
        cout << "Klaida irasyme i faila: " << failo_pavadinimas << "\n";
        return;   
    }
    failas.close();

}
bool lygintiPagalVarda(const studentas& a, const studentas& b) {
    return a.vardas < b.vardas;
}
bool lygintiPagalPavarde(const studentas& a, const studentas& b) {
    return a.pavarde < b.pavarde;
}
bool lygintiPagalGalutiniBala(const studentas& a, const studentas& b, int pasirinkimas) {
     if (pasirinkimas == 1) {
        return a.vid_rez < b.vid_rez;
    } else {
        return a.med_rez < b.med_rez;
    }
}
    
