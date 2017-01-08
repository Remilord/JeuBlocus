#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "menu.h"
int ConditionDefaite(int tab3[11][11],int j) {
	int w,d,defaite=0;
	 for(w=0;w<=j;w++) {
 	for(d=0;d<=j;d++) {
 		if (tab3[w][d]==-2) {
 			if((tab3[w-1][d-1]<0)&&(tab3[w-1][d]<0)&&(tab3[w-1][d+1]<0)&&(tab3[w][d-1]<0)&&(tab3[w][d]<0)&&(tab3[w][d+1]<0)&&(tab3[w+1][d-1]<0)&&(tab3[w+1][d]<0)&&(tab3[w+1][d+1])) {
 				defaite=1;
 				return	defaite;
 				
 			}
 		}
 	}
 }
	 for(w=0;w<=j;w++) {
 	for(d=0;d<=j;d++) {
 		if (tab3[w][d]==-3) {
 			if((tab3[w-1][d-1]<0)&&(tab3[w-1][d]<0)&&(tab3[w-1][d+1]<0)&&(tab3[w][d-1]<0)&&(tab3[w][d]<0)&&(tab3[w][d+1]<0)&&(tab3[w+1][d-1]<0)&&(tab3[w+1][d]<0)&&(tab3[w+1][d+1])) {
 				defaite=2;
 				return defaite;
 				
 			}
 		}
 	}
 }
 	return defaite;

}
void RemplirTableaux(int tab1[2][10],int tab2[2][10],int tab3[11][11],int j) {
	int x,y,z,k,a,i;
	z=1000/j;
	k=800/j;
	a=j+1;
	for(i=1;i<j;i++) {
	DessinerSegment(i*z,0,i*z,800);
	DessinerSegment(0,i*k,1000,i*k);
	}
		for(x=0;x<=j;x++) {
		tab1[0][x]=z*x;
	}
	for(y=0;y<=j;y++) {
		tab1[1][y]=k*y;
	}
		for(x=0;x<j;x++) {
			tab2[0][x]=(tab1[0][x])+(z/2);
		}
		for(y=0;y<j;y++) {
			tab2[1][y]=(tab1[1][y])+(k/2);
		}
		for(x=0;x<=a;x++) {
				tab3[0][x]=-5;
				tab3[x][0]=-5;
				tab3[a][x]=-5;
				tab3[x][a]=-5;
			}

		for(x=1;x<a;x++) {
			for(y=1;y<a;y++) {
				tab3[x][y]=0;
			}
		}

}
void PremierTour(int tab1[2][10],int tab2[2][10],int tab3[11][11],int tab4[2],int tab5[2],int j,int* va1,int* va2,int* vaj1,int* vaj2,int nbj,int sk) {
 int x=0,v1,v2,ia1=0,ia2=0;
 ChargerImage("effacertexte.png",0,800,0,0,800,100);
 EcrireTexte(50, 850, "Le joueur 1 doit placer son pion ", 2);
while (x==0) {
	
		if(SourisCliquee()) {
					for(v1=*va1-j;v1<=*va1+1;v1++) {
						if((_X>tab1[0][v1])&&(_X<tab1[0][v1+1])) {
							for(v2=*va2-j;v2<=*va2+1;v2++) {
								if((_Y>tab1[1][v2])&&(_Y<tab1[1][v2+1])&&(tab3[v1+1][v2+1]>=0)) {
				PlacerImage(1,sk,tab2[0][v1]-12,tab2[1][v2]-18);
				x=x+1;
				tab3[v1+1][v2+1]=-2;
				*va1=v1;
				*va2=v2;
				tab4[0]=tab2[0][v1];
				tab4[1]=tab2[1][v2];
		}}}}}}
		ChargerImage("effacertexte.png",0,800,0,0,800,100);

		EcrireTexte(50, 850, "Le joueur 2 doit placer son pion ", 2);
		while(x==1) {
		if(SourisCliquee()&&(nbj==2)) {
				for(v1=*vaj1-j;v1<=*vaj1+1;v1++) {
						if((_X>tab1[0][v1])&&(_X<tab1[0][v1+1])) {
							for(v2=*vaj2-j;v2<=*vaj2+1;v2++) {
								if((_Y>tab1[1][v2])&&(_Y<tab1[1][v2+1])&&(tab3[v1+1][v2+1]>=0)) {
			PlacerImage(3,sk,tab2[0][v1]-12,tab2[1][v2]-18);
			x=x+1;
				tab3[v1+1][v2+1]=-3;
				*vaj1=v1;
				*vaj2=v2;
				tab5[0]=tab2[0][v1];
				tab5[1]=tab2[1][v2];
		}
		}}}}
		if(nbj==1) {
			srand(time(NULL));
			ia1=rand()%1001;
			ia2=rand()%801;
			for(v1=*vaj1-j;v1<=*vaj1+1;v1++) {
						if((ia1>tab1[0][v1])&&(ia1<tab1[0][v1+1])) {
							for(v2=*vaj2-j;v2<=*vaj2+1;v2++) {
								if((ia2>tab1[1][v2])&&(ia2<tab1[1][v2+1])&&(tab3[v1+1][v2+1]>=0)) {
			PlacerImage(3,sk,tab2[0][v1]-12,tab2[1][v2]-18);
			x=x+1;
				tab3[v1+1][v2+1]=-3;
				*vaj1=v1;
				*vaj2=v2;
				tab5[0]=tab2[0][v1];
				tab5[1]=tab2[1][v2];
		}
		}}}

		}
}
}
int TourJoueur1(int tab1[2][10],int tab2[2][10],int tab3[11][11],int tab4[2],int j,int* x,int* va1,int* va2,int sk) {
	int v1,v2;
	int defaite;
	EcrireTexte(50, 850, "Le joueur 1 doit bouger son pion ", 2);
	 while (*x==2) {
		if(SourisCliquee()) {
					for(v1=*va1-1;v1<=*va1+1;v1++) {
						if((_X>tab1[0][v1])&&(_X<tab1[0][v1+1])) {
							for(v2=*va2-1;v2<=*va2+1;v2++) {
								if((_Y>tab1[1][v2])&&(_Y<tab1[1][v2+1])&&(tab3[v1+1][v2+1]>=0)) {
								PlacerImage(0,sk,tab4[0]-12,tab4[1]-18);
								tab3[*va1+1][*va2+1]=0;
				PlacerImage(1,sk,tab2[0][v1]-12,tab2[1][v2]-18);
				*x=*x+1;
				tab3[v1+1][v2+1]=-2;
				*va1=v1;
				*va2=v2;
				tab4[0]=tab2[0][v1];
				tab4[1]=tab2[1][v2];
		}}}}}
		defaite=ConditionDefaite(tab3,j);
		 if(defaite !=0) {
 	return defaite;
 }
	}

		ChargerImage("effacertexte.png",0,800,0,0,800,100);

	EcrireTexte(50, 850, "Le joueur 1 doit placer sa croix", 2);
while(*x==3) {
	if(SourisCliquee()) {
		for(v1=0;v1<j;v1++) {
						if((_X>tab1[0][v1])&&(_X<tab1[0][v1+1])) {
							for(v2=0;v2<j;v2++) {
								if((_Y>tab1[1][v2])&&(_Y<tab1[1][v2+1])&&(tab3[v1+1][v2+1]>=0)) {
		PlacerImage(2,sk,tab2[0][v1]-12,tab2[1][v2]-12);
		*x=*x+1;
		tab3[v1+1][v2+1]=-1;
	}
}
 	}}}
 defaite=ConditionDefaite(tab3,j);
		 if(defaite !=0) {
 	return defaite;
 }}
 	ChargerImage("effacertexte.png",0,800,0,0,800,100);
 		return defaite;

}
int TourJoueur2(int tab1[2][10],int tab2[2][10],int tab3[11][11],int tab5[2],int j,int* x,int* vaj1,int* vaj2,int sk) {
	int v1,v2;
	int defaite;
	EcrireTexte(50, 850, "Le joueur 2 de deplacer son pion ", 2);
 	while (*x==4) {
		if(SourisCliquee()) {
				for(v1=*vaj1-1;v1<=*vaj1+1;v1++) {
						if((_X>tab1[0][v1])&&(_X<tab1[0][v1+1])) {
							for(v2=*vaj2-1;v2<=*vaj2+1;v2++) {
								if((_Y>tab1[1][v2])&&(_Y<tab1[1][v2+1])&&(tab3[v1+1][v2+1]>=0)) {
								PlacerImage(0,sk,tab5[0]-12,tab5[1]-18);
								tab3[*vaj1+1][*vaj2+1]=0;
			PlacerImage(3,sk,tab2[0][v1]-12,tab2[1][v2]-18);
			*x=*x+1;
				tab3[v1+1][v2+1]=-3;
				*vaj1=v1;
				*vaj2=v2;
				tab5[0]=tab2[0][v1];
				tab5[1]=tab2[1][v2];
		}
		}}}}
		defaite=ConditionDefaite(tab3,j);
		 if(defaite !=0) {
 	return defaite;
 }
}
		ChargerImage("effacertexte.png",0,800,0,0,800,100);
 	EcrireTexte(50, 850, "Le joueur 2 doit placer sa croix", 2);
	while(*x==5) {
		if(SourisCliquee()) {
			for(v1=0;v1<j;v1++) {
						if((_X>tab1[0][v1])&&(_X<tab1[0][v1+1])) {
							for(v2=0;v2<j;v2++) {
								if((_Y>tab1[1][v2])&&(_Y<tab1[1][v2+1])&&(tab3[v1+1][v2+1]>=0)) {
		PlacerImage(4,sk,tab2[0][v1]-12,tab2[1][v2]-12);
		*x=*x-3;
		tab3[v1+1][v2+1]=-1;
	}
 	}}}}
defaite=ConditionDefaite(tab3,j);
		 if(defaite !=0) {
 	return defaite;
 }
 }
 		return defaite;

}
int TourJoueur2IA(int tab1[2][10],int tab2[2][10],int tab3[11][11],int tab5[2],int j,int* x,int* vaj1,int* vaj2,int sk) {
	int v1,v2,ia1,ia2;
	int defaite;
	EcrireTexte(50, 850, "Le joueur 2 de deplacer son pion ", 2);
 	while (*x==4) {
 		ia1=rand()%1001;
				for(v1=*vaj1-1;v1<=*vaj1+1;v1++) {
						if((ia1>tab1[0][v1])&&(ia1<tab1[0][v1+1])) {
							ia2=rand()%801;
							for(v2=*vaj2-1;v2<=*vaj2+1;v2++) {
								if((ia2>tab1[1][v2])&&(ia2<tab1[1][v2+1])&&(tab3[v1+1][v2+1]>=0)) {
			PlacerImage(0,sk,tab5[0]-12,tab5[1]-18);
			tab3[*vaj1+1][*vaj2+1]=0;
			PlacerImage(3,sk,tab2[0][v1]-12,tab2[1][v2]-18);
			*x=*x+1;
				tab3[v1+1][v2+1]=-3;
				*vaj1=v1;
				*vaj2=v2;
				tab5[0]=tab2[0][v1];
				tab5[1]=tab2[1][v2];
		}
		}}}
		defaite=ConditionDefaite(tab3,j);
		 if(defaite !=0) {
 	return defaite;
 }
 }
		ChargerImage("effacertexte.png",0,800,0,0,800,100);
 	EcrireTexte(50, 850, "Le joueur 2 doit placer sa croix", 2);
	while(*x==5) {
		ia1=rand()%1001;
			for(v1=0;v1<j;v1++) {
						if((ia1>tab1[0][v1])&&(ia1<tab1[0][v1+1])) {
							ia2=rand()%801;
							for(v2=0;v2<j;v2++) {
								if((ia2>tab1[1][v2])&&(ia2<tab1[1][v2+1])&&(tab3[v1+1][v2+1]>=0)) {
		PlacerImage(4,sk,tab2[0][v1]-12,tab2[1][v2]-18);
		*x=*x-3;
		tab3[v1+1][v2+1]=-1;
	}
 	}}}
defaite=ConditionDefaite(tab3,j);
		 if(defaite !=0) {
 	return defaite;
 }
 }
 		return defaite;
 
}


/*int main(void) {
	int x=0,z=1,j=9,op=j+1;
	int nbj=1;
	int hj=j;
	int tab1[2][10];
	int tab2[2][10];
	int tab3[11][11];
	int defaite=0,debutdegame=0;
	int v1,v2;
	int tab4[2],tab5[2];
	int va1=j,va2=j;
	int vaj1=j,vaj2=j;
	InitialiserGraphique();
	CreerFenetre(0,0,800,900);
	ChargerImage("./blocus.png",0,0,0,0,800,800);
	ChargerSprite("SergePion.png");
	ChargerSprite("disable.png");
	ChargerSprite("SergeCroix.png");
	ChargerSprite("BradpittPion.png");
	ChargerSprite("BPcroix.png");
	RemplirTableaux(tab1,tab2,tab3,j);
	PremierTour(tab1,tab2,tab3,tab4,tab5,j,&va1,&va2,&vaj1,&vaj2,1);
	x=x+2;
	while(defaite==0)  {
 defaite=TourJoueur1(tab1,tab2,tab3,tab4,hj,&x,&va1,&va2);
 if (nbj==1) {
 	defaite=TourJoueur2IA(tab1,tab2,tab3,tab5,hj,&x,&vaj1,&vaj2);
 }
 if (nbj==2) {
defaite=TourJoueur2(tab1,tab2,tab3,tab5,hj,&x,&vaj1,&vaj2);
}
}
FermerGraphique();
}*/
	