#include <stdio.h>
#include "vols.h"
#define MAX_SIZE 100


int main() {
    Vols vols[MAX_SIZE];
    int nbVols = 0;
    int choice;
    const char* nomDuFichier = "informations_vols.txt";

    
    do {
        printf("\nGestion de vols :\n");
        printf("1. Ajouter un vol\n");
        printf("2. Réserver un siège\n");
        printf("3. Annuler une réservation\n");
        printf("4. Afficher les vols\n");
        printf("5. Enregistrer les informations sur les vols\n");
        printf("6. Quitter\n");

        printf("******************************\n");
        printf("Votre choix: ");
        scanf("%d", &choice);
        printf("******************************\n");

        switch (choice)
        {
        case 1:
            ajouterVols(vols, &nbVols);
            nbVols++;  // Incrémentation après l'ajout
            break;
        
        case 2:
            reserverSiege(vols, nbVols);
            break;
        
        case 3:
            annulerReservation(vols, nbVols);
            break;

        case 4:
            afficherVols(vols, nbVols);
            break;

        case 5:
            enregistrerVols(vols, nbVols, nomDuFichier);
            break;

        case 6:
            printf("Okay, à plus tard.");
            break;

        default:
            printf("Choix invalide, veuillez réésayer.\n");
            break;
        }
    }
    while(choice < 1 && choice > 6);


    return 0;
}