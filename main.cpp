 /************************************************************************************************************************************
 * Programa: Rede Ótica	
 * 
 * Descriçao:  Programa implementado em C para resolver o "Problema da árvore geradora de mínimo" sob o contexto
 * de uma ligação de fibra ótica entre duas tabas de um ramo de rede. 
 *
 * Autores:  Bruno Sastre     Felipe Aversoni
 * TIA:      41316861         41313038 
 ************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM_MAXIMO 128
#define A_MAX 100


typedef struct { //Definição do novo tipo Aresta
  int custo; //sera armazenado o valor do custo minimo
  int v1, v2; //declaracao dos vertices
} Aresta; 

typedef struct Componente { //Definicao do tipo Componente
  struct Componente *next;
} Componente;

void imprimir_logo(FILE *impArq);
void compInit(); //Inicializa os componentes para a struct
void compUni(int, int); //Uniao dos componentes
int sameComp(int, int );
int compare(const void *, const void *); //Compara arestas

int n, m;

Aresta aresta[A_MAX * (A_MAX-1) /2];

Componente *componente[A_MAX]; 

int treeSize;

int main()
{
 
   int register i;
   int t=1, a, b;
	
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
   
   printf("Digite a entrada\n\n");
   scanf("%d %d\n", &n, &m);
  
  while(n!=0){
              
    treeSize=0;//tamanho da arvore
    compInit();
    
    for(i=0; i<m; i++)
    {
      scanf("%d %d %d\n", &a, &b, &aresta[i].custo);
       
      if(a < b)
      {
        aresta[i].v1 = a-1; aresta[i].v2 = b-1;
      }
      else
      {
        aresta[i].v1 = b-1; aresta[i].v2 = a-1;
      }
    }
    
    qsort(aresta, m, sizeof(Aresta), compare);

    printf("\n\tConjunto de teste %d\n", t);
    for(i=0; treeSize<n-1; i++)
      if(!sameComp(aresta[i].v1, aresta[i].v2))
      {
	printf("%d %d\n", aresta[i].v1+1, aresta[i].v2+1);
	compUni(aresta[i].v1, aresta[i].v2); 
	treeSize++;
      }

    printf("\n");
    printf("Digite novos dados para a entrada\n\n");
    scanf("%d %d\n", &n, &m);
    t++;
  }


  system("pause");
}

   //impressao do logo
    void imprimir_logo(FILE *impArq){
    
    char read_string[TAM_MAXIMO];
    
    
    while(fgets(read_string,sizeof(read_string),impArq) != NULL)
        printf("%s",read_string);
    }
	
	//Compara arestas
	int compare(const void *a, const void *b){
		  Aresta *A=(Aresta*)a, *B=(Aresta*)b;

		  if( A->custo > B->custo ) return +1;
		  else if ( A->custo < B-> custo ) return -1;
		  else return 0;
	}
	//Inicializa os componentes para a struct
	void compInit(){
	  int i;
	  for(i=0; i<n; i++){
		componente[i]=(Componente *)malloc(sizeof(Componente));
		componente[i]->next=NULL;
	  }
	}
	//Uniao dos componentes
	void compUni(int v1, int v2){
	  
	  Componente *Comp;
	  Comp=(Componente *)malloc(sizeof(Componente));//alocacao de memoria para Componente
	  
	  Comp->next=NULL;
	  
	  componente[v1]->next=Comp;
	  componente[v2]->next=Comp;
	}

	int sameComp(int v1, int v2){
        
	  Componente *Cv1, *Cv2; //recebimento dos componentes

	  for(Cv1=componente[v1]; Cv1->next!=NULL; Cv1=Cv1->next);
	  
	  for(Cv2=componente[v2]; Cv2->next!=NULL; Cv2=Cv2->next);
	  
      //Arvore sendo compactada
	  componente[v1]=Cv1; 
	  componente[v2]=Cv2;
	 
	  return (Cv1==Cv2 && Cv1!=NULL); 
	}
