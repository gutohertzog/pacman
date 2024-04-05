#define COME_COME '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapa {
  char **matriz;
  int linhas;
  int colunas;
};
typedef struct mapa MAPA;

struct posicao {
  int x;
  int y;
};
typedef struct posicao POSICAO;

void aloca_mapa(MAPA *m);
void le_mapa(MAPA *m);
void libera_mapa(MAPA *m);
void imprime_mapa(MAPA *m);
void busca_mapa(MAPA *m, POSICAO *p, char c);
void anda_no_mapa(MAPA *m, int x_origem, int y_origem, int x_destino, int y_destino);

int eh_valido(MAPA *m, int x, int y);
int eh_vazio(MAPA *m, int x, int y);

