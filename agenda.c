#include "agenda.h"
#include <stdio.h>
#include <string.h>

ERROS criar(agenda contatos[], int *pos){

  if (*pos >= TOTAL)
    return MAX_AGENDA;

  long telefone;
  printf("Entre com o numero de telefone: ");
  scanf("%ld", &telefone);
  contatos[*pos].telefone = telefone;

  clearBuffer();
  
  printf("Entre com o primeiro nome: ");
  fgets(contatos[*pos].nome, NOME_MAX, stdin);
  contatos[*pos].nome[strcspn(contatos[*pos].nome, "\n")] = '\0';

  printf("Entre com o sobrenome: ");
  fgets(contatos[*pos].sobrenome, SOBRENOME_MAX, stdin);
  contatos[*pos].sobrenome[strcspn(contatos[*pos].sobrenome, "\n")] = '\0';

  printf("Entre com o email: ");
  fgets(contatos[*pos].email, EMAIL_MAX, stdin);
  contatos[*pos].email[strcspn(contatos[*pos].email, "\n")] = '\0';

  *pos = *pos + 1;

  return OK;
  
}

ERROS deletar(agenda contatos[], int *pos){
  if(*pos == 0){
    printf("Nenhum contato para deletar\n");
    return SEM_CONTATOS;
  }

  long telefone_deletar;
  int pos_DELETAR = -1;
  printf("Entre com o telefone do contato a ser excluído: ");
  scanf("%ld", &telefone_deletar);

  for(int i = 0; i < *pos; i++){
    if(contatos[i].telefone == telefone_deletar){
      pos_DELETAR = i;
      break;
    }  
  }

  if(pos_DELETAR == -1){
    printf("Contato com telefone %ld não encontrado\n", telefone_deletar);
    return NAO_ENCONTRADO;
  }

  for(int i = pos_DELETAR; i < *pos - 1; i++){
    strcpy(contatos[i].nome, contatos[i + 1].nome);
    strcpy(contatos[i].sobrenome, contatos[i + 1].sobrenome);
    strcpy(contatos[i].email, contatos[i + 1].email);
    contatos[i].telefone = contatos[i + 1].telefone;
  }

  *pos = *pos - 1;

  printf("Contato deletado com sucesso\n");

  return OK;
}
ERROS listar(agenda contatos[], int *pos){


  if (*pos == 0){
    return SEM_CONTATOS;
  }

  for (int i = 0; i < *pos; i++){
    printf("Posição: %d\n", i+1);
    printf("Nome: %s\t", contatos[i].nome);
    printf("Sobrenome: %s\n", contatos[i].sobrenome);
    printf("Telefone: %ld\t", contatos[i].telefone);
    printf("Email: %s\n\n", contatos[i].email); 
  }
  
  return OK;
}
ERROS salvar(agenda contatos[], int *pos){


  return OK;
}
ERROS carregar(agenda contatos[], int *pos){


  return OK;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void printErro(ERROS e){
  switch(e){
    case 0:
    printf("OK\n");
    break;
      case 1:
    printf("Maximo de contatos atingido!\n");
    break;
        case 2:
    printf("Sem contatos no arquivo!\n");
    break;
          case 3:
    printf("Contato não encontrado!\n");
    break;
            case 4:
    printf("Erro ao abrir o arquivo!\n");
    break;
              case 5:
    printf("Erro ao fechar o arquivo!\n");
    break;
                case 6:
    printf("Erro ao escrever no arquivo!\n");
    break;
                  case 7:
    printf("Erro ao ler o arquivo!\n");
    break;
    default:
    printf("Erro desconhecido!\n");
  }
}