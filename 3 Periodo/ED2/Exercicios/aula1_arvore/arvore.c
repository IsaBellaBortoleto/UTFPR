#include "arvore.h"

Arvore *cria_arv_vazia(void) { return NULL; }

Arvore *constroi_arv(char c, Arvore *e, Arvore *d) {
  Arvore *no = (Arvore *)malloc(sizeof(Arvore));
  no->info = c;
  no->esq = e;
  no->dir = d;
  return no;
}

int verifica_arv_vazia(Arvore *a) { return (a == NULL); }

void arv_libera(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
    arv_libera(a->esq);
    arv_libera(a->dir);
    free(a);
  }
}

//========= Exercício 2 - pré-ordem (R,E,D)====
void pre_ordem(Arvore *a) {
  // comeca na raiz, no a
  // ordem: a->b->d->c->e->f

  if (!verifica_arv_vazia(a)) {
    printf("%c", a->info);
    pre_ordem(a->esq);
    pre_ordem(a->dir);
  }
}
  //========= Exercício 2 - in-ordem (E,R,D) ====
  int in_ordem(Arvore * a) {
    // ordem: b,d,u,e,c,f

    if (!verifica_arv_vazia(a)) {
      in_ordem(a->esq);
      printf("%c", a->info);
      in_ordem(a->dir);
    }
  }

  //========= Exercício 2 - pós-ordem (E,D,R)====
  int pos_ordem(Arvore * a) {
    // ordem: d,b,e,f,c,a
    if (!verifica_arv_vazia(a)) {
      pos_ordem(a->esq);
      pos_ordem(a->dir);
      printf("%c", a->info);
    }
  }

//========= Exercício 3 - pertence ====
int pertence_arv(Arvore *a, char c)
{
  if (!verifica_arv_vazia(a))
  {
    if (a->info == c)
      return 1;
    else
      return pertence_arv(a->esq, c) || pertence_arv(a->dir, c);
  }
  else
    return 0;
}

//========= Exercício 4 - conta nós ====
int conta_nos(Arvore *a)
{
  if (!verifica_arv_vazia(a))
  {
    return 1 + conta_nos(a->esq) + conta_nos(a->dir);
  }
  else
    return 0;
}

//========= Exercício 5 - calcula altura ====

int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int calcula_altura_arvore(Arvore *a) {
  if(!verifica_arv_vazia(a))
  {
    return(max(calcula_altura_arvore(a->esq),calcula_altura_arvore(a->dir))+1); 
  }
  else 
    return -1; //se ela for nula, altura=-1

}


//========= Exercício 6 - conta folhas ====
int conta_nos_folha(Arvore *a)
{
  if (!verifica_arv_vazia(a))
  {
    if ((a->esq == NULL) && (a->dir == NULL)) //se n tem filho, eh uma folha
      return 1;
    else
      return conta_nos_folha(a->esq) + conta_nos_folha(a->dir); 
  }
  else
    return 0;
}

int main(int argc, char *argv[])
{

  Arvore *a = constroi_arv(
    'a',
    constroi_arv('b', cria_arv_vazia(),
           constroi_arv('d', cria_arv_vazia(), cria_arv_vazia())),
    constroi_arv('c', constroi_arv('e', cria_arv_vazia(), cria_arv_vazia()),
           constroi_arv('f', cria_arv_vazia(), cria_arv_vazia())));

  // =============== Para testar o ex.2
  printf("Pre-ordem: ");
  pre_ordem(a);
  printf("\n");

  printf("In-ordem: ");
  in_ordem(a);
  printf("\n");

  printf("Pos-ordem: ");
  pos_ordem(a);
  printf("\n");

  //============== Para testar o ex.3
  char caracteres[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
  int n = sizeof(caracteres) / sizeof(caracteres[0]);
  for (int i = 0; i < n; i++)
  {
    char c = caracteres[i];
    if (pertence_arv(a, c))
    {
      printf("O caractere '%c' pertence à árvore.\n", c);
    }
    else
    {
      printf("O caractere '%c' NÃO pertence à árvore.\n", c);
    }
  }

  //============= Para testar o ex.4
  printf("Total de nós na árvore: %d\n", conta_nos(a));

  //============= Para testar o ex.5
  printf("A altura da árvore é: %d\n", calcula_altura_arvore(a));

  //============= Para testar o ex.6
  printf("Total de folhas na árvore: %d\n", conta_nos_folha(a));

  arv_libera(a);

  return 0;
}
