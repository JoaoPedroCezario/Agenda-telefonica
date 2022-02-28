#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

FILE *arquivo;
int deseja, busca, decorar, aux1, aux2;

struct ag
{
	char cod[3], nome[20], telefone[15];
};

struct ag sistema;

void listar(void);

int main()
{
	
	arquivo = fopen ("agenda.dat","a");
	fclose (arquivo);
	
	do{
	
	system ("color e1");
	system ("cls");;
	
	for (decorar=0; decorar <80; decorar++)
	{
		printf ("%c", 178);
	}
	
	printf ("\nAgenda - V: 1.0.0 - 2017\n\n");
	printf ("[1] - Inserir Dados\n[2] - Alterar Dados\n[3] - Listar Todos\n\n");
	cin>>deseja;
	system ("cls");
	
	if (deseja == 1)
	{
		printf ("\nINSERIR DADOS\n\n");
		arquivo = fopen ("agenda.dat","a");
		
		printf ("Digite o No De Registro: ");
		cin>>sistema.cod;
		printf ("\nDigite o Nome: ");
		cin>>sistema.nome;
		printf ("\nDigite o Telefone: ");
		cin>>sistema.telefone;
		
		fwrite(&sistema, sizeof(struct ag), 1, arquivo);
		printf ("\n\nGravado!!!\n\n");
		system ("pause");
		fclose (arquivo);
	}
	
	if (deseja == 2)
	{
		printf ("\nALTERAR REGISTRO\n\n");
		arquivo = fopen ("agenda.dat","r+");
		
		printf ("Digite o No De Registro: ");
		cin>>busca;
		busca = busca - 1;
		
		fseek(arquivo,busca*sizeof(struct ag),SEEK_SET);
		fread(&sistema, sizeof(struct ag), 1, arquivo);
		
		cout<<"\n\nCod:......."<<sistema.cod;
		cout<<"\nNome:......."<<sistema.nome;
		cout<<"\nTelefone:..."<<sistema.telefone;
		
		printf ("\n\nDigite o No De Registro: ");
		cin>>sistema.cod;
		printf ("\nDigite o Nome: ");
		cin>>sistema.nome;
		printf ("\nDigite o Telefone: ");
		cin>>sistema.telefone;
		printf ("\nDigite o Endereco (max 18): ");
		
		fseek(arquivo,busca*sizeof(struct ag),SEEK_SET);
		fwrite(&sistema, sizeof(struct ag), 1, arquivo);
		printf ("\n\nGravado!!!\n\n");
		system ("pause");
		fclose (arquivo);
	}
	
	if (deseja == 3)
	{
		printf ("\nLISTAR TODOS OS REGISTROS\n");
		listar();
	}
	
	}while (1 == 1);
}

void listar(void)
{
	arquivo = fopen("agenda.dat","r+");
	fseek(arquivo,0,SEEK_SET);
	busca = 0;
	
	do{
		
		fread(&sistema, sizeof(struct ag), 1, arquivo);
		
		cout<<"\n\nCod:......."<<sistema.cod;
		cout<<"\nNome:......."<<sistema.nome;
		cout<<"\nTelefone:..."<<sistema.telefone;
		
		if (feof(arquivo))
		{
			fclose(arquivo);
			printf ("\n\n");
			system ("pause");
			return;
		}
		
	}while (1==1);
	fclose(arquivo);
	
	return;
}
