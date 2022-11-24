#ifndef ENS_H_INCLUDED
#define ENS_H_INCLUDED
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "personne.h"
#include "livre.h"
#include <string.h>

using namespace std;
//nb_heures,grade,departement,universite


class ens : public  personne
{
    public:

    int nb_heures;
    string grade;
    string departement;
    string universite;
    livre TlivreempE[10];
int static z;//compteur pour les livres emprunter

public :
    ens(int,string,string ,string ,string ,string,int ,string ,string ,string  );
ens(){};
    int getnb_heures();
    string getgrade();
    string getdepartement();
    string getuniversite();

    void setnb_heures(int);
    void setgrade(string);
    void setdepartement(string);
    void setuniversite(string);

    void modifier_nb_heures( int );
    void modifier_grade( string );
    void modifier_departement( string );

     ens* cree_ens_sans_tab();

static  void aff_livre_emp_ens(ens);

void afficheens();

};


#endif // ENS_H_INCLUDED
