#include <stdio.h>
#include "agenda.h"

int main(){
  agenda contatos[TOTAL];
  funcao fs[] = {criar, deletar, listar, salvar, carregar};
  int pos;

  
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
        fs[opcao](contatos,&pos);
    }else{
        printf("Sair...\n");
    }
  }while(opcao!=-1);
  
}
