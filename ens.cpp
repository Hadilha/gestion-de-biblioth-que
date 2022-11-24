#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "personne.h"
#include "ens.h"
#include <cstring>
#include <string.h>

using namespace std;
//nb_heures,grade,departement,universite
//nom,prenom,cen,ville,rue,code_postale
   ens::ens(int nb_heures1,string grade1,string departement1,string universite1,string nom1 ,string prenom1,int cen1,string ville1,string rue1,string code_postale1 ):personne(nom1,prenom1,cen1,ville1,code_postale1)
{nb_heures=nb_heures1;
grade=grade1;
departement=departement1;
universite=universite1;

}
int  ens::getnb_heures()
{
    return nb_heures;
}
string  ens::getgrade()
{
      return  grade;
}
string  ens:: getdepartement()
{
       return  departement;
}
string  ens::getuniversite()
{
       return universite;
}


void ens::setnb_heures(int nb_heures1)
{
    nb_heures=nb_heures1;
}
    void ens::setgrade(string grade1)
    {
        grade=grade1;
    }
    void ens::setdepartement(string departement1)
    {
        departement=departement1;
    }
    void ens:: setuniversite(string universite1)
    {
      universite=universite1;
    }




void ens:: modifier_nb_heures( int n )
{
   nb_heures=n;
}
    void ens:: modifier_grade( string n)
    {
       grade=n;
    }
    void ens:: modifier_departement( string n)
    {
        departement=n;
    }

void ens::afficheens()
{personne::affichage();
cout<<"\t nombre d'heures: "<< nb_heures << "\n \t grade: " << grade <<"\n \tdepartement : "<< departement <<"\n \t universite  : "<<universite;
}
ens* ens:: cree_ens_sans_tab()
{
    ens *r;
   string n11 ,surname,vil,ruee,dep,gra,co,uni;
       int ciin,nb;


cout <<"taper le nom de l'enseignant  : "<< endl ;
    fflush(stdin);
    getline(cin,n11);
   r->setnomm(n11) ;

    cout <<"taper le prenom de l'enseignant  : "<< endl ;
    fflush(stdin);
    getline(cin,surname);
     r->setprenom(surname) ;

    cout <<"taper le cin de l'enseignant  : "<< endl ;
    fflush(stdin);
    std::cin >>ciin;
   r->setcen(ciin) ;

    cout <<"taper la ville de l'enseignant  : "<< endl ;
    fflush(stdin);
    getline(cin,vil);
   r->setville(vil) ;



    cout <<"taper le code postale de l'enseignant   : "<< endl ;
    fflush(stdin);
    getline(cin,co);
    r->setcode_postale(co) ;

    cout <<"taper le numero de le nembre d'heures  de l'enseignant : "<< endl ;
    fflush(stdin);
      std::cin >>nb;
   r->setnb_heures(nb) ;

    cout <<"taper le grades de l'enseignant  : "<< endl ;
    fflush(stdin);
     getline(cin,gra);
    r->setgrade(gra) ;



    cout <<"taper le departement  de l'enseignant   : "<< endl ;
    fflush(stdin);
    getline(cin,dep);
   r->setdepartement(dep) ;

    cout <<"taper l'université de l'enseignant  : "<< endl ;
    fflush(stdin);
    getline(cin,uni);
   r->setuniversite(uni) ;
   return r;
}

void ens:: aff_livre_emp_ens(ens e)
{int i;

      for( i=0;i<=ens::z;i++){
    cout<<"Titre du  Livre : "<<e.TlivreempE[i].gettitre()<<"\t|| Auteur : " <<e.TlivreempE[i].getauteur() <<"\t|| date de release : "<< e.TlivreempE[i].getannee()  <<"\t|| code du livre  : "<<e.TlivreempE[i].getcode()<<"\n" ;
      }

  }





