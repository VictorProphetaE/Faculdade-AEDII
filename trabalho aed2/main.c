/**
Descrição: Este programa gera aleatoriamente numeros ou le arquivo
para lista, fila e pilha em todos ele pode adicionar, excluir ou mostrar os numeros
em fila e pilha ele pode excluir a lista toda.

Nota: Colocar o arquivo na pasta do programa com o nome "teste.txt"
faltou busca binaria e ordenação da parte de lista.
GCC compiler and GDB debugger from TDM-GCC (version 4.7.1, 32 bit)

Nome: Victor Propheta Erbano
RGM: 021052
Matéria: Algoritmos e Estrutura de Dados II
Prof:André Chastel Lima
Data de Criação: 13/04/2014
Data Modificação: 27/04/2014

*/

#include <stdio.h>
#include <stdlib.h>

/**Estrutura  para  dados*/
typedef  struct  data
{
    int  number;
    /**ponteiro  para  o  proximo  item  do  lista*/
    struct  data  *next;
}datas;

/**ponteiros  para  o  primeiro  dado  e  o  ultimo  dado*/
struct  data  *begin,  *end;

void  eguals(int  number,  int  size)
{
    int  cont=  10;

    while(size  >=  cont)
    {
        if(cont  >  number)
        printf("0");
        cont=  cont  *  10;
    }
}

/**Contador  para  todos  os  dados  da  lista*/
int  all_data=  0;

void  clear_data()
{
    struct  data  *temp;
    temp=  begin;
    while(temp  !=  NULL)
    {
        begin=  temp->next;
        free(temp);
        temp=  begin;
    }
    begin=  NULL;
    end=  NULL;
    all_data=  0;
}

/**Leitura de Arquivo*/
void leitura()
{
    int  input =  0;
    FILE *fp;
    fp = fopen("teste.txt","r");
    if (fp == NULL)
    {
        printf("Nao existe nenhum dado a ser lido ou o arquivo reportou um erro!\n");
    }
    while(!feof(fp))
    {
        fscanf(fp,"%d",&input);
        if(all_data  !=  0)
        {
        struct  data  *temp;
        /**se  não  for  o  primeiro  numero  fara...*/
        temp=  malloc  (sizeof  (datas));
        temp->next=  NULL;
        temp->number=  input;
        end->next=  temp;
        end=  temp;
        all_data++;
        }
        else
        {
            /**se  for  o  primeiro*/
            begin=  malloc(sizeof(datas));
            begin->next=  NULL;
            begin->number=  all_data  +  1;
            end=begin;
            all_data++;
        }
    }
    fclose(fp);

}

/**Adicionar numero aleatorio*/
void  rand_data()
{
    int  input =  0;
    int i,k;
    for(i=0;i<=20;i++)
    {
        input = rand() % 30;
        /**se  não  for  o  primeiro  numero  fara...*/
        if(all_data  !=  0)
        {
            struct  data  *temp;
            temp=  malloc  (sizeof  (datas));
            temp->next=  NULL;
            temp->number=  input;
            end->next=  temp;
            end=  temp;
            all_data++;
        }
        else
        {
            for(k = -1; k < i; k++)
            {
                /**se  for  o  primeiro*/
                input = rand() % 30;
                begin=  malloc(sizeof(datas));
                begin->next=  NULL;
                begin->number=  all_data  +  1;
                end=begin;
                all_data++;
                k = 0;
            }
        }
    }

}

/**Função  para  adicionar  numero no  lista*/
void  add_data()
{
    system("cls");
    /**ler  o  numero  e  o    salva  em  uma  variavel  temporaria*/
    int  input =  0;

    printf("Adicionar\n");
    printf("Numero:  \n");
    scanf("%d",  &input);
    /**se  não  for  o  primeiro  numero  fara...*/
    if(all_data  !=  0)
    {
        struct  data  *temp;
        temp=  malloc  (sizeof  (datas));
        temp->next=  NULL;
        temp->number=  input;
        end->next=  temp;
        end=  temp;
        all_data++;
    }
    /**se  for  o  primeiro*/
    else
    {
        begin=  malloc(sizeof(datas));
        begin->next=  NULL;
        begin->number=  all_data  +  1;
        end=begin;
        all_data++;
    }
    system("cls");
}

/**Deleta  endereço  recebido  por  paramento*/
int  delete_data(struct  data  *delete)
{
    system("cls");
    if(delete  ==  begin)
    {
        begin=  begin->next;
        free(delete);
        all_data--;
        return  0;
    }
    else
    {
    struct  data  *temp;
    temp=  begin;
    while(1)
    {
        if(temp->next  ==  delete)
        {
            temp->next=  temp->next->next;
            if(delete  ==  end)
            end=  temp;
            free(delete);
            all_data--;
            end=  temp;
        return  0;
        }
        temp=  temp->next;
        }
    }
  return  1;
}

/**Mostra  o  array  dado*/
void  show_data()
{
    int  cont=  1;
    if(all_data  !=  0)
    {
        struct  data  *temp;
        temp=  begin;
        while(temp  !=  NULL)
        {
        printf("  ");
        eguals(temp->number,  all_data);
        printf("%d  -  %d\n",  cont,  temp->number);
        temp=  temp->next;
        cont++;
        }
    }
    else
        printf("Sua  lista  está  vazia!!!\n");
}

/**Esvazia a fila e pilha e mostrar*/
void  esvaziar_filapilha()
{
    system("cls");
    int  cont=  1;

    if(all_data  !=  0)
    {
        struct  data  *temp;
        temp=  begin;
        while(temp  !=  NULL)
        {
            printf("  ");
            eguals(temp->number,  all_data);
            printf("%d  -  %d\n",  cont,  temp->number);
            temp=  temp->next;
            cont++;
            system("pause");
        }
    }
    else
    {
        printf("Sua  lista  está  vazia!!!\n");
    }
    struct  data  *temp;
    temp=  begin;
    while(temp  !=  NULL)
    {
        begin=  temp->next;
        free(temp);
        temp=  begin;
    }
    begin=  NULL;
    end=  NULL;
    all_data=  0;
    system("pause");
}

/**Esvaziar sem mostrar para gerar novos numeros aleatorios*/
void  esvaziar()
{
    system("cls");
    struct  data  *temp;

    temp=  begin;
    while(temp  !=  NULL)
    {
        begin=  temp->next;
        free(temp);
        temp=  begin;
    }
    begin=  NULL;
    end=  NULL;
    all_data=  0;
}

/**Menu  fila*/
int  menu_file()
{
    int  option=  0;
    system("cls");
    printf("      Menu  Fila\n");
    printf("  1-  Adicionar\n");
    printf("  2-  Excluir\n");
    printf("  3-  Exibir\n");
    printf("  4-  Esvaziar Fila\n");
    printf("  5-  Sair\n");
    printf("Opcao:  ");
    scanf("%d",  &option);
    switch  (option)
    {
    case  1:
        add_data();
        break;
        case  2:
            if(delete_data(begin)  ==  0)
                printf("Dado  deletado  com  sucesso!");
            else
                printf("Nenhum  dado  deletado");
    system("pause");
        break;
        case  3:
            system("cls");
            printf("Estado  atual  da  fila\n");
            show_data();
    system("pause");
        break;
        case  4:
            esvaziar_filapilha();
        break;
        case  5:
            system("cls");
        break;
        default:
            system("cls");
            printf("Opcao  invalida!");
    system("pause");
        break;
      }
    return  option;
}

/**Menu  pilha*/
int  menu_stack()
{
    int  option=  0;
    system("cls");
    printf("      Menu  Pilha\n");
    printf("  1-  Adicionar\n");
    printf("  2-  Excluir\n");
    printf("  3-  Exibir\n");
    printf("  4-  Esvaziar Pilha\n");
    printf("  5-  Sair\n");
    printf("Opcao:  ");
    scanf("%d",  &option);
    switch  (option)
    {
        case  1:
        add_data();
        break;
        case  2:
            if(delete_data(end)  ==  0)
                printf("Dado  deletado  com  sucesso!");
          else
                printf("Nenhum  dado  deletado");
    system("pause");
        break;
        case  3:
            system("cls");
            printf("Estado  atual  da  fila\n");
            show_data();
    system("pause");
        break;
        case  4:
            esvaziar_filapilha();
        break;
        case  5:
            system("cls");
        break;
        default:
            system("cls");
            printf("Opcao  invalida!");
    system("pause");
        break;
    }
  return  option;
}

/**Menu  lista*/
int  menu_list()
{
    int  option=  0;
    system("cls");
    printf("      Menu  Lista\n");
    printf("  1-  Adicionar\n");
    printf("  2-  Excluir\n");
    printf("  3-  Exibir\n");
    printf("  4-  Pesquisar\n");
    printf("  5-  Sair\n");
    printf("Opcao:  ");
    scanf("%d",  &option);
    switch  (option)
    {
        case  1:
            add_data();
        break;
        case  2:
            if(delete_data(end)  ==  0)
                printf("Dado  deletado  com  sucesso!");
            else
                printf("Nenhum  dado  deletado");
        break;
        case  3:
            system("cls");
            printf("Estado  atual  da  fila\n");
            show_data();
    system("pause");
        break;
        case  4:
        break;
        case  5:
            system("cls");
        break;
        default:
            system("cls");
            printf("Opcao  invalida!");
    system("pause");
        break;
    }
  return  option;
}

/**Menu  principal*/
int  menu()
{
    int option =  0;

    system("cls");
    printf("Menu  Principal\n");
    printf(" 1 - Fila\n");
    printf(" 2 - Pilha\n");
    printf(" 3 - Lista\n");
    printf(" 4 - Sair\n");
    printf("  Opcao:  ");
    scanf("%d",  &option);
    switch  (option)
    {
        case  1:
            while(menu_file()  !=  5);
        break;
        case  2:
            while(menu_stack()  !=  5);
        break;
        case  3:
            while(menu_list()  !=  5);
        break;
        case  4:
            esvaziar();
            system("cls");
        break;
        default:
            system("cls");
            printf("Opcao  invalida!");
            system("pause");
        break;
    }
return  option;
}

int selec()
{
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
            rand_data();
            while(menu()  !=  4);
        break;
        case 2:
            leitura();
            while(menu()  !=  4);
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

/**Função  principal*/
int  main()
{
    while(selec()  !=  3);
    return  0;
}
