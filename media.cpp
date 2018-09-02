#include <string>
#include <ostream>
#include<fstream>
#include <cstdlib>
#include <iostream>


#include "media.h"

using namespace std;

Media::Media()
{
}

unsigned int Media::id(void)
{
  return  identifiant;
}

void Media::make_id(unsigned int id)
{
  identifiant = id;
}

void Media::lister(void)
{
  Media::detailler();
}


void Media::ajouter()
{
  cout << "Quel est le titre du media? ";
  getline(cin,titre);
  cout << "Quel est l'auteur ? ";
  getline(cin,auteur);
  cout << "Quel est l'état ? ";
  getline(cin,etat);

  nb_total=0;
  while((nb_total == 0))
    {
    cout << "Quel est le nombre d'exemplaires? ";
    getline(cin,nombre_total);
    nb_total = atoi(nombre_total.c_str());
    if (nb_total == 0)
      {
        cout << "Le nombre d'exemplaire doit etre >0" << endl;
        nombre_total = "0";
      }
    nb_restant=nb_total;
    
    }
}

bool Media::content(string recherche)
{
  if (etat.find(recherche) < etat.size()) return true;
  else if (auteur.find(recherche)<auteur.size()) return true;
  else if (titre.find(recherche)<titre.size()) return true;
  else if (type.find(recherche) < type.size()) return true;
  else return false;
}


void Media::detailler(void)
{
  cout<< "Le type type est "<<type<<endl;
  cout << "L'identifiant est " << identifiant << endl;
  cout << "Le titre est "<<titre<<endl;
  cout << "L'auteur est "<<auteur<<endl;
  cout << "L'Etat est "<<etat<<endl;
  cout << "Le nombres d'elements achete est " << nb_total<<endl;
  cout << "Le Nombre d'exemplaires qui restent est " << nb_restant<<endl;
}



void Media::sauvgarder(ostream &os)
{
    os << type<< endl;  
    os << identifiant<< endl;  
    os << etat<< endl;  
    os << titre << endl;  
    os << auteur << endl;  
    os << nb_total << endl;  
    os << nb_restant << endl;  
}

istream&  Media::charger(istream &is)
{
    string tmp;
    is >> identifiant; 
    getline(is,tmp); 
    getline(is,etat); 
    getline(is,titre); 
    getline(is,auteur); 
    getline(is,nombre_total); 
    nb_total = atoi(nombre_total.c_str()); 
    getline(is,nombre_restant); 
    nb_restant = atoi(nombre_restant.c_str()); 
  return is;
}

void Media::ramener(void)
{
    if (nb_restant >= nb_total)
        cout << "les exemplaires sont deja tous au magasin"<<endl;
    else
    {
        nb_restant++;
        cout << " L'exemplaire \""<<titre<<"\"  a ete rendu "<<endl;
    }
}


void Media::location(void)
{
    if (nb_restant <= 0)
        cout << "Il n'y a plus d'exemplaires disponibles en stock"<<endl;
    else
    {
        nb_restant--;
        cout << "** Vous venez de louer \"" << titre <<"\" **"<<endl;
    }
}


Media::~Media()
{
}
