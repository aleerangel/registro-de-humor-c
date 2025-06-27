#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDuplamenteEnc.h"
#include "RegistroDeHumor.h"

NoLista* criarListaVazia() {
    return NULL;
}

//verifica se a lista esta vazia
int listaVazia(NoLista**l) {
    return ((*l)==NULL);
}

//retorna um ponteiro para ultimo elemento da lista
NoLista* ultimoElemento(NoLista** l) {
    if(listaVazia(l)) {
        return NULL;
    } else {
    NoLista* p = *l;
    for(; p->prox!=NULL; p=p->prox);
    return p;
    }
}

void insereNoFim(NoLista** l, RegistroDeHumor v) {
    NoLista* novo = malloc(sizeof(NoLista));
    if(novo == NULL) {
        printf("Nao foi possivel alocar memoria\n");
        return;
    }

    novo->info = v;
    novo->prox = NULL;

    if(listaVazia(l)) {
        *l = novo;
        novo->ant = NULL;
    } else {
        NoLista* ultimo = ultimoElemento(l);
        ultimo->prox = novo;
        novo->ant = ultimo;
    }
}

//busca e retorna um ponteiro para um no da lista com base no ID
NoLista* buscaPorId(NoLista** l, int id) {
    NoLista* p = *l;
    for(; p!=NULL && p->info.id!=id; p=p->prox);
    return p;
}

//busca registros com o humor recebido e imprime a data e o ID
void buscaPorHumor(NoLista** l, Humor humor) {
    NoLista* p = *l;
    int encontrou = 0;

    for(; p!=NULL; p=p->prox) {
        if(p->info.humor == humor) {
            printf("Data: %d/%d/%d\n", p->info.data.dia, p->info.data.mes, p->info.data.ano);
            printf("ID: %d\n", p->info.id);
            encontrou = 1;
        }
    }

    if(!encontrou) {
        printf("Nao foi encontrado nenhum regisstro com esse humor\n");
    }
}

void removePorId(NoLista** l, int id) {
    NoLista* p = buscaPorId(l, id);
    if(p==NULL) {
        printf("Elemento nao encontrado\n");
        return;
    }

    if(p->ant == NULL) {
        //unico elemento
        if(p->prox == NULL) {
            *l = NULL;
        } else {
            //primeiro elemento
            p->prox->ant = NULL;
            *l = p->prox;
        }
    } else if(p->prox==NULL) {
        //ultimo elemento
        p->ant->prox = NULL;
    } else {
        //meio
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
    }

    free(p);
}

void imprimirTodosRegistros(NoLista** l) {
    NoLista* p = *l;
    printf("----------\n");
    for(; p!=NULL; p=p->prox) {
        imprimirRegistro(&(p->info));
        printf("----------\n");
    }
}

//imprime a media das notas dos ultimos dias
void mediaNotaDoDia(NoLista** l, int dias) {
    if(*l == NULL || dias<=0) {
        printf("Lista vazia ou numero de dias invalido.\n");
        return;
    }

    float soma = 0;
    int contador = 0;
    NoLista* p = ultimoElemento(l);

    for(int i=0; p!=NULL && i<dias; p=p->ant, i++) {
        soma += p->info.notaDoDia;
        contador++;
    }

    float media = soma/contador;
    printf("Media das notas dos ultimos %d dias: %.2f\n", contador, media);
}

//mostra os motivos do humor recebido
void motivosDoHumor(NoLista** l, Humor humor) {
    NoLista* p = *l;
    int achou = 0;

    printf("Motivos registrados para o humor %s:\n", humores[humor]);
    for(; p!=NULL; p=p->prox) {
        if(p->info.humor == humor) {
            printf("- %s\n", p->info.motivo);
            achou = 1;
        }
    }

    if(!achou) {
        printf("Esse humor nao foi registrado nenhum dia\n");
    }
}

//imprime o humor mais frequente nos ultimos dias 
void humorMaisFrequente(NoLista** l, int dias) {
    if(listaVazia(l)) {
        printf("Lista vazia ou numero de dias invalido\n");
        return;
    }  

    int frequenciaHumores[7] = {0};
    int maiorFrequencia = 0;
    int humorMaisFrequente = -1;

    NoLista* p = ultimoElemento(l);
    for(int i=1; p!=NULL && i<=dias; p=p->ant, i++) {
        int h = p->info.humor;
        frequenciaHumores[h]++;
        if(frequenciaHumores[h] > maiorFrequencia) {
            maiorFrequencia = frequenciaHumores[h];
            humorMaisFrequente = h;
        }
    }

    if(humorMaisFrequente != -1) {
        printf("Humor mais frequente nos ultimos %d dias: %s\n", dias, humores[humorMaisFrequente]);
    } else {
        printf("Nao ha dados suficientes para os ultimos %d dias.\n", dias);
    }  
}

void liberaLista(NoLista** l) {
    NoLista* p = *l;
    while(p != NULL) {
        NoLista* temp = p;
        p = p->prox;
        free(temp);
    }
    *l = NULL;
}

