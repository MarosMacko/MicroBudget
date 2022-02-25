//
// Created by marosm on 25. 2. 2022.
//

#include "draw.h"

///pprint stands for pretty print. Heh.
void pprint(const char *toPrint, const char *color)
{
    static char msg[10] = {0};
    static char lastColor = 'w'; //Call WINAPI only when needed

    static char cPrefix[8] = {0};

    if(lastColor != color[0])
    {
        lastColor = color[0];
        switch (color[0])
        {
            case 'n':
                strcpy(cPrefix, "\x1B[0m");
                break;

            case 'r':
            case 1 :
                strcpy(cPrefix, "\x1B[31m");
                break;

            case 'g':
            case 2 :
                strcpy(cPrefix, "\x1B[32m");
                break;

            case 'b':
            case 3 :
                strcpy(cPrefix, "\x1B[34m");
                break;

            case 'c':
            case 4 :
                strcpy(cPrefix, "\x1B[36m");
                break;

            case 'm':
            case 5 :
                strcpy(cPrefix, "\x1B[35m");
                break;

            case 'y':
            case 6 :
                strcpy(cPrefix, "\x1B[33m");
                break;

            case 'u':
            case 7 :
                strcpy(cPrefix, "\x1B[4m");
                break;
            case 't':
            case 8 :
                strcpy(cPrefix, "\x1B[97m");
                break;
            case 'i':
                strcpy(cPrefix, "\x1B[47m");
                break;
            default:
                break;
        }
    }
    strcpy(msg, cPrefix);
    strcat(msg, toPrint);
    //msg[0] = *toPrint;
    printf("%s", msg);

}

void draw_quest(){
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
    static char invert = 'i';
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

}

void draw()
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
    static char invert = 'i';
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

    for(int i = 0; i < 5; i ++)
    {
        gotoXY(xOffset, yOffset + (i*2) + 1);

        pprint(" ", &blue);
        printf("Stock %c \t", 'A' + i);
        printf("Have: 0 (0$) \t");
        printf("Value: 420$ \t");
        printf("⇈5%% \t");

        pprint(" ", &blue);

        if((cursor.x == 0) && (cursor.y == i))
        {
            pprint("", &underline);
            if(editMode)
            {
                pprint("", &invert);
            }
        }

        printf("BUY\t");
        pprint("", &reset);

        if((cursor.x == 1) && (cursor.y == i))
        {
            pprint("", &underline);
            if(editMode)
                pprint("", &invert);
        }

        printf("SELL\t");
        pprint("", &reset);

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

    if(editMode)
    {
        printf("\t");
        if(cursor.x == 0)
        {
            printf("BUY: %i", enteredValue);
        }
        else
        {
            printf("SELL: %i", enteredValue);
        }
    }


}
