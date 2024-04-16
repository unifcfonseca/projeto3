



typedef enum {OK, MAX_AGENDA, SEM_CONTATOS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER,CRIAR} ERROS;

typedef ERROS (*funcao)();

ERROS criar();
ERROS deletar();
ERROS listar();
ERROS salvar();
ERROS carregar();