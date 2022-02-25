#ifndef DRAW_OTAZKY
#define DRAW_OTAZKY



typedef struct Otazka {
    char title[74];
    char ans0[74];
    char ans1[74];
    char ans2[74];
    int correct;
} Otazka;
int otazky();

void draw_otazky();

#endif