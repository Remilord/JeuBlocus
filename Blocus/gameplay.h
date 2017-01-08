
#ifndef H_GAMEPLAY
#define H_GAMEPLAY

int ConditionDefaite(int tab3[11][11],int j);

void RemplirTableaux(int tab1[2][10],int tab2[2][10],int tab3[11][11],int j);

void PremierTour(int tab1[2][10],int tab2[2][10],int tab3[11][11],int tab4[2],int tab5[2],int j,int* va1,int* va2,int* vaj1,int* vaj2,int nbj,int sk);

int TourJoueur1(int tab1[2][10],int tab2[2][10],int tab3[11][11],int tab4[2],int j,int* x,int* va1,int* va2,int sk);

int TourJoueur2(int tab1[2][10],int tab2[2][10],int tab3[11][11],int tab5[2],int j,int* x,int* vaj1,int* vaj2,int sk);

int TourJoueur2IA(int tab1[2][10],int tab2[2][10],int tab3[11][11],int tab5[2],int j,int* x,int* vaj1,int* vaj2,int sk);



#endif
					
