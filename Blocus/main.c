#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "gameplay.h"
#include "menu.h"

#define fenX 1000 /* largeur de la fenetre */
#define fenY 800 /* hauteur de la fenetre  */
#define imX 1000 /* largeur de l'image de fond */
#define imY 800 /* hauteur de l'image de fond */
#define sX 400 /* position X à partir desquelles sont affichés les sprites "joueur 1" et "joueur 2" */
#define sY1 400 /* position Y à partir de laquelle le sprite "joueur 1" est affiché */
#define sY2 600 /* position Y à partir de laquelle le sprite "joueur 2" est affiché */
#define imX3 150 /* position X à partir de laquelle l'image 3*3 s'affiche */
#define imX4 250 /* position X à partir de laquelle l'image 4*4 s'affiche */
#define imX5 350 /* position X à partir de laquelle l'image 5*5 s'affiche */ 
#define imX6 450 /* position X à partir de laquelle l'image 6*6 s'affiche */
#define imX7 550 /* position X à partir de laquelle l'image 7*7 s'affiche */
#define imX8 650 /* position X à partir de laquelle l'image 8*8 s'affiche */
#define imX9 750 /* position X à partir de laquelle l'image 9*9 s'affiche */
#define im_Y 450 /* position Y à partir de laquelle les images s'affichent */
#define cim 50 /* valeur des cotes des images de selection du nombres de cases */
#define cliXm 150+100*p /* valeurs de X minimum pour pouvoir cliquer sur les boutons de selections du nombres de cases */
#define cliXM 200+100*p /* valeurs de X maximum pour pouvoir cliquer sur les boutons de selections du nombres de cases */
#define cliYm 450 /* valeurs de Y minimum pour pouvoir cliquer sur les boutons de selections du nombres de cases */
#define cliYM 500 /* valeurs de Y maximum pour pouvoir cliquer sur les boutons de selections du nombres de cases */
#define XMj 600 /* Position X maximum pour les boutons de selection du nombre de joueurs  */
#define Xmj 400 /* Position X minimum pour les boutons de selection du nombre de joueurs  */
#define Ymj1 400 /* Position Y minimum pour le bouton 1 joueur */
#define YMj1 500 /* Position Y maximum pour le bouton 1 joueur */
#define Ymj2 600 /* position Y minimum pour le bouton 2 joueurs */
#define YMj2 700 /* position Y maximum pour le bouton 2 joueurs  */
#define YmQ 500 /* position Y minimum pour le bouton "QUITTER" */
#define YMQ 700 /* position Y maximum pour le bouton "QUITTER" */
#define XmQ 100 /* position X minimum pour le bouton "QUITTER" */
#define XMQ 400 /* position X maximum pour le bouton "QUITTER" */
#define YmR 500 /* position Y minimum pour le bouton "REJOUER" */
#define YMR 700 /* position Y maximum pour le bouton "REJOUER" */
#define XmR 600 /* position X minimum pour le bouton "REJOUER" */
#define XMR 900 /* position X maximum pour le bouton "REJOUER" */
#define XT 200 /* Position X pour l'affichage du texte */
#define XY 200 /* position Y pour l'affichage du texte */

int main(void)  {
	int nbj,hj,sk,findumenu,hk;
	int x,va1,va2,vaj1,vaj2,defaite;
	int tab1[2][10];
	int tab2[2][10];
	int tab3[11][11];
	int tab4[2],tab5[2];
	int findugame=0;
	while(findugame==0) {
    defaite=0,nbj=0,hj=0,sk=0,findumenu=0,hk=0;
    x=0,defaite=0;
	InitialiserGraphique();
	CreerFenetre(0,0,fenX,fenY);
	ChargerImage("Bloquesjoueur.png",0,0,0,0,imX,imY);
	ChargerSprite("joueur1.png");
	AfficherSprite(1,sX,sY1);
	ChargerSprite("joueur2.png");
	AfficherSprite(2,sX,sY2);
	ChoisirEcran(1);
	ChargerImage("bloquesboutons.png",0,0,0,0,imX,imY);
	while (findumenu==0) {
		if(nbj==0) {
		nbj=ChoisirJoueur();
	}
	if((nbj!=0)&&(hj==0)) {
		hj=ChoisirCases();
		va1=hj;
		va2=hj;
		vaj1=hj;
		vaj2=hj;
	}
	if((hj!=0)&&(sk==0)) {
		sk=ChoisirSkin();
	}
	if(sk!=0) {
		findumenu=AffichageRegles();
	}
	}
	if(hk==0) {
	ChoisirEcran(7);
	ChargerImage("Blocusg.png",0,0,0,0,1000,800);
	CopierZone(7,0,0,0,1000,800,0,0);
	hk=hk+1;
}
	ChoisirEcran(0);
	RemplirTableaux(tab1,tab2,tab3,hj);
	PremierTour(tab1,tab2,tab3,tab4,tab5,hj,&va1,&va2,&vaj1,&vaj2,nbj,sk);
	x=x+2;
	while(defaite==0)  {
 defaite=TourJoueur1(tab1,tab2,tab3,tab4,hj,&x,&va1,&va2,sk);
 if (nbj==1) {
 	defaite=TourJoueur2IA(tab1,tab2,tab3,tab5,hj,&x,&vaj1,&vaj2,sk);
 }
 if (nbj==2) {
defaite=TourJoueur2(tab1,tab2,tab3,tab5,hj,&x,&vaj1,&vaj2,sk);
}
}
findugame=MenuFin(defaite,sk);
LibererSprite(1);
LibererSprite(2);
FermerGraphique();
}
return EXIT_SUCCESS;
}
