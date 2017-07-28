#include <stdio.h>
#include <math.h>
#include <ctype.h>

double digit,nilai_f,angka,batas_angka,batas,pangkat,k,hasil[100];
int nilai,banyak,i_i;
char masukan,spasi;


int main()
{
	FILE *in;
	FILE *mas;
	FILE *spas;

	in = fopen( "input.txt", "r" );
	mas = fopen( "input.txt", "r" );
	spas = fopen( "input.txt", "r" );
	fscanf(in,"%lf",&digit);
	fscanf(mas,"%c",&masukan);
	fscanf(spas,"%c",&spasi);
	
	batas=pow(10,digit);
	pangkat=digit/2;
	batas_angka=pow(10,pangkat);    
	
	for(float i=0;i<batas_angka;i++)
	{
		i_i=(int)i;
		printf("%d loading...\n",i_i);
		for(float j=0;j<batas_angka;j++)
		{
			k=i+j;
			nilai_f=pow(k,2);
			angka=i*batas_angka;
			angka=angka+j;
			if(nilai_f==angka)
			{
				banyak=banyak+1;
				hasil[banyak]=nilai_f;
			}
		}		
	}
	FILE *out;
	out = fopen( "output.txt", "w" );
	fprintf(out,"\n/****************************** Start ******************************/\n");
	if(isdigit(masukan)&&!isspace(spasi))
	{
		if(banyak<=1)fprintf(out,"%d",hasil[banyak]);
		else
		{
			if(out!=NULL )
			{
				for(int a=1;a<banyak;a++)fprintf(out,"%010.0lf, ",hasil[a]);	
				fprintf(out,"dan %010.0lf",hasil[banyak]);
			}
		}
	}
	else fprintf(out,"ERROR");
	fprintf(out,"\n/******************************* End *******************************/\n");
}