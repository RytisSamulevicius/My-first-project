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

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;

struct studentas{
    string vardas, pavarde;
    vector<int> paz;
    int exam;
    double vid_rez, med_rez;
};
string pasirinktiFaila();
void printas(const studentas& A, int pasirinkimas, int w_vardas, int w_pavarde);
void skaiciavimas( studentas& B);
bool lygintiPagalVarda(const studentas& a, const studentas& b);
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
  cout<<"5 - Baigti darba\n";
  cout<< "Meniu pasirinkimas: ";
  cin>>meniu;

  if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki 5.\n";
        continue;
    }

  if (meniu == 5) 
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
    std::ifstream failas (failo_pavadinimas);
    if (!failas.is_open()){
        cout << "Nepavyko atidaryti failo " << failo_pavadinimas << "\n";
        continue;
    }

    grupe.clear();
    string eilute;
    std::getline(failas, eilute);

    while(std::getline(failas, eilute))
    {
        std::istringstream s(eilute);
        studentas S;
        s >> S.vardas >> S.pavarde;

        vector<int> rezultatai;

        string x;

        while(s >> x)
        {
            if(x != "1" && x != "2" && x != "3" && x != "4" && 
                x != "5" && x != "6" && x != "7" && x != "8" &&
                x != "9" && x != "10")
             {
                cout << "Klaida faile: " << eilute << "'\n";
                rezultatai.clear();
                break;
             }
            rezultatai.push_back(std::stoi(x));
        }
        if (rezultatai.empty()) continue;

        S.exam = rezultatai.back();
        rezultatai.pop_back();
        S.paz = rezultatai;

        skaiciavimas(S);

        grupe.push_back(std::move(S));
        
    }
    failas.close();

    std::sort(grupe.begin(), grupe.end(), lygintiPagalVarda);
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

    cout<<"\nStudentu duom.: \n";
    cout<<"|"<<left<<setw(w_vardas)<<"Vardas"<<"|"<<left<<setw(w_pavarde)<<"Pavarde";
    if (pasirinkimas==1)
        cout<<"|"<<right<<setw(10)<<"Gal.(vid)";
    else if (pasirinkimas==2)
        cout<<"|"<<right<<setw(10)<<"Gal.(med)";
    else
        cout<<"|"<<right<<setw(10)<<"Gal.(vid)"<<"|"<<right<<setw(10)<<"Gal.(med)";
    cout<<"|\n";

    int br = w_vardas + w_pavarde + 10 + 3;
    int br1= w_vardas + w_pavarde + 10 + 10 + 4;

    if (pasirinkimas==1 || pasirinkimas==2) {
        for (int i=0;i<br;i++) cout<<"-";
    } else {
         for (int i=0;i<br1;i++) cout<<"-";
    }
    cout<<"|\n";

    for(const studentas& B:grupe) printas(B, pasirinkimas, w_vardas, w_pavarde);
 }
 else
     cout << "Tokio pasirinkimo nera.\n";
 }
}
string pasirinktiFaila()
{
    int pasirinkimas;

    while (true)
    {
        cout << "\n -----Pasirinkite faila:-----\n";
        cout << "1 - kursiokai.txt\n";
        cout << "2 - studentai10000.txt\n";
        cout << "3 - studentai100000.txt\n";
        cout << "4 - studentai1000000.txt\n";
        cout << "5 - Iveskite failo pavadinima paciam\n";
        cout << "0 - atsaukti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;
    
    
        if (cin.fail()) 
        {
           cin.clear();
           cin.ignore(10000, '\n');
           cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 0 iki 5.\n";
           continue;
        }

        switch (pasirinkimas)
         {
            case 1:
                return "kursiokai.txt";
            case 2:
                return "studentai10000.txt";
            case 3:
                return "studentai100000.txt";
            case 4:
                return "studentai1000000.txt";
            case 5:
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
bool lygintiPagalVarda(const studentas& a, const studentas& b)
{
    int nrA = std::stoi(a.vardas.substr(6));
    int nrB = std::stoi(b.vardas.substr(6));

    return nrA < nrB;
}
void printas( const studentas& A, int pasirinkimas, int w_vardas, int w_pavarde){
    cout<<"|"<<left<<setw(w_vardas)<<A.vardas<<"|"<<left<<setw(w_pavarde)<<A.pavarde;
    cout<<std::fixed<<std::setprecision(2);
    if (pasirinkimas==1)
        cout<<"|"<<right<<setw(10)<<std::fixed<<std::setprecision(2)<<A.vid_rez;
    else if (pasirinkimas == 2)
        cout<<"|"<<right<<setw(10)<<std::fixed<<std::setprecision(2)<<A.med_rez;
    else
         cout<<"|"<<right<<setw(10)<<A.vid_rez<<"|"<<right<<setw(10)<<A.med_rez;

    cout<<"|\n";
}
