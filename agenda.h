#define NOME_MAX 20
#define SOBRENOME_MAX 50
#define EMAIL_MAX 30
#define TOTAL 255

typedef struct agenda{
int telefone;
char nome[NOME_MAX];
char sobrenome[SOBRENOME_MAX];
char email[EMAIL_MAX];
}agenda;


typedef enum {OK, MAX_AGENDA, SEM_CONTATOS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER,CRIAR} ERROS;

typedef ERROS (*funcao)();

ERROS criar(agenda contatos[], int *pos);
ERROS deletar(agenda contatos[], int *pos);
ERROS listar(agenda contatos[], int *pos);
ERROS salvar(agenda contatos[], int *pos);
ERROS carregar(agenda contatos[], int *pos);

void clearBuffer();