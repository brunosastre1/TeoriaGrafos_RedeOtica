 /************************************************************************************************************************************
 * Programa: Rede �tica	
 * 
 * Descri�ao:  Programa implementado em C para resolver o "Problema da �rvore geradora de m�nimo" sob o contexto
 * de uma liga��o de fibra �tica entre duas tabas de um ramo de rede. 
 *
 * Autores:  Bruno Sastre     Felipe Aversoni
 * TIA:      41316861         41313038 
 ************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM_MAXIMO 128
#define MAX_N 100


typedef struct {
  int custo;
  int v1, v2;
} Aresta;

void imprimir_logo(FILE *impArq);
void compInit(); //Inicializa os componentes para a struct
void compUni(int, int); //Uniao dos componentes
int sameComp(int, int );

int main()
{
    
    //Impressao logo  
    char *nome_arquivo = "imagem.txt"; //variavel que possui o nome do arquivo que carega o arquivo com o logo, autores etc
    FILE *impArq = NULL;
 
    //tratativa de quando o arquivo n�o for encontrado ou ser nulo
    if((impArq = fopen(nome_arquivo,"r")) == NULL)
    {
        fprintf(stderr,"erro ao abrir %s\n",nome_arquivo);
        return 1;
    }
    
    imprimir_logo(impArq);
    printf("\n");
    fclose(impArq);
    printf("\n");
   

  system("pause");
}

   //impressao do logo
    void imprimir_logo(FILE *impArq){
    
    char read_string[TAM_MAXIMO];
    
    
    while(fgets(read_string,sizeof(read_string),impArq) != NULL)
        printf("%s",read_string);
    }
	


