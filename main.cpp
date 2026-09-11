#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using std::string;
using std::vector;
struct studentas{
    string vardas, pavarde;
    vector<int> paz;
    int exam;
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
  A.rez = 0,4*std::accumulate(A.paz.begin(), A.paz.end(), 0.0)/A.paz.size() + 0.6 *A.egz;
  grupe.push_back(A);
  A.pavarde.clear();
  A.vardas.clear();
  A.paz.clear();
  
  }
  std::cout<<"Studentu duom.: \n";
  for (studentas B:grupe) printas(B);
}
void printas( studentas A){
    std::cout<<"|"<<std::left<<std::setw(10)<<A.vardas<<"|"<<std::left<<std::setw(10)<<A.pavarde<<"|";
  for (int p: A.paz) std::cout<<std::right<<std::setw(3)<<p<<"|";
  std::cout<<std::right<<std::setw(5)<<A.exam<<"|\n";
}

