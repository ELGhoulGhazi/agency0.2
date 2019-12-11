#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ajouter.h"
#include <gtk/gtk.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif





int inscri (client c) 
{
FILE *f;
FILE *f1 ; 
int role=3 ;
int v=0 ;
int b=0 ;
int s=0 ;
char user1[50] ; 
char pass1[50] ;
int role1 ;   
char empty[50]="\0" ;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/users.txt","a+");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/client.txt","a");

if(f!=NULL)
{
 if(f1!=NULL)
    {  
       while(fscanf(f,"%s %s %d \n",user1,pass1,&role1)!=EOF)
          {
               if (strcmp(c.user,user1)==0) 
                   {
                       v=1 ; 
                   }  
               if ( (strcmp(c.nom,empty)==0) || (strcmp(c.prenom,empty)==0) || (strcmp(c.cin,empty)==0) || (strcmp(c.user,empty)==0) || (strcmp(c.password,empty)==0) ) 
                   {
                      b=1 ;
                   }
          }

               if (v!=1 && b!=1)
                  {
                     s=0 ; 
                  } 
               if  (b==1) 
                  {
                    s=1 ;
                  }
              else if (v==1)
                  {
                    s=2 ;
                  }
 
                  if(s==0) 
                   {
                   fprintf(f,"%s %s %d \n",c.user,c.password,role);
                   fprintf(f1,"%s %s %s %s %s \n",c.nom,c.prenom,c.cin,c.user,c.password);
                   }
          
    }
fclose(f1);
}
fclose(f);
return s  ;

}






void ajouteremployer (emp e)
{
FILE *f;
int role=2 ;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/users.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %d \n",e.user,e.password,role);
fclose(f);
}
f=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %d/%d/%d %s %s \n",e.nom,e.prenom,e.j,e.m,e.y,e.user,e.password);
fclose(f);
}
}


enum 
{
NOM ,
PRENOM,
DATEDERECRUTEMENT,
USER, 
PASSWORD, 
COLUMNS11
}; 
void afficheremp (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char nom[30] ;
char prenom[30] ;
char user[30];
char password[30];  
char date[30]; 
store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("nom",render,"text",NOM,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("prenom",render,"text",PRENOM,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("date",render,"text",DATEDERECRUTEMENT,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("user",render,"text",USER,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("password",render,"text",PASSWORD,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


store=gtk_list_store_new(COLUMNS11,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt","a+") ;
 while(fscanf(f,"%s %s %s %s %s \n" ,nom,prenom,date,user,password)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,NOM,nom,PRENOM,prenom,DATEDERECRUTEMENT,date,USER,user,PASSWORD,password,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}


enum 
{
NOMC ,
PRENOMC,
CIN ,
USERC, 
PASSWORDC, 
COLUMNS10
}; 

void afficherclient (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

client c ;

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("nom",render,"text",NOMC,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("prenom",render,"text",PRENOMC,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("cin",render,"text",CIN,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("user",render,"text",USERC,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("password",render,"text",PASSWORDC,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

store=gtk_list_store_new(COLUMNS10,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/client.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/client.txt","a+") ;
 while(fscanf(f,"%s %s %s %s %s \n" ,c.nom,c.prenom,c.cin,c.user,c.password)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,NOMC,c.nom,PRENOMC,c.prenom,CIN,c.cin,USERC,c.user,PASSWORDC,c.password,-1) ; 
}
fclose(f) ;} 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}

void supprimeremployer(char name[])
{
FILE *f;
FILE *f1;
empl e ; 
int r;
int n;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo1.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %s %s %s %s \n" ,e.nom,e.prenom,e.date,e.user,e.password)!=EOF ) {
    if(strcmp(name,e.nom)!=0){
        fprintf(f1,"%s %s %s %s %s \n" ,e.nom,e.prenom,e.date,e.user,e.password);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	remove ("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/empinfo1.txt","/home/ggmghoul/Desktop/agency-master/src/empinfo.txt");
	}

}

void modifieremployer (char name[],char newuser[] ,char newpass[])
{
int n=0;
empl e ;




FILE *f;
FILE *f1;
 
int r;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo1.txt","w");
if (f!=NULL)
{
    if(f1!=NULL)
     {
while(fscanf(f,"%s %s %s %s %s \n" ,e.nom,e.prenom,e.date,e.user,e.password)!=EOF ) 
{
    if(strcmp(name,e.nom)==0)
            {
        fprintf(f1,"%s %s %s %s %s \n" ,e.nom,e.prenom,e.date,newuser,newpass);
            }
     else 
          {fprintf(f1,"%s %s %s %s %s \n" ,e.nom,e.prenom,e.date,e.user,e.password);} 
}
}
}
fclose(f1);
fclose(f);

	remove ("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/empinfo1.txt","/home/ggmghoul/Desktop/agency-master/src/empinfo.txt");
	


}

void supprimerclient(char cin[])
{
FILE *f;
FILE *f1;
client c ; 
int r;
int n;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/client.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/client0.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %s %s %s %s \n" ,c.nom,c.prenom,c.cin,c.user,c.password)!=EOF ) {
    if(strcmp(cin,c.cin)!=0){
        fprintf(f1,"%s %s %s %s %s \n" ,c.nom,c.prenom,c.cin,c.user,c.password);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	remove ("/home/ggmghoul/Desktop/agency-master/src/client.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/client0.txt","/home/ggmghoul/Desktop/agency-master/src/client.txt");
	}

}

void modifierclient (char cin[],char newuser[] ,char newpass[])
{
int n=0;
client c ; 




FILE *f;
FILE *f1;
 
int r;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/client.txt","r");
f1=fopen("/home/ggmghoul/Desktop/agency-master/src/client0.txt","w");
if (f!=NULL)
{
    if(f1!=NULL)
     {
while(fscanf(f,"%s %s %s %s %s \n" ,c.nom,c.prenom,c.cin,c.user,c.password)!=EOF ) 
{
    if(strcmp(cin,c.cin)==0)
            {
        fprintf(f1,"%s %s %s %s %s \n" ,c.nom,c.prenom,c.cin,newuser,newpass);
            }
     else 
          {fprintf(f1,"%s %s %s %s %s \n" ,c.nom,c.prenom,c.cin,c.user,c.password);} 
}
}
}
fclose(f1);
fclose(f);

	remove ("/home/ggmghoul/Desktop/agency-master/src/client.txt");
	rename ("/home/ggmghoul/Desktop/agency-master/src/client0.txt","/home/ggmghoul/Desktop/agency-master/src/client.txt");
	
}










