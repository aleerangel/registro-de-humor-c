#ifndef REGISTRODEHUMOR_H
#define REGISTRODEHUMOR_H

typedef struct{
    int dia, mes, ano;
} Data;

typedef enum {
    FELIZ,
    TRISTE,
    ANSIOSO,
    CANSADO,
    MOTIVADO,
    ESTRESSADO,
    NEUTRO
} Humor;

extern char humores[][20];

typedef struct RegistroDeHumor{
    int id;
    Data data;
    Humor humor;
    char motivo[101];
    int notaDoDia;
} RegistroDeHumor;

RegistroDeHumor* criarRegistro();
void leituraRegistro(RegistroDeHumor* registro);
void imprimirRegistro(RegistroDeHumor* registro);
void liberarRegistro(RegistroDeHumor* registro);
int stringParaHumor(const char* entrada);

#endif