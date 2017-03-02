#include<stdio.h>
#include<stdlib.h>

#include "dod_kal.h"

char z;

void dl_dt ()
	{
	system("clear");
	int n, m, d, i,suma,przen=0;
	printf("Podaj dlugosc pierwszej liczby: ");
	scanf("%i", &m);
	printf("Podaj dlugosc drugiej liczby: ");
	scanf("%i", &n);
	if((m<=0)||(n<=0))
		printf("Liczby musza byc dodatnie!\n");
	else
		{
		if(m>n)
			d=m+1;
		else
			d=n+1;
		int tab[m], tab2[n], tab3[d];
		printf("Podaj pierwsza liczbe: ");
		for(i=0; i<m; i++)
			scanf("%1i", &tab[i]);
		printf("Podaj druga liczbe: ");
		for(i=0; i<n; i++)
			scanf("%1i", &tab2[i]);
		for(i=0; i<d; i++)
			tab3[i] = 0;
		for(i=d-1; i>0; i--)
			{
			if(n<1)
				suma=tab[m-1]+0+przen;
			if(m<1)
				suma=0+tab2[n-1]+przen;
			else if((m>=1)&&(n>=1))
				suma=tab[m-1]+tab2[n-1]+przen;
			if(suma>9)
				{
				suma-=10;
				przen=1;
				}
			else
				przen=0;
			tab3[i]=suma;
			n--;
			m--;
			}
		tab3[0]=przen;
		if(tab3[0]==0)
			i=1;
		else
			i=0;
		printf("Suma to: ");
		for(i=i; i<d; i++)
			printf("%i", tab3[i]);
		printf("\n");
		}
	do
		z=getchar();
	while(z!='\n');
	spac(3);
	}

void dl_od () 
	{
	system("clear");
	int n, m, d, i,suma,j=1;
	printf("Podaj dlugosc pierwszej liczby: ");
	scanf("%i", &m);
	printf("Podaj dlugosc drugiej liczby: ");
	scanf("%i", &n);
	if((m<=0)||(n<=0))
		printf("Liczby musza byc dodatnie!\n");
	else
		{
		if(m>=n)
		d=m;
		else
		d=n;
		int tab[m], tab2[n], tab3[d];
		printf("Podaj pierwsza liczbe: ");
		for(i=0; i<m; i++)
		scanf("%1i", &tab[i]);
		printf("Podaj druga liczbe: ");
		for(i=0; i<n; i++)
		scanf("%1i", &tab2[i]);
		for(i=0; i<d; i++)
			tab3[i] = 0;
		if(m==n)
			{
			i=0;
			while((tab[i]==tab2[i])&&(n-1!=i))
			i++;
			if(tab2[i]>tab[i])
			j=0;
			}
		if((m>=n)&&(j==1))
			for(i=d-1; i>=0; i--)
			{
			if(n<1)
				{
				suma=tab[m-1]-0;
				if(m<1)
				suma=0-tab2[n-1];
				}
			else if(m>=1)
			suma=tab[m-1]-tab2[n-1];
			if((suma<0)&&(d!=1))
				{
				suma+=10;
				tab[m-2]-=1;
				}
			tab3[i]=suma;
			n--;
			m--;
			}
	else
		for(i=d-1; i>=0; i--){
			if(m<1)
			suma=tab2[n-1]-0;
			else if(m>=1)
			suma=tab2[n-1]-tab[m-1];
			if((suma<0)&&(d!=1))
				{
				suma+=10;
				tab2[n-2]-=1;}
			tab3[i]=suma;
			n--;
			m--;
			}
		i=0;
		while(tab3[i]==0)
			i++;
		printf("Roznica to: ");
			if(!(m>=n)||(j==0))
		printf("-");
		if(i==d)
			printf("%i", 0);
		for(i=i; i<d; i++)
			printf("%i", tab3[i]); 
		printf("\n");
		}
	do
		z=getchar();
	while(z!='\n');
	spac(3);
	}

void dl_mn () 
	{
	system("clear");
	int n, m, d,d2, i,j,ilocz=0,przen=0;
	printf("Podaj dlugosc pierwszej liczby: ");
	scanf("%i", &m);
	printf("Podaj dlugosc drugiej liczby: ");
	scanf("%i", &n);
	if((m<=0)||(n<=0))
		printf("Liczby musza byc dodatnie!\n");
	else
		{
		d=n+m;
		d2=d;
		int tab[m], tab2[n], tab3[d];
		printf("Podaj pierwsza liczbe: ");
		for(i=0; i<m; i++)
		scanf("%1i", &tab[i]);
		printf("Podaj druga liczbe: ");
		for(i=0; i<n; i++)
			scanf("%1i", &tab2[i]);
		for(i=0; i<d; i++)
			tab3[i] = 0;
		for(i=n-1; i>=0; i--)
		{
			for(j=m-1; j>=0; j--)
				{
				ilocz=0;
				ilocz+=tab[j]*tab2[i]+przen;
				przen=0;
				while((ilocz>=10)&&(j!=0))
					{
					ilocz-=10;
					przen++;
					}
				tab3[d-1]+=ilocz;
				while(tab3[d-1]>9)
					{
					tab3[d-2]+=1;
					tab3[d-1]-=10;
					}
				d--;
				}
			d2--;
			d=d2;
			}
		tab3[0]+=przen;
		d=m+n;
		if(tab3[0]==0)
			i=1;
		else
			i=0;
		printf("Iloczyn to: ");
		for(i=i; i<d; i++)
			printf("%i", tab3[i]); 
		printf("\n");
		}
	do
		z=getchar();
	while(z!='\n');
	spac(3);
	}


void macierze () 
	{
	system("clear");
	int n,m,n2,m2,i,j;
	printf("Podaj wysokosc pierwszej macierzy: ");
	scanf("%i", &n);
	printf("Podaj szerokosc pierwszej macierzy: ");
	scanf("%i", &m);
	printf("Podaj wysokosc drugiej macierzy: ");
	scanf("%i", &n2);
	printf("Podaj szerokosc drugiej macierzy: ");
	scanf("%i", &m2);
	if(m<0 || n<0 || n2<0 || m2<0)
		printf("Rozmiar macierzy nie moze byc ujemny!!!\n");
	else
		{
		double tab[n][m],tab2[n2][m2],tab3[n][m2];
		for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			{
			printf("Podaj kolumny %i i wiersza %i element pierwszej macierzy: ", i+1,j+1);
			scanf("%lf", &tab[i][j]);}
			for(i=0; i<n2; i++)
			for(j=0; j<m2; j++)
				{
				printf("Podaj kolumny %i i wiersza %i element drugiej macierzy: ", i+1,j+1);
				scanf("%lf", &tab2[i][j]);
				}	
			printf("\nPierwsza macierz to: \n");
			for(i=0; i<n; i++)
				{
				printf("\n");
				for(j=0; j<m; j++)
					printf("%15.2lf ", tab[i][j]);}
				printf("\n\nDruga macierz to: \n");
				for(i=0; i<n2; i++)
					{
					printf("\n");
					for(j=0; j<m2; j++)
					printf("%15.2lf ", tab2[i][j]);
					}
				printf("\n\nIloczyn tych dwoch macierzy to: \n");
				if(m==n2)
					{
					int ilocz=0,i2=0,j2=0;
					while(i2<m2)
						{
						ilocz=0;
						i=0;
						j=0;
						while(j<m)
							{
							ilocz+=tab[i2][j]*tab2[i][j2];
							i++;
							j++;
							}
						tab3[i2][j2]=ilocz;
						j2++;
						if(j2==m2)
							{
							j2=0;
							i2++;
							}
						}
					for(i=0; i<n; i++)
						{
						printf("\n");
						for(j=0; j<m2; j++)
						printf("%15.2lf ", tab3[i][j]);
						}
					printf("\n");
					}
				else 
					printf("\nTaka macierz nie istnieje.\n");
				}
			do
				z=getchar();
			while(z!='\n');
			spac(5);
	}

void s_licz()
	{
	system("clear");
	int l, s;
	printf("Podaj calkowita liczbe (system dziesiatkowy): ");
	scanf("%i", &l);
	if(l<0)
		printf("BLAD!\n");
	else
		{
		printf("Podaj podstawe: ");
		scanf("%i", &s);
		if(s>16 || s<0)
			{
			printf("Podstawa musi byc miejsza od 16 i wieksza od 0\n");
			printf("\n");
			}
		else
			{
			int pom=l, i=0, j, dl;
			char liczba[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}, po;
			while(pom!=0)
				{
				pom/=s;
				i++;	
				}
			if(l==0)
				i=1;
			char *wynik=malloc(sizeof(char)*i);
			pom=l;
			i=0;
			while(pom!=0)
				{
				wynik[i]=liczba[pom%s];
				pom/=s;
				i++;	
				}
			if(l==0)
				wynik="0";
			dl=i;
			j=dl;
			for(i=0;i<dl/2;i++)
				{
				po=wynik[i];
				wynik[i]=wynik[j-1];
				wynik[j-1]=po;
				j--;
				}
			printf ("Liczba %i w systemie %i to: %s\n", l, s, wynik);
			}
		}
	do
		z=getchar();
	while(z!='\n');
	spac(3);
	}

void zesp()
	{
	system("clear");
	double r, i, r2, i2, wynikr, wyniki;
	printf("Podaj czesc rzeczywista piewszej liczby: ");
	scanf("%lf", &r);
	printf("Podaj czesc rzeczywista piewszej liczby: ");
	scanf("%lf", &i);
	printf("Podaj czesc urojona drugiej liczby: ");
	scanf("%lf", &r2);
	printf("Podaj czesc urojona drugiej liczby: ");
	scanf("%lf", &i2);
	wynikr=(r*r2)-(i*i2);
	wyniki=(i*r2)+(r*i2);
	if(wyniki<0)
		printf("\nWynik to: %.4lf %.4lfi", wynikr, wyniki);
	else
		printf("\nWynik to: %.4lf +%.4lfi", wynikr, wyniki);
	do
		z=getchar();
	while(z!='\n');
	printf("\n");
	spac(3);
	}

int wybor(char c){int i;
		switch (c) {
		     			case '1':
					i=1; break;
					case 'I':
					i=1; break;
					case 'i':
					i=1; break;
					case '2':
					i=2; break;
					case 'V':
					i=2; break;
					case 'v':
					i=2; break;
					case '3':
					i=3; break;
					case 'X':
					i=3; break;
					case 'x':
					i=3; break;
					case '4':
					i=4; break;
					case 'L':
					i=4; break;
					case 'l':
					i=4; break;
					case '5':
					i=5; break;
					case 'C':
					i=5; break;
					case 'c':
					i=5; break;
					case '6':
					i=6; break;
					case 'D':
					i=6; break;
					case 'd':
					i=6; break;
					case '7':
					i=7; break;
					case 'M':
					i=7; break;
					case 'm':
					i=7; break;
					default:i=8;}
				return i;}

void arab_rzym(){
			system("clear");
  char rzym[] = { 'I', 'V', 'X',
                   'L', 'C',
                   'D', 'M'};
  int arab[] = { 1, 5, 10,
                 50, 100,
                 500, 1000, 
		  3, 8, 30, 
		  80, 300, 800};
  int  i=0, j=0, liczba=0,k=15,l=15,pow=0;
  char znak[30]=" ", c;
  printf("\n1:I,\n2:V,\n3:X,\n4:L,\n5:C,\n6:D,\n7:M,\n8+:koniec.\n");
  printf("\nPodaj liczbe rzymska: ");
  while(i<8){
  	scanf("%c",&c);
	i=wybor(c);
	if(i==0 || i==8){if(i==0) printf("blad\n");}
	else
		if(((i>1 && (k==1||k==2)) || (i>4 && k==4) || (i>5 && k==3) || (i==7 && k==6)) && i<8)
				{printf("blad przy: %c\n", rzym[i-1]);
				i=k;}
		else{	if(pow>=2 && (i==1 || i==3 || i==5) && i==k)
				printf("blad przy: %c\n", rzym[i-1]);
			else if((i==2 || i==4 || i==6) && i==k)
				printf("blad przy: %c\n", rzym[i-1]);
			else if((l==1 && i>=1) || (l==2 && i>=2) || (l==3 && i>=3) || (l==4 && i>=4) ||  (l==5 && i>=5)  || (l==6 && i>=6))
				{printf("blad przy: %c\n", rzym[i-1]);
				i=k;}
			else{
				if(k<i)
					
					liczba+=arab[i-1+6];
				else
  					liczba+=arab[i-1];
  				znak[j]=rzym[i-1];
				j++;
				if(i==k)
					pow++;
				else
					pow=0;
				if(k!=i)
					l=k;
				k=i;
			}	
		}
	}	
  printf("Liczba rzymska to: %s\n", znak); 
  printf("Liczba arabska to: %i\n", liczba); 
  spac(3);
}

void dod_opcja ()
	{
	char znaczek;
	while(znaczek!='q' && znaczek!='Q')
		{
		system("clear");
		printf("\nOpcje:\n");
		printf("\nI: Przeczytaj informacje\nQ: Wyjscie z aplikacji\n1: Dodawanie dlugich liczb\n2: Odejmowanie dlugich liczb\n3: Mnozenie dlugich liczb \n4: Mnozenie macierzy\n5: Mnozenie liczb zespolonych\n6: Systemy liczenia\n7: Rzymska na arabska\n\nWybierz opcje: ", znaczek);
		scanf("%c", &znaczek);
		do
			z=getchar();
		while(z!='\n');
		if(znaczek>='1' && znaczek<='7')
			switch (znaczek) 
				{
				case '1':
				dl_dt();
				break;
				case '2':
				dl_od();
				break;
				case '3':
				dl_mn();
				break;
				case '4':
				macierze();
				break;
				case '5':
				zesp();
				break;
				case '6':
				s_licz();
				break;
				case '7':
				arab_rzym();
				break;
				}
		else if(znaczek=='I' || znaczek=='i')
			{
			printf("\nAplikacja posiada mozliwosc dodawania/odejmowania/mnozenia dwoch dodatnich dlugich liczb. Poczatkowo uzytkownik podaje dlugosc dwoch liczb, a nastepnie podaje dwie dodatnie liczby o wczesniej podanej dlugosci. Posiada rowniez mozliwosc mnozenia macierzy oraz liczb zespolonych, przeliczania z liczby w systemie dziesietnym na inny dowolny system liczbowy oraz mozliwosc zamiany liczby rzyskiej na arabska.\n");
			spac(8);
			} 
		}
	}