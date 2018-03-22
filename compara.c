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

typedef struct
{

 	char* nome;
 	FILE *file;

} Arquivo;

typedef struct 
{
	int word;
	struct Palavras *prox;
}Palavras;

/*Fim das Structs*/

/*Inicio dos cabecalhos de funcoes*/
void	abreArquivos ();
void	iniciaLista (Palavras *listaPalavras);
int		listaVazia ( Palavras *listaPalavras );
/*Fim dos cabecalhos de funcoes*/

/*Inicio da Funcao Main*/
int main() {
	
	Palavras *listaPalavras = (Palavras *) malloc(sizeof(Palavras));

	iniciaLista(listaPalavras);
	
	if (!listaPalavras)
	{
		printf("Sem memoria disponivel\n");
		exit(1);
	}
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
		teste[i].file = (FILE *) malloc((tamanho)*sizeof(FILE));
	}

  for (k = 0; k < arquivos; k++) 
  {
      char filename[100];

      //FILE *file;
      // sprintf(filename, "texto%d.txt", (k+1)); /* texto1.txt ; texto2.txt  ; ... ; textoN.txt */
      sprintf(teste[k].nome, "texto%d.txt", (k+1)); /* texto1.txt ; texto2.txt  ; ... ; textoN.txt */

      // file = fopen(filename, "r");
      teste[k].file = fopen(teste[k].nome, "r");
      
      while (((ch = fgetc(teste[k].file)) != EOF))
      {
          if(isalpha(ch))
            contaPalavra++;
      }

      if (teste[k].file != NULL) 
      {
          fclose(teste[k].file);
      } else 
      {
          perror(filename);
          exit(1);
      }
  		printf("%s\n",teste[k].nome );

  }
  for (i=0 ; i<arquivos ; i++)
    {
        free(teste[i].nome);
    }
	free(teste);
  printf("%d\n", contaPalavra);
}/*fim da funcao que abre arquivos*/

/*Inicio da funcao para iniciar lista*/
void	iniciaLista (Palavras *listaPalavras)
{
	listaPalavras->prox = NULL;
}
/*Inicio da funcao para lista vazia*/
int		listaVazia( Palavras *listaPalavras )
{
	if (listaPalavras->prox == NULL)
		return 1;
	else
		return 0;
}