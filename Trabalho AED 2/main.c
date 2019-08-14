#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct pilha{
        int n;
        float vet[N];
        }Pilha;

Pilha *pilha_cria(){
      Pilha *p=(Pilha*)malloc(sizeof(Pilha));
      p->n=0;
      return p;
}
int pilha_vazia(Pilha *p){
    return(p->n==0);
}

void pilha_push(Pilha *p, float v)
 {
    if(p->n==N){
      printf("Capacidade da pilha esgotada.\n");
      exit (1); //aborta o programa
      }   //insere novo elemento
      p->vet[p->n]=v;
      p->n++;
}
float pilha_pop(Pilha *p){
     float v;
     if(pilha_vazia(p)){
         printf("Pilha vazia.\n");
         exit (1);
     }    //retira o elemento da pilha
     v=p->vet[p->n-1];
     p->n--;
     return v;
}

void pilha_libera(Pilha *p){
     free(p);
}
void mostra_pilha(Pilha *p)
{
    int i;
     printf("Conteúdo da pilha\n");
     for(i=p->n-1;i>=0;i--)
         printf("%0.f\n",p->vet[i]);
     printf("\n");
}
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Empilha (push)\n");
     printf("2. Retira (pop)\n");
     printf("3. Mostra a pilha\n");
     printf("4. Fim\n");
}

int main()
{
    Pilha *pi=pilha_cria();
    int opmenu;
    float item;
    do{
        menu();
        scanf("%d", &opmenu);
        switch (opmenu) {
        case 1 : //insere
                printf("Digite o valor a ser empilhado: ");
                scanf("%f", &item);
                pilha_push(pi,item);
                break;
        case 2 : //retira
                printf("Elemento retirado = %.0f\n",pilha_pop(pi));
                break;
        case 3 : //mostra
                mostra_pilha(pi);
                break;
       }  //switch
       printf("\n");
       system("pause");
    } while(opmenu!=4);
}

