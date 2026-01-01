#ifndef PATIENT_H
#define PATIENT_H
#include "config.h"
#include"medecin.h"





/* Base globale de patients */
extern Patient patients[MAX_PATIENTS];
extern int nbPatients;

/* Fonctions */

void afficherPatients();
void chargerPatients(); 
void ajouterPatientMedecin(Medecin *m);
int patientExiste(int id);
#endif
