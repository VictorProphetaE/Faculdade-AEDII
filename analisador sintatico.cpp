#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char buffer[80], lookahead;
int i=0;

void S();
void L();
void erro();
void L_();

void reconhecedor (char t)
{
  if(lookahead==t)
        lookahead=buffer[i++];
    else
        erro();
}

void erro()
{
    cout << "Erro sintatico";
    exit(1);
}

void S()
{
    if(lookahead=='(')
       {
           reconhecedor('(');
           L();
           reconhecedor(')');
       }
    else if(lookahead=='a')
            reconhecedor('a');
        else erro();
}

void L()
{
    S();
    L_();
}

void L_()
{
    if(lookahead==',')
    {
        reconhecedor(',');
        S();
        L_();
    }
}

int main()
{
    system("cls");
    cout<<"Cadia:";
    gets(buffer);
    lookahead=buffer[i++];
    S();
    if(lookahead=='\0')
        cout<<"Analise sintatica completa com sucesso";
    else
        cout<<"Era esperado fim da cadeia";
    system("pause");

}
