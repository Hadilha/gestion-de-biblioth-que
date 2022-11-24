#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "personne.h"
#include <string.h>
#include <cstring>
using namespace std;




personne :: personne (string nom1 ,string prenom1 ,int cen1 ,string ville1,string code_postale1 )
{
nomm=nom1 ;
prenom=prenom1;
cen=cen1;
ville=ville1;
code_postale=code_postale1;



}


string  personne:: getnom()
{
    return nomm;
}
string  personne:: getprenom()
{
    return prenom;
}
int   personne:: getcen()
{
    return cen;
}
string   personne:: getville()
{
    return ville;
}

string  personne:: getcode_postale()
{
    return code_postale;
}
/*-------------------------------------------*/
//nom,prenom,cen,ville,rue,code_postale
void personne::setnomm(string nomm1)
{
    nomm=nomm1;

}




void personne::setprenom(string prenom1)
{
   prenom=prenom1;
}
void personne::setcen(int cen1)
{
     cen=cen1;
}
void personne::setville(string ville1)
{
     ville=ville1;
}

void personne::setcode_postale(string code_postale1)
{
   code_postale=code_postale1;
}





void personne::affichage()
{cout<<getnom();
cout<<" \t nom: "<< nomm << "\n \t prenom : " << prenom <<"\n \t cen: "<< cen<<"\n \t Ville: "<< ville<<"\n \t Code postale: "<< code_postale ;
cout<<"\n";
}

void personne:: modifier_nom( string nom1)
{
    nomm=nom1;
}
void personne:: modifier_cen( int cen1)
{
    cen=cen1;
}
void personne:: modifier_ville( string ville1 )
{
    ville=ville1;
}

void personne:: modifier_code_postale( string c)
{
    code_postale=c;
}


