#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Sabitler
#define PLANET_COUNT 8
#define PI 3.1415926535



double get_positive_input(char *prompt) {
    double value;
    int status;

    while (1) {
        printf("%s", prompt);
        status = scanf("%lf", &value);

        if (status == 1) {
            break;
        } else {
            printf("Hatali giris! Lutfen sayisal bir deger giriniz.\n");
            while(getchar() != '\n');
        }
    }

    return (value < 0) ? -value : value;
}

// 1. Serbest Dusme Deneyi
void exp_free_fall(double *g_ptr, char (*n_ptr)[20]) {
    double t;
    printf("\n--- Serbest Dusme Deneyi ---\n");
    t = get_positive_input("Dusus suresi (saniye) giriniz: ");

    printf("\n%-10s | %-10s\n", "Gezegen", "Yol (m)");
    printf("--------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        double h = 0.5 * g * pow(t, 2);
        printf("%-10s : %.2f m\n", *(n_ptr + i), h);
    }
}

// 2. Yukari Atis Deneyi
void exp_vertical_throw(double *g_ptr, char (*n_ptr)[20]) {
    double v0;
    printf("\n--- Yukari Atis Deneyi ---\n");
    v0 = get_positive_input("Firlatma hizi (m/s) giriniz: ");

    printf("\n%-10s | %-15s\n", "Gezegen", "Max Yukseklik");
    printf("-------------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        double h_max = pow(v0, 2) / (2 * g);
        printf("%-10s : %.2f m\n", *(n_ptr + i), h_max);
    }
}

// 3. Agirlik Deneyi
void exp_weight(double *g_ptr, char (*n_ptr)[20]) {
    double m;
    printf("\n--- Agirlik Deneyi ---\n");
    m = get_positive_input("Cismin kutlesi (kg) giriniz: ");

    printf("\n%-10s | %-10s\n", "Gezegen", "Agirlik (N)");
    printf("--------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        double G = m * g;
        printf("%-10s : %.2f N\n", *(n_ptr + i), G);
    }
}

// 4. Kutlecekimsel Potansiyel Enerji Deneyi
void exp_potential_energy(double *g_ptr, char (*n_ptr)[20]) {
    double m, h;
    printf("\n--- Potansiyel Enerji Deneyi ---\n");
    m = get_positive_input("Cismin kutlesi (kg) giriniz: ");
    h = get_positive_input("Yukseklik (m) giriniz: ");

    printf("\n%-10s | %-10s\n", "Gezegen", "Enerji (J)");
    printf("--------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        double Ep = m * g * h;
        printf("%-10s : %.2f J\n", *(n_ptr + i), Ep);
    }
}

// 5. Hidrostatik Basinc Deneyi
void exp_hydrostatic_pressure(double *g_ptr, char (*n_ptr)[20]) {
    double rho, h;
    printf("\n--- Hidrostatik Basinc Deneyi ---\n");
    rho = get_positive_input("Sivi yogunlugu (kg/m3) giriniz: ");
    h = get_positive_input("Derinlik (m) giriniz: ");

    printf("\n%-10s | %-10s\n", "Gezegen", "Basinc (Pa)");
    printf("--------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        double P = rho * g * h;
        printf("%-10s : %.2f Pa\n", *(n_ptr + i), P);
    }
}

// 6. Arsimet Kaldirma Kuvveti Deneyi
void exp_archimedes(double *g_ptr, char (*n_ptr)[20]) {
    double rho, V;
    printf("\n--- Arsimet Kaldirma Kuvveti Deneyi ---\n");
    rho = get_positive_input("Sivi yogunlugu (kg/m3) giriniz: ");
    V = get_positive_input("Batan hacim (m3) giriniz: ");

    printf("\n%-10s | %-10s\n", "Gezegen", "Kuvvet (N)");
    printf("--------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        double Fk = rho * g * V;
        printf("%-10s : %.2f N\n", *(n_ptr + i), Fk);
    }
}

// 7. Basit Sarkac Periyodu Deneyi
void exp_pendulum(double *g_ptr, char (*n_ptr)[20]) {
    double L;
    printf("\n--- Basit Sarkac Deneyi ---\n");
    L = get_positive_input("Sarkac uzunlugu (m) giriniz: ");

    printf("\n%-10s | %-10s\n", "Gezegen", "Periyot (s)");
    printf("--------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        double T = 2 * PI * sqrt(L / g);
        printf("%-10s : %.2f s\n", *(n_ptr + i), T);
    }
}

// 8. Sabit Ip Gerilmesi Deneyi
void exp_rope_tension(double *g_ptr, char (*n_ptr)[20]) {
    double m;
    printf("\n--- Sabit Ip Gerilmesi Deneyi ---\n");
    m = get_positive_input("Cismin kutlesi (kg) giriniz: ");

    printf("\n%-10s | %-10s\n", "Gezegen", "Gerilme (N)");
    printf("--------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        double T = m * g;
        printf("%-10s : %.2f N\n", *(n_ptr + i), T);
    }
}

// 9. Asansor Deneyi
void exp_elevator(double *g_ptr, char (*n_ptr)[20]) {
    double m, a;
    int direction;

    printf("\n--- Asansor Deneyi ---\n");
    m = get_positive_input("Cismin kutlesi (kg) giriniz: ");
    a = get_positive_input("Asansor ivmesi (m/s2) giriniz: ");

    while(1) {
        printf("Hareket yonunu seciniz:\n");
        printf("1. Yukari Hizlanan veya Asagi Yavaslayan (g + a)\n");
        printf("2. Asagi Hizlanan veya Yukari Yavaslayan (g - a)\n");
        printf("Secim: ");
        if(scanf("%d", &direction) == 1 && (direction == 1 || direction == 2)) {
            break;
        } else {
            printf("Hatali giris! Lutfen 1 veya 2 giriniz.\n\n");
            while(getchar() != '\n');
        }
    }

    printf("\n%-10s | %-10s\n", "Gezegen", "Etkin Agirlik");
    printf("--------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        double N;

        if (direction == 1) {
             N = m * (g + a);
        } else {
             N = m * (g - a);
             N = (N < 0) ? -N : N;
        }

        printf("%-10s : %.2f N\n", *(n_ptr + i), N);
    }
}

int main() {
    char scientist_name[50];
    int choice;

    char planets[PLANET_COUNT][20] = {
        "Merkur", "Venus", "Dunya", "Mars",
        "Jupiter", "Saturn", "Uranus", "Neptun"
    };

    double gravities[PLANET_COUNT] = {
        3.70, 8.87, 9.80, 3.71,
        24.79, 10.44, 8.69, 11.15
    };

    printf("Uzay Simulasyonuna Hosgeldiniz!\n");
    printf("Lutfen Bilim Insani Adini Giriniz: ");
    fgets(scientist_name, sizeof(scientist_name), stdin);
    scientist_name[strcspn(scientist_name, "\n")] = 0;

    printf("\nMerhaba, Bilim Insani %s. Simulasyon baslatiliyor...\n", scientist_name);

    // Ana Dongu
    do {
        printf("\n==========================================\n");
        printf("DENEY LISTESI:\n");
        printf("1. Serbest Dusme Deneyi\n");
        printf("2. Yukari Atis Deneyi\n");
        printf("3. Agirlik Deneyi\n");
        printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n");
        printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
        printf("7. Basit Sarkac Periyodu Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n");
        printf("9. Asansor Deneyi\n");
        printf("-1. CIKIS\n");
        printf("==========================================\n");


        while(1) {
            printf("Seciminiz: ");
            if (scanf("%d", &choice) == 1) {
                break;
            } else {
                printf("Hatali giris! Lutfen bir sayi giriniz.\n");
                while(getchar() != '\n');
            }
        }

        switch(choice) {
            case 1: exp_free_fall(gravities, planets); break;
            case 2: exp_vertical_throw(gravities, planets); break;
            case 3: exp_weight(gravities, planets); break;
            case 4: exp_potential_energy(gravities, planets); break;
            case 5: exp_hydrostatic_pressure(gravities, planets); break;
            case 6: exp_archimedes(gravities, planets); break;
            case 7: exp_pendulum(gravities, planets); break;
            case 8: exp_rope_tension(gravities, planets); break;
            case 9: exp_elevator(gravities, planets); break;
            case -1: printf("Simulasyondan cikiliyor... Iyi gunler %s!\n", scientist_name); break;
            default: printf("Gecersiz secim! Lutfen tekrar deneyiniz.\n");
        }

    } while (choice != -1);

    return 0;
}
