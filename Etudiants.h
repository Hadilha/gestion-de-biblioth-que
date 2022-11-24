#ifndef ETUDIANTS_H_INCLUDED
#define ETUDIANTS_H_INCLUDED

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "personne.h"
#include "livre.h"
#include <string.h>

/*bibliotheque :carte_etud,meilleur_note,nb_abscence, classe

les methodes:

modifier meilleur_note
 modifier nb_abscence
 modifier calsse
 modifier universite
 modifier etat
-affiche Etudiant
*/




using namespace std ;



class Etudiants: public personne
{
public:
int carte_etud;
int meilleur_note;
int nb_abscence;
string classe;
livre Tlivreemp[10];
int static x;//compteur pour les livres emprunter

public :
Etudiants (){};
Etudiants (string,string,int,string,string ,string ,int ,int  ,int );

int getcarte_etud();
int getmeilleur_note();
int getnb_abscence();
string getcalsse();



void setcarte_etud(int);
void setmeilleur_note(int);
void setnb_abscence(int);
void setcalsse( string );
void setlivreempetud(livre);


 void modifier_carte_etud( int );
void modifier_meilleur_note( int );
 void modifier_nb_abscence( int );
 void modifier_calsse( string );
 Etudiants* cree_etud_sans_tab();


 void afficheEtudiant();

 static void aff_livre_emp_etudiants( Etudiants);



};

#endif // ETUDIANTS_H_INCLUDED
