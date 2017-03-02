#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#include "dod_gry.h"

char z;

int spr_ust1(char* s) 
	{
	int pom;
	int ile=0;
	FILE* gry = fopen(s,"r");
	fscanf(gry, "%i", &pom);
	fclose(gry);
	return pom;
	}

int spr_ust2(char* s) 
	{
	int pom;
	int ile=0;
	FILE* gry = fopen(s,"r");
	fscanf(gry, "%i", &pom);
	fscanf(gry, "%i", &pom);
	fclose(gry);
	return pom;
	}

void graj1(int p, int r)
{
	system("clear");
	int wc=0, wk=0, kol=0;
	char zg='t';
	while(zg=='t' || zg=='T' || zg=='y' || zg=='Y')
		{
		char l1;
		int l2, suma=0;
		printf("\nZakres liczb: 1-%i, Suma do: %i", r, p);
		while(suma<p)
			{
			l1=0;
			if(kol%2==0 || suma!=0)
				{
				while(l1-48<1 || l1-48>r)
					{
					printf("\nPodaj liczbe: ");
					scanf("%c", &l1);
					do
						z=getchar();
					while(z!='\n');
					if(l1-48<1 || l1-48>r)
						printf("\nZakres liczb: 1-%i !!!\n",r);
					}
				suma+=l1-48;
				}
			if(suma>=p)
				{
				system("clear");
				printf("Suma to: %i\nWYGRALES!!\n", suma);
				wc++;
				}
			else
				{
				srand(time(NULL));
   				l2=(int)rand()%r+1;
				suma+=l2;
				printf("\nKomputer podal: %i, suma to: %i\n", l2, suma);
				if(suma>=p)
					{
					system("clear");
					printf("PRZEGRALES!!\n");
					wk++;
					}
				}		
			}
		printf("\nCzy chcesz zagrac jeszcze raz? [Y/N]: ");
		scanf("%c", &zg);
		system("clear");
		do
			z=getchar();
		while(z!='\n');
		kol++;
		}
	printf("\n\nWynik to: Gracz: %i, Komputer: %i\n", wc, wk);
	spac(4);
	gra1();
}

void ust1(int p, int r)
{
	char wyb;
	while(wyb!='1' && wyb!='2' && wyb!='q' && wyb!='Q')
		{
		system("clear");
		printf("\nOpcje:\n");
		printf("\nQ: Wroc\n1: Dlugosc sumy\n2: Zakres liczb\n\nWybierz opcje: ");
		scanf("%c", &wyb);
		do
			z=getchar();
		while(z!='\n');
		}
	if(wyb=='1')
			{
			system("clear");
			int p;
			printf("\nPodaj dlugosc sumy do ktorej ma konczyc sie gra (nie mniejsza od 10): ");
			scanf("%i", &p);
			do
				z=getchar();
			while(z!='\n');
			if(p>=10)
				{
				FILE* gry = fopen("FILE/gry/dod/1","w");
				fprintf(gry, "%i\n%i", p, r);
				fclose(gry);
				printf("\nZapisano!\n");
				spac(2);
				}
			else
				{
				printf("\nNieprawidlowa liczba!\n");
				spac(2);
				}
			}
	if(wyb=='2')
			{
			system("clear");
			int r;
			printf("Podaj zakres do ktorego mozna podawac liczby - od 1 do (nie wiekszy od 9): ");
			scanf("%i", &r);
			do
				z=getchar();
			while(z!='\n');
			if(r<=9 && r!=0)
				{
				FILE* gry = fopen("FILE/gry/dod/1","w");
				fprintf(gry, "%i\n%i", p, r);
				fclose(gry);
				printf("\nZapisano!\n");
				spac(2);
				}
			else
				{
				printf("\nNieprawidlowa liczba!\n");
				spac(2);
				}
			}
	gra1();
}

void gra1 () 
	{
	char wyb;
	while(wyb!='1' && wyb!='2' && wyb!='q' && wyb!='Q')
		{
		system("clear");
		printf("\nOpcje:\n");
		printf("\nI: Instrukcja\nQ: Wyjdz\n1: Graj\n2: Ustawienia\n\nWybierz opcje: ");
		scanf("%c", &wyb);
		do
			z=getchar();
		while(z!='\n');
		if(wyb=='i'|| wyb=='I')
			{
			printf("\nKomputer i gracz podaja na przemian liczby z danego zakresu, liczby te sa sumowane. Wygrywa ten ktory pierwszy poda liczbe ktora dojdze do danej sumy.\n");
			spac(7);
			}
		}
	if(wyb=='1')
			{
			int p, r;
			p=spr_ust1("FILE/gry/dod/1");
			r=spr_ust2("FILE/gry/dod/1");
			graj1(p,r);
			}
	else if(wyb=='2')
			{
			int p, r;
			p=spr_ust1("FILE/gry/dod/1");
			r=spr_ust2("FILE/gry/dod/1");
			ust1(p,r);
			}
	else if(wyb=='q' || wyb=='Q')
			gry();
	}

void graj2 () 
	{
	system("clear");
	char slowko[3], zgaduj[3];
	srand(time(NULL));
   	slowko[0]=(int)rand()%26+65;
   	slowko[1]=(int)rand()%26+65;
   	slowko[2]=(int)rand()%26+65;
	slowko[3]='\0';	
	slowko[4]='\0';
	slowko[5]='\0';
	slowko[6]='\0';
	slowko[7]='\0';
	char wyb;
	int ile=0;
	while(strcmp(slowko,zgaduj)!=0 && wyb!='8')
		{ 
		char lit;
		printf("\n1: Czy zaczyna sie na: ");
		printf("\n2: Czy druga literka to: ");
		printf("\n3: Czy konczy sie na: ");
		printf("\n4: Czy pierwsza literka poprzedza alfabetycznie: ");
		printf("\n5: Czy druga literka poprzedza alfabetycznie: ");
		printf("\n6: Czy trzecia literka poprzedza alfabetycznie: ");
		printf("\n7: Czy slowo to: ");
		printf("\n8: Wyjdz z gry");
		printf("\n\nWybierz pytanie: ");
		scanf("%c", &wyb);
		do
			z=getchar();
		while(z!='\n');
		if(wyb=='1')
			{
			printf("Podaj literke: ");
			scanf("%c", &lit);
			do
				z=getchar();
			while(z!='\n');
			if(lit>='a' && lit<='z')
				lit-=32;
			if(lit>='A' && lit<='Z')
				if(slowko[0]==lit)
					{
					printf("\nTAK\n");
					ile++;
					}
				else
					{
					printf("\nNIE\n");
					ile++;
					}
			spac(1);
			}
		else if(wyb=='2')
			{
			printf("Podaj literke: ");
			scanf("%c", &lit);
			do
				z=getchar();
			while(z!='\n');
			if(lit>='a' && lit<='z')
				lit-=32;
			if(lit>='A' && lit<='Z')
				if(slowko[1]==lit)
					{
					printf("\nTAK\n");
					ile++;
					}
				else
					{
					printf("\nNIE\n");
					ile++;
					}
			spac(1);
			}
		else if(wyb=='3')
			{
			printf("Podaj literke: ");
			scanf("%c", &lit);
			do
				z=getchar();
			while(z!='\n');
			if(lit>='a' && lit<='z')
				lit-=32;
			if(lit>='A' && lit<='Z')
				if(slowko[2]==lit)
					{
					printf("\nTAK\n");
					ile++;
					}
				else
					{
					printf("\nNIE\n");
					ile++;
					}
			spac(1);
			}
		else if(wyb=='4')
			{
			printf("Podaj literke: ");
			scanf("%c", &lit);
			do
				z=getchar();
			while(z!='\n');
			if(lit>='a' && lit<='z')
				lit-=32;
			if(lit>='A' && lit<='Z')
				if(slowko[0]<lit)
					{
					printf("\nTAK\n");
					ile++;
					}
				else
					{
					printf("\nNIE\n");
					ile++;
					}
			spac(1);		
			}
		else if(wyb=='5')
			{
			printf("Podaj literke: ");
			scanf("%c", &lit);
			do
				z=getchar();
			while(z!='\n');
			if(lit>='a' && lit<='z')
				lit-=32;
			if(lit>='A' && lit<='Z')
			if(slowko[1]<lit)
				{
				printf("\nTAK\n");
				ile++;
				}
			else
				{
				printf("\nNIE\n");
				ile++;
				}
			spac(1);
			}
		else if(wyb=='6')
			{
			printf("Podaj literke: ");
			scanf("%c", &lit);
			do
				z=getchar();
			while(z!='\n');
			if(lit>='a' && lit<='z')
				lit-=32;
			if(lit>='A' && lit<='Z')
			if(slowko[2]<lit)
				{
				printf("\nTAK\n");
				ile++;
				}
			else
				{
				printf("\nNIE\n");
				ile++;
				}
			spac(1);
			}
	else if(wyb=='7')
			{
			printf("Podaj slowo: ");
			scanf("%c", &zgaduj[0]);
			if(zgaduj[0]>='a' && zgaduj[0]<='z')
				zgaduj[0]-=32;
			scanf("%c", &zgaduj[1]);
			if(zgaduj[1]>='a' && zgaduj[1]<='z')
				zgaduj[1]-=32;
			scanf("%c", &zgaduj[2]);
			if(zgaduj[2]>='a' && zgaduj[2]<='z')
				zgaduj[2]-=32;
			zgaduj[3]='\0';
			zgaduj[4]='\0';
			zgaduj[5]='\0';
			zgaduj[6]='\0';
			zgaduj[7]='\0';
			do
				z=getchar();
			while(z!='\n');
			if(strcmp(slowko,zgaduj)!=0)
					{
					printf("%s\n%s",slowko,zgaduj);
					printf("\nNIE\n");
					ile++;
					spac(2);
					}
			else
				{
				int wynik;
				wynik=spr_ust1("FILE/gry/dod/2");
				if(ile<wynik)
					{
					FILE* gry = fopen("FILE/gry/dod/2","w");
					fprintf(gry, "%i", ile);
					fclose(gry);
					system("clear");
					printf("\nNowy rekord !!!, twoj wynik to: %i\n", ile);
					spac(2);
					gra2();
					}
				else
					{
					system("clear");
					printf("\nTwoj wynik to: %i\nNajlepszy wynik to: %i\n", ile, wynik);
					spac(2);
					gra2();
					}
				}
			}
		else if(wyb=='8')
			gra2();
		}
	}

void gra2() 
	{
	char wyb;
	while(wyb!='1' && wyb!='q' && wyb!='Q')
		{
		system("clear");
		printf("\nOpcje:\n");
		printf("\nI: Instrukcja\nQ: Wyjdz\n1: Graj\n2: Najlepszy wynik\n\nWybierz opcje: ");
		scanf("%c", &wyb);
		do
			z=getchar();
		while(z!='\n');
		if(wyb=='2')
			{
			system("clear");
			int wynik;
			wynik=spr_ust1("FILE/gry/dod/2");
			printf("\nNajlepszy wynik to: %i\n", wynik);
			spac(4);
			}
		if(wyb=='i'|| wyb=='I')
			{
			printf("\nKomputer wymysla trzy literowe slowo, zadaniem gracza jest odgadniecie co to za slowo, zadajac pytania komputerowi.\n");
			spac(7);
			}
		}
	if(wyb=='1')
			{
			int p, r;
			p=spr_ust1("FILE/gry/dod/2");
			graj2(p,r);
			}
	else if(wyb=='q' || wyb=='Q')
			gry();
	}

void graj3 () 
{
char zg='t';
int kol=0, wc=0, wk=0, re=0;
while(zg=='t' || zg=='T' || zg=='y' || zg=='Y')
	{
	system("clear");
	char wyb;
	char tab[5][5];
	int i, j, k=0;
	for(i=0; i<5; i++)
	for(j=0; j<5; j++)
		{
		if(i%2==0 && j%2==0)
			tab[i][j]=' ';
		else if((i==1 || i==3) && (j==1 || j==3))
			tab[i][j]='+';
		else if((i==1 || i==3))
			tab[i][j]='-';
		else
			tab[i][j]='|';
		}
	typedef  struct 
		{
		char x;
		char y;
		}  wspolrzedna;
	wspolrzedna ruch;
	if(kol%2==0)
		{
		printf("  1 2 3");
		for(i=0; i<5; i++)
			{
			printf("\n");
			if(i%2==0)
				{
				k++;
				printf("%i ",k);
				}
			else
				printf("  ");
			for(j=0; j<5; j++)
				printf("%c", tab[i][j]);
			}
		}
	int ile=0;
	while (ile<9)
		{
		if(kol%2==0 || ile!=0)
		{
			ruch.x='0'; ruch.y='0';
			while(tab[(ruch.x-49)*2][(ruch.y-49)*2]!=' ')
				{
				ruch.x='0'; ruch.y='0';
				while(ruch.x<'1' || ruch.x>'3')
					{
					printf("\nPodaj wpolrzedna pozioma: ");
					scanf("%c", &ruch.x);
					do
						z=getchar();
					while(z!='\n');
					}
				while(ruch.y<'1' || ruch.y>'3')
					{
					printf("\nPodaj wpolrzedna pionowa: ");
					scanf("%c", &ruch.y);
					do
						z=getchar();
					while(z!='\n');
					}
				}
			tab[(ruch.x-49)*2][(ruch.y-49)*2]='X';
			if((tab[0][0]=='X' && tab[2][2]=='X' && tab[4][4]=='X') || (tab[0][4]=='X' && tab[2][2]=='X' && tab[4][0]=='X'))
				{
				wc++;
				ile=10;	
				}
			else
				{	
				for(i=0; i<5; i=i+2)
					if(tab[i][0]=='X' && tab[i][2]=='X' && tab[i][4]=='X')
						{	
						wc++;
						ile=10;
						}
				for(j=0; j<5; j=j+2)
					if(tab[0][j]=='X' && tab[2][j]=='X' && tab[4][j]=='X')
						{	
						wc++;
						ile=10;
						}
				}
		}
		ile++;
		if((kol%2==0 && ile<9) || (kol%2!=0 && ile<10))
			{
			if(ile==9)
				ile--;
			while((tab[i*2][j*2])!=' ')
				{
				srand(time(NULL));
   				i=(int)rand()%3+0;
   				j=(int)rand()%3+0;
				}
			ile++;
			tab[i*2][j*2]='O';
			}
		printf("  1 2 3");
		k=0;
		if((tab[0][0]=='O' && tab[2][2]=='O' && tab[4][4]=='O') || (tab[0][4]=='O' && tab[2][2]=='O' && tab[4][0]=='O'))
			{
			wk++;
			ile=10;	
			}
		else
			{
			for(i=0; i<5; i=i+2)
				if(tab[i][0]=='O' && tab[i][2]=='O' && tab[i][4]=='O')
					{	
					wk++;
					ile=10;
					}
			for(j=0; j<5; j=j+2)
				if(tab[0][j]=='O' && tab[2][j]=='O' && tab[4][j]=='O')
					{	
					wk++;
					ile=10;
					}
			}
		system("clear");
		for(i=0; i<5; i++)
			{
			printf("\n");
			if(i%2==0)
				{
				k++;
				printf("%i ",k);
				}
			else
				printf("  ");
			for(j=0; j<5; j++)
				printf("%c", tab[i][j]);
			}	
		}
	if(ile==9)
		{
		re++;
		printf("\n\nRemis !\n");
		spac(1);
		}
	else if(ile==10)
		{
		printf("\n\nPrzegrales !\n");
		spac(1);
		}
	else if(ile==11)
		{
		printf("\n\nWygrales !\n");
		spac(1);
		}
	printf("\nCzy chcesz zagrac jeszcze raz? [Y/N]: ");
	scanf("%c", &zg);
	do
		z=getchar();
	while(z!='\n');
	kol++;
}
system("clear");
printf("\n\nWynik to: Gracz: %i, Komputer: %i, Remis: %i\n", wc, wk, re);
spac(4);
gra3();
}

void gra3() 
	{
	char wyb;
	while(wyb!='1' && wyb!='q' && wyb!='Q')
		{
		system("clear");
		printf("\nOpcje:\n");
		printf("\nI: Instrukcja\nQ: Wyjdz\n1: Graj\n\nWybierz opcje: ");
		scanf("%c", &wyb);
		do
			z=getchar();
		while(z!='\n');
		if(wyb=='2')
			{
			int wynik;
			wynik=spr_ust1("FILE/gry/dod/2");
			printf("\nNajlepszy wynik to: %i\n", wynik);
			spac(4);
			}
		if(wyb=='i'|| wyb=='I')
			{
			printf("\nGrasz rozgrywa z komputerem gre w kolko i krzyzyk. Gracz gra jako X komputer jako O. Aby ustawic X w odpowiednie mniejsce gracz podaje wsposlrzedne (1,2,3). W przypadku podania blednych wspolrzednych gracz podaje je ponownie.\n");
			spac(9);
			}
		}
	if(wyb=='1')
			{
			int p, r;
			p=spr_ust1("FILE/gry/dod/2");
			graj3();
			}
	else if(wyb=='q' || wyb=='Q')
			gry();
	}