#ifndef LISTADUPLAMENTEENC_H
#define LISTADUPLAMENTEENC_H

#include "RegistroDeHumor.h"

typedef struct NoLista{
    struct NoLista *ant, *prox;
    RegistroDeHumor info;
} NoLista;

NoLista* criarListaVazia();
int listaVazia(NoLista** l);
NoLista* ultimoElemento(NoLista** l);
void insereNoFim(NoLista** l, RegistroDeHumor v);
NoLista* buscaPorId(NoLista** l, int id);
void buscaPorHumor(NoLista** l, Humor humor);
void removePorId(NoLista** l, int id);
void imprimirTodosRegistros(NoLista** l);
void mediaNotaDoDia(NoLista** l, int dias);
void motivosDoHumor(NoLista** l, Humor humor);
void humorMaisFrequente(NoLista** l, int dias);
void liberaLista(NoLista** l);

#endif