#define NOME_MAX 20
#define SOBRENOME_MAX 50
#define EMAIL_MAX 30
#define TOTAL 255

typedef struct agenda {
  long telefone;
  char nome[NOME_MAX];
  char sobrenome[SOBRENOME_MAX];
  char email[EMAIL_MAX];
} agenda;

typedef enum {
  OK,
  MAX_AGENDA,
  SEM_CONTATOS,
  NAO_ENCONTRADO,
  ABRIR,
  FECHAR,
  ESCREVER,
  LER
} ERROS;

typedef ERROS (*funcao)();

ERROS criar(agenda contatos[], int *pos);
ERROS deletar(agenda contatos[], int *pos);
ERROS listar(agenda contatos[], int *pos);
ERROS editar(agenda contatos[], int *pos);
ERROS salvar(agenda trabalho[],agenda pessoal[], int *posTrabalho, int *posPessoal);
ERROS carregar(agenda trabalho[],agenda pessoal[], int *posTrabalho, int *posPessoal);

void clearBuffer();

void printErro(ERROS e);

int validarEmail(char email[]);