#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void le_mapa(MAPA *m){
  FILE *arq;
  arq = fopen("mapa.txt", "r");

  if(arq == NULL){
    printf("Erro ao abrir o arquivo!");
    exit(1);
  }

  fscanf(arq, "%d %d", &(m->linhas), &(m->colunas));
  aloca_mapa(m);

  for(int i = 0; i < m->linhas; i++){
    fscanf(arq, "%s", m->matriz[i]);
  }

  fclose(arq);
}

void aloca_mapa(MAPA *m){
  m->matriz = malloc(sizeof(char*) * m->linhas);

  for(int i = 0; i < m->linhas; i++){
    m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
  }
}

void libera_mapa(MAPA *m){
  for(int i = 0; i < m->linhas; i++){
    free(m->matriz[i]);
  }

  free(m->matriz);
}

void imprime_mapa(MAPA *m){
  for(int i = 0; i < m->linhas; i++){
    printf("%s\n", m->matriz[i]);
  }
}

void busca_mapa(MAPA *m, POSICAO *p, char c){
  for(int i = 0; i < m->linhas; i++){
    for(int j = 0; j < m->colunas; j++){
      if(m->matriz[i][j] == c){
        p->x = i;
        p->y = j;
        return;
      }
    }
  }
}

int eh_valido(MAPA *m, int x, int y){
  if(x >= m->linhas)
    return 0;
  if(y >= m->colunas)
    return 0;

  return 1;
}

int eh_vazio(MAPA *m, int x, int y){
  return m->matriz[x][y] == '.';
}

void anda_no_mapa(MAPA *m, int x_origem, int y_origem, int x_destino, int y_destino){
  char personagem = m->matriz[x_origem][y_origem];
  m->matriz[x_destino][y_destino] = personagem;
  m->matriz[x_origem][y_origem] = '.';
}

