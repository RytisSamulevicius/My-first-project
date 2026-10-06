#include "generavimas.h"

#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <string>


using std::string;

void generuotiFaila(const string& pavadinimas, int kiekis, int nd_kiekis)
{

    std::ofstream failas(pavadinimas);
    if (!failas.is_open()) {
        std::cerr << "Nepavyko sukurti failo: " << pavadinimas << "\n";
        return;
    
    }
    failas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 1; i <= nd_kiekis; ++i)
    {
        failas << std::right << std::setw(10) << ("ND" + std::to_string(i));
    }
    failas << std::right << std::setw(10) << "Egz." << "\n";

    for (int i = 1; i <= kiekis; i++)
    {
        failas << std::left << std::setw(20) << ("Vardas" + std::to_string(i)) << std::setw(20) << ("Pavarde" + std::to_string(i));
        for (int j = 0; j <= nd_kiekis; j++)
        {
            failas << std::right << std::setw(10) << rand() % 10 + 1;
        }
        failas << "\n";
    }
    failas.close();

}
void generuotiVisusFailus()
{
    int dydziai[] = {1000, 10000, 100000, 1000000, 10000000};
    for (int dydis : dydziai)
    {
        auto pradzia = std::chrono::high_resolution_clock::now();
        generuotiFaila("studentai" + std::to_string(dydis) + ".txt", dydis);
        auto pabaiga = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> laikas = pabaiga - pradzia;

        std::cout << dydis << " Irasu failo kurimo laikas: " << laikas.count() << " sekundžių\n";
    }
} 
