 /************************************************************************************************************************************
 * Programa: Indio	
 * 
 * Descriçao:  Programa que implementa o algoritmo de Kruskall para resolver o "Problema da árvore geradora de mínimo" sob o contexto
 * de uma ligação de fibra ótica entre duas tabas de um ramo de rede. 
 *
 * Autores:  Bruno Sastre     Felipe Aversoni
 * TIA:      41316861         41313038 
 ************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM_MAXIMO 128

void imprimir_logo(FILE *impArq);

int main()
{
    
    //Impressao logo  
    char *nome_arquivo = "imagem.txt"; //variavel que possui o nome do arquivo que carega o arquivo com o logo, autores etc
    FILE *impArq = NULL;
 
    //tratativa de quando o arquivo não for encontrado ou ser nulo
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
