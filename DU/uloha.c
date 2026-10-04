#include <stdio.h>

typedef struct {
    char nazov[50];
    int kusy;
    float cena;
} Produkt;

int main() {
    int pocet;

    printf("Zadaj pocet produktov (1-10): ");

    if (scanf("%d", &pocet) != 1 || pocet < 1 || pocet > 10) {
        printf("Neplatny vstup. Pocet musi byt od 1 do 10.\n");
        return 1;
    }

    Produkt zoznam[10];
    float celkom = 0;

    for (int i = 0; i < pocet; i++) {
        printf("\n--- PRODUKT %d ---\n", i + 1);

        printf("Nazov: ");
        scanf("%49s", zoznam[i].nazov);

        printf("Cena za kus: ");
        scanf("%f", &zoznam[i].cena);

        printf("Pocet kusov: ");
        scanf("%d", &zoznam[i].kusy);
    }

    printf("\n--- PREHLAD NAKUPU ---\n");

    for (int i = 0; i < pocet; i++) {
        float suma = zoznam[i].cena * zoznam[i].kusy;
        celkom = celkom + suma;

        printf("%d. %s | Kus: %.2f EUR | Ks: %d | Spolu: %.2f EUR\n",
               i + 1,
               zoznam[i].nazov,
               zoznam[i].cena,
               zoznam[i].kusy,
               suma);
    }

    printf("--------------------------------------\n");
    printf("CELKOVA CENA: %.2f EUR\n", celkom);

    if (celkom > 50) {
        float po_zlave = celkom * 0.90;

        printf("\nNakup je nad 50 EUR, mas zlavu 10%%.\n");
        printf("Cena po zlave: %.2f EUR\n", po_zlave);
    }

    return 0;
}