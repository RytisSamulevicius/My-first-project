#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <fstream>
#include <string>
#include <vector>

#include "studentas.h"

std::string pasirinktiFaila();
void printas(std::ofstream& failas, const studentas& A, int pasirinkimas, int w_vardas, int w_pavarde);
void skaiciavimas(studentas& B);
void skirstyti(const std::vector<studentas>& visi, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietiakai, int pasirinkimas);
bool NuskaitytiFaila(const std::string& failo_pavadinimas, std::vector<studentas>& grupe);
void IrasytiIFaila(const std::string& failo_pavadinimas, const std::vector<studentas>& studentai, int pasirinkimas);        
bool lygintiPagalVarda(const studentas& a, const studentas& b);
bool lygintiPagalPavarde(const studentas& a, const studentas& b);
bool lygintiPagalGalutiniBala(const studentas& a, const studentas& b, int pasirinkimas);
#endif