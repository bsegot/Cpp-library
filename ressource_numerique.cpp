#include <string>
#include<fstream>
#include <ostream>
#include <cstdlib>
#include <iostream>


#include "ressource_numerique.h"

using namespace std;

Ressource_numerique::Ressource_numerique()
{
  
  type = "ressource_num";
  
}

Ressource_numerique::~Ressource_numerique(void)
{
}

bool Ressource_numerique::content(string recherche)
{
  
  if (Media::content(recherche) == true)
  return true;
  else if (taille.find(recherche)<taille.size()) 
  return true;
  else if (chemin_acces.find(recherche)<chemin_acces.size()) 
  return true;
  else if (format.find(recherche)<format.size())
  return true;

  else return false;

void Ressource_numerique::ajouter(void)
{
  
  Media::ajouter();

  cout << "Quelest le format ? ";
  getline(cin,format);
  cout << "Quelest le chemin d'acces ? ";
  getline(cin,chemin_acces);
  cout << "Quel est la taille ? ";
  getline(cin,taille);
  cout <<"-- "<< format << " a bien ete cree "<<endl;

}

void Ressource_numerique::detailler(void)
{
  Media::detailler();

  cout << "Le format est " << format << endl;
  cout << "Le Chemin d'acces est  "<<chemin_acces<<endl;
  cout << "La taille de cette ressource est  "<<taille<<endl;
  cout << endl;
  
}


  
}

istream & Ressource_numerique::charger(istream &is)
{
  
    Media::charger(is);  
    getline(is,format); 
    getline(is,chemin_acces); 
    getline(is,taille); 
  return is;
  
}


void Ressource_numerique::sauvgarder(ostream &os)
{
  
    Media::sauvgarder(os);  
    os << format << endl;  
    os << chemin_acces << endl;  
    os << taille << endl;  
  
}


