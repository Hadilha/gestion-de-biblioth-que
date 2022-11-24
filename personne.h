#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>


/*personne :nom,prenom, S cen,ville,rue,code_postale
les methodes:
-modification de nom
-modification cen
-modification ville
-modification rue
-modification code_postale
-getteurs et setteurs
-affichage*/

using namespace std;
class personne
{
public :
 string nomm;
string prenom;
int cen;
string ville;

string code_postale;

public :
personne (string ,string ,int,string,string );
personne (){};

string getnom();
string getprenom();
int getcen();
string getville();
string getcode_postale();

void setnomm(string );
void setprenom(string);
void setcen(int);
void setville(string);
void setcode_postale(string);

void affichage();

void modifier_nom( string );
void modifier_cen( int );
void modifier_ville( string );
void modifier_rue( string );
void modifier_code_postale( string );



};

#endif // PERSONNE_H_INCLUDED
