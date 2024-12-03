#include <stdio.h>
#include "vols.h"
#include <string.h>
#define MAX_SIZE 100


void ajouterVols(Vols vols[], int *n) {
    // Vérification de la capacité
    if (*n >= MAX_SIZE) {
        printf("Erreur : impossible d'ajouter un vol, le tableau est plein.\n");
        return;
    }

    printf("Ajout d'un nouveau vol\n");
    printf("******************************\n");

    printf("Entrez le code : ");
    scanf("%s", vols[*n].code);  // Lire une chaîne pour le code

    printf("Entrez la destination : ");
    scanf("%s", vols[*n].destination);  // Lire une chaîne pour la destination

    printf("Entrez la date (JJ/MM/AA) : ");
    scanf("%s", vols[*n].date);  // Lire une chaîne pour la date

    printf("Nombre de sièges disponibles : ");
    scanf("%d", &vols[*n].sieges);  // Lire un entier pour les sièges

    // Incrémenter le compteur de vols
    (*n)++;

    printf("******************************\n");
    printf("Vol ajouté avec succès !\n");
    printf("******************************\n");

    return;
}

void reserverSieges(Vols vols[], int n) {
    int code;

    if (n == 0)
    {
        printf("Il n'y a aucun vol répertorié, il faudrait en ajouter un.\n");
        return;
    }

    printf("Réservation de siège\n");
    printf("******************************\n");

    printf("Entrez le code correspondant au vol en question : ");
    scanf("%d", code);

    
    
    for (int i = 0; i < n; i++)
    {
        /* code */
        if(vols[i].code == code) {
            if(vols[i].sieges > 0) {
                vols[i].sieges--;
                printf("******************************\n");
                printf("Réservation faite avec succès. Nombre de sièges disponibles : %d\n", vols[i].sieges);
                printf("******************************\n");
            }
            else
            {
                /* code */
                printf("Aucun siège disponible pour ce vol");
            }

            return;  
        }

    }
    printf("Le code %d ne correspond à aucun vol répertorié.\n", code);
    printf("******************************\n");

    return;
    
}

void annulerReservation(Vols vols[], int n) {
    int code;

    printf("Vous vouler annuler votre réservation ?\n");
    printf("******************************\n");

    printf("Entrez le code du vol correspondant à votre réservation : ");
    scanf("%d", code);

    for (int i = 0; i < n; i++)
    {
        if (vols[i].code == code)
        {
            vols[i].sieges++;
            printf("******************************\n");
            printf("Annulation de réservation effectuée avec succès. Nombre de sièges disponibles : %d\n", vols[i].sieges);
            printf("******************************\n");
        
            return;   
        }
        
    }

    printf("Le code %d ne correspond à aucun vol répertorié.\n", code);
    printf("******************************\n");

    return;

}


void afficherVols(Vols vols[], int n) {

    if (n == 0)
    {
        printf("Aucun vol répertorié.");
    }
    

    printf("Voici la liste des vols : ");
    printf("******************************\n");

    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("******************************\n");
        printf("Code : %d\n", vols[i].code);
        printf("Destination : %s\n", vols[i].destination);
        printf("Date : %s\n", vols[i].date);
        printf("Nombre de sièges disponibles : %d\n", vols[i].sieges);
        printf("******************************\n");
    }

    return;
    
}

void enregistrerVols(Vols vols[], int n, const char *nomDuFichier) {
    printf("Début de l'enregistrement....\n");

    FILE *fichier = fopen(nomDuFichier, "w");

    if (fichier == NULL)
    {
        /* code */
        printf("Une erreur s'est produite pendant l'ouverture du fichier.\n");
    }

    if(n == 0) {
        fprintf(fichier, "Aucun vol répertorié.");
        fclose(fichier);
    }

    for (int i = 0; i < n; i++)
    {
        /* code */
        fprintf(fichier, "******************\n");
        fprintf(fichier, "Code : %d\n", vols[i].code);
        fprintf(fichier, "Destination : %s\n", vols[i].destination);
        fprintf(fichier, "Date : %s\n", vols[i].date);
        fprintf(fichier, "Nombre de sièges disponibles : %d\n", vols[i].sieges);
        fprintf(fichier, "******************************\n");
    }
    
    fclose(fichier);
    printf("Données enregistrées avec succès dans %s\n", nomDuFichier);

    return;
    
}