#ifndef LIVRE_H_INCLUDED
#define LIVRE_H_INCLUDED

#include <string.h>
#include <iostream>

/*livre :code,annee,titre,auteur
les methodes:
-modification de titre
-modification d'annee
-getteurs et setteurs
-affichage*/


using namespace std;



class livre
{
public :
int code ;
int annee ;
string titre;
string auteur;

public :
livre(int ,int , string , string);
livre(){};

int getcode();
int getannee();
string gettitre();
string getauteur();

void setcode(int);
void setannee(int);
void settitre(string);
void setauteur(string);

void affichelivre();

void modifier_titre( string );
void modifier_annee(int);
livre*  cree_livre_sans_tab();


} ;

#endif // LIVRE_H_INCLUDED
