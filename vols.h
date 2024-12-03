#ifndef VOL_H
#define VOL_H


typedef struct 
{
    /* data */
    int code;
    char destination[200];
    char date[20];
    int sieges;
}Vols;


void ajouterVols(Vols vols[], int *n);
void reserverSiege(Vols vols[], int n);
void annulerReservation(Vols vols[], int n);
void afficherVols(Vols vols[], int n);
void enregistrerVols(Vols vols[], int n, const char *nomDuFichier);

#endif
