#include <stdio.h>
#include <string.h>
#include "medecin.h"

void initialiserMedecin(Medecin *m) {
    printf("Nom du medecin : ");
    scanf("%s", m->nom);
    printf("Specialite : ");
    scanf("%s", m->specialite);
    m->nbRdv = 0;
}

void ajouterRendezVous(Medecin *m) {
    RendezVous r;
    int choix;

    printf("Date (jj mm aaaa) : ");
    scanf("%d %d %d", &r.jour, &r.mois, &r.annee);
    printf("Heure (hh min) : ");
    scanf("%d %d", &r.heure, &r.minute);
    printf("ID patient : ");
    scanf("%d", &r.idPatient);

    printf("Type (0:Presentiel 1:Distance) : ");
    scanf("%d", &choix);
    r.type = (choix == 1) ? DISTANCE : PRESENTIEL;
    strcpy(r.compteRendu, "N/A");

    m->rdv[m->nbRdv++] = r;
}

void consulterADistance(Medecin *m) {
    int id;
    printf("ID patient : ");
    scanf("%d", &id);
    getchar();
    int i;

    for ( i = 0; i < m->nbRdv; i++) {
        if (m->rdv[i].idPatient == id &&
            m->rdv[i].type == DISTANCE) {

            printf("Compte rendu : ");
            fgets(m->rdv[i].compteRendu, 200, stdin);
            printf("Teleconsultation enregistree.\n");
            return;
        }
    }
    printf("Aucune teleconsultation trouvee.\n");
}

void afficherEmploiDuTemps(Medecin m) {
	int i;
    for (i = 0; i < m.nbRdv; i++) {
        printf("%02d/%02d/%d %02d:%02d | Patient %d | %s\n",
            m.rdv[i].jour, m.rdv[i].mois, m.rdv[i].annee,
            m.rdv[i].heure, m.rdv[i].minute,
            m.rdv[i].idPatient,
            m.rdv[i].type == DISTANCE ? "Distance" : "Presentiel");
    }
}

void sauvegarderRendezVous(Medecin m) {
    FILE *f = fopen("rdv_medecin.txt", "w");
    if (f == NULL) {
        printf("Erreur sauvegarde RDV.\n");
        return;
    }
	int i;
    for ( i = 0; i < m.nbRdv; i++) {
        fprintf(f, "%d %d %d %d %d %d\n",
                m.rdv[i].jour,
                m.rdv[i].mois,
                m.rdv[i].annee,
                m.rdv[i].heure,
                m.rdv[i].minute,
                m.rdv[i].idPatient);
    }

    fclose(f);
}

void chargerRendezVous(Medecin *m) {
    FILE *f = fopen("rdv_medecin.txt", "r");
    if (f == NULL) return;

    m->nbRdv = 0;
    while (fscanf(f, "%d %d %d %d %d %d",
           &m->rdv[m->nbRdv].jour,
           &m->rdv[m->nbRdv].mois,
           &m->rdv[m->nbRdv].annee,
           &m->rdv[m->nbRdv].heure,
           &m->rdv[m->nbRdv].minute,
           &m->rdv[m->nbRdv].idPatient) != EOF) {
        m->nbRdv++;
    }

    fclose(f);
}
