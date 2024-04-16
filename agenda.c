#include "agenda.h"
#include <stdio.h>
#include <string.h>

ERROS criar(agenda contatos[], int *pos){
  printf("Criar contato\n");
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
  printf("Deletar contato\n");

  return OK;
}
ERROS listar(agenda contatos[], int *pos){
  printf("Listar contatos\n");

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
  printf("Salvar contatos\n");

  return OK;
}
ERROS carregar(agenda contatos[], int *pos){
  printf("Carregar contatos\n");

  return OK;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}