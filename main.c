#include <stdio.h>

int main(){
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
        //chamar função
    }else{
        printf("Sair...\n");
    }
  }while(opcao!=0);
  
}
