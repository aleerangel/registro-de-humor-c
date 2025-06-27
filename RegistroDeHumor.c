#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RegistroDeHumor.h"
#include "ListaDuplamenteEnc.h"

char humores[][20] = {
    "FELIZ",
    "TRISTE",
    "ANSIOSO",
    "CANSADO",
    "MOTIVADO",
    "ESTRESSADO",
    "NEUTRO"
};

//cria dinamicamente um novo registro e le as entradas do usuario
RegistroDeHumor* criarRegistro() {
    static int proximoId = 1; //id que incrementa automaticamente para cada novo registro
    
    RegistroDeHumor* registro = malloc(sizeof(RegistroDeHumor));
    if (registro==NULL) {
        printf ("Nao foi possivel alocar memoria para o registro\n");
        return NULL;
    } 

    registro->id = proximoId++; //atribui e incrementa o ID
    leituraRegistro(registro); //le os dados do usuario

    return registro;
}

//le os dados de um registro a ser criado
void leituraRegistro(RegistroDeHumor* registro) {
    printf("ID do registro: %d\n", registro->id);
    printf("Digite a data (Dia Mes Ano): ");
    scanf("%d %d %d", &registro->data.dia, &registro->data.mes, &registro->data.ano);
    char entrada[20];
    printf("Humor do dia (FELIZ, TRISTE, ANSIOSO,...): ");
    scanf("%s", entrada);
    //converte a string para enum
    int encontrou = 0;
    for(int i=0; i<7; i++) {
        if(strcmp(entrada, humores[i]) == 0) {
            registro->humor = (Humor)i;
            encontrou = 1;
            break;
        }
    }
    if(!encontrou) {
        printf("Entrada invalida\n");
        return;
    }
    getchar();
    printf("Motivo do humor: ");
    scanf("%[^\n]", registro->motivo);
    printf("Nota do dia (0-10): ");
    scanf("%d", &registro->notaDoDia);
}

//imprime as informacoes de um registro na tela
void imprimirRegistro(RegistroDeHumor* registro) {
    printf("ID: %d\n", registro->id);
    printf("Data: %d/%d/%d\n", registro->data.dia, registro->data.mes, registro->data.ano);
    printf("Humor: %s\n", humores[registro->humor]);
    printf("Motivo: %s\n", registro->motivo);
    printf("Nota do dia: %d\n", registro->notaDoDia);
}

//libera a memoria alocada para um registro
void liberarRegistro(RegistroDeHumor* registro) {
    free(registro);
}

//converte uma string para o enum correspondente ao humor
int stringParaHumor(const char* entrada) {
    for (int i = 0; i < 7; i++) {
        if (strcmp(entrada, humores[i]) == 0) {
            return i;
        }
    }
    return -1; // não encontrado
}
