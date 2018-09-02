#include <string>
#include<fstream>
#include <cstdlib>
#include <iostream>
#include <ostream>


#include "livre.h"

using namespace std;

Livre::Livre()
{
  type = "livre";
}

Livre::~Livre()
{
}

void Livre::ajouter(void)
{
  Media::ajouter();

  cout << "Quelle est l'annee ? ";
  getline(cin, annee);
  cout << "Quel est le nombre de page ? ";
  getline(cin, nombre_page);
  cout << "Quelle est la collection ? ";
  getline(cin,collection);
  cout << "Quel est le resume ? ";
  getline(cin,resume);
  cout << " Le livre a bien ete cree" << endl;
  cout << endl;
}

bool Livre::content(string recherche)
{
  if (Media::content(recherche) == true) 
  return true;
  else if (nombre_page.find(recherche)<nombre_page.size()) 
  return true;
  else if (annee.find(recherche)<annee.size())
  return true;
  else if (resume.find(recherche)<resume.size()) 
  return true;
  else if (collection.find(recherche)<collection.size())
  return true;
  
  else return false;
}

void Livre::detailler(void)
{
  Media::detailler();

  cout << "L'anee du livre est "<<annee<<endl;
  cout << "Son nombre de page est "<<nombre_page<<endl;
  cout << "Sa Collection est  "<<collection<<endl;
  cout << "Spn resume est "<<resume<<endl;
  cout << endl;
}



istream & Livre::charger(istream &is)
{
  
    Media::charger(is);
    getline(is,annee);
    getline(is,nombre_page);
    getline(is,collection);
    getline(is,resume);
    return is;
  
}

void Livre::sauvgarder(ostream &os)
{
  
    Media::sauvgarder(os);  
    os << annee << endl;  
    os << nombre_page<< endl;  
    os << collection<< endl;  
    os << resume<< endl;  
  
}


