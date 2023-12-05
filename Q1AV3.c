#include <stdio.h>
#include <string.h>

int valorRomano(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanoParaDecimal(char* romano) {
    int decimal = 0;
    int i;
    
    for (i = 0; i < strlen(romano); i++) {
        int valor1 = valorRomano(romano[i]);
        if (i + 1 < strlen(romano)) {
            int valor2 = valorRomano(romano[i + 1]);
            if (valor1 >= valor2) {
                decimal += valor1;
            } else {
                decimal += valor2 - valor1;
                i++;
            }
        } else {
            decimal += valor1;
        }
    }
    
    return decimal;
}

void decimalParaBinario(int decimal) {
    if (decimal > 0) {
        decimalParaBinario(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main() {
    char romano[13];
    
    scanf("%s", romano);
    
    int decimal = romanoParaDecimal(romano);
    
    printf("na base 2: ");
    decimalParaBinario(decimal);
    printf("\n");
    
    printf("na base 10: %d\n", decimal);
    
    printf("na base 16: %X\n", decimal);
    
    return 0;
}