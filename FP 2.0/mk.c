#include<stdio.h>
#include<stdlib.h>
#include "structdanfx.h"

void mk()
{
	FILE *fp = fopen("isi_mk.dat", "r");
	
	if(fp == NULL)
	{
		printf("File list Mata Kuliah tidak bisa dibuka!?!?!?");
		
		return;
	}
	
	struct isi_mk isimk = {0, 0, "", ""};
	
	printf("//ID Mata Kuliah\t\tNama Mata Kuliah\t\tJumlah Mahasiswa\t\tDosen Pengajar\\\n");
	printf("||==============\t\t================\t\t================\t\t==============||\n");
	
	while(fread(&isimk, sizeof(isimk), 1, fp) == 1)
	{
		printf("||%d\t\t%s\t\t%d\t\t%s||\n\n", isimk.id, isimk.mk, isimk.jml_mhssw, isimk.dosen);
	}
	
	if(ferror(fp))
	{
		printf("File list Mata Kuliah tidak bisa dibuka!?!?!?");
	}
	
	fclose(fp);
}
