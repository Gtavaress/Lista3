#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[10];
    char dia[20];

    fgets(placa, sizeof(placa), stdin);
    fgets(dia, sizeof(dia), stdin);

    placa[strcspn(placa, "\n")] = '\0';
    dia[strcspn(dia, "\n")] = '\0';

    for (int i = 0; dia[i]; i++) {
        dia[i] = tolower(dia[i]);
    }

    int placa_valida = 1;

    if (!((strlen(placa) == 8 && placa[3] == '-' && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7])) ||
          (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6])))) {
        placa_valida = 0;
    }

    int dia_valido = 0;
    if (strcmp(dia, "segunda-feira") == 0) {
        dia_valido = 1;
    } else if (strcmp(dia, "terca-feira") == 0) {
        dia_valido = 2;
    } else if (strcmp(dia, "quarta-feira") == 0) {
        dia_valido = 3;
    } else if (strcmp(dia, "quinta-feira") == 0) {
        dia_valido = 4;
    } else if (strcmp(dia, "sexta-feira") == 0) {
        dia_valido = 5;
    } else if (strcmp(dia, "sabado") == 0 || strcmp(dia, "domingo") == 0) {
        dia_valido = 6;
    }

    if (placa_valida && dia_valido) {
        char ultimo_digito = (strlen(placa) == 8) ? placa[7] : placa[6];
        switch (dia_valido) {
            case 1:
                if (ultimo_digito == '0' || ultimo_digito == '1') {
                    printf("%s nao pode circular segunda-feira\n", placa);
                } else {
                    printf("%s pode circular segunda-feira\n", placa);
                }
                break;
            case 2:
                if (ultimo_digito == '2' || ultimo_digito == '3') {
                    printf("%s nao pode circular terca-feira\n", placa);
                } else {
                    printf("%s pode circular terca-feira\n", placa);
                }
                break;
            case 3:
                if (ultimo_digito == '4' || ultimo_digito == '5') {
                    printf("%s nao pode circular quarta-feira\n", placa);
                } else {
                    printf("%s pode circular quarta-feira\n", placa);
                }
                break;
            case 4:
                if (ultimo_digito == '6' || ultimo_digito == '7') {
                    printf("%s nao pode circular quinta-feira\n", placa);
                } else {
                    printf("%s pode circular quinta-feira\n", placa);
                }
                break;
            case 5:
                if (ultimo_digito == '8' || ultimo_digito == '9') {
                    printf("%s nao pode circular sexta-feira\n", placa);
                } else {
                    printf("%s pode circular sexta-feira\n", placa);
                }
                break;
            case 6:
                printf("Nao ha proibicao no fim de semana\n");
                break;
            default:
                printf("Dia da semana invalido\n");
                break;
        }
    } else if (!placa_valida) {
        printf("Placa invalida\n");
    } else {
        printf("Dia da semana invalido\n");
    }
return 0;
}
