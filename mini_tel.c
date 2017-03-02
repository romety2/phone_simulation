#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<unistd.h>

#include "conio.h"
#include "mini_tel.h"
#include "dod_gry.h"
#include "dod_kal.h"
#include "obrazki.h"

#define ilosc 50

char z, *wibr=NULL, *dg=NULL, *ka=NULL, *gr=NULL, *ob=NULL;

void kasew();
void kasei();

typedef  struct 
	{
	char uzyj;
	char info;
	}  wybor;

typedef  struct 
	{
	char nazwa[ilosc];
	char numer[10];
	}  kontakt;

typedef struct s1 
	{
 	char slowko[ilosc];
  	struct s1* nast;
	}* lista;

void spac(int i)
	{
	sleep(i);
	}

int plik()
{
	FILE* pow = fopen("FILE/ustaw/pow","r");
	FILE* hasl = fopen("FILE/ustaw/hasl","r");
	FILE* wib = fopen("FILE/ustaw/wib","r");
	FILE* dg = fopen("FILE/ustaw/dg","r");
	FILE* kal = fopen("FILE/ustaw/kal","r");
	FILE* gry = fopen("FILE/ustaw/gry","r");
	FILE* obr = fopen("FILE/ustaw/obr","r");
	FILE* wl = fopen("FILE/gry/w_lit","r");
	FILE* zl = fopen("FILE/gry/zn_li","r");
	FILE* g1 = fopen("FILE/gry/dod/1","r");
	FILE* g2 = fopen("FILE/gry/dod/2","r");
  		if (hasl == NULL || pow == NULL || wib == NULL || dg == NULL || kal == NULL ||gry == NULL || obr == NULL || wl == NULL || zl == NULL || g1 == NULL || g2 == NULL)
			return 0;
		else	
			{
			fclose(pow);
			fclose(hasl);
			fclose(wib);
			fclose(dg);
			fclose(kal);
			fclose(gry);
			fclose(obr);
			fclose(wl);
			fclose(zl);
			fclose(g1);
			fclose(g2);
			return 1;
			}
}


void wyp_pow()
	{
		system("clear");
		char czesc[50];
		FILE* pow = fopen("FILE/ustaw/pow","r");
		printf("\n\n");
		while(fscanf(pow, "%s", czesc) != EOF)
			printf("%s ", czesc);
		printf("\n");
		fclose(pow);
	}

void czyt_has(char* hasl, char* hasl2, int* time)
{	
	FILE* ust = fopen("FILE/ustaw/hasl","r");
	fscanf(ust, "%c", hasl);
	if(*hasl=='t')
	{
		fscanf(ust, "%s", hasl2);
		fscanf(ust, "%i", time);
	}
	fclose(ust);
}

char* data_czas(char znak)
	{
	char* mies_pol[] =  { "Sty", "Lut", "Mar", "Kwi", "Maj", "Cze",
    				"Lip", "Sie", "Wrz", "Paz", "Lis", "Gru" };
  	char* mies_ang[] =  { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    				"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	char* dzien_pol[] = { "Nie", "Pon", "Wto", "Sro", "Czw", "Pia", "Sob" };
  	char* dzien_ang[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	time_t dtcz;
  	struct tm * dataczas;
	time (&dtcz);
  	dataczas = localtime (&dtcz);
	char* data, *czas, *miesiac, *dzien;
	miesiac=NULL, dzien=NULL;
	data=malloc(sizeof(char)*16);
	czas=malloc(sizeof(char)*8);
	miesiac=malloc(sizeof(char)*3);
	dzien=malloc(sizeof(char)*3);
	miesiac[0]=(asctime (dataczas))[4];
	miesiac[1]=(asctime (dataczas))[5];
	miesiac[2]=(asctime (dataczas))[6];
	miesiac[3]='\0';
	miesiac[4]='\0';
	miesiac[5]='\0';
	miesiac[6]='\0';
	miesiac[7]='\0';
	dzien[0]=(asctime (dataczas))[0];
	dzien[1]=(asctime (dataczas))[1];
	dzien[2]=(asctime (dataczas))[2];
	dzien[3]='\0';
	dzien[4]='\0';
	dzien[5]='\0';
	dzien[6]='\0';
	dzien[7]='\0';
	int i=0;
	while(strcmp(miesiac,mies_ang[i])!=0)
		i++;
	strcpy(miesiac,mies_pol[i]);
	i=0;
	while(strcmp(dzien,dzien_ang[i])!=0)
		i++;
	strcpy(dzien,dzien_pol[i]);
	data[0]=(asctime (dataczas))[8];
	data[1]=(asctime (dataczas))[9];
	data[2]=' ';
	data[3]=miesiac[0];
	data[4]=miesiac[1];
	data[5]=miesiac[2];
	data[6]=' ';
	data[7]=(asctime (dataczas))[20];
	data[8]=(asctime (dataczas))[21];
	data[9]=(asctime (dataczas))[22];
	data[10]=(asctime (dataczas))[23];
	data[11]=':';
	data[12]=' ';
	data[13]=dzien[0];
	data[14]=dzien[1];
	data[15]=dzien[2];
	data[16]='\0';
	data[17]='\0';
	data[18]='\0';
	data[19]='\0';
	data[20]='\0';
	czas[0]=(asctime (dataczas))[11];
	czas[1]=(asctime (dataczas))[12];
	czas[2]=(asctime (dataczas))[13];
	czas[3]=(asctime (dataczas))[14];
	czas[4]=(asctime (dataczas))[15];
	czas[5]=(asctime (dataczas))[16];
	czas[6]=(asctime (dataczas))[17];
	czas[7]=(asctime (dataczas))[18];
	czas[8]='\0';
	czas[9]='\0';
	czas[10]='\0';
	czas[11]='\0';
	czas[12]='\0';
	if(znak=='d')
		return data;
	if(znak=='t')
		return czas;
	if(znak=='a')
		return (strcat(strcat(data, ", "), czas));
	}

int haslo()
		{		
		int zmien=0;
		char hasl;
		char hasl2[20],slowo[20];
		int pom=1, time, ile=0,i;
		zmien=0;
		czyt_has(&hasl, hasl2, &time);
		if(hasl=='t')
			{printf("Podaj haslo: ");
			while(pom==1 && ile<time)
				{i=0;
				do
					{
					scanf("%c",&slowo[i]);
					i++;
					}
				while(slowo[i-1]!='\n');
				slowo[i-1]='\0';
				if(strcmp(hasl2, slowo) == 0)
					pom=0;
				else
					{
					if(ile!=time-1)
					printf("Nieprawidlowe haslo, sprobuj jeszcze raz pozostalo ci %i prob: ", time-ile-1);
					ile++;
					if(ile==time)
					zmien=1;}
				}
			}
	return zmien;
		}

void wibruj()
	{
	if(wibr!=NULL)		
		{
		int i;
		for(i=0; i<100000; i++)
			printf("b");
		for(i=0; i<100000; i++)
			printf("r");
		printf("\n\n");
		}
	}

char* spr_data(int d, int m, int r);

void scp()
	{
	FILE* przy = fopen("FILE/przyp/nazw/nazw","r");
	char slowo[8],nazwij[8],slow2[ilosc],p1[]="FILE/przyp/";
	int d,m,r;
	strcpy(nazwij,"abcdefgh");
	while(fscanf(przy, "%s", slowo) != EOF)
		{
		d=(10*(slowo[6]-48))+(slowo[7]-48);
		m=(10*(slowo[4]-48))+(slowo[5]-48);
		r=(1000*(slowo[0]-48))+(100*(slowo[1]-48))+(10*(slowo[2]-48))+(slowo[3]-48);
		if(strcmp(data_czas('d'), spr_data(d, m, r))==0)
			strcpy(nazwij,slowo);
		}	
	fclose(przy);
	if(strcmp(nazwij,"abcdefgh")!=0)
		{
		FILE* przy2;
			printf("\n");
			printf("Przyponienie: ");
			przy2=fopen(strcat(p1,slowo),"r");
			while(fscanf(przy2, "%s", slow2) != EOF)
				{
				printf("%s ", slow2);
				}
			printf("\n");
			fclose(przy2);
		}
	}

void wybierz()
		{
			wybor wybr;
			char wybr2;
			wybr.uzyj='\0';
			wibruj();
			system("clear");
			while((wybr.uzyj<'1' || wybr.uzyj>59)  && wybr.uzyj!='q' && wybr.uzyj!='Q')
				{
				if(dg!=NULL)
					printf("\n%s\n", data_czas(*dg));
				scp();
				printf("\nOpcje:\n");
				printf("\nI: Informacja\nQ: Wyjdz\n1: Zadzwon\n2: Wiadomosc\n3: Kontakty\n4: Zrob zdjecie\n5: Obrazki\n6: Przypomnienie\n7: Gry\n8: Ustawienia\n9: Stoper\n10: Kalkulator\n11: Notatki\n\nWybierz opcje: ");
				scanf("%c", &wybr.uzyj);
				scanf("%c", &wybr2);
				if(wybr2!='\n')
					do
						z=getchar();
					while(z!='\n');
				if(wybr.uzyj=='1' && (wybr2=='0' || wybr2=='1'))
					wybr.uzyj+=9+(wybr2-48);
				if(wybr.uzyj>='1' && wybr.uzyj<=59)
					kasew(wybr.uzyj-48);
				else if(wybr.uzyj=='i' || wybr.uzyj=='I')
					{
					printf("Wybierz opcje dla ktorej chcesz przeczytac informacje: ");
					scanf("%c", &wybr.info);
					scanf("%c", &wybr2);
					if(wybr2!='\n')
					do
						z=getchar();
					while(z!='\n');
					if(wybr.info=='1' && (wybr2=='0' || wybr2=='1'))
						wybr.info+=9+(wybr2-48);	
					if(wybr.info>='1' && wybr.info<=59)
						kasei(wybr.info-48);
					}
				system("clear");
				}
		}

void zdjecie()
	{	
		wibruj();
		system("clear");
		printf("\nUsmiechnij sie do monitora!\n");
		spac(3);
		printf("Wykonywanie zdjecia przy pomocy monitora rozpocznie sie za:\n");
		printf("3\n");
		spac(1);
		printf("2\n");
		spac(1);
		printf("1\n");
		spac(1);
		printf("\nZdjecie zostalo wykonane!\n");
		spac(3);
		printf("Ujzysz je za: \n");
		printf("3\n");
		spac(1);
		printf("2\n");
		spac(1);
		printf("1\n");
		spac(1);
		printf("\n");
		printf("\n");
		printf("      ...''''''''......\n");
		printf("     :                  ''.\n");
		printf("    :                      :\n");
		printf("   :      .::'..     ...    :\n");
		printf(" :' ...  :''''..'   ::..:    :\n");
		printf(":  : . '...'        :         :\n");
		printf(":  : :'..     :'    '.  .'''. :\n");
		printf(" : '. :. :'.. ' '' ..'    :  :\n");
		printf("  :   '.':.. :'''....'':':: :\n");
		printf("   :    ::  ':...:..:.:::: :\n");
		printf("    :    ''. :   : :':::::: :\n");
		printf("     '.     ''...:.:.:.:.'  :\n");
		printf("       '..                   :\n");
		printf("          ''..               :\n");
		printf("              '.....        :\n");
		printf("\n\n");
		spac(5);
		printf("Naprawde myslales, ze monitor potrafi wykonac zdjecie?\n");
		printf("\n");
		spac(5);
		wybierz();
	}


void obrazki()
	{
	wibruj();
	system("clear");
	if(ob==NULL)
		{
		char zg;
		printf("\nOpcja zostala wylaczona, gdyz uzywa grafike wyknana w OpenGLUT. Jezeli posiadasz to oprogramowanie wlacz opcje\n");
		printf("Czy ustawic obrazki [Y/N]: ");
		scanf("%c", &zg);
		do
			z=getchar();
		while(z!='\n');
		system("clear");
		if(zg=='t' || zg=='T' || zg=='y' || zg=='Y')
			{
			FILE* obrazek = fopen("FILE/ustaw/obr","w");
			fprintf(obrazek, "t");
			fclose(obrazek);
			ob=malloc(sizeof(char));
			*ob='t';
			system("clear");
			}	
		}
	if(ob!=NULL)
		{
		char wybr;	
		printf("\nQ: Wroc");
		while(wybr!='q' && wybr!='Q')
			{
			printf("\nTwoje obrazki:\n1: Choinka\n2: Kolko\n3: Szescian\n\nWybierz obrazek: ");
			scanf("%c", &wybr);
			do
				z=getchar();
			while(z!='\n');
			if(wybr=='3')
				szescian(0, "\0");
			else if(wybr=='2')
				kolko(0, "\0");
			else if(wybr=='1')
				choinka(0, "\0");
			}
		}
	system("clear");
	wybierz();
	}

void ustaw()
		{
		wybor wybr;
		wibruj();
		system("clear");
		while((wybr.uzyj<'1' || wybr.uzyj>'8') && wybr.uzyj!='q' && wybr.uzyj!='Q')
				{
				printf("\nOpcje:\n");
				printf("\nI: Informacja\nQ: Wroc\n1: Powitanie\n2: Bezpieczenstwo\n3: Wibracje\n4: Data/godzina\n5: Dodatkowy kalkulator\n6: Dodatkowe gry\n7: Wlacz obrazki\n8: Ustawienia fabryczne\n\nWybierz opcje: ");
				scanf("%c", &wybr.uzyj);
				do
					z=getchar();
				while(z!='\n');
				if(wybr.uzyj>='1' && wybr.uzyj<='8')
					kasew(wybr.uzyj-48+11);
				else if(wybr.uzyj=='i' || wybr.uzyj=='I')
					{	
					printf("Wybierz opcje dla ktorej chcesz przeczytac informacje: ");
					scanf("%c", &wybr.info);
					do
						z=getchar();
					while(z!='\n');
					if(wybr.info>='1' && wybr.info<='8')
						kasei(wybr.info-48+11);
					}
				else if(wybr.uzyj=='q' || wybr.uzyj=='Q')
					wybierz();
				system("clear");
				}
		}

void ust_pow()
	{	
		wibruj();
		system("clear");
		printf("Podaj nowe powitanie: ");
		FILE* pow = fopen("FILE/ustaw/pow","w");
		z='\0';
		while(z!='\n')
			{
			z=getchar();
			if(z!='\n')
				fprintf(pow, "%c", z);
			}
		fclose(pow);
		printf("\nNowe powitanie zostalo ustawione.\n");
		ustaw();
	}

void ust_bez()
	{
		wibruj();
		system("clear");
		char h1,h2[20],h3;
		int i;
		printf("Czy ustawic haslo [Y/N]: ");
		scanf("%c", &h1);
		do
			z=getchar();
		while(z!='\n');
		if(h1=='t' || h1=='y' || h1=='T' || h1=='Y')
			{
		if(h1=='y' || h1=='T' || h1=='Y')
			h1='t';		
			do
				{
				for(i=0;i<20;i++)
					h2[i]='\0';
				i=0;
				printf("Podaj nowe haslo: ");
				do
					{
					if(i!=20)
						scanf("%c", &h2[i]);
					if(i==20)
						{
						printf("ZBYT DLUGIE HASLO!\n");
						do
							z=getchar();
						while(z!='\n');
						}
					else if(h2[i]==' ')
						{
						printf("HASLO ZAWIERA NIEPRAWIDLOWE ZNAKI!\n");
						do
							z=getchar();
						while(z!='\n');
						}
					i++;
					}
					while(h2[i-1]!='\n' && h2[i-1]!=' ' && i!=21);
				}
				while(h2[i-1]!='\n');
				while(h3<'1' || h3>'9')
					{
					printf("Podaj ilosc mozliwych prob (min: 1, max: 9): ");
					scanf("%c", &h3);
						do
							z=getchar();
						while(z!='\n');
					system("clear");
					}
				FILE* hasl = fopen("FILE/ustaw/hasl","w");
				fprintf(hasl, "%c\n", h1);
				fprintf(hasl, "%s", h2);
				fprintf(hasl, "%c", h3);
				fclose(hasl);
			}
		else if(h1=='n' || h1=='N')
			{
			if(h1=='N')
				h1='n';
			FILE* hasl = fopen("FILE/ustaw/hasl","w");
			fprintf(hasl, "%c\n", h1);
			fclose(hasl);
			}
		if(h1=='n' || h1=='t')
			{
			printf("\nUstawienia zostaly zapisane.\n");
			spac(1);
			}
		ustaw();
	}

void ust_wib()
	{
	char wibra;
	wibruj();
	system("clear");
	int i;
	printf("Czy ustawic \"wibracje\" [Y/N]: ");
	scanf("%c", &wibra);
		do
			z=getchar();
		while(z!='\n');
	if(wibra=='t' || wibra=='y' || wibra=='T' || wibra=='Y')
		{
		FILE* wibracja = fopen("FILE/ustaw/wib","w");
		fprintf(wibracja, "t");
		fclose(wibracja);
		wibr=malloc(sizeof(char));
		*wibr='t';
		printf("\nUstawienia zostaly zapisane.\n");
		spac(1);
		}
	else if(wibra=='n' || wibra=='N')
		{
		FILE* wibracja = fopen("FILE/ustaw/wib","w");
		fprintf(wibracja, "n");
		fclose(wibracja);
		wibr=NULL;
		printf("\nUstawienia zostaly zapisane.\n");
		spac(1);
		}
	ustaw();
	}

void ust_dtcz()
	{
	wibruj();
	system("clear");
	wybor wybr;
	wybr.uzyj='\0';
	int i;
	while((wybr.uzyj<'1' || wybr.uzyj>'4')  && wybr.uzyj!='q' && wybr.uzyj!='Q')
		{
		printf("\nOpcje:\n");
		printf("\nI: Informacja\nQ: Wroc\n1: Data\n2: Godzina\n3: Data i godzina\n4: Wylacz\n\nWybierz opcje: ");
		scanf("%c", &wybr.uzyj);
		do
			z=getchar();
		while(z!='\n');
		if(wybr.uzyj=='1')
			{
				FILE* dacz = fopen("FILE/ustaw/dg","w");
				fprintf(dacz, "d");
				fclose(dacz);
				dg=malloc(sizeof(char));
				*dg='d';
				printf("\nUstawienia zostaly zapisane.\n");
				spac(1);
			}
		else if(wybr.uzyj=='2')
			{
				FILE* dacz = fopen("FILE/ustaw/dg","w");
				fprintf(dacz, "t");
				fclose(dacz);
				dg=malloc(sizeof(char));
				*dg='t';
				printf("\nUstawienia zostaly zapisane.\n");
				spac(1);
			}
		else if(wybr.uzyj=='3')
			{
				FILE* dacz = fopen("FILE/ustaw/dg","w");
				fprintf(dacz, "a");
				fclose(dacz);
				dg=malloc(sizeof(char));
				*dg='a';
				printf("\nUstawienia zostaly zapisane.\n");
				spac(1);
			}
		else if(wybr.uzyj=='4')
			{
				FILE* dacz = fopen("FILE/ustaw/dg","w");
				fprintf(dacz, "n");
				fclose(dacz);
				dg=NULL;
				printf("\nUstawienia zostaly zapisane.\n");
				spac(1);
			}
		else if(wybr.uzyj=='i' || wybr.uzyj=='I')
			{
				printf("Wybierz opcje dla ktorej chcesz przeczytac informacje: ");
				scanf("%c", &wybr.info);
				do
					z=getchar();
				while(z!='\n');
				if(wybr.info>='1' && wybr.info<='4')
					kasei(wybr.info-48+25);
			}
		system("clear");
		}
	ustaw();
	}

void ust_ka()
	{
	wibruj();
	system("clear");
	char wybr;
	int i;
	printf("Czy wlaczyc dodatek w kulator [Y/N]: ");
	scanf("%c", &wybr);
		do
			z=getchar();
		while(z!='\n');
	if(wybr=='t' || wybr=='y' || wybr=='T' || wybr=='Y')
		{
		FILE* kalkulator = fopen("FILE/ustaw/kal","w");
		fprintf(kalkulator, "t");
		fclose(kalkulator);
		ka=malloc(sizeof(char));
		*ka='t';
		printf("\nUstawienia zostaly zapisane.\n");
		spac(1);
		}
	else if(wybr=='n' || wybr=='N')
		{
		FILE* kalkulator = fopen("FILE/ustaw/kal","w");
		fprintf(kalkulator, "n");
		fclose(kalkulator);
		ka=NULL;
		printf("\nUstawienia zostaly zapisane.\n");
		spac(1);
		}
	ustaw();
	}

void ust_gry()
	{
	wibruj();
	system("clear");
	char wybr;
	int i;
	printf("Czy wlaczyc dodatkowe gry [Y/N]: ");
	scanf("%c", &wybr);
		do
			z=getchar();
		while(z!='\n');
	if(wybr=='t' || wybr=='y' || wybr=='T' || wybr=='Y')
		{
		FILE* gry = fopen("FILE/ustaw/gry","w");
		fprintf(gry, "t");
		fclose(gry);
		gr=malloc(sizeof(char));
		*gr='t';
		printf("\nUstawienia zostaly zapisane.\n");
		spac(1);
		}
	else if(wybr=='n' || wybr=='N')
		{
		FILE* gry = fopen("FILE/ustaw/gry","w");
		fprintf(gry, "n");
		fclose(gry);
		gr=NULL;
		printf("\nUstawienia zostaly zapisane.\n");
		spac(1);
		}
	ustaw();
	}

void ust_obr()
	{
	wibruj();
	system("clear");
	char wybr;
	int i;
	printf("Czy wlaczyc opcje obrazki [Y/N]: ");
	scanf("%c", &wybr);
		do
			z=getchar();
		while(z!='\n');
	if(wybr=='t' || wybr=='y' || wybr=='T' || wybr=='Y')
		{
		FILE* obrazek = fopen("FILE/ustaw/obr","w");
		fprintf(obrazek, "t");
		fclose(obrazek);
		ob=malloc(sizeof(char));
		*ob='t';
		printf("\nUstawienia zostaly zapisane.\n");
		spac(1);
		}
	else if(wybr=='n' || wybr=='N')
		{
		FILE* obrazek = fopen("FILE/ustaw/obr","w");
		fprintf(obrazek, "n");
		fclose(obrazek);
		ob=NULL;
		printf("\nUstawienia zostaly zapisane.\n");
		spac(1);
		}
	ustaw();
	}

void ust_fab()
	{
	wibruj();
	system("clear");
	char zg;
	printf("Czy napewno przyrocic ustawienia fabryczne [Y/N]: ");
	scanf("%c", &zg);
		do
			z=getchar();
		while(z!='\n');
	if(zg=='t' || zg=='T' || zg=='y' || zg=='Y')
			{
			FILE* powitanie = fopen("FILE/ustaw/pow","w");
			fprintf(powitanie, "WITAJ!");
			fclose(powitanie);
			FILE* haslo = fopen("FILE/ustaw/hasl","w");
			fprintf(haslo, "n");
			fclose(haslo);
			FILE* wibracje = fopen("FILE/ustaw/wib","w");
			fprintf(wibracje, "n");
			fclose(wibracje);
			FILE* data = fopen("FILE/ustaw/dg","w");
			fprintf(data, "a");
			fclose(data);
			FILE* kalkulator = fopen("FILE/ustaw/kal","w");
			fprintf(kalkulator, "n");
			fclose(kalkulator);
			FILE* gry = fopen("FILE/ustaw/gry","w");
			fprintf(gry, "n");
			fclose(gry);
			FILE* obrazek = fopen("FILE/ustaw/obr","w");
			fprintf(obrazek, "n");
			fclose(obrazek);
			printf("\nUstawienia zostaly zapisane.\n");
			spac(2);
			dg=malloc(sizeof(char));
			*dg='a';
			wibr=NULL; ka=NULL; gr=NULL; ob=NULL;
			}	
	ustaw();
	}

void spr_us()
	{
	wibr=NULL;
	dg=NULL;
	ka=NULL;
	gr=NULL;
	ob=NULL;
	char sp;
	FILE* wibracja = fopen("FILE/ustaw/wib","r");
	fscanf(wibracja, "%c", &sp);
	fclose(wibracja);
	if(sp=='t')
		{
		wibr=malloc(sizeof(char));
		*wibr='t';
		wibruj();
		}
	FILE* dataczas = fopen("FILE/ustaw/dg","r");
	fscanf(dataczas, "%c", &sp);
	fclose(dataczas);
	if(sp=='a')
		{
		dg=malloc(sizeof(char));
		*dg='a';
		}
	else if(sp=='t')
		{
		dg=malloc(sizeof(char));
		*dg='t';
		}
	else if(sp=='d')
		{
		dg=malloc(sizeof(char));
		*dg='d';
		}
	FILE* kalkulator = fopen("FILE/ustaw/kal","r");
	fscanf(kalkulator, "%c", &sp);
	fclose(kalkulator);
	if(sp=='t')
		{
		ka=malloc(sizeof(char));
		*ka='t';
		}
	FILE* gry = fopen("FILE/ustaw/gry","r");
	fscanf(gry, "%c", &sp);
	fclose(gry);
	if(sp=='t')
		{
		gr=malloc(sizeof(char));
		*gr='t';
		}
	FILE* obrazek = fopen("FILE/ustaw/obr","r");
	fscanf(obrazek, "%c", &sp);
	fclose(obrazek);
	if(sp=='t')
		{
		ob=malloc(sizeof(char));
		*ob='t';
		}
	}

void stoper()
	{
	wibruj();
	system("clear");
	char ile;
	printf("\nPodaj ilosc [max: 9]: ");
	scanf("%c", &ile);
	do
		z=getchar();
	while(z!='\n');
	if(ile < '0' || ile > '9')
		{
		printf("\nBLAD!\n");
		spac(1);
		}
	else
		{
		char ent;
		int il=0;
  		time_t czas;
  		time_t czas2;
		time (&czas);
		printf("\n\nWcisnij ENTER aby zatrzymac czas\n\n"); 
		while(il < ile-48)
			{
			do
				ent=getchar();
			while(ent!='\n');
			il++;
			time (&czas2);
			   printf("%i: %i sec.\n",il, (int)difftime(czas2, czas)); 
			}
		spac(1);
		}
	wybierz();
	}

lista dodaj (char slow[ilosc], lista lis)
	{
	lista p;
	p = malloc(sizeof(struct s1));
	if (lis == NULL)
		p->nast = NULL;
	else
		p->nast = lis;
	strcpy(p->slowko, slow);
	return p;
	}

void zapisz_kont(lista lis, lista lis2) 
	{
	FILE* kont = fopen("FILE/kont/kont","w");
	while (lis2 != NULL)
		{
		fprintf(kont, "%s ", lis->slowko);
		lis = lis->nast;
		fprintf(kont, "%s\n", lis2->slowko);
		lis2 = lis2->nast;
    		}
	fclose(kont);
	}

void zapisz_not(char* sc, lista lis) 
	{
	FILE* not = fopen(sc,"w");
	while (lis != NULL)
		{
		fprintf(not, "%s\n", lis->slowko);
		lis = lis->nast;
    		}
	fclose(not);
	}

int sprawdzaj(char* s, lista lis) 
	{
	int i=0;
	while (lis != NULL)
		{
		if(strcmp(s,lis->slowko)==0)
			i=1;
		lis = lis->nast;
    		}
	return i;
	}

int szukaj() 
	{
	char pom[ilosc];
	int ile=0;
	FILE* kont = fopen("FILE/kont/kont","r");
	while(fscanf(kont, "%s", pom) != EOF)
		ile++;
	fclose(kont);
	return ile/2;
	}

int sprawdz(char* sc) 
	{
	char pom[ilosc];
	int ile=0;
	FILE* not;
	not = fopen(sc,"r");
	while(fscanf(not, "%s", pom) != EOF)
		ile++;
	fclose(not);
	return ile;
	}

void sort_kont() 
	{
	int i=0,j=1,l=0;
	int ile;
	ile=szukaj();
	int k=ile;
	char pom[ilosc], tab[ile][ilosc], tab2[ile][ilosc];
	FILE* not = fopen("FILE/kont/kont","r");
	while(fscanf(not, "%s", tab[i]) != EOF)
		{
		fscanf(not, "%s", tab2[i]);
		i++;
		}
	fclose(not);
	while (k>1)
		{
		for(i=1;i<k;i++)
			{
			while(tab[i-1][l] == tab[i][l])
				l++;
			if (tab[i-1][l] > tab[i][l])
				{
				strcpy(pom,tab[i-1]);
				strcpy(tab[i-1],tab[i]);
				strcpy(tab[i],pom);
				strcpy(pom,tab2[i-1]);
				strcpy(tab2[i-1],tab2[i]);
				strcpy(tab2[i],pom);
				}
			j=i;
			l=0;
			}
		k=j;
		}
	FILE* not2 = fopen("FILE/kont/kont","w");
	for(i=0; i<ile; i++)
		fprintf(not, "%s %s\n", tab[i], tab2[i]);
	fclose(not2); 
	}

void sort_not(char* sc) 
	{
	int i=0,j=1,l=0;
	int ile;
	ile=sprawdz(sc);
	int k=ile;
	char pom[ilosc], tab[ile][ilosc];
	FILE* not = fopen(sc,"r");
	while(fscanf(not, "%s", tab[i]) != EOF)
		i++;
	fclose(not);
	while (k>1)
		{
		for(i=1;i<k;i++)
			{
			while(tab[i-1][l] == tab[i][l])
				l++;
			if (tab[i-1][l] > tab[i][l])
				{
				strcpy(pom,tab[i-1]);
				strcpy(tab[i-1],tab[i]);
				strcpy(tab[i],pom);
				}
			j=i;
			l=0;
			}
		k=j;
		}
	FILE* not2 = fopen(sc,"w");
	for(i=0; i<ile; i++)
		fprintf(not, "%s\n", tab[i]);
	fclose(not2); 
	}

void zamien(char* nazwa, char* numer, lista lis, lista lis2)
	{
	while(strcmp(nazwa,lis->slowko)!=0)
		{
		lis = lis->nast;
		lis2 = lis2->nast;
		}
		strcpy(lis2->slowko, numer);
	}

char* spradz_czy_zapisany(char* s)
	{
		kontakt wybr;
		FILE* kont = fopen("FILE/kont/kont","r");
		while(fscanf(kont, "%s", wybr.nazwa) != EOF)
			{
			fscanf(kont, "%s", wybr.numer);
			if(strcmp(wybr.numer,s)==0)
				strcpy(s,wybr.nazwa);
			}
		fclose(kont);
		return s;
	}

int prefiks(char* s)
	{
	int zm=0;
	if(
	(s[0]=='5' && s[1]=='0') ||
	(s[0]=='5' && s[1]=='1') ||
	(s[0]=='5' && s[1]=='3' && s[2]=='0') ||
	(s[0]=='5' && s[1]=='3' && s[2]=='1') ||
	(s[0]=='5' && s[1]=='3' && s[2]=='3') ||
	(s[0]=='5' && s[1]=='3' && s[2]=='5') ||
	(s[0]=='5' && s[1]=='3' && s[2]=='6') ||
	(s[0]=='5' && s[1]=='3' && s[2]=='9') ||
	(s[0]=='6' && s[1]=='0') ||
	(s[0]=='6' && s[1]=='6') ||
	(s[0]=='6' && s[1]=='9' && s[2]=='0') ||
	(s[0]=='6' && s[1]=='9' && s[2]=='1') ||
	(s[0]=='6' && s[1]=='9' && s[2]=='2') ||
	(s[0]=='6' && s[1]=='9' && s[2]=='3') ||
	(s[0]=='6' && s[1]=='9' && s[2]=='4') ||
	(s[0]=='6' && s[1]=='9' && s[2]=='5') ||
	(s[0]=='6' && s[1]=='9' && s[2]=='6') ||
	(s[0]=='6' && s[1]=='9' && s[2]=='7') ||
	(s[0]=='6' && s[1]=='9' && s[2]=='8') ||
	(s[0]=='7' && s[1]=='2' && s[2]=='0') ||
	(s[0]=='7' && s[1]=='2' && s[2]=='1') ||
	(s[0]=='7' && s[1]=='2' && s[2]=='2') ||
	(s[0]=='7' && s[1]=='2' && s[2]=='3') ||
	(s[0]=='7' && s[1]=='2' && s[2]=='4') ||
	(s[0]=='7' && s[1]=='2' && s[2]=='5') ||
	(s[0]=='7' && s[1]=='2' && s[2]=='6') ||
	(s[0]=='7' && s[1]=='2' && s[2]=='8') ||
	(s[0]=='7' && s[1]=='2' && s[2]=='9') ||
	(s[0]=='7' && s[1]=='3' && s[2]=='0') ||
	(s[0]=='7' && s[1]=='3' && s[2]=='1') ||
	(s[0]=='7' && s[1]=='3' && s[2]=='2') ||
	(s[0]=='7' && s[1]=='3' && s[2]=='3') ||
	(s[0]=='7' && s[1]=='3' && s[2]=='9') ||
	(s[0]=='7' && s[1]=='8' && s[2]=='1') ||
	(s[0]=='7' && s[1]=='8' && s[2]=='2') ||
	(s[0]=='7' && s[1]=='8' && s[2]=='3') ||
	(s[0]=='7' && s[1]=='8' && s[2]=='4') ||
	(s[0]=='7' && s[1]=='8' && s[2]=='5') ||
	(s[0]=='7' && s[1]=='8' && s[2]=='6') ||
	(s[0]=='7' && s[1]=='8' && s[2]=='7') ||
	(s[0]=='7' && s[1]=='8' && s[2]=='8') ||
	(s[0]=='7' && s[1]=='9') ||
	(s[0]=='8' && s[1]=='8' && s[2]=='0') ||
	(s[0]=='8' && s[1]=='8' && s[2]=='1') ||
	(s[0]=='8' && s[1]=='8' && s[2]=='3') ||
	(s[0]=='8' && s[1]=='8' && s[2]=='4') ||
	(s[0]=='8' && s[1]=='8' && s[2]=='5') ||
	(s[0]=='8' && s[1]=='8' && s[2]=='6') ||
	(s[0]=='8' && s[1]=='8' && s[2]=='7') ||
	(s[0]=='8' && s[1]=='8' && s[2]=='8') ||
	(s[0]=='8' && s[1]=='8' && s[2]=='9') 
	)
		zm=1;
	return zm;
	}


int spr_numer(char* s)
	{
	int zm=0, i=0;
	if(strlen(s) != 9)
		zm=1;
	while (i<9)
		{
		if(s[i]<'0' || s[i]>'9')
			zm=1;
		i++;
		}
	if(prefiks(s)==0)
	zm=1;
	return zm;
	}

void losuj(char* s, int los, int w)
	{
		if(los==0)
			printf("\nTrwa wysylanie wiadomosci do %s\n", s);
		else
			printf("\nTrwa laczenie z %s\n", s);
		spac(5);
		switch (los)
			{
		     	case 0:
			printf("\n\nWYSLANIE WIADOMOSCI NIE POWIODLO SIE! SPROBOJ POZNIEJ!\n\n");
			sleep(3);
			kasew(w);
			break;
			case 1:
			printf("\n\nWYBRANY NUMER PROWADZI W TEJ CHWILI ROZMOWE!\n\n");
			sleep(3);
			kasew(w);
			break;
			case 2:
			printf("\n\nWYBRANY NUMER MA WYLACZONY TELEFON!\n\n");
			sleep(3);
			kasew(w);
			break;
			case 3:
			printf("\n\nWYBRANY NUMER JEST POZA ZASIEGIEM!\n\n");
			sleep(3);
			kasew(w);
			break;
			}
	}

void wyb_num_dzwon(int p, int d)
	{
	wibruj();
	system("clear");
	int ile=0;
	char numer[10], s[ilosc];
	printf("\nPodaj numer: ");
	do
		{
		scanf("%c", &numer[ile]);
		ile++;
		}
	while(numer[ile-1]!='\n');
	numer[ile-1]='\0';
	if(spr_numer(numer)==1)
		{
		printf("\nNIE MA TAKIEGO NUMERU!\n");
		spac(3);
		kasew(1);
		}
	else
		{
		int los;
    		srand(time(NULL));
   		los=(int)rand()%p+d;
		strcpy(s,spradz_czy_zapisany(numer));
		losuj(s, los, 1);
		}
	}

void szuk_num_dzwon(int p, int d)
		{
		wibruj();
		system("clear");
		int ile, los;
		char slowo[ilosc],n1,n2,s[ilosc];
		kontakt wybr;
		printf("\nQ: Wroc\n\nTwoje kontakty:\n");
		FILE* kont = fopen("FILE/kont/kont","r");
		ile=1;
		while(fscanf(kont, "%s", wybr.nazwa) != EOF)
			{
			fscanf(kont, "%s", wybr.numer);
			printf("%i: %s\n", ile, wybr.nazwa);
			ile++;
			}
		printf("\nWybierz opcje: ");
		scanf("%c", &n1);
		scanf("%c", &n2);
		if(n2!='\n')
			do
				z=getchar();
			while(z!='\n');
		if(n1!='q' && n1!='Q')
			{
			if(n2>='0' && n2<='9')
				n1=(10*(n1-48))+(n2-48);
			else
				n1-=48;
			if(n1>0 && n1<ile)
				{
				rewind(kont);
				ile=0;
				do
					{
					fscanf(kont, "%s", wybr.nazwa);
					fscanf(kont, "%s", wybr.numer);
					ile++;
					}
				while(ile!=n1);
				if(spr_numer(wybr.numer)==1)
					{
					printf("\nNIE MA TAKIEGO NUMERU!\n");
					spac(3);
					kasew(1);
					}
				else
					{
					int los;
    					srand(time(NULL));
   					los=(int)rand()%p+d;
					strcpy(s,spradz_czy_zapisany(wybr.numer));
					losuj(s, los, 1);
					}
				fclose(kont);	
				}
			else
				{
				printf("\nBRAK TAKIEGO KONTAKTU!\n");
				spac(1);
				fclose(kont);
				kasew(1);
				}
			}
		else
		kasew(1);
		}

void dzwon()
	{
	wibruj();	
	system("clear");
	char wybr;
	wybr='\0';
	while(wybr!='1' && wybr!='2'  && wybr!='q' && wybr!='Q')
		{
		printf("\nOpcje:\n");
		printf("\nQ: Wroc\n1: Wpisz numer\n2: Szukaj w kontaktach\n");
		printf("\nWybierz opcje: ");
		scanf("%c", &wybr);
		do
			z=getchar();
		while(z!='\n');
		if(wybr=='1')
			wyb_num_dzwon(3,1);
		if(wybr=='2')
			szuk_num_dzwon(3,1);
		if(wybr=='Q' || wybr=='q')
			wybierz();
		system("clear");
		}	
	}

void wyb_num_wiad(int p, int d)
	{
	wibruj();
	system("clear");
	int ile=0;
	char numer[10], s[ilosc];
	printf("\nPodaj numer: ");
	do
		{
		scanf("%c", &numer[ile]);
		ile++;
		}
	while(numer[ile-1]!='\n');
	numer[ile-1]='\0';
	if(spr_numer(numer)==1)
		{
		printf("\nNIE MA TAKIEGO NUMERU!\n");
		spac(3);
		kasew(2);
		}
	else
		{
		printf("\nWpisz wiadomosc [ENTER - wyslij]: ");
		do
			z=getchar();
		while(z!='\n');
		int los;
    		srand(time(NULL));
   		los=(int)rand()%p+d;
		strcpy(s,spradz_czy_zapisany(numer));
		losuj(s, los, 2);
		}
	}

void szuk_num_wiad(int p, int d)
		{
		wibruj();
		system("clear");
		int ile, los;
		char slowo[ilosc],n1,n2,s[ilosc];
		kontakt wybr;
		printf("\nQ: Wroc\n\nTwoje kontakty:\n");
		FILE* kont = fopen("FILE/kont/kont","r");
		ile=1;
		while(fscanf(kont, "%s", wybr.nazwa) != EOF)
			{
			fscanf(kont, "%s", wybr.numer);
			printf("%i: %s\n", ile, wybr.nazwa);
			ile++;
			}
		printf("\nWybierz opcje: ");
		scanf("%c", &n1);
		scanf("%c", &n2);
		if(n1!='q' && n1!='Q')
			{
			if(n2!='\n')
				do
					z=getchar();
				while(z!='\n');
			if(n2>='0' && n2<='9')
				n1=(10*(n1-48))+(n2-48);
			else
				n1-=48;
			if(n1>0 && n1<ile)
				{
				rewind(kont);
				ile=0;
				do
					{
					fscanf(kont, "%s", wybr.nazwa);
					fscanf(kont, "%s", wybr.numer);
					ile++;
					}
				while(ile!=n1);
				if(spr_numer(wybr.numer)==1)
					{
					printf("\nNIE MA TAKIEGO NUMERU!\n");
					spac(3);
					kasew(2);
					}
				else
					{
					printf("\nWpisz wiadomosc [ENTER - wyslij]: ");
					do
						z=getchar();
					while(z!='\n');
					int los;
    					srand(time(NULL));
   					los=(int)rand()%p+d;
					strcpy(s,spradz_czy_zapisany(wybr.numer));
					losuj(s, los, 2);
					}
				fclose(kont);	
				}
			else
				{
				printf("\nBRAK TAKIEGO KONTAKTU!\n");
				spac(1);
				fclose(kont);
				kasew(2);
				}
		}
		else
		kasew(2);
		}

void sms()
	{
	wibruj();
	system("clear");	
	char wybr='\0';
	while(wybr!='1' && wybr!='2'  && wybr!='q' && wybr!='Q')
		{
		printf("\nOpcje:\n");
		printf("\nQ: Wroc\n1: Wpisz numer\n2: Szukaj w kontaktach\n");
		printf("\nWybierz opcje: ");
		scanf("%c", &wybr);
		do
			z=getchar();
		while(z!='\n');
		if(wybr=='1')
			wyb_num_wiad(1,0);
		if(wybr=='2')
			szuk_num_wiad(1,0);
		if(wybr=='Q' || wybr=='q')
			wybierz();
		system("clear");
		}	
	}

void dod_kont() 
	{
	wibruj();
	system("clear");
	int ile;
	char slowo[ilosc], zg='t';
	kontakt wybr;
	ile=0;
	z='\0';
	if(szukaj()==99)
		{
		printf("ZBYT DUZO KONTAKTOW, ABY DODAC NOWY MUSISZ JAKIS USUNAC!\n");
		spac(3);
		kasew(3);	
		}
	else
		{
		printf("\nPodaj nazwe kontaktu: ");
		do
			{
			scanf("%c", &wybr.nazwa[ile]);
			ile++;
			if(wybr.nazwa[ile-1]==' ')
				ile--;
			}
		while(wybr.nazwa[ile-1]!='\n');
		wybr.nazwa[ile-1]='\0';
		printf("\nPodaj numer: ");
		ile=0;
		do
			{
			scanf("%c", &wybr.numer[ile]);
			ile++;
			if(wybr.numer[ile-1]==' ')
				ile--;
			}
		while(wybr.numer[ile-1]!='\n');
		wybr.numer[ile-1]='\0';
		lista lis=NULL;
		lista lis2=NULL;
		FILE* kont = fopen("FILE/kont/kont","r");
		while(fscanf(kont, "%s", slowo) != EOF)
			{
			lis=dodaj(slowo, lis);
			fscanf(kont, "%s", slowo);
			lis2=dodaj(slowo, lis2);
			}
		fclose(kont);
		if(spr_numer(wybr.numer)==1)
			{
			printf("Numer jest nieprawidlowy. Czy napewno zapisac? [Y/N]: ");
			scanf("%c", &zg);
			do
				z=getchar();
			while(z!='\n');
			}
		if(sprawdzaj(wybr.nazwa, lis)==1 && zg=='t')
			{
			printf("Kontakt o takiej nazwie juz istnieje. Czy nastapic? [Y/N]: ");
			scanf("%c",&zg);
			do
				z=getchar();
			while(z!='\n');
			z='t';
			}
		if(zg=='t' || zg=='T' || zg=='y' || zg=='Y')
			{
			if(z!='t')
				{
				lis=dodaj(wybr.nazwa, lis);
				lis2=dodaj(wybr.numer, lis2);
				}
			else
				zamien(wybr.nazwa,wybr.numer,lis,lis2);
			zapisz_kont(lis, lis2);
			sort_kont();
			printf("\nNowy kontakt zostal dodany.\n");
			spac(1);
			}
		if(lis!=NULL)
			{
			free(lis->slowko);
			free(lis->nast);
			}
		if(lis2!=NULL)
			{
			free(lis2->slowko);
			free(lis2->nast);
			}
		kasew(3);
		}
	}


void czyt_kont()
	{
	wibruj();
	system("clear");
	int ile;
	char slowo[ilosc],n1,n2;
	kontakt wybr;
	printf("\nQ: Wroc\n\nTwoje kontakty:\n");
	FILE* kont = fopen("FILE/kont/kont","r");
		ile=1;
			while(fscanf(kont, "%s", wybr.nazwa) != EOF)
				{
				fscanf(kont, "%s", wybr.numer);
				printf("%i: %s\n", ile, wybr.nazwa);
				ile++;
				}
			printf("\nWybierz opcje: ");
			scanf("%c", &n1);
			scanf("%c", &n2);
			if(n2!='\n')
				do
					z=getchar();
				while(z!='\n');
			if(n1!='q' && n1!='Q')
				{
				if(n2>='0' && n2<='9')
					n1=(10*(n1-48))+(n2-48);
				else
					n1-=48;
				if(n1>0 && n1<ile)
					{
					system("clear");
					char opcja;
					opcja='0';
					while((opcja<'1' || opcja>'3') && opcja!='Q' && opcja!='q')
					{
					printf("\nOpcje:\n\nQ: Wroc\n1: Zadzwon\n2: Wiadomosc\n3: Zobacz/edytuj numer\n\n");
					printf("Wybierz opcje: ");
					scanf("%c", &opcja);
					do
						z=getchar();
					while(z!='\n');
					rewind(kont);
					ile=0;
					do
						{
						fscanf(kont, "%s", wybr.nazwa);
						fscanf(kont, "%s", wybr.numer);
						ile++;
						}
					while(ile!=n1);
					if(opcja=='1')
						{
						if(spr_numer(wybr.numer)==1)
							{
							printf("\nNIE MA TAKIEGO NUMERU!\n");
							spac(3);
							kasew(3);
							}
						else
							{
							int los;
    							srand(time(NULL));
   							los=(int)rand()%3+1;
							losuj(wybr.nazwa, los, 3);
							}
						}
					else if(opcja=='2')
						{
						if(spr_numer(wybr.numer)==1)
							{
							printf("\nNIE MA TAKIEGO NUMERU!\n");
							spac(3);
							kasew(3);
							}
						else
							{
							system("clear");
							printf("\nWpisz wiadomosc [ENTER - wyslij]: ");
							do
								z=getchar();
							while(z!='\n');
							losuj(wybr.nazwa, 0, 3);
							}
						}
					else if(opcja=='3')
						{
						system("clear");
						printf("\nNumer to: %s", wybr.numer);
						printf("\nCzy edytowac numer [Y/N]: ");
						scanf("%c", &opcja);
						do
							z=getchar();
						while(z!='\n');
						if(opcja=='t' || opcja=='T' || opcja=='y' || opcja=='Y')
							{
							printf("Podaj nowy numer: ");
							int ile=0;
							char zg='t';
							do
								{
								scanf("%c", &wybr.numer[ile]);
								ile++;
								if(wybr.numer[ile-1]==' ')
									ile--;
								}
							while(wybr.numer[ile-1]!='\n');
							wybr.numer[ile-1]='\0';
							if(spr_numer(wybr.numer)==1)
								{
								printf("Numer jest nieprawidlowy. Czy napewno zapisac? [Y/N]: ");
								scanf("%c", &zg);
								do
									z=getchar();
								while(z!='\n');
								}
							if(zg=='T' || zg=='t' || zg=='y' || zg=='Y')
								{
								lista lis=NULL, lis2=NULL;
								FILE* kont = fopen("FILE/kont/kont","r");
								while(fscanf(kont, "%s", slowo) != EOF)
									{
									lis=dodaj(slowo, lis);
									fscanf(kont, "%s", slowo);
									lis2=dodaj(slowo, lis2);
									}
								zamien(wybr.nazwa,wybr.numer,lis,lis2);
								zapisz_kont(lis, lis2);
								sort_kont();
								if(lis!=NULL)
									{
									free(lis->slowko);
									free(lis->nast);
									}
								if(lis2!=NULL)
									{
									free(lis2->slowko);
									free(lis2->nast);
									}
								fclose(kont);
								printf("\nNowy numer zostal zapisany!");
								printf("\n");
								spac(2);
								}
							}
						opcja='3';
						}
					if(opcja!='1' && opcja!='2')
						kasew(3);
					system("clear");
					}
				}
			else
				{
				printf("\nBRAK TAKIEGO KONTAKTU!\n");
				spac(1);
				fclose(kont);
				kasew(3);
				} 
			}
		else
		kasew(3);
	}

void us_kont()
	{
	wibruj();
	system("clear");
	int ile;
	kontakt wybr;
	char n1,n2;
	printf("\nQ: Wroc\n\nTwoje kontakty:\n");
	FILE* kont = fopen("FILE/kont/kont","r");
		ile=1;
			while(fscanf(kont, "%s", wybr.nazwa) != EOF)
				{
				printf("%i: %s\n", ile, wybr.nazwa);
				ile++;
				fscanf(kont, "%s", wybr.numer);
				}
			printf("\nWybierz opcje: ");
			scanf("%c", &n1);
			scanf("%c", &n2);
			if(n2!='\n')
				do
					z=getchar();
				while(z!='\n');
			if(n1!='q' && n1!='Q')
				{
			if(n2>='0' && n2<='9')
					n1=(10*(n1-48))+(n2-48);
				else
					n1-=48;
			if(n1>0 && n1<ile)
				{
				char zn, sl[ilosc];
				kontakt wybr;
				printf("Czy na pewno chcesz usunac ten kontakt? [Y/N]: ");
				scanf("%c",&zn);
				do
					z=getchar();
				while(z!='\n'); 
				if(zn=='T' || zn=='t' || zn=='Y' || zn=='y')
					{
					lista lis=NULL, lis2=NULL;
					rewind(kont);
					ile=0;
					do
						{
						fscanf(kont, "%s", wybr.nazwa);
						ile++;
						fscanf(kont, "%s", wybr.numer);
						}
					while(ile!=n1);
					rewind(kont);
					while(fscanf(kont, "%s", sl) != EOF)
						if(strcmp(wybr.nazwa, sl)!=0)
							{
							lis=dodaj(sl, lis);
							fscanf(kont, "%s", wybr.numer);
							lis2=dodaj(wybr.numer, lis2);
							}
						else
							fscanf(kont, "%s", wybr.numer);
					fclose(kont);
					zapisz_kont(lis, lis2);
					sort_kont();
					printf("\nKontakt usuniety!\n");
					if(lis!=NULL)
						{
						free(lis->slowko);
						free(lis->nast);
						}
					if(lis2!=NULL)
						{
						free(lis2->slowko);
						free(lis2->nast);
						}
					spac(1);
					kasew(3);
					}
				else
					{
					fclose(kont);
					kasew(3);
					}
				}
			else
				{
				printf("\nBRAK TAKIEGO KONTAKTU!\n");
				spac(1);
				fclose(kont);
				kasew(3);
				}
			}
			else
				kasew(3);
		}

void kont()
	{
	wibruj();
	system("clear");
	wybor wybr;
	wybr.uzyj='0';
	while((wybr.uzyj<'1' || wybr.uzyj>'3') && wybr.uzyj!='Q' && wybr.uzyj!='q')
		{
		printf("\nOpcje:\n");
		printf("\nI: Informacja\nQ: Wroc\n1: Dodaj kontakt\n2: Sprawdz kontakty\n3: Usun kontakt\n");
		printf("\nWybierz opcje: ");
		scanf("%c", &wybr.uzyj);
		do
			z=getchar();
		while(z!='\n');
		if(wybr.uzyj>='1' && wybr.uzyj<='3')
			kasew(wybr.uzyj-48+22);
		else if(wybr.uzyj=='i' || wybr.uzyj=='I')
					{
					printf("Wybierz opcje dla ktorej chcesz przeczytac informacje: ");
					scanf("%c", &wybr.info);
					do
						{
						z=getchar();
						}
					while(z!='\n');	
					if(wybr.info>='1' && wybr.info<='3')
						kasei(wybr.info-48+22);
					}
		else if(wybr.uzyj=='Q' || wybr.uzyj=='q')
			wybierz();
		system("clear");
		}
	}


void dod_not()
	{
	wibruj();
	system("clear");
	int ile;
	z='\0';
	char slowo[ilosc], s1[9], zg='t',p1[]="FILE/notat/";
	ile=0;
	if(sprawdz("FILE/notat/nazw/nazw")==99)
		{
		printf("ZBYT DUZO NOTATEK, ABY DODAC NOWA MUSISZ JAKAS USUNAC!\n");
		spac(3);
		kasew(11);	
		}
	else
		{
		printf("\nPodaj nazwe notaki: ");
		do
			{
			scanf("%c", &s1[ile]);
			ile++;
			if(s1[ile-1]==' ')
				ile--;
			}
		while(s1[ile-1]!='\n');
		s1[ile-1]='\0';
		lista lis=NULL;
		FILE* not = fopen("FILE/notat/nazw/nazw","r");
		while(fscanf(not, "%s", slowo) != EOF)	
			lis=dodaj(slowo, lis);
		fclose(not);
		if(sprawdzaj(s1, lis)==1)
			{
			printf("Notatka o takiej nazwie juz istnieje. Czy nastapic? [Y/N]: ");
			scanf("%c",&zg);
			do
				z=getchar();
			while(z!='\n');
			z='t';
			}
		if(zg=='t' || zg=='T' || zg=='y' || zg=='Y')
			{
			if(z!='t')
				lis=dodaj(s1, lis);
			zapisz_not("FILE/notat/nazw/nazw", lis);
			sort_not("FILE/notat/nazw/nazw");
			FILE* not1;
			not1= fopen(strcat(p1,s1),"w");
			printf("\nPodaj tresc notatki: ");
			do
				{
				z=getchar();
				fprintf(not1, "%c", z);
				}
			while(z!='\n');
			fclose(not1);
			printf("\nNotatka zostala dodana.\n");
			spac(1);
			}
		if(lis!=NULL)
			{
			free(lis->slowko);
			free(lis->nast);
			}
		kasew(11);
		}
	}

void czyt_not()
	{
	wibruj();
	system("clear");
	int ile;
	char slowo[9],n1,n2;
	printf("\nQ: Wroc\n\nTwoje notatki:\n");
	FILE* not = fopen("FILE/notat/nazw/nazw","r");
		ile=1;
			while(fscanf(not, "%s", slowo) != EOF)
				{
				printf("%i: %s\n", ile, slowo);
				ile++;
				}
			printf("\nWybierz opcje: ");
			scanf("%c", &n1);
			scanf("%c", &n2);
			if(n2!='\n')
				do
					z=getchar();
				while(z!='\n');
			if(n1!='q' && n1!='Q')
				{
				if(n2>='0' && n2<='9')
					n1=(10*(n1-48))+(n2-48);
				else
					n1-=48;
			if(n1>0 && n1<ile)
				{
				char slow2[ilosc],p1[]="FILE/notat/";
				rewind(not);
				ile=0;
				do
					{
					fscanf(not, "%s", slowo);
					ile++;
					}
				while(ile!=n1);
				fclose(not);
				FILE* not2;
				printf("\n");
				not2=fopen(strcat(p1,slowo),"r");
				while(fscanf(not2, "%s", slow2) != EOF)
					{
					printf("%s ", slow2);
					}
				printf("\n");
				fclose(not2);
				spac(3);
				kasew(11);
				}
			else
				{
				printf("\nBRAK TAKIEJ NOTATKI!\n");
				spac(1);
				fclose(not);
				kasew(11);
				}
			}
		else
		kasew(11);
	}


void us_not()
	{
	wibruj();
	system("clear");
	int ile;
	char slowo[9],n1,n2;
	printf("\nQ: Wroc\n\nTwoje notatki:\n");
	FILE* not = fopen("FILE/notat/nazw/nazw","r");
		ile=1;
			while(fscanf(not, "%s", slowo) != EOF)
				{
				printf("%i: %s\n", ile, slowo);
				ile++;
				}
			printf("\nWybierz opcje: ");
			scanf("%c", &n1);
			scanf("%c", &n2);
			if(n2!='\n')
				do
					z=getchar();
				while(z!='\n');
			if(n1!='q' && n1!='Q')
				{	
				if(n2>='0' && n2<='9')
					n1=(10*(n1-48))+(n2-48);
				else
					n1-=48;
				if(n1>0 && n1<ile)
				{
				char p1[]="FILE/notat/",zn,sl[ilosc];
				printf("Czy na pewno chcesz usunac notatke? [Y/N]: ");
				scanf("%c",&zn);
				do
					z=getchar();
				while(z!='\n'); 
				if(zn=='T' || zn=='t' || zn=='Y' || zn=='y')
					{
					lista lis=NULL;
					rewind(not);
					ile=0;
					do
						{
						fscanf(not, "%s", slowo);
						ile++;
						}
					while(ile!=n1);
					rewind(not);
					while(fscanf(not, "%s", sl) != EOF)
						if(strcmp(slowo, sl)!=0)
							lis=dodaj(sl, lis);
					fclose(not);
					zapisz_not("FILE/notat/nazw/nazw", lis);
					sort_not("FILE/notat/nazw/nazw");
					remove(strcat(p1,slowo));
					printf("\nNotatka zostala usunieta!\n");
					if(lis!=NULL)
						{
						free(lis->slowko);
						free(lis->nast);
						}
					spac(1);
					kasew(11);
					}
				else
					{
					fclose(not);
					kasew(11);
					}
				}
			else
				{
				printf("\nBRAK TAKIEJ NOTATKI!\n");
				spac(1);
				fclose(not);
				kasew(11);
				}
			}
		else
			kasew(11);
	}

void notat()
	{
	wibruj();
	system("clear");
	wybor wybr;
	wybr.uzyj='\0';
	while((wybr.uzyj<'1' || wybr.uzyj>'3') && wybr.uzyj!='Q' && wybr.uzyj!='q')
		{
		printf("\nOpcje:\n");
		printf("\nI: Informacja\nQ: Wroc\n1: Utworz notatke\n2: Przeczytaj notatke\n3: Usun notatke\n");
		printf("\nWybierz opcje: ");
		scanf("%c", &wybr.uzyj);
		do
			z=getchar();
		while(z!='\n');
		if(wybr.uzyj>='1' && wybr.uzyj<='3')
			kasew(wybr.uzyj-48+19);
		else if(wybr.uzyj=='i' || wybr.uzyj=='I')
					{
					printf("Wybierz opcje dla ktorej chcesz przeczytac informacje: ");
					scanf("%c", &wybr.info);
					do
						{
						z=getchar();
						}
					while(z!='\n');	
					if(wybr.info>='1' && wybr.info<='3')
						kasei(wybr.info-48+19);
					}
		else if(wybr.uzyj=='Q' || wybr.uzyj=='q')
			wybierz();
		system("clear");
		}
	}

char* spr_data(int d, int m, int r)
	{
	m--;
	int dzien=2,dz=1,ms=0,rk=1980;
	while((d!=dz || m!=ms || r!=rk) && rk<=2100)
		{
		if((ms==1-1 || ms==3-1 || ms==5-1 || ms==7-1 || ms==8-1 || ms==10-1 || ms ==12-1) && dz<31)
			{
			dz++;
			dzien++;
			if(dzien==7)
				dzien=0;
			}
		else if(((rk%4 == 0 && rk%100 != 0) || rk%400 == 0) && ms==2-1 && dz<29)
			{
			dz++;
			dzien++;
			if(dzien==7)
				dzien=0;
			}
		else if( ms==2-1 && dz<28)
			{
			dz++;
			dzien++;
			if(dzien==7)
				dzien=0;
			}
		else if((ms==4-1 || ms==6-1 || ms==9-1 || ms==11-1) && dz<30)
			{
			dz++;
			dzien++;
			if(dzien==7)
				dzien=0;
			}
		else if(dz==28 || dz==29 || dz==30 || dz==31)
			{
			ms++;
			dz=1;
			dzien++;
			if(dzien==7)
				dzien=0;
			}
		else if(ms==12)
			{
			rk++;
			ms=0;
			}
		}
	if(rk<=2100)
		{
		char* mies[] =  { "Sty", "Lut", "Mar", "Kwi", "Maj", "Cze",
    				"Lip", "Sie", "Wrz", "Paz", "Lis", "Gru" };
		char* dzie[] = { "Nie", "Pon", "Wto", "Sro", "Czw", "Pia", "Sob" };
		char* data, *miesiac, *dzionek;
		miesiac=NULL, dzionek=NULL;
		data=malloc(sizeof(char)*16);
		miesiac=malloc(sizeof(char)*3);
		dzionek=malloc(sizeof(char)*3);
		strcpy(miesiac, mies[ms]);
		strcpy(dzionek, dzie[dzien]);
		int i=0;
		if(dz>=10)
			data[0]=((dz/10)%10)+48;
		else
			data[0]=32;
		data[1]=(dz%10)+48;
		data[2]=' ';
		data[3]=miesiac[0];
		data[4]=miesiac[1];
		data[5]=miesiac[2];
		data[6]=' ';
		data[7]=((rk/1000)%10)+48;
		data[8]=((rk/100)%10)+48;
		data[9]=((rk/10)%10)+48;
		data[10]=(rk%10)+48;
		data[11]=':';
		data[12]=' ';
		data[13]=dzionek[0];
		data[14]=dzionek[1];
		data[15]=dzionek[2];
		data[16]='\0';
		data[17]='\0';
		data[18]='\0';
		data[19]='\0';
		data[20]='\0';
		return data;
		}
	else 
		return "BLEDNA DATA !!! (ZAKRES DAT TO ROK 1980-2100)";
	}

int data_licz(char* s)
	{
	int liczba;
	if(strlen(s)==1)
		{
		liczba=(s[0]-48);
		return liczba;
		}
	else if(strlen(s)==2)
		{
		liczba=10*(s[0]-48)+(s[1]-48);
		return liczba;
		}
	else if(strlen(s)==4)
		{
		liczba=1000*(s[0]-48)+100*(s[1]-48)+10*(s[2]-48)+(s[3]-48);
		return liczba;
		}
	else
		return -1;
	}

char* nazw_przyp(int d, int m, int r)
	{
		char* nazwa=malloc(sizeof(char)*8);
		nazwa[0]=((r/1000)%10)+48;
		nazwa[1]=((r/100)%10)+48;
		nazwa[2]=((r/10)%10)+48;
		nazwa[3]=(r%10)+48;
		nazwa[4]=((m/10)%10)+48;
		nazwa[5]=(m%10)+48;
		nazwa[6]=((d/10)%10)+48;
		nazwa[7]=(d%10)+48;
		nazwa[8]='\0';
		nazwa[9]='\0';
		nazwa[10]='\0';
		nazwa[11]='\0';
		nazwa[12]='\0';
		return nazwa;
	}

void sprawdz_czy(int d, int m, int r)
	{
	char naz[8], slo[8];
	strcpy(naz, nazw_przyp(d,m,r));
	FILE* przyp = fopen("FILE/przyp/nazw/nazw","r");
	while(fscanf(przyp, "%s", slo) != EOF)	
		if(strcmp(slo,naz)==0)
			{	
			printf("\nTwoje przypomnienie to: ");
			char slow2[ilosc],p1[]="FILE/przyp/";
			FILE* przy2;
			przy2=fopen(strcat(p1,slo),"r");
			while(fscanf(przy2, "%s", slow2) != EOF)
				printf("%s ", slow2);
			printf("\n");
			fclose(przy2);
			}
	fclose(przyp);
	}

void dod_przyp(int dz, int ms, int rk)
	{
	system("clear");
	int ile;
	z='\0';
	char slowo[ilosc], s1[8], zg='t',p1[]="FILE/przyp/";
	strcpy(s1, nazw_przyp(dz, ms, rk));
	ile=0;
	if(sprawdz("FILE/przyp/nazw/nazw")==99)
		{
		printf("ZBYT DUZO PRZYPOMNIEN, ABY DODAC NOWE MUSISZ JAKIES USUNAC!\n");
		spac(3);
		}
	else
		{
		lista lis=NULL;
		FILE* przyp = fopen("FILE/przyp/nazw/nazw","r");
		while(fscanf(przyp, "%s", slowo) != EOF)	
			lis=dodaj(slowo, lis);
		fclose(przyp);
		if(sprawdzaj(s1, lis)==1)
			{
			printf("\nPrzypomnienie na ten dzien juz istnieje. Czy nastapic? [Y/N]: ");
			scanf("%c",&zg);
			do
				z=getchar();
			while(z!='\n');
			z='t';
			}
		if(zg=='t' || zg=='T' || zg=='y' || zg=='Y')
			{
			if(z!='t')
				lis=dodaj(s1, lis);
			zapisz_not("FILE/przyp/nazw/nazw", lis);
			sort_not("FILE/przyp/nazw/nazw");
			FILE* przy1;
			przy1=fopen(strcat(p1,s1),"w");
			printf("\nPodaj tresc przypomnienia: ");
			do
				{
				z=getchar();
				fprintf(przy1, "%c", z);
				}
			while(z!='\n');
			fclose(przy1);
			printf("\nPrzypomnienie zostalo dodane.\n");
			spac(1);
			}
		if(lis!=NULL)
			{
			free(lis->slowko);
			free(lis->nast);
			}
		}
	}

czyt_przyp(char* slowo, int n1)
		{
		system("clear");
		FILE* przy = fopen("FILE/przyp/nazw/nazw","r");
		char slow2[ilosc],p1[]="FILE/przyp/";
		int ile=0;
		do
			{
			fscanf(przy, "%s", slowo);
			ile++;
			}
		while(ile!=n1);
		fclose(przy);
		FILE* przy2;
		printf("\n");
		przy2=fopen(strcat(p1,slowo),"r");
		while(fscanf(przy2, "%s", slow2) != EOF)
			{
			printf("%s ", slow2);
			}
		printf("\n");
		fclose(przy2);
		spac(3);
		}

us_przyp(n1)
 	{
	system("clear");
	char slowo[ilosc];
	FILE* przy = fopen("FILE/przyp/nazw/nazw","r");
	char p1[]="FILE/przyp/",zn,sl[ilosc];
	printf("Czy na pewno chcesz usunac przypomnienie? [Y/N]: ");
	scanf("%c",&zn);
		do
			z=getchar();
		while(z!='\n'); 
		if(zn=='T' || zn=='t' || zn=='Y' || zn=='y')
			{
			lista lis=NULL;
			int ile=0;
			do
				{
				fscanf(przy, "%s", slowo);
				ile++;
				}
			while(ile!=n1);
			rewind(przy);
			while(fscanf(przy, "%s", sl) != EOF)
				if(strcmp(slowo, sl)!=0)
					lis=dodaj(sl, lis);
			fclose(przy);
			zapisz_not("FILE/przyp/nazw/nazw", lis);
			sort_not("FILE/przyp/nazw/nazw");
			remove(strcat(p1,slowo));
			printf("\nPrzypomnienie zostalo usuniete!\n");
			if(lis!=NULL)
				{
				free(lis->slowko);
				free(lis->nast);
				}
			spac(1);
			}
		else	
			fclose(przy);
		}

void dod_przy()
	{
	wibruj();
	system("clear");
	typedef  struct 
		{
		char dzien[2];
		char miesiac[2];
		char rok[4];
		}  data;
	data wybr;
	int dz, ms, rk;
	printf("\n\nWSZYSTKIE DANE WPROWADZAJ LICZBOWO!\n");
	printf("\nPodaj dzien: ");
	scanf("%c", &wybr.dzien[0]);
	scanf("%c", &wybr.dzien[1]);
	wybr.dzien[2]='\0';
	if(wybr.dzien[1]!='\n')
		do
			{
			z=getchar();
			}
		while(z!='\n');
	else
		wybr.dzien[1]='\0';
	dz=data_licz(wybr.dzien);
	printf("\nPodaj miesiac: ");
	scanf("%c", &wybr.miesiac[0]);
	scanf("%c", &wybr.miesiac[1]);
	wybr.miesiac[2]='\0';
	if(wybr.miesiac[1]!='\n')
		do
			{
			z=getchar();
			}
		while(z!='\n');
	else
		wybr.miesiac[1]='\0';
	ms=data_licz(wybr.miesiac);
	printf("\nPodaj rok: ");
	scanf("%c", &wybr.rok[0]);
	scanf("%c", &wybr.rok[1]);
	scanf("%c", &wybr.rok[2]);
	scanf("%c", &wybr.rok[3]);
	do
		{
		z=getchar();
		}
	while(z!='\n');
	rk=data_licz(wybr.rok);
	printf("\n%s\n",spr_data(dz,ms,rk));
	spac(1);
	sprawdz_czy(dz,ms,rk);
	spac(1);
	if(strcmp(spr_data(dz,ms,rk),"BLEDNA DATA !!! (ZAKRES DAT TO ROK 1980-2100)")!=0)
		{
		char zg='n';
		printf("\nCzy chcesz dodac przypomnienie? [Y/N]: ");
		scanf("%c",&zg);
		do
			{
			z=getchar();
			}
		while(z!='\n');
		if(zg=='t' || zg=='T' || zg=='y' || zg=='Y')
			dod_przyp(dz,ms,rk);
		}
	kasew(6);
	}

void twoje_przy()
	{
	wibruj();
	system("clear");
	int ile,d,m,r;
	char slowo[8],n1,n2,opcja='\0';
	printf("\nQ: Wroc\n\nTwoje przypomnienia:\n");
	FILE* przy = fopen("FILE/przyp/nazw/nazw","r");
		ile=1;
			while(fscanf(przy, "%s", slowo) != EOF)
				{
				d=(10*(slowo[6]-48))+(slowo[7]-48);
				m=(10*(slowo[4]-48))+(slowo[5]-48);
				r=(1000*(slowo[0]-48))+(100*(slowo[1]-48))+(10*(slowo[2]-48))+(slowo[3]-48);
				printf("%i: %s\n", ile, spr_data(d,m,r));
				ile++;
				}
			printf("\nWybierz opcje: ");
			scanf("%c", &n1);
			scanf("%c", &n2);
			if(n2!='\n')
				do
					z=getchar();
				while(z!='\n');
			if(n1!='q' && n2!='Q')
				{
				if(n2>='0' && n2<='9')
					n1=(10*(n1-48))+(n2-48);
				else
					n1-=48;
				if(n1>0 && n1<ile)
				{
				fclose(przy);
				printf("\nOpcje:\n");
				while(opcja!='q' && opcja!='Q' && opcja!='1' && opcja!='2')
					{
					system("clear");
					printf("\nQ: Wroc\n1: Przeczytaj\n2: Usun\n\nWybierz opcje: ");
					scanf("%c", &opcja);
					do
						z=getchar();
					while(z!='\n');
					if(opcja=='1')
						czyt_przyp(slowo, n1);
					if(opcja=='2')
						us_przyp(n1);
					system("clear");
					}
				kasew(6);
				}
				else
					{
					printf("\nBRAK TAKIEGO PRZYPOMNIENIA!\n");
					spac(1);
					fclose(przy);
					kasew(6);
					} 
				}
			else
				kasew(6);
	}

void przyp()
	{
	wibruj();
	system("clear");
	wybor wybr;
	printf("\nOpcje:\n");
	while(wybr.uzyj!='1' && wybr.uzyj!='2' && wybr.uzyj!='Q' && wybr.uzyj!='q')
		{
		system("clear");
		printf("\nI: Informacja\nQ: Wroc\n1: Nowe przypomnienie\n2: Twoje przypomnienia\n");
		printf("\nWybierz opcje: ");
		scanf("%c", &wybr.uzyj);
		do
			z=getchar();
		while(z!='\n');
		if(wybr.uzyj=='1' || wybr.uzyj=='2')
			kasew(wybr.uzyj-48+29);
		else if(wybr.uzyj=='i' || wybr.uzyj=='I')
					{
					printf("Wybierz opcje dla ktorej chcesz przeczytac informacje: ");
					scanf("%c", &wybr.info);
					do
						{
						z=getchar();
						}
					while(z!='\n');	
					if(wybr.info=='1' || wybr.info=='2')
						kasei(wybr.info-48+29);
					}
		else if(wybr.uzyj=='Q' || wybr.uzyj=='q')
			wybierz();
		}
	}

double potega(double wynik)
	{
	int i, wyk;
	printf("\nPodaj calkowity wykladnik potegi: ");
	scanf("%i", &wyk);
	do
		z=getchar();
	while(z!='\n');
	if(wyk>0)
		{
		double pot=wynik;
		for(i=0; i<wyk-1; i++)
		wynik*=pot;;
		}
	else if(wyk==0)
		wynik=1;
	else
		{
		int i;
		double pom=wynik;
		wynik*=wynik;
		wynik=pom/wynik;
		pom=wyk;
		wyk-=wyk;
		wyk-=pom;
		double pot=wynik;
		for(i=0; i<wyk-1; i++)
			wynik*=pot;
		}
	return wynik;
	}

double logarytm(double wynik)
	{
	char wybr;
	printf("\nWybierz rodzaj logarytmu:\n1: Dziesietny\n2: Naturalny\n");
	printf("\nWybierz: ");
	scanf("%c", &wybr);
	do
		z=getchar();
	while(z!='\n');
	if(wybr=='1')
		wynik=log10(wynik);
	if(wybr=='2')
		wynik=log(wynik);
	return wynik;
	}

int dziele(double wynik)
	{
	printf("\nPod uwage jest brana czesc calkowita liczby.\n");
	int resz;
	printf("Podaj z jakiej liczby chcesz uzyskac reszte z dzielenia [Y/N]: ");
	scanf("%i", &resz);
	do
		z=getchar();
	while(z!='\n');
	wynik=(int)wynik%resz;
	return wynik;
	}

double trygono(double wynik)
	{
	double pi=3.14159265;
	char wybr;
	printf("\nWybierz funcje trygonometryczna:\n");
	printf("\n1: sin\n2: cos\n3: tg\n\nWybierz: ");
	scanf("%c", &wybr);
	do
		z=getchar();
	while(z!='\n');
	if(wybr=='1')
		wynik=sin(wynik*pi/180);
	else if(wybr=='2')
		wynik=cos(wynik*pi/180);
	else if(wybr=='3')
		wynik=tan(wynik*pi/180);
	return wynik;
	}

void kal_pr()
	{
		wibruj();
		system("clear");
		double *memory=NULL, liczba=0, wynik;
		char opcja='\0';
		printf("\nPodaj liczbe: ");
		scanf("%lf", &wynik);
		do
			z=getchar();
		while(z!='\n');
		printf("\nOpcje:\n+: Dodawanie \n-: Odejmowanie \n*: Mnozenie \n/: Dzielenie \n^: Potega \nS: Pierwiastek (st. 2) \n%%: Procent \nL: Logarytm dziesietny/naturalny\nM: Reszta z dzielenia (liczby calkowite)\nT: Funkcje trygonometryczne\nW: Zapisz pamiec \nR: Wczytaj pamiec\nD: Kasuj pamiec\nB: Nowa liczba\n");
		while(opcja!='Q' && opcja!='q')
			{
			printf("\nQ: Wroc\nH: Pomoc (wybor opcji)\n");
			printf("\nWybierz opcje: ");
			scanf("%c", &opcja);
			do
				z=getchar();
			while(z!='\n');
			if(opcja=='+')
				{
				printf("\nPodaj liczbe: ");
				scanf("%lf", &liczba);
				do
					z=getchar();
				while(z!='\n');
				wynik+=liczba;
				printf("\nWynik to: %.4lf", wynik);
				printf("\n");
				spac(2);
				}
			else if(opcja=='-')
				{
				printf("\nPodaj liczbe: ");
				scanf("%lf", &liczba);
				do
					z=getchar();
				while(z!='\n');
				wynik-=liczba;
				printf("\nWynik to: %.4lf", wynik);
				printf("\n");
				spac(2);
				}
			else if(opcja=='*')
				{
				printf("\nPodaj liczbe: ");
				scanf("%lf", &liczba);
				do
					z=getchar();
				while(z!='\n');
				wynik*=liczba;
				printf("\nWynik to: %.4lf", wynik);
				printf("\n");
				spac(2);
				}
			else if(opcja=='/')
				{
				printf("\nPodaj liczbe: ");
				scanf("%lf", &liczba);
				do
					z=getchar();
				while(z!='\n');
				wynik/=liczba;
				printf("\nWynik to: %.4lf", wynik);
				printf("\n");
				spac(2);
				}
			else if(opcja=='^')
				{
				wynik=potega(wynik);
				printf("\nWynik to: %.4lf", wynik);
				printf("\n");
				spac(2);
				}
			else if(opcja=='S' || opcja=='s')
				{
				wynik=sqrt(wynik);
				printf("\nWynik to: %.4lf", wynik);
				printf("\n");
				spac(2);
				}
			else if(opcja=='%')
				{
				wynik=wynik*0.01;
				printf("\nWynik to: %.4lf", wynik);
				printf("\n");
				spac(2);
				}
			else if(opcja=='L' || opcja=='l')
				{
				wynik=logarytm(wynik);
				printf("\nWynik to: %.4lf", wynik);
				printf("\n");
				spac(2);
				}
			else if(opcja=='M' || opcja=='m')
				{
				wynik=dziele(wynik);
				printf("\nWynik to: %.4lf", wynik);
				printf("\n");
				spac(2);
				}
			else if(opcja=='T' || opcja=='t')
				{
				wynik=trygono(wynik);	
				printf("\nWynik to: %.4lf", wynik);
				printf("\n");
				spac(2);
				}
			else if(opcja=='W' || opcja=='w')
				{
				memory=malloc(sizeof(wynik));
				*memory=wynik;
				printf("Liczba zostala zapisana w pamieci.\n");
				}
			else if(opcja=='R' || opcja=='r')
				{
				if(memory!=NULL)
					{
					char pam='\0';
					while(pam!='q' && pam!='Q')
						{
						printf("\nOpcje:\n\nQ: Wroc\n+: Dodawanie \n-: Odejmowanie \n*: Mnozenie \n/: Dzielenie\nI: Pokaz liczbe w pamieci\nO: Inna operacja na liczbie w pamieci (zmienia ta liczbe)\n");
						printf("\nWybierz opcje: ");
						scanf("%c", &pam);
						do
							z=getchar();
						while(z!='\n');
						if(pam=='O' || pam=='o')
							{
							char cos='\0';
							double pom;
							while(cos!='q' && cos!='Q')
								{
								printf("Q: Wroc\n^: Potega \nS: Pierwiastek (st. 2) \n%%: Procent \nL: Logarytm dziesietny/naturalny\nM: Reszta z dzielenia (liczby calkowite)\nT: Funkcje trygonometryczne\n\nWybierz opcje ktora chcesz wykonac dla liczby w pamieci: ");
								scanf("%c", &cos);
								do
									z=getchar();
								while(z!='\n');
								if(cos=='^')
									{
									pom=*memory;
									pom=potega(pom);
									memory=malloc(sizeof(pom));
									*memory=pom;
									printf("\nPamiec to: %.4lf", *memory);
									printf("\n");
									spac(2);
									}
								else if(cos=='S' || cos=='s')
									{
									pom=*memory;
									pom=sqrt(pom);
									memory=malloc(sizeof(pom));
									*memory=pom;
									printf("\nPamiec to: %.4lf", *memory);
									printf("\n");
									spac(2);
									}
								else if(cos=='%')
									{
									pom=*memory;
									pom=pom*0.01;
									memory=malloc(sizeof(pom));
									*memory=pom;
									printf("\nPamiec to: %.4lf", *memory);
									printf("\n");
									spac(2);
									}
								else if(cos=='L' || cos=='l')
									{
									pom=*memory;
									pom=logarytm(pom);
									memory=malloc(sizeof(pom));
									*memory=pom;
									printf("\nPamiec to: %.4lf", *memory);
									printf("\n");
									spac(2);
									}
								else if(cos=='M' || cos=='m')
									{
									pom=*memory;
									pom=dziele(pom);
									memory=malloc(sizeof(pom));
									*memory=pom;
									printf("\nPamiec to: %.4lf", *memory);
									printf("\n");
									spac(2);
									}
								else if(cos=='T' || cos=='t')
									{
									pom=*memory;
									pom=trygono(pom);	
									memory=malloc(sizeof(pom));
									*memory=pom;
									printf("\nPamiec to: %.4lf", *memory);
									printf("\n");
									spac(2);
									}

								}
							}
						if(pam=='I' || pam=='i')
							{
							printf("\nLiczba w pamieci to: %.4lf\n", *memory);
							spac(2);
							}
						else if(pam=='+')
							{
							wynik+=*memory;
							printf("Wykonano!\n");
							spac(2);
							}
						else if(pam=='-')
							{
							printf("Liczba w pamieci ma byc pierwsza/druga(domyslnie) [1/2]?: ");
							scanf("%c", &pam);
							do
								z=getchar();
							while(z!='\n');
							if(pam=='1')
								{
								wynik=*memory-wynik;
								printf("Wykonano!\n");
								spac(2);
								}
							else
								{
								wynik-=*memory;
								printf("Wykonano!\n");
								spac(2);
								}
							}
						else if(pam=='*')
							{
							wynik*=*memory;
							printf("Wykonano!\n");
							spac(2);
							}
						else if(pam=='/')
							{
							printf("Liczba w pamieci ma byc pierwsza/druga(domyslnie) [1/2]?: ");
							scanf("%c", &pam);
							do
								z=getchar();
							while(z!='\n');
							if(pam=='1')
								{
								wynik=*memory/wynik;
								printf("Wykonano\n");
								spac(2);
								}
							else	
								{
								wynik/=*memory;
								printf("Wykonano\n");
								spac(2);
								}
							}
						}
					printf("\nWynik to: %.4lf\n", wynik);
					}
				else
					printf("BRAK LICZBY W PAMIECI!\n");
				}	
			else if(opcja=='D' || opcja=='d')
				{
				if(memory!=NULL)
					{
					memory=NULL;
					printf("Liczba w pamieci zostala usunieta.\n");
					}
				else
					printf("BRAK LICZBY W PAMIECI!\n");
				}
			else if(opcja=='B' || opcja=='b')
				{
				printf("\nPoprzedia liczba zostala usunieta!\n");
				printf("\nPodaj liczbe: ");
				scanf("%lf", &wynik);
				do
					z=getchar();
				while(z!='\n');
				}
			else if(opcja=='Q' || opcja=='q')
				{
				wybierz();
				memory=NULL;
				}
			else if(opcja=='H' || opcja=='h')
				{
				printf("\nLiczba to: %.4lf\n", wynik);
				printf("\nOpcje:\n+: Dodawanie \n-: Odejmowanie \n*: Mnozenie \n/: Dzielenie \n^: Potega \nS: Pierwiastek (st. 2) \n%%: Procent \nL: Logarytm dziesietny/naturalny\nM: Reszta z dzielenia (liczby calkowite)\nT: Funkcje trygonometryczne\nW: Zapisz pamiec \nR: Wczytaj pamiec\nD: Kasuj pamiec\nB: Nowa liczba\n");
				spac(2);
				}
			}
	}

void kal()
	{
	char wybr;
	wybr='\0';
	if(ka!=NULL)
		{
		wibruj();
		system("clear");
		while(wybr!='1' && wybr!='2' && wybr!='q' && wybr!='Q')
			{
			system("clear");
			printf("\nWybierz:\n");
			printf("\nQ: Wroc\n1: Zwykly kalkulator\nDodatek:\n2: Dodatkowy kalkulator\n\nWybierz opcje: ");
			scanf("%c", &wybr);
			do
				z=getchar();
			while(z!='\n');
			}
		}
	else 
		wybr='1';
	if(wybr=='1')
		kal_pr();
	else if(wybr=='2')
		{	
		dod_opcja();
		kasew(10);
		}
	else if(wybr=='q' || wybr=='Q')
		wybierz();
	}

void zn_liczbe();

int spr_us1(char* s) 
	{
	int pom;
	int ile=0;
	FILE* gry = fopen(s,"r");
	fscanf(gry, "%i", &pom);
	fclose(gry);
	return pom;
	}

int spr_us2(char* s) 
	{
	int pom;
	int ile=0;
	FILE* gry = fopen(s,"r");
	fscanf(gry, "%i", &pom);
	fscanf(gry, "%i", &pom);
	fclose(gry);
	return pom;
	}

void grajzl(int p, int r)
{
	system("clear");	
	int liczba, zgaduj=0, ile=0, wynik;
	srand(time(NULL));
   	liczba=(int)rand()%r+1;
	printf("\nZakres losowania liczb: 1-%i\n", r);
	while(zgaduj!=liczba)
		{
		printf("\nPodaj liczbe: ");
		scanf("%i", &zgaduj);
		if(zgaduj>liczba)
			printf("Wylosowana liczba jest mniejsza\n");
		else if(zgaduj<liczba)	
			printf("Wylosowana liczba jest wieksza\n");
		ile++;		
		}
	printf("Gratulacje to jest ta liczba!\n");
	spac(3);
	wynik=spr_us1("FILE/gry/zn_li");
			if(ile<wynik)
				{
				FILE* gry = fopen("FILE/gry/zn_li","w");
				fprintf(gry, "%i\n%i", ile, r);
				fclose(gry);
				printf("\nNowy rekord !!!, twoj wynik to: %i\n", ile);
				spac(3);
				}
			else
				{
				printf("\nTwoj wynik to: %i\nNajlepszy wynik to: %i\n", ile, wynik);
				spac(3);
				}
	do
		z=getchar();
	while(z!='\n');
	zn_liczbe();
}

void uszl(int p, int r)
{
		system("clear");
		printf("Podaj zakres do ktorego mozna podawac liczby - od 1 do (nie mniejsza od 500 wieksza od 100000000): ");
		scanf("%i", &r);
		do
			z=getchar();
		while(z!='\n');
		if(r<=100000000 && r>=500)
			{
			FILE* gry = fopen("FILE/gry/zn_li","w");
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
	zn_liczbe();
}

void zn_liczbe()
	{
	char wyb;
	while(wyb!='1' && wyb!='2' && wyb!='q' && wyb!='Q')
		{
		system("clear");
		printf("\nOpcje:\n");
		printf("\nI: Instrukcja\nQ: Wyjdz\n1: Graj\n2: Ustawienia zakresu\n3: Najlepszy wynik\n\nWybierz opcje: ");
		scanf("%c", &wyb);
		do
			z=getchar();
		while(z!='\n');
		if(wyb=='i'|| wyb=='I')
			{
			printf("\nKomputer losuje liczbe z podanego zakresu. Zadaniem gracza jest odgadniecie jaka to jest liczba w taki sposob, ze gracz podaje propozycje liczby, zas komputer odpowiada czy dana liczba jest wieksza czy mniejsza\n");
			spac(9);
			}
		else if(wyb=='3')
			{
			system("clear");
			int wynik;
			wynik=spr_ust1("FILE/gry/zn_li");
			printf("\nNajlepszy wynik to: %i\n", wynik);
			spac(4);
			}
		}
	if(wyb=='1')
			{
			int p, r;
			p=spr_us1("FILE/gry/zn_li");
			r=spr_us2("FILE/gry/zn_li");
			grajzl(p,r);
			}
	else if(wyb=='2')
			{
			int p, r;
			p=spr_us1("FILE/gry/zn_li");
			r=spr_us2("FILE/gry/zn_li");
			uszl(p,r);
			}
	else if(wyb=='q' || wyb=='Q')
			gry();
	}

void wp_lit();

void grajwl(int p)
	{
	system("clear");
	int i=0;
	char slowo[320], zgaduj;
	srand(time(NULL));
	while(i<320)
		{
		int k=(int)rand()%2+1;
		if(k==1)
   			slowo[i]=(int)rand()%26+65;
		if(k==2)
			slowo[i]=(int)rand()%26+97;
		i++;
		}
	slowo[320]='\0';
	slowo[321]='\0';
	slowo[322]='\0';
	slowo[323]='\0';
	slowo[324]='\0';
	slowo[325]='\0';
	slowo[326]='\0';
	slowo[327]='\0';
	printf("%s\n", slowo);
	i=0;
  	time_t czas;
  	time_t czas2;
	zgaduj=getch();
	time (&czas);
	while(slowo[i]==zgaduj && i<320)
		{
		i++;
		zgaduj=getch();
		}
	time (&czas2);	
	if(i<320)
		{
		printf("Popelniles blad!\n");
		spac(2);
		}
	else
		{
		printf("Gratuluje wpisales wszystkie literki poprawnie!\n");
		spac(2);
		printf("Twoj czas to: %i sec.\n",(int)difftime(czas2, czas));
		if((int)difftime(czas2, czas)<p)
				{
				FILE* gry = fopen("FILE/gry/w_lit","w");
				fprintf(gry, "%i",(int)difftime(czas2, czas));
				fclose(gry);
				printf("Nowy rekord !!!\n");
				spac(3);
				}
			else
				{
				printf("Najlepszy czas to: %i  sec.\n", p);
				spac(3);
				}
		}
	wp_lit();
	}

void wp_lit()
	{
	char wyb;
	while(wyb!='1' && wyb!='q' && wyb!='Q')
		{
		system("clear");
		printf("\nOpcje:\n");
		printf("\nI: Instrukcja\nQ: Wyjdz\n1: Graj\n2: Najlepszy czas\n\nWybierz opcje: ");
		scanf("%c", &wyb);
		do
			z=getchar();
		while(z!='\n');
		if(wyb=='i'|| wyb=='I')
			{
			printf("\nZadaniem gracza jest powtorzenie ciagu literek wypisanego przez komputer w jak najszybszym czasie nie widzac literek ktore wczesniej wypisal. Jezeli gracz sie pomyli przegrywa gre. Przy wpisywanu wazna jest rowniez wielkosc liter.\n");
			spac(9);
			}
		else if(wyb=='2')
			{
			int wynik;
			wynik=spr_ust1("FILE/gry/w_lit");
			printf("\nNajlepszy czas to: %i sec.\n", wynik);
			spac(4);
			}
		}
	if(wyb=='1')
			{
			int p;
			p=spr_us1("FILE/gry/w_lit");
			grajwl(p);
			}
	else if(wyb=='q' || wyb=='Q')
			gry();
	}


void gry()
	{
	wibruj();
	system("clear");
	char wybr;
	char zmienna;
	wybr='\0';
	wibruj();
	if(gr!=NULL)
		zmienna='5';
	else
		zmienna='2';
	while((wybr<'1' || wybr>zmienna) && wybr!='q' && wybr!='Q')
		{
		system("clear");
		printf("\nWybierz:\n");
		if(gr!=NULL)
		printf("\nQ: Wroc\n1: Znajdz liczbe\n2: Wpisz literki\nDodadkowe gry:\n3: Sumuj liczbe\n4: Zgadnij slowo\n5: Kolko i krzyzyk\n\nWybierz opcje: ");
		else
		printf("\nQ: Wroc\n1: Znajdz liczbe\n2: Wpisz literki\n\nWybierz opcje: ");
		scanf("%c", &wybr);
		do
			z=getchar();
		while(z!='\n');
		if(wybr=='1')
			zn_liczbe();
		else if(wybr=='2')
			wp_lit();
		else if(wybr=='q' || wybr=='Q')
			wybierz();
		if(gr!=NULL)
			{
			if(wybr=='3')
				gra1();
			else if(wybr=='4')
				gra2();
			else if(wybr=='5')
				gra3();
			}
		}
	}

void kasew(int i)
{		
		switch (i) {
					case 1:
					dzwon();
					break;
					case 2:
					sms();
					break;
					case 3:
					kont();
					break;
					case 4:
					zdjecie();
					break;
					case 5:
					obrazki();
					break;
					case 6:
					przyp();
					break;
					case 7:
					gry();
					break;
		     			case 8:
					ustaw();
					break;
		     			case 9:
					stoper();
					break;
		     			case 10:
					kal();
					break;
		     			case 11:
					notat();
					break;
					case 12:
					ust_pow();
					break;
					case 13:
					ust_bez();
					break;
					case 14:
					ust_wib();
					break;
					case 15:
					ust_dtcz();
					break;
					case 16:
					ust_ka();
					break;
					case 17:
					ust_gry();
					break;
					case 18:
					ust_obr();
					break;
					case 19:
					ust_fab();
					break;
					case 20:
					dod_not();
					break;
					case 21:
					czyt_not();
					break;
					case 22:
					us_not();
					break;
					case 23:
					dod_kont();
					break;
					case 24:
					czyt_kont();
					break;
					case 25:
					us_kont();
					break;
					case 30:
					dod_przy();
					break;
					case 31:
					twoje_przy();
					break;
				}
}

void kasei(int i)
{
		switch (i) {
		     			case 1:
					printf("\n\nPozwala na wykonanie polaczenia z wybranym numerem telefonu komorkowego.\n\n");
					sleep(4);
					break;
					case 2:
					printf("\n\nPozwala na wyslanie wiadomosci SMS do wybranego numeru telefonu komorkowego.\n\n");
					sleep(4);
					break;
					case 3:
					printf("\n\nUmozliwia zapisanie nowego numeru telefonu oraz spradzenie/usuniecie wczesniej dodanych numerow.\n\n");
					sleep(5);
					break;
		     			case 4:
					printf("\n\nUmozliwia wykonanie zdjecia przy pomoy monitora.\n\n");
					sleep(4);
					break;
		     			case 5:
					printf("\n\nUruchamia obrazki wykonane przy pomocy oprogramowania OpenGL.\n\n");
					sleep(4);
					break;
		     			case 6:
					printf("\n\nUmozliwia ustawienie przypomnienia na okreslony dzien zakres to 1980-2100.\n\n");
					sleep(4);
					break;
		     			case 7:
					printf("\n\nUruchamia gry.\n\n");
					sleep(3);
					break;
					case 8:
					printf("\n\nZawiera ustawienia wszystkich opcji.\n\n");
					sleep(4);
					break;
		     			case 9:
					printf("\n\nPozwala na wymierzenie czasu w sekundach.\n\n");
					sleep(4);
					break;
					case 10:
					printf("\n\nKalkulator wykonujacy obliczenia: dodawanie, odejmowanie, mnozenie, dzielenie dwoch liczb, oraz potegowanie, pierwiastek, procent, logarytm, modulo, sinus, cosinus, tangens dla pojedynczej liczby. Posiada rowniez mozliwosc zapisania liczby w pamieci.\n\n");
					sleep(7);
					break;
					case 11:
					printf("\n\nUmozliwia utworzenie/usuniecie/przeczytanie wlasnej notatki.\n\n");
					sleep(4);
					break;
					case 12:
					printf("\n\nUmozliwia ustawienie odpowiedniego powitania, ktore jest widoczne podczas uruchamiania aplikacji.\n\n");
					sleep(4);
					break;
					case 13:
					printf("\n\nUmozliwia ustawienie odpowiednich ustawien tyczacych bezpieczenstwa dostepu do aplikacji.\n\n");
					sleep(4);
					break;
					case 14:
					printf("\n\nUmozliwia ustawienie \"wibracji\", ktore uruchamiaja sie podczas uruchamiania innych opcji.\n\n");
					sleep(4);	
					break;
					case 15:
					printf("\n\nUmozliwia ustawienie widoku daty/godziny w menu glownym.\n\n");
					sleep(4);
					break;
					case 16:
					printf("\n\nWlacza/wylacza dodatkowe opcje w kalkulatorze.\n\n");
					sleep(4);
					break;
					case 17:
					printf("\n\nWlacza/wylacza dodatkowe gry (labolatorium 15).\n\n");
					sleep(4);
					break;
					case 18:
					printf("\n\nWlacza/wylacza opcje obrazki.\n\n");
					sleep(4);
					break;
					case 19:
					printf("\n\nPrzywraca poczatkowe ustawienia.\n\n");
					sleep(4);
					break;
					case 20:
					printf("\n\nUmozliwia utworzenie wlasnej notatki.\n\n");
					sleep(4);
					break;
					case 21:
					printf("\n\nUmozliwia przeczytanie utworzenej wczesniej notatki.\n\n");
					sleep(4);
					break;
					case 22:
					printf("\n\nUmozliwia usuniecie utworzenej wczesniej notatki.\n\n");
					sleep(4);
					break;
					case 23:
					printf("\n\nUmozliwia zapisanie nowego kontaktu.\n\n");
					sleep(4);
					break;
					case 24:
					printf("\n\nUmozliwia sprawdzenie zapisanych wczesniej kontaktow.\n\n");
					sleep(4);
					break;
					case 25:
					printf("\n\nUmozliwia usuniecie zapisanego wczesniej kontaktu.\n\n");
					sleep(4);
					break;
					case 26:
					printf("\n\nWidoczna bedzie jedynie aktualna data (dd mmm rrrr) oraz dzien tygodnia.\n\n");
					sleep(5);
					break;
					case 27:
					printf("\n\nWidoczna bedzie jedynie godzina (gg:mm:ss) w ktorej zostalo uruchomione menu glowne.\n\n");
					sleep(5);
					break;
					case 28:
					printf("\n\nWidoczna bedzie jedynie aktualna data (dd mmm rrrr), dzien tygodnia oraz godzina (gg:mm:ss) w ktorej zostalo uruchomione menu glowne.\n\n");
					sleep(6);
					break;
					case 29:
					printf("\n\nWylacza widok daty i godziny.\n\n");
					sleep(4);
					break;
					case 30:
					printf("\n\nUmozliwia ustawienie wlasnej notatki (przypomnienie), ktora bedzie widoczna podczas uruchamiania aplikacji (dziala na rok 1980 - 2100).\n\n");
					sleep(6);
					break;
					case 31:
					printf("\n\nUmozliwie przeczytanie/usuniecie wczesniej utworzonego przypomnienia.\n\n");
					sleep(6);
					break;
				}
}