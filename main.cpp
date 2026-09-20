//Studentu ivertinimai
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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

void printas( studentas A, int pasirinkimas);

int main()
{
  srand(time(0));
  vector<studentas> grupe;
  studentas A;
  int meniu;

  while(true)
  {
  cout<<"\n===== Meniu =====\n";
  cout<<"1 - Ivesti studentu pazymius ranka\n";
  cout<<"2 - Generuoti studentu pazymius atsitiktinai\n";
  cout<<"3 - Rodyti rezultatus\n";
  cout<<"4 - Baigti darba\n";
  cout<< "Meniu pasirinkimas: ";
  cin>>meniu;

  if (meniu == 4) break;

  if (meniu ==  1 || meniu == 2)
  {
      int budas = meniu;

      while (true)
      {
      cout<<"Iveskite varda "; cin>>A.vardas;
      cout<<"Iveskite pavarde "; cin>>A.pavarde;
      while (true){
          int n; char kl;
          if (budas == 1){
              cout<<"Iveskite semestro paz.: "; cin>>n;
          } else {
              n =rand() % 10 + 1;
              cout << "Sugeneruotas namu darbu pazymys: "<<n<<"\n";
          }
          A.paz.push_back(n);
          cout<<"Ar studentas turi dar pazymiu? t/n "; cin>>kl;
          if (kl =='n' || kl == 'N') break;
          }
      if (budas == 1){
          cout<<"Iveskite semestro Egzamino paz.: ";cin>>A.exam;
      }  else {
           A.exam = rand() % 10 + 1;
           cout << "Sugeneruotas egzamino pazymys: "<<A.exam<<"\n";
          }
          vector <int> surikiuoti_paz = A.paz;
          std::sort(surikiuoti_paz.begin(), surikiuoti_paz.end());
          double mediana;
          int dydis = surikiuoti_paz.size();
          if (dydis%2==0)
              mediana=(surikiuoti_paz[dydis/2-1] + surikiuoti_paz[dydis/2]) / 2.0;
          else
              mediana=surikiuoti_paz[dydis/2];

          A.vid_rez=0.4*std::accumulate(A.paz.begin(), A.paz.end(), 0.0)/A.paz.size() + 0.6*A.exam;
          A.med_rez = 0.4*mediana + 0.6*A.exam;
          grupe.push_back(A);
          A.pavarde.clear();
          A.vardas.clear();
          A.paz.clear();
          char kl;
          cout<<"Ar turite dar studentu? t/n "; cin>>kl;
              if (kl == 'n' || kl == 'N') break;
      }
}
else if (meniu == 3)
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

    cout<<"\nStudentu duom.: \n";
    cout<<"|"<<left<<setw(15)<<"Vardas"<<"|"<<left<<setw(20)<<"Pavarde";
    if (pasirinkimas==1)
        cout<<"|"<<right<<setw(10)<<"Gal.(vid)";
    else if (pasirinkimas==2)
        cout<<"|"<<right<<setw(10)<<"Gal.(med)";
    else
        cout<<"|"<<right<<setw(10)<<"Gal.(vid)"<<"|"<<right<<setw(10)<<"Gal.(med)";
    cout<<"|\n";

    int br=15+20+10+3;
    int br1=15+20+10+10+4;

    if (pasirinkimas==1 || pasirinkimas==2) {
        for (int i=0;i<br;i++) cout<<"-";
    } else {
         for (int i=0;i<br1;i++) cout<<"-";
    }
    cout<<"|\n";

    for(studentas B:grupe) printas(B, pasirinkimas);
 }
 else
     cout << "Tokio pasirinkimo nera.\n";
 }
}

void printas( studentas A, int pasirinkimas){
    cout<<"|"<<left<<setw(15)<<A.vardas<<"|"<<left<<setw(20)<<A.pavarde;
    cout<<std::fixed<<std::setprecision(2);

    if (pasirinkimas==1)
        cout<<"|"<<right<<setw(10)<<std::fixed<<std::setprecision(2)<<A.vid_rez;
    else if (pasirinkimas == 2)
        cout<<"|"<<right<<setw(10)<<std::fixed<<std::setprecision(2)<<A.med_rez;
    else
         cout<<"|"<<right<<setw(10)<<A.vid_rez<<"|"<<right<<setw(10)<<A.med_rez;

    cout<<"|\n";
}

    cout<<"|\n";
}


