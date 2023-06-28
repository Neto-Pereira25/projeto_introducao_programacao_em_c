#include <stdio.h>
#include <stdlib.h>

void menu(){
    puts("********** CRUD **********");
    puts("1 - CADASTRAR");
    puts("2 - CONSULTAR");
    puts("3 - ATUALIZAR");
    puts("4 - DELETAR");
    puts("5 - SAIR");
    puts("Digite um numero inteiro: ");
}

int main(){

    int opcao;

    while (opcao != 5){
        do{
            menu();
            scanf("%d", &opcao);
            if((opcao < 1) || (opcao > 5)){
                printf("\nOpcao Invalida! Digite um valor de 1 a 5\n\n");
            }
        }while((opcao < 1) || (opcao > 5));
        printf("\n");

        if(opcao == 1){ // Cadastrar

        } else if(opcao == 2){ // Ler

        } else if(opcao == 3){ // Atualizar

        } else if(opcao == 4){ // Deletar

        }
    }
    

    return 0;
}