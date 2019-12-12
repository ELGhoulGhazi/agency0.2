#include <gtk/gtk.h>


typedef struct 
{
char pays[50]; 
char hotel[50]; 
char prix[50]; 
}hyber; 

typedef struct 
{
char pays[50]; 
char hotel[50][50]; 
char prix[50]; 
}hyberg; 

typedef struct 
{
char marque[50]; 
char prix[50];  
}loc; 

typedef struct 
{
char depart[50]; 
char destination[50];
char heure[50]; 
char compagnie[50]; 
char datealler[50]; 
char dateretour[50]; 
char prix[50];   
}vollemp;


typedef struct 
{
char depart[50]; 
char destination[50];
char heure[50]; 
char compagnie[50]; 
char ar[50]; 
char datealler[50]; 
char dateretour[50];
char classe[50];
int adulte ; 
int enf ;  
int bb ;
char cin[50]; 
int prix;    
}volclient;

typedef struct
{
char cin[50]; 
char pays[50]; 
char hotel[50]; 
int jd ;
int nbp ; 
char fnf[50]; 
int prix ; 
}hyberclient ;  

typedef struct 
{
char cin[50]; 
char marque[50]; 
int nbj ; 
int prix ; 
}locationclient ; 
 







int verifierdest (char depart[] ,char destination[], char heurededepart[50][50] ,char compagnie[50][50],char datealler[50][50], char dateretour[50][50],char prix[]) ; 
void ajoutervol (char depart[] ,char destination[], char heurededepart[] ,char compagnie[],char datealler[], char dateretour[],char prix[]) ; 
void ajouterhybergement(hyber h); 
void ajouterlocation(loc l);
int verifierpays (hyberg h) ; 
int affichermarque (char marque[][50]) ;
int departdestdispo (char depart[][30] ,char destination[][30]) ;
int paysdispo (char pays[][50]) ; 



void affichervol (GtkTreeView *liste);
void afficherhybergement (GtkTreeView *liste); 
void afficherlocation (GtkTreeView *liste);

void supprimervol(char depart[],char destination[] ,char compagnie[]); 
void modifiervol (char depart[],char destination[] ,char compagnie[] ,char newdate[] ,char newdater[] ,char newprix[]);
void supprimerhyber(char hotel[]);
void modifierhyber (char hotel[] ,char newprix[]); 
void supprimerloc(char marque[]);
void modifierloc (char marque[] ,char newprix[]);

void reservervol(volclient cv) ;
void reserverhyber(hyberclient hc) ;
void reserverlocation(locationclient lc) ; 


void reservtotal(char cin[]) ; 
void afficherreservation (GtkTreeView *liste);

void stockage() ;
void effacer() ;


void messgae(char cin[] ,char message[]);
void affichermessage (GtkTreeView *liste) ;
void suppmsg(char cin[]);


void reclamer(char cin[] ,char message[] ,char type[],int j ,int m , int y ) ;
void afficherrec (GtkTreeView *liste);
void modifieretat(char cin1[]); 
void supprimerrec(char cin1[]);
void supprimerfact(char cin1[]);
void afficherfact (GtkTreeView *liste);



void afficherprixvol(char depart[] ,char dest[] ,char comp[] ,char prix[]);
void afficherprixhyber(char hotel[] ,char prix[]);
void afficherprixloc(char marque[] ,char prix[]);

//int departdestdispo (char depart[][30] ,char destination[][30]);
