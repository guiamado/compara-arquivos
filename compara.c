/*
  TRABALHO 1 ED 1/2018 TURMA D
  Aluno: Guilherme Amado da Silva
  Matricula: 17/0011585     
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void  abreArquivos();

int main() {
  
  abreArquivos();
  
  return 0;
}

void abreArquivos(){
  int ch, contaPalavra, k;
  contaPalavra = 0;
  for (k = 0; k < 2; k++) 
  {
      char filename[3];
      FILE *file;
      sprintf(filename, "texto%d.txt", (k+1)); /* texto1.txt ; texto2.txt  ; ... ; texton.txt */
      file = fopen(filename, "r");
      while (((ch = fgetc(file)) != EOF))
      {
          if(isalpha(ch))
            contaPalavra++;
      }

      if (file != NULL) 
      {
          fclose(file);
      } else 
      {
          perror(filename);
          return 0;
      }
  }
  printf("%d\n", contaPalavra);
}