#include <ostream>
#include <string>
#include<fstream>
#include <cstdlib>
#include <iostream>


#include "cd.h"

using namespace std;

Cd::Cd()
{
  type = "cd";
}

Cd::~Cd()
{
}


void Cd::ajouter(void)
{
  Media::ajouter();

  cout << "Quelle est sa maison de production ? ";
  getline(cin, maison_production);
  cout << "Quel est son nombre de piste ? ";
  getline(cin,nombre_piste);
  cout << "Quel est sa duree ? ";
  getline(cin,duree);
  cout << "Le cd a bien ete cree" << endl;
  cout << endl;
  
}

void Cd::detailler(void)
{
  Media::detailler();
  cout << "Sa maison de production est "<<maison_production<<endl;
  cout << "Son nombre de piste est "<<nombre_piste<<endl;
  cout << "Sa duree est "<<duree<<endl;
  cout << endl;

}

bool Cd::content(string recherche)
{
  if (Media::content(recherche) == true) 
  return true;
  else if (duree.find(recherche)<duree.size())
  return true;
  else if (nombre_piste.find(recherche)<nombre_piste.size()) 
  return true;
  else if (maison_production.find(recherche)<maison_production.size())
  return true;

  else return false;
}

void Cd::sauvgarder(ostream &os)
{
  
  Media::sauvgarder(os);
    os << maison_production << endl;  
    os << nombre_piste << endl;   
    os << duree << endl;  
  
}

istream & Cd::charger(istream &is)
{
  
  Media::charger(is);
    getline(is,maison_production);  
    getline(is,nombre_piste);  
    getline(is,duree);  
  return is;
  
}
