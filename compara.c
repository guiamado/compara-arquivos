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
	char word;
	struct Palavras *prox;
}Palavras;
// typedef struct
// {
// 	char* word;
// 	int frenquencia;
// }Word;
/*Fim das Structs*/

/*Inicio dos cabecalhos de funcoes*/
void	abreArquivos ();
int 	iniciaListaVazia(Palavras* listaPalavras);
Palavras*	inserePalavraLista ( Palavras* listaPalavras, char i);
void	imprimePalavraLista ( Palavras* listaPalavras);
Palavras* buscaPalavraLista ( Palavras* listaPalavras, char v );
void liberaPalavraLista (Palavras* listaPalavras);
int comparaPalavraLista (Palavras* listaPalavras1, Palavras* listaPalavras2);
/*Fim dos cabecalhos de funcoes*/

/*Inicio da Funcao Main*/
int main() {
	
	// Palavras *listaPalavras = (Palavras *) malloc(sizeof(Palavras));

	// if (!listaPalavras)
	// {
	// 	printf("Sem memoria disponivel\n");
	// 	exit(1);
	// }
	abreArquivos();
  
  return 0;
}/*Termino da Funcao Main*/

/*Inicio da funcao que abre arquivos*/
void abreArquivos(){
  int ch, contaPalavra, k,i;
  contaPalavra = 0;

  Arquivo* teste = (Arquivo *) malloc(arquivos*sizeof(Arquivo));
  for (i=0 ; i<arquivos ; i++)
    {   
		teste[i].nome = (char *) malloc((tamanho)*sizeof(char));
		teste[i].file = (FILE *) malloc(sizeof(FILE));
	}

  for (k = 0; k < arquivos; k++) 
  {
    	char filename[100], treta[50];

      // FILE *file;
      // sprintf(filename, "texto%d.txt", (k+1)); /* texto1.txt ; texto2.txt  ; ... ; textoN.txt */
    	sprintf(teste[k].nome, "texto%d.txt", (k+1)); /* texto1.txt ; texto2.txt  ; ... ; textoN.txt */

      // file = fopen(filename, "r");
    	teste[k].file = fopen(teste[k].nome, "r");
      
     	fscanf(teste[k].file, "%s", treta[k]);
		while (((fscanf(teste[k].file, "%s", treta[k])) != EOF))
		{
			contaPalavra++;
		}
      //tentar usar a funcao fscanf
      // while (((ch = fgetc(teste[k].file)) != EOF))
      // {
      //   	if(isalpha(ch))
      //   		contaPalavra++;
      // }

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
        free(teste[i].file);
    }
    if (k == arquivos)
		free(teste);
  printf("%d\n", contaPalavra);
}/*fim da funcao que abre arquivos*/

/*Inicio da funcao para iniciar lista*/
int 	iniciaListaVazia ( Palavras* listaPalavras )
{
	return (listaPalavras == NULL);
}/*fim da funcao que inicia lista vazia*/

/*Inicio da funcao para inserir lista vazia*/
Palavras*	inserePalavraLista ( Palavras* listaPalavras, char i )
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