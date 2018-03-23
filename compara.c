/*
  TRABALHO 1 ED 1/2018 TURMA D
  Aluno: Guilherme Amado da Silva
  Matricula: 17/0011585     
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define arquivos 2
#define tamanho 100

/* Definindo Structs a serem usadas*/

typedef struct Arquivo
{
 	char* nome;
 	FILE *file;

}Arquivo;

typedef struct Palavras
{
	char* word;
	struct Palavras *prox;
}Palavras;
/*Fim das Structs*/
typedef struct Lista
{
	Palavras* palavras;
}Lista;
/*Inicio dos cabecalhos de funcoes*/
void	abreArquivos ();
Palavras* criaListaPalavra();
int 	iniciaListaVazia(Palavras* listaPalavras);
Palavras*	inserePalavraLista ( Palavras* listaPalavras, char* i);
void	imprimePalavraLista ( Palavras* listaPalavras);
Palavras* buscaPalavraLista ( Palavras* listaPalavras, char v );
void liberaPalavraLista (Palavras* listaPalavras);
int comparaPalavraLista (Palavras* listaPalavras1, Palavras* listaPalavras2);
void pegaPalavra(Palavras* listaPalavras, Arquivo* teste);
/*Fim dos cabecalhos de funcoes*/

/*Inicio da Funcao Main*/
int main() {
	Lista* listinha = (Lista *) malloc(5*sizeof(Lista)); 	
	abreArquivos(listinha);
  
 	return 0;
}/*Termino da Funcao Main*/

/*Inicio da funcao que abre arquivos*/
void abreArquivos(Lista* arrayDePalavras){
  	int ch, contaPalavra, k,i;
  	contaPalavra = 0;
  	char naPalavra = 'F', vh;

  	Arquivo* teste = (Arquivo *) malloc(arquivos*sizeof(Arquivo));
  	for (i=0 ; i<arquivos ; i++)
    	{   
			teste[i].nome = (char *) malloc((tamanho)*sizeof(char));
			teste[i].file = (FILE *) malloc(sizeof(FILE));
		}

  	for (k = 0; k < arquivos; k++) 
	{
		
		Palavras* listaPalavras;
		listaPalavras = criaListaPalavra();

		sprintf(teste[k].nome, "texto%d.txt", (k+1)); /* texto1.txt ; texto2.txt  ; ... ; textoN.txt */

		teste[k].file = fopen(teste[k].nome, "r");

		pegaPalavra(listaPalavras, &teste[k]);
		arrayDePalavras->palavras = listaPalavras;

		if (teste[k].file != NULL) 
		{
			fclose(teste[k].file);
		} else 
		{
			perror(teste[k].nome);
			exit(1);
		}
		printf("%s\n",teste[k].nome );

	}
	for (i=0 ; i<arquivos ; i++)
	{
		free(teste[i].nome);
	}
	if (k == arquivos)
		free(teste);
	printf("%d\n", contaPalavra);
}/*fim da funcao que abre arquivos*/

/*Inicio da funcao de criacao da lista*/
Palavras* criaListaPalavra()
{
	return NULL;
}/*Fim da funcao de criacao de lista*/

/*Inicio da funcao para iniciar lista*/
int 	iniciaListaVazia ( Palavras* listaPalavras )
{
	return (listaPalavras == NULL);
}/*fim da funcao que inicia lista vazia*/

/*Inicio da funcao para inserir lista vazia*/
Palavras*	inserePalavraLista ( Palavras* listaPalavras, char* i )
{
	Palavras* novaPalavra = (Palavras*) malloc(sizeof(Palavras));
	novaPalavra->word = i;
	novaPalavra->prox = listaPalavras;

	return novaPalavra;
}/*fim da funcao que insere palavras*/

/*Inicio da funcao que imprime lista*/
void	imprimePalavraLista ( Palavras* listaPalavras )
{
	Palavras* aux;

	for ( aux = listaPalavras; aux != NULL; aux = aux->prox ) 
	{
		printf("info = %s \n", aux->word);
	}
}/*fim da funcao que imprime lista*/

/*Inicio da funcao que busca pela lista*/
Palavras* buscaPalavraLista ( Palavras* listaPalavras, char v )
{
	Palavras *p;

	for ( p = listaPalavras; p != NULL; p = p->prox )
	{
		if (p->word == v)
			return p;
	}
	return NULL;
} /*fim da funcao que busca pela lista*/

/*Inicio da funcao que libera as palavras da lista*/ 
void liberaPalavraLista (Palavras* listaPalavras)
{
	Palavras* p = listaPalavras;

	while (p != NULL)
	{
		Palavras* t = p->prox;
		free(p);
		p = t;
	}
}/*fim da funcao que libera a lista*/

/*Inicio da funcao que que compara lista*/
int comparaPalavraLista (Palavras* listaPalavras1, Palavras* listaPalavras2)
{
	Palavras* p1;
	Palavras* p2;

	for (p1 = listaPalavras1, p2 = listaPalavras2; 
		 p1 != NULL && p2 != NULL; 
		 p1 = p1->prox, p2 = p2->prox)
	{
		if (p1->word != p2->word)
			return 0;
	}
	return (p1 == p2);
}/*fim da funcao que compara a lista*/

void pegaPalavra(Palavras* listaPalavras, Arquivo* teste)
{
	char treta[100];
	while (treta != EOF)
	{
		fscanf(teste->file, "%s", treta);
		printf("%s", treta);
		inserePalavraLista(listaPalavras, treta);
	}
}
