#include <gtk/gtk.h>

typedef struct
{
char nom[50]; 
char prenom[50] ;
char cin[50] ;
char user[50] ;
char password[50];
}client; 

typedef struct 
{
char nom[50] ;
char prenom[50] ;
int j ;
int m;
int y ;
char user[50] ;
char password[50];
}emp ;

typedef struct 
{
char nom[30] ;
char prenom[30] ;
char user[30];
char password[30];  
char date[30]; 
}empl;



int inscri (client c) ;


void ajouteremployer (emp e);
 
void afficheremp (GtkTreeView *liste) ; 
void afficherclient (GtkTreeView *liste) ;


void supprimeremployer(char name[]); 
void modifieremployer (char name[],char newuser[] ,char newpass[]); 
void supprimerclient (char cin[]) ; 
void modifierclient (char cin[],char newuser[] ,char newpass[]) ;  
