#include <stdio.h>
#include <string.h>

#define MAX_HAK 5  
#define KELIME "elma" 

void karsilastir(char tahmin[]) {
    int uzunluk = strlen(KELIME);
    char sonuc[uzunluk + 1];

    
    for (int i = 0; i < uzunluk; i++) {
        sonuc[i] = '_';
    }
    sonuc[uzunluk] = '\0'; 

    // Doğru harfleri yerinde kontrol et
    for (int i = 0; i < uzunluk; i++) {
        if (tahmin[i] == KELIME[i]) {
            sonuc[i] = '✓'; 
        }
    }

    
    for (int i = 0; i < uzunluk; i++) {
        if (sonuc[i] != '✓') { 
            for (int j = 0; j < uzunluk; j++) {
                if (tahmin[i] == KELIME[j] && sonuc[j] != '✓') {
                    sonuc[i] = '*'; 
                    break;
                }
            }
        }
    }

    printf("Sonuc: %s\n", sonuc);
}

int main() {
    char tahmin[20]; 
    int hak = MAX_HAK;

    printf("== Kelime Tahmin Oyunu ==\n");
    printf("%d harfli bir kelimeyi tahmin etmelisin!\n", (int)strlen(KELIME));

    while (hak > 0) {
        printf("\nTahminini gir: ");
        scanf("%s", tahmin);

        if (strcmp(tahmin, KELIME) == 0) {
            printf("Tebrikler! Kelimeyi doğru tahmin ettin!\n");
            return 0;
        }

        karsilastir(tahmin);
        hak--;
        printf("Kalan hakkin: %d\n", hak);
    }

    printf("\nUzgunum, hakkin bitti! Doğru kelime: %s\n", KELIME);
    return 0;
}
