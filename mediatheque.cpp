#include <string>
#include<fstream>
#include <cstdlib>
#include <iostream>


#include "mediatheque.h"

using namespace std;


Bibliotheque::Bibliotheque()
{
    
  liste_neg = (Media**) new Media[TAILLE];  
  liste_ok = (Media**) new Media[TAILLE];


  identifiant = 0;
  taille_liste_neg = 0;
  taille_liste_ok = 0;


}

void Bibliotheque::add(string type)
{

  Media *nx_media = new Media();

  if (!type.compare(CD))
    {
      Cd *nx_cd= new Cd();
      nx_media = nx_cd;
    }

  else if (!type.compare(LIVRE))
    {
      Livre *nx_livre = new Livre();
      nx_media = nx_livre;
    }
    
      else if (!type.compare(DVD))
    {
      Dvd *nx_dvd= new Dvd();
      nx_media = nx_dvd;
    }


  else if (!type.compare(REVUE))
    {
      Revue *nx_revue= new Revue();
      nx_media = nx_revue;
    }

  else if (!type.compare(RESSOURCE_NUM))
    {
      Ressource_numerique *nx_ressource_numerique = new Ressource_numerique();
      nx_media = nx_ressource_numerique;
    }

  else if (!type.compare(VHS))
    {
      Vhs *nx_vhs = new Vhs();
      nx_media = nx_vhs;
    }
    
  else
    {
      cout << "Le type est de ce media est inconnu" << endl;
      return;
    }

  this->rebuild();			//  On recree la mediatheque
  nx_media->ajouter();		// On effectue la completion manuelle de nx media
  nx_media->make_id(identifiant);	// On fait la creation de l'identifiant
  liste_ok[taille_liste_ok] = nx_media;	// On Sauvgarde le media dans la mdiatheque
  taille_liste_ok++;				// On incrementation la taille associee a la taille de la mediatheque
  identifiant++;					// On incrementation l'identifiant
}

void Bibliotheque::supress(unsigned int id)
{
  unsigned int i;

  this->rebuild();			//  On recree la mediatheque

  i=position_media(id);			//On recupere la poistion du media dans la mediatheque qui a l'identifiant id

  if (i != taille_liste_ok)			// si celui ci existe
    {
      delete liste_ok[i];			// on supprime le media
      liste_ok[i] = NULL;			// on replace la liste_ok au pointeur NULL
      this->reorganize();		
      cout <<"   "<<id<<" a bien ete supprime **" << endl;
    }
  else
    cout << "Aucun media associe  a cette identifiant." << endl;
}

void Bibliotheque::list(void)
{
  unsigned int i;

  if (taille_liste_ok == 0)			// Verification la mediatheque existe
    {
      cout << " aucun media " << endl;
      return;
    }

  cout << "le listage commence" << endl;

  for (i=0;i<taille_liste_ok;i++)
    {
      cout << endl;				
      cout << "media " << i << " : "<< endl << endl;
      liste_ok[i]->lister();		
    }

  cout << "le listage est fini" << endl;
}


void Bibliotheque::louer(unsigned int id)
{
  unsigned int i;

  i=position_media(id);			//On recupere la poistion du media dans la mediatheque qui a l'identifiant id

  if (i != taille_liste_ok)			// On Verification que l'identifiant existe
    {
        liste_ok[i]->location();
    }
  else
    cout << "Il n y a aucun media associe a l'identifiant "<< id << endl;
}

void Bibliotheque::show(unsigned int id)
{
  unsigned int i;

  i=position_media(id);			//On recupere la poistion du media dans la mediatheque qui a l'identifiant id

  if (i != taille_liste_ok)			// On Verification que l'identifiant existe
    {
      liste_ok[i]->detailler();		
      cout << endl;				
    }
  else
    cout << "Il n y a aucun media associe a l'identifiant "<< id << endl;

}



void Bibliotheque::retour(unsigned int id)
{
  unsigned int i;

  i=position_media(id);			//On recupere la poistion du media dans la mediatheque qui a l'identifiant id

  if (i != taille_liste_ok)			// On Verification que l'identifiant existe
    {
        liste_ok[i]->ramener();
    }
  else
    cout << "Il n y a aucun media associe a l'identifiant "<< id << endl;
}

void Bibliotheque::reset(void)
{
  unsigned int i;

  this->rebuild();	// On recree la mediatheque

  for(i=0;i<taille_liste_ok;i++)	// On parcourt les elements de la mediatheque un a un
    {
      delete liste_ok[i];		// On Supprime le ieme media
      liste_ok[i] = NULL;		// On met liste_ok au pointeur NULL
    }

  identifiant = 0;

  taille_liste_ok = 0;			// Reinitialisation de la taille de le mediatheque
  cout <<"Le reset a bien ete effectue " << endl;
}


void Bibliotheque::reorganize(void)
{
    
  unsigned int i,j,t;

  j = taille_liste_ok;
  t = 0;


  for(i=0;i<j;i++)
    {
      if (liste_ok[i] != NULL)
	{
	    
	  liste_ok[t] = liste_ok[i];
	  t++;
	  
	}
      taille_liste_ok = t;
    }
}


void Bibliotheque::save(const string  &nom_fichier)
{
  ofstream fichier;
  unsigned int i;


  this->rebuild();					// On recree la mediatheque

  fichier.open(nom_fichier.c_str(), ios::out);	//On ouvre le fichier en ecriture

  for (i=0;i<taille_liste_ok;i++)				// On parcourt les elements de la mediatheque un a un
    {
      liste_ok[i]->sauvgarder(fichier);		// On sauvgarde l'ieme  element media
    }

  fichier.close();							
  cout <<"La mediatheque a ete sauvegardee dans le fichier "<<nom_fichier<<""<<endl;

}

unsigned int Bibliotheque::position_media(unsigned int id)
{

  unsigned int i,position_media = taille_liste_ok; // initialisation de la position sur la taille max

  for(i=0;i<taille_liste_ok;i++)				// On parcour les elements de la mediatheque un a un 
    {
      if (liste_ok[i]->id() == id)			// On teste de l'id du media i
	{
	  position_media = i;				// on memorise l'indice
	  break;					
	}
    }
  return position_media;					// On renvoie la position du media
}

bool Bibliotheque::load(const string &nom_fichier)
{
  Media *nx_media = new Media();
  string type;
  ifstream fichier,tmp;
  string etat;

  fichier.open(nom_fichier.c_str(), ios::in);   //ouverture en lecture du fichier


  if (fichier.fail())
    {
      cout << "Fichier non trouve." << endl;
      return 0;
    }

  this->reset();					// Avant de charger la mediatheque on reset

  while ( getline(fichier,type))
    {
      if (!type.compare(CD))
	{
	  Cd *nx_cd= new Cd();
	  nx_media = nx_cd;
	}

      else if (!type.compare(LIVRE))
	{
	  Livre *nx_livre = new Livre();
	  nx_media = nx_livre;
	}
	      else if (!type.compare(DVD))
	{
	  Dvd *nx_dvd= new Dvd();
	  nx_media = nx_dvd;
	}
      else if (!type.compare(VHS))
	{
	  Vhs *nx_vhs = new Vhs();
	  nx_media = nx_vhs;
	}

      else if (!type.compare(REVUE))
	{
	  Revue *nx_revue= new Revue();
	  nx_media = nx_revue;
	}

      else if (!type.compare(RESSOURCE_NUM))
	{
	  Ressource_numerique *nx_ressource_numerique = new Ressource_numerique();
	  nx_media = nx_ressource_numerique;
	}

       nx_media->charger(fichier); 
       identifiant = (nx_media->id() > identifiant) ? nx_media->id() : identifiant; 
       nx_media->detailler(); 

      liste_ok[taille_liste_ok] = nx_media;			// On sauvegarde le media dans la mediatheque
      taille_liste_ok++;
    }

  identifiant ++;
  return 1;
  
}



void Bibliotheque::rebuild(void)	
{
  unsigned int i;

  for(i=0;i<taille_liste_neg;i++)
    {
      liste_ok[taille_liste_ok] = liste_neg[i];
      taille_liste_ok++;
    }
  taille_liste_neg = 0;
}

unsigned int Bibliotheque::search(string chaine)
{
  unsigned int i=0,nbr=0;

  for(i=0;i<taille_liste_ok;i++)				// On parcour les elements de la mediatheque un a un 
    {
      if(liste_ok[i]->content(chaine) == false) // Le media contient il une chaine
	{
	  liste_neg[taille_liste_neg]=liste_ok[i];	// On transfère le media qui ne correspond pas aa la recherche dans le "taille_liste_neg"
	  liste_ok[i] = NULL;					// liste_ok mise au pointeur NULL
	  taille_liste_neg++;					// On incremente la taille de la liste des media qui ne correspondent pas a ceux recherches
	}
      else
	nbr++;							// On incremente la variable du resultat
    }

  this->reorganize();						
  return nbr;
}



void Bibliotheque::help2(void)
{
  cout << "Les fonction suivantes sont disponibles "<<endl;
  cout << "------------ bye"<<endl;
  cout << "-------------change"<<endl;
  cout << "-------------clear"<<endl;
  cout << "-------------help"<<endl;
  cout << "-------------list"<<endl;
  cout << "-------------louer {id}"<<endl;
  cout << "-------------search {texte}"<<endl;
  cout << "-------------show {id}"<<endl;

void Bibliotheque::help(void)
{
  cout << "Les fonction suivantes sont disponibles "<<endl;
  cout << "----------- add {cd,livre, dvd , ressource_num, vhs, revue}"<<endl;
  cout << "----------- bye"<<endl;
  cout << "----------- change"<<endl;
  cout << "----------- clear"<<endl;
  cout << "----------- delete {id}"<<endl;
  cout << "----------- help"<<endl;
  cout << "----------- list"<<endl;
  cout << "----------- load {nom du fichier}"<<endl;
  cout << "----------- louer {id}"<<endl;
  cout << "----------- reset"<<endl;
  cout << "----------- retour {id}"<<endl;
  cout << "----------- save {nom du fichier}"<<endl;
  cout << "----------- search {texte}"<<endl;
  cout << "----------- show {id}"<<endl;
}


}


Bibliotheque::~Bibliotheque()
{
  this->reset();
}
