
/*Exercício 1:
Crie uma Struct Contato para representar informa��es de contatos, incluindo nome, n�mero de telefone e email. Solicite que o usu�io cadastre 3 contatos.
Escreva uma fun��o que recebe um nome como par�metro, e retorna o n�mero de telefone correspondente a esse nome.
Em seguida, implemente um programa que utiliza essa fun��o para buscar e imprimir o n�mero de telefone de um contato espec�fico.*/

/* Invocando bibliotecas */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*Definindo Constantes*/

#define T1 3

/*Declara��o da estrutura dos contatos*/

struct dados_contatos
{
    char nome[300], telefone[300], email[300];
};

/*Declarando Prot�tipos das Fun��es*/

void pesquisarContato(struct dados_contatos *contatos, char *contato); // <- Colocar "*" antes da variavel para inserir mais de um character.

/*|===========|FUN��O PRINCIPAL|===========|*/

int main()
{

    setlocale(LC_ALL, "portugues");

    struct dados_contatos contatos[T1];
    char contato[200];
    int i;

    /*Coletando informa��es dos contatos*/

    for (i = 0; i < T1; i++)
    {
        printf("\n\tDigite os dados do %d� contato: \n", i + 1);
        printf("\n\tNome: ");
        gets(contatos[i].nome);

        printf("\n\tTelefone: ");
        gets(contatos[i].telefone);

        printf("\n\tE-mail: ");
        gets(contatos[i].email);
    }

    printf("\n\tDigite o nome do contato que deseja pesquisar: \n");
    gets(contato);

    printf("\n");
    printf("\n");

    pesquisarContato(contatos, contato);

    return 0;
}

/*|===========|FUN��ES AUXILIARES|===========|*/

void pesquisarContato(struct dados_contatos *contatos, char *contato)
{
    int i;
    for (i = 0; i < T1; i++)
    {
        if (strcmp(contatos[i].nome, contato) == 0) // STRCMP => Compara nome inserido na busca, com o nomes armazedanos.
        {
            printf("Nome: %s \n", contatos[i].nome);
            printf("\n");
            printf("Telefone: %s \n", contatos[i].telefone);
            printf("\n");
            printf("E-mail: %s \n", contatos[i].email);
            return;
        }
    }
    printf("\n\tContato inexistente. \n");
}
