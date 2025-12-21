#include <iostream>
#include<stdio.h>
#define MAX_NOM 50
#define MAX_SPEC 30

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// structure medecin
typedef struct {
	int id;
	char nom[MAX_NOM];
	char prenom[MAX_NOM];
	char specialite[MAX_SPEC];
	int disponible; // 1 pour disponible ET 0 pour indisponible
}Medecin;

void ajouterMedecin(int id) {
    
    FILE *f=fopen("informations du patient.txt","a");
				     if (f == NULL) {
				      printf("Nous n'avons pas pu ouvrir le fichier correspondant a vos informations \n");
				      return ;
				     };
	Medecin m;

    m.id = id;
	printf("ID du medecin ");
	scanf("%d", &m.id);
	//fprintf(f," %s    ",m.id);
    printf("Nom du medecin : ");
    scanf("%s", m.nom);
	//fprintf(f," %s    ",m.nom)
    printf("Prenom du medecin : ");
    scanf("%s", m.prenom);
	//fprintf(f," %s    ",m.prenom);
    printf("Specialite : ");
    scanf("%s", m.specialite);
    //fprintf(f,"  %s   ",m.specialite);

    m.disponible = 1; // disponible par defaut
    
    fprintf(f,
    "ID : %d\n"
    "Nom : %s\n"
    "Prenom : %s\n"
    "Specialite : %s\n"
    "Disponibilite : %s\n"
    "--------------------------------------\n",
    m.id,
    m.nom,
    m.prenom,
    m.specialite,
    m.disponible ? "Disponible" : "Indisponible");
    fclose(f);
    
    printf("Medecin enregistre avec succes. \n");

    
}

int main(int argc, char** argv) {
	int id;
	ajouterMedecin(id);
	return 0;
}
	/*void ShowMedecin(){
		Ligne();
		printf("\n                         LISTE DES MEDECINS DISPONIBLES SUIVIS DE LEURS NUMEROS DE TELEPHONES RESPECTIFS\n\n");
		Ligne();
	
		printf("\n************************************MEDECINS GENERALISTES****************************************************\n");
		printf("1. Dr LOWIS ABATE  - 123456\n");
		printf("2. Dr MACK ABOUGOU - 123457\n");
		printf("3. Dr FLORE ABAMOU  - 123458\n");
			
		printf("\n*************************************MEDECINS SPECIALISTES***************************************************\n");
		printf("1.Neurologie:  Dr KARMEN FOTSO 654123\n");
		printf("2.Carlogie:  Dr LOVELINE DONANG 654122\n");
		printf("3.Dermatologie: Dr ANDY NGONO 654133\n");
		printf("4.Pneumologie:  Dr GAEL  MINKOMA 654132\n");
		printf("5.Pediatrie:  Dr  SYLVANIE MFOMO 654321\n");
		printf("\nDisponibles du Lundi au Vendredi de 10H a 17H.\n");
		printf("\n Appuyez sur ENTRER pour revenir au menu...");
	
	} */
