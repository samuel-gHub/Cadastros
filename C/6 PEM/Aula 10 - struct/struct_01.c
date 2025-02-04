//Estrutura3.c: mostro como o uso de estrutura facilita o trabalho numa ordena��o

//Estruturas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct amigo {
	char nome[30];
	long int telefone;
	char email[40];
};

//typedef d� um apelido para a estrutura
typedef struct amigo AMIGO;

void ordenacao(AMIGO vet[], int N)
{	int i, j;
	for(i=1; i<= N; i++)
		for(j=0; j<N-i; j++)
        	if(strcmp(vet[j].nome,vet[j+1].nome) > 0)
        	{	AMIGO aux;
        		aux = vet[j];
        		vet[j] = vet[j+1];
        		vet[j+1] = aux;
        	}
}
int main(){	
	AMIGO lista[100];
	int i;
	for(i=0; i<5; i++){	
		printf("FICHA %d\n", i+1);
		printf("Entre com o nome: ");
		fgets(lista[i].nome, 30, stdin);
		lista[i].nome[strlen(lista[i].nome)-1] = '\0';
		printf("Entre com o telefone: ");
		char aux[15];
		fgets(aux, 15, stdin);
		lista[i].telefone = atoi(aux);
		printf("Entre com o e-mail: ");
		fgets(lista[i].email, 40, stdin);
		lista[i].email[strlen(lista[i].email)-1] = '\0';
	}
	ordenacao(lista, 5);
	for(i=0; i<5; i++)
	{	printf("FICHA %d\n", i+1);
		printf("Nome: %s\n", lista[i].nome);
		printf("Telefone: %ld\n", lista[i].telefone);
		printf("E-mail: %s\n", lista[i].email);
	}
	return 0;
}

