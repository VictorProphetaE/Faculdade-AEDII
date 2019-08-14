/**
Descrição:

Nota: Colocar o arquivo na pasta do programa com o nome "teste.txt"
faltou busca binaria e ordenação da parte de lista.
GCC compiler and GDB debugger from TDM-GCC (version 4.7.1, 32 bit)

Nome: Victor Propheta Erbano
RGM: 021052
Matéria: Algoritmos e Estrutura de Dados II
Prof:André Chastel Lima
Data de Criação: 25/06/2014
Data Modificação: 08/07/2014

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

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

/**Função  para  adicionar  numero a lista*/
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

/**Numeros randomicos para ordenação*/
int rand_ord(int *vet,int tamanho)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < tamanho; i ++)
    {
        vet[i] = rand() % 100;
    }
}

/**Insertion Sort*/
void insertionSort(int vetorDesordenado[], int tamanhoVetor )
{
   int i, j, valorAtual;

    for( j=1; j < tamanhoVetor; j++ )
    {
        valorAtual = vetorDesordenado[j];
        i = j-1;

        while(i >= 0 && vetorDesordenado[i] > valorAtual)
        {
            vetorDesordenado[i+1] = vetorDesordenado[i];
            i--;
        }
        vetorDesordenado[i+1] = valorAtual;
    }
    for(i=0;i<tamanhoVetor;i++)
    {
        printf("%d ",vetorDesordenado[i]);
    }
    printf("\n");
}

/**Bubble Sort*/
void bubleSort( int vetorDesordenado[], int tamanhoVetor )
{
    int i, j;
    for( i = 0; i < ( tamanhoVetor -1 );  i++ )
    {
        for( j=0; j <( tamanhoVetor -( i +1 ) ); j++ )
        {
            if( vetorDesordenado[j] > vetorDesordenado[j+1] )
            {
                trocarPosicaoValores( &vetorDesordenado[j], &vetorDesordenado[j+1] );
            }
        }
    }
    for(i=0;i<tamanhoVetor;i++)
    {
        printf("%d ",vetorDesordenado[i]);
    }
    printf("\n");
}

/**Troca de posicoes*/
void trocarPosicaoValores( int *posicaoA, int *posicaoB )
{
   int temporario;
   temporario = *posicaoA;
   *posicaoA = *posicaoB;
   *posicaoB = temporario;
}

/**Selection Sort*/
void selectionSort( int *vetorDesordenado, int tamanhoVetor )
{
    int i, j, posicaoValorMinimo;

    for (i = 0; i < ( tamanhoVetor - 1 ); i++)
    {
        posicaoValorMinimo = i;
        for (j = ( i + 1 ); j < tamanhoVetor; j++)
        {
            if( vetorDesordenado[j] < vetorDesordenado[posicaoValorMinimo] )
            {
            posicaoValorMinimo = j;
            }
        }

        if ( i != posicaoValorMinimo )
        {
            trocarPosicaoValores( &vetorDesordenado[i], &vetorDesordenado[posicaoValorMinimo] );
        }
    }
    for(i=0;i<tamanhoVetor;i++)
    {
        printf("%d ",vetorDesordenado[i]);
    }
    printf("\n");
}

/**Merge Sort*/
void mergeSort( int *vetorDesorndeado, int posicaoInicio, int posicaoFim )
{
   int i,j,k,metadeTamanho,*vetorTemp;
   if ( posicaoInicio == posicaoFim ) return;

   /** ordenacao recursiva das duas metades*/
   metadeTamanho = ( posicaoInicio+posicaoFim )/2;
   mergeSort( vetorDesorndeado, posicaoInicio, metadeTamanho);
   mergeSort( vetorDesorndeado, metadeTamanho+1,posicaoFim );

   /** intercalacao no vetor temporario t*/
   i = posicaoInicio;
   j = metadeTamanho+1;
   k = 0;
   vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim-posicaoInicio+1));

   while( i < metadeTamanho+1 || j  < posicaoFim+1 )
   {
      if ( i == metadeTamanho+1 )
      { /** i passou do final da primeira metade, pegar v[j]*/
         vetorTemp[k] = vetorDesorndeado[j];
         j++;
         k++;
      }
      else
      {
         if (j==posicaoFim+1)
         {
            /** j passou do final da segunda metade, pegar v[i]*/
            vetorTemp[k] = vetorDesorndeado[i];
            i++;
            k++;
         }
         else
         {
            if (vetorDesorndeado[i] < vetorDesorndeado[j])
            {
               vetorTemp[k] = vetorDesorndeado[i];
               i++;
               k++;
            }
            else
            {
              vetorTemp[k] = vetorDesorndeado[j];
              j++;
              k++;
            }
         }
      }

   }
   /** copia vetor intercalado para o vetor original*/
   for( i = posicaoInicio; i <= posicaoFim; i++ )
   {
      vetorDesorndeado[i] = vetorTemp[i-posicaoInicio];
   }
   free(vetorTemp);

}

/**Quick Sort*/
void quickSort( int *vetorDesordenado, int posicaoInicio, int posicaoFim )
{
   int pivot;
   if (posicaoInicio < posicaoFim)
   {
      pivot = partition( vetorDesordenado, posicaoInicio, posicaoFim);
      quickSort( vetorDesordenado, posicaoInicio, pivot);
      quickSort(vetorDesordenado, pivot+1, posicaoFim);
   }
}

/**Particionamento do quick sort*/
int partition( int *vetorDesordenado, int posicaoInicio, int posicaoFim )
{
   int x,i,j,auxiliar;
   x = vetorDesordenado[posicaoInicio];
   i = posicaoInicio - 1;
   j = posicaoFim + 1;

   for(;;)
   {
      do { j--; } while( vetorDesordenado[j] > x );
      do { i++; } while( vetorDesordenado[i] < x );

      if (i < j)
      {
         auxiliar = vetorDesordenado[i];
         vetorDesordenado[i] = vetorDesordenado[j];
         vetorDesordenado[j] = auxiliar;
      }
      else
      {
         return j;
      }
   }
}

/**Heap Sort*/
void HeapSort(int *vetorDesordenado, int tamanhoVetor)
{
   int i = tamanhoVetor/2, pai, filho, t;

   for (;;)
   {
      if (i > 0)
      {
          i--;
          t = vetorDesordenado[i];
      }
      else
      {
          tamanhoVetor--;
          if (tamanhoVetor == 0)
             return;
          t = vetorDesordenado[tamanhoVetor];
          vetorDesordenado[tamanhoVetor] = vetorDesordenado[0];
      }

      pai = i;

      /**Primeiro será feita a comparação com o filho da esquerda*/
      filho = i*2;

      while (filho < tamanhoVetor)
      {
         /**Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado*/
          if ((filho + 1 < tamanhoVetor)  &&  (vetorDesordenado[filho + 1] > vetorDesordenado[filho]))
              filho++;
          if (vetorDesordenado[filho] > t)
          {
             vetorDesordenado[pai] = vetorDesordenado[filho];
             pai = filho;
             filho = pai*2 + 1;
          }
          else
             break;
      }
      vetorDesordenado[pai] = t;
   }
}

/**Menu  Ordenação*/
int  menu_Ordenacao()
{
    int  option=  0;
    system("cls");
    printf("      Menu  de Ordenacoes\n");
    printf("  1-  Insertion Sort\n");
    printf("  2-  Bubble Sort\n");
    printf("  3-  Selection Sort\n");
    printf("  4-  Merge Sort\n");
    printf("  5-  Quick Sort\n");
    printf("  6-  Heap Sort\n");
    printf("  7-  Sair\n");
    printf("Opcao:  ");
    scanf("%d",  &option);
    return  option+20;
}

/**Menu  lista encadeada*/
int  menu_list()
{
    int  option=  0;
    system("cls");
    printf("      Menu  Lista\n");
    printf("  1-  Adicionar\n");
    printf("  2-  Excluir\n");
    printf("  3-  Exibir\n");
    printf("  4-  Sair\n");
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

/**Menu de Selecionamento de Aleatorio ou Arquivo*/
int selec_lista()
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
            while(menu_list()  !=  4);
        break;
        case 2:
            leitura();
            while(menu_list()  !=  4);
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

/**Menu de Selecionamento de Aleatorio ou Arquivo*/
int selec_ordenacao()
{
    int option = 0;
    system("cls");
    printf("Menu da Entrada de Dados\n");
    printf(" 1 - Geracao Aleatoria\n");
    printf(" 2 - Entrada com Arquivo\n");
    printf(" 3 - Sair\n");
    printf("  Opcao:  ");
    scanf("%d",  &option);

    return option+10;
}

/**Operações para as ordenações*/
void operacoes()
{
    int i;
    int opt=0, opt2=0;
    int	nv1=0,nv2=0;
    int *vetor_base[TAM];
    int tamanho_vetor;

    do
    {
        fflush (stdin);
        fflush (stdout);
        /** Gerenciamento dos menus*/
        if (nv1==0)
        {
            opt = selec_ordenacao();
        }
        else
        {
            opt = menu_Ordenacao();
        }

        switch (opt)
        {
                case 11:
                    nv1=1;
                    tamanho_vetor = TAM;
                    rand_ord(&vetor_base, tamanho_vetor);
                    system("pause");
                break;

                /**Leitura do arquivo*/
                case 12:
                    nv1=1;
                        int cont=0;
                        int vet;
                        FILE *fp;
                        fp = fopen("teste.txt","r");
                        if (fp == NULL)
                        {
                            printf("Nao existe nenhum dado a ser lido ou o arquivo reportou um erro!\n");
                        }
                        while(!feof(fp))
                        {
                            fscanf(fp,"%d",&vet);
                            vetor_base[cont] = vet;
                            cont++;
                            printf("%d\n",vet);
                        }
                        fclose(fp);
                        tamanho_vetor = cont;
                    system("pause");
                break;

                case 21:
                    nv2=1;
                    for (i = 0; i < tamanho_vetor; i ++)
                    {
                        printf("%d ",vetor_base[i]);
                    }
                    printf("\n");
                    insertionSort(&vetor_base, tamanho_vetor);
                    system("pause");
                    system("cls");
                break;

                case 22:
                    nv2=1;
                    for (i = 0; i < tamanho_vetor; i ++)
                    {
                        printf("%d ",vetor_base[i]);
                    }
                    printf("\n");
                    bubleSort(&vetor_base, tamanho_vetor);
                    system("pause");
                    system("cls");
                break;

                case 23:
                    nv2=1;
                    for (i = 0; i < tamanho_vetor; i ++)
                    {
                        printf("%d ",vetor_base[i]);
                    }
                    printf("\n");
                    selectionSort(&vetor_base, tamanho_vetor);
                    system("pause");
                    system("cls");
                break;

                case 24:
                    nv2=1;
                    for (i = 0; i < tamanho_vetor; i ++)
                    {
                        printf("%d ",vetor_base[i]);
                    }
                    printf("\n");
                    mergeSort(&vetor_base,0,tamanho_vetor);
                    for (i = 1; i < tamanho_vetor+1; i ++)
                    {
                        printf("%d ",vetor_base[i]);
                    }
                    printf("\n");
                    system("pause");
                    system("cls");
                break;

                case 25:
                    nv2=1;
                    for (i = 0; i < tamanho_vetor; i ++)
                    {
                        printf("%d ",vetor_base[i]);
                    }
                    printf("\n");
                    quickSort(&vetor_base,0,tamanho_vetor);
                    for (i = 1; i < tamanho_vetor+1; i ++)
                    {
                        printf("%d ",vetor_base[i]);
                    }
                    printf("\n");
                    system("pause");
                    system("cls");
                break;

                case 26:
                    nv2=1;
                    for (i = 0; i < tamanho_vetor; i ++)
                    {
                        printf("%d ",vetor_base[i]);
                    }
                    printf("\n");
                    HeapSort(&vetor_base, tamanho_vetor);
                    for (i = 0; i < tamanho_vetor; i ++)
                    {
                        printf("%d ",vetor_base[i]);
                    }
                    printf("\n");
                    system("pause");
                    system("cls");
                break;

                case 13:
                    opt = 3;
                    system("cls");
                    break;
                case 27:
                    opt = 3;
                    system("cls");
                    break;

            default:
                system("cls");
                printf("Opcao  invalida!");
                system("pause");
            break;

        }
    }while ( opt != 3 );
}

/**Menu  principal*/
int  menu()
{
    int option =  0;

    system("cls");
    printf("Menu  Principal\n");
    printf(" 1 - Ordenacao\n");
    printf(" 2 - Lista\n");
    printf(" 3 - Sair\n");
    printf("  Opcao:  ");
    scanf("%d",  &option);
    switch  (option)
    {
        case  1:
            operacoes();
        break;
        case  2:
            while(selec_lista()  !=  3);
        break;
        case  3:
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

/**Função  principal*/
int  main()
{
    while(menu()  !=  3);
    return  0;
}
