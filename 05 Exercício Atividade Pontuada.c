
/*Exerc√≠cio 5: 

Crie uma struct "Funcionario" com membros para nome, cargo e sal√°rio. 
Escreva uma fun√ß√£o que recebe um array de Funcion·rios e um cargo como par√¢metro, e retorna a m√©dia salarial dos Funcion·rios com esse cargo. 
Em seguida, implemente um programa que utiliza essa fun√ß√£o para calcular e imprimir a m√©dia salarial dos programadores em uma empresa.*/

/* Invocando bibliotecas */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*DeclaraÁ„o da estrutura dos Funcion·rios*/

struct Funcionario {
    char nome[100];
    char cargo[100];
    float salario;
};


/*|===========|PROT”TIPOS DAS FUN«’ES AUXILIARES|===========|*/
float calcularMediaSalarial(struct Funcionario funcionarios[], int numFuncionarios, const char cargoAlvo[]);

/*|===========|FUN«√O PRINCIPAL|===========|*/

int main() {
    
    struct Funcionario equipe[] = {
        {"Augusto", "Programador", 3000.0},
        {"SÈrgio", "Analista", 3500.0},
        {"Leonel", "Programador", 2800.0},
        {"Hugo", "Gerente", 5000.0},
    };


    int numFuncionarios = sizeof(equipe) / sizeof(equipe[0]);

   
    const char cargoAlvo[] = "Programador";

   
    float mediaProgramadores = calcularMediaSalarial(equipe, numFuncionarios, cargoAlvo);
    
    if (mediaProgramadores > 0.0) {
        printf("\t\nMÈdia salarial dos programadores: R$ %.2f\n", mediaProgramadores);
    } else {
        printf("\t\nNenhum programador encontrado na equipe.\n");
    }

    return 0;
}

/*|===========|FUN«’ES AUXILIARES|===========|*/

float calcularMediaSalarial(struct Funcionario funcionarios[], int numFuncionarios, const char cargoAlvo[]) {
    int count = 0;
    float somaSalarios = 0.0;

    for (int i = 0; i < numFuncionarios; ++i) {
        if (strcmp(funcionarios[i].cargo, cargoAlvo) == 0) {
            somaSalarios += funcionarios[i].salario;
            count++;
        }
    }

    if (count > 0) {
        return somaSalarios / count;
    } else {
        return 0.0; 
    }
}

