#include <stdio.h>
#include <stdlib.h>
#include "draw_otazky.h"
#include "draw.h"
#include "main.h"
//74 znakov
//127 znakov








int otazky(){
    FILE *fp = fopen("./otazky.txt", "r");
    if(fp == NULL){
        perror("Unable to open file!");
        exit(1);
    }
    char chunk[200];
    char data[50][200];
    int count_line = 0;
    while(fgets(chunk, sizeof(chunk), fp) != NULL) {
        strcpy(data[count_line],chunk);
        count_line ++;
    }

    fclose(fp);
    
    for(int i =0; i<50; i+=5){
        strcpy(otazka[i].title,data[i]);
        strcpy(otazka[i].ans0,data[i+1]);
        strcpy(otazka[i].ans1,data[i+2]);
        strcpy(otazka[i].ans2,data[i+3]);
        otazka[i].correct = atoi(data[i+4]);
    }
}


void draw_otazky(){
    static unsigned long frame = 0;
    static unsigned frames=0;
    static double fps=0;
    static unsigned long long lastDraw_us=0, now_us=0;

    static char borderColor = 'c';
    static char green = 'g';
    static char red = 'r';
    static char blue = 'b';
    static char text = 't';
    static char underline = 'u';
    static char invertBG = 'i';
    static char invertFG = 'f';
    static char reset = 'n';
    static const int WindowSizeX = 80;
    static const int WindowSizeY = 18;

    int X = ((getConsoleWidth() - WindowSizeX) / 2);
    int Y = ((getConsoleHeight() - WindowSizeY) / 2) + 1;

    const int xOffset = ((getConsoleWidth() - WindowSizeX) / 2) + 2;
    const int yOffset = ((getConsoleHeight() - WindowSizeY) / 2) + 1;

    ///FPS measureC
    long long old_now = now_us;
    usElapsed(&now_us);
    if (now_us > lastDraw_us+10)
    {
        fps = (double)frames*1000000 / (double)(now_us-lastDraw_us);
        frames = 0;
        lastDraw_us = now_us;
    }
    frames++;
    clearScreen();

    gotoXY(0, 0);
    printf("%3.1f FPS %5.2fms       ", fps, (now_us-old_now)/1000.0);

    //firstline
    gotoXY(X, Y - 2);
    pprint("#", &borderColor);
    for (short i=0; i < WindowSizeX + 2; i++)
        pprint("#", &borderColor);
    pprint("#", &borderColor);

    //doubled firstline
    gotoXY(X, Y - 1);
    pprint("##", &borderColor);
    for (short i=0; i < WindowSizeX; i++)
        pprint("#", &borderColor);
    pprint("##", &borderColor);

    ///BOARD
    for (short i=0; i < WindowSizeY; i++)
    {
        gotoXY(X, Y++);
        pprint("##", &borderColor);

        for (short j=0; j < WindowSizeX; j++)
        {
            //pprint(board[i/g->scaling][j/(g->scaling*2)]==' ' ? " " : "█" , &board[i/g->scaling][j/(g->scaling*2)]);
            //pprint("█", &green);
        }

        gotoXY(getConsoleWidth() - ((getConsoleWidth() - WindowSizeX) / 2), i + 1 + ((getConsoleHeight() - WindowSizeY)/2));
        pprint("##", &borderColor);//end of row
    }
    
    gotoXY(xOffset+1, yOffset+1);
    printf(otazka[question].title);
    Y++;
    gotoXY(X, Y++);
    printf(otazka[question].ans0);
    gotoXY(X, Y++);
    printf(otazka[question].ans1);
    gotoXY(X, Y++);
    printf(otazka[question].ans2);
    


    //endl
    gotoXY(X, Y);
    pprint("##", &borderColor);
    for (short i=0; i < WindowSizeX; i++)
        pprint("#", &borderColor);
    pprint("##\n", &borderColor);

    //doubled end
    gotoXY(X, Y + 1);
    pprint("#", &borderColor);
    for (short i=0; i < (WindowSizeX + 2); i++)
        pprint("#", &borderColor);
    pprint("#\n", &borderColor);

    printf("%i", editMode);

}