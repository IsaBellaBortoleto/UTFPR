#include "abbLista.h"
#include <time.h>

Arvore *cria_arvore_vazia(void) { return NULL; }

void arvore_libera(Arvore *a)
{
	if (a != NULL)
	{
		arvore_libera(a->esq);
		arvore_libera(a->dir);
		free(a);
	}
}

//========= Q1 - inserir
Arvore *inserir(Arvore *a, int v)
{
	/* Completar */
	if (a == NULL)
	{
		a = (Arvore *)malloc(sizeof(Arvore));
		a->info = v;
		a->esq = NULL;
		a->dir = NULL;
		return a; //lembrar desse return
	}
	else if (v < a->info)
		a->esq = inserir(a->esq, v);
	else
		a->dir = inserir(a->dir, v);

	return a;
}

//========= Q1 - remover
Arvore *remover(Arvore *a, int v)
{
	/* Completar */
	if (a == NULL)
		return NULL;
	else
	{
		if (v < a->info)
			a->esq = remover(a->esq, v);
		else if (v > a->info)
			a->dir = remover(a->dir, v);
		else
		{
			if ((a->esq == NULL) && (a->dir == NULL))
			{
				free(a);
				a = NULL;
			}
			else if (a->dir == NULL)
			{
				Arvore *tmp = a;
				a = a->esq;
				free(tmp);
			}
			else if (a->esq == NULL)
			{
				Arvore *tmp = a;
				a = a->dir;
				free(tmp);
			}
			else
			{
				Arvore *tmp = a->esq;
				while (tmp->dir != NULL)
					tmp = tmp->dir;
				a->info = tmp->info;
				tmp->info = v;
				a->esq = remover(a->esq, v);
			}
		}
	}

	return a;
}

//========= Q1 - busca
int buscar(Arvore *a, int v)
{
	/* Completar */
	if (a == NULL)
		return 0;
	else if (v < a->info)
		return buscar(a->esq, v);
	else if (v > a->info)
		return buscar(a->dir, v);
	else
		return 1;
}

//========= Q2 - min =====
int min(Arvore *a)
{
	// retorna e imprime o menor valor da arv
	// o menor valor sera o int mais a esq
	int valor_min = a->info;

	while (a != NULL){
		valor_min = a->info;
		a = a->esq;
	}
	return valor_min;
}

//========= Q2 - max =====
int max(Arvore *a)
{
	// retorna e imprime o maior valor da arv
	// o maior valor sera o int mais a dir
	int valor_max = a->info;
	while (a != NULL)
	{
		valor_max = a->info;
		a = a->dir;
	}
	return valor_max;
}

//========= Q3 - imprime_decrescente =====
void imprime_decrescente(Arvore *a)
{
	if(!arvore_vazia(a))
	{
		imprime_decrescente(a->dir);
		printf(" %d ", a->info);
		imprime_decrescente(a->esq);
	}
}

//========= Q4 - maior ramo =====

int comp_max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int maior_ramo(Arvore *a)
{
	// retorna o valor do maior ramo
	if (!arvore_vazia(a))
		return comp_max(maior_ramo(a->esq),maior_ramo(a->dir)) + a->info;
	else
		return 0;
}


void pre_order(Arvore *a)
{
	if (a != NULL)
	{
		printf("%d ", a->info);
		pre_order(a->esq);
		pre_order(a->dir);
	}
}

int main()
{

	int i;

	Arvore *a = cria_arvore_vazia();
	//--------//\
	a = inserir(a, 30);
	a = inserir(a, 50);
	a = inserir(a, 90);
	a = inserir(a, 20);
	a = inserir(a, 40);
	a = inserir(a, 95);
	a = inserir(a, 10);
	a = inserir(a, 35);
	a = inserir(a, 45);
	//--------//\

	// ====== Q1 ====
	printf("\n");
	pre_order(a);
	printf("\n");

	a = inserir(a, 47);

	printf("\n");
	pre_order(a);
	printf("\n");

	a = remover(a, 47);

	printf("\n");
	pre_order(a);
	printf("\n");

	printf("\nBusca:%d\n", buscar(a, 47));

	// ====== Q2 ====
	int minimo = min(a);
	int maximo = max(a);
	// ====== Q3 ====
	printf("\nOrdem decrescente:\n");
	imprime_decrescente(a);

	// ====== Q4 ====

	printf("\nO maior ramo eh:%d\n", maior_ramo(a));

	// ====== Q5 ====
	/*	A inser¸c˜ao em ordem cria uma ABB degenerada (“lista”) e, consequentemente, sua
		altura ´e n − 1 (onde n ´e n´umero de n´os na ABB) e o custo para a busca ´e o custo
		de percorrer esta altura (n). Por outro lado, o tempo de busca na ABB aleat´oria
		´e bem menor, pois a inser¸c˜ao aleat´oria cria uma ABB que distribui os valores nas
		sub´arvores de direita e esquerda e, consequentemente, sua altura ´e menor do que
		n − 1 (no caso da ABB cheia a altura ´e logn).*/

	return 0;
}
