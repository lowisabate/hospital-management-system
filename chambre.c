#include <stdio.h>
#include "chambre.h"

/*
  0 : chambre libre
  1 : chambre occupée
*/
static int chambres[NB_CHAMBRES];

/* Initialisation des chambres */
void initialiserChambres()
{
    int i;
    for (i = 0; i < NB_CHAMBRES; i++)
    {
        chambres[i] = 0;
    }
}

/* Attribution d'une chambre */
int attribuerChambre()
{
    int i;
    for (i = 0; i < NB_CHAMBRES; i++)
    {
        if (chambres[i] == 0)
        {
            chambres[i] = 1;
            return i; // chambre trouvée
        }
    }

    // Toutes les chambres sont occupées
    return -1;
}

/* Libération d'une chambre */
void libererChambre(int numero)
{
    if (numero >= 0 && numero < NB_CHAMBRES)
    {
        chambres[numero] = 0;
    }
    else
    {
        printf("Erreur : numéro de chambre invalide.\n");
    }
}

/* Affichage de l'état des chambres */
void afficherEtatChambres()
{
    int i;
    printf("\nEtat des chambres :\n");
    for (i = 0; i < NB_CHAMBRES; i++)
    {
        if (chambres[i] == 0)
            printf("Chambre %d : Libre\n", i);
        else
            printf("Chambre %d : Occupee\n", i);
    }
}

