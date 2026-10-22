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
void rikiuotiStudentus(std::vector<studentas>& grupe, int rusiavimas, int pasirinkimas)
{
    if (rusiavimas == 1)
    {
        std::sort(grupe.begin(), grupe.end(), lygintiPagalVarda);   
    }
    else if (rusiavimas == 2)
    {
        std::sort(grupe.begin(), grupe.end(), lygintiPagalPavarde);   
    }
    else if (rusiavimas == 3)
    {
        std::sort(grupe.begin(), grupe.end(),
        [pasirinkimas](const studentas &a, const studentas& b)
        {
            return lygintiPagalGalutiniBala(a, b, pasirinkimas);
        });
    }
}
void rikiuotiStudentus(std::list<studentas>& grupe, int rusiavimas, int pasirinkimas)
{
    if (rusiavimas == 1)
    {
        grupe.sort(lygintiPagalVarda);
    }
    else if (rusiavimas == 2)
    {
        grupe.sort(lygintiPagalPavarde);
    }
    else if (rusiavimas == 3)
    {
        grupe.sort(
            [pasirinkimas] (const studentas &a, const studentas& b)
        {
            return lygintiPagalGalutiniBala(a, b, pasirinkimas);
        });
    }
}
