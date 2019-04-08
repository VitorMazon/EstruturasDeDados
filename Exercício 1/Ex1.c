/*Escreva um programa que leia o tamanho de vetro de inteiros.
 * Aplique dinamicamente o vetor. Leia o vetor e preencha o vetor. 
 * Imprima o vetro e em seguida ordene o vetor mostrando o mesmo abaixo.
 * 
 * 1-Bubblesort
 * 2-Seleção
 * 3-Inserção
 * 
 * Mostre que o vetor ordenado logo após leia um valor qualquer e 
 * faça a busca através do menu.
 * 
 * 1-Busca Sequencial
 * 2-Busca Binária
 * 3-Sair
 * 
 * na busca, mostre uma mensagem se achou ou não achou utilizando o retorno da função.
*/
#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int*b)
{
 int aux;
 aux= *a;
 *a=*b;
 *b=aux;
}

void bubblesort(int v[],int max)
{
 //max vale N-1
 
 int i, trocou=1;
 
 while(trocou)
 {
  trocou=0;
  for(i=0;i<max;i++)
  {
   if(v[i]>v[i+1])
   {
    troca(&v[i],&v[i+1]);
    trocou=1;
   }
  }
  max--;
 }
}

void selection(int v[], int N)
{
 int i, j, menor;
 for(j=0;j<N-1;j++)
 {
  menor = j;
  for(i=j+1;i<N;i++)
  {
   if(v[i]<v[menor])
    menor=i;
  }
  troca(&v[j],&v[menor]);
 }
}

void inscricao(int v[], int N)
{
 int i, j;
 for(j=1;j<N;j++)
 {
  for(i=j;i>0 && v[i-1]>v[i];i--)
   troca(&v[i-1],&v[i]);
 }
}

int buscaSeqOrd(int v[], int chave, int *pos, int N)
{
	 int i;
	 for(i==0;i<N && chave > v[i];i++);
	 pos=&i;
	 if((i==N)||(chave!=v[i]))
		return 0;
	 return 1;
}

int buscaBinaria (int v[], int chave, int N)
{
	 int ini, fim, meio;
	 ini=0;
	 fim=N-1;
	 
	 while(ini<=fim)
	 {
		  meio=(ini+fim)/2;
		  
		  if(chave==v[meio])
		   	return (meio);
		  
		  if (chave<v[meio])
		   	fim=meio-1;
		  
		  else
		  	ini=meio+1;
	 }
	 return -1;
}

int tamanho(int k[]){
	
	int i=0;
	
	while(k[i] != NULL){
		i++;
	}
	
	return i+1;
}

void main() {
	int *v, tam, o=1, i, n, s, escolha=0, ord;
	
//--------------------------------------------------------
//-----------Define vetor e seu tamanho-------------------
//--------------------------------------------------------

	puts("Digite o tamanho do vetor");
	scanf("%d", &n);
	printf("\nConteúdo dos %d elementos:\n", n);
	
	v=(int *)malloc(n*sizeof(int *));
	
	for(i=0; i<n; i++)
		scanf("%d", &v[i]);
		
	puts("\nVetor:");
	for(i=0; i<n; i++)
		printf("\tv[%d]=%d\n", i, v[i]);

//-------------------------------------------------------------
//------------Bloco de escolha de ordenação--------------------
//-------------------------------------------------------------

	printf("\nEscolha o método para ordenar o vetor:\n");
	printf("\n1-Bubblesort");
	printf("\n2-Seleção");
	printf("\n3-Inscrição\n");
	
	while(escolha == 0) {
		scanf("%d", &ord);
		
		if(ord==1){
			bubblesort(v, n-1);
			escolha = 1;
		}
		
		if(ord==2){
			selection(v, n);
			escolha = 1;
		}
		
		if(ord==3){
			inscricao(v, n);
			escolha = 1;
		}
		
		else{
			puts("Escolha uma das opções acima.");
		}
	}
	
	puts("\n----------------------------");
	
	puts("Vetor ordenado:");
	for(i=0; i<n; i++)
		printf("\tv[%d]=%d\n", i, v[i]);

//--------------------------------------------------------
//----------------Bloco de busca--------------------------
//--------------------------------------------------------

	do{
		printf("\n--------Menu---------");
		printf("\n1-Busca Sequencial");
		printf("\n2-Busca Binária");
		printf("\n3-Sair\n");
		
		scanf("%d", &s);
		switch(s){
			case 1:	
					break;
			case 2: 
					break;
			case 3: o=0;
					break;
			default:
					printf("Comando inválido :))))\n");
			break;
		}
	}while(o!=0);
	
	free(v);
}
