#include <ostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include <iostream>



#include "vhs.h"

using namespace std;


Vhs::Vhs()
{
  type = "vhs";
}

Vhs::~Vhs()
{
}


bool Vhs::content(string recherche)
{
  
  if (Media::content(recherche) == true) 
  return true;
  
  else if (maison_production.find(recherche)<maison_production.size()) 
  return true;
  
  else if (duree.find(recherche)<duree.size()) 
  return true;
  
  else return false;
  
}

void Vhs::detailler(void)
{
  Media::detailler();

  cout << "Quelle est la duree ? "<<duree<<endl;
  cout << "Quelle est la maison de production ? "<<maison_production<<endl;
  cout << endl;
}


void Vhs::ajouter()
{
  Media::ajouter();

  cout << "Quelle est la duree ? ";
  getline(cin,duree);
  cout << "Quelle est la maison de production ? ";
  getline(cin,maison_production);
  cout << "Ressource VHS cree" << endl;
  cout << endl;
}


istream & Vhs::charger(istream &is)
{
  
  Media::charger(is);
  
  getline(is,duree);
  getline(is,maison_production);
  
  return is;
}

void Vhs::sauvgarder(ostream &os)
{
  
  Media::sauvgarder(os);
  
  os << duree << endl;
  os << maison_production << endl;
  
}


