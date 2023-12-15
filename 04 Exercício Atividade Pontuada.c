
/*ExercÃ­cio 4: 

Modele uma struct "conta" que represente uma conta bancÃ¡ria com nÃºmero da conta, nome do titular, saldo e tipo de conta (poupança ou corrente).
Implemente funções para depositar e sacar dinheiro da conta, bem como para imprimir o saldo atual.
Crie um programa que utilize essas funções para simular operações bancárias. Crie um menu para as operações disponíveis.
*/

/* Invocando bibliotecas */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*Declaração da estrutura da Conta*/

struct conta {
    int numeroConta;
    float saldo;
    char nomeTitular[100], tipoConta[10];
     
};

//*|===========|PROTÓTIPOS DAS FUNÇÕES AUXILIARES|===========|*/
void depositar(struct conta *conta, float valor);
void sacar(struct conta *conta, float valor);
void imprimirSaldo(struct conta *conta);


/*|===========|FUNÇÕES PRINCIPAL|===========|*/
int main() {
    

    struct conta minhaConta = {12345, 500000.0, "João Ninguem", "corrente"};

    int opcao;
    float valor;

    do {
        
        printf("\t\n|=====|MENU|======|:\n");
        printf("\n");
        printf("\n");
        printf("\t\nSelecione uma opção: \n");
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
                printf("\n\tValor para depósito: \n");
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
                printf("\t\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

/*|===========|FUNÇÕES AUXILIARES|===========|*/

void depositar(struct conta *conta, float valor) {
    conta->saldo += valor;
    printf("\n\tDepósito de R$ %.2f realizado com sucesso.\n", valor);
}

void sacar(struct conta *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("\n\tSaque no valor deR$ %.2f.\n", valor);
        printf("\n\tRealizado com Sucesso!\n");
    } else {
        printf("\n\tSaldo insuficiente ou valor ditado inválido.\n");
        printf("\n\tPor favor tente novamente.\n");
    }
}

void imprimirSaldo(struct conta *conta) {
    printf("\n\tSaldo atual: R$ %.2f\n", conta->saldo);
}
