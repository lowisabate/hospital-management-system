#ifndef CHAMBRE_H
#define CHAMBRE_H

#define NB_CHAMBRES 5   // Ressource volontairement limitée

void initialiserChambres();
int attribuerChambre();
void libererChambre(int numero);
void afficherEtatChambres();

#endif

