#include <stdio.h>
#include "patient.h"
#include "medecin.h"

Patient patients[MAX_PATIENTS];
int nbPatients = 0;

void ajouterPatientMedecin(Medecin *m) {
    if (nbPatients >= MAX_PATIENTS) {
        printf("Base de patients pleine !\n");
        return;
    }

    Patient p;
    printf("ID patient : ");
    scanf("%d", &p.id);
    printf("Nom patient : ");
    scanf("%s", p.nom);
    printf("Age : ");
    scanf("%d", &p.age);

    patients[nbPatients] = p;   // BASE GLOBALE
    nbPatients++;

    printf("Patient ajoute avec succes.\n");
}
void afficherPatients(void) {
    if (nbPatients == 0) {
        printf("Aucun patient.\n");
        return;
    }
	int i;
    for ( i = 0; i < nbPatients; i++) {
        printf("ID:%d | %s | %d ans\n",
               patients[i].id,
               patients[i].nom,
               patients[i].age);
    }
}
int patientExiste(int id) {
    int i;
    for (i = 0; i < nbPatients; i++) {
        if (patients[i].id == id)
            return 1;
    }
    return 0;
}

void chargerPatients() {
    FILE *f = fopen("patients.txt", "r");
    if (f == NULL) return;   // normal au premier lancement

    nbPatients = 0;
    while (fscanf(f, "%d %s %d",
           &patients[nbPatients].id,
           patients[nbPatients].nom,
           &patients[nbPatients].age) != EOF) {
        nbPatients++;
    }

    fclose(f);
}



void sauvegarderPatients() {
    FILE *f = fopen("patients.txt", "w");
    if (f == NULL) {
        printf("Erreur sauvegarde patients.\n");
        return;
    }
	int i;
    for ( i = 0; i < nbPatients; i++) {
        fprintf(f, "%d %s %d\n",
                patients[i].id,
                patients[i].nom,
                patients[i].age);
    }

    fclose(f);
}
