// ----------------------------------------------------------
//                - Amédée Wend-Bénédo DERA -
	    /*       	o-o   o--o o--o    O
					|  \  |    |   |  / \
					|   O O-o  O-Oo  o---o
					|  /  |    |  \  |   |
			    	o-o   o--o o   o o   o

		*/
// ----------------------------------------------------------
//         MIAGE - Semestre 3 - Complextité des Algorithmes
// ----------------------------------------------------------
// ----------------------------------------------------------
//                          IBAM


// Bibiliotèques utilisées
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
/* Informations personnelles (listes des couleurs)
0 : Noir
1 : Bleu foncé
2 : Vert foncé
3 : Turquoise
4 : Rouge foncé
5 : Violet
6 : Vert caca d'oie
7 : Gris clair
8 : Gris foncé
9 : Bleu fluo
10 : Vert fluo
11 : Turquoise
12 : Rouge fluo
13 : Violet 2
14 : Jaune
15 : Blanc
*/
// Variable globale

int choix=0;

void menu(){
	printf("\n");
	printf("\n");
    Color(9, 0);
	printf("\n");
	printf(" .-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+. \n");
	printf("| .*********************************. |\n");
	printf("| |     Utilisez les lettres        | |\n");
	printf("| |   H, B, D et G pour jouer.      | |\n");
	Color(12, 0);
	printf("* *    Votre deplacement doit       * *\n");
	printf("* *   etre valide et faisable       * *\n");
	Color(9, 0);
	printf("| |                                 | |\n");
	printf("| |     Taper sur la touche 1       | |\n");
	printf("| |   pour commencer la partie      | |\n");
	printf("| |                                 | |\n");
	printf("| '*********************************' |\n");
	printf("'-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+' \n");
	printf("\n");
	printf("\n");
	Color(15, 0);
}



// Fonction qui génère une grille aleatoire
void Grille (int largeur, int hauteur)
{
	// Déclarations
    int nb_cases = largeur * hauteur;
    int *tab = NULL, *tmp_tab = NULL;
    int i, n, nb_changements;
    int x, tmp;
    int similitude;
    int cpt = -1;
    tab = malloc(nb_cases* sizeof *tab), tmp_tab = malloc(nb_cases * sizeof *tab);
    char saisie;
	//int H,G,B,D; //int saisie;
    int boucle=1;

    do
    {
        nb_changements = 0;
        // Initialise le tableau
        for ( i=0 ; i<nb_cases ; i++ )
        {
            tab[i] = i;
        }
        // Le génère aléatoirement
        for ( i=0 ; i<nb_cases ; i++ )
        {
            x = i + (rand() % (nb_cases-i));
            tmp = tab[i];
            tab[i] = tab[x];
            tab[x] = tmp;
        }
        // cherche les similitudes
        for ( i=0; tab[i] != 0; i++ );
        similitude = (largeur-1) + (hauteur-1) - ((i/largeur) + (i%largeur));
        // copie du tableau pour comptage
        memcpy(tmp_tab, tab, nb_cases * sizeof *tab);
        // On positionne 0 en fin
        if (i < nb_cases-1)
        {
            tmp = tmp_tab[nb_cases-1];
            tmp_tab[nb_cases-1] = tmp_tab[i];
            tmp_tab[i] = tmp;
            nb_changements++;
        }
        // comptage des changements restants
        for ( i=nb_cases-1; i>0; i-- )
        {
            if (tmp_tab[i-1] < i)
            {
                for (n=i-1; n>=0; n--)
                {
                    if (tmp_tab[n] == i)
                    {
                        tmp = tmp_tab[n];
                        tmp_tab[n] = tmp_tab[i-1];
                        tmp_tab[i-1] = tmp;
                        nb_changements++;
                    }
                }
            }
        }
    }
    while (((nb_changements%2)^(similitude%2)));


    // Affichage du tableau melangé

 	printf("       0    1    2    3\n");
    for ( i=0 ; i<nb_cases ; i++ )
    {
        if (!(i%largeur))
        {
            printf("\n");
            printf("      ----+----+----+----\n");
            printf("%2i   |", cpt = cpt +1);
        }
        printf(" %2i |", tab[i]);
    }
    printf("\n");
    printf("      ----+----+----+----\n");
    cpt =-1;


    // Boucle qui permet de jouer tant que la grille n'est pas dans la position gagnante
    do
    {
    	for(i=0 ; i<nb_cases; i++)
    	{
	        if(tab[i]==0)
	        {

				//Initilisation des touches H B G et D
				/*H = tab[i-4];
				B = tab[i+4];
				G = tab[i-1];
				D = tab[i+1];*/

	            printf("\nVotre coup ? ((H)aut, (B)as, (G)auche, (D)roit) :");
	            scanf("%s", &saisie);
	            // Si la saisie est égale au chiffre situé à gauche
	       		if(saisie=='G')
	       		{
	       			// Echange la case de gauche avec le zéro
	       			tab[i]=tab[i-1];
	       			// Réinitialise la case à 0
	       			tab[i-1]=0;
	       			// Et réimprime le tableau
	       			printf("       0    1    2    3\n");
	       			for ( i=0 ; i<nb_cases ; i++ )
					   {
					       if (!(i%largeur))
					        {
					            printf("\n");
					            printf("      ----+----+----+----\n");
					            printf("%2i   |", cpt = cpt +1);
					        }
					        printf(" %2d |", tab[i]);
					   }
					   printf("\n");
					   printf("      ----+----+----+----\n");
					   printf("\n");
					   tab[i]=0;
					   cpt = -1;
				}
				else if(saisie=='H')
	       		{
	       			// Echange la case du haut avec le zéro
	       			tab[i]=tab[i-4];
	       			// Réinitialise la case à 0
					tab[i-4]=0;
					// Et réimprime le tableau
	       			printf("       0    1    2    3\n");
	       			for ( i=0 ; i<nb_cases ; i++ )
					   {
					       if (!(i%largeur))
					        {
					            printf("\n");
					            printf("      ----+----+----+----\n");
					            printf("%2i   |", cpt = cpt +1);
					        }
					        printf(" %2d |", tab[i]);
					   }
					   printf("\n");
					   printf("      ----+----+----+----\n");
					   printf("\n");
					   tab[i]=0;
					   cpt = -1;
				}
				else if(saisie=='D')
	       		{
	       			// Echange la case de droite avec le zéro
	       			tab[i]=tab[i+1];
	       			// Réinitialise la case à 0
	       			tab[i+1]=0;
	       			// Et réimprime le tableau
	       			printf("       0    1    2    3\n");
	       			for ( i=0 ; i<nb_cases ; i++ )
					   {
					       if (!(i%largeur))
					        {
					            printf("\n");
					            printf("      ----+----+----+----\n");
					            printf("%2i   |", cpt = cpt +1);
					        }
					        printf(" %2d |", tab[i]);
					   }
					   printf("\n");
					   printf("      ----+----+----+----\n");
					   printf("\n");
					   tab[i]=0;
					   cpt = -1;
				}
				else if(saisie=='B')
	       		{
	       			// Echange la case du bas avec le zéro
	       			tab[i]=tab[i+4];
	       			// Réinitialise la case à 0
	       			tab[i+4]=0;
	       			// Et réimprime le tableau
	       			printf("       0    1    2    3\n");
	       			for ( i=0 ; i<nb_cases ; i++ )
					   {
					       if (!(i%largeur))
					        {
					            printf("\n");
					            printf("      ----+----+----+----\n");
					            printf("%2i   |", cpt = cpt +1);
					        }
					        printf(" %2d |", tab[i]);
					   }
					   printf("\n");
					   printf("      ----+----+----+----\n");
					   printf("\n");
					   tab[i]=0;
					   cpt= -1;
				}
				else {
					printf("Veuillez entrer une lettre valide");
				}

				// Position gagnante
				 if(tab[15]==0 && tab[14]==15 && tab[13]==14 && tab[12]==13 && tab[11]==12 && tab[10]==11 && tab[9]==10 && tab[8]==9 && tab[7]==8 && tab[6]==7 && tab[5]==6 && tab[4]==5 && tab[3]==4 && tab[2]==3 && tab[1]==2 && tab[0]==1)
				   	{
				   		// On met la boucle à 2 pour sortir du while
				   		boucle = 2;


				    }



       		}


        }

    }
    while(boucle==1);

    printf("\n\n Bravo! Vous avez résolu le Taquin !!!\n");
    // libère la mémoire
    free(tmp_tab);
    free (tab);
}



// Fonction principale

int main(void){

   	int count=1;

   	// Affiche le menu tant que count est égale à 1
	while(count==1){
	    menu();

	    printf(" Veuillez entrer votre choix : ");
		scanf("%i", &choix);

	    while(choix!=1){
	    	printf("\n Veuillez entrer votre choix une nouvelle fois:");
	    	scanf("%i", &choix);
	    }

	    // Affiche le jeu
	    if (choix==1){
	    	srand(time(NULL));
	    	Grille (4,4);
	    	printf("\n");
	    	return 0;

	    }
	    // Affiche le jeu
	    else{

	    	printf("\n Veuillez taper la touche 1 ");


	    }

	}

}
