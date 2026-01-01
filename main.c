#include <stdio.h>
#include "patient.h"
#include "medecin.h"

int main() {
    Medecin m;
    int choix;

    chargerPatients();
    initialiserMedecin(&m);

    printf("\nBonjour Dr %s :)\n", m.nom);

    do {
    	printf("\n1. Ajouter un patient");
    	printf("\n2. Liste des patients");
        printf("\n3. Ajouter rendez-vous");
        printf("\n4. Afficher emploi du temps");
        printf("\n5. Teleconsultation");
        printf("\n0. Deconnexion\nChoix : ");
        scanf("%d", &choix);

        switch (choix) {
        	case 1:ajouterPatientMedecin(&m);
			sauvegarderPatients();
			 break;
            case 2: afficherPatients(); break;
            case 3: ajouterRendezVous(&m); break;
            case 4: afficherEmploiDuTemps(m); break;
            case 5: consulterADistance(&m); break;
        }
    } while (choix != 0);

    
    sauvegarderRendezVous(m);
    printf("Au revoir Dr %s.\n", m.nom);
    return 0;
}
