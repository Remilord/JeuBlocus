#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

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


int ChoisirJoueur(void) {
	/* Position du bouton 1 joueur */
	int nbj;
			if (SourisCliquee())  {
				if ((_Y >= Ymj1) && (_Y <= YMj1) && (_X >= Xmj) && ( _X <= XMj))  {
					nbj = 1;
					CopierZone ( 1,  0,  0,  0,  1000,  800,  0,  0); /* Copie l'image de L'écran invisible n°1 pour le mettre dans l'ecran visible*/

				}
			
	/* Position du bouton 2 Joueurs */

				if ((_Y >= Ymj2) && (_Y <= YMj2) && (_X >= Xmj) && ( _X <= XMj))  {
					nbj = 2;
					CopierZone ( 1,  0,  0,  0,  1000,  800,  0,  0); /* Copie l'image de L'écran invisible n°1 pour le mettre dans l'ecran visible*/

				}
			}
		return nbj;
	}

	int ChoisirCases (void)  {
		/* Affichage des images de selection du nombres de cases */
		int p,click=0,hj=0;
		char white;
		white = CouleurParNom("white");
			/* Fonction des possibilitées de clique sur les boutons de selection de cases */

			while(click==0) {
				if(SourisCliquee()) {
					for (p=0;p<7;p++) {
						if((_X>cliXm)&&(_X<cliXM)&&(_Y>cliYm)&&(_Y<cliYM)) { /*affiche les images de choix du nombres cases*/
						EffacerEcran(white);
						hj=hj+p;
						click=1;
						}
					}
				}	
			}
			hj=hj+3;
				return hj;
		}
	int ChoisirSkin(void) {
		int apparence=2,finselection=0;
		ChoisirEcran(2);
	ChargerImage("Bloquesapparence.png",0,0,0,0,imX,imY);
	ChargerImage("Flechegauche.png",0,350,0,0,300,300);
	ChargerImage("Flechedroite.png",700,350,0,0,300,300);
	ChargerImage("Classique.png",350,350,0,0,300,300);
	ChargerImage("continuer.png",350,600,0,0,100,50);
		CopierZone ( 2,  0,  0,  0,  1000,  800,  0,  0);
	ChoisirEcran(3);
	ChargerImage("Bloquesapparence.png",0,0,0,0,imX,imY);
	ChargerImage("Flechegauche.png",0,350,0,0,300,300);
	ChargerImage("Flechedroite.png",700,350,0,0,300,300);
	ChargerImage("Fightclub.png",350,350,0,0,300,300);
	ChargerImage("continuer.png",350,600,0,0,100,50);
	ChoisirEcran(4);
	ChargerImage("Bloquesapparence.png",0,0,0,0,imX,imY);
	ChargerImage("Flechegauche.png",0,350,0,0,300,300);
	ChargerImage("Flechedroite.png",700,350,0,0,300,300);
	ChargerImage("bloqua.png",350,350,0,0,300,300);
	ChargerImage("continuer.png",350,600,0,0,100,50);
	ChoisirEcran(0);
	while(finselection==0) {
		if(SourisCliquee()) {
			if((_X>=0)&&(_X<=300)&&(_Y>=350)&&(_Y<=650)&&(apparence>2)) {
				CopierZone(apparence-1,0,0,0,1000,800,0,0);
				apparence=apparence-1;
			}
			if((_X>=700)&&(_X<=1000)&&(_Y>=350)&&(_Y<=650)&&(apparence<4)) {
				CopierZone(apparence+1,0,0,0,1000,800,0,0);
				apparence=apparence+1;
			}
			if((_X>=350)&&(_X<=450)&&(_Y>=600)&&(_Y<=650)) {
				finselection=1;
			}

		}

	}
	ChoisirEcran(0);
return	apparence;
	}
	int AffichageRegles(void) {
		int r=0;
		ChoisirEcran(3);
	ChargerImage("Bloquesregles.png",0,0,0,0,imX,imY);
ChargerImage("continuer.png",350,600,0,0,100,50);
CopierZone(3,0,0,0,1000,800,0,0);
while(r==0) {
	if(SourisCliquee()) {
 if((_X>=350)&&(_X<=450)&&(_Y>=600)&&(_Y<=650)) {
				r=1;
			}
		}
}
ChoisirEcran(0);
return r;
	}
	int MenuFin (int defaite,int sk)  {
		int Findugame=0,boucle=0;
		ChoisirEcran(8);
		ChargerImage("écranfin.png",0,0,0,0,imX,imY);
		ChargerImage("quitter1.png",XmQ,YmQ,0,0,300,200);
		ChargerImage("rejouer.png",XmR,YmR,0,0,300,200);
		if ( defaite == 1)  {
			ChargerImage("vicj2.png",XT,XY,0,0,800,46);
		}

		if ( defaite == 2)  {
			ChargerImage("vicj1.png",XT,XY,0,0,800,46);
		}
		if (sk==3) {
			ChargerImage("interdit.png",XT,400,0,0,800,97);
		}
		CopierZone(8,0,0,0,1000,800,0,0);
		ChoisirEcran(0);
		while(boucle==0) {
		if (SourisCliquee())  {
			if ((_Y >= YmQ) && (_Y <= YMQ) && (_X >= XmQ) && ( _X <= XMQ))  {
				Findugame=1;
				boucle=1;
			}
			if ((_Y >= YmR) && (_Y <= YMR) && (_X >= XmR) && ( _X <= XMR))  {
				Findugame = 0;
				boucle=1;
			}
		}
	}
	return Findugame;
	}
	void PlacerImage(int i,int sk,int x,int y) {
		ChoisirEcran(0);
		if(sk==2) {
		switch(i) {
			case 1:
			ChargerImage("blocuspersobleu.png",x,y,0,0,24,37);
			break;
			case 2:
			ChargerImage("blocuscroixbleue.png",x,y,0,0,24,24);
			break;
			case 3:
			ChargerImage("blocuspersojaune.png",x,y,0,0,24,37);
			break;
			case 4:
			ChargerImage("blocuscroixjaune.png",x,y,0,0,24,24);
			break;
		}
	}
	if(sk==3) {
		switch(i) {
			case 1:
			ChargerImage("BradpittPion.png",x,y,0,0,24,37);
			break;
			case 2:
			ChargerImage("BPcroix.png",x,y,0,0,24,24);
			break;
			case 3:
			ChargerImage("SergePion.png",x,y,0,0,24,37);
			break;
			case 4:
			ChargerImage("SergeCroix.png",x,y,0,0,24,24);
			break;
		}
}
	if(sk==4) {
		switch(i) {
			case 1:
			ChargerImage("GringePion.png",x,y,0,0,24,37);
			break;
			case 2:
			ChargerImage("GringeCroix.png",x,y,0,0,24,24);
			break;
			case 3:
			ChargerImage("OrelsanPion.png",x,y,0,0,24,37);
			break;
			case 4:
			ChargerImage("OrelsanCroix.png",x,y,0,0,24,24);
			break;
		}
	}
	if(i==0) {
		ChargerImage("disable.png",x,y,0,0,24,37);
	}
}

/*void main(void)  {
	char white;
	int nbj=0,hj=0,sk=0,findumenu=0;
	InitialiserGraphique();
	white = CouleurParNom("white");
	CreerFenetre(0,0,fenX,fenY);
	ChargerImage("Bloquesjoueur.png",0,0,0,0,imX,imY);
	ChargerImage("joueur1.png",sX,sY1,0,0,200,100);
	ChargerImage("joueur2.png",sX,sY2,0,0,200,100);
	ChoisirEcran(1);
	ChargerImage("bloquesboutons.png",0,0,0,0,imX,imY);
	while (findumenu==0) {
		if(nbj==0) {
		nbj=ChoisirJoueur();
	}
	if((nbj!=0)&&(hj==0)) {
		hj=ChoisirCases();
	}
	if((hj!=0)&&(sk==0)) {
		sk=ChoisirSkin();
	}
	if(sk!=0) {
		findumenu=AffichageRegles();
	}
	}
	
}*/


