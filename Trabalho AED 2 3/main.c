/**
Descrição: Este programa gera aleatoriamente numeros ou le arquivo
para uma arvore AVL onde ele pode tanto inserir, qnto remover um numero
onde ele fara o balanceamento q é mostrado como (bf (-1 ou 0)) e mostrado em pre-ordem
caso o elemento exista ele aparece encontrado caso nao exista ele nao aparece so mostra onde provavelmente estaria.

Nota: Colocar o arquivo na pasta do programa com o nome "teste.txt"
GCC compiler and GDB debugger from TDM-GCC (version 4.7.1, 32 bit)

Nome: Victor Propheta Erbano
RGM: 021052
Matéria: Algoritmos e Estrutura de Dados II
Prof:André Chastel Lima
Data de Criação: 15/09/2014
Data Modificação: 12/11/2014
*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

/**Estrutura  para  dados*/
typedef struct node
{
int data;
struct node *left,*right;
int ht;
}node;

/**Todas funções e procedimentos*/
int selec();
int rand_menu();
int leitura_menu();
node *insert(node *,int);
node *inserti_on(node *,int);
node *Delete(node *,int);
void  preorder(node *);
void  inorder(node *);
int   height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);
void searchElement(node *,int);

/**Função principal*/
int main()
{
        while(selec()  !=  3);

return 0;
}

/**Menu principal*/
int selec()
{
    node *root=NULL;
    int x,n,i,op;
    int option = 0;

    system("cls");
    printf("Menu da Entrada de Dados\n");
    printf(" 1 - Geracao Aleatoria\n");
    printf(" 2 - Entrada com Arquivo\n");
    printf(" 3 - Sair\n");
    printf("  Opcao:  ");
    scanf("%d",  &option);
    switch (option)
    {
        case 1:
            while(rand_menu()  !=  5);
        break;
        case 2:
            while(leitura_menu()  !=  5);
        break;
        case 3:
            system("cls");
        break;
        default:
            system("cls");
            printf("Opcao  invalida!");
            system("pause");
        break;
    }
return option;
}

/**Adicionar numero aleatorio*/
int rand_menu()
{

    node *root=NULL;
    int x,n,i,op;
    root=NULL;
    int w;

    printf("Entre com a qntidade de numeros aleatorios a ser gerado\n");
    scanf("%d",&w);
    for(i=0;i<w+1;i++)/**para aumentar a quantidade de numeros a ser inseridos só mudar o 20*/
    {
        x = rand() % 500;/**para aumentar a quantidade de numeros randomicos só mudar o 30*/
        root=insert(root,x);
    }
    do
    {
        printf("\n1)Busca");
        printf("\n2)Inserir:");
        printf("\n3)Deletar:");
        printf("\n4)Imprimir:");
        printf("\n5)Sair:");
        printf("\n\nOpcao:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\nEntre com o numero a ser buscado:\n");
                scanf("%d",&x);
                printf("\n");
                searchElement(root,x);
            break;
           case 2:

                printf("\nEntre com o numero:");
                scanf("%d",&x);
                root=inserti_on(root,x);
            break;
            case 3:
                printf("\nEntre com o numero a ser deletado:");
                scanf("%d",&x);
                root=Delete(root,x);
            break;
            case 4:
                printf("\nSequencia em pre-ordem:\n");
                preorder(root);
                //printf("\n\nSenquencia em ordem:\n");
                //inorder(root);
                printf("\n");
            break;
        }

}while(op!=5);
}

/**Leitura de Arquivo*/
int leitura_menu()
{

    node *root=NULL;
    FILE *fp;
    int x,n,i,op;
    root=NULL;

    fp = fopen("teste.txt","r");
    if (fp == NULL)
    {
        printf("Nao existe nenhum dado a ser lido ou o arquivo reportou um erro!\n");
    }

    while(!feof(fp))
    {
        fscanf(fp,"%d",&x);
        if(x<=-1)
        {
            break;
        }
        else
        {
            root=insert(root,x);
        }
    }
    fclose(fp);

    do
    {
        printf("\n1)Busca");
        printf("\n2)Inserir:");
        printf("\n3)Deletar:");
        printf("\n4)Imprimir:");
        printf("\n5)Sair:");
        printf("\n\nOpcao:");
        scanf("%d",&op);
        switch(op)
        {

            case 1:
                printf("\nEntre com o numero a ser buscado:\n");
                scanf("%d",&x);
                printf("\n");
                searchElement(root,x);
            break;
            case 2:

                printf("\nEntre com o numero:");
                scanf("%d",&x);
                root=inserti_on(root,x);
            break;
            case 3:
                printf("\nEntre com o numero a ser deletado:");
                scanf("%d",&x);
                root=Delete(root,x);
            break;
            case 4:
                printf("\nSequencia em pre-ordem:\n");
                preorder(root);
                //printf("\n\nSenquencia em ordem:\n");
                //inorder(root);
                printf("\n");
            break;
        }

}while(op!=5);
}

/**no que mostra o balanceamento*/
node * insert(node *T,int x)
{

        if(T==NULL)
        {
                    T=(node*)malloc(sizeof(node));
                    T->data=x;
                    T->left=NULL;
                    T->right=NULL;
        }
        else
                if(x > T->data)                /** inserir na sub-árvore direita*/
                {
                                             T->right=insert(T->right,x);
                                             if(BF(T)==-2)
                                                            if(x>T->right->data)

                                                                           T=RR(T);
                                                            else
                                                                           T=RL(T);
                              }
                              else
                                             if(x<T->data)
                                             {
                                                            T->left=insert(T->left,x);    /** inserir na sub-árvore esquerda*/
                                                            if(BF(T)==2)
                                                                           if(x < T->left->data)
                                                                                          T=LL(T);
                                                                           else
                                                                                          T=LR(T);
                                             }
                                             T->ht=height(T);
                                             return(T);
}

/**no de inserção*/
node * inserti_on(node *T,int x)
{

        if(T==NULL)
        {
                    T=(node*)malloc(sizeof(node));
                    T->data=x;
                    T->left=NULL;
                    T->right=NULL;
        }
        else
                if(x > T->data)                /** inserir na sub-árvore direita*/
                {
                                             T->right=inserti_on(T->right,x);
                                             if(BF(T)==-2)
                                                            if(x>T->right->data)
                                                            {
                                                                printf("\n");
                                                                if(T!=NULL)
                                                                    {
                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                        preorder(T->left);
                                                                        preorder(T->right);
                                                                    }
                                                                           T=RR(T);
                                                                           printf("\n");
                                                                if(T!=NULL)
                                                                    {
                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                        preorder(T->left);
                                                                        preorder(T->right);
                                                                    }
                }
                                                            else
                                                            {
                                                                printf("\n");
                                                                 if(T!=NULL)
                                                                    {
                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                        preorder(T->left);
                                                                        preorder(T->right);
                                                                    }
                                                                           T=RL(T);
                                                                           printf("\n");
                                                                if(T!=NULL)
                                                                    {
                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                        preorder(T->left);
                                                                        preorder(T->right);
                                                                    }
                                                            }
                              }
                              else
                                             if(x<T->data)
                                             {

                                                            T->left=inserti_on(T->left,x);    /** inserir na sub-árvore esquerda*/
                                                            if(BF(T)==2)
                                                                           if(x < T->left->data)
                                                                           {
                                                                               printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }

                                                                                          T=LL(T);
                                                                                          printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                                                                           }
                                                                           else{
                                                                                printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                                                                                          T=LR(T);
                                                                                          printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                                                                           }
                                             }

                                             T->ht=height(T);
                                             return(T);
}


/**no para deletar*/
node * Delete(node *T,int x)
{
    node *p;

    if(T==NULL)
    {
        return NULL;
    }
    else

    if(x > T->data)                /** inserir na sub-árvore direita*/
    {
        T->right=Delete(T->right,x);
        if(BF(T)==2)
                if(BF(T->left)>=0)
                {
                    printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }

                        T=LL(T);
                        printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                }
                else
                {
                    printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }

                    T=LR(T);
                    printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                }
    }
    else
        if(x<T->data)
        {
            T->left=Delete(T->left,x);
                    if(BF(T)==-2)/**Reequilibrar durante o movimento*/
                            if(BF(T->right)<=0)
                            {
                                printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }

                                T=RR(T);
                                printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                            }
                            else{
                                printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                                T=RL(T);
                            printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                            }
                                                                            }
        }
        else
        {/**dados a serem apagados é encontrado*/
            if(T->right !=NULL)
                {  /**excluir seu sucessor em ordem*/
                    p=T->right;
                    while(p->left != NULL)
                                p=p->left;

                        T->data=p->data;
                        T->right=Delete(T->right,p->data);
                        if(BF(T)==2)/**Reequilibrar durante o movimento*/
                                if(BF(T->left)>=0){
                                    printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                                        T=LL(T);
                                        printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                                }
                                else{
                                        printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                                        T=LR(T);
                                printf("\n");
                                                                                if(T!=NULL)
                                                                                    {
                                                                                        printf("%d(Bf=%d) ",T->data,BF(T));
                                                                                        preorder(T->left);
                                                                                        preorder(T->right);
                                                                                    }
                                }
                }
                        else
                                return(T->left);

    }
    T->ht=height(T);
return(T);
}

/**Verifica o balanço*/
int height(node *T)
{
    int lh,rh;
    if(T==NULL)
            return(0);
    if(T->left==NULL)
            lh=0;
    else
            lh=1+T->left->ht;
    if(T->right==NULL)
            rh=0;
    else
            rh=1+T->right->ht;
    if(lh>rh)
            return(lh);
    return(rh);
}

/**rotação para a direita*/
node * rotateright(node *x)
{
    node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
return(y);
}

/**rotação para a esquerda*/
node * rotateleft(node *x)
{
    node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);
return(y);
}

/**rotação para a esquerda*/
node * RR(node *T)
{
    T=rotateleft(T);
return(T);
}

/**rotação para a direita*/
node * LL(node *T)
{
    T=rotateright(T);
return(T);
}

/**rotação para a esquerda*/
node * LR(node *T)
{
    T->left=rotateleft(T->left);
    T=rotateright(T);
return(T);
}

/**rotação para a direita*/
node * RL(node *T)
{
    T->right=rotateright(T->right);
    T=rotateleft(T);
return(T);
}


int BF(node *T)
{
    int lh,rh;

    if(T==NULL)
    return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
        if(T->right==NULL)
            rh=0;
        else
            rh=1+T->right->ht;
return(lh-rh);
}

/**Visualização em pre ordem*/
void preorder(node *T)
{
    if(T!=NULL)
    {
        printf("%d(Bf=%d) ",T->data,BF(T));
        preorder(T->left);
        preorder(T->right);
    }
}

/**Visualização em ordem crescente
void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d(Bf=%d) ",T->data,BF(T));
        inorder(T->right);
    }
}
*/
/**Busca de elemento*/
 void searchElement(node *T,int x)
 {
    int flag =0;

    if(T==NULL)
    {
        return NULL;
    }
    if((T!=NULL)&&(x != T->data))
    {
        if(x >= T->data)
        {
            printf("%d(Bf=%d) ",T->data,BF(T));
            searchElement(T->right,x);
            flag=1;
        }
        else
        {
            if(x <= T->data)
            {
                printf("%d(Bf=%d) ",T->data,BF(T));
                searchElement(T->left,x);
                flag=1;
            }
        }
    }
    if(!flag)
    {
        printf("%d(Bf=%d) ",T->data,BF(T));
        printf("\n");
        printf("Elemento encontrado\n");
    }
    printf("\n");

}
