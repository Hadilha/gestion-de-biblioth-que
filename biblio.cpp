/*fichier dinstalation .xe*/


#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
//#include "personne.h"
//#include "Etudiants.h"
//#include "livre.h"
#include "biblio.h"
#include <string.h>
#include "ens.h"
#include<fstream>
#include<cstdlib>


#include <fstream>

using namespace std;
ofstream My_file;;
ifstream Ma_fichier;


int Etudiants::x=-1;
int ens::z=-1;
int biblio::n1=-1;
int biblio::n2=-1;
int biblio::n3=-1;
biblio::biblio()
{

}
bool biblio:: checkEmptyString(const char *s)
{
    return strlen(s) == 0;
}



 void biblio::cree_biblio_livre(biblio *e)
 {

    int res;

     int ch;

      printf("\n                            * BIENVENUE A NOTRE BIBILOTHEQUE ***\n ");


    printf("\n                  * NOUS ESPERONS QUE VOUS SEREZ SATISFAIT DE NOTRE PLATFORME  * \n");

	do{cout<<"\nVoulez vous ajouter un livre a notre platforme  ? \nTAPER 1 POUR EFFECTUER L'AJOUT ! \nTAPER 0 POUR QUITTER !   \nVOTRE CHOIX  : ";
   cin>>ch;}while(!((ch==1)||(ch==0)));
	if(ch)
	{
	   string tit,aut;
       int ann,co;

/************************************************/
    do{biblio::n2++;
             do{try{cout <<"taper le nom du livre : "<< endl ;
    fflush(stdin);
    getline(cin,tit);
    if(checkEmptyString(tit.data())==true )
     throw string("ce titre n'est pas de type string !");
     else
    e->T2[biblio::n2].settitre(tit);
    }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(tit.data()) );

/************************************************/
  do{try{
    cout <<"taper l'auteur du livre : "<< endl ;
    fflush(stdin);
    getline(cin,aut);
     if(checkEmptyString(tit.data())==true )
     throw string("cette auteur n'est pas de type string !");
    e->T2[biblio::n2].setauteur(aut) ;
 }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(tit.data()) );
/************************************************/
   do{try{ cout <<"taper l'annee du livre : "<< endl ;
    fflush(stdin);
    cin>>ann;
    if(((ann<=1000)||(ann>2020)))
    throw string("annee invalide !");
    else
    e->T2[biblio::n2].setannee(ann);

    }catch(string const& chaine)
      {

       cerr << chaine << endl;}
   }while((ann<=1000)||(ann>2020));

/************************************************/
     do{try{cout <<"taper le code du livre (4 chiffres): \n"<< endl ;
    fflush(stdin);
    cin >>co;
   if(((co<=1000)||(co>9999)))
         throw string("code invalide !");
    e->T2[biblio::n2].setcode(co);
     }catch(string const& chaine)
      {

       cerr << chaine << endl;}
   }while(((co<=1000)||(co>9999)));
/************************************************/

   cout<<"voulez vous ajouter un autre livre \n si oui tapez 1 \n si non taper 0";
    cin>>res;
     cout<<"\n";
  }while((biblio::n2<100)&&(res==1));

	}
 }

 void biblio:: ajouter_un_livre(biblio *e )
 {biblio::n2++;
 string tit,aut;
       int ann,co;

    biblio::n2++;
             do{try{cout <<"taper le nom du livre : "<< endl ;
    fflush(stdin);
    getline(cin,tit);
    if(checkEmptyString(tit.data())==true )
     throw string("ce titre est vide!");
     else
    e->T2[biblio::n2].settitre(tit);
    }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(tit.data()) );

/************************************************/
  do{try{
    cout <<"taper l'auteur du livre : "<< endl ;
    fflush(stdin);
    getline(cin,aut);
     if(checkEmptyString(tit.data())==true )
     throw string("cette auteur est vide!");
    e->T2[biblio::n2].setauteur(aut) ;
 }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(tit.data()) );
/************************************************/
   do{try{ cout <<"taper l'annee du livre : "<< endl ;
    fflush(stdin);
    cin>>ann;
    if(((ann<=1000)||(ann>2020)))
    throw string("annee invalide !");
    else
    e->T2[biblio::n2].setannee(ann);

    }catch(string const& chaine)
      {

       cerr << chaine << endl;}
   }while((ann<=1000)||(ann>2020));

/************************************************/
     cout <<"taper le code du livre (4 chiffres): \n"<< endl ;
    fflush(stdin);
    cin >>co;

    e->T2[biblio::n2].setcode(co);
 }
 void biblio:: affichertlivre(biblio *e)
  {int i;

      for( i=0;i<=biblio::n2;i++){
    cout<<"Titre du  Livre : "<<e->T2[i].gettitre()<<"\n Auteur : " <<e->T2[i].getauteur() <<"\n date de release : "<< e->T2[i].getannee()  <<"\n code du livre  : "<<e->T2[i].getcode()<<"\n\n" ;
     }

  }
   void biblio:: affichertetudiant(biblio *e)
  {int i;

      {for( i=0;i<biblio::n1;i++)
      cout<<"le nom de l'etudiant :"<<e->T1[i].getnom()<<"\n le cin de l'etudiant:"<<e->T1[i].getcen()<<"\n la ville de l'etudiant:"
      <<e->T1[i].getville()<<"\nle code postale de l'etudiant:"<<e->T1[i].getcode_postale()<< "\n la meilleur  de l'etudiant:"
      <<e->T1[i].getmeilleur_note()<<"\n le nombre d'absence de l'etudiant:"<<e->T1[i].getnb_abscence()<<"\n la classe  de l'etudiant :"<<e->T1[i].getcalsse()
      ;
      cout<<"\n\n";

      }
  }


  void biblio:: affichertenseignant(biblio *e)
  {int i;

      {for( i=0;i<biblio::n3;i++)
      cout<<"le nom de l'enseignant :"<<e->T3[i].getnom()<<"\n le cin de l'enseignant:"<<e->T3[i].getcen()<<"\n la ville de l'enseignant:"
      <<e->T3[i].getville()<<"\nle code postale de l'enseignant:"<<e->T3[i].getcode_postale()<< "\n le nombre d'heures de l'enseignant:"
      <<e->T3[i].getnb_heures()<<"\n le grade de l'enseignant:"<<e->T3[i].getgrade()<<"\n le departement de l'enseignant :"<<e->T3[i].getdepartement()
      ;

      }
  }

 void  biblio:: cree_biblio_etudiant(biblio *e)
 {

   int res;

     int ch;
     n1++;
      printf("\n                            * BIENVENUE A NOTRE BIBILOTHEQUE ***\n ");


    printf("\n                  * NOUS ESPERONS QUE VOUS SEREZ SATISFAIT DE NOTRE PLATFORME  * \n");

	do{cout<<"\nVoulez vous ajouter un etudiant a notre platforme  ? \nTAPER 1 POUR EFFECTUER L'AJOUT ! \nTAPER 0 POUR QUITTER !   \nVOTRE CHOIX  : ";
   cin>>ch;
   }while(!((ch==1)||(ch==0)));

	if(ch==1)
	{
	   string n11 ,surname,vil,ruee,co,cla,uni;
       int ciin,cartee,nootee,abss;

       /*************************************************/
do{  do{try{cout <<"taper le nom de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,n11);
    if(checkEmptyString(n11.data())==true )
     throw string("cette nom est vide !");
    e->T1[biblio::n1].setnomm(n11); }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(n11.data()) );
   /*************************************************/

    do{try{ cout <<"taper le prenom de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,surname);
    if(checkEmptyString(surname.data())==true )
     throw string("cette prenom est vide !");
     e->T1[biblio::n1].setprenom(surname) ; }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(surname.data()) );

   /*************************************************/
   int ciin;

    cout <<"taper le cin de l'etudiant (4 chiffres) : "<< endl ;
    fflush(stdin);
    std::cin >>ciin;


    e->T1[biblio::n1].setcen(ciin) ;


   /*************************************************/
     do{try{cout <<"taper la ville de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,vil);
    if(checkEmptyString(vil.data())==true )
     throw string("cette ville est vide  !");
    e->T1[biblio::n1].setville(vil) ;
     }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(vil.data()) );
/*************************************************/

    do{try{ cout <<"taper le code postale de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,co);
     if(checkEmptyString(co.data())==true )
    throw string("cette code postale est vide  !");

    e->T1[biblio::n1].setcode_postale(co) ; }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(co.data()) );

   /*************************************************/


    cout <<"taper le numero de la carte d'etudiant (4 chiffres) : "<< endl ;
    fflush(stdin);
    std::cin >>cartee;


    e->T1[biblio::n1].setcarte_etud(cartee) ;


/*************************************************/
do{try{
    cout <<"tapez la meilleur note de l'etudiant  : "<< endl ;
    fflush(stdin);
    std::cin >>nootee;
     if((nootee<0)||(nootee>20))
    e->T1[biblio::n1].setmeilleur_note(nootee) ;
    }catch(string const& chaine)
      {

       cerr << chaine << endl;}
   }while((nootee<0)||(nootee>20));
/*************************************************/
do{try{
    cout <<"taper le nombre d'absence de l'etudiant  : "<< endl ;
    fflush(stdin);
    std::cin >>abss;
    if((abss<0)||(abss>20))
    throw string("le nombre d'absence est inavlide   !");

    e->T1[biblio::n1].setnb_abscence(abss) ;
    }catch(string const& chaine)
      {

       cerr << chaine << endl;}
   }while((abss<0)||(abss>20));
/*************************************************/

    do{try{ cout <<"taper la classe  de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,cla);
         if(checkEmptyString(cla.data())==true )

        throw string("cette classe est vide  !");

    e->T1[biblio::n1].setcalsse(cla) ; }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(cla.data()) );
   /*************************************************/




   biblio::n1++;
    cout<<"voulez vous ajouter un autre etudiant ? \nTAPER 1 POUR EFFECTUER L'AJOUT ! \nTAPER 0 POUR QUITTER !   \nVOTRE CHOIX  : ";
    cin>>res;
    cout<<"\n";

  }while((biblio::n1<100)&&(res==1));

	}
	}

void biblio:: ajouter_biblio_etudiant(biblio *e )
 {biblio::n1++;

string n11 ,surname,vil,ruee,co,cla,uni;
       int ciin,cartee,nootee,abss;


 do{try{cout <<"taper le nom de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,n11);
    if(checkEmptyString(n11.data())==true )
     throw string("cette nom est vide !");
    e->T1[biblio::n1].setnomm(n11); }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(n11.data()) );
   /*************************************************/

    do{try{ cout <<"taper le prenom de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,surname);
    if(checkEmptyString(surname.data())==true )
     throw string("cette prenom est vide !");
     e->T1[biblio::n1].setprenom(surname) ; }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(surname.data()) );

   /*************************************************/
//   int ciin;

    cout <<"taper le cin de l'etudiant (4 chiffres) : "<< endl ;
    fflush(stdin);
    std::cin >>ciin;


    e->T1[biblio::n1].setcen(ciin) ;

   /*************************************************/
     do{try{cout <<"taper la ville de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,vil);
    if(checkEmptyString(vil.data())==true )
     throw string("cette ville est vide  !");
    e->T1[biblio::n1].setville(vil) ;
     }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(vil.data()) );
/*************************************************/

    do{try{ cout <<"taper le code postale de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,co);
     if(checkEmptyString(co.data())==true )
    throw string("cette code postale est vide  !");

    e->T1[biblio::n1].setcode_postale(co) ; }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(co.data()) );

   /*************************************************/

   unsigned long int c;

    cout <<"taper le numero de la carte d'etudiant (4 chiffres) : "<< endl ;
    fflush(stdin);
    std::cin >>cartee;


    e->T1[biblio::n1].setcarte_etud(cartee) ;


/*************************************************/
do{try{
    cout <<"tapez la meilleur note de l'etudiant  : "<< endl ;
    fflush(stdin);
    std::cin >>nootee;
     if((nootee<0)||(nootee>20))
    e->T1[biblio::n1].setmeilleur_note(nootee) ;
    }catch(string const& chaine)
      {

       cerr << chaine << endl;}
   }while((nootee<0)||(nootee>20));
/*************************************************/
do{try{
    cout <<"taper le nombre d'absence de l'etudiant  : "<< endl ;
    fflush(stdin);
    std::cin >>abss;
    if((abss<0)||(abss>20))
    throw string("le nombre d'absence est inavlide   !");

    e->T1[biblio::n1].setnb_abscence(abss) ;
    }catch(string const& chaine)
      {

       cerr << chaine << endl;}
   }while((abss<0)||(abss>20));
/*************************************************/

    do{try{ cout <<"taper la classe  de l'etudiant   : "<< endl ;
    fflush(stdin);
    getline(cin,cla);
         if(checkEmptyString(cla.data())==true )

        throw string("cette classe est vide  !");

    e->T1[biblio::n1].setcalsse(cla) ; }catch(string const& chaine )
      {

       cerr << chaine << endl;}
   }while(checkEmptyString(cla.data()) );
   /*************************************************/

}


 void biblio:: supprimer_livre_par_code(int code,biblio *e  )
 {int x=0,i;
     while (x<biblio::n2){

    if(!(code==(e->T2[x].getcode())))
     {
         x++;
     }
     for (i=x;i<(biblio::n2)-1;i++)
         e->T2[i]=e->T2[i+1];
         biblio::n2--;
     }
     }


 void biblio:: supprimer_livre_par_titre(string tit,biblio * e)
 {int x=0,i;
 string ch;
     while (x<biblio::n2){

    if(!(strcmp(tit.c_str(), e->T2[x].gettitre().c_str())))
     {
         x++;
     }

     for (i=x;i<(biblio::n2)-1;i++)

         e->T2[i]=e->T2[i+1];

 biblio::n2--;

     }
     biblio::affichertlivre(e);


   }
void biblio:: supprimer_etudiant_par_nom_et_prenom(string n,string p,biblio * e)
 {int x=0,i;

     while (x<biblio::n1){

    if(!(strcasecmp(n.c_str(), e->T1[x].getnom().c_str()))&&(strcasecmp(p.c_str(), e->T1[x].getprenom().c_str())))
     {
         x++;
     }

     for (i=x;i<(biblio::n1)-1;i++)

         e->T1[i]=e->T1[i+1];

 biblio::n1--;

     }


   }
   void biblio:: supprimer_enseignant_par_nom_et_prenom(string n,string p,biblio * e)
 {int x=0,i;

     while (x<biblio::n3){

    if(!(strcasecmp(n.c_str(), e->T3[x].getnom().c_str()))&&(strcasecmp(p.c_str(), e->T3[x].getprenom().c_str())))
     {
         x++;
     }

     for (i=x;i<(biblio::n3)-1;i++)

         e->T3[i]=e->T3[i+1];

 biblio::n3--;

     }


   }


void biblio:: supprimer_etudiant_par_cin_et_cen(int n,int p,biblio * e)
 {int x=0,i;

     while (x<biblio::n1){

    if(!(n==e->T1[x].getcen())&&(p, e->T1[x].getcarte_etud()))
     {
         x++;
     }

     for (i=x;i<(biblio::n1)-1;i++)

         e->T1[i]=e->T1[i+1];

 biblio::n1--;

     }


   }

   void biblio:: supprimer_enseignant_par_cin(int n,biblio * e)
 {int x=0,i;

     while (x<biblio::n3){

    if(!(n==e->T3[x].getcen()))
     {
         x++;
     }

     for (i=x;i<(biblio::n3)-1;i++)

         e->T3[i]=e->T3[i+1];

 biblio::n3--;

     }


   }

 void  biblio:: cree_biblio_enseignant(biblio *e)
 {

   int res;

     int ch;
     n3++;
      printf("\n                            * BIENVENUE A NOTRE BIBILOTHEQUE ***\n ");


    printf("\n                  * NOUS ESPERONS QUE VOUS SEREZ SATISFAIT DE NOTRE PLATFORME  * \n");

	do{cout<<"\nVoulez vous ajouter un enseignant a notre platforme  ? \nTAPER 1 POUR EFFECTUER L'AJOUT ! \nTAPER 0 POUR QUITTER !   \nVOTRE CHOIX  : ";
   cin>>ch;
   }while(!((ch==1)||(ch==0)));

	if(ch==1)
	{
	   string n11 ,surname,vil,ruee,co,cla,uni,dep,gra;
       int ciin,cartee,nootee,nb;
do{ /****************************************************/
 do{try{cout <<"taper le nom de l'enseignant  : "<< endl ;
    fflush(stdin);
    getline(cin,n11);
     if(checkEmptyString(n11.data())==true )
     throw string("cette nom est vide !");
    e->T3[biblio::n3].setnomm(n11) ;
     }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(n11.data()) );
/****************************************************/
     do{try{cout <<"taper le prenom de l'enseignant   : "<< endl ;
    fflush(stdin);
    getline(cin,surname);
     if(checkEmptyString(surname.data())==true )
     throw string("cette prenom est vide !");
     e->T3[biblio::n3].setprenom(surname) ;
     }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(surname.data()) );

/****************************************************/
 cout <<"taper le cin de l'enseignant (4 chiffres) : "<< endl ;
    fflush(stdin);
    std::cin >>ciin;


    e->T3[biblio::n3].setcen(ciin) ;

/****************************************************/
    do{try{ cout <<"taper la ville de l'enseignant   : "<< endl ;
    fflush(stdin);
    getline(cin,vil);
    if(checkEmptyString(vil.data())==true )
     throw string("cette ville est vide !");
    e->T3[biblio::n3].setville(vil) ;
    }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(vil.data()) );

/****************************************************/
     do{try{cout <<"taper le code postale de l'enseignant   : "<< endl ;
    fflush(stdin);
    getline(cin,co);
    if(checkEmptyString(co.data())==true )
     throw string("cette code postale est vide !");
    e->T3[biblio::n3].setcode_postale(co) ;
    }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(co.data()) );
/****************************************************/
    do{try{ cout <<"taper le nombre d'heure de l'enseignant (entre 0 et 20) : "<< endl ;
    fflush(stdin);
    std::cin >>nb;
     if((nb<0)||(nb>20))
     throw string("ce nombre d'heure est invalide !");
    e->T3[biblio::n3].setnb_heures(nb) ;
    }catch(string const& chaine)
      {cerr << chaine << endl;}
   }while((nb<0)||(nb>20));
/****************************************************/
    do{try{ cout <<"taper le departement  : "<< endl ;
    fflush(stdin);
    getline(cin,dep);
    if(checkEmptyString(dep.data())==true )
     throw string("cette departement  est vide !");
    e->T3[biblio::n3].setdepartement(dep) ;
    }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(dep.data()) );
/****************************************************/
    do{try{ cout <<"taper le grade : "<< endl ;
    fflush(stdin);
   getline(cin,gra);
   if(checkEmptyString(gra.data())==true )
     throw string("cette grade est vide !");
    e->T3[biblio::n3].setgrade(gra) ;
    }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(gra.data()) );



   biblio::n3++;
    cout<<"voulez vous ajouter un autre etudiant ? \nTAPER 1 POUR EFFECTUER L'AJOUT ! \nTAPER 0 POUR QUITTER !   \nVOTRE CHOIX  : ";
    cin>>res;
    cout<<"\n";

  }while((biblio::n3<100)&&(res==1));

	}
	}
void biblio::ajouter_biblio_enseignant(biblio* e)
{int ch;
    do{cout<<"\nVoulez vous ajouter un enseignant a notre platforme  ? \nTAPER 1 POUR EFFECTUER L'AJOUT ! \nTAPER 0 POUR QUITTER !   \nVOTRE CHOIX  : ";
   cin>>ch;
   }while(!((ch==1)||(ch==0)));

	if(ch==1)
	{
	   string n11 ,surname,vil,ruee,co,cla,uni,dep,gra;
       int ciin,cartee,nootee,nb;
/****************************************************/
 do{try{cout <<"taper le nom de l'enseignant  : "<< endl ;
    fflush(stdin);
    getline(cin,n11);
     if(checkEmptyString(n11.data())==true )
     throw string("cette nom est vide !");
    e->T3[biblio::n3].setnomm(n11) ;
     }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(n11.data()) );
/****************************************************/
     do{try{cout <<"taper le prenom de l'enseignant   : "<< endl ;
    fflush(stdin);
    getline(cin,surname);
     if(checkEmptyString(surname.data())==true )
     throw string("cette prenom est vide !");
     e->T3[biblio::n3].setprenom(surname) ;
     }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(surname.data()) );

/****************************************************/
  cout <<"taper le cin de l'enseignant (4 chiffres) : "<< endl ;
    fflush(stdin);
    std::cin >>ciin;


    e->T3[biblio::n3].setcen(ciin) ;

/****************************************************/
    do{try{ cout <<"taper la ville de l'enseignant   : "<< endl ;
    fflush(stdin);
    getline(cin,vil);
    if(checkEmptyString(vil.data())==true )
     throw string("cette ville est vide !");
    e->T3[biblio::n3].setville(vil) ;
    }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(vil.data()) );

/****************************************************/
     do{try{cout <<"taper le code postale de l'enseignant   : "<< endl ;
    fflush(stdin);
    getline(cin,co);
    if(checkEmptyString(co.data())==true )
     throw string("cette code postale est vide !");
    e->T3[biblio::n3].setcode_postale(co) ;
    }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(co.data()) );
/****************************************************/
    do{try{ cout <<"taper le nombre d'heure de l'enseignant (entre 0 et 20) : "<< endl ;
    fflush(stdin);
    std::cin >>nb;
     if((nb<0)||(nb>20))
     throw string("ce nombre d'heure est invalide !");
    e->T3[biblio::n3].setnb_heures(nb) ;
    }catch(string const& chaine)
      {cerr << chaine << endl;}
   }while((nb<0)||(nb>20));
/****************************************************/
    do{try{ cout <<"taper le departement  : "<< endl ;
    fflush(stdin);
    getline(cin,dep);
    if(checkEmptyString(dep.data())==true )
     throw string("cette departement  est vide !");
    e->T3[biblio::n3].setdepartement(dep) ;
    }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(dep.data()) );
/****************************************************/
    do{try{ cout <<"taper le grade : "<< endl ;
    fflush(stdin);
   getline(cin,gra);
   if(checkEmptyString(gra.data())==true )
     throw string("cette grade est vide !");
    e->T3[biblio::n3].setgrade(gra) ;
    }catch(string const& chaine )
      {cerr << chaine << endl;}
   }while(checkEmptyString(gra.data()) );


   biblio::n3++;
}}


int biblio :: recherche_livre(string tit ,int code1,biblio* e)//recherche  par
 {int i;
 for(i=0;i<=biblio::n2;i++)
 {
     if((strcasecmp(tit.c_str(), e->T2[i].gettitre().c_str())==0)&&(code1==e->T2[i].getcode()))
        {
        return 0;
         }
 }
 return 1;
 }

 int  biblio::recherche_enseignant_par_nom_et_prenom(string nom,string prenom,biblio *e  )
 {int i;
 for(i=0;i<=biblio::n3;i++)
 {
     if((strcasecmp(nom.c_str(), e->T3[i].getnom().c_str())==0)&&(strcasecmp(e->T3[i].getprenom().c_str(),prenom.c_str()))==0)
     {
         return 0;
     }
 }
return 1;
 }
int  biblio::recherche_edudiant_par_nom_et_prenom(string nom,string prenom,biblio *e  )
 {int i;
 for(i=0;i<=biblio::n1;i++)
 {
     if((strcasecmp(nom.c_str(), e->T1[i].getnom().c_str())==0)&&(strcasecmp(e->T1[i].getprenom().c_str(),prenom.c_str()))==0)
     {
         return 0;
     }
 }
return 1;
 }


 int  biblio::recherche_edudiant_par_cin_et_cen(int c1,int c2,biblio *e  )
 {int i;
 for(i=0;i<=biblio::n1;i++)
 {
     if( (e->T1[i].getcen()==c1)&&(e->T1[i].getcarte_etud()==c2))
     {
         return 0;
     }
 }
return 1;
 }

 int  biblio::recherche_enseignant_par_cin(int c1,biblio *e  )
 {int i;
 for(i=0;i<=biblio::n3;i++)
 {
     if( (e->T3[i].getcen()==c1))
     {
         return 0;
     }
 }
return 1;
 }

 //carte_etud,meilleur_note,nb_abscence, classe,universite
 int biblio::recherche_edudiant_par_tous_prop(biblio *e  )
{Etudiants *r1;
Etudiants r;
r1=r.cree_etud_sans_tab();
    int i;
 for(i=0;i<=biblio::n1;i++)
 {
     if((strcasecmp(r1->getnom().c_str(),e->T1[i].getnom().c_str())==0)&&
        (strcasecmp(r1->getprenom().c_str(), e->T1[i].getprenom().c_str())==0)&&
        (e->T1[i].getcen()==r1->getcen())&&
        (strcasecmp(r1->getville().c_str(), e->T1[i].getville().c_str())==0)&&
        (strcasecmp(r1->getcode_postale().c_str(), e->T1[i].getcode_postale().c_str())==0)&&
        (e->T1[i].getcarte_etud()==r1->getcarte_etud())&&
        (e->T1[i].getmeilleur_note()==r1->getmeilleur_note())&&
        (e->T1[i].getnb_abscence()==r1->getnb_abscence())&&
        (strcasecmp(r1->getcalsse().c_str(), e->T1[i].getcalsse().c_str())==0))

     {
         return 0;
     }}
     return 1;
 }
int biblio::recherche_enseignant_par_tous_prop(biblio *e  )
{ens *r1;
ens r;
r1=r.cree_ens_sans_tab();
    int i;
 for(i=0;i<=biblio::n3;i++)
 {
     if((strcasecmp(r1->getnom().c_str(),e->T3[i].getnom().c_str())==0)&&
        (strcasecmp(r1->getprenom().c_str(), e->T3[i].getprenom().c_str())==0)&&
        (e->T3[i].getcen()==r1->getcen())&&
        (strcasecmp(r1->getville().c_str(), e->T3[i].getville().c_str())==0)&&
        (strcasecmp(r1->getcode_postale().c_str(), e->T3[i].getcode_postale().c_str())==0)&&
        (e->T3[i].getnb_heures()==r1->getnb_heures())&&
        (strcasecmp(r1->getgrade().c_str(), e->T3[i].getgrade().c_str())==0)&&
        (strcasecmp(r1->getdepartement().c_str(), e->T3[i].getdepartement().c_str())==0))

     {
         return 0;
     }}
     return 1;
 }


 int biblio::recherche_livre_par_tout_prop(biblio *e  )
{livre *r1;
livre r;
r1=r.cree_livre_sans_tab();
    int i;
 for(i=0;i<=biblio::n2;i++)
 {
     if((strcasecmp(r1->gettitre().c_str(),e->T2[i].gettitre().c_str())==0)&&
        (strcasecmp(r1->getauteur().c_str(), e->T2[i].getauteur().c_str())==0)&&
        (e->T2[i].getcode()==r1->getcode())&&
        (e->T2[i].getannee()==r1->getannee())
        )

     {
         return 0;
     }}
     return 1;
 }
void biblio:: emprunter_des_livre_pour_les_etudient(int code  ,biblio* b,int cen)
{
    int i,j,ch1=0,ch2=0;

    for(i=0;i<biblio::n2;i++)
    {
        if(code==b->T2[i].getcode())
        {
         cout<<"\n";

        ch1=1;
        break;}
          else  {cout<<"ce livre n'existe pas dans la bibliotheque des livres";
            return ;}

    }
    for(j=0;j<biblio::n1;j++)
    {
        if(cen==b->T1[j].getcen())
           { cout<<"\n";
               ch2=1;
               break;}
               else{ cout<<"cette etudiant n'a pas d'abonnement";
            return ;}

                }

    if((ch1==1)&&(ch2==1))
    {
        Etudiants::x++;

       b->T1[j].Tlivreemp[Etudiants::x]=b->T2[i];


    }
}
void biblio:: rendre_un_livreetud(int code  ,biblio* b,int cen)
{int j,ch2,y=0;

for(j=0;j<biblio::n1;j++)
    {
        if(cen==b->T1[j].getcen())
           {ch2=1;
               break;}
               else{ cout<<"cette etudiant n'a pas d'abonnement";
            return ;}

                }
    while (y<Etudiants::x){

    if(!(code ==b->T1[j].Tlivreemp[y].getcode()))
     {
         y++;
     }

     for (int i=y;i<(Etudiants::x)-1;i++)

         b->T1[j].Tlivreemp[i+1]=b->T1[j].Tlivreemp[i];

 Etudiants::x--;

     }
     biblio::n2++;
     b->T2[biblio::n2]=b->T1[j].Tlivreemp[y];


}


void biblio:: aff_livre_emp_etudiants_dansbib(biblio*e)
{{for( int i=0;i<biblio::n1;i++)
Etudiants::aff_livre_emp_etudiants(e->T1[i]);
}
}
void biblio:: aff_livre_emp_enseignants_dansbib(biblio*e)
{{for( int i=0;i<biblio::n3;i++)
ens::aff_livre_emp_ens(e->T3[i]);
}
}

void biblio:: emprunter_des_livre_pour_les_enseignant(int code  ,biblio* b,int cen)
{
    int i,j,ch1=0,ch2=0;

    for(i=0;i<biblio::n2;i++)
    {
        if(code==b->T2[i].getcode())
        {
         cout<<"\n";

        ch1=1;
        break;}
          else  {cout<<"ce livre n'existe pas dans la bibliotheque des livres";
            return ;}

    }
    for(j=0;j<biblio::n3;j++)
    {
        if(cen==b->T3[j].getcen())
           { cout<<"\n";
               ch2=1;
               break;}
               else{ cout<<"cette enseignant n'a pas d'abonnement";
            return ;}

                }

    if((ch1==1)&&(ch2==1))
    {
       ens::z++;

       b->T3[j].TlivreempE[ens::z]=b->T2[i];


    }
}
void biblio:: rendre_un_livreens(int code  ,biblio* b,int cen)
{int j,ch2,y=0;

for(j=0;j<biblio::n3;j++)
    {
        if(cen==b->T3[j].getcen())
           {ch2=1;
               break;}
               else{ cout<<"cette enseignant n'a pas d'abonnement";
            return ;}

                }
    while (y<ens::z){

    if(!(code ==b->T3[j].TlivreempE[y].getcode()))
     {
         y++;
     }

     for (int i=y;i<(ens::z)-1;i++)

         b->T3[j].TlivreempE[i+1]=b->T3[j].TlivreempE[i];

 ens::z--;

     }
     biblio::n2++;
     b->T2[biblio::n2]=b->T3[j].TlivreempE[y];


}
/************************************enregistrement*********************************************/
//ville/code po/cen/m note/classe
void biblio:: enreg_tabetud(biblio *e)
{
    string n;
  ofstream fich;
  fich.open("fichier_etudiant.csv",ios::in | ios::out);
  fich << biblio::n1<<endl;
  for(int i=0;i<=biblio::n1;i++)
{
fich << e->T1[i].getnom() << "|"<< e->T1[i].getprenom()<<"|"<<e->T1[i].getcen()<<"|"<<e->T1[i].getville()<<e->T1[i].getcode_postale()<<"|"<<e->T1[i].getcarte_etud()<<"|"<<e->T1[i].getmeilleur_note()<<"|"<<e->T1[i].getcalsse()<<"|"<<endl ;;
}
fich.close();

}
void biblio:: enreg_tabens(biblio *e)
{//b_heures,grade,departement,universite
    string n;
  ofstream fich;
  fich.open("fichier_enseignant.csv",ios::in | ios::out);
  fich << biblio::n3<<endl;
  for(int i=0;i<=biblio::n3;i++)
{
fich << e->T3[i].getnom() << "|"<< e->T3[i].getprenom()<<"|"<<e->T3[i].getcen()<<"|"<<e->T3[i].getville()<<e->T3[i].getcode_postale()<<"|"<<e->T3[i].getnb_heures()<<"|"<<e->T3[i].getgrade()<<"|"<<e->T3[i].getdepartement()<<"|"<<endl ;;
}
fich.close();
}


void biblio:: enreg_tablivre(biblio *e)

//b_heures,grade,departement,universite
{string n;
  ofstream fich;
  fich.open("fichier_livre.csv",ios::in | ios::out);
  fich << biblio::n2<<endl;
  for(int i=0;i<=biblio::n2;i++)
{

fich << e->T2[i].gettitre() << "|"<< e->T2[i].getauteur()<<"|"<<e->T2[i].getcode()<<"|"<<e->T2[i].getannee()<<"|"<<endl ;
}
fich.close();
}


void biblio:: enreg_tablivreempens(biblio *e)
{//b_heures,grade,departement,universite
    string n;
  ofstream fich;
  fich.open("fichier livre emprunter_par etudiant.csv",ios::in | ios::out);
  fich << biblio::n2<<endl;
    {for(int i=0;i<=biblio::n3;i++)
    for (int j=0;j<=ens::z;j++)
    {fich <<  e->T3[i].TlivreempE[j].gettitre() << "|"<<e->T3[i].TlivreempE[j].getauteur()<<"|"<<e->T3[i].TlivreempE[j].getcode()<<"|"<< e->T3[i].TlivreempE[j].getannee()<<"|"<<endl ;


    }

    }
}

void biblio:: enreg_tablivreempetud(biblio *e)
{//b_heures,grade,departement,universite
    string n;
  ofstream fich;
  fich.open("fichier livre emprunter par enseignant.csv",ios::in | ios::out);
  fich << biblio::n2<<endl;
    {for(int i=0;i<=biblio::n3;i++)
    for (int j=0;j<=Etudiants::x;j++)
    {fich <<  e->T1[i]. Tlivreemp[j].gettitre() << "|"<<e->T1[i]. Tlivreemp[j].getauteur()<<"|"<<e->T1[i]. Tlivreemp[j].getcode()<<"|"<< e->T1[i]. Tlivreemp[j].getannee()<<"|"<<endl ;


    }

    }
}


void biblio::enregistrement(biblio *e)
{
     biblio:: enreg_tabetud(e);
     biblio:: enreg_tabens(e);
     biblio:: enreg_tablivre(e);
  biblio:: enreg_tablivreempetud(e);
    biblio::  enreg_tablivreempens(e);
}
/********************************search*******************************************/
int biblio:: search_livre_pos(biblio*e, int code)
{int i;
    for( i=0;i<biblio::n2;i++)
    {
        if(e->T2[i].getcode()==code )
            return -1;
    }
    return 0;
}
int biblio:: search_etudiant_pos(biblio*e, int code)
{int i;
    for( i=0;i<biblio::n1;i++)
    {
        if(e->T1[i].getcen()==code )
            return -1;
    }
    return 0;
}
/****************************************load***************************************/
void biblio::loadlivre(biblio *b)

{
    ifstream myfile;
    myfile.open("fichier_livre.csv",std::ofstream::out);
    if(myfile.is_open())
    {
        if(myfile.peek()==EOF)
        {
            cout<<"le fichier est vide\n";
        }
        else
        {
            string line1;
            getline(myfile,line1);
           biblio::n2=atoi(line1.c_str())-1;
            for (int i = 0; i <= biblio::n2; i++)
            {
                string line;
                char s1[20],s2[20],s3[20],s4[20],s5[20];
                int d=0,f=0,x=0;
                int ok1=0,ok2=0,ok3=0,ok4=0,ok5=0;
                getline(myfile,line);
                for(int k=0;k<line.length();k++)
                {

                    if(line.at(k)=='|')
                    {
                        if(f!=0)
                                d=f+2;
                        f=k-1;
                        x++;
                    }
                    if(x==1&&ok1==0)
                        {
                            ok1=1;
                            line.copy(s1,f-d+1,d);
                            s1[f-d+1]='\0';
                           b->T2[i].settitre(s1);
                        }
                    if(x==2&&ok2==0)
                    {
                        ok2=1;
                        line.copy(s2,f-d+1,d);
                        s2[f-d+1]='\0';
                     b->T2[i].setauteur(s2);                    }
                    if(x==3&&ok3==0)
                    {
                        ok3=1;
                        line.copy(s3,f-d+1,d);
                        s3[f-d+1]='\0';
                          b->T2[i].setannee(atoi(s3));
                    }
                    if(x==4&&ok4==0)
                    {
                        ok4=1;
                        line.copy(s4,f-d+1,d);
                        s4[f-d+1]='\0';
                         b->T2[i].setcode(atoi(s4));
                    }

                }
            }
        }
    }
}
/*---------------------------------------------------------------------------------------*/


void biblio::loadetudiant(biblio*e)
{
    ifstream myfile;
    myfile.open("fichier_etudiant.csv",std::ofstream::out);
    if(myfile.is_open())
    {
        if(myfile.peek()==EOF)
        {
            cout<<"le fichier est vide\n";
        }
        else
        {
            string line1;
            getline(myfile,line1);
           biblio::n1=atoi(line1.c_str())-1;
            for (int i = 0; i <=  biblio::n1; i++)
            {
                string line;
                char s1[20],s2[20],s3[20],s4[20],s5[20],s6[20],s7[20],s8[20],s9[20];
                int d=0,f=0,x=0;
                int ok1=0,ok2=0,ok3=0,ok4=0,ok5=0,ok6=0,ok7=0,ok8=0,ok9=0;
                getline(myfile,line);
                for(int k=0;k<line.length();k++)
                {

                    if(line.at(k)=='|')
                    {
                        if(f!=0)
                                d=f+2;
                        f=k-1;
                        x++;
                    }
                    if(x==1&&ok1==0)
                        {
                            ok1=1;
                            line.copy(s1,f-d+1,d);
                            s1[f-d+1]='\0';
                            e->T1[i].setnomm(s1);
                        }
                    if(x==2&&ok2==0)
                    {
                        ok2=1;
                        line.copy(s2,f-d+1,d);
                        s2[f-d+1]='\0';
                          e->T1[i].setprenom(s2);
                    }
                    if(x==3&&ok3==0)
                    {
                        ok3=1;
                        line.copy(s3,f-d+1,d);
                        s2[f-d+1]='\0';
                         e->T1[i].setcen(atoi(s3));
                    }


                     if(x==4&&ok4==0)
                    {
                        ok4=1;
                        line.copy(s4,f-d+1,d);
                        s4[f-d+1]='\0';
                        e->T1[i].setville(s4);    }

                    if(x==5&&ok5==0)
                    {
                        ok5=1;
                        line.copy(s5,f-d+1,d);
                        s5[f-d+1]='\0';
                        e->T1[i].setcode_postale(s5);    }
                        //carte_etud,meilleur_note,nb_abscence, classe
                         if(x==6&&ok6==0)
                    {
                        ok6=1;
                        line.copy(s6,f-d+1,d);
                        s6[f-d+1]='\0';
                        e->T1[i].setcarte_etud(atoi(s6));    }

                        if(x==7&&ok7==0)
                    {
                        ok7=1;
                        line.copy(s7,f-d+1,d);
                        s7[f-d+1]='\0';
                        e->T1[i].setmeilleur_note(atoi(s7));    }


                         if(x==8&&ok8==0)
                    {
                        ok8=1;
                        line.copy(s8,f-d+1,d);
                        s8[f-d+1]='\0';
                        e->T1[i].setnb_abscence(atoi(s8));    }

                         if(x==9&&ok9==0)
                    {
                        ok9=1;
                        line.copy(s9,f-d+1,d);
                        s9[f-d+1]='\0';
                        e->T1[i].setcalsse(s9);    }



                           }   }    }   }
}



void biblio::loadenseig(biblio*e)
{
    ifstream myfile;
    myfile.open("fichier livre emprunter par enseignant.csv",std::ofstream::out);
    if(myfile.is_open())
    {
        if(myfile.peek()==EOF)
        {
            cout<<"le fichier est vide\n";
        }
        else
        {
            string line1;
            getline(myfile,line1);
           biblio::n1=atoi(line1.c_str())-1;
            for (int i = 0; i <=  biblio::n1; i++)
            {
                string line;
                char s1[20],s2[20],s3[20],s4[20],s5[20],s6[20],s7[20],s8[20],s9[20];
                int d=0,f=0,x=0;
                int ok1=0,ok2=0,ok3=0,ok4=0,ok5=0,ok6=0,ok7=0,ok8=0,ok9=0;
                getline(myfile,line);
                for(int k=0;k<line.length();k++)
                {

                    if(line.at(k)=='|')
                    {
                        if(f!=0)
                                d=f+2;
                        f=k-1;
                        x++;
                    }
                    if(x==1&&ok1==0)
                        {
                            ok1=1;
                            line.copy(s1,f-d+1,d);
                            s1[f-d+1]='\0';
                            e->T1[i].setnomm(s1);
                        }
                    if(x==2&&ok2==0)
                    {
                        ok2=1;
                        line.copy(s2,f-d+1,d);
                        s2[f-d+1]='\0';
                          e->T1[i].setprenom(s2);
                    }
                    if(x==3&&ok3==0)
                    {
                        ok3=1;
                        line.copy(s3,f-d+1,d);
                        s2[f-d+1]='\0';
                         e->T1[i].setcen(atoi(s3));
                    }


                     if(x==4&&ok4==0)
                    {
                        ok4=1;
                        line.copy(s4,f-d+1,d);
                        s4[f-d+1]='\0';
                        e->T1[i].setville(s4);    }

                    if(x==5&&ok5==0)
                    {
                        ok5=1;
                        line.copy(s5,f-d+1,d);
                        s5[f-d+1]='\0';
                        e->T1[i].setcode_postale(s5);    }
                        //carte_etud,meilleur_note,nb_abscence, classe
                         if(x==6&&ok6==0)
                    {
                        ok6=1;
                        line.copy(s6,f-d+1,d);
                        s6[f-d+1]='\0';
                        e->T1[i].setcarte_etud(atoi(s6));    }

                        if(x==7&&ok7==0)
                    {
                        ok7=1;
                        line.copy(s7,f-d+1,d);
                        s7[f-d+1]='\0';
                        e->T1[i].setmeilleur_note(atoi(s7));    }


                         if(x==8&&ok8==0)
                    {
                        ok8=1;
                        line.copy(s8,f-d+1,d);
                        s8[f-d+1]='\0';
                        e->T1[i].setnb_abscence(atoi(s8));    }

                         if(x==9&&ok9==0)
                    {
                        ok9=1;
                        line.copy(s9,f-d+1,d);
                        s9[f-d+1]='\0';
                        e->T1[i].setcalsse(s9);    }



                           }   }    }   }
}



void biblio::loadletu(biblio*e)
{
    ifstream myfile;
    myfile.open("fichier livre emprunter par etudiant.csv",std::ofstream::out);
    if(myfile.is_open())
    {
        if(myfile.peek()==EOF)
        {
            cout<<"le fichier est vide\n";
        }
        else
        {
            string line1;
            getline(myfile,line1);
           biblio::n1=atoi(line1.c_str())-1;
           {for(int i=0;i<biblio::n1;i++)
                 {

                  for (int j=0;j<Etudiants::x;j++)
            {
                string line;
                char s1[20],s2[20],s3[20],s4[20],s5[20],s6[20],s7[20],s8[20],s9[20];
                int d=0,f=0,x=0;
                int ok1=0,ok2=0,ok3=0,ok4=0,ok5=0,ok6=0,ok7=0,ok8=0,ok9=0;
                getline(myfile,line);
                for(int k=0;k<line.length();k++)
                {

                    if(line.at(k)=='|')
                    {
                        if(f!=0)
                                d=f+2;
                        f=k-1;
                        x++;
                    }
                    if(x==1&&ok1==0)
                        {
                            ok1=1;
                            line.copy(s1,f-d+1,d);
                            s1[f-d+1]='\0';
                           e->T1[i].Tlivreemp[j].gettitre();
                        }
                    if(x==2&&ok2==0)
                    {
                        ok2=1;
                        line.copy(s2,f-d+1,d);
                        s2[f-d+1]='\0';
                         e->T1[i].Tlivreemp[j].getauteur();
                    }
                    if(x==3&&ok3==0)
                    {
                        ok3=1;
                        line.copy(s3,f-d+1,d);
                        s2[f-d+1]='\0';
                        e->T1[i].Tlivreemp[j].getcode();
                    }


                     if(x==4&&ok4==0)
                    {
                        ok4=1;
                        line.copy(s4,f-d+1,d);
                        s4[f-d+1]='\0';
                       e->T1[i].Tlivreemp[j].getannee() ;}




                           }   }    }   }
}

}}

void biblio::loadlens(biblio*e)
{
    ifstream myfile;
    myfile.open("fichier livre emprunter_par etudiant.csv",std::ofstream::out);
    if(myfile.is_open())
    {
        if(myfile.peek()==EOF)
        {
            cout<<"le fichier est vide\n";
        }
        else
        {
            string line1;
            getline(myfile,line1);
           biblio::n3=atoi(line1.c_str())-1;
           {for(int i=0;i<biblio::n3;i++)
                 {

                  for (int j=0;j<ens::z;j++)
            {
                string line;
                char s1[20],s2[20],s3[20],s4[20],s5[20],s6[20],s7[20],s8[20],s9[20];
                int d=0,f=0,x=0;
                int ok1=0,ok2=0,ok3=0,ok4=0,ok5=0,ok6=0,ok7=0,ok8=0,ok9=0;
                getline(myfile,line);
                for(int k=0;k<line.length();k++)
                {

                    if(line.at(k)=='|')
                    {
                        if(f!=0)
                                d=f+2;
                        f=k-1;
                        x++;
                    }
                    if(x==1&&ok1==0)
                        {
                            ok1=1;
                            line.copy(s1,f-d+1,d);
                            s1[f-d+1]='\0';
                           e->T3[i].TlivreempE[j].gettitre();
                        }
                    if(x==2&&ok2==0)
                    {
                        ok2=1;
                        line.copy(s2,f-d+1,d);
                        s2[f-d+1]='\0';
                         e->T3[i].TlivreempE[j].getauteur();
                    }
                    if(x==3&&ok3==0)
                    {
                        ok3=1;
                        line.copy(s3,f-d+1,d);
                        s2[f-d+1]='\0';
                        e->T3[i].TlivreempE[j].getcode();
                    }


                     if(x==4&&ok4==0)
                    {
                        ok4=1;
                        line.copy(s4,f-d+1,d);
                        s4[f-d+1]='\0';
                       e->T3[i].TlivreempE[j].getannee() ;}




                           }
                             }
                              }   }}}


                              }






/*********************************modification**************************************/
    void biblio::modifier_livre_par_titre(biblio*e,string titre1,string titre2)
    {
        for(int i=0;i<=biblio::n2;i++)
        {
     if(strcasecmp(titre1.c_str(), e->T2[i].gettitre().c_str())==0)
         e->T2[i].settitre(titre2);
    }    }


 void biblio:: modifier_livre_par_code(biblio*e,int co1,int co2)
 {
    for(int i=0;i<=biblio::n2;i++)
 {
     if( co1== e->T2[i].getcode())
         e->T2[i].setcode(co2);
    }
 }


 void biblio:: modifier_etudiant_par_nom(biblio*e,string nom1,string nom2)
 {
    for(int i=0;i<=biblio::n1;i++)
 {
     if((strcasecmp(nom1.c_str(), e->T1[i].getnom().c_str())==0))
         e->T1[i].setnomm(nom2);
    }
 }
 void biblio:: modifier_etudiant_par_prenom(biblio*e,string prenom1,string prenom2) {
    for(int i=0;i<=biblio::n1;i++)
 {
     if((strcasecmp(prenom1.c_str(), e->T1[i].getprenom().c_str())==0))
         e->T1[i].setprenom(prenom2);
    }
 }
 void biblio:: modifier_etudiant_par_cin(biblio*e,int cin1,int cin2)
 {
    for(int i=0;i<=biblio::n1;i++)
 {
     if( cin1== e->T1[i].getcen())
         e->T1[i].setcen(cin2);
    }
 }
 void biblio:: modifier_etudiant_par_ville(biblio*e,string ville1,string ville2)
 {
    for(int i=0;i<=biblio::n1;i++)
 {
     if((strcasecmp(ville1.c_str(), e->T1[i].getville().c_str())==0))
         e->T1[i].setville(ville2);
    }
 }
 void biblio:: modifier_etudiant_par_codepostale(biblio*e,string codepos1,string codepos2)
 {
    for(int i=0;i<=biblio::n1;i++)
 {
     if((strcasecmp(codepos1.c_str(), e->T1[i].getcode_postale().c_str())==0))
         e->T1[i].setcode_postale(codepos2);
    }
 }
 void biblio:: modifier_etudiant_par_meilleurn(biblio*e,int meilleurn1,int meilleurn2)
 {
    for(int i=0;i<=biblio::n1;i++)
 {
     if( meilleurn1==e->T1[i].getmeilleur_note())
         e->T1[i].setmeilleur_note(meilleurn2);
    }
 }
 void biblio:: modifier_etudiant_par_nb_abscence(biblio*e,int nba1,int nba2)
 {
    for(int i=0;i<=biblio::n1;i++)
 {
     if(nba1==e->T1[i].getnb_abscence())
         e->T1[i].setnb_abscence(nba2);
    }
 }
 void biblio:: modifier_etudiant_par_classe(biblio*e,string classe1,string classe2)
 {
    for(int i=0;i<=biblio::n1;i++)
 {
     if((strcasecmp(classe1.c_str(), e->T1[i].getcalsse().c_str())==0))
         e->T1[i].setcalsse(classe2);
    }
 }


 void biblio:: modifier_enseignant_par_nombreheures(biblio*e,int nb1,int nb2)
 {
    for(int i=0;i<=biblio::n3;i++)
 {
     if(nb1== e->T3[i].getnb_heures())
         e->T3[i].setnb_heures(nb2);
    }
 }

 void biblio:: modifier_enseignant_par_grade(biblio*e,string gr1,string gr2)
 {
    for(int i=0;i<=biblio::n3;i++)
 {
     if((strcasecmp(gr1.c_str(), e->T3[i].getgrade().c_str())==0))
         e->T3[i].setgrade(gr2);
    }
 }

 void biblio:: modifier_enseignant_par_departement(biblio*e,string dep1,string dep2)
 {
    for(int i=0;i<=biblio::n3;i++)
 {
     if((strcasecmp(dep1.c_str(), e->T3[i].getdepartement().c_str())==0))
         e->T3[i].setdepartement(dep2);
    }
 }

 /************************************************************/

