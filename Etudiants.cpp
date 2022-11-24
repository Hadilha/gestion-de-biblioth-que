#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "personne.h"
#include "Etudiants.h"
#include <cstring>
#include <string.h>



//carte_etud,meilleur_note,nb_abscence,calsse,universiteta
using namespace std;



Etudiants ::  Etudiants  (string nom ,string prenom ,int cen ,string ville,string code_postale,string classe1
                       ,int carte_etud1,int meilleur_note1 ,int nb_abscence1
                       ):personne(nom ,prenom ,cen ,ville,code_postale )
{

classe=classe1;
carte_etud=carte_etud1;
meilleur_note=meilleur_note1;
nb_abscence=nb_abscence1;

}
int  Etudiants:: getcarte_etud()
{
    return carte_etud;
}
int  Etudiants:: getmeilleur_note()
{
    return meilleur_note;
}
int  Etudiants:: getnb_abscence()
{
    return nb_abscence;
}
string  Etudiants:: getcalsse()
{
    return classe;
}

/*---------------------------*/
void Etudiants::setcarte_etud(int carte_etud1)
{
    carte_etud=carte_etud1;
}
void Etudiants::setmeilleur_note(int meilleur_note1)
{
    meilleur_note=meilleur_note1;
}
void Etudiants::setnb_abscence(int nb_abscence1)
{
    nb_abscence=nb_abscence1;
}
void Etudiants::setcalsse(string classe1)
{

 classe=classe1;

}




void Etudiants:: modifier_carte_etud( int n1 )
{
    carte_etud=n1;
}
void Etudiants::  modifier_meilleur_note( int n1 )
{
    meilleur_note=n1;
}
void Etudiants:: modifier_nb_abscence( int n1)
{
   nb_abscence=n1;
}
void  Etudiants:: modifier_calsse( string n1)
{
    classe=n1;
}



void Etudiants:: afficheEtudiant()
{
    personne::affichage();

cout<<"\t classe : "<<  classe << " \n \t carte_etud : " << carte_etud << " \n \t  meilleur_note : " <<  meilleur_note << " \n \t nb_abscence : " << nb_abscence ;
}

Etudiants* Etudiants:: cree_etud_sans_tab()
{
    Etudiants *r;
   string n11 ,surname,vil,ruee,co,cla,uni;
       int ciin,cartee,nootee,abss;


cout <<"taper le nom de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,n11);
   r->setnomm(n11) ;

    cout <<"taper le prenom de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,surname);
     r->setprenom(surname) ;

    cout <<"taper le cin de l'etudiant  : "<< endl ;
    fflush(stdin);
    std::cin >>ciin;
   r->setcen(ciin) ;

    cout <<"taper la ville de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,vil);
   r->setville(vil) ;



    cout <<"taper le code postale de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,co);
    r->setcode_postale(co) ;

    cout <<"taper le numero de la carte d'etudiant  : "<< endl ;
    fflush(stdin);
    std::cin >>cartee;
   r->setcarte_etud(cartee) ;

    cout <<"taper la meilleur note de l'etudiant  : "<< endl ;
    fflush(stdin);
    std::cin >>nootee;
    r->setmeilleur_note(nootee) ;

    cout <<"taper le nombre d'absence de l'etudiant  : "<< endl ;
    fflush(stdin);
    std::cin >>abss;
    r->setnb_abscence(abss) ;

    cout <<"taper la classe  de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,cla);
   r->setcalsse(cla) ;

   return r;
}


void Etudiants:: aff_livre_emp_etudiants(Etudiants e)
{int i;

      for( i=0;i<=Etudiants::x;i++){
    cout<<"Titre du  Livre : "<<e.Tlivreemp[i].gettitre()<<"\t|| Auteur : " <<e.Tlivreemp[i].getauteur() <<"\t|| date de release : "<< e.Tlivreemp[i].getannee()  <<"\t|| code du livre  : "<<e.Tlivreemp[i].getcode()<<"\n" ;
      }

  }
