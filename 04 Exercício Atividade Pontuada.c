
/*Exercício 4: 

Modele uma struct "conta" que represente uma conta bancária com número da conta, nome do titular, saldo e tipo de conta (poupan�a ou corrente).
Implemente fun��es para depositar e sacar dinheiro da conta, bem como para imprimir o saldo atual.
Crie um programa que utilize essas fun��es para simular opera��es banc�rias. Crie um menu para as opera��es dispon�veis.
*/

/* Invocando bibliotecas */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*Declara��o da estrutura da Conta*/

struct conta {
    int numeroConta;
    float saldo;
    char nomeTitular[100], tipoConta[10];
     
};

//*|===========|PROT�TIPOS DAS FUN��ES AUXILIARES|===========|*/
void depositar(struct conta *conta, float valor);
void sacar(struct conta *conta, float valor);
void imprimirSaldo(struct conta *conta);


/*|===========|FUN��ES PRINCIPAL|===========|*/
int main() {
    

    struct conta minhaConta = {12345, 500000.0, "Jo�o Ninguem", "corrente"};

    int opcao;
    float valor;

    do {
        
        printf("\t\n|=====|MENU|======|:\n");
        printf("\n");
        printf("\n");
        printf("\t\nSelecione uma op��o: \n");
        printf("\n");
        printf("\t\n2. Sacar\n");
        printf("\n");
        printf("\t\n3. Consultar saldo\n");
        printf("\n");
        printf("\t\n1. Depositar\n");
        printf("\n");
        printf("\t\n4. Sair\n");
        printf("\n");
        scanf("%d", &opcao);

        
        switch (opcao) {
            case 1:
                printf("\n\tValor para dep�sito: \n");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;
            case 2:
                printf("\t\nInforme o valor para saque: \n");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;
            case 3:
                imprimirSaldo(&minhaConta);
                break;
            case 4:
                printf("\t\nSaindo do programa...\n");
                break;
            default:
                printf("\t\nOp��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

/*|===========|FUN��ES AUXILIARES|===========|*/

void depositar(struct conta *conta, float valor) {
    conta->saldo += valor;
    printf("\n\tDep�sito de R$ %.2f realizado com sucesso.\n", valor);
}

void sacar(struct conta *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("\n\tSaque no valor deR$ %.2f.\n", valor);
        printf("\n\tRealizado com Sucesso!\n");
    } else {
        printf("\n\tSaldo insuficiente ou valor ditado inv�lido.\n");
        printf("\n\tPor favor tente novamente.\n");
    }
}

void imprimirSaldo(struct conta *conta) {
    printf("\n\tSaldo atual: R$ %.2f\n", conta->saldo);
}
