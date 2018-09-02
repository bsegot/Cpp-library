#include <string>
#include <cstdlib>
#include <iostream>


#include "revue.h"

using namespace std;

Revue::Revue()
{
  nbr_article = 0;
  type = "revue";
}

Revue::~Revue()
{
}


void Revue::ajouter(void)
{
  string nom_article_tmp;
  unsigned int i,j=0;


    Media::ajouter();

    cout << "Quelle est l'annee ? ";
    getline(cin, annee);
    cout << "Quel est le nombre de page ?";
    getline(cin, nombre_page);
    cout << "Quel est la collection ? ";
    getline(cin,collection);
    cout << "Quel est son resume ? ";
    getline(cin,resume);
    cout << "Quel est son editeur ? ";
    getline(cin,editeur);

    while((nbr_article == 0) && ( j < NBR_DDE))
      {
        cout << "Quel est le nombre d'article ? ";
        
        getline(cin,nombre_article);
        nbr_article = atoi(nombre_article.c_str());

        if (nbr_article > NBR_MAX_ARTICLE)
          {
            cout << "On a atteint le nombre maximal d'articles " << endl;
           nombre_article = "0";
           nbr_article = 0;
          }
        if (nbr_article == 0)
          {
            cout << "Il faut entrer un nombre d'article valable (>0)" << endl;
            nombre_article = "0";
          }
        for (i=0;i<nbr_article;i++)
          {
            
            cout << "Entrez le nom de l'article  "<< i+1 << " : ";
            getline(cin,nom_article_tmp);
      
            nom_article[i] = nom_article_tmp.c_str();
          }
          
        j++;
      }
    cout << "La revue a ete cree" << endl;
    cout << endl;
}


bool Revue::content(string recherche)
{
  unsigned int i;
  if (Media::content(recherche) == true) 
  return true;
  else if (editeur.find(recherche)<editeur.size()) 
  return true;
  else if (annee.find(recherche)<annee.size())
  return true;
  else if (collection.find(recherche)<collection.size())
  return true;
  else if (nombre_page.find(recherche)<nombre_page.size())
  return true;
  else if (resume.find(recherche)<resume.size())
  return true;
  else if (nombre_article.find(recherche)<nombre_article.size()) 
  return true;
  else
    {
      
      for (i=0;i<nbr_article;i++)
	  if ((nom_article[i].find(recherche) < 40)) return true;
      return false;
    }
    
}

void Revue::detailler()
{
  unsigned int i;
  
  Media::detailler();

    cout << "Annee de partution "<<annee<<endl;
    cout << "Nombre de page de la revue "<<nombre_page<<endl;
	cout << "Collection de la revue "<<collection<<endl;
    cout << "Resume de la revue "<<resume<<endl;
    cout << "Editeur en question "<< editeur<<endl;
    cout << "Nombre d'article en tout "<< nombre_article<<endl;
    for (i=0;i<nbr_article;i++)
	    cout << "article numero" << i+1 << " :: "<< nom_article[i] << endl;
    cout << endl;
}


istream & Revue::charger(istream &is)
{
  
  unsigned int i;
  
  Media::charger(is); 
     getline(is,annee); 
     getline(is,nombre_page); 
	   getline(is,collection); 
     getline(is,resume); 
     getline(is,editeur); 
     getline(is,nombre_article); 
     nbr_article = atoi(nombre_article.c_str()); 
    
    for (i=0;i<nbr_article;i++)
    getline(is,nom_article[i]);
    return is;
}

void Revue::sauvgarder(ostream &os)
{
  unsigned int i;
  
  Media::sauvgarder(os);
  
      os << annee << endl; 
      os << nombre_page<< endl;
     	os << collection<< endl; 
      os << resume<< endl;
      os << editeur << endl; 
      os << nombre_article<< endl;
    
    for (i=0;i<nbr_article;i++)
      os << nom_article[i]<< endl; 
      
}


