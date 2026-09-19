//Studentu ivertinimai
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;
using std::cout;

struct studentas{
    string vardas, pavarde;
    vector<int> paz;
    int exam;
    double vid_rez, med_rez;
};
    
void printas( studentas A, int pasirinkimas);

int main()
{
  std::vector<studentas> grupe;
  studentas A;
  while (true)
  {
  std::cout<<"Iveskite varda "; cin>>A.vardas;
  std::cout<<"Iveskite pavarde "; cin>>A.pavarde;
  while (true){
      int n; char kl;
      std::cout<<"Iveskite semestro paz.: ";std::cin>>n; A.paz.push_back(n);
      std::cout<<"Ar studentas turi dar pazymiu? t/n "; cin>>kl;
      if (kl =='n' || kl == 'N') break;
      }
  std::cout<<"Iveskite semestro Egzamino paz.: ";std::cin>>A.exam;
  A.vid_rez=0.4*std::accumulate(A.paz.begin(), A.paz.end(), 0.0)/A.paz.size() + 0.6*A.exam;
      vector <int> surikiuoti_paz = A.paz;
      std::sort(surikiuoti_paz.begin(), surikiuoti_paz.end());
      double mediana;
      int dydis = surikiuoti_paz.size();
      if (dydis%2==0)
          mediana=(surikiuoti_paz[dydis/2-1] + surikiuoti_paz[dydis/2]) / 2.0;
      else
          mediana=surikiuoti_paz[dydis/2];
          
      A.med_rez = 0.4*mediana + 0.6*A.exam;          
      grupe.push_back(A);
      A.pavarde.clear();
      A.vardas.clear();
      A.paz.clear();
      char kl;
      cout<<"Ar turite dar studentu? t/n "; cin>>kl;
          if (kl == 'n' || kl == 'N') break;
  }
  int pasirinkimas;
  std::cout<<"\nJeigu nori, kad galutini bala nusakytu vidurkis, spauskite 1\n";
  std::cout<<"\nJeigu nori, kad galutini bala nusakytu mediana, spauskite 2\n";
  std::cout<<"\nJeigu nori, kad galutini bala nusakytu vidurkis ir mediana, spauskite 3\n";
  std::cout<<"Pasirinkimas: ";
  std::cin >> pasirinkimas;
  
  std::cout<<"\nStudentu duom.: \n";
  std::cout<<"|"<<std::left<<std::setw(15)<<"Vardas"<<"|"<<std::left<<std::setw(20)<<"Pavarde";
  if (pasirinkimas==1)
      std::cout<<"|"<<std::right<<std::setw(10)<<"Gal.(vid)";
  else if (pasirinkimas==2)
      std::cout<<"|"<<std::right<<std::setw(10)<<"Gal.(med)";
  else 
      std::cout<<"|"<<std::right<<std::setw(10)<<"Gal.(vid)"<<"|"<<std::right<<std::setw(10)<<"Gal.(med)";
  std::cout<<"|\n";
  
  int br=15+20+10+3;
  int br1=15+20+10+10+4;
  
  if (pasirinkimas==1 || pasirinkimas==2) {
      for (int i=0;i<br;i++) std::cout<<"-";
  } else {
       for (int i=0;i<br1;i++) std::cout<<"-";
  }
  std::cout<<"|\n";
  
  for(studentas B:grupe) printas(B, pasirinkimas);
}

void printas( studentas A, int pasirinkimas){
    std::cout<<"|"<<std::left<<std::setw(15)<<A.vardas<<"|"<<std::left<<std::setw(20)<<A.pavarde;
    std::cout<<std::fixed<<std::setprecision(2);
    
    if (pasirinkimas==1)
        std::cout<<"|"<<std::right<<std::setw(10)<<std::fixed<<std::setprecision(2)<<A.vid_rez;
    else if (pasirinkimas == 2)
        std::cout<<"|"<<std::right<<std::setw(10)<<std::fixed<<std::setprecision(2)<<A.med_rez;
    else
         std::cout<<"|"<<std::right<<std::setw(10)<<A.vid_rez<<"|"<<std::right<<std::setw(10)<<A.med_rez;
    
    std::cout<<"|\n";
}

