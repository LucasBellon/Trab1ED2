#include <stdio.h>

int fatorial(int n)
{
	int fat;
	for(fat = 1; n > 1; n--)
		fat = fat * n;
	return fat;
}

void inicializa (char* vetor , int ncidades)
{
	int i;

	for (i=0; i < ncidades; i++)
		vetor[i] = i+48;
	vetor[ncidades] = '\0';
}

int verificaRepetida (char* vetor, int max)
{
	int i,j;
	for(i=0; i < max; i++)
		for (j=i+1; j < max; j++)
			if ( vetor[i] == vetor[j] )
				return 0;
	return 1;
}

void somador (int i, char *vetor, int max)
{
	vetor[i]++;
	if ( vetor[i] >= max )
	{
		vetor[i] = 48;
		if (i < max-49)
			somador (i+1, vetor, max);
	}
}

int main (int argc, char** argv)
{
	
	char vetor [25];
	int i = 0;
	int j, ncidades,k,l;

	int matriz[25][25];
	char aux[100];

	ncidades = atoi(argv[1]);
//	printf("%i numero de cidades \n",ncidades);
	j = fatorial( ncidades );
//	printf("%i fatorial\n\n",j);
	inicializa ( vetor , ncidades );
//	printf("%s \n\n\n",vetor);

	for(k=0; k < ncidades; k++)
		for (l=0; l < ncidades; l++)
			{
				scanf("%s", aux );
				matriz[k][l] = atoi(aux);
			}

	for(k=0; k < ncidades; k++){
		for (l=0; l < ncidades; l++)
			{
				printf("%i ",matriz[k][l]);
			}
		printf("\n");
		}

	while(j>0)
	{
		if ( verificaRepetida(vetor, ncidades) )
		{
//			printf("%s\n",vetor);
			
			j--;
		}
		somador (i, vetor, ncidades+48);
	}
}
