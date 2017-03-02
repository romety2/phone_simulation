#include<stdio.h>

#include "mini_tel.h"

int main () 
		{
		system("clear");
		if(plik()==0)
			printf("BLAD\n");
		else if(haslo()==1)
			printf("PODALES NIEPRAWIDLOWE HASLO ZBYT WIELE RAZY !!!\n\n");
		else
			{
			spr_us();
			wyp_pow();
			sleep(2);
			wybierz();
			}
		return 0; 
		}