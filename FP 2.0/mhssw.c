#include<stdio.h>
#include<stdlib.h>
#include "structdanfx.h"

void mhssw()
{
	FILE *fp = fopen("isi_mhssw.dat", "r");
	
	if(fp == NULL)
	{
		printf("File list Mahasiswa tidak bisa dibuka!?!?!?");
		
		return;
	}
	
		struct isi_mhssw isimhssw = {0, 0, "", "", ""};
	
	printf("//Nama\t\tNIM\t\tEmail\t\tDepartemen\t\t\tIPS\\\n");
	printf("||====\t\t===\t\t=====\t\t==========\t\t\t===||\n");
	
	while(fread(&isimhssw, sizeof(isimhssw), 1, fp) == 1)
	{
		printf("||%-20s\t\t%-20d\t\t%s\t\t%s\t\t%.2f||\n\n", isimhssw.nama, isimhssw.nim, isimhssw.email, isimhssw.departemen, isimhssw.ips);
	}
	
	if(ferror(fp))
	{
		printf("File list Mahasiswa tidak bisa dibuka!?!?!?");
	}
	
	fclose(fp);
}
