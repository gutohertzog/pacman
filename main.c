#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "mapa.h"

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

MAPA mapa;
POSICAO come_come;

int acabou(){
  return 0;
}

int eh_direcao(char dir){
  return dir == CIMA || dir == BAIXO || dir == DIREITA || dir == ESQUERDA;
}

void move(char direcao) {
  if(!eh_direcao(direcao))
    return;

  int proximo_x = come_come.x;
  int proximo_y = come_come.y;

  switch (direcao) {
    case ESQUERDA:
      proximo_y--;
      break;
    case CIMA:
      proximo_x--;
      break;
    case BAIXO:
      proximo_x++;
      break;
    case DIREITA:
      proximo_y++;
      break;
  }

  if (!eh_valido(&mapa, proximo_x, proximo_y))
    return;

  if (!eh_vazio(&mapa, proximo_x, proximo_y))
    return;

  anda_no_mapa(&mapa, come_come.x, come_come.y, proximo_x, proximo_y);
  come_come.x = proximo_x;
  come_come.y = proximo_y;
}

int main(){
  le_mapa(&mapa);
  busca_mapa(&mapa, &come_come, COME_COME);

  do {
    imprime_mapa(&mapa);

    char comando;
    scanf(" %c", &comando);

    move(comando);
  }while(!acabou());

  libera_mapa(&mapa);
}

