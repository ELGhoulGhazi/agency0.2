#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>

#include <stdio.h> 
#include<string.h>
#include<stdlib.h>

#include <gtk/gtkclist.h>
//#include <gtk/gdkkeysyms.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "ajouter.h"
#include "reservation.h"


 
void
on_ggbuttonVisiteur_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Home ,*Visiteur ;

Home=lookup_widget(objet_graphique,"Home");
Visiteur=create_ModeVisiteur();
gtk_widget_show(Visiteur);
gtk_widget_hide(Home);
}


 
void
on_buttonConnect_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data) 
{
GtkWidget *Home ,*Visiteur ;

Visiteur=lookup_widget(objet_graphique,"ModeVisiteur");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(Visiteur);
}


void
on_buttonInscriV_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *inscription ,*Visiteur ;

Visiteur=lookup_widget(objet_graphique,"ModeVisiteur");
inscription=create_Inscription();
gtk_widget_show(inscription);
gtk_widget_hide(Visiteur);
}


 

void
on_buttonAGC_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Admin ,*GClients,*treeview ;

Admin=lookup_widget(objet_graphique,"ModeAdmin");
GClients=create_GestionAClient(); 
gtk_widget_show(GClients);
gtk_widget_hide(Admin);

treeview=lookup_widget(GClients,"treeviewAclient");
afficherclient(treeview) ; 

}



void
on_buttonAGE_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Admin ,*GEmp,*treeview ; 

Admin=lookup_widget(objet_graphique,"ModeAdmin");
GEmp=create_GestionAEmployes(); 
gtk_widget_show(GEmp);
gtk_widget_hide(Admin); 

treeview=lookup_widget(GEmp,"treeviewemp");
afficheremp(treeview) ; 
}


void
on_ggbuttonLogin_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f;
int role;
int c ; 
cverif v ; 

GtkWidget *Home ,*Admin ,*Employe ,*Client ; 

GtkWidget *input,*input1,*output; 

input=lookup_widget(objet_graphique,"ggenetryUser");
input1=lookup_widget(objet_graphique,"ggentryPass");
Home=lookup_widget(objet_graphique,"Home");

strcpy(v.user,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(v.password,gtk_entry_get_text(GTK_ENTRY(input1)));
output=lookup_widget(objet_graphique,"labelwrong");
c=verifier(v);

if (c==1)
{Admin=create_ModeAdmin();
gtk_widget_show(Admin);
gtk_widget_hide(Home);
}

else if (c==2)
{Employe=create_ModeEmploye();
gtk_widget_show(Employe);
gtk_widget_hide(Home);
}

else if (c==3)
{Client=create_ModeClient();
gtk_widget_show(Client);
gtk_widget_hide(Home);
}
else 
{
gtk_label_set_text(GTK_LABEL(output)," Unable to Connect ! ");
}
/*GtkWidget *Home ,*Visiteur ;

Home=lookup_widget(objet_graphique,"Home");
Visiteur=create_ModeVisiteur(); 
gtk_widget_show(Visiteur);
gtk_widget_hide(Home);*/
}





void
on_ggbuttonIinscription_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*inscription; 

Home=lookup_widget(objet_graphique,"Home");
inscription=create_Inscription();
gtk_widget_show(inscription);
gtk_widget_hide(Home);
}




void
on_buttonDecoA_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Admin;

Admin=lookup_widget(objet_graphique,"ModeAdmin");
Home=create_Home();
gtk_widget_show(Home);
gtk_widget_hide(Admin);
}




void
on_buttoninscriconnect_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*inscription;

inscription=lookup_widget(objet_graphique,"Inscription");
Home=create_Home();
gtk_widget_show(Home);
gtk_widget_hide(inscription);
}



void
on_buttonACretour_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GestionClient ,*Admin;

GestionClient=lookup_widget(objet_graphique,"GestionAClient");
Admin=create_ModeAdmin();
gtk_widget_show(Admin);
gtk_widget_hide(GestionClient);


}


void
on_buttonEAretour_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GestionEmp ,*Admin;

GestionEmp=lookup_widget(objet_graphique,"GestionAEmployes");
Admin=create_ModeAdmin();
gtk_widget_show(Admin);
gtk_widget_hide(GestionEmp);
}

  
void
on_buttonValiderinscri_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Home ,*inscription ;

FILE *f;

client c ; 

GtkWidget *inputuser,*inputpass ,*inputnom ,*inputprenom ,*inputcin ,*label; 

int n=0 ;  

label=lookup_widget(objet_graphique,"utiliser");


inputnom=lookup_widget(objet_graphique,"entryinscrinom"); 
inputprenom=lookup_widget(objet_graphique,"entryinscriprenom");
inputcin=lookup_widget(objet_graphique,"entryinscricin"); 
inputuser=lookup_widget(objet_graphique,"entryinscriptionuser");
inputpass=lookup_widget(objet_graphique,"entryinscriptionpass");
inscription=lookup_widget(objet_graphique,"Inscription");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(inputnom)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(inputprenom)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(inputcin)));
strcpy(c.user,gtk_entry_get_text(GTK_ENTRY(inputuser)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(inputpass)));

n=inscri(c);

switch (n) 
{
case 0 : 
inscription=lookup_widget(objet_graphique,"Inscription");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(inscription); break ; 
case 1 : gtk_label_set_text(GTK_LABEL(label)," Il faut remplir tout les champs ! "); break ; 
case 2 : gtk_label_set_text(GTK_LABEL(label)," Ce nom d'utilisateur est déjà utilisé ! ");break ; 
}

}


void
on_buttonEGC_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GestionClient ,*Emp ,*treeview;

Emp=lookup_widget(objet_graphique,"ModeEmploye");
GestionClient=create_GestionEClient();
gtk_widget_show(GestionClient);
gtk_widget_hide(Emp);

treeview=lookup_widget(GestionClient,"treeviewEclient");
afficherclient(treeview) ; 
}


void
on_buttonEPrestations_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Pres ,*Emp;

Emp=lookup_widget(objet_graphique,"ModeEmploye");
Pres=create_Prestations();
gtk_widget_show(Pres);
gtk_widget_hide(Emp);
}


void
on_buttonEGFactures_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Fact ,*Emp;

Emp=lookup_widget(objet_graphique,"ModeEmploye");
Fact=create_Factures();
gtk_widget_show(Fact);
gtk_widget_hide(Emp);
}




void
on_buttonretourCE_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GestionClient ,*Emp;

GestionClient=lookup_widget(objet_graphique,"GestionEClient");
Emp=create_ModeEmploye();
gtk_widget_show(Emp);
gtk_widget_hide(GestionClient);
}


void
on_buttonretourPE_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Pres ,*Emp;

Pres=lookup_widget(objet_graphique,"Prestations");
Emp=create_ModeEmploye();
gtk_widget_show(Emp);
gtk_widget_hide(Pres);
}


void
on_buttonretourFE_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Fact ,*Emp;

Fact=lookup_widget(objet_graphique,"Factures");
Emp=create_ModeEmploye();
gtk_widget_show(Emp);
gtk_widget_hide(Fact);
}

void
on_buttonDecoEmp_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Emp;

Emp=lookup_widget(objet_graphique,"ModeEmploye");
Home=create_Home();
gtk_widget_show(Home);
gtk_widget_hide(Emp);
}


void
on_buttondecoclient_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Client;

Client=lookup_widget(objet_graphique,"ModeClient");
Home=create_Home();
gtk_widget_show(Home);
gtk_widget_hide(Client);
}


void
on_buttonAEMajouter_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutemp ,*Gemp;

Gemp=lookup_widget(objet_graphique,"GestionAEmployes");
ajoutemp=create_ajouteremp();
gtk_widget_show(ajoutemp);
gtk_widget_hide(Gemp);

}


void
on_buttonretourajoutadmin_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutemp ,*Gemp,*treeview;

ajoutemp=lookup_widget(objet_graphique,"ajouteremp");
Gemp=create_GestionAEmployes();
gtk_widget_show(Gemp);
gtk_widget_hide(ajoutemp);


treeview=lookup_widget(Gemp,"treeviewemp");
afficheremp(treeview) ; 


}


void
on_buttonvaliderajouteremploye_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutemp ,*Gemp;

FILE *f;

emp e ; 

GtkWidget *inputuser,*inputpass ,*inputnom ,*inputprenom ,*inputj,*inputm,*inputy ,*treeview ;  


inputnom=lookup_widget(objet_graphique,"entrynomemp"); 
inputprenom=lookup_widget(objet_graphique,"entryprenomemp");
inputj=lookup_widget(objet_graphique,"jour"); 
inputm=lookup_widget(objet_graphique,"mois"); 
inputy=lookup_widget(objet_graphique,"years"); 
inputuser=lookup_widget(objet_graphique,"entryuseremp");
inputpass=lookup_widget(objet_graphique,"entrypassemp");
ajoutemp=lookup_widget(objet_graphique,"ajouteremp");


strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(inputnom)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(inputprenom)));
e.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputj));
e.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputm));
e.y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputy));

strcpy(e.user,gtk_entry_get_text(GTK_ENTRY(inputuser)));
strcpy(e.password,gtk_entry_get_text(GTK_ENTRY(inputpass)));

ajouteremployer(e);


Gemp=create_GestionAEmployes();
gtk_widget_show(Gemp);
gtk_widget_hide(ajoutemp);

treeview=lookup_widget(Gemp,"treeviewemp");
afficheremp(treeview) ; 
}


void
on_buttonCVols_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


GtkWidget *vol ,*Client;

Client=lookup_widget(objet_graphique,"ModeClient");
vol=create_Vols();
gtk_widget_show(vol);
gtk_widget_hide(Client);

}


void
on_buttonCLocation_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

 

GtkWidget *loc ,*Client ;

Client=lookup_widget(objet_graphique,"ModeClient");
loc=create_Location();
gtk_widget_show(loc);
gtk_widget_hide(Client);



}


void
on_buttonCHyber_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyber ,*Client;

Client=lookup_widget(objet_graphique,"ModeClient");
hyber=create_Hybergement();
gtk_widget_show(hyber);
gtk_widget_hide(Client);
}

void
on_buttonretourVC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vol ,*Client;

vol=lookup_widget(objet_graphique,"Vols");
Client=create_ModeClient();
gtk_widget_show(Client);
gtk_widget_hide(vol);
}




void
on_buttonretourHC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyber ,*Client;

hyber=lookup_widget(objet_graphique,"Hybergement");
Client=create_ModeClient();
gtk_widget_show(Client);
gtk_widget_hide(hyber);
}


void
on_buttonretourLC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *loc ,*Client;

loc=lookup_widget(objet_graphique,"Location");
Client=create_ModeClient();
gtk_widget_show(Client);
gtk_widget_hide(loc);
}


void
on_buttonEvols_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *evol ,*pres ,*treeview;

pres=lookup_widget(objet_graphique,"Prestations");
evol=create_VolsE();
gtk_widget_show(evol);
gtk_widget_hide(pres);

treeview=lookup_widget(evol,"treeviewvol");
affichervol(treeview) ; 



}


void
on_buttonELocation_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eloc ,*pres,*treeview;

pres=lookup_widget(objet_graphique,"Prestations");
eloc=create_LocationE();
gtk_widget_show(eloc);
gtk_widget_hide(pres);

treeview=lookup_widget(eloc,"treeviewlocation");
afficherlocation(treeview) ; 
}


void
on_buttonEHyber_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ehyber , *pres, *treeview;

pres=lookup_widget(objet_graphique,"Prestations");
ehyber=create_HybergementE();
gtk_widget_show(ehyber);
gtk_widget_hide(pres);

treeview=lookup_widget(ehyber,"treeviewhyber");
afficherhybergement(treeview) ; 

}


void
on_buttonretourVP_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *evol ,*pres;

evol=lookup_widget(objet_graphique,"VolsE");
pres=create_Prestations();
gtk_widget_show(pres);
gtk_widget_hide(evol);

}


void
on_buttonretourHP_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ehyber ,*pres;

ehyber=lookup_widget(objet_graphique,"HybergementE");
pres=create_Prestations();
gtk_widget_show(pres);
gtk_widget_hide(ehyber);

}


void
on_buttonretourLP_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eloc ,*pres;

eloc=lookup_widget(objet_graphique,"LocationE");
pres=create_Prestations();
gtk_widget_show(pres);
gtk_widget_hide(eloc);

}


void
on_buttonmsgA_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *message ,*admin ,*treeview;

admin=lookup_widget(objet_graphique,"ModeAdmin");
message=create_message();
gtk_widget_show(message);
gtk_widget_hide(admin);

treeview=lookup_widget(message,"treeviewmessageadmin");
affichermessage(treeview) ; 
}


void
on_buttonrecA_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*admin ,*treeview;

admin=lookup_widget(objet_graphique,"ModeAdmin");
rec=create_reclamation();
gtk_widget_show(rec);
gtk_widget_hide(admin);

treeview=lookup_widget(rec,"treeviewrecadmin");
afficherrec(treeview) ; 
}


void
on_buttonmsgE_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *message ,*emp ,*treeview;

emp=lookup_widget(objet_graphique,"ModeEmploye");
message=create_messageE();
gtk_widget_show(message);
gtk_widget_hide(emp);

treeview=lookup_widget(message,"treeviewmessageemp");
affichermessage(treeview) ; 
}


void
on_buttonrecE_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*emp ,*treeview;

emp=lookup_widget(objet_graphique,"ModeEmploye");
rec=create_reclamationE();
gtk_widget_show(rec);
gtk_widget_hide(emp);

treeview=lookup_widget(rec,"treeviewreclamationemp");
afficherrec(treeview) ; 
}


void
on_buttonrecC_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*client;

client=lookup_widget(objet_graphique,"ModeClient");
rec=create_reclamer();
gtk_widget_show(rec);
gtk_widget_hide(client);
}


void
on_buttonmsgC_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *contact ,*client;

client=lookup_widget(objet_graphique,"ModeClient");
contact=create_contacter();
gtk_widget_show(contact);
gtk_widget_hide(client);
}


void
on_buttonretourmsg_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *message ,*admin;

message=lookup_widget(objet_graphique,"message");
admin=create_ModeAdmin();
gtk_widget_show(admin);
gtk_widget_hide(message);
}


void
on_buttonretourrec_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*admin;

rec=lookup_widget(objet_graphique,"reclamation");
admin=create_ModeAdmin();
gtk_widget_show(admin);
gtk_widget_hide(rec);

}


void
on_buttonretourCC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *contact ,*client;

contact=lookup_widget(objet_graphique,"contacter");
client=create_ModeClient();
gtk_widget_show(client);
gtk_widget_hide(contact);
}


void
on_buttonretourRC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*client;

rec=lookup_widget(objet_graphique,"reclamer");
client=create_ModeClient();
gtk_widget_show(client);
gtk_widget_hide(rec);

}


void
on_buttonretourME_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *message ,*emp;

message=lookup_widget(objet_graphique,"messageE");
emp=create_ModeEmploye();
gtk_widget_show(emp);
gtk_widget_hide(message);
}


void
on_buttonretourRE_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*emp;

rec=lookup_widget(objet_graphique,"reclamationE");
emp=create_ModeEmploye();
gtk_widget_show(emp);
gtk_widget_hide(rec);
}


void
on_buttonretourLV_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *locv ,*visiteur;

locv=lookup_widget(objet_graphique,"Locationvisiteur");
visiteur=create_ModeVisiteur();
gtk_widget_show(visiteur);
gtk_widget_hide(locv);

}


void
on_buttonconnecterVL_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*locv ;

locv=lookup_widget(objet_graphique,"Locationvisiteur");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(locv);
}


void
on_buttoninscriVL_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *inscri ,*locv ;

locv=lookup_widget(objet_graphique,"Locationvisiteur");
inscri=create_Inscription(); 
gtk_widget_show(inscri);
gtk_widget_hide(locv);

}


void
on_buttonhyberV_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyberv ,*visiteur, *treeview;

visiteur=lookup_widget(objet_graphique,"ModeVisiteur");
hyberv=create_Hybergementvisiteur();
gtk_widget_show(hyberv);
gtk_widget_hide(visiteur);

treeview=lookup_widget(hyberv,"treeviewhybervisiteur");
afficherhybergement(treeview) ; 
}


void
on_buttonlocationV_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *locv ,*visiteur ,*treeview;

visiteur=lookup_widget(objet_graphique,"ModeVisiteur");
locv=create_Locationvisiteur();
gtk_widget_show(locv);
gtk_widget_hide(visiteur);

treeview=lookup_widget(locv,"treeviewlocationvisiteur");
afficherlocation(treeview) ; 
}


void
on_buttonvolsV_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *volv ,*visiteur ,*treeview;

visiteur=lookup_widget(objet_graphique,"ModeVisiteur");
volv=create_Volsvisiteur();
gtk_widget_show(volv);
gtk_widget_hide(visiteur);


treeview=lookup_widget(volv,"treeviewvolvisiteur");
affichervol(treeview) ; 
}


void
on_buttonconnecterVV_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*volv ;

volv=lookup_widget(objet_graphique,"Volsvisiteur");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(volv);

}


void
on_buttoninscriVV_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *inscri ,*volv ;

volv=lookup_widget(objet_graphique,"Volsvisiteur");
inscri=create_Inscription(); 
gtk_widget_show(inscri);
gtk_widget_hide(volv);

}


void
on_buttonretourVV_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *volv ,*visiteur;

volv=lookup_widget(objet_graphique,"Volsvisiteur");
visiteur=create_ModeVisiteur();
gtk_widget_show(visiteur);
gtk_widget_hide(volv);
}


void
on_buttoninscriVH_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *inscri ,*hyberv ;

hyberv=lookup_widget(objet_graphique,"Hybergementvisiteur");
inscri=create_Inscription(); 
gtk_widget_show(inscri);
gtk_widget_hide(hyberv);

}


void
on_buttonconnecterVH_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*hyberv ;

hyberv=lookup_widget(objet_graphique,"Hybergementvisiteur");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(hyberv);

}


void
on_buttonretourHV_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyberv ,*visiteur;

hyberv=lookup_widget(objet_graphique,"Hybergementvisiteur");
visiteur=create_ModeVisiteur();
gtk_widget_show(visiteur);
gtk_widget_hide(hyberv);
}



void
on_buttonrecherchevol_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *comboboxdepart ,*comboboxdestination ,*combocompagnie , *comboheure ,*comboda ,*combodr; 
char depart[30] ;
char destination[30] ;
char compagnie[50][50] ;
char heure[50][50] ;
char da[50][50] ;
char dr[50][50] ; 
char prix[30]; 
int n,i; 
comboboxdepart=lookup_widget(objet_graphique,"comboboxentrydepart");
comboboxdestination=lookup_widget(objet_graphique,"comboboxentrydestination");
comboheure=lookup_widget(objet_graphique,"comboboxheuredepart");
combocompagnie=lookup_widget(objet_graphique,"comboboxcompagnie");
comboda=lookup_widget(objet_graphique,"comboboxdateA");
combodr=lookup_widget(objet_graphique,"comboboxdateR");

strcpy(depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxdepart)));
strcpy(destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxdestination)));

n=verifierdest(depart,destination,heure,compagnie,da,dr,prix);
 if (n!=0) 
  {
    for (i=0 ;i<n ;i++)
       {
         gtk_combo_box_append_text (GTK_COMBO_BOX (comboheure),_(heure[i]));
         gtk_combo_box_append_text (GTK_COMBO_BOX (combocompagnie),_(compagnie[i]));
         gtk_combo_box_append_text (GTK_COMBO_BOX (comboda),_(da[i]));
         gtk_combo_box_append_text (GTK_COMBO_BOX (combodr),_(dr[i]));
       }
  }

}


void
on_buttonajoutvol_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vole ,*ajoutvol ;

vole=lookup_widget(objet_graphique,"VolsE");
ajoutvol=create_ajoutervol(); 
gtk_widget_show(ajoutvol);
gtk_widget_hide(vole);
}


void
on_buttonvaliderajoutvol_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutvol ,*vole;

FILE *f;

char depart[30] ;
char destination[30];
char heurededepart[30] ;
char compagnie[30];
char datealler[30];
char dateretour[30];
char prix[30];

GtkWidget *inputdepart,*inputdesti ,*inputheure ,*inputddepart ,*inpudretour,*inputprix, *inputcomp ,*treeview;  


inputdepart=lookup_widget(objet_graphique,"entrydepart"); 
inputdesti=lookup_widget(objet_graphique,"entrydesti");
inputheure=lookup_widget(objet_graphique,"entryheure"); 
inputcomp=lookup_widget(objet_graphique,"entrycomp"); 
inputddepart=lookup_widget(objet_graphique,"entrydatealler"); 
inpudretour=lookup_widget(objet_graphique,"entrydateretour");
inputprix=lookup_widget(objet_graphique,"entryprix");

ajoutvol=lookup_widget(objet_graphique,"ajoutervol");


strcpy(depart,gtk_entry_get_text(GTK_ENTRY(inputdepart)));
strcpy(destination,gtk_entry_get_text(GTK_ENTRY(inputdesti)));
strcpy(heurededepart,gtk_entry_get_text(GTK_ENTRY(inputheure)));
strcpy(compagnie,gtk_entry_get_text(GTK_ENTRY(inputcomp)));
strcpy(datealler,gtk_entry_get_text(GTK_ENTRY(inputddepart)));
strcpy(dateretour,gtk_entry_get_text(GTK_ENTRY(inpudretour)));
strcpy(prix,gtk_entry_get_text(GTK_ENTRY(inputprix)));

ajoutervol(depart,destination,heurededepart,compagnie,datealler,dateretour,prix);


vole=create_VolsE();
gtk_widget_show(vole);
gtk_widget_hide(ajoutvol);

treeview=lookup_widget(vole,"treeviewvol");
affichervol(treeview) ; 

}



void
on_buttonretourajoutvolgvol_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vole ,*ajoutvol,*treeview ;

ajoutvol=lookup_widget(objet_graphique,"ajoutervol");
vole=create_VolsE(); 
gtk_widget_show(vole);
gtk_widget_hide(ajoutvol);

treeview=lookup_widget(vole,"treeviewvol");
affichervol(treeview) ; 
}


void
on_buttonajouthyber_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyber ,*ajouthyber ;

hyber=lookup_widget(objet_graphique,"HybergementE");
ajouthyber=create_ajouterhyber(); 
gtk_widget_show(ajouthyber);
gtk_widget_hide(hyber);
}




void
on_buttonajoutlocation_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *loc ,*ajoutloc ;

loc=lookup_widget(objet_graphique,"LocationE");
ajoutloc=create_ajouterloc(); 
gtk_widget_show(ajoutloc);
gtk_widget_hide(loc);
}




void
on_buttonretourajouthyberhyber_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyber ,*ajouthyber,*treeview ;

ajouthyber=lookup_widget(objet_graphique,"ajouterhyber");
hyber=create_HybergementE(); 
gtk_widget_show(hyber);
gtk_widget_hide(ajouthyber);

treeview=lookup_widget(hyber,"treeviewhyber");
afficherhybergement(treeview) ; 
}


void
on_buttonvaliderhyber_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouthyber ,*hyberg ,*treeview;

FILE *f;

hyber h ;

GtkWidget *inputpays,*inputhotel ,*inputprix ;  


inputpays=lookup_widget(objet_graphique,"comboboxentrypayshyber"); 
inputhotel=lookup_widget(objet_graphique,"entryajouthotel");
inputprix=lookup_widget(objet_graphique,"entryajoutprixhyber"); 

ajouthyber=lookup_widget(objet_graphique,"ajouterhyber");

strcpy(h.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(inputpays)));
strcpy(h.hotel,gtk_entry_get_text(GTK_ENTRY(inputhotel)));
strcpy(h.prix,gtk_entry_get_text(GTK_ENTRY(inputprix)));


ajouterhybergement(h);


hyberg=create_HybergementE();
gtk_widget_show(hyberg);
gtk_widget_hide(ajouthyber);

treeview=lookup_widget(hyberg,"treeviewhyber");
afficherhybergement(treeview) ; 

}


void
on_buttonretourajoutlocloc_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *loc ,*ajoutloc,*treeview ;

ajoutloc=lookup_widget(objet_graphique,"ajouterloc");
loc=create_LocationE(); 
gtk_widget_show(loc);
gtk_widget_hide(ajoutloc);

treeview=lookup_widget(loc,"treeviewlocation");
afficherlocation(treeview) ; 

}


void
on_buttonvaliderlocajout_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutloc ,*loca;

FILE *f;

loc l ; 

GtkWidget *inputmarq,*inputprix ,*treeview ;  


 
inputmarq=lookup_widget(objet_graphique,"entrymarque");
inputprix=lookup_widget(objet_graphique,"entryprixloc"); 

ajoutloc=lookup_widget(objet_graphique,"ajouterloc");

strcpy(l.marque,gtk_entry_get_text(GTK_ENTRY(inputmarq)));
strcpy(l.prix,gtk_entry_get_text(GTK_ENTRY(inputprix)));


ajouterlocation(l);


loca=create_LocationE();
gtk_widget_show(loca);
gtk_widget_hide(ajoutloc);

treeview=lookup_widget(loca,"treeviewlocation");
afficherlocation(treeview) ; 

}


void
on_buttonrecherchepays_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *inputpays , *boxhotel ; 

hyberg h ; 

int n,i; 
inputpays=lookup_widget(objet_graphique,"comboboxentryHyberpays");
boxhotel=lookup_widget(objet_graphique,"comboboxhotel");


strcpy(h.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(inputpays)));


n=verifierpays(h);
 if (n!=0) 
  {
    for (i=0 ;i<n ;i++)
       {
         gtk_combo_box_append_text (GTK_COMBO_BOX (boxhotel),_(h.hotel[i]));
         
       }
  }

}




void
on_buttonprixlocation_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


}


void
on_buttonrecherchemarque_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

int n=0 ,i ;
char marque[50][50];
GtkWidget *combomarque ;

combomarque=lookup_widget(objet_graphique,"comboboxmar");

n=affichermarque (marque) ;

if(n!=0) 
{
for(i=0 ;i<n ;i++) 
{
gtk_combo_box_append_text (GTK_COMBO_BOX (combomarque),_(marque[i])) ;
}
}

}


void
on_buttonvoldispo_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int i ,n ; 
char depart[30][30] ;
char destination[30][30]; 

GtkWidget *comboboxdepart,*comboboxdestination ; 


comboboxdepart=lookup_widget(objet_graphique,"comboboxentrydepart");
comboboxdestination=lookup_widget(objet_graphique,"comboboxentrydestination");


n=departdestdispo(depart,destination);  
for(i=0 ;i<n ;i++) 
{
gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxdepart),depart[i]) ;
gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxdestination),destination[i]) ;
}

}



void
on_buttonpaysdispo_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int i ,n ; 
char pays1[30][50] ;
 

GtkWidget *comboboxpays ;


comboboxpays=lookup_widget(objet_graphique,"comboboxentryHyberpays");


n=paysdispo(pays1);  
for(i=0 ;i<n ;i++) 
{
gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxpays),pays1[i]) ;

}

}


void
on_buttonvoirprixvol_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}

char cin1[200]; 
void
on_buttonACModifier_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gclient ,*modif ,*recherche;

recherche=lookup_widget(objet_graphique,"entryRechercherAC");

gclient=lookup_widget(objet_graphique,"GestionAClient");
modif=create_modifierclient();
gtk_widget_show(modif);
gtk_widget_hide(gclient);

strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(recherche)));
}


void
on_buttonACSupprimer_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char cin[2000];
GtkWidget *recherche ,*treeview ,*emp ,*clients;

recherche=lookup_widget(objet_graphique,"entryRechercherAC");

emp=lookup_widget(objet_graphique,"GestionAClient");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(recherche)));

supprimerclient(cin);

clients=create_GestionAClient() ;
gtk_widget_show(clients);
gtk_widget_hide(emp);


treeview=lookup_widget(clients,"treeviewAclient");
afficherclient(treeview) ; 


}

char name1[200];
void
on_buttonmodifieremp_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gemp ,*modif ,*recherche;

recherche=lookup_widget(objet_graphique,"entryrechercheemp");

gemp=lookup_widget(objet_graphique,"GestionAEmployes");
modif=create_modifieremp();
gtk_widget_show(modif);
gtk_widget_hide(gemp);

strcpy(name1,gtk_entry_get_text(GTK_ENTRY(recherche)));
}


void
on_buttonsuppemp_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char name[2000];
GtkWidget *recherche ,*treeview ,*emp ,*gemp ;

recherche=lookup_widget(objet_graphique,"entryrechercheemp");
emp=lookup_widget(objet_graphique,"GestionAEmployes");

strcpy(name,gtk_entry_get_text(GTK_ENTRY(recherche)));
supprimeremployer(name);

gemp=create_GestionAEmployes() ;
gtk_widget_show(gemp);
gtk_widget_hide(emp);

treeview=lookup_widget(gemp,"treeviewemp");
afficheremp(treeview) ; 


}


void
on_buttonretourclientgestion_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *modif ,*gclient ,*treeview ;

modif=lookup_widget(objet_graphique,"modifierclient");
gclient=create_GestionAClient();
gtk_widget_show(gclient);
gtk_widget_hide(modif);

treeview=lookup_widget(gclient,"treeviewAclient");
afficherclient(treeview) ;  
}


void
on_buttonvalidermclient_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
char user[50]; 
char pass[50];  
GtkWidget *inputuser , *inputpass ;
GtkWidget *modif ,*gclient,*treeview ;

modif=lookup_widget(objet_graphique,"modifierclient");
gclient=create_GestionAClient();
gtk_widget_show(gclient);
gtk_widget_hide(modif); 

inputuser=lookup_widget(objet_graphique,"entrynouveauuserclient"); 
inputpass=lookup_widget(objet_graphique,"entrynouveaupassclient"); 

strcpy(user,gtk_entry_get_text(GTK_ENTRY(inputuser)));
strcpy(pass,gtk_entry_get_text(GTK_ENTRY(inputpass)));
modifierclient (cin1,user,pass) ; 

treeview=lookup_widget(gclient,"treeviewAclient");
afficherclient(treeview) ; 
}


void
on_buttonvalideremp_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
char user[50]; 
char pass[50];  
GtkWidget *inputuser , *inputpass ;
GtkWidget *modif ,*gemp,*treeview ;

modif=lookup_widget(objet_graphique,"modifieremp");
gemp=create_GestionAEmployes();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

inputuser=lookup_widget(objet_graphique,"entrynouveauuseremp"); 
inputpass=lookup_widget(objet_graphique,"entrynouveaupassemp"); 

strcpy(user,gtk_entry_get_text(GTK_ENTRY(inputuser)));
strcpy(pass,gtk_entry_get_text(GTK_ENTRY(inputpass)));
modifierclient (name1,user,pass) ; 

treeview=lookup_widget(gemp,"treeviewemp");
afficheremp(treeview) ;
}


void
on_buttonretourempgestion_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *modif ,*gemp,*treeview ;

modif=lookup_widget(objet_graphique,"modifieremp");
gemp=create_GestionAEmployes();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

treeview=lookup_widget(gemp,"treeviewemp");
afficheremp(treeview) ;


}


void
on_buttonsupprimerce_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char cin[2000];
GtkWidget *recherche ;

recherche=lookup_widget(objet_graphique,"entryrechercheclientee");


strcpy(cin,gtk_entry_get_text(GTK_ENTRY(recherche)));

supprimerclient(cin);
}

char cin2[200]; 
void
on_buttonmodifierce_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gclient ,*modif ,*recherche;

recherche=lookup_widget(objet_graphique,"entryrechercheclientee");

gclient=lookup_widget(objet_graphique,"GestionEClient");
modif=create_modifierclientemp();
gtk_widget_show(modif);
gtk_widget_hide(gclient);

strcpy(cin2,gtk_entry_get_text(GTK_ENTRY(recherche)));
}


void
on_buttonvaliderce_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
char user[50]; 
char pass[50];  
GtkWidget *inputuser , *inputpass ;
GtkWidget *modif ,*gclient,*treeview ;

modif=lookup_widget(objet_graphique,"modifierclientemp");
gclient=create_GestionEClient();
gtk_widget_show(gclient);
gtk_widget_hide(modif); 

inputuser=lookup_widget(objet_graphique,"entryuserce"); 
inputpass=lookup_widget(objet_graphique,"entrypassce"); 

strcpy(user,gtk_entry_get_text(GTK_ENTRY(inputuser)));
strcpy(pass,gtk_entry_get_text(GTK_ENTRY(inputpass)));
modifierclient (cin1,user,pass) ; 

treeview=lookup_widget(gclient,"treeviewEclient");
afficherclient(treeview) ; 
}


void
on_buttonretourclientemp_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gclient,*treeview ;

modif=lookup_widget(objet_graphique,"modifierclientemp");
gclient=create_GestionEClient();
gtk_widget_show(gclient);
gtk_widget_hide(modif); 

treeview=lookup_widget(gclient,"treeviewEclient");
afficherclient(treeview) ;  
}



void
on_buttonmodifiervol_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *modif ,*gemp ;

modif=lookup_widget(objet_graphique,"VolsE");
gemp=create_modifiervol();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 
}


void
on_buttonsuppvol_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ;

modif=lookup_widget(objet_graphique,"VolsE");
gemp=create_supprimervol();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 
}


void
on_buttonretourmodvoltogvol_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ,*treeview ;

modif=lookup_widget(objet_graphique,"modifiervol");
gemp=create_VolsE();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

treeview=lookup_widget(gemp,"treeviewvol");
affichervol(treeview) ; 
}


void
on_buttonvalidernvvol_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

FILE *f ; 
char depart[50]; 
char destination[50];
char compagnie[50]; 
char daller[50]; 
char dretour[50]; 
char prix[50]; 

  
GtkWidget *inputdep , *inputdest ,*comp ,*nvaller ,*nvretour ,*nvprix ;
GtkWidget *treeview ;
GtkWidget *modif ,*gemp ;


inputdep=lookup_widget(objet_graphique,"entrydepartmodvol"); 
inputdest=lookup_widget(objet_graphique,"entrydestmodvol"); 
comp=lookup_widget(objet_graphique,"entrycompagniemodifiervol");
nvaller=lookup_widget(objet_graphique,"entrynvdatealler");
nvretour=lookup_widget(objet_graphique,"entrynvdateretour");
nvprix=lookup_widget(objet_graphique,"entrynvprix");

strcpy(depart,gtk_entry_get_text(GTK_ENTRY(inputdep)));
strcpy(destination,gtk_entry_get_text(GTK_ENTRY(inputdest)));
strcpy(compagnie,gtk_entry_get_text(GTK_ENTRY(comp)));
strcpy(daller,gtk_entry_get_text(GTK_ENTRY(nvaller)));
strcpy(dretour,gtk_entry_get_text(GTK_ENTRY(nvretour)));
strcpy(prix,gtk_entry_get_text(GTK_ENTRY(nvprix)));
modifiervol (depart,destination,compagnie,daller,dretour,prix) ; 




modif=lookup_widget(objet_graphique,"modifiervol");
gemp=create_VolsE();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

treeview=lookup_widget(gemp,"treeviewvol");
affichervol(treeview) ; 


}


void
on_buttonvalidersuppvol_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
char depart[50]; 
char destination[50];
char compagnie[50]; 


  
GtkWidget *inputdep , *inputdest ,*comp  ;
GtkWidget *treeview ;
GtkWidget *modif ,*gemp ;


inputdep=lookup_widget(objet_graphique,"entrysuppdepartvol"); 
inputdest=lookup_widget(objet_graphique,"entrydestsuppvol"); 
comp=lookup_widget(objet_graphique,"entrydestsuppvol");


strcpy(depart,gtk_entry_get_text(GTK_ENTRY(inputdep)));
strcpy(destination,gtk_entry_get_text(GTK_ENTRY(inputdest)));
strcpy(compagnie,gtk_entry_get_text(GTK_ENTRY(comp)));

supprimervol(depart,destination,compagnie);



modif=lookup_widget(objet_graphique,"supprimervol");
gemp=create_VolsE();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

treeview=lookup_widget(gemp,"treeviewvol");
affichervol(treeview) ; 
}


void
on_buttonretoursuppvoltogvol_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ,*treeview;

modif=lookup_widget(objet_graphique,"supprimervol");
gemp=create_VolsE();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

treeview=lookup_widget(gemp,"treeviewvol");
affichervol(treeview) ; 


}


void
on_buttonmodifierhyber_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ;

modif=lookup_widget(objet_graphique,"HybergementE");
gemp=create_modifierhotel();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 
}


void
on_buttonsupphyber_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
char hotel[50]; 



  
GtkWidget *inputhot  ;
GtkWidget *treeview ;
GtkWidget *gemp ,*modif ;


inputhot=lookup_widget(objet_graphique,"entryrecherchesupphotel"); 
modif=lookup_widget(objet_graphique,"HybergementE");

strcpy(hotel,gtk_entry_get_text(GTK_ENTRY(inputhot)));
supprimerhyber(hotel);


gemp=create_HybergementE();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 


treeview=lookup_widget(gemp,"treeviewhyber");
afficherhybergement(treeview) ; 

}


void
on_buttonvalidermodifhotel_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
char hotel[50]; 
char prix[50]; 

  
GtkWidget *inputhot  ,*nvprix ;
GtkWidget *treeview ;
GtkWidget *modif ,*gemp ;


inputhot=lookup_widget(objet_graphique,"entrymodifierhotel"); 
nvprix=lookup_widget(objet_graphique,"entrynvprix"); 

strcpy(hotel,gtk_entry_get_text(GTK_ENTRY(inputhot)));
strcpy(prix,gtk_entry_get_text(GTK_ENTRY(nvprix)));

modifierhyber (hotel,prix);



modif=lookup_widget(objet_graphique,"modifierhotel");
gemp=create_HybergementE();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

treeview=lookup_widget(gemp,"treeviewhyber");
afficherhybergement(treeview) ; 
}


void
on_buttonretourmodifhoteltohotel_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ,*treeview ;

modif=lookup_widget(objet_graphique,"modifierhotel");
gemp=create_HybergementE();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

treeview=lookup_widget(gemp,"treeviewhyber");
afficherhybergement(treeview) ; 
}

char marquedevoiture[50] ;
void
on_buttonmodifierlocation_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ,*marque ;

marque=lookup_widget(objet_graphique,"entryrecherchesupploc");
strcpy(marquedevoiture,gtk_entry_get_text(GTK_ENTRY(marque)));

modif=lookup_widget(objet_graphique,"LocationE");
gemp=create_modifierlocation();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 
}


void
on_buttonsupplocation_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
char marque[50]; 



  
GtkWidget *inputmarque  ;
GtkWidget *treeview ;
GtkWidget *gemp ,*modif ;


inputmarque=lookup_widget(objet_graphique,"entryrecherchesupploc"); 
modif=lookup_widget(objet_graphique,"LocationE");

strcpy(marque,gtk_entry_get_text(GTK_ENTRY(inputmarque)));
supprimerloc(marque);

gemp=create_LocationE();
gtk_widget_show(gemp);
gtk_widget_hide(modif);
treeview=lookup_widget(gemp,"treeviewlocation");
afficherlocation(treeview) ; 
}


void
on_buttonretourmodifierloctogloc_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ,*treeview;

modif=lookup_widget(objet_graphique,"modifierlocation");
gemp=create_LocationE();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

treeview=lookup_widget(gemp,"treeviewlocation");
afficherlocation(treeview) ; 
}


void
on_buttonvalidernvprixlocation_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 

char prix[50]; 

  
GtkWidget *nvprix ;
GtkWidget *treeview ;
GtkWidget *modif ,*gemp ;


nvprix=lookup_widget(objet_graphique,"entrynvprixlocation"); 



strcpy(prix,gtk_entry_get_text(GTK_ENTRY(nvprix)));

modifierloc(marquedevoiture,prix);



modif=lookup_widget(objet_graphique,"modifierlocation");
gemp=create_LocationE();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

treeview=lookup_widget(gemp,"treeviewlocation");
afficherlocation(treeview) ; 

}


void
on_buttonaffichervol_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
/*
GtkWidget *treeview ,*gemp ;

gemp=create_VolsE();

treeview=lookup_widget(gemp,"treeviewvol");
affichervol(treeview) ; */
}

void
on_buttonvalidervol_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

FILE *f ;
volclient cv ;

GtkWidget *modif ,*gemp ;

GtkWidget *dep ,*dest ,*heure ,*comp ,*datealler ,*dateretour , *nbad ,*nbenf ,*nbbb ,*ciin ;

gboolean toga ,togar ,togfc ,togec ;
dep=lookup_widget(objet_graphique,"comboboxentrydepart");
dest=lookup_widget(objet_graphique,"comboboxentrydestination");
comp=lookup_widget(objet_graphique,"comboboxcompagnie");
heure=lookup_widget(objet_graphique,"comboboxheuredepart");

datealler=lookup_widget(objet_graphique,"comboboxdateA");
dateretour=lookup_widget(objet_graphique,"comboboxdateR");

nbad=lookup_widget(objet_graphique,"spinbuttonadult");
nbenf=lookup_widget(objet_graphique,"spinbuttonenfant");
nbbb=lookup_widget(objet_graphique,"spinbuttonbebe");
ciin=lookup_widget(objet_graphique,"entryvalidercin");

toga=on_checkbuttonA_toggled(objet_graphique,user_data);
togar=on_checkbuttonAR_toggled(objet_graphique,user_data);
togfc=on_checkbuttonfirst_toggled(objet_graphique,user_data);
togec=on_checkbuttoneco_toggled(objet_graphique,user_data);



strcpy(cv.depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dep)));
strcpy(cv.destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dest)));
strcpy(cv.compagnie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comp)));
strcpy(cv.heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX(heure)));

strcpy(cv.datealler,gtk_combo_box_get_active_text(GTK_COMBO_BOX(datealler)));
strcpy(cv.dateretour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dateretour)));

cv.adulte=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbad));
cv.enf=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbenf));
cv.bb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbbb));

strcpy(cv.cin,gtk_entry_get_text(GTK_ENTRY(ciin)));

if (toga) 
  {
   strcpy(cv.ar,"aller") ; 
  }

if (togar) 
  {
   strcpy(cv.ar,"aller/retour") ; 
  }
if (togfc) 
  {
   strcpy(cv.classe,"FirstClass") ; 
  }

if (togec) 
  {
   strcpy(cv.classe,"Economique") ; 
  }

reservervol(cv); 

modif=lookup_widget(objet_graphique,"Vols");
gemp=create_ModeClient();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

}



gboolean
on_checkbuttonA_toggled                (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget	*togglebutton1,*togglebutton2;
	gboolean etat;
	togglebutton1=lookup_widget(objet_graphique,"checkbuttonA");
	togglebutton2=lookup_widget(objet_graphique,"checkbuttonAR");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton1));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton2),FALSE);
	}
	return etat;
}


gboolean
on_checkbuttonAR_toggled               (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget	*togglebutton1,*togglebutton2;
	gboolean etat;
	togglebutton1=lookup_widget(objet_graphique,"checkbuttonA");
	togglebutton2=lookup_widget(objet_graphique,"checkbuttonAR");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton2));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton1),FALSE);
	}
	return etat;
}


gboolean
on_checkbuttonfirst_toggled            (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget	*togglebutton1,*togglebutton2;
	gboolean etat;
	togglebutton1=lookup_widget(objet_graphique,"checkbuttonfirst");
	togglebutton2=lookup_widget(objet_graphique,"checkbuttoneco");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton1));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton2),FALSE);
	}
	return etat;
}


gboolean
on_checkbuttoneco_toggled              (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget	*togglebutton1,*togglebutton2;
	gboolean etat;
	togglebutton1=lookup_widget(objet_graphique,"checkbuttonfirst");
	togglebutton2=lookup_widget(objet_graphique,"checkbuttoneco");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton2));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton1),FALSE);
	}
	return etat;
}


void
on_buttonvaliderhyberclient_clicked    (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *modif ,*gemp ;

GtkWidget *pay , *hotel , *nbp , *jour ,*ciin ; 

gboolean togf ,tognf ;


hyberclient hc ; 

ciin=lookup_widget(objet_graphique,"entrycinhyberclient");
pay=lookup_widget(objet_graphique,"comboboxentryHyberpays");
hotel=lookup_widget(objet_graphique,"comboboxhotel");
nbp=lookup_widget(objet_graphique,"spinbuttonnbh");
jour=lookup_widget(objet_graphique,"spinbuttond1");


togf=on_checkbuttonfumeur_toggled(objet_graphique,user_data);
tognf=on_checkbuttonnfumeur_toggled(objet_graphique,user_data);

strcpy(hc.cin,gtk_entry_get_text(GTK_ENTRY(ciin)));
strcpy(hc.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(pay)));
strcpy(hc.hotel,gtk_combo_box_get_active_text(GTK_COMBO_BOX(hotel)));

hc.jd=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

if (togf) 
   {
     strcpy(hc.fnf,"Fumeur") ; 
   }
if (tognf) 
   {
     strcpy(hc.fnf,"NonFumeur") ; 
   }

reserverhyber(hc) ; 

modif=lookup_widget(objet_graphique,"Hybergement");
gemp=create_ModeClient();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 


}


gboolean
on_checkbuttonfumeur_toggled           (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget	*togglebutton1,*togglebutton2;
	gboolean etat;
	togglebutton1=lookup_widget(objet_graphique,"checkbuttonfumeur");
	togglebutton2=lookup_widget(objet_graphique,"checkbuttonnfumeur");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton1));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton2),FALSE);
	}
	return etat;
}
gboolean
on_checkbuttonnfumeur_toggled          (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget	*togglebutton1,*togglebutton2;
	gboolean etat;
	togglebutton1=lookup_widget(objet_graphique,"checkbuttonfumeur");
	togglebutton2=lookup_widget(objet_graphique,"checkbuttonnfumeur");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton2));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton1),FALSE);
	}
	return etat;
}

void
on_buttonvaliderlocation_clicked       (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ;

locationclient lc ; 
GtkWidget *marque ,*nbj ,*ciin ;

ciin=lookup_widget(objet_graphique,"entrycinlocation");
nbj=lookup_widget(objet_graphique,"spinbuttonjd");
marque=lookup_widget(objet_graphique,"comboboxmar");


strcpy(lc.cin,gtk_entry_get_text(GTK_ENTRY(ciin)));
strcpy(lc.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(marque)));
lc.nbj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbj));

reserverlocation(lc) ; 

modif=lookup_widget(objet_graphique,"Location");
gemp=create_ModeClient();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 
}


void
on_buttonPanier_clicked                (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ;

modif=lookup_widget(objet_graphique,"ModeClient");
gemp=create_panier();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 
}


void
on_buttonretourvaliderreservationtomodeclient_clicked    (GtkWidget        *objet_graphique,
                                                           gpointer         user_data)
{
GtkWidget *modif ,*gemp ;

modif=lookup_widget(objet_graphique,"panier");
gemp=create_ModeClient();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 
}


void
on_buttonvaliderreservation_clicked    (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *modif ,*gemp ;

modif=lookup_widget(objet_graphique,"panier");
gemp=create_merci();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

stockage();  
}


void
on_buttonafficherreservation_clicked   (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ciin ,*pani ,*treeview; 
char cin[50]; 

pani=lookup_widget(objet_graphique,"panier");
ciin=lookup_widget(objet_graphique,"entrycinreservation");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(ciin)));
reservtotal(cin); 

treeview=lookup_widget(pani,"treeviewpanier");
afficherreservation (treeview) ;



}



void
on_buttonok_clicked                    (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ;

modif=lookup_widget(objet_graphique,"merci");
gemp=create_ModeClient();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 

effacer() ; 
}




void
on_buttonenvoyermessage_clicked        (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ,*ciin , *mess ;

char cin[50]; 
char message1[3000]; 

ciin=lookup_widget(objet_graphique,"entrycincontacter");
mess=lookup_widget(objet_graphique,"entrymessagecontacter");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(ciin)));
strcpy(message1,gtk_entry_get_text(GTK_ENTRY(mess)));

messgae(cin,message1);

modif=lookup_widget(objet_graphique,"contacter");
gemp=create_ModeClient();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 
}


void
on_buttonsuppmessageadmin_clicked      (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
char cin[50]; 



  
GtkWidget *inputcin  ;
GtkWidget *treeview ;
GtkWidget *gemp ,*modif ;


inputcin=lookup_widget(objet_graphique,"entrycinmessageadmin"); 
modif=lookup_widget(objet_graphique,"message");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(inputcin)));
suppmsg(cin);


gemp=create_message();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 


treeview=lookup_widget(gemp,"treeviewmessageadmin");
affichermessage(treeview) ; 

}


void
on_buttonsuppmessageemp_clicked        (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
char cin[50]; 



  
GtkWidget *inputcin  ;
GtkWidget *treeview ;
GtkWidget *gemp ,*modif ;


inputcin=lookup_widget(objet_graphique,"entrycinempmsg"); 
modif=lookup_widget(objet_graphique,"messageE");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(inputcin)));
suppmsg(cin);


gemp=create_messageE();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 


treeview=lookup_widget(gemp,"treeviewmessageemp");
affichermessage(treeview) ; 
}


void
on_buttonenvoyerrecluser_clicked       (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modif ,*gemp ,*ciin , *mess ,*type ,*jj ,*mm ,*yy ;

char cin[50]; 
char message1[3000]; 
char type1[50]; 
int j ; 
int m ; 
int y ; 

ciin=lookup_widget(objet_graphique,"entrycinrecuser");
mess=lookup_widget(objet_graphique,"entryrecuser");
type=lookup_widget(objet_graphique,"comboboxreclamation");
jj=lookup_widget(objet_graphique,"spinbuttonrecj");
mm=lookup_widget(objet_graphique,"spinbuttonrecm");
yy=lookup_widget(objet_graphique,"spinbuttonrecy");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(ciin)));
strcpy(message1,gtk_entry_get_text(GTK_ENTRY(mess)));
strcpy(type1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));

reclamer(cin,message1,type1,j,m,y);

modif=lookup_widget(objet_graphique,"reclamer");
gemp=create_ModeClient();
gtk_widget_show(gemp);
gtk_widget_hide(modif); 
}



void
on_buttontraiter_clicked               (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
GtkWidget *rec ,*ciin ,*rec1 ,*treeview ;

char cin[50] ; 

ciin=lookup_widget(objet_graphique,"entryciinrecemp");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(ciin)));

modifieretat(cin);

rec=lookup_widget(objet_graphique,"reclamationE");
rec1=create_reclamationE(); 
gtk_widget_show(rec1);
gtk_widget_hide(rec);

treeview=lookup_widget(rec1,"treeviewreclamationemp");
afficherrec(treeview) ; 



}


void
on_buttonsupprec_clicked               (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
GtkWidget *rec ,*ciin ,*rec1 ,*treeview ;

char cin[50] ; 

ciin=lookup_widget(objet_graphique,"entryciinrecemp");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(ciin)));

supprimerrec(cin);

rec=lookup_widget(objet_graphique,"reclamationE");
rec1=create_reclamationE(); 
gtk_widget_show(rec1);
gtk_widget_hide(rec);

treeview=lookup_widget(rec1,"treeviewreclamationemp");
afficherrec(treeview) ; 
}


void
on_buttontraiteradmin_clicked          (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
GtkWidget *rec ,*ciin ,*rec1 ,*treeview ;

char cin[50] ; 

ciin=lookup_widget(objet_graphique,"entrycinrecadmin");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(ciin)));

modifieretat(cin);

rec=lookup_widget(objet_graphique,"reclamation");
rec1=create_reclamation(); 
gtk_widget_show(rec1);
gtk_widget_hide(rec);

treeview=lookup_widget(rec1,"treeviewrecadmin");
afficherrec(treeview) ; 
}


void
on_buttonsuppadmin_clicked             (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
GtkWidget *rec ,*ciin ,*rec1 ,*treeview ;

char cin[50] ; 

ciin=lookup_widget(objet_graphique,"entrycinrecadmin");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(ciin)));

supprimerrec(cin);

rec=lookup_widget(objet_graphique,"reclamation");
rec1=create_reclamation(); 
gtk_widget_show(rec1);
gtk_widget_hide(rec);

treeview=lookup_widget(rec1,"treeviewrecadmin");
afficherrec(treeview) ; 
}

