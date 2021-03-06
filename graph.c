//
// Created by marosm on 25. 2. 2022.
//

#include "graph.h"

void draw_graph()
{
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

    pprint("", &reset);

    float min = 1e10;
    float max = 0;
    unsigned long dataLen = stonksState->instruments[cursor.y]->len;
    uint32_t windowLen = WindowSizeX;
    if(windowLen > dataLen) windowLen = dataLen;
    if(dataLen < 3) return;

    for(int i = 0; i < windowLen; i++)
    {
        if(stonksState->instruments[cursor.y]->data[dataLen-i] > max)
        {
            max = stonksState->instruments[cursor.y]->data[dataLen-i];
        }
        if(stonksState->instruments[cursor.y]->data[dataLen-i] < min)
        {
            min = stonksState->instruments[cursor.y]->data[dataLen-i];
        }
    }

    /// Scale
    gotoXY(xOffset - 10, yOffset);
    printf("%4.1f CZK", max);

    gotoXY(xOffset - 10, yOffset + WindowSizeY / 2);
    printf("%4.1f CZK", (max+min)/2);

    gotoXY(xOffset - 10, yOffset + WindowSizeY);
    printf("%4.1f CZK", min);

    //OldRange = (OldMax - OldMin)
    int oldRange = max - min;
    //NewRange = (NewMax - NewMin)
    int newRange = WindowSizeY;
    //NewValue = (((OldValue - OldMin) * NewRange) / OldRange) + NewMin

    for(int i = 0; i < windowLen; i++)
    {
        static int lastY = 0;
        int oldY = stonksState->instruments[cursor.y]->data[dataLen - (windowLen - i)];
        int newY = (((oldY - min) * newRange) / oldRange) + 0;
        newY = WindowSizeY - newY; // invert, cuz Y=0 is up

        gotoXY(xOffset + i, newY + yOffset);
        if(lastY > newY)
        {
            pprint("", &green);
            printf("/");
        }
        else if(lastY == newY)
        {
            pprint("", &reset);
            printf("-");
        }
        else
        {
            pprint("", &red);
            printf("\\");
        }
        lastY = newY;
    }



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
