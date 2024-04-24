#include <stdio.h>
#include "agenda.h"

int main(){
  agenda contatos[TOTAL];
  funcao fs[] = {criar, deletar, listar, salvar, carregar};
  int pos;
  ERROS erro = fs[4](contatos, &pos);
  
  if(erro != OK)
      printf("Erro ao executar a operação.\n");
      printErro(erro);
      pos = 0;
  
  int opcao;
  do{
    printf("\nMenu principal\n");
    printf("1 - Criar contato\n");
    printf("2 - Deletar contato \n");
    printf("3 - Listar contatos\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: \n");
    scanf("%d", &opcao);
    opcao--;
    if(opcao >2 || opcao<-1){
        printf("Opção invalida!\n");
    }
    else if(opcao >= 0){
        erro = fs[opcao](contatos,&pos);
        if(erro !=OK){
        printf("Erro ao executar a operação.\n");
        printErro(erro);
      }
    }else{
        printf("Sair...\n");
    }
  }while(opcao!=-1);
  erro = fs[3](contatos, &pos);
  if(erro !=OK){
    printf("Erro ao executar a operação.\n");
    printErro(erro);
  }
  return OK;
}
