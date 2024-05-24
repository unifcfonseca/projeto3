#include <stdio.h>
#include "agenda.h"

int main(){
    agenda contatos_pessoais[TOTAL];
    agenda contatos_trabalho[TOTAL];
    funcao fs[] = {criar, deletar, listar, editar, salvar, carregar};
   
    int pos_pessoais = 0;
    int pos_trabalho = 0;
    int opcao_array;
    int opcao;  

    ERROS erro;
    
    erro = fs[5](contatos_trabalho, contatos_pessoais, &pos_trabalho, &pos_pessoais);
    
    if(erro != OK){
        printf("Erro ao executar a operação.\n");
        printErro(erro);
        pos_pessoais = 0;
        pos_trabalho = 0;
    }

    do {
        printf("\nMenu principal\n");
        printf("1 - Criar contato\n");
        printf("2 - Deletar contato \n");
        printf("3 - Listar contatos\n");
        printf("4 - Editar contato\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);
        opcao--;

        if(opcao > 3 || opcao < -1){
            printf("Opção invalida!\n");
        } else if(opcao >= 0){
            printf("Escolha uma opcao:\n");
            printf("1 - Contatos Pessoais\n");
            printf("2 - Contatos de Trabalho\n");
            scanf("%d", &opcao_array);
            while(opcao_array != 1 && opcao_array != 2){
                printf("Opção invalida!\n");
                scanf("%d", &opcao_array);
            }
            if(opcao_array==1){
                erro = fs[opcao](contatos_trabalho,&pos_trabalho);
            }else{
                erro = fs[opcao](contatos_pessoais,&pos_pessoais);
            }
            if(erro !=OK){
                printf("Erro ao executar a operação.\n");
                printErro(erro);
              }
            } else {
            printf("Sair...\n");
        }
    } while(opcao != -1);
    
    erro = fs[4](contatos_trabalho, contatos_pessoais, &pos_trabalho, &pos_pessoais);
      if(erro !=OK){
        printf("Erro ao executar a operação.\n");
        printErro(erro);
      }
    
    return 0;
}