
/*ExercÃ­cio 2:
Crie uma função chamada "calcularMedia" que recebe como parÃ¢metro uma struct "Aluno", esta struct terá informações como: nome, data de nascimento, duas notas e média e retorna a média das notas.
Em seguida, crie um programa que declare um array de 5 alunos e utilize a função "calcularMedia" para imprimir a média de cada aluno.
Também crie uma função para verificar se um aluno está aprovado ou reprovado sendo nescessário média maior ou igual a 7,0 para aprovção.*/

/* Invocando bibliotecas */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

/*Definindo Constantes*/

#define T1 1

/*Declaração da estrutura dos Alunos*/

struct Aluno
{
    char nome[300], dataNascimento[15];
    float nota1, nota2, media;
};

/*|===========|PROTÓTIPOS DAS FUNÇÕES AUXILIARES|===========|*/

float calcularMedia(struct Aluno aluno);
void verificarAprovacao(struct Aluno aluno);

/*|===========|FUNÇÃO PRINCIPAL|===========|*/

int main()
{

    struct Aluno alunos[T1];
    int i;
    /*Coletando dados dos alunos*/

    for (i = 0; i < T1; i++)
    {
        printf("\n\tNome do aluno %d: \n", i + 1);
        scanf("%s", alunos[i].nome);
        printf("\n");
        printf("\n\tData de nascimento do aluno %d: \n", i + 1);
        scanf("%s", alunos[i].dataNascimento);
        printf("\n");
        printf("\n\tInforme a nota 1 do aluno %d: \n", i + 1);
        scanf("%f", &alunos[i].nota1);
        printf("\n");
        printf("\n\tInforme a nota 2 do aluno %d: \n", i + 1);
        scanf("%f", &alunos[i].nota2);
        printf("\n");

        alunos[i].media = calcularMedia(alunos[i]);
    }
    system("cls || clear");

    for (i = 0; i < T1; i++)
    {
        printf("Media das Notas de %s: %.2f\n", alunos[i].nome, alunos[i].media);
        verificarAprovacao(alunos[i]);
    }

    return 0;
}

/*|===========|FUNÇÕES AUXILIARES|===========|*/

/*Função da Média*/
float calcularMedia(struct Aluno aluno)
{
    return (aluno.nota1 + aluno.nota2) / 2;
}

/*Função de verificação*/
void verificarAprovacao(struct Aluno aluno)
{
    if (aluno.media >= 7.0)
    {
        printf("\t\n%s Aprovado!\n", aluno.nome);
    }
    else
    {
        printf("\t\n%s Reprovado.\n", aluno.nome);
    }
}