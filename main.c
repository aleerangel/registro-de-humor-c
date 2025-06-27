#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDuplamenteEnc.h"
#include "RegistroDeHumor.h"

void imprimeMenu() {
    printf("\n----------------MENU------------------\n");
    printf("1 - Adicionar novo registro\n");
    printf("2 - Remover registro por id\n");
    printf("3 - Buscar por humor\n");
    printf("4 - Imprimir todos os registros\n");
    printf("5 - Mostrar media da notaDoDia\n");
    printf("6 - Mostrar humor mais frequente\n");
    printf("7 - Mostrar os motivos do humor\n");
    printf("8 - Sair\n");
    printf("Escolha uma opcao:\n");
    printf("-------------------------------------------\n");
}

int main() {
    //lista principal
    NoLista* lista = criarListaVazia();
    int opcao = 0;
 
    while (opcao!=8) {
        imprimeMenu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                //cria novo registro e insere no fim da lista
                printf("\nAdicionar novo registro:\n");
                RegistroDeHumor* novoRegistro = criarRegistro();
                if(novoRegistro != NULL) {
                    insereNoFim(&lista, *novoRegistro);
                    liberarRegistro(novoRegistro);
                }
                break;
            }    

            case 2: {
                //remove registro com base no ID digitado
                printf("\nRemover elemento por ID:\nID:");
                int id;
                scanf("%d", &id);
                removePorId(&lista, id);
                break;
            }

            case 3: {
                //converte a string para enum do Humor
                printf("\nBuscar por humor:\nDigite o humor (FELIZ, TRISTE, ANSIOSO,...): ");
                char entrada[20];
                scanf("%s", entrada);
                int humor = stringParaHumor(entrada);
                if (humor == -1) {
                    printf("Entrada invalida\n");
                    break;
                }
                //imprime registros para o humor correspondente
                buscaPorHumor(&lista, humor);
                break;
            }

            case 4: {
                //imprime todos os registros
                printf("\nTodos os registros:\n");
                imprimirTodosRegistros(&lista);
                break;
            }

            case 5: {
                //le quantidade de dias e calcula a media da nota
                printf("\nMedia da nota do dia:\nQuantidade de dias: ");
                int dias;
                scanf("%d", &dias);
                mediaNotaDoDia(&lista, dias);
                break;
            }

            case 6: {
                //calcula o humor mais frequente na quantidade de dias
                printf("Mostrar humor mais frequente:\nQuantidade de dias: ");
                int dias;
                scanf("%d", &dias);
                humorMaisFrequente(&lista, dias);
                break;
            }

            case 7: {
                //mostra todos os motivos registrados para determinado humor
                printf("Mostrar motivos do humor:\nDigite o humor (FELIZ, TRISTE, ANSIOSO,...): ");
                char entrada[20];
                getchar();
                scanf("%s", entrada);
                int humor = stringParaHumor(entrada);
                if (humor == -1) {
                    printf("Entrada invalida\n");
                    break;
                }
                motivosDoHumor(&lista, humor);
                break;
            }

            case 8: {
                printf("\nPrograma encerrado.\n");
                break;
            }

            default: {
                printf("Opcao invalida\n");
                break;
            }
        }
    }

    liberaLista(&lista);

    return 0;
}  