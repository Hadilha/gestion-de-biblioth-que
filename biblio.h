#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ens.h"
#include "livre.h"
#include "etudiants.h"
#include "personne.h"
#include <cstring>
#include <string.h>

/*bibliotheque :tab etudiant ,tab livre
les methodes:
cree biblio livre
cree biblio etudiant
ajouter biblio livre
ajouter biblio etudiant
supprimer livre nom et code
supprimer personne cen et nom
-affichage1
affichage2*/
using namespace std;


class biblio{
   public  :
    Etudiants *T1;
    livre *T2;
    ens *T3;
    int  static n1;
     int  static n3;
    int nb1;
    int nb2;
    int  static n2;
    public :

        static void cree_biblio_livre(biblio *);
        static  void ajouter_un_livre(biblio *);
         static void  affichertlivre(biblio *);
       biblio();

            static void cree_biblio_etudiant(biblio *);
            static void affichertetudiant(biblio *);
           static  void ajouter_biblio_etudiant(biblio *);

           static  void supprimer_livre_par_code(int,biblio * );
            static void supprimer_livre_par_titre(string ,biblio * );
            static int recherche_livre(string,int ,biblio* );
            static int recherche_livre_par_tout_prop(biblio *  );




            static int recherche_edudiant_par_nom_et_prenom(string,string,biblio *);
             static int recherche_edudiant_par_cin_et_cen(int ,int ,biblio *);
               static int recherche_edudiant_par_tous_prop(biblio *  );

            static void supprimer_etudiant_par_nom_et_prenom(string ,string ,biblio * );
           static  void  supprimer_etudiant_par_cin_et_cen(int ,int ,biblio * );
static void emprunter_des_livre_pour_les_etudient(int ,biblio*,int );
           static void aff_livre_emp_etudiants_dansbib(biblio*);
          static void  rendre_un_livreetud(int  ,biblio* ,int );
         static void aff_livre_emp_enseignants_dansbib(biblio*);
          static void rendre_un_livreens(int  ,biblio*,int );
static void  emprunter_des_livre_pour_les_enseignant(int  ,biblio* ,int );
         static  void   cree_biblio_enseignant(biblio *);
       static  void  affichertenseignant(biblio *);
         static void  supprimer_enseignant_par_nom_et_prenom(string ,string ,biblio * );
            static void supprimer_enseignant_par_cin(int  ,biblio * );
              static int recherche_enseignant_par_nom_et_prenom(string ,string ,biblio *  );
              static  int recherche_enseignant_par_cin(int  ,biblio * );
             static int recherche_enseignant_par_tous_prop(biblio * );
 static void enreg_tabetud(biblio *);
 static void  enreg_tabens(biblio *);
 static void  enreg_tablivre(biblio *);
 static void enreg_tablivreempetud(biblio *);
 static void enreg_tablivreempens(biblio *);
 static void enregistrement(biblio *);
  static int search_etudiant_pos(biblio* ,int);

 static void loadetudiant(biblio *);
 static void loadlivre(biblio *);
  static void loadenseig(biblio *);
 static void loadletu(biblio*);
  static void loadlens(biblio*);


 static int search_livre_pos(biblio*, int );
static void modifier_livre_par_titre(biblio*,string,string );
static void modifier_livre_par_code(biblio*,int,int );
static void  modifier_etudiant_par_nom(biblio*,string ,string);
 static void modifier_etudiant_par_prenom(biblio*,string ,string);
 static void  modifier_etudiant_par_cin(biblio*,int ,int );
 static void modifier_etudiant_par_ville(biblio*,string ,string);
  static void modifier_etudiant_par_codepostale(biblio*,string ,string );
   static void  modifier_etudiant_par_meilleurn(biblio*,int ,int );
 static void  modifier_etudiant_par_nb_abscence(biblio*,int ,int );
 static void  modifier_etudiant_par_classe(biblio*,string,string);
  static void  modifier_enseignant_par_nombreheures(biblio*,int ,int );
  static void modifier_enseignant_par_grade(biblio*e,string ,string );
  static void  modifier_enseignant_par_departement(biblio*e,string ,string);
 static bool  checkEmptyString(const char *);

static  void  ajouter_biblio_enseignant(biblio *);





/*supprimer livre par code
supprimer livre par titre
supprimer_etudiant_par_nom_et_prenom
supprimer_etudiant_par_cin_et_cen*/
         };


#endif // BIBLIO_H_INCLUDED



