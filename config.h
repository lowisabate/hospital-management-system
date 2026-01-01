// j'utilise ce fichier d'en tete pour pouvoir éviter les problemes de redefinition de constantes
#ifndef CONSTANTES_H
#define CONSTANTES_H

#define MAX_PATIENTS 100
#define MAX_RDV 50

typedef struct {
    int id;
    char nom[50];
    int age;
} Patient;

#endif
