
/*Exercício 3:
Desenvolva uma struct "Produto" que contenha informações como nome, preço e quantidade em estoque. Em seguida, desenvolva um menu para facilitar a escolha das opções:
1 - Adicionar produto
2 - Realizar uma compra
3 - Consultar estoque
4 - Sair do programa.

Escreva funções necessárias para calcular o valor total em estoque do produto e para atualizar a quantidade em estoque com base em uma compra.
Crie um programa que utiliza essas funções para um produto.
*/

/* Invocando bibliotecas */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*Estrutura do produto*/

struct Produto
{
    char nome[300];
    float preco;
    int quantidade;
};

/*|===========|PROTÓTIPOS DAS FUNÇÕES AUXILIARES|===========|*/

float calcularTotal(struct Produto *produto);
void realizarCompra(struct Produto *produto);

/*|===========|FUNÇÕES PRINCIPAL|===========|*/

int main()
{

    setlocale(LC_ALL, "portugues");

    struct Produto meuProduto; //= {"Produto A", 10.0, 50};
    int opcao;

    do
    {

        printf("\t\n|=====|MENU|======|:\n");
        printf("\n");
        printf("\n");
        printf("\t\nEscolha uma opção: \n");
        printf("\n");
        printf("\t\n1. Adicionar protudo\n");
        printf("\n");
        printf("\t\n2. Realizar uma compra\n");
        printf("\n");
        printf("\t\n3. Consultar estoque\n");
        printf("\n");
        printf("\t\n4. Sair do programa\n");
        printf("\n");
        scanf("%d", &opcao);

        system("cls || clear");

        fflush(stdin);
        switch (opcao)
        {
        case 1:
            printf("\n\tDigite o nome do Produto\n");
            gets(meuProduto.nome);
            printf("\n\tInforme o valor do produto:\n");
            scanf("%f", &meuProduto.preco);
           fflush(stdin);
            printf("\n\tInforme a quantidade: ");
            scanf("%d", &meuProduto.quantidade);
            break;
        case 2:
            realizarCompra(&meuProduto);
            break;
        case 3:
            printf("\t\nEstoque disponível: %d unidades\n", meuProduto.quantidade);
            printf("\t\nValor total em estoque: R$ %.2f\n", calcularTotal(&meuProduto));
            break;
        case 4:
            printf("\t\nEncerrando o programa...\n");
            break;
        default:
            printf("\t\n Opção Inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

/*|===========|FUNÇÕES AUXILIARES|===========|*/

float calcularTotal(struct Produto *produto)
{
    return produto->preco * produto->quantidade;
}

void realizarCompra(struct Produto *produto)
{
    int quantidadeCompra;
    printf("\n\tInforme a quantidade a ser comprada: \n");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > 0 && quantidadeCompra <= produto->quantidade)
    {
        produto->quantidade -= quantidadeCompra;
        printf("\n\tParabens a sua compra foi realizada com sucesso!\n");
    }
    else
    {
        printf("\n\tQuantidade Inválida. Verifique o estoque.\n");
    }
}
