#include <stdio.h>
#include <math.h>

int pai (int i) {
   return (i - 1)/2; 
}

int esquerda(int i){
	return (i*2)+1;
}

int direita(int i){
	return (i*2)+2;
}

void trocar (int V[], int a, int b) {
   int aux = V[a];
   V[a] = V[b];
   V[b] = aux;
}

void imprimir (int V[], int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", V[i]);
   }
   printf("\n");
}

void max_heapify (int V[], int size, int i) {
   /*TERMINAR*/
	int e = esquerda(i);
	int d = direita(i);
	int maior = -1;
	if (e<size && v[e]>v[i])
		maior = e;
	else
		maior = i;
	if(e<size && v[d]>v[i])
		maior = d;
	else
		maior = i; //ver necessidade
	if(i!=maior){
		v[i]=v[maior];
		v[maior] = v[i];
		max_heapify(v,size,maior);
	}	
}

void build_max_heap (int V[], int size) {
   /*TERMINAR*/
	for (int i = floor(size/2)-1; i<= 0;i++)//procurar equacao para chao
	{
		max_heapify(x,size,i);
	}

}

void heap_sort (int V[], int size) {
   /*TERMINAR*/
	build_max_heap(v,size);
	for(int i = size-1;i<=0;i++)
	{
		v[0]=v[i];
		v[i]=v[0];
		size = i;
		max_heapify(v,size,0);

	}
}

int main () {

   int i;

   int size = 10;

   int V[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  
   printf("Vetor inicial : ");
   imprimir (V, size);

   heap_sort (V, size);

   printf("Vetor ordenado: ");
   imprimir (V, size);
  
   return 0;
}
