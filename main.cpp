//Studentu ivertinimai
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <utility>
#include <chrono>
#include "generavimas.h"
#include "studentas.h"
#include "funkcijos.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;

int main()
{
  srand(time(0));

  vector<studentas> grupe;
  studentas A;
  int meniu;
  string failo_pavadinimas;

  while(true)
  {
  cout<<"\n===== Meniu =====\n";
  cout<<"1 - Ivesti studentu pazymius ranka\n";
  cout<<"2 - Generuoti studentu pazymius atsitiktinai\n";
  cout<<"3 - Nuskaityti is pasirinkto failo\n";
  cout<<"4 - Rodyti rezultatus\n";
  cout<<"5 - Sugeneruoti studentu failus\n";
  cout<<"6 - Studentai isvesti i du naujus failus vargsiukai.txt ir kietiakai.txt, bei atlikti programos veikimo analize\n";
  cout<<"7 - Baigti darba\n";
  cout<< "Meniu pasirinkimas: ";
  cin>>meniu;

  if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki 7.\n";
        continue;
    }

  if (meniu == 7) 
  {
    cout << "Programa baigia darba.\n";
    break;
  }
 

  if (meniu ==  1 || meniu == 2)
  {
      int budas = meniu;

      while (true)
      {
          cout<<"Iveskite varda "; cin>>A.vardas;
          cout<<"Iveskite pavarde "; cin>>A.pavarde;

          A.paz.clear();

          while (true){
          char kl;

          cout<<"Ar studentas turi dar pazymiu? t/n "; cin>>kl;
          if (kl =='t' || kl == 'T')
          {
             int n;

             if (budas == 1)
             {
                cout<<"Iveskite semestro paz.: "; cin>>n;
                if(cin.fail() || n < 1 || n > 10) 
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Pazymys turi buti nuo 1 iki 10.\n";
                    continue;
                }
                A.paz.push_back(n);
             }
             else
                {
                    n = rand() % 10 + 1;
                    cout << "Sugeneruotas namu darbu pazymys: "<<n<<"\n";
                    A.paz.push_back(n);
                }
          }
        
          else if (kl == 'n' || kl == 'N') 
          {
             break;
          }
          else 
          {
            cout << "Neteisingas pasirinkimas. Iveskite t arba n.\n";
          }
        }
      if (budas == 1)
      {
          while (true) 
          {
              cout<<"Iveskite semestro Egzamino paz.: ";cin>>A.exam;
              if (cin.fail() || A.exam < 1 || A.exam > 10) 
              {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Egzamino pazymys turi buti nuo 1 iki 10.\n";
                continue;
              }
              else 
              {
                break;
              }
          }  
       }
       else
       {
           A.exam = rand() % 10 + 1;
           cout << "Sugeneruotas Egzamino pazymys: "<<A.exam<<"\n";
       }
          skaiciavimas(A);
          grupe.push_back(A);
          A.pavarde.clear();
          A.vardas.clear();
          A.paz.clear();
          char kl;
          while (true)
          {
             cout<<"Ar turite dar studentu? t/n "; cin>>kl;
              if (kl == 't' || kl == 'T') break;
                else if (kl == 'n' || kl == 'N') break;
                else cout << "Neteisingas pasirinkimas. Iveskite t arba n.\n";
          }
          if (kl == 'n' || kl == 'N') break;
         
      }
}
else if (meniu == 3)
{
    failo_pavadinimas = pasirinktiFaila();
    if (failo_pavadinimas.empty()) {
        cout << "Failas nerastas. Grizti prie meniu.\n";
        continue;
    }
    NuskaitytiFaila(failo_pavadinimas, grupe);
 }

else if (meniu == 4)
{
    if (grupe.empty()) {
        cout << "Studentu dar nera. Grizti prie 1 ir 2 veiksmo meniu\n";
        continue;
    }
    int pasirinkimas;
    cout<<"\nJeigu nori, kad galutini bala nusakytu vidurkis, spauskite 1\n";
    cout<<"\nJeigu nori, kad galutini bala nusakytu mediana, spauskite 2\n";
    cout<<"\nJeigu nori, kad galutini bala nusakytu vidurkis ir mediana, spauskite 3\n";
    cout<<"Pasirinkimas: ";
    cin >> pasirinkimas;

     if (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3) {
        cout << "Neteisingas pasirinkimas.\n";
        continue;
    }

    size_t max_vardas = string("Vardas").size();
    size_t max_pavarde = string("Pavarde").size();
    for (const auto& s: grupe) {
        max_vardas = std::max(max_vardas, s.vardas.size());
        max_pavarde = std::max(max_pavarde, s.pavarde.size());
    }
    int w_vardas = static_cast<int>(max_vardas) + 2;
    int w_pavarde = static_cast<int>(max_pavarde) + 2;
    
    std::ofstream rezultatufailas("rezultatai.txt");
    if (!rezultatufailas.is_open()) {
        cout << "Nepavyko sukurti rezultatai.txt failo.\n";
        continue;
    }
    rezultatufailas<<"\nStudentu duom.: \n";
    rezultatufailas<<"|"<<left<<setw(w_vardas)<<"Vardas"<<"|"<<left<<setw(w_pavarde)<<"Pavarde";
    if (pasirinkimas==1)
        rezultatufailas<<"|"<<right<<setw(10)<<"Gal.(vid)";
    else if (pasirinkimas==2)
        rezultatufailas<<"|"<<right<<setw(10)<<"Gal.(med)";
    else
        rezultatufailas<<"|"<<right<<setw(10)<<"Gal.(vid)"<<"|"<<right<<setw(10)<<"Gal.(med)";
    rezultatufailas<<"|\n";

    int br = w_vardas + w_pavarde + 10 + 3;
    int br1= w_vardas + w_pavarde + 10 + 10 + 4;

    if (pasirinkimas==1 || pasirinkimas==2) {
        for (int i=0;i<br;i++) rezultatufailas<<"-";
    } else {
         for (int i=0;i<br1;i++) rezultatufailas<<"-";
    }
    rezultatufailas<<"|\n";

    for(const studentas& B:grupe) printas(rezultatufailas, B, pasirinkimas, w_vardas, w_pavarde);
    rezultatufailas.close();
    cout << "Rezultatai issaugoti faile rezultatai.txt\n";
   }
   else if (meniu == 5)
   {
      generuotiVisusFailus();
   }
   else if (meniu == 6)
   {
        string failo_pavadinimas = pasirinktiFaila();
        if (failo_pavadinimas.empty()) continue;

        int pasirinkimas;
        cout << "Pagal ka skirstyti? 1 - pagal vidurki, 2 - pagal mediana: ";
        cin >> pasirinkimas;

        if (cin.fail() || (pasirinkimas != 1 && pasirinkimas != 2)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Neteisingas pasirinkimas. Iveskite 1 arba 2.\n";
            continue;
        }
        int rusiavimas;
        cout << "Kaip rusiuoti rezultatus? 1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini bala: ";
        cin >> rusiavimas;

        if (cin.fail() || (rusiavimas != 1 && rusiavimas != 2 && rusiavimas != 3)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Neteisingas pasirinkimas. Iveskite 1, 2 arba 3.\n";
            continue;
        }  
        
        int bandymai;
        cout << "Kiek kartų atlikti testą? ";
        cin >> bandymai;
        if (cin.fail() || bandymai <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Neteisingas pasirinkimas. Iveskite teigiamą sveiką skaičių.\n";
            continue;
        }

        double sk_nuskaitymas = 0, sk_skirstymas = 0, sk_rusiavimas = 0;
        double sk_rasymas_vargsiukai = 0, sk_rasymas_kietiakai = 0, sk_bendras_laikas = 0;
        size_t kiekis = 0;
        int atlikimas = 0;
        
        for (int i = 0; i < bandymai; ++i)
        {
        vector <studentas> studentai, vargsiukai, kietiakai;
        auto t1 = std::chrono::high_resolution_clock::now();
        if (!NuskaitytiFaila(failo_pavadinimas, studentai)) {
            cout << "Nepavyko nuskaityti failo. Testas nutrauktas.\n";
            break;
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> nuskaitymas = t2 - t1;
        kiekis = studentai.size();

        skirstyti(studentai, vargsiukai, kietiakai, pasirinkimas);
        auto t3 = std::chrono::high_resolution_clock::now();

        if(rusiavimas == 1){
            std::sort(vargsiukai.begin(), vargsiukai.end(), lygintiPagalVarda);
            std::sort(kietiakai.begin(), kietiakai.end(), lygintiPagalVarda);
        }
        else if(rusiavimas == 2){
            std::sort(vargsiukai.begin(), vargsiukai.end(), lygintiPagalPavarde);
            std::sort(kietiakai.begin(), kietiakai.end(), lygintiPagalPavarde);
        }
        else if(rusiavimas == 3){
            std::sort(vargsiukai.begin(), vargsiukai.end(), [pasirinkimas](const studentas& a, const studentas& b) {
                return lygintiPagalGalutiniBala(a, b, pasirinkimas);
            });

        }
        auto t4 = std::chrono::high_resolution_clock::now();

        IrasytiIFaila("vargsiukai.txt", vargsiukai, pasirinkimas);
        auto t5 = std::chrono::high_resolution_clock::now();

        IrasytiIFaila("kietiakai.txt", kietiakai, pasirinkimas);
        auto t6 = std::chrono::high_resolution_clock::now();
            
        sk_nuskaitymas += std::chrono::duration<double>(t2 - t1).count();
        sk_skirstymas += std::chrono::duration<double>(t3 - t2).count();
        sk_rusiavimas += std::chrono::duration<double>(t4 - t3).count();
        sk_rasymas_vargsiukai += std::chrono::duration<double>(t5 - t4).count();
        sk_rasymas_kietiakai += std::chrono::duration<double>(t6 - t5).count();
        sk_bendras_laikas += std::chrono::duration<double>(t6 - t1).count();
        kiekis = studentai.size();
    
        }
        if (bandymas == 1)
        {
        cout << "\nFailas uzdarytas\n";
        cout << kiekis << " Irasu failo nuskaitymo laikas: " << sk_nuskaitymas  << " sekundžių\n";
        cout << kiekis << " Irasu studentu skirstymo i dvi grupes laikas: " << sk_skirstymas  << " sekundžių\n";
        cout << kiekis << " Irasu studentu rusiavimo laikas: " << sk_rusiavimas  << " sekundžių\n";
        cout << kiekis << " Irasu rezultatu irasymas i vargsiukai.txt: " << sk_rasymas_vargsiukai  << " sekundžių\n";     
        cout << kiekis << " Irasu rezultatu irasymas i kietiakai.txt: " << sk_rasymas_kietiakai  << " sekundžių\n";    
        cout << kiekis << " Irasu bendras laikas: " << sk_bendras_laikas  << " sekundžių\n"; 
        }
        else 
        {
        cout << "\nFailas uzdarytas\n";
        cout << kiekis << " Irasu failo nuskaitymo laiko vidurkis: " << sk_nuskaitymas / bandymai << " sekundžių\n";
        cout << kiekis << " Irasu studentu skirstymo i dvi grupes laiko vidurkis: " << sk_skirstymas / bandymai << " sekundžių\n";
        cout << kiekis << " Irasu studentu rusiavimo laiko vidurkis: " << sk_rusiavimas / bandymai << " sekundžių\n";
        cout << kiekis << " Irasu rezultatu irasymas i vargsiukai.txt laiko vidurkis: " << sk_rasymas_vargsiukai / bandymai << " sekundžių\n";     
        cout << kiekis << " Irasu rezultatu irasymas i kietiakai.txt laiko vidurkis: " << sk_rasymas_kietiakai / bandymai << " sekundžių\n";    
        cout << kiekis << " Irasu bendras laiko vidurkis: " << sk_bendras_laikas / bandymai << " sekundžių\n"; 
        }
        
        
   } 
   else
   {
      cout << "Tokio pasirinkimo nera.\n";
   } 
  }
  return 0;

}

