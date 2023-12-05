#include <stdio.h>
#include <math.h>

int main() {
    int meses;
    double aporte, taxa, valor;
    double montante;

    scanf("%d %lf %lf", &meses, &aporte, &taxa);

    for (int i = 1; i <= meses; i++) {
        montante = aporte * (1.00 + taxa) * ((pow((1.00 + taxa),i) - 1.00) / taxa);
        valor += montante;
        printf("Montante ao fim do mes %d:R$ %.2lf \n", i, valor);
    }

    return 0;
}