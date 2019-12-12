#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"reservation.h"
#include <gtk/gtk.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif






int verifierdest (char depart[] ,char destination[], char heurededepart[50][50] ,char compagnie[50][50],char datealler[50][50], char dateretour[50][50],char prix[] ) 
{
char depart1[30] ;
char destination1[30] ;
char heurededepart1[30] ;
char compagnie1[30] ;
char datealler1[30] ;
char dateretour1[30];
char prix1[30] ;

int a=1,b=1,c=0 ; 

FILE *f ; 
f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s \n",depart1,destination1,heurededepart1,compagnie1,datealler1,dateretour1,prix1)!=EOF)
{
a=strcmp(depart,depart1) ; 
  b=strcmp(destination,destination1) ;

if (a==0 && b==0) 
{
strcpy(compagnie[c],compagnie1) ; 
strcpy(heurededepart[c],heurededepart1) ;
strcpy(datealler[c],datealler1) ;
strcpy(dateretour[c],dateretour1) ;
c++ ;
} 
}
}
fclose(f); 
return c ; 

 
}


int verifierpays (hyberg h) 
{
char pays1[50] ;
char hotel1[50]; 
char prix1[50];  

int a=1,c=0 ; 
int i ;

FILE *f ; 
f=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s \n",pays1,hotel1,prix1)!=EOF)
{
a=strcmp(h.pays,pays1) ; 
  

if (a==0) 
{
strcpy(h.hotel[c],hotel1) ;
c++ ;
} 
}
}
fclose(f); 
return c ; 

 
}

void ajoutervol (char depart[] ,char destination[], char heurededepart[] ,char compagnie[],char datealler[], char dateretour[],char prix[]) 
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %s %s \n",depart,destination,heurededepart,compagnie,datealler,dateretour,prix);
fclose(f);
}
}

enum 
{
DEPART, 
DESTINATION, 
COMPAGNIE, 
HEUREDEDEPART, 
DATEALLER,
DATERETOUR,
PRIX,
COLUMNS
}; 


void affichervol (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char depart[30] ;
char destination[30] ;
char compagnie[30];
char heure[30];
char da[30];
char dr[30] ;
char prix[50] ;  


store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Depart",render,"text",DEPART,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Destination",render,"text",DESTINATION,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Heure",render,"text",HEUREDEDEPART,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Compagnie",render,"text",COMPAGNIE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Date d'aller",render,"text",DATEALLER,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Date de retour",render,"text",DATERETOUR,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","a+") ;
 while(fscanf(f," %s %s %s %s %s %s %s \n" ,depart,destination,heure,compagnie,da,dr,prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,DEPART,depart,DESTINATION,destination,HEUREDEDEPART,heure,COMPAGNIE,compagnie,DATEALLER,da,DATERETOUR,dr,PRIX,prix,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}

void ajouterhybergement (hyber h)
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %s \n",h.pays,h.hotel,h.prix);
fclose(f);
}
}

enum 
{
PAYS, 
HOTEL,
PRIX0,
COLUMNS0

}; 


void afficherhybergement (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

hyber h ; 


store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Pays",render,"text",PAYS,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Hotel",render,"text",HOTEL,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX0,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


store=gtk_list_store_new(COLUMNS0,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","a+") ;
 while(fscanf(f," %s %s %s \n" ,h.pays,h.hotel,h.prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,PAYS,h.pays,HOTEL,h.hotel,PRIX0,h.prix,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}


void ajouterlocation (loc l)
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/locdispo.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s \n",l.marque,l.prix);
fclose(f);
}
}




enum 
{
MARQUE,
PRIX2,
COLUMNS2,

}; 

void afficherlocation (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

loc l ; 


store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Marque",render,"text",MARQUE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX2,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 





store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/locdispo.txt","r") ; 
if (f==NULL) 
{

return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/locdispo.txt","a+") ;
 while(fscanf(f," %s %s \n" ,l.marque,l.prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,MARQUE,l.marque,PRIX2,l.prix,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}


int departdestdispo (char depart[][30] ,char destination[][30]) 
{
FILE *f ;
int n=0; 
char depart1[30] ;
char destination1[30] ;
char heurededepart1[30] ;
char compagnie1[30] ;
char datealler1[30] ;
char dateretour1[30];
char prix[50]; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","r");
if(f!=NULL)
{

while(fscanf(f,"%s %s %s %s %s %s %s \n",depart1,destination1,heurededepart1,compagnie1,datealler1,dateretour1,prix)!=EOF)
{ 
 
    
        strcpy(depart[n],depart1) ; 
        strcpy(destination[n],destination1) ;
        n++ ; 
    
}
}
fclose(f) ; 
return n ; 

}

int affichermarque (char marque[][50]) 
{
char marque1[50]; 
char prix1[50];  

int i ;  
int c=0 ; 

FILE *f ; 
f=fopen("/home/ggmghoul/Desktop/agency-master/src/locdispo.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s \n",marque1,prix1)!=EOF)
{

strcpy(marque[c],marque1) ;
c++ ;
} 
}
fclose(f); 
return c ; 
}


int paysdispo (char pays[][50]) 
{
FILE *f ;
int n=0; 
hyber h ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","r");
if(f!=NULL)
{

while(fscanf(f,"%s %s %s \n",h.pays,h.hotel,h.prix)!=EOF)
{ 
 
    
        strcpy(pays[n],h.pays) ; 
        
        n++ ; 
    
}
}
fclose(f) ; 
return n ; 

}

/*-----------------------------------------------------------modifiesupprvol---------------------------------------*/


void supprimervol(char depart[],char destination[] ,char compagnie[])
{
FILE *f;
FILE *f1;
vollemp ev ;
int r;
int n;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo1.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s \n",ev.depart,ev.destination,ev.heure,ev.compagnie,ev.datealler,ev.dateretour,ev.prix)!=EOF ) {
    if((strcmp(depart,ev.depart)!=0) && (strcmp(destination,ev.destination)!=0) && (strcmp(compagnie,ev.compagnie)!=0))  
    {
        fprintf(f1,"%s %s %s %s %s %s %s \n",ev.depart,ev.destination,ev.heure,ev.compagnie,ev.datealler,ev.dateretour,ev.prix);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	remove ("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/voldispo1.txt","/home/ggmghoul/Desktop/agency-master/src/voldispo.txt");
	}

}

void modifiervol (char depart[],char destination[] ,char compagnie[] ,char newdate[] ,char newdater[] ,char newprix[])
{
int n=0;
vollemp ev ;  




FILE *f;
FILE *f1;
 
int r;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo1.txt","w");
if (f!=NULL)
{
    if(f1!=NULL)
     {
while(fscanf(f,"%s %s %s %s %s %s %s \n",ev.depart,ev.destination,ev.heure,ev.compagnie,ev.datealler,ev.dateretour,ev.prix)!=EOF ) 
{
    if((strcmp(depart,ev.depart)==0) && (strcmp(destination,ev.destination)==0) && (strcmp(compagnie,ev.compagnie)==0))  
            {
        fprintf(f1,"%s %s %s %s %s %s %s \n",ev.depart,ev.destination,ev.heure,ev.compagnie,newdate,newdater,newprix);
            }
     else 
          {fprintf(f1,"%s %s %s %s %s %s %s \n",ev.depart,ev.destination,ev.heure,ev.compagnie,ev.datealler,ev.dateretour,ev.prix);} 
}
}
}
fclose(f1);
fclose(f);

	remove ("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/voldispo1.txt","/home/ggmghoul/Desktop/agency-master/src/voldispo.txt");
	
}

/*---------------------------------------modifiersupphyber-------------------------------------------*/


void supprimerhyber(char hotel[])
{
FILE *f;
FILE *f1;
hyber h ; 
int r;
int n;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo1.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %s %s \n",h.pays,h.hotel,h.prix)!=EOF ) {
    if(strcmp(hotel,h.hotel)!=0)  
    {
        fprintf(f1,"%s %s %s \n",h.pays,h.hotel,h.prix);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	remove ("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/hyberdispo1.txt","/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt");
	}

}

void modifierhyber (char hotel[] ,char newprix[])
{
int n=0;
hyber h ;  




FILE *f;
FILE *f1;
 
int r;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo1.txt","w");
if (f!=NULL)
{
    if(f1!=NULL)
     {
while(fscanf(f,"%s %s %s \n",h.pays,h.hotel,h.prix)!=EOF ) 
{
    if(strcmp(hotel,h.hotel)==0)  
            {
        fprintf(f1,"%s %s %s \n",h.pays,h.hotel,newprix);
            }
     else 
          {fprintf(f1,"%s %s %s \n",h.pays,h.hotel,h.prix);} 
}
}
}
fclose(f1);
fclose(f);

	remove ("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/hyberdispo1.txt","/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt");
	
}

/*----------------------------------------------modifiersupploc-----------------------------------------*/

void supprimerloc(char marque[])
{
FILE *f;
FILE *f1;
loc l ;
int r;
int n;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/locdispo.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/locdispo1.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %s \n",l.marque,l.prix)!=EOF ) {
    if (strcmp(marque,l.marque)!=0)
    {
        fprintf(f1,"%s %s \n",l.marque,l.prix);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	remove ("/home/ggmghoul/Desktop/agency-master/src/locdispo.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/locdispo1.txt","/home/ggmghoul/Desktop/agency-master/src/locdispo.txt");
	}

}

void modifierloc (char marque[] ,char newprix[])
{
int n=0;
loc l ; 




FILE *f;
FILE *f1;
 
int r;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/locdispo.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/locdispo1.txt","w");
if (f!=NULL)
{
    if(f1!=NULL)
     {
while(fscanf(f,"%s %s \n",l.marque,l.prix)!=EOF ) 
{
    if (strcmp(marque,l.marque)==0)   
            {
        fprintf(f1,"%s %s \n",l.marque,newprix);
            }
     else 
          {fprintf(f1,"%s %s \n",l.marque,l.prix);} 
}
}
}
fclose(f1);
fclose(f);

	remove ("/home/ggmghoul/Desktop/agency-master/src/locdispo.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/locdispo1.txt","/home/ggmghoul/Desktop/agency-master/src/locdispo.txt");
	
}




/*--------------------------------------------------reservvol--------------------------------------------------------*/



void reservervol(volclient cv) 
{
int prixx ;
FILE *f;
FILE *f1 ;
vollemp ev ; 
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","r"); 
f=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationvol.txt","a");

if(f1!=NULL)
   {  if (f!=NULL) 
         {
          while(fscanf(f1,"%s %s %s %s %s %s %d \n",ev.depart,ev.destination,ev.heure,ev.compagnie,ev.datealler,ev.dateretour,&prixx)!=EOF )
           {
             if((strcmp(cv.depart,ev.depart)==0) && (strcmp(cv.destination,ev.destination)==0) && (strcmp(cv.compagnie,ev.compagnie)==0))
               {
                cv.prix=(prixx*cv.adulte)+((prixx-((prixx*30)*100))*cv.enf)+((prixx/2)*cv.bb) ;
                     if (strcmp(cv.ar,"aller/retour")==0) cv.prix*=1.5 ; 
                     if (strcmp(cv.classe,"FirstClass")==0) cv.prix*=2 ;  
               } 
           }
         
       fprintf(f,"%s %s %s %s %s %s %s %s %s %d %d %d %d \n",cv.cin,cv.depart,cv.destination,cv.heure,cv.compagnie,cv.ar,cv.datealler,cv.dateretour,cv.classe,cv.adulte,cv.enf,cv.bb,cv.prix);
         }
      fclose(f);
    }
   fclose(f1) ;
}


/*-------------------------------reservhyber---------------------------------------*/

void reserverhyber(hyberclient hc) 
{
int prixx ;
FILE *f;
FILE *f1 ;
hyber h ;  
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","r"); 
f=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationhyber.txt","a");

if(f1!=NULL)
   {  if (f!=NULL) 
         {
          while(fscanf(f1,"%s %s %d \n",h.pays,h.hotel,&prixx)!=EOF )
           {
             if((strcmp(hc.pays,h.pays)==0) && (strcmp(hc.hotel,h.hotel)==0))
               {
                hc.prix=(prixx*hc.jd)*hc.nbp ;  
               } 
           }
         
       fprintf(f,"%s %s %s %d %d %s %d \n",hc.cin,hc.pays,hc.hotel,hc.jd,hc.nbp,hc.fnf,hc.prix);
         }
      fclose(f);
    }
   fclose(f1) ;
}

/*-------------------------------reservlocation-----------------------------------------------------*/


void reserverlocation(locationclient lc) 
{
int prixx ;
FILE *f;
FILE *f1 ;
loc l ;  
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/locdispo.txt","r"); 
f=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationlocation.txt","a");

if(f1!=NULL)
   {  if (f!=NULL) 
         {
          while(fscanf(f1,"%s %d \n",l.marque,&prixx)!=EOF )
           {
             if (strcmp(lc.marque,l.marque)==0)
               {
                lc.prix=prixx*lc.nbj ;  
               } 
           }
         
       fprintf(f,"%s %s %d %d \n",lc.cin,lc.marque,lc.nbj,lc.prix);
         }
      fclose(f);
    }
   fclose(f1) ;
}


/*---------------------------------------------afficherreservationtotale----------------------------------------------*/
enum 
{
CIN,
VOSRESERVATION,
PRIX1,
COLUMNS1
}; 

void afficherreservation (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char cin[50]; 
char reserv[50]; 
char prix[50]; 

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Cin",render,"text",CIN,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Reservation",render,"text",VOSRESERVATION,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX1,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 




store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationtotale.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationtotale.txt","a+") ;
 while(fscanf(f,"%s %s %s \n" ,cin,reserv,prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,CIN,cin,VOSRESERVATION,reserv,PRIX1,prix,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}


/*-------------------reservtotale---------------------------------------------*/


void reservtotal(char cin[]) 
{
FILE *f ;
FILE *f1 ;
FILE *f2 ;
FILE *f3 ;


volclient cv ; 
hyberclient hc ; 
locationclient lc ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationvol.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationhyber.txt","r");
f2=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationlocation.txt","r");
f3=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationtotale.txt","a+");
    if (f!=NULL) 
       {
          if (f1!=NULL) 
             {  
                  if(f2!=NULL) 
                        { 
                            if (f3!=NULL) 
                                  {
           while(fscanf(f,"%s %s %s %s %s %s %s %s %s %d %d %d %d \n",cv.cin,cv.depart,cv.destination,cv.heure,cv.compagnie,cv.ar,cv.datealler,cv.dateretour,cv.classe,&cv.adulte,&cv.enf,&cv.bb,&cv.prix)!=EOF )
                { 
                 if (strcmp(cin,cv.cin)==0) 
             fprintf(f3,"%s %s %d \n",cv.cin,cv.destination,cv.prix) ;  
                }
while(fscanf(f1,"%s %s %s %d %d %s %d \n",hc.cin,hc.pays,hc.hotel,&hc.jd,&hc.nbp,hc.fnf,&hc.prix)!=EOF )
                { 
                 if (strcmp(cin,hc.cin)==0) 
             fprintf(f3,"%s %s %d \n",hc.cin,hc.hotel,hc.prix) ;  
                }
while(fscanf(f2,"%s %s %d %d \n",lc.cin,lc.marque,&lc.nbj,&lc.prix)!=EOF )
                { 
                 if (strcmp(cin,lc.cin)==0) 
             fprintf(f3,"%s %s %d \n",lc.cin,lc.marque,lc.prix) ;  
                }

                                 }fclose(f3) ; 
                        }fclose(f2) ; 
            }fclose(f1) ; 
        }fclose(f) ; 

}


/*------------------------------------------------reservdata---------------------------------------------*/


void stockage() 
{

FILE *f ;
FILE *f1 ; 

char reserv[50]; 
char prix[50]; 
char cin[50]; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationtotale.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationdata.txt","a+");

   if (f!=NULL) 
      { 
         if (f1!=NULL) 
              { 
             while(fscanf(f,"%s %s %s \n",cin,reserv,prix)!=EOF )
           {
          fprintf(f1,"%s %s %s \n",cin,reserv,prix) ; 
           }
              }fclose(f1); 
      }fclose(f) ;


}


/*------------------------------------effacement-----------------------------------------*/

void effacer() 
{
remove ("/home/ggmghoul/Desktop/agency-master/src/reservationtotale.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/reservationtotale1.txt","/home/ggmghoul/Desktop/agency-master/src/reservationtotale.txt");

}




/*-------------------------------------------message---------------------------------------------------*/

void messgae(char cin[] ,char message[]) 
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/message.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s \n",cin,message);
fclose(f);
}
}


/*-----------------------------------affichermessgae----------------------------------------------------------*/



enum 
{
CIN0 , 
MESSAGE0 , 
COLUMNS00 
};
void affichermessage (GtkTreeView *liste) 
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char cin[50]; 
char message[3000];
 

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Cin",render,"text",CIN0,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Message",render,"text",MESSAGE0,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 







store=gtk_list_store_new(COLUMNS00,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/message.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/message.txt","a+") ;
 while(fscanf(f,"%s %[^\n]s \n",cin,message)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,CIN0,cin,MESSAGE0,message,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}


/*----------------------------supprimermsg--------------------------------------------*/

void suppmsg(char cin[])
{
FILE *f;
FILE *f1;
char cin0[50]; 
char message0[3000]; 

int r;
int n;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/message.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/message1.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %[^\n]s \n",cin0,message0)!=EOF ) {
    if(strcmp(cin,cin0)!=0)  
    {
        fprintf(f1,"%s %s \n",cin0,message0);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	remove ("/home/ggmghoul/Desktop/agency-master/src/message.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/message1.txt","/home/ggmghoul/Desktop/agency-master/src/message.txt");
	}

}




/*----------------------envoyerrec---------------------------------------------------------------------*/

void reclamer(char cin[] ,char message[] ,char type[],int j ,int m , int y ) 
{
FILE *f;

char etat[50]="NonTraitée" ;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/reclamation.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %d/%d/%d %s %s \n",cin,type,j,m,y,etat,message);
fclose(f);
}
}


/*---------------------------afficherrec-------------------------------------------------*/



enum 
{
CIN1 , 
MESSAGE1 , 
TYPE1,
DATE1,
ETAT1,
COLUMNS111 
};
void afficherrec (GtkTreeView *liste) 
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char cin[50]; 
char message[3000];
char type[50]; 
char date[50]; 
char etat[50]; 

 

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Cin",render,"text",CIN1,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Reclamation",render,"text",MESSAGE1,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Type",render,"text",TYPE1,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Date",render,"text",DATE1,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Etat",render,"text",ETAT1,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 









store=gtk_list_store_new(COLUMNS111,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/reclamation.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/reclamation.txt","a+") ;
 while(fscanf(f,"%s %s %s %s %[^\n]s \n",cin,type,date,etat,message)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,CIN1,cin,MESSAGE1,message,TYPE1,type,DATE1,date,ETAT1,etat,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}


/*---------------------------------------------Modifieretat---------------------------------*/


void modifieretat(char cin1[])
{
FILE *f;
FILE *f1;
 
int r;
char etat1[50]="Traitée";
char cin[50]; 
char message[3000];
char type[50]; 
char date[50]; 
char etat[50]; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/reclamation.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/reclamation1.txt","w");
if (f!=NULL)
{
    if(f1!=NULL)
     {
while(fscanf(f,"%s %s %s %s %[^\n]s \n",cin,type,date,etat,message)!=EOF ) 
{
    if(strcmp(cin1,cin)==0)  
            {
        fprintf(f1,"%s %s %s %s %s \n",cin,type,date,etat1,message);
            }
     else 
          {fprintf(f1,"%s %s %s %s %s \n",cin,type,date,etat,message);} 
}
}
}
fclose(f1);
fclose(f);

	remove ("/home/ggmghoul/Desktop/agency-master/src/reclamation.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/reclamation1.txt","/home/ggmghoul/Desktop/agency-master/src/reclamation.txt");
	
}

/*---------------------------------------------Supprimerrec---------------------------------*/

void supprimerrec(char cin1[])

{
FILE *f;
FILE *f1;

int r;
int n;

char cin[50]; 
char message[3000];
char type[50]; 
char date[50]; 
char etat[50]; 


f=fopen("/home/ggmghoul/Desktop/agency-master/src/reclamation.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/reclamation1.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %s %s %s %[^\n]s \n",cin,type,date,etat,message)!=EOF ) {
    if(strcmp(cin1,cin)!=0)  
    {
        fprintf(f1,"%s %s %s %s %s \n",cin,type,date,etat,message);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	remove ("/home/ggmghoul/Desktop/agency-master/src/reclamation.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/reclamation1.txt","/home/ggmghoul/Desktop/agency-master/src/reclamation.txt");
	}

}


/*--------------------------------afficherfact----------------------------------------------------*/ 

enum 
{
CIN33,
VOSRESERVATION2,
PRIX33,
COLUMNS33
}; 

void afficherfact (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char cin[50]; 
char reserv[50]; 
char prix[50]; 

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Cin",render,"text",CIN33,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Reservation",render,"text",VOSRESERVATION2,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX33,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 




store=gtk_list_store_new(COLUMNS33,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationdata.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationdata.txt","a+") ;
 while(fscanf(f,"%s %s %s \n" ,cin,reserv,prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,CIN33,cin,VOSRESERVATION2,reserv,PRIX33,prix,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}


/*---------------------------------suppfact----------------------------------------------------*/


void supprimerfact(char cin1[])

{
FILE *f;
FILE *f1;

int r;
int n;

char cin[50]; 
char reserv[50]; 
char prix[50]; 


f=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationdata.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/reservationdata1.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %s %s \n" ,cin,reserv,prix)!=EOF ) {
    if(strcmp(cin1,cin)!=0)  
    {
        fprintf(f1,"%s %s %s \n" ,cin,reserv,prix);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	remove ("/home/ggmghoul/Desktop/agency-master/src/reservationdata.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/reservationdata1.txt","/home/ggmghoul/Desktop/agency-master/src/reservationdata.txt");
	}

}


