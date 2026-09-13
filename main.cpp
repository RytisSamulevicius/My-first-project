//Studentu ivertinimai
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
using std::string;
using std::vector;
struct studentas{
    string vardas, pavarde;
    vector<int> paz;
    int exam;
    double rez;
    };
    
void printas( studentas A);

int main()
{
  std::vector<studentas> grupe;
  int k;
  studentas A;
  std::cout<<"Kiek studentu yra sarase: ";
  int n;
  std::cin>>n;
  for (int j=0;j<n;j++)
  {
      
  std::cout<<"Iveskite per tarpa studento varda ir pavarde: ";
  std::cin >> A.vardas >> A.pavarde;
  std::cout<<"Iveskite semestro paz. kieki: ";std::cin>>k;
  for (int i = 0; i < k; i++){
      std::cout<<"Iveskite " <<i + 1<< "paz.: ";
      //cin>>A.paz[i];
      int a;
      std::cin>>a;
      A.paz.push_back(a);
  }
  std::cout<<"Iveskite semestro Egzamino paz.: ";std::cin>>A.exam;
  A.rez=0.4*std::accumulate(A.paz.begin(), A.paz.end(), 0.0)/A.paz.size() + 0.6*A.exam;
  grupe.push_back(A);
  A.pavarde.clear();
  A.vardas.clear();
  A.paz.clear();
  
  }
  std::cout<<"Studentu duom.: \n";
  std::cout<<"|"<<std::left<<std::setw(15)<<"Vardas"<<"|"<<std::left<<std::setw(20)<<"Pavarde";
  std::cout<<"|"<<std::right<<std::setw(10)<<"Gal."<<"|\n";
  int br=15+20+10+2;
  std::cout <<"|";for (int i=0;i<br; i++) std::cout<<"-"; std::cout<<"|\n";
  
  for (studentas B:grupe) printas(B);
}
void printas( studentas A){
    std::cout<<"|"<<std::left<<std::setw(15)<<A.vardas<<"|"<<std::left<<std::setw(20)<<A.pavarde;
    std::cout<<"|"<<std::right<<std::setw(10)<<std::fixed<<std::setprecision(2)<<A.rez<<"|\n";
}
