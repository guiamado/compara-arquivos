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

typedef struct{

 	char* nome;
 	FILE *file;

} Arquivo;

void  abreArquivos();

int main() {
  
  abreArquivos();
  
  return 0;
}

void abreArquivos(){
  int ch, contaPalavra, k,i;
  contaPalavra = 0;

  Arquivo* teste = (Arquivo *) malloc(arquivos*sizeof(Arquivo));
  for (i=0 ; i<arquivos ; i++)
    {   
		teste[i].nome = (char *) malloc((tamanho)*sizeof(char));
		teste[i].nome = (FILE *) malloc((tamanho)*sizeof(FILE));
	}

  for (k = 0; k < arquivos; k++) 
  {
      char filename[100];

      FILE *file;
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
  		printf("%s\n",teste[0].nome );

  }
  for (i=0 ; i<arquivos ; i++)
    {
        free(teste[i].nome);
    }
	free(teste);
  printf("%d\n", contaPalavra);
}
