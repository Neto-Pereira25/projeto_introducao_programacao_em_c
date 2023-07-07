#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validarCPF.C"

typedef struct{
    char nome[100];
    int idade, estadoCivil, nacionalidade;
    char cpf[12];
    float altura, peso, IMC;
    char endereco[50];
    char telefone[12];
    char email [40];
    char profissao[100];
    char doenca[100];
}Pessoa;

void menu(){
    puts("\n\t************* CRUD *************");
    puts("\t1 - CADASTRAR PESSOA");
    puts("\t2 - ALTERAR DADOS DA PESSOA");
    puts("\t3 - DELETAR PESSOAS");
    puts("\t4 - IMPRIMIR LISTA DE PESSOAS");
    puts("\t5 - SALVAR DADOS CADASTRADOS");
    puts("\t6 - LER ARQUIVO");
    puts("\t7 - DELETAR ARQUIVO DE TEXTO");
    puts("\t8 - SALVAR ARQUIVO EM BINARIO");
    puts("\t9 - LER ARQUIVO EM BINARIO");
    puts("\t10 - ALTERAR ARQUIVO EM BINARIO");
    puts("\t11 - SAIR\n");
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
    return p/(a*a);
}

void imprimir_lista(Pessoa **p, int quant){
    int i;

    printf("\n\t\t\tLista de Pessoas:\n");
    printf("\t----------------------------------------------------\n");
    for(i = 0; i < quant; i++){
        printf("\t******************************************\n");
        printf("\tPessoa %d\n\tNome: %s\n\tIdade: %d\n\tCPF: %s\n\tAltura: %.2f\n\tPeso: %.2f\n\tIMC: %.2f\n\tTelefone: %s\n\tEstado Civil: %d\n\tEmail: %s\n\tProfissao: %s\n\tNacionalidade: %d\n\tHistorico de Doenca/Alergia: %s\n\tEndereco: %s\n",
        (i+1), p[i]->nome, p[i]->idade, p[i]->cpf, p[i]->altura, p[i]->peso, p[i]->IMC, p[i]->telefone, p[i]->estadoCivil, p[i]->email, p[i]->profissao, p[i]->nacionalidade, p[i]->doenca, p[i]->endereco);
        printf("\t******************************************\n");
    }
    printf("\t----------------------------------------------------\n");
}

int cadastrar_pessoa(Pessoa **p, int tam, int qtd){

    if(qtd < tam){
        Pessoa *novaPessoa = malloc(sizeof(Pessoa));

        // Pedindo dados para o usuário
        printf("\nDigite o seu nome: ");
        scanf("%99[^\n]", novaPessoa->nome);

        getchar();
        
        do{
            printf("\nDigite a sua idade: ");
            scanf("%d", &novaPessoa->idade);

            getchar();

            if((novaPessoa->idade) < 0 || (novaPessoa->idade) > 150){
                puts("\n\tIdade invalida! Tente novamente.");
            }
        }while((novaPessoa->idade) < 0 || (novaPessoa->idade) > 150);
        
        do{
            printf("\nDigite o seu CPF: ");
            scanf("%11[^\n]", &novaPessoa->cpf);

            getchar();

            if(!validarCPF(novaPessoa->cpf)){
                printf("\n\tCPF Invalido! Tente Novamente.");
            }
        } while(!validarCPF(novaPessoa->cpf));

        do{
            printf("\nDigite a sua altura em metros: ");
            scanf("%f", &novaPessoa->altura);
            
            getchar();

            if(novaPessoa->altura <= 0 || novaPessoa->altura > 2.50){
                puts("\n\tAltura invalida! Tente novamente.");
            }
        }while(novaPessoa->altura <= 0 || novaPessoa->altura > 2.50);
        
        do{
            printf("\nDigite o seu peso em kg: ");
            scanf("%f", &novaPessoa->peso);
            
            getchar();
            
            if(novaPessoa->peso <= 0 || novaPessoa->peso > 600){
                puts("\n\tPeso invalido! Tente novamente.");
            }
        }while(novaPessoa->peso <= 0 || novaPessoa->peso > 600);
        
        novaPessoa->IMC = calcIMC(novaPessoa->peso, novaPessoa->altura);

        do{
            printf("\nDigite o seu telefone (APENAS NUMEROS) com DDD incluso: ");
            scanf("%11[^\n]", novaPessoa->telefone);
            
            getchar();
            
            if(strlen(novaPessoa->telefone) != 11){
                puts("\n\tTelefone invalido! Tente novamente.");
            }
        }while(strlen(novaPessoa->telefone) != 11);

        do{
            printf("\nDigite o numero do seu estado civil:\n");
            estadoCivil();
            scanf("%d", &novaPessoa->estadoCivil);

            getchar();

            if(novaPessoa->estadoCivil < 1 || novaPessoa->estadoCivil > 7){
                puts("\n\tOpcao invalida! Tente novamente.");
            }
        }while(novaPessoa->estadoCivil < 1 || novaPessoa->estadoCivil > 7);

        // Validacao com funçao
        printf("\nDigite o seu email: ");
        scanf("%39[^\n]", novaPessoa->email);

        getchar();

        printf("\nDigite sua profissao: ");
        scanf("%99[^\n]", novaPessoa->profissao);
        
        getchar();

        do{
            printf("\nDigite o numero do seu pais de origem:\n");
            nacionalidades();
            scanf("%d", &novaPessoa->nacionalidade);
            
            getchar();
            
            if(novaPessoa->nacionalidade < 1 || novaPessoa->nacionalidade > 10){
                puts("\n\tOpcao invalida! Tente novamente.");
            }
        }while(novaPessoa->nacionalidade < 1 || novaPessoa->nacionalidade > 10);

        printf("\nDigite alguma alergia ou doenca que voce tenha. Caso nao possua doencas ou alergias digite \"NENHUMA\": ");
        scanf("%99[^\n]", novaPessoa->doenca);

        getchar();

        printf("\nDigite seu endereco: ");
        scanf("%49[^\n]", novaPessoa->endereco);

        getchar();

        p[qtd] = novaPessoa;

        return 1;
    } else {
        printf("\n\tImpossivel Novo Cadastro. Vetor Cheio!!!\n");
        return 0;
    }
}

void alterar_pessoa(Pessoa **p, int qtd){
    int id;

    imprimir_lista(p, qtd);

    printf("\n\tDigite o numero (identificador) da pessoa que deseja alterar:\n");
    scanf("%d", &id);
    getchar();
    id--;
    if(id >= 0 && id < qtd){
        Pessoa *novaPessoa = malloc(sizeof(Pessoa));
        // Pedindo dados para o usuário
        printf("\nDigite o seu nome: ");
        scanf("%99[^\n]", novaPessoa->nome);

        getchar();
        
        do{
            printf("\nDigite a sua idade: ");
            scanf("%d", &novaPessoa->idade);

            getchar();

            if((novaPessoa->idade) < 0 || (novaPessoa->idade) > 150){
                puts("\n\tIdade invalida! Tente novamente.");
            }
        }while((novaPessoa->idade) < 0 || (novaPessoa->idade) > 150);
        
        do{
            printf("\nDigite o seu CPF: ");
            scanf("%11[^\n]", &novaPessoa->cpf);
            if(!validarCPF(novaPessoa->cpf)){
                printf("\n\tCPF Invalido! Tente Novamente.");
            }
        } while(!validarCPF(novaPessoa->cpf));
        
        

        getchar();

        do{
            printf("\nDigite a sua altura em metros: ");
            scanf("%f", &novaPessoa->altura);
            
            getchar();

            if(novaPessoa->altura <= 0 || novaPessoa->altura > 2.50){
                puts("\n\tAltura invalida! Tente novamente.");
            }
        }while(novaPessoa->altura <= 0 || novaPessoa->altura > 2.50);
        
        do{
            printf("\nDigite o seu peso em kg: ");
            scanf("%f", &novaPessoa->peso);
            
            getchar();
            
            if(novaPessoa->peso <= 0 || novaPessoa->peso > 600){
                puts("\n\tPeso invalido! Tente novamente.");
            }
        }while(novaPessoa->peso <= 0 || novaPessoa->peso > 600);
        
        novaPessoa->IMC = calcIMC(novaPessoa->peso, novaPessoa->altura);

        do{
            printf("\nDigite o seu telefone (APENAS NUMEROS) com DDD incluso: ");
            scanf("%11[^\n]", novaPessoa->telefone);
            
            getchar();
            
            if(strlen(novaPessoa->telefone) != 11){
                puts("\n\tTelefone invalido! Tente novamente.");
            }
        }while(strlen(novaPessoa->telefone) != 11);

        do{
            printf("\nDigite o numero do seu estado civil:\n");
            estadoCivil();
            scanf("%d", &novaPessoa->estadoCivil);

            getchar();

            if(novaPessoa->estadoCivil < 1 || novaPessoa->estadoCivil > 7){
                puts("\n\tOpcao invalida! Tente novamente.");
            }
        }while(novaPessoa->estadoCivil < 1 || novaPessoa->estadoCivil > 7);

        // Validacao com funçao
        printf("\nDigite o seu email: ");
        scanf("%39[^\n]", novaPessoa->email);

        getchar();

        printf("\nDigite sua profissao: ");
        scanf("%99[^\n]", novaPessoa->profissao);
        
        getchar();

        do{
            printf("\nDigite o numero do seu pais de origem:\n");
            nacionalidades();
            scanf("%d", &novaPessoa->nacionalidade);
            
            getchar();
            
            if(novaPessoa->nacionalidade < 1 || novaPessoa->nacionalidade > 10){
                puts("\n\tOpcao invalida! Tente novamente.");
            }
        }while(novaPessoa->nacionalidade < 1 || novaPessoa->nacionalidade > 10);

        printf("\nDigite alguma alergia ou doenca que voce tenha. Caso nao possua doencas ou alergias digite \"NENHUMA\": ");
        scanf("%99[^\n]", novaPessoa->doenca);

        getchar();

        printf("\nDigite seu endereco: ");
        scanf("%49[^\n]", novaPessoa->endereco);

        getchar();
        p[id] = novaPessoa;
    } else {
        printf("\n\tNumero Invalido!\n");
    }
}

int deletarPessoa(Pessoa **p, int qtd){
    int opcao;
    
    if(qtd < 0){
        printf("\nVoce ainda nao possui pessoas cadastradas!\n");
        return 0;
    }

    imprimir_lista(p, qtd);

    printf("\n\tDigite o indice para deletar a pessoa: ");
    scanf("%d", &opcao);
    getchar();
    opcao--;

    if(opcao >= 0 && opcao < qtd){
        free(p[opcao]); // Liberando a memoria da posição excluída
        if(opcao < qtd - 1){
            p[opcao] = p[qtd - 1];
        } else {
            return -1;
        }
    } else {
        printf("\nOpcao Invalida!\n");
        return 0;
    }
    return -1;
}

void salvarPessoaARQ(Pessoa **p, int qtd, char arq[]){
    FILE *file = fopen(arq, "w");
    int i;

    if(file){
        fprintf(file, "%d\n", qtd);
        for(i = 0; i < qtd; i++){
            // fprintf(file, "%99[^\n]\n", p[i]->nome);
            // fprintf(file, "%d\n", p[i]->idade);
            // fprintf(file, "%11[^\n]\n", p[i]->cpf);
            // fprintf(file, "%.2f\n", p[i]->altura);
            // fprintf(file, "%.2f\n", p[i]->peso);
            // fprintf(file, "%.2f\n", p[i]->IMC);
            // fprintf(file, "%11[^\n]\n", p[i]->telefone);
            // fprintf(file, "%99[^\n]\n", p[i]->estadoCivil);
            // fprintf(file, "%99[^\n]\n", p[i]->email);
            // fprintf(file, "%99[^\n]\n", p[i]->profissao);
            // fprintf(file, "%99[^\n]\n", p[i]->nacionalidade);
            // fprintf(file, "%99[^\n]\n", p[i]->doenca);
            // fprintf(file, "%99[^\n]\n", p[i]->endereco);
            
            fputs(p[i]->nome, file);
            fputc('\n', file);
            fprintf(file, "%d", p[i]->idade);
            fputc('\n', file);
            fputs(p[i]->cpf, file);
            fputc('\n', file);
            fprintf(file, "%.2f", p[i]->altura);
            fputc('\n', file);
            fprintf(file, "%.2f", p[i]->peso);
            fputc('\n', file);
            fprintf(file, "%.2f", p[i]->IMC);
            fputc('\n', file);
            fputs(p[i]->telefone, file);
            fputc('\n', file);
            fprintf(file, "%d", p[i]->estadoCivil);
            fputc('\n', file);
            fputs(p[i]->email, file);
            fputc('\n', file);
            fputs(p[i]->profissao, file);
            fputc('\n', file);
            fprintf(file, "%d", p[i]->nacionalidade);
            fputc('\n', file);
            fputs(p[i]->doenca, file);
            fputc('\n', file);
            fputs(p[i]->endereco, file);
            fputc('\n', file);
        }
        fclose(file);
    }
}

int ler_arquivo(Pessoa **p, char arq[]){
    FILE *file = fopen(arq, "r");
    int quant = 0, i;
    Pessoa *novaPessoa = malloc(sizeof(Pessoa));
    //char f;

    if(file){

        // while ((f = fgetc(file)) != EOF){
        //     printf("%c", f);
        //     fprintf(file, "", );
        // }
        
        fscanf(file, "%d\n", &quant);
        for(i = 0; i < quant; i++){
            fscanf(file, "%99[^\n]", novaPessoa->nome);
            fscanf(file, "%d\n", &novaPessoa->idade);
            fscanf(file, "%11[^\n]", novaPessoa->cpf);
            fscanf(file, "%f", &novaPessoa->altura);
            fscanf(file, "%f", &novaPessoa->peso);
            fscanf(file, "%f\n", &novaPessoa->IMC);
            fscanf(file, "%11[^\n]", novaPessoa->telefone);
            fscanf(file, "%d\n", &novaPessoa->estadoCivil);
            fscanf(file, "%39[^\n]\n", novaPessoa->email);
            fscanf(file, "%99[^\n]", novaPessoa->profissao);
            fscanf(file, "%d\n", &novaPessoa->nacionalidade);
            fscanf(file, "%99[^\n]\n", novaPessoa->doenca);
            fscanf(file, "%49[^\n]\n", novaPessoa->endereco);
            p[i] = novaPessoa;
            novaPessoa = malloc(sizeof(Pessoa));
        }
        fclose(file);
    } else {
        printf("\n\tNao foi possivel abrir/criar o arquivo!\n");
    }
    return quant;
}

void deletar_arquivo(char arq[]){
    FILE *file = fopen(arq, "r");

    if(file){
        fclose(file);
        if(remove(arq) != 0){
            printf("\nArquivo nao existe ou nao encontrado!!\n\n");
        } else {
            remove(arq);
            printf("\nArquivo Deletado com Sucesso\n\n");
        }
        
    } else {
        printf("\n\tERROR!!Nao foi possivel abrir/criar o arquivo!\n");
    }
}

void salvarBinario(char arq[], Pessoa **p, int quant){
    FILE *file = fopen(arq, "wb");
    int i;

    if(file){
        for(i = 0; i < quant; i++){
            fwrite(p[i], sizeof(Pessoa), 1, file);
        }
        fclose(file);
    } else {
        printf("\n\tNao foi possivel abrir/criar o arquivo!\n");
    }
}

int lerArquivoBinario(char arq[], Pessoa **p){
    int qtd = 0;

    Pessoa *novo = malloc(sizeof(Pessoa));
    FILE *file = fopen(arq, "rb");

    if(file){
        while (fread(novo, sizeof(Pessoa), 1, file)){
            p[qtd] = novo;
            qtd++;
            novo = malloc(sizeof(Pessoa));
        }
        fclose(file);
    } else {
        printf("\n\tNao foi possivel abrir/criar o arquivo!\n");
    }

    return qtd;
}

void alterarArquivoBinario(char arq[]){
    FILE *file = fopen(arq, "rb+");
    Pessoa p;
    int id, i = 1;

    if(file){
        printf("\tLista de Pessoas:\n");
        printf("\t---------------------------------\n");
        while (fread(&p, sizeof(Pessoa), 1, file)){
            printf("\t******************************************\n");
            printf("\tPessoa %d\n\tNome: %s\n\tIdade: %02d\n\tCPF: %s\n\tAltura: %.2f\n\tPeso: %.2f\n\tIMC: %.2f\n\tTelefone: %s\n\tEstado Civil: %01d\n\tEmail: %s\n\tProfissao: %s\n\tNacionalidade: %01d\n\tHistorico de Doenca/Alergia: %s\n\tEndereco: %s\n",
            i, p.nome, p.idade, p.cpf, p.altura, p.peso, p.IMC, p.telefone, p.estadoCivil, p.email, p.profissao, p.nacionalidade, p.doenca, p.endereco);
            printf("\t******************************************\n");
            i++;
        }
        printf("\t---------------------------------\n");
        printf("\n\tDigite o indice da pessoa que deseja alterar: \n\n");
        scanf("%d", &id);
        getchar();
        id--;
        if((id >= 0) && (id < (i - 1))){
            printf("\nDigite o seu nome: ");
            scanf("%99[^\n]", p.nome);
            
            getchar();

            do{
                printf("\nDigite a sua idade: ");
                scanf("%d", &p.idade);
                
                getchar();

                if(p.idade < 0 || p.idade > 150){
                    puts("\nIdade invalida! Tente novamente.");
                }
            }while(p.idade < 0 || p.idade > 150);
            
            do{
                printf("\nDigite o seu CPF: ");
                scanf("%11[^\n]", &p.cpf);
                if(!validarCPF(p.cpf)){
                    printf("\n\tCPF Invalido! Tente Novamente.");
                }
            } while(!validarCPF(p.cpf));
            
            getchar();

            do{
                printf("\nDigite a sua altura em metros: ");
                scanf("%f", &p.altura);
                
                getchar();
                
                if(p.altura <= 0 || p.altura > 2.50){
                    puts("\nAltura invalida! Tente novamente.");
                }
            }while(p.altura <= 0 || p.altura > 2.50);
            
            do{
                printf("Digite o seu peso em kg: ");
                scanf("%f", &p.peso);
                
                getchar();
                
                if(p.peso <= 0 || p.peso > 600){
                    puts("\nAltura invalido! Tente novamente.");
                }
            }while(p.peso <= 0 || p.peso > 600);
            
            p.IMC = calcIMC(p.peso, p.altura);

            do{
                printf("\nDigite o seu telefone (APENAS NUMEROS) com DDD incluso: ");
                scanf("%11[^\n]", p.telefone);
                
                getchar();

                if(strlen(p.telefone) != 11){
                    puts("\nTelefone invalido! Tente novamente.");
                }
            }while(strlen(p.telefone) != 11);
            
            // Validacao com funçao
            printf("\nDigite o seu email: ");
            scanf("%39[^\n]", p.email);

            getchar();

            do{
                printf("\nDigite o numero do seu estado civil:\n");
                estadoCivil();
                scanf("%d", &p.estadoCivil);

                getchar();

                if(p.estadoCivil < 1 || p.estadoCivil > 7){
                    puts("\nOpcao invalida! Tente novamente.");
                }
            }while(p.estadoCivil < 1 || p.estadoCivil > 7);
            
            printf("\nDigite sua profissao: ");
            scanf("%99[^\n]", p.profissao);

            getchar();

            do{
                printf("\nDigite o numero do seu pais de origem:\n");
                nacionalidades();
                scanf("%d", &p.nacionalidade);

                getchar();

                if(p.nacionalidade < 1 || p.nacionalidade > 10){
                    puts("\nOpcao invalida! Tente novamente.");
                }
            }while(p.nacionalidade < 1 || p.nacionalidade > 10);

            printf("\nDigite alguma alergia ou doenca que voce tenha. Caso nao possua doencas ou alergias digite \"NENHUMA\": ");
            scanf("%99[^\n]", p.doenca);

            getchar();

            printf("\nDigite seu endereco: ");
            scanf("%49[^\n]", p.endereco);

            // getchar();

            fseek(file, id * sizeof(Pessoa), SEEK_SET);
            fwrite(&p, sizeof(Pessoa), 1, file);
        }

        fclose(file);
    } else {
        printf("\n\tNao foi possivel abrir/criar o arquivo para alteracao!\n");
    }
}

int main(){

    Pessoa *pessoa[50];
    char arq[] = {"pessoa.txt"};
    char arq1[] = {"pessoa.bin"};
    int opcao, qtd = 0, tam = 50;

    do{
        menu();
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao){
            case 1:
                qtd += cadastrar_pessoa(pessoa, tam, qtd);
                break;
            
            case 2:
                alterar_pessoa(pessoa, qtd);
                break;
            
            case 3:
                qtd += deletarPessoa(pessoa, qtd);
                break;
            
            case 4:
                imprimir_lista(pessoa, qtd);
                break;
            
            
            case 5:
                salvarPessoaARQ(pessoa, qtd, arq);
                break;
            
            case 6:
                qtd = ler_arquivo(pessoa, arq);
                // qtd = lerArquivoBinario(arq1, pessoa);
                break;
            
            case 7:
                deletar_arquivo(arq);
                break;
            
            case 8:
                salvarBinario(arq1, pessoa, qtd);
                break;
            
            case 9:
                qtd = lerArquivoBinario(arq1, pessoa);
                break;
            
            case 10:
                alterarArquivoBinario(arq1);
                break;
            
            default:
                if(opcao != 11){
                    printf("\nOpcao Invalida! Digite um valor de 1 a 11\n\n");
                }
                break;
        }
    }while(opcao != 11);

    return 0;
}