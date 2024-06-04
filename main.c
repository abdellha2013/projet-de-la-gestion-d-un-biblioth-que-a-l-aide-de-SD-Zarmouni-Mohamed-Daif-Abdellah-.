#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 200
// Structure du Livre--------------------------------------------------------------------
typedef struct
{
    char *titre;  // un pointeur vers une cha�ne de caract�res.
    char *auteur; // un pointeur vers une cha�ne de caract�res.
    int annee;    // un entier repr�sentant l'ann�e de publication.
    int ISBN;     // un entier unique pour chaque livre.
    int quntite;  // les livre disponuible
} Livre;

// Structure de l'Emprunteur--------------------------------------------------------------
typedef struct
{
    char *nom; // un pointeur vers une cha�ne de caract�res.
    int id;    // un entier unique pour chaque emprunteur.
} Emprunteur;

// Structure de l'Emprunt-----------------------------------------------------------------
typedef struct
{
    Livre *livre;           // un pointeur vers une structure de type Livre.
    Emprunteur *emprunteur; // un pointeur vers une structure de type Emprunteur.
    char *dateEmprunt;      // un pointeur vers une cha�ne de caract�res repr�sentant la date d'emprunt (format : JJ/MM/AAAA).
    char *dateRetour;       // un pointeur vers une cha�ne de caract�res repr�sentant la date de retour (format : JJ/MM/AAAA).
} Emprunt;

// Listes simplement chainees-------------------------------------------------------------
// Une liste de livres.
typedef struct liste_livres
{
    Livre *livre;
    struct liste_livres *next;
} liste_livres;

// Une liste d'emprunteurs.
typedef struct liste_emprunteurs
{
    Emprunteur *emprunteur;
    struct liste_emprunteurs *next;
} liste_emprunteurs;

// Une liste d'emprunts
typedef struct liste_emprunts
{
    Emprunt *emprunt;
    struct liste_emprunts *next;
} liste_emprunts;

// c'est pour initialiser le pointeur sur la liste simplement chainee soit livre , empunteurs ou emprint par NULL
void *new_struct(void);

// est ce que ls liste est vide pour les trois cas et retourner un valeur booleane
bool est_vide_livres(liste_livres *l);
bool est_vide_emprunts(liste_emprunts *l);
bool est_vide_emprunteurs(liste_emprunteurs *l);

// Ajouter un livre a la bibliotheque.
void ajouter_livres(liste_livres **l, char *titre, char *auteur, int annee, int ISBN, int quntite);
void ajouter_n_livres(liste_livres ** l);
void afficher_ls_livres(liste_livres *l);

// Ajouter un emprunteur.
void Ajouter_emprunteur(liste_emprunteurs **l, char *nom, int id);
void afficher_ls_emprunteur(liste_emprunteurs *l);

// Enregistrer un emprunt.
void Enregistrer_emprunt(liste_emprunts **l, Livre *livres, Emprunteur *emprunteur, char *date_emprunt, char *date_retour);
void Ajouter_emprunt(liste_emprunts**ls_emprunts,liste_emprunteurs **ls_emprunteurs,liste_livres**ls_livres);
void afficher_ls_emprunt(liste_emprunts *l);


//retoure d'un livre
void pop_emprunt(liste_emprunts**ls_emprunts,liste_emprunteurs **ls_emprunteurs,liste_livres**ls_livres);
void pop_emprunteur(liste_emprunteurs **ls_emprunteurs,char* name,int id);


// fonction la manupilation des fichier------------------------------------------------------
void    telecharger_livre(liste_livres**ls_livres);//télécharger les livres dons le fichier livres.txt
void    save_livre(liste_livres**ls_livres);
void    telecharger_emprunts(liste_emprunts**ls_emprunts,liste_emprunteurs **ls_emprunteurs,liste_livres**ls_livres);
void    save_emprunts(liste_emprunts**ls_emprunts);
void    telecharger_emprunteurs(liste_emprunteurs**ls_emprunteurs);
void    save_emprunteurs(liste_emprunteurs ** ls_emprunteurs);



int main()
{
    int n;
    liste_livres *ls_livres = new_struct();           // initialiser le pointeur vers la liste simplement chainee pour les livres
    liste_emprunteurs *ls_emprunteurs = new_struct(); // initialiser le pointeur vers la liste simplement chainee pour les emprunteurs
    liste_emprunts *ls_emprunts = new_struct();       ////initialiser le pointeur vers la liste simplement chainee pour les emprunts

    //Chargement des informations du disque dur dans les liste

    telecharger_livre(&ls_livres);
    telecharger_emprunteurs(&ls_emprunteurs);
    telecharger_emprunts(&ls_emprunts,&ls_emprunteurs,&ls_livres);

    printf("************************************************************\n");
    printf("*                Gestion d'une bibliotheque                *\n");
    printf("************************************************************\n\n");

    debut:
    printf("Menu :******************************************************\n");
    printf("\t1- Afficher la liste des livres.\n");
    printf("\t2- affiche la liste des emprunteurs .\n");
    printf("\t3- affiche la liste des emprunts .\n");
    printf("\t4- Ajouter un liver dans le stock.\n");
    printf("\t5- Ajouter plieusieurs livres dans le stock.\n");
    printf("\t6- Ajoute un emprunt a la liste des emprunts.\n");
    printf("\t7- validier la reteur d'un liver.\n");
    printf("\t8- tester est-ce-que la liste des livres est vide .\n");
    printf("\t9- tester est-ce-que la liste des emprunts est vide .\n");
    printf("\t10- tester est-ce-que la liste des emprunteurs est vide .\n");
    printf("\t11- fin du programme et enregister les information sur HD \n");
    int i;
    printf("veuillez entrer un  entier :\n\t");
    scanf("%d",&i);

    switch(i){
        case 1: afficher_ls_livres(ls_livres); break;
        case 2: afficher_ls_emprunteur(ls_emprunteurs);break;
        case 3: afficher_ls_emprunt(ls_emprunts);break;

        case 4:
            fflush(stdin);
            char titre[20];
            char name[20];

            printf("veuillez entrer le titre du livres : ");
            scanf("%s",titre);
            printf("veuillez entrer le nom de l'auteur : ");
            scanf("%s",name);
            int annee,ISBN,quantite;
            printf("veuillez entrer l'annee de naisence : ");
            scanf("%i",&annee);
            printf("veuillez entrer le ISBN : ");
            scanf("%i",&ISBN);
            printf("veuillez entrer la quntite : ");
            scanf("%i",&quantite);

            ajouter_livres(&ls_livres,titre,name,annee,ISBN,quantite); break;
        case 5:
            ajouter_n_livres(&ls_livres); break;
        case 6:
            Ajouter_emprunt(&ls_emprunts,&ls_emprunteurs,&ls_livres); break;
        case 7:
            pop_emprunt(&ls_emprunts,&ls_emprunteurs,&ls_livres); break;
        case 8:
            if(est_vide_livres(ls_livres))
                printf("la liste des livres est vide \n");
            else
                printf("la liste  des livres n'est pas vide \n");
            break;
        case 9:
            if(est_vide_emprunts(ls_emprunts))
                printf("la liste des emprunts est vide \n");
            else
                printf("la liste  des emprunts n'est pas vide \n");
            break;
        case 10:
            if(est_vide_emprunteurs(ls_emprunteurs))
                printf("la liste des emprunteurs est vide \n");
            else
                printf("la liste  des emprunteurs n'est pas vide \n");
            break;
        case 11:
            save_livre(&ls_livres);
            save_emprunteurs(&ls_emprunteurs);
            save_emprunts(&ls_emprunts);
            return 0;break;
        default:
            printf("votre choi n'est pas existe \n");

    }
    goto debut;

}
// c'est pour initialiser le pointeur sur la liste simplement chainee soit livre , empunteurs ou emprint par NULL
void *new_struct(void) { return NULL; }


// Ajouter un livre a la bibliotheque.
bool est_vide_livres(liste_livres *l) { return l == NULL; }
bool est_vide_emprunts(liste_emprunts *l) { return l == NULL; }
bool est_vide_emprunteurs(liste_emprunteurs *l) { return l == NULL; }

// Ajouter un livre a la bibliotheque.
void ajouter_livres(liste_livres **l, char *titre, char *auteur, int annee, int ISBN, int quantite)
{
    liste_livres *p = (liste_livres *)malloc(sizeof(liste_livres));
    if (p == NULL)
    {
        fprintf(stderr, "Un probleme d'allocation de la memoire.\n");
        exit(EXIT_FAILURE);//1
    }
    p->livre = (Livre *)malloc(sizeof(Livre));
    if (p->livre == NULL)
    {
        fprintf(stderr, "Un probleme d'allocation de la memoire pour le livre.\n");
        exit(EXIT_FAILURE);
    }

    p->livre->titre = strdup(titre);
    p->livre->auteur = strdup(auteur);
    p->livre->annee = annee;
    p->livre->ISBN = ISBN;
    p->livre->quntite = quantite;
    p->next = *l;
    *l = p;
}

//// Ajouter plusieur livre a la bibliotheque.
void ajouter_n_livres(liste_livres ** l)
{
   //pour ajouter des livre :
    printf("veuillez entrer le nomre des livres a ajouter :");
    int nbr_livre;
    char Auteur[MAX_SIZE];
    scanf("%i",&nbr_livre);
    char Titre[MAX_SIZE];
    int anne,ISBN,quntite;
    for(int i=1;i<=nbr_livre;i++){
        fflush(stdin);
        printf("veuillez entrer le titre du livre :");
        gets(Titre);
        printf("veuillez entrer le nom de l'auteur :");
        gets(Auteur);
        printf("veuillez entrer anne de l'auteur :");
        scanf("%i",&anne);
        printf("veuillez entrer l'ISBN du livre :");
        scanf("%i",&ISBN);
        printf("veuillez entrer la quntite a ajouter :");
        scanf("%i",&quntite);
        ajouter_livres(l,Titre,Auteur,anne,ISBN,quntite);
    }

}

//affichage des livres
void afficher_ls_livres(liste_livres *l)
{
    if (l == NULL)
        printf("aucune livre existe dons la liste des livres .\n");
    else
    {
        liste_livres *tmp = l;
        int i = 1;
        printf("les livres disponible est **********************************\n");

        while (tmp != NULL)
        {
            printf("le %i eme livre est :\n", i++);
            printf("\ttitre : %s   \n\tauteur : %s  \n\tannee : %i  \n\tISBN : %i  \n\tQuntite %i \n\n", tmp->livre->titre, tmp->livre->auteur, tmp->livre->annee, tmp->livre->ISBN, tmp->livre->quntite);
            tmp = tmp->next;
        }
        printf("************************************************************\n");
    }
}

// Ajouter un emprunteur .
void Ajouter_emprunteur(liste_emprunteurs **l, char *nom, int id)
{
    liste_emprunteurs *p = (liste_emprunteurs *)malloc(sizeof(liste_emprunteurs));
    if (p == NULL)
    {
        fprintf(stderr, "Un probleme d'allocation de la memoire.\n");
        exit(EXIT_FAILURE);
    }
    p->emprunteur = (Emprunteur *)malloc(sizeof(Emprunteur));
    if (p->emprunteur == NULL)
    {
        fprintf(stderr, "Un probleme d'allocation de la memoire.\n");
        exit(EXIT_FAILURE);
    }
    p->emprunteur->nom = strdup(nom);
    p->emprunteur->id = id;
    p->next = *l;
    *l = p;
    // return p;
}

//affichage des emprunteurs
void afficher_ls_emprunteur(liste_emprunteurs *l)
{
    if (l == NULL)
    {
        printf("aucune emprunteur existe dons la liste des emprunteurs .\n");
        return;
    }
    else
    {
        liste_emprunteurs *tmp = l;
        printf("les emprunteurs est ****************************************\n");
        while (tmp != NULL)
        {
            printf("\n\tle nom : %s\n\tid : %i\n\n", tmp->emprunteur->nom, tmp->emprunteur->id);
            tmp = tmp->next;
        }
        printf("************************************************************\n");
    }
}


void Enregistrer_emprunt(liste_emprunts **l, Livre *livre, Emprunteur *emprunteur, char *date_emprunt, char *date_retour)
{
    liste_emprunts *p = (liste_emprunts *)malloc(sizeof(liste_emprunts));
    if (p == NULL)
    {
        fprintf(stderr, "Un probleme d'allocation de la memoire.\n");
        exit(EXIT_FAILURE);
    }
    p->emprunt = (Emprunt *)malloc(sizeof(Emprunt));
    if (p->emprunt == NULL)
    {
        fprintf(stderr, "Un probleme d'allocation de la memoire.\n");
        exit(EXIT_FAILURE);
    }

    p->emprunt->livre = livre;
    p->emprunt->emprunteur = emprunteur;
    p->emprunt->dateEmprunt = strdup(date_emprunt);
    p->emprunt->dateRetour = strdup(date_retour);
    p->next = *l;
    *l = p;
}


void Ajouter_emprunt(liste_emprunts**ls_emprunts,liste_emprunteurs **ls_emprunteurs,liste_livres**ls_livres){
    if(est_vide_livres(*ls_livres)){
        fprintf(stderr,"la bibliotheque est vide .");
        exit(EXIT_FAILURE);
    }

    //afficher_ls_livres(*ls_livres);

    char name[20];
    char Titre[20];
    int id;

    fflush(stdin);//vider le tampon de sortie du flux d'entrée standard.
    printf("veuillez entrer le nom du client :");
    gets(name);

    printf("veuillez entrer le titre du livre a empunter :");
    gets(Titre);
    liste_livres *tmp=*ls_livres;
    while(!est_vide_livres(tmp)){
        if(strcmp(tmp->livre->titre,Titre)==0){
            break;
        }
        tmp=tmp->next;
    }
    if(est_vide_livres(tmp)){//tmp==NULL
            fprintf(stderr,"votre livre n'est pas existe .");
            exit(EXIT_FAILURE);
    }
    if(tmp->livre->quntite==0){//tmp==NULL
            fprintf(stderr,"votre stock de la livre ''%s'' est vide .",Titre);
            exit(EXIT_FAILURE);
    }
    --(tmp->livre->quntite);

    printf("veuillez entrer le  id du client : ");
    scanf("%i",&id);

    Ajouter_emprunteur(ls_emprunteurs,name,id);

    char dat_emprunt[20],dat_retoure[20];
    fflush(stdin);//vider le tampon de sortie du flux d'entrée standard.
    printf("veuillez entrer la date de aujourd'huit  (JJ/MM/AAAA) :");
    scanf("%s",dat_emprunt);
    printf("veuillez entrer la date de retoure du livre (JJ/MM/AAAA) :");
    scanf("%s",dat_retoure);

    Enregistrer_emprunt(ls_emprunts,tmp->livre, (*ls_emprunteurs)->emprunteur, dat_emprunt, dat_retoure);//pour ajouter un element a la liste des emprunts
}

//affichage des emprunteur
void afficher_ls_emprunt(liste_emprunts *l)
{
    if (l == NULL)
    {
        printf("aucun emprunt existe dons la liste des emprunts .\n");
    }
    else
    {
        liste_emprunts *tmp = l;
        int comp = 1;
        printf("Les elements d'emprunt :************************************\n");
        while (tmp != NULL)
        {
            printf("les information du %i ere emprunteur :\n", comp++);
            printf("\tNom  : %s \n\tID : %i\n", tmp->emprunt->emprunteur->nom, tmp->emprunt->emprunteur->id);
            printf("\t\tTitre du livre : %s\n\t\tAuteur : %s\n\t\tAnnee : %i\n\t\tISBN : %i\n\t\tQuantite qui reste dons le stock : %i\n",
            tmp->emprunt->livre->titre, tmp->emprunt->livre->auteur, tmp->emprunt->livre->annee,
            tmp->emprunt->livre->ISBN, tmp->emprunt->livre->quntite);
            printf("\tDate d'emprunt : %s\n\tDate de retour : %s\n\n", tmp->emprunt->dateEmprunt, tmp->emprunt->dateRetour);
            tmp = tmp->next;
        }
        printf("************************************************************\n");
    }
}

//retoure d'un livre
void pop_emprunt(liste_emprunts**ls_emprunts,liste_emprunteurs **ls_emprunteurs,liste_livres**ls_livres){
    if(est_vide_emprunts(*ls_emprunts)){
        printf("la liste des emprunts est vide .");
        return;
    }
    fflush(stdin);
    char name[20];
    printf("veuillez entrer le nom du client pour retourner le livre :");
    gets(name);
    int id;
    printf("veuillez entrer le id du client :");
    scanf("%i",&id);

    //block pour retirer un emprunt dons la liste des emprunts si il existe
    liste_emprunts* tmp=*ls_emprunts,*tmp_;
    while(tmp!=NULL){
        tmp_=tmp;
        if((strcmp(tmp->emprunt->emprunteur->nom,name)==0)&&id==tmp->emprunt->emprunteur->id){
            //printf("le client %s exist dons la liste des emprunts . \n",name);
            break;
        }
        tmp=tmp->next;
    }
    if(est_vide_emprunts(tmp)){//tmp==NULL
        printf("le client %s n'est pas exist dons la liste des emprunts . \n",name);
        return;
    }

    liste_livres *livre=tmp->emprunt->livre;
    if((*ls_emprunts)==tmp)
        *ls_emprunts=tmp->next;
    else
        tmp_->next=tmp->next;
    free(tmp);

    //block pour retirer un emprunteur dons la liste des emprunteurs s'il existe
    pop_emprunteur(ls_emprunteurs,name,id);
    //incrimentation de la quntite du livre :
    liste_livres *tmp2=*ls_livres;
    while(tmp2!=NULL){
        if(tmp2->livre==livre){
            break;
        }
        tmp2=tmp2->next;
    }
    (tmp2->livre->quntite)++;

}

//supprimer un emprunteur dons la liste des emprinteurs
 void   pop_emprunteur(liste_emprunteurs **ls_emprunteurs,char* name,int id){
    if(est_vide_emprunteurs(*ls_emprunteurs)){
        printf("la liste des emprunteurs est vide .");
        return;
    }
    liste_emprunteurs *tmp=*ls_emprunteurs,*tmp_;
    while(tmp!=NULL){
        tmp_=tmp;
        if((strcmp(tmp->emprunteur->nom,name)==0)&&tmp->emprunteur->id==id){
            break;
        }
        tmp=tmp->next;
    }
    if(tmp==NULL){
        printf("vetre client n'est pas existe dons la liste des emprunteurs .");
        return;
    }
    else if(est_vide_emprunteurs(tmp->next)){
        *ls_emprunteurs=NULL;
    }else{
        tmp_->next=tmp->next;
    }
    free(tmp);
 }

//manipulation  pour le fichier des livres

 void    telecharger_livre(liste_livres**ls_livres){
    FILE * file=NULL;
    file=fopen("livres.txt","rt");//en mode lecture dons le fichier pour les fichier text
    if(file==NULL){
        fprintf(stderr,"Erreur douvrire le fichier.");
        exit(EXIT_FAILURE);
    }// si le fichier est vide
    fseek(file,0,SEEK_END);
    while(ftell(file)==0){
          fclose(file);
          return;
    }
    rewind(file);
    char Titre[20];
    char auteur[20];
    int annee,ISBN,quntite;
    while((fscanf(file,"%s %s %i %i %i\n",Titre,auteur,&annee,&ISBN,&quntite))!=EOF){
        ajouter_livres(ls_livres,Titre,auteur,annee,ISBN,quntite);
    }
    fclose(file);

}

void    save_livre(liste_livres**ls_livres){
    FILE * file=NULL;
    file=fopen("livres.txt","w");//en mode ecriture seul
    if(file==NULL){
        fprintf(stderr,"Erreur douvrire le fichier.");
        exit(EXIT_FAILURE);
    }
    if(est_vide_livres(*ls_livres)){
        afficher_ls_livres(*ls_livres);//affiche aucune livre existe dons la liste des livres .
        fclose(file);
        return;
    }
    liste_livres * tmp=*ls_livres;
    while(tmp!=NULL){
        fprintf(file,"%s %s %i %i %i\n",tmp->livre->titre,tmp->livre->auteur,
        tmp->livre->annee,tmp->livre->ISBN,tmp->livre->quntite);
        tmp=tmp->next;
    }
    fclose(file);
}


//manipulation  pour le fichier des emprunteurs
 void    telecharger_emprunteurs(liste_emprunteurs**ls_emprunteurs){
    FILE * file=NULL;
    file=fopen("emprunteurs.txt","rt");//en mode lecture dons le fichier pour les fichier text
    if(file==NULL){
        fprintf(stderr,"Erreur douvrire le fichier.");
        exit(EXIT_FAILURE);
    }//si le fichier est vide
    fseek(file,0,SEEK_END);
    while(ftell(file)==0){
          fclose(file);
          return;
    }
    rewind(file);
    char name[20];
    int id;
    while((fscanf(file,"%s %i\n",name,&id))!=EOF){
        Ajouter_emprunteur(ls_emprunteurs,name,id);
    }
    fclose(file);

}

void    save_emprunteurs(liste_emprunteurs ** ls_emprunteurs){
    FILE * file=NULL;
    file=fopen("emprunteurs.txt","w");//en mode ecriture seul
    if(file==NULL){
        fprintf(stderr,"Erreur douvrire le fichier.");
        exit(EXIT_FAILURE);
    }
    if(est_vide_emprunteurs(*ls_emprunteurs)){
        afficher_ls_emprunteur(*ls_emprunteurs);//affiche aucune livre existe dons la liste des livres .
        fclose(file);
        return;
    }
    liste_emprunteurs * tmp=*ls_emprunteurs;
    while(tmp!=NULL){
        fprintf(file,"%s %i\n",tmp->emprunteur->nom,tmp->emprunteur->id);
        tmp=tmp->next;
    }
    fclose(file);
}


//manipulation  pour le fichier des emprunts

 void    telecharger_emprunts(liste_emprunts**ls_emprunts,liste_emprunteurs **ls_emprunteurs,liste_livres**ls_livres){
    FILE * file=NULL;
    file=fopen("emprunts.txt","rt");//en mode lecture dons le fichier pour les fichier text
    if(file==NULL){
        fprintf(stderr,"Erreur douvrire le fichier.");
        exit(EXIT_FAILURE);
    }
    fseek(file,0,SEEK_END);
    while(ftell(file)==0){
          fclose(file);
          return;
    }
    rewind(file);

    liste_livres *tmp_livre=*ls_livres;
    liste_emprunteurs *tmp_emprunteur=*ls_emprunteurs;
    fflush(stdin);
    char titre[20];
    char name[20];
    int id,ISBN;
    char dateEmprunt[20];
    char dateretour[20];
    bool b;
    while((fscanf(file,"%s %i %s %i %s %s\n",titre,&ISBN,name,&id,dateEmprunt,dateretour))!=EOF){
        b=true;
        while(tmp_emprunteur!=NULL)
        {
            if( strcmp(tmp_emprunteur->emprunteur->nom,name)==0 && tmp_emprunteur->emprunteur->id==id ){
                b=false;
                break;
            }
            tmp_emprunteur=tmp_emprunteur->next;
        }
        if(b){
            fprintf(stderr,"Erreur : votre information sur l'emprunteur n'est pas existe dons la liste des emprunteurs .");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        b=true;
        while(tmp_livre!=NULL)
        {
            if( strcmp(tmp_livre->livre->titre,titre)==0 && tmp_livre->livre->ISBN==ISBN ){
                b=false;
                break;
            }
            tmp_livre=tmp_livre->next;
        }
        if(b){
            fprintf(stderr,"Erreur : votre information sur le livre n'est pas existe dons la liste des livres .");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        Enregistrer_emprunt(ls_emprunts,tmp_livre->livre,tmp_emprunteur->emprunteur,dateEmprunt,dateretour);
        tmp_emprunteur=tmp_emprunteur->next;
        tmp_livre=tmp_livre->next;
    }
    fclose(file);

}


void    save_emprunts(liste_emprunts**ls_emprunts){
    FILE * file=NULL;
    file=fopen("emprunts.txt","w");//en mode ecriture seul
    if(file==NULL){
        fprintf(stderr,"Erreur douvrire le fichier.");
        exit(EXIT_FAILURE);
    }
    if(est_vide_emprunts(*ls_emprunts)){
        afficher_ls_emprunt(*ls_emprunts);//affiche aucune livre existe dons la liste des livres .
        fclose(file);
        return;
    }
    liste_emprunts * tmp=*ls_emprunts;
    while(tmp!=NULL){
        fprintf(file,"%s %i %s %i %s %s\n",tmp->emprunt->livre->titre,tmp->emprunt->livre->ISBN,
        tmp->emprunt->emprunteur->nom,tmp->emprunt->emprunteur->id,tmp->emprunt->dateEmprunt,tmp->emprunt->dateRetour);
        tmp=tmp->next;
    }
    fclose(file);
}



