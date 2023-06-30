#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    char nome[100];
    int idade, cpf, estadoCivil, nacionalidade;
    float altura, peso, IMC;
    char endereco[50];
    char telefone[11]; //81 983 900 943
    char email [40];
    char profissao[100];
    char doenca[100];
}Pessoa;

void menu(){
    puts("\n************* CRUD *************");
    puts("\t1 - CADASTRAR");
    puts("\t2 - CONSULTAR");
    puts("\t3 - ATUALIZAR");
    puts("\t4 - DELETAR");
    puts("\t5 - SAIR\n");
    printf("\tDigite um numero inteiro: ");
}

void estadoCivil(){
    puts("1 - SOLTEIRO");
    puts("2 - CASADO");
    puts("3 - DIVORCIADO");
    puts("4 - VIUVO");
    puts("5 - SEPARADO JUDICIALMENTE");
    puts("6 - CASADO NO PAPEL");
    puts("7 - UNIAO ESTAVEL");
    printf("Opcao: ");
}

void nacionalidades() {
    puts("\t1 - Brasil");
    puts("\t2 - Argentina");
    puts("\t3 - Canada");
    puts("\t4 - Dinamarca");
    puts("\t5 - Espanha");
    puts("\t6 - Franca");
    puts("\t7 - Grecia");
    puts("\t8 - Holanda");
    puts("\t9 - Italia");
    puts("\t10 - Outro");
    printf("Opcao: ");
}

float calcIMC(float p, float a){
    float imc;

    imc = p/(a*a);

    return imc;
}

// int idade(int ano){}
// int validarCPF(int cpf){}
// void validarEmail(char email[]){}

void cadastrar(char nome[], int *id){
    FILE *file = fopen(nome, "a");
    Pessoa p;
    char info[500] = "Nome: %s\nIdade: %d\nCPF: %d\nAltura: %.2f\nPeso: %.2f\nIMC: %.2f\nTelefone: %s\nEstado Civil: %d\nEmail: %s\nProfissao: %s\nNacionalidade: %d\nHistorico de Doenca/Alergia: %s\nEndereco: %s";
    
    if(file){
        // Pedindo dados para o usuário
        printf("\nDigite o seu nome: ");
        scanf("%100[^\n]", p.nome);
        
        do{
            printf("\nDigite a sua idade: ");
            scanf("%d", &p.idade);

            if(p.idade < 0 || p.idade > 150){
                puts("\nIdade invalida! Tente novamente.");
            }
        }while(p.idade < 0 || p.idade > 150);
        
        //Validacao com funçao
        printf("\nDigite o seu CPF: ");
        scanf("%d", &p.cpf);

        do{
            printf("\nDigite a sua altura em metros: ");
            scanf("%f", &p.altura);
            if(p.altura <= 0 || p.altura > 2.50){
                puts("\nAltura invalida! Tente novamente.");
            }
        }while(p.altura <= 0 || p.altura > 2.50);
        

        do{
            printf("Digite o seu peso em kg: ");
            scanf("%f", &p.peso);
            if(p.peso <= 0 || p.peso > 600){
                puts("\nAltura invalido! Tente novamente.");
            }
        }while(p.peso <= 0 || p.peso > 600);
        

        do{
            printf("\nDigite o seu telefone (APENAS NUMEROS) com DDD incluso: ");
            scanf("%s", p.telefone);
            if(strlen(p.telefone) != 11){
                puts("\nTelefone invalido! Tente novamente.");
            }
        }while(strlen(p.telefone) != 11);
        

        // Validacao com funçao
        printf("\nDigite o seu email: ");
        scanf("%s", p.email);

        do{
            printf("\nDigite o numero do seu estado civil:\n");
            estadoCivil();
            scanf("%d", &p.estadoCivil);
            if(p.estadoCivil < 1 || p.estadoCivil > 7){
                puts("\nOpcao invalida! Tente novamente.");
            }
        }while(p.estadoCivil < 1 || p.estadoCivil > 7);
        

        printf("\nDigite sua profissao: ");
        scanf("%s", p.profissao);

        do{
            printf("\nDigite o numero do seu pais de origem:\n");
            nacionalidades();
            scanf("%d", &p.nacionalidade);
            if(p.nacionalidade < 1 || p.nacionalidade > 10){
                puts("\nOpcao invalida! Tente novamente.");
            }
        }while(p.nacionalidade < 1 || p.nacionalidade > 10);
        

        scanf("%c");

        printf("\nDigite alguma alergia ou doenca que voce tenha. Caso nao possua doencas ou alergias digite \"NENHUMA\": ");
        scanf("%100[^\n]", p.doenca);

        scanf("%c");

        printf("\nDigite seu endereco: ");
        scanf("%100[^\n]", p.endereco);

        p.IMC = calcIMC(p.peso, p.altura);

        // Inserido dados lidos no arquivo
        fprintf(file, "Pessoa - %d\n", *id);
        fprintf(file, info, p.nome, p.idade, p.cpf, p.altura, p.peso, p.IMC, p.telefone, p.email, p.estadoCivil, p.profissao, p.nacionalidade, p.doenca, p.endereco);
        fprintf(file, "\n------------------------------\n");

        fclose(file);
    } else {
        printf("\nErro ao abrir arquivo\n");
    }
}

void consultar(char nome[]){
    FILE *file = fopen(nome, "r");
    char texto[500];

    if(file){
        printf("\nConsulta do arquivo: %s\n", nome);
        while (!feof(file)){
            if(fgets(texto, 500, file)){
                printf("\n\t%s", texto);
            }
        }
        fclose(file);
    } else {
        printf("\nErro ao abrir arquivo\n");
    }
}

// void atualizar(){}

// void deletar(){}

int main(){

    char arq[] = "pessoa.txt";
    int opcao, id, *pID = &id;
    *pID = 0;

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
            scanf("%c");
            id++;
            cadastrar(arq, pID);
        } else if(opcao == 2){ // Ler
            // scanf("%c");
            consultar(arq);
        } else if(opcao == 3){ // Atualizar

        } else if(opcao == 4){ // Deletar

        }
    }
    

    return 0;
}