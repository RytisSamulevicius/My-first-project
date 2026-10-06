#include "generavimas.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <string>


using std::string;

void generuotiFaila(const string& pavadinimas, int kiekis, int nd_kiekis)
{
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 10);


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
            failas << std::right << std::setw(10) << dist(gen);
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
        generuotiFaila("studentai" + std::to_string(dydis) + ".txt", dydis);
        std::cout << "Sugeneruotas failas su " << dydis << " irasu\n";
    }
}