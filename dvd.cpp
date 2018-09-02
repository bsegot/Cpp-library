#include <string>
#include<fstream>
#include <cstdlib>
#include <ostream>
#include <iostream>


#include "dvd.h"

using namespace std;

Dvd::Dvd()
{
  type = "dvd";
}

Dvd::~Dvd()
{
}


void Dvd::ajouter()
{
  Media::ajouter();

    cout << "Quelle est la duree du dvd? ";
    getline(cin,duree);
	cout << "Quelle est sa maison de production ? ";
    getline(cin,maison_production);
    cout << "Quel est son nombre de piste ? ";
    getline(cin,nombre_piste);
    cout << "Le dvd a bien ete cree " << endl;
    cout << endl;
    
}

bool Dvd::content(string recherche)
{
  if (Media::content(recherche) == true)
  return true;
  else if (nombre_piste.find(recherche) < nombre_piste.size()) 
  return true;
  else if (maison_production.find(recherche)<maison_production.size())
  return true;
  else if (duree.find(recherche)<duree.size())
  return true;

  else return false;
}


void Dvd::detailler(void)
{
  Media::detailler();

    cout << "la duree du dvd est  "<<duree<<endl;
    cout << "Sa maison de production est "<<maison_production<<endl;
    cout << "Son nombre de piste est "<<nombre_piste<<endl;
    cout << endl;
}



istream & Dvd::charger(istream &is)
{
  
  Media::charger(is);  
       getline(is,duree);  
       getline(is,maison_production);  
       getline(is,nombre_piste);  
      return is;
      
}

void Dvd::sauvgarder(ostream &os)
{
  
    Media::sauvgarder(os);  
    os << duree << endl;  
    os << maison_production << endl;   
    os << nombre_piste << endl;  
  
}

