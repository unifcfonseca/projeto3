
  #include "agenda.h"
  #include <stdio.h>
  #include <string.h>
  #include <stdbool.h>

    ERROS criar(agenda contatos[], int *pos){
      printf("Criar contato\n");
      if (*pos >= TOTAL)
        return MAX_AGENDA;

      long telefone;
      bool telefoneExistente=false;
      do{
      printf("Entre com o numero de telefone: ");
      scanf("%ld", &telefone);

        telefoneExistente=false;

        for(int i=0;i<*pos;i++){
          if( contatos[i].telefone == telefone){
              telefoneExistente=true;
            printf("Telefone já em uso. Favor entre com outro número\n");
            break;
          }
        } 
      }while(telefoneExistente);

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

    while(validarEmail(contatos[*pos].email) == 0){
      printf("Email invalido!\n");
      printf("Entre com o email: ");
      fgets(contatos[*pos].email, EMAIL_MAX, stdin);
      contatos[*pos].email[strcspn(contatos[*pos].email, "\n")] = '\0';
    }

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
  ERROS editar(agenda contatos[], int *pos){
    if(*pos == 0){
      printf("Nenhum contato para editar\n");
      return SEM_CONTATOS;
    }

    long telefone_editar;
    int pos_EDITAR = -1;
    printf("Entre com o telefone do contato a ser editado: ");
    scanf("%ld", &telefone_editar);

    for(int i = 0; i < *pos; i++){
      if(contatos[i].telefone == telefone_editar){
          pos_EDITAR = i;
        break;
      }  
    }

    if(pos_EDITAR == -1){
      printf("Contato com telefone %ld não encontrado\n", telefone_editar);
      return NAO_ENCONTRADO;
    }
    int opcaoEditar;

    while(opcaoEditar!=0){

      printf("Telefone: %ld\t", contatos[pos_EDITAR].telefone);
      printf("Email: %s\n", contatos[pos_EDITAR].email); 
      printf("Nome: %s\t", contatos[pos_EDITAR].nome);
      printf("Sobrenome: %s\n\n", contatos[pos_EDITAR].sobrenome);

      printf("Escolha uma opção:\n");
      printf("1 - Editar nome\n");
      printf("2 - Editar sobrenome\n");
      printf("3 - Editar email\n");
      printf("0 - Sair\n");

      scanf("%d", &opcaoEditar);


      switch(opcaoEditar){
        case 1:
          clearBuffer();
          printf("Entre com o novo nome: ");
          fgets(contatos[pos_EDITAR].nome, NOME_MAX, stdin);
          contatos[pos_EDITAR].nome[strcspn(contatos[pos_EDITAR].nome, "\n")] = '\0';
          break;
        case 2:
          clearBuffer();
          printf("Entre com o novo sobrenome: ");
          fgets(contatos[pos_EDITAR].sobrenome, SOBRENOME_MAX, stdin);
          contatos[pos_EDITAR].sobrenome[strcspn(contatos[pos_EDITAR].sobrenome, "\n")] = '\0';
          break;
        case 3:
          clearBuffer();
          printf("Entre com o novo email: ");
          fgets(contatos[pos_EDITAR].email, EMAIL_MAX, stdin);
          contatos[pos_EDITAR].email[strcspn(contatos[pos_EDITAR].email, "\n")] = '\0';
          while(validarEmail(contatos[pos_EDITAR].email) == 0){
            printf("Email invalido!\n");
            printf("Entre com o email: ");
            fgets(contatos[pos_EDITAR].email, EMAIL_MAX, stdin);
            contatos[pos_EDITAR].email[strcspn(contatos[pos_EDITAR].email, "\n")] = '\0';
          }
          break;
        case 0:
          break;
        default:
          printf("Opção inválida!\n");
          break;
      }
    }
    printf("Contato Editado com sucesso\n");

    return OK;
  }
  ERROS salvar(agenda trabalho[],agenda pessoal[], int *posTrabalho, int *posPessoal){
    FILE *f = fopen("agenda.bin", "wb");
    if(f == NULL)
        return ABRIR;
    int qtd = fwrite(trabalho, TOTAL, sizeof(agenda), f);
    
    if(qtd == 0)
        return ESCREVER;

    qtd = fwrite(posTrabalho, 1, sizeof(int), f);
    
    if(qtd == 0)
        return ESCREVER;
    
    qtd = fwrite(pessoal, TOTAL, sizeof(agenda), f);
    
    if(qtd == 0)
        return ESCREVER;

    qtd = fwrite(posPessoal, 1, sizeof(int), f);
    if(qtd == 0)
        return ESCREVER;

    if(fclose(f))
        return FECHAR;

    return OK;
  }
  ERROS carregar(agenda trabalho[],agenda pessoal[], int *posTrabalho, int *posPessoal){

    FILE *f = fopen("agenda.bin", "rb");
    if(f == NULL)
        return ABRIR;

    int qtd = fread(trabalho, TOTAL, sizeof(agenda), f);
    if(qtd == 0)
        return LER;

    qtd = fread(posTrabalho, 1, sizeof(int), f);
    if(qtd == 0)
        return LER;

    qtd = fread(pessoal, TOTAL, sizeof(agenda), f);
    if(qtd == 0)
        return LER;

    qtd = fread(posPessoal, 1, sizeof(int), f);
    if(qtd == 0)
        return LER;
    
    if(fclose(f))
        return FECHAR;

    return OK;
  }

  void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
  }

  int validarEmail(char email[]){
    int tam = strlen(email);
    int arroba = 0;
    int posarroba;
    int ponto = 0;
    for(int i = 0; i < tam; i++){
      if(email[i] == '@'){
        arroba++;
        posarroba = i;
      }
      if(email[i] == '.'){
        ponto++;
      }
    }
    int pontos[ponto];
    int j = 0;
    for(int i = 0; i < tam; i++){
      if(email[i] == '.'){
        pontos[j] = i;
        j++;
      }
    }
    if(arroba != 1 || posarroba==0 || ponto == 0 || pontos[0] == 0 || pontos[ponto - 1] == tam - 1 || pontos[0] < posarroba){
      return 0;
    }
    return 1;
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