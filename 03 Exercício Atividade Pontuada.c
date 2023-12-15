
/*Exerc√≠cio 3: 
Desenvolva uma struct "Produto" que contenha informa√ß√µes como nome, pre√ßo e quantidade em estoque.
Em seguida, desenvolva um menu para facilitar a escolha das op√ß√µes:
1 - Realizar uma compra
2 - Consultar estoque
3 - Sair do programa.

Escreva fun√ß√µes necess√°rias para calcular o valor total em estoque do produto e para atualizar a quantidade em estoque com base em uma compra.
Crie um programa que utiliza essas fun√ß√µes para um produto.
*/

/* Invocando bibliotecas */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*Estrutura do produto*/

struct Produto {
    char nome[300];
    float preco;
    int quantidade;
};

/*|===========|PROT”TIPOS DAS FUN«’ES AUXILIARES|===========|*/

float calcularTotal(struct Produto *produto);
void realizarCompra(struct Produto *produto); 

/*|===========|FUN«’ES PRINCIPAL|===========|*/
int main() {
    

setlocale(LC_ALL, "portugues");

    struct Produto meuProduto = {"Produto A", 10.0, 50};
    int opcao;
    
    do {
   
        printf("\t\n|=====|MENU|======|:\n");
        printf("\n");
        printf("\n");
        printf("\t\nEscolha uma opÁ„o: \n");
        printf("\n");
        printf("\t\n1. Realizar uma compra\n");
        printf("\n");
        printf("\t\n2. Consultar estoque\n");
        printf("\n");
        printf("\t\n3. Sair do programa\n");
        printf("\n");
        scanf("%d", &opcao);

system("cls || clear");
        
        switch (opcao) {
            case 1:
                realizarCompra(&meuProduto);
                break;
            case 2:
                printf("\t\nEstoque disponÌvel: %d unidades\n", meuProduto.quantidade);
                printf("\t\nValor total em estoque: R$ %.2f\n", calcularTotal(&meuProduto));
                break;
            case 3:
                printf("\t\nEncerrando o programa...\n");
                break;
            default:
                printf("\t\n OpÁ„o Inv·lida. Tente novamente.\n");
   
        }
    } while (opcao != 3);

    return 0;}



/*|===========|FUN«’ES AUXILIARES|===========|*/

float calcularTotal(struct Produto *produto) {
    return produto->preco * produto->quantidade;
}

void realizarCompra(struct Produto *produto) {
    int quantidadeCompra;
    printf("\n\tInforme a quantidade a ser comprada: \n");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > 0 && quantidadeCompra <= produto->quantidade) {
        produto->quantidade -= quantidadeCompra;
        printf("\n\tParabens a sua compra foi realizada com sucesso!\n");
    } else {
        printf("\n\tQuantidade Inv·lida. Verifique o estoque.\n");
    }
}

