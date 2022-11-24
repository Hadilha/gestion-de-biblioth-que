

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include "myconio.h"
#include <stdio.h>
#include <windows.h>
#include<iostream>
#include <stdio.h>
#include "biblio.h"
#include <string>
#include "etudiants.h"
#include "livre.h"
#include <fstream>
#include <new>
#include <cstring>
#include <string.h>
#include<fstream>


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;

HWND hname ,hage,hout,hogo,Add,Finnish;
 HDC hdc;
HMENU hmenu ;
biblio *b1;


HBITMAP hlogoImage , hgenerateImage;
int intro=1 ;
char ch[30] ;
long p ;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("my project");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    b1=new biblio();
b1->T2=new livre [100];
b1->T1=new Etudiants [100];
b1->T3=new ens [100];
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("my project"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1250,                 /* The programs width */
           768,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HBITMAP  hBmp;



   /* if(intro)
    {
        system("start test.exe") ;
        intro=0;
    }*/


    switch (message)                  /* handle the messages */
    {

        case WM_COMMAND:
        switch(wParam)
        {

        case 0:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                biblio::cree_biblio_livre(b1);
                biblio::affichertlivre(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 1:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                biblio::cree_biblio_etudiant(b1);
                biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 2:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                biblio::cree_biblio_enseignant(b1);
                biblio::affichertenseignant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
       case 3:system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int b;
                cout<<"voulez vous ajoutez un autre livre ?\n si oui tapez 1\n si non tapez 0";
                cin>>b;
                if(b==1)
                biblio::ajouter_un_livre(b1);
                biblio::affichertlivre(b1);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

        case 4:
           system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int codee;
                cout<<"donner le code de livre voulez supprimer";
            cin>>codee;
              biblio::supprimer_livre_par_code(codee ,b1);
              biblio::affichertlivre(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

       case 5:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               string ti;
                cout<<"donner le titre  de livre voulez supprimer";
            cin>>ti;
              biblio::supprimer_livre_par_titre(ti ,b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 6:
            {system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                string titre1,titre2;
                cout<<"donner le titre  de livre voulez modifier";
                 fflush(stdin);
           getline(cin,titre1);
            cout<<"donner le nouveaux titre";
             fflush(stdin);
            getline(cin,titre2);
              biblio::modifier_livre_par_titre(b1,titre1,titre2);
              biblio::affichertlivre(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 7:
       {system("color F9");
                ShowWindow(hwnd,SW_HIDE);
             int code1,code2;
                cout<<"donner le code  de livre voulez modifier ";
           cin>>code1;
            cout<<"donner le nouveaux code";
            cin>>code2;
              biblio::modifier_livre_par_code(b1,code1,code2);
              biblio::affichertlivre(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
        case 8:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int b;
                cout<<"voulez vous ajoutez un autre etudiant ?\n si oui tapez 1\n si non tapez 0";
                cin>>b;
                if(b==1)
                biblio::ajouter_biblio_etudiant(b1);
                biblio::affichertetudiant(b1);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}


            case 9:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               string pr1,pr2;
                cout<<"donner le nom du l'etudiant  voulez supprimer";
                 fflush(stdin);
           getline(cin,pr1);
          cout<<"donner le prenom du l'etudiant  voulez supprimer";
             fflush(stdin);
            getline(cin,pr2);
              biblio::supprimer_etudiant_par_nom_et_prenom(pr1,pr2,b1);
              biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}



        case 10:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int cinn,cen;
                cout<<"donner le cin du l'etudiant  voulez supprimer";
                 fflush(stdin);
           cin>>cinn;
          cout<<"donner le cen du l'etudiant  voulez supprimer";
             fflush(stdin);
            cin>>cen;
              biblio::supprimer_etudiant_par_cin_et_cen(cinn,cen,b1);
              biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 11:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                string n1,n2;
                cout<<"donner le nom de l'etudiant voulez modifier";
                fflush(stdin);
                getline(cin,n1);
                cout<<"donner le nouveaux nom";
                fflush(stdin);
                getline(cin,n2);
                biblio::modifier_etudiant_par_nom(b1,n1,n2);
                biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}


        case 12:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                string prenom1,prenom2;
                cout<<"donner le prenom de l'etudiant voulez modifier";
                 fflush(stdin);
           getline(cin,prenom1);
            cout<<"donner le nouveaux prenom";
             fflush(stdin);
            getline(cin,prenom2);
              biblio::modifier_etudiant_par_prenom(b1,prenom1,prenom2);
              biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 13:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               int cin1,cin2;
                cout<<"donner le cin de l'etudiant voulez modifier";
                 fflush(stdin);
           cin>>cin1;
            cout<<"donner le nouveaux cin";
             fflush(stdin);
            cin>>cin2;
              biblio::modifier_etudiant_par_cin(b1,cin1,cin2);
              biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}



        case 14:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
              string ville1,ville2;
                cout<<"donner le ville de l'etudiant voulez modifier";
                 fflush(stdin);
           getline(cin,ville1);
            cout<<"donner la nouvelle ville";
             fflush(stdin);
            getline(cin,ville2);
              biblio::modifier_etudiant_par_ville(b1,ville1,ville2);
              biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}


        case 15:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
              string cp1,cp2;
                cout<<"donner le code postale de l'etudiant voulez modifier";
                 fflush(stdin);
           getline(cin,cp1);
            cout<<"donner le nouveaux le code postale";
             fflush(stdin);
            getline(cin,cp2);
              biblio::modifier_etudiant_par_codepostale(b1,cp1,cp2);
              biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}


        case 16:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
              int m1,m2;
                cout<<"donner le meilleur note de l'etudiant voulez modifier";
                 fflush(stdin);
           cin>>m1;
            cout<<"donner le nouveaux meilleur note";
             fflush(stdin);
            cin>>m2;
              biblio::modifier_etudiant_par_meilleurn(b1,m1,m2);
              biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 17:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
              int m1,m2;
                cout<<"donner le nombre d'absence de l'etudiant voulez modifier";
                 fflush(stdin);
           cin>>m1;
            cout<<"donner la nouvelle nombre d'absence";
             fflush(stdin);
            cin>>m2;
              biblio::modifier_etudiant_par_nb_abscence(b1,m1,m2);
              biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 18:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
              string cp1,cp2;
                cout<<"donner la classe l'etudiant voulez modifier";
                 fflush(stdin);
           getline(cin,cp1);
            cout<<"donner le nouveaux la classe";
             fflush(stdin);
            getline(cin,cp2);
              biblio::modifier_etudiant_par_classe(b1,cp1,cp2);
              biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
        case 19:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int b;
                cout<<"voulez vous ajoutez un autre enseignant ?\n si oui tapez 1\n si non tapez 0";
                cin>>b;
                if(b==1)
                biblio::ajouter_biblio_enseignant(b1);
                biblio::affichertenseignant(b1);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
        case 20:
            {system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               string pr1,pr2;
                cout<<"donner le nom du l'enseignant voulez supprimer";
                 fflush(stdin);
           getline(cin,pr1);
          cout<<"donner le prenom du l'enseignant  voulez supprimer";
             fflush(stdin);
            getline(cin,pr2);
              biblio::supprimer_enseignant_par_nom_et_prenom(pr1,pr2,b1);
               biblio::affichertenseignant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
        case 21:
                {system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int cinn;
                cout<<"donner le cin du l'enseignant voulez supprimer";
                 fflush(stdin);
                cin>>cinn;
                biblio::supprimer_enseignant_par_cin(cinn,b1);
                biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
        case 22:
            {system("color F9");
                ShowWindow(hwnd,SW_HIDE);
              int gr1,gr2;
                cout<<"donner le nombre d'heure de l'enseignant voulez modifier";
                 fflush(stdin);
        cin>>gr1;
            cout<<"donner le nouveaux  nombre d'heure";
             fflush(stdin);
          cin>>gr2;
              biblio::modifier_enseignant_par_nombreheures(b1,gr1,gr2);
              biblio::affichertenseignant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

            case 23:
            {system("color F9");
                ShowWindow(hwnd,SW_HIDE);
              string dep1,dep2;
                cout<<"donner le grade de l'enseignant voulez modifier";
                 fflush(stdin);
           getline(cin,dep1);
            cout<<"donner le nouveaux grade";
             fflush(stdin);
            getline(cin,dep2);
              biblio::modifier_enseignant_par_grade(b1,dep1,dep2);
              biblio::affichertenseignant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

                 case 24:
            {system("color F9");
                ShowWindow(hwnd,SW_HIDE);
              string dep1,dep2;
                cout<<"donner le deparement de l'enseignant voulez modifier";
                 fflush(stdin);
           getline(cin,dep1);
            cout<<"donner le nouveaux deparement";
             fflush(stdin);
            getline(cin,dep2);
              biblio::modifier_enseignant_par_departement(b1,dep1,dep2);
              biblio::affichertenseignant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}


                 case 25:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int y,z;
                cout<<"donner le cin de l'etudiant qui va emprunter le livre " ;
                 fflush(stdin);
                cin>>y;
                cout<<"donner le code de livre a emprunter";
                fflush(stdin);
                cin>>z;
                biblio::aff_livre_emp_etudiants_dansbib(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                 case 26:
                     {system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int y,z;
                cout<<"donner le cin de l'enseignant qui va emprunter le livre " ;
                 fflush(stdin);
                cin>>y;
                cout<<"donner le code de livre a emprunter";
                fflush(stdin);
                cin>>z;
                biblio::emprunter_des_livre_pour_les_enseignant(z,b1,y);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

                 case 27:
                   {
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int code6;
                string t;
                cout<<"donner le titre de livre a rechercher";
                fflush(stdin);
                getline(cin,t);
                cout<<"donner le code du livre a rechercher";
                fflush(stdin);
                cin>>code6;
                int i4=biblio::recherche_livre(t,code6,b1);
                if (i4==0)
                cout<<"le livre est existant";
                else if(i4==1)
                cout<<"le livre n n'existe pas";
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                 case 28:
                     {
                    system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int i7=biblio::recherche_livre_par_tout_prop(b1);
                if (i7==0)
                cout<<"le livre est existant";
                else if(i7==1)
                cout<<"le livre n n'existe pas";
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                 case 29:
                     {

                    system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                string c,v;
                 cout<<"donner le nom de l'etudiant a rechercher";
                fflush(stdin);
                getline(cin,c);
                cout<<"donner le prenom de l'etudiant a rechercher";
                fflush(stdin);
                getline(cin,v);

                int i9=biblio::recherche_edudiant_par_nom_et_prenom(c,v,b1);
                if (i9==0)
                cout<<"ce etudiant est existant";
                else if(i9==1)
                cout<<"ce etudiant n'existe pas";
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

                case 30:
                     {
                    system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int n1,n2;
                 cout<<"donner le cin de l'etudiant a rechercher";
                fflush(stdin);
                cin>>n1;
                cout<<"donner le cen de l'etudiant a rechercher";
                fflush(stdin);
                cin>>n2;
                int i3=biblio::recherche_edudiant_par_cin_et_cen(n1,n2,b1);
                if (i3==0)
                cout<<"ce etudiant est existant";
                else if(i3==1)
                cout<<"ce etudiant n'existe pas";
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                case 31:
                     {
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int i11=biblio::recherche_edudiant_par_tous_prop(b1);
                if (i11==0)
                cout<<"ce etudiant est existant";
                else if(i11==1)
                cout<<"ce etudiant n'existe pas";
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                case 32:
                     {

                    system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                string c1,v1;
                 cout<<"donner le nom de l'enseignant a rechercher";
                fflush(stdin);
                getline(cin,c1);
                cout<<"donner le prenom de l'enseignant a rechercher";
                fflush(stdin);
                getline(cin,v1);

                int i33=biblio::recherche_enseignant_par_nom_et_prenom(c1,v1,b1);
                if (i33==0)
                cout<<"cette enseignant est existant";
                else if(i33==1)
                cout<<"cette enseignant n'existe pas";
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

                 case 33:
                     {

                    system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int j;
                 cout<<"donner le cin de l'enseignant a rechercher";
                fflush(stdin);
                cin>>j;
                int i44=biblio::recherche_enseignant_par_cin(j,b1);
                if (i44==0)
                cout<<"cette enseignant est existant";
                else if(i44==1)
                cout<<"cette enseignant n'existe pas";
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

                case 34:
                     {system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                int i55=biblio::recherche_enseignant_par_tous_prop(b1);
                if (i55==0)
                cout<<"cette enseignant est existant";
                else if(i55==1)
                cout<<"cette enseignant n'existe pas";
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                case 35:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio::affichertlivre(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                case 36:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio::affichertetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                case 37:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio::affichertenseignant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                case 38:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio::aff_livre_emp_etudiants_dansbib(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                    case 39:{system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio::aff_livre_emp_enseignants_dansbib(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}


                case 40:{ system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio:: enreg_tablivre(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                case 41:{ system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio::  enreg_tabetud(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

                case 42:{ system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio:: enreg_tabens(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

                case 43:{ system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio:: enreg_tablivreempetud(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                case 44:{ system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio:: enreg_tablivreempens(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

               case 45:
                    { system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio:: loadlivre(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
                case 46:
                    { system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio:: loadetudiant(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

                case 47:
                    { system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio:: loadenseig(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

                case 48:
                    { system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio:: loadletu(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

                case 49:
                    { system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               biblio:: loadlens(b1);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}





                 case 50:
                if (MessageBox(hwnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hwnd);
                    system("cls");
                }



        }
     case WM_CREATE :
        addmenus(hwnd);
//         CreateBtt(hwnd) ;
    /*****************ajouter fond **********************/
            hBmp=(HBITMAP)LoadImage(0,"c++.bmp",IMAGE_BITMAP,1560,800,LR_LOADFROMFILE);

            break;

        case WM_PAINT :
            {

         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            PostQuitMessage (0);        /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    HMENU htp=CreateMenu();
    HMENU htp1=CreateMenu();
    HMENU htp2=CreateMenu();
    HMENU htp3=CreateMenu();
    HMENU htp33=CreateMenu();
    HMENU htp4=CreateMenu();
    HMENU htp5=CreateMenu();
     HMENU htp6=CreateMenu();
    HMENU hex2=CreateMenu();
    HMENU hex3=CreateMenu();
    HMENU hex4=CreateMenu();
    HMENU hex5=CreateMenu();
    HMENU hex6=CreateMenu();
    HMENU hex1=CreateMenu();
    HMENU hex8=CreateMenu();
    HMENU hex9=CreateMenu();
    HMENU hex7=CreateMenu();
    HMENU hex12=CreateMenu();
            HMENU hex11=CreateMenu();

     HMENU hex44=CreateMenu();
        HMENU hex77=CreateMenu();




   /************************** creation du base de donneee*****************************/
   AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp," Creation du base de donnee");

       AppendMenu(htp,MF_STRING,0,"cree un base de donnee pour les livres ");
       AppendMenu(htp,MF_STRING,1,"cree un base de donnee pour les etudiants  ");
       AppendMenu(htp,MF_STRING,2,"cree un base de donnee pour les enseignant  ");


    /*******************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp1,"Mise a jour des base de donnee ");

    AppendMenu(htp1,MF_STRING,3,"Ajouter un nouvel livre");

    AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex1," Supprimer un livre");
        AppendMenu(hex1,MF_STRING,4," Suppression du livre par code");
        AppendMenu(hex1,MF_STRING,5,"Suppression du livre par titre");

    AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex2," Modifier les données d'un livre ");
        AppendMenu(hex2,MF_STRING,6," titre");
        AppendMenu(hex2,MF_STRING,7,"annee");

    AppendMenu(htp1,MF_STRING,8,"Ajouter un nouvel etudiant");

    AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex3," Supprimer un etudiant");
        AppendMenu(hex3,MF_STRING,9," Suppression d'un etudiant par nom et prenom");
        AppendMenu(hex3,MF_STRING,10," Suppression d'un etudiant par cin  et cen");
       //nom,prenom, S cen,ville,rue,code_postale
    AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex4," Modifier les données d'un etudiant ");
        AppendMenu(hex4,MF_STRING,11," nom");
        AppendMenu(hex4,MF_STRING,12,"prenom");
        AppendMenu(hex4,MF_STRING,13," cin");
        AppendMenu(hex4,MF_STRING,14," ville");
        AppendMenu(hex4,MF_STRING,15," code postale ");
        AppendMenu(hex4,MF_STRING,16,"meilleur note");
        AppendMenu(hex4,MF_STRING,17," nombre d'absence");
        AppendMenu(hex4,MF_STRING,18," classe ");

      AppendMenu(htp1,MF_STRING,19,"Ajouter un nouvel enseignant");

    AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex5," Supprimer un enseignant");
        AppendMenu(hex5,MF_STRING,20," Suppression d'un enseignant par nom et prenom");
        AppendMenu(hex5,MF_STRING,21," Suppression d'un enseignant par cin  ");
       //nom,prenom, S cen,ville,rue,code_postale
    AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex6," Modifier les données d'un enseignant ");
        AppendMenu(hex6,MF_STRING,22," nombre d'heures");
        AppendMenu(hex6,MF_STRING,23,"grade");
        AppendMenu(hex6,MF_STRING,24," département");
/********************************************************************/
 AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp2," Menu emprunter livres ");

       AppendMenu(htp2,MF_POPUP,(UINT_PTR)hex44,"  emprunter  ");
           AppendMenu(hex44,MF_STRING,25," etudiant ");
           AppendMenu(hex44,MF_STRING,26," enseignant");

/***************************************************************/

    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp3," Menu recherche ");

       AppendMenu(htp3,MF_POPUP,(UINT_PTR)hex7," recherche livre ");
           AppendMenu(hex7,MF_STRING,27," titre et code ");
           AppendMenu(hex7,MF_STRING,28," tout ses proprieter");
       AppendMenu(htp3,MF_POPUP,(UINT_PTR)hex8," recherche etudiant ");
           AppendMenu(hex8,MF_STRING,29,"nom et prenom ");
           AppendMenu(hex8,MF_STRING,30," cin et cen ");
           AppendMenu(hex8,MF_STRING,31," tout ses proprieter");
       AppendMenu(htp3,MF_POPUP,(UINT_PTR)hex9," recherche enseignant ");
           AppendMenu(hex9,MF_STRING,32,"nom et prenom ");
           AppendMenu(hex9,MF_STRING,33," cin  ");
           AppendMenu(hex9,MF_STRING,34," tout ses proprieter");
/********************************************************************/
 AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp4," Menu  affichage ");
    AppendMenu(htp4,MF_STRING,35," affichage des livres ");
    AppendMenu(htp4,MF_STRING,36," affichage des etudiants ");
      AppendMenu(htp4,MF_STRING,37," affichage enseignants ");
      AppendMenu(htp4,MF_STRING,38," affichage les livres emprunter par etudiants ");
      AppendMenu(htp4,MF_STRING,39," affichage les livres emprunter par enseignants ");



      /***************************************************************/

    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp5,"Menu enregistrement et chargement");

      AppendMenu(htp5,MF_POPUP,(UINT_PTR)hex11,"Enregistrement");
                 AppendMenu(hex11,MF_STRING,40,"les livre");
                 AppendMenu(hex11,MF_STRING,41,"les etudiants ");
                 AppendMenu(hex11,MF_STRING,42,"les  enseignants");
                AppendMenu(hex11,MF_STRING,43,"les livre emprunter par etudiant");
                AppendMenu(hex11,MF_STRING,44,"les livre emprunter par  enseignants");

     AppendMenu(htp5,MF_POPUP,(UINT_PTR)hex12,"chargement");
                 AppendMenu(hex12,MF_STRING,45,"les livre");
                 AppendMenu(hex12,MF_STRING,46,"les etudiants ");
                 AppendMenu(hex12,MF_STRING,47,"les  enseignants");
                AppendMenu(hex12,MF_STRING,48,"les livre emprunter par etudiant");
                AppendMenu(hex12,MF_STRING,49,"les livre emprunter par  enseignants");


/***************************************************************/

    AppendMenu(hmenu,MF_STRING,50,"Quitter");
    SetMenu(hwnd,hmenu);
}

















