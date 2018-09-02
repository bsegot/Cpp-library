#include <vector>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iostream>
#include <iterator>

#include "mediatheque.h"

using namespace std;

int log(void)
{
  int login=0;
  unsigned int i;
  string command;
  for(i=1;i<=3;i++) // On demande le mot de passe trois fois seulement
    {
          cout << "Login :"<< endl;
          getline(cin,command);
          if (!command.compare("admin"))
        {
            cout << "Mot de passe :"<< endl;
            getline(cin,command);
              if (!command.compare("admin"))
            {
                  cout << "\nBonjour admin, pour voir la liste des commandes, veuillez tapez -help- " << endl;
              login =1;
              break;
            }
              else
            {
              cout << "Password incorrecte" << endl;
              login = 0;
            }
        }
          else if(!command.compare("user"))
        {

            cout << "Mot de passe :"<< endl;
            getline(cin,command);
              if (!command.compare("user"))
            {
              cout << "\nBonjour user, pour voir la liste des commandes, veuillez tapez -help-" << endl;
              login =2;
              break;
            }
              else
            {
              cout << "Password incorrecte" << endl;
              login = 0;
            }
        }

          else
        {
          cout << "Login errone" << endl;
          login = 0;
        }
    }
  return login;
}

int main(void)
{
  unsigned int i;
  string command;
  unsigned int resultat=0;
  int login=0;

  Bibliotheque *ma_bibliotheque = new Bibliotheque();

  cout << "M'HAMDI ALAOUI Anas - SEGOT Bastien\n" <<endl;
  cout << "*******************************" <<endl;
  cout << "                                          " <<endl;
  cout << " -_-_-_    Bienvenue dans votre médiathèque  -_-_-_- " <<endl;
  cout << "                                          " <<endl;
  cout << "*******************************" <<endl;
  cout << "  ------------------------------" <<endl;
  cout << " ||             |              ||" <<endl;
  cout << " ||             |              ||" <<endl;
  cout << " ||             |              ||" <<endl;
  cout << " ||             |              ||" <<endl;
  cout << " ||             |              ||" <<endl;
  cout << " -------------------------------" <<endl;
  cout << "----------------------------------" <<endl;
  cout << "\nPour vous connecter en tant qu admin entrez :\"admin\" et le mot de passe \"admin\"" <<endl;
  cout << " Pour vous connecter en tant qu user entrez : \"user\" et le mot de passe  \"user\"\n" <<endl;
  login=log();
  cout << endl;
  while(1)
    {

      while(login==1) // Boucle infinie
        {
          cout << "Commande de l'admin : ";
          getline(cin,command);	// On recupere la commande saisie
          if (command.size() != 0)
            {
              istringstream iss(command); // On met dans un flux
              vector<string> command_function;
              copy(istream_iterator<string>( iss ),istream_iterator<string>(),back_inserter( command_function ) ); // On remplie mot par mot le vecteur "command_fuction

              if (!command_function[0].compare("list") == false)
            {
              if (command_function.size() == 1)
                ma_bibliotheque->list();
              else
                cout << "Argument incorrect"<< endl;
            }

              else if (!command_function[0].compare("show") == false)
            {
              if (command_function.size() >= 2)
                for(i=1;i<command_function.size();i++)
                  ma_bibliotheque->show(atoi(command_function[i].c_str()));
              else
                cout << "un argument est manquant" << endl;
            }

              else if (command_function[0].compare("search") == false)
            {
              if (command_function.size() >= 2)
                {
                  for(i=1;i<command_function.size();i++)
                {
                  resultat = ma_bibliotheque->search(command_function[i]);
                  cout << "Il existe " << resultat << " autant de media correspondant a la recherche." << endl;
                }
                  cout << "Il existe " << resultat << " autant de media correspondant a la recherche." << endl;
                  ma_bibliotheque->list();
                }
              else
                cout << "Argument Manquant";
            }
              else if (command_function[0].compare("save") == false)
            {
              if (command_function.size() == 2)
                ma_bibliotheque->save(command_function[1]);
              else if (command_function.size() > 2)
                cout << "l'argument est incorrect"<< endl;
              else
                cout << "un argument est Manquant"<< endl;
            }

              else if (command_function[0].compare("clear") == false)
            {
              if (command_function.size() == 1)
                ma_bibliotheque->rebuild();
              else
                cout << "Argument incorrect"<< endl;
            }
              else if (command_function[0].compare("add") == false)
            {
              if (command_function.size() == 2)
                ma_bibliotheque->add(command_function[1]);
              else if (command_function.size() > 2)
                cout << "l'argument est incorrect"<< endl;
              else
                cout << "un Argument est manquant"<< endl;
            }


              else if (command_function[0].compare("load") == false)
            {
              if (command_function.size() == 2)
                ma_bibliotheque->load(command_function[1]);
              else if (command_function.size() > 2)
                cout << "l'argument est incorrect"<< endl;
              else
                cout << "un argument est manquant"<< endl;
            }

              else if (command_function[0].compare("reset") == false)
            {
              if (command_function.size() == 1)
                ma_bibliotheque->reset();
              else
                cout << "l'argument est impossible"<< endl;
            }


              else if (command_function[0].compare("delete") == false)
            {
              if (command_function.size() >= 2)
                for(i=1;i<command_function.size();i++)
                  ma_bibliotheque->supress(atoi(command_function[i].c_str()));
              else
                cout << "un argument est manquant"<< endl;
            }





              else if (command_function[0].compare("louer") == false)
            {
              if (command_function.size() >= 2)
                for(i=1;i<command_function.size();i++)
                  ma_bibliotheque->louer(atoi(command_function[i].c_str()));
              else
                cout << "Un argument est manquant"<< endl;
            }

              else if (command_function[0].compare("help") == false)
            {
              if (command_function.size() == 1)
                ma_bibliotheque->help();
              else
                cout << "L'argument est impossible"<< endl;
            }

               else if (command_function[0].compare("retour") == false)
            {
              if (command_function.size() >= 2)
                for(i=1;i<command_function.size();i++)
                  ma_bibliotheque->retour(atoi(command_function[i].c_str()));
              else
                cout << "Un argument est manquant"<< endl;
            }



              else if (command_function[0].compare("bye") == false)
            {
              if (command_function.size() == 1)
                {
                  delete ma_bibliotheque;
                  break;
                }

              else if (command_function[0].compare("change") == false)
            {
              if (command_function.size() == 1)
                login=log();
              else
                cout << "L'argument est impossible"<< endl;
            }

              else
                cout << "L'Argument est impossible"<< endl;
            }
              else
            cout << "La commande est inconnue";
            cout << endl;
            }
          else
            cout << "La commande est inconnue";
        cout << endl;
        }
      while(login==2) // Boucle pour l'user
        {
          cout << "Commande de l'user  ";
          getline(cin,command);	// on recupere la commande saisie
          if (command.size() != 0)
            {
              istringstream iss(command);
              vector<string> command_function;
              copy(istream_iterator<string>( iss ),istream_iterator<string>(),back_inserter( command_function ) ); // remplissage du tableau


              if (command_function[0].compare("list") == false)
            {
              if (command_function.size() == 1)
                ma_bibliotheque->list();
              else
                cout << "L'argument est impossible"<< endl;
            }



              else if (command_function[0].compare("search") == false)
            {
              if (command_function.size() >= 2)
                {
                  for(i=1;i<command_function.size();i++)
                {
                  resultat = ma_bibliotheque->search(command_function[i]);
                  cout << "nous avons" << resultat << " qui  correspondent a votre recherche " << endl;
                }
                  cout << "nous avons" << resultat << "qui correspondent a votre recherche " << endl;
                  ma_bibliotheque->list();
                }
              else
                cout << "un argument est manquant";
            }

              else if (command_function[0].compare("show") == false)
            {
              if (command_function.size() >= 2)
                for(i=1;i<command_function.size();i++)
                  ma_bibliotheque->show(atoi(command_function[i].c_str()));
              else
                cout << "Un argument est manquant" << endl;
            }

              else if (command_function[0].compare("help") == false)
            {
              if (command_function.size() == 1)
                ma_bibliotheque->help2();
              else
                cout << "L'Argument est  Impossible"<< endl;
            }
              else if (command_function[0].compare("clear") == false)
            {
              if (command_function.size() == 1)
                ma_bibliotheque->rebuild();
              else
                cout << "L'Argument est Impossible"<< endl;
            }


              else if (command_function[0].compare("change") == false)
            {
              if (command_function.size() == 1)
                login=log();
              else
                cout << "L'Argument est Impossible"<< endl;
            }

               else if (command_function[0].compare("louer") == false)
            {
              if (command_function.size() >= 2)
                for(i=1;i<command_function.size();i++)
                  ma_bibliotheque->louer(atoi(command_function[i].c_str()));
              else
                cout << "Un Argument est Manquant"<< endl;
            }

              else if (command_function[0].compare("bye") == false)
            {
              if (command_function.size() == 1)
                {
                  delete ma_bibliotheque;
                  break;
                }
              else
                cout << "L'Argument est Impossible"<< endl;
            }
              else
            cout << "La Commande est Inconnue";
            cout << endl;
            }
          else
            cout << "la Commande est  Inconnue";
        cout << endl; //
        }
          if (command.size() != 0)
        {
          istringstream iss(command);
          vector<string> command_function;
          copy(istream_iterator<string>( iss ),istream_iterator<string>(),back_inserter( command_function ) );
          if (command_function[0].compare("bye") == false)
            break;
        }
    }
}
