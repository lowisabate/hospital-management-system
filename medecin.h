#ifndef MEDECIN_H
#define MEDECIN_H

#include "config.h"


typedef enum {
    PRESENTIEL,
    DISTANCE
} TypeConsultation;

typedef struct {
    int jour, mois, annee;
    int heure, minute;
    int idPatient;
    TypeConsultation type;
    char compteRendu[200];
} RendezVous;



typedef struct {
    int id;
    char nom[50];
    char specialite[50];
    Patient patients[MAX_PATIENTS];
    int nbPatients;
    RendezVous rdv[MAX_RDV];
    int nbRdv;
} Medecin;

/* Fonctions medecin */
void initialiserMedecin(Medecin *m);
void chargerRendezVous(Medecin *m);
void sauvegarderRendezVous(Medecin m);
void ajouterRendezVous(Medecin *m);
void afficherEmploiDuTemps(Medecin m);
void consulterADistance(Medecin *m);

#endif
