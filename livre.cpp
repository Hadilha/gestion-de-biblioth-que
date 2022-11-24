#include<iostream>
#include <stdio.h>
#include "livre.h"
#include <string.h>

using namespace std;



livre :: livre(int code , int annee ,string titre ,string auteur )
{
this->code=code ;
this->titre=titre ;
this->annee=annee;
this->auteur=auteur;

}
int livre::getcode()

{
    return code;
}
int livre::getannee()
{
    return annee;
}
string livre::gettitre()
{
    return titre;

}
string livre::getauteur()
{
    return auteur;

}

void livre::setcode(int code1)
{
    code=code1;
}
void livre::setannee(int annee1)
{
     annee=annee1;
}
void livre::settitre(string titre1)
{
    titre=titre1;
}
void livre::setauteur(string auteur1)
{
    auteur=auteur1;
}

void livre::modifier_titre( string tit )
{
    titre=tit;
}
void livre::modifier_annee(int ann )
{
    annee=ann;
}

void livre::affichelivre()
{
cout<<"\t Titre du  Livre : "<< titre << "\n \t Auteur : " << auteur <<"\n \t date de release : "<< annee <<"\n \t code du livre  : "<<code;
}
livre* livre:: cree_livre_sans_tab()
{livre *e;
    string tit,aut;
       int ann,co;


    cout <<"taper le nom du livre : "<< endl ;
    fflush(stdin);
    getline(cin,tit);
    e->settitre(tit) ;

    cout <<"taper l'auteur du livre : "<< endl ;
    fflush(stdin);
    getline(cin,aut);
    e->setauteur(aut) ;

    cout <<"taper l'annee du livre : "<< endl ;
    fflush(stdin);
    cin>>ann;
    e->setannee(ann);

    cout <<"taper le code du livre : "<< endl ;
    fflush(stdin);
    cin >>co;
   e->setcode(co);
   return e;


}


