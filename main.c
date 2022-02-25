#include "main.h"

unsigned long long t_now=0, t_lastRender=0;

struct app app;
struct player player;
struct stocks stocks;
struct cursor cursor;

int editMode;
int enteredValue = 0;


int calculateNetWorth()
{
    int ret = player.freeCash;

    return 0;
}

int main()
{
    signal(SIGINT, exit_handler);
    app.consoleHeight = getConsoleHeight();
    app.consoleWidth  = getConsoleWidth();
    app.targetFPS = 15;
    app.state = 1;

    player.freeCash = 1000;
    player.netWorth = 0;

    cursor.x = 0;
    cursor.y = 0;

    editMode = 0;

    //random init
    pcg32_srandom((uint64_t) time(0), (uint64_t) time(0)/2);

    //APP INIT
    initTermios(0);

    /// STONKS INIT



    //GAME LOOP
    while(app.state==1)
    {
        if(kbhit())
        {
            char key = parseKey();
            if(editMode)
            {
                if(key == 'n')
                {
                    if(cursor.x == 0)
                    {
                        /// TODO: BUY(enteredValue)
                    }
                    if(cursor.x == 1)
                    {
                        /// TODO: SELL(enteredValue)
                    }
                }
                enteredValue = (enteredValue * 10) + key;
            }
            else
            {
                switch (key)
                {
                    case 'w':
                        cursor.y = (cursor.y - 1) % 5;
                        if(cursor.y < 0) cursor.y = 4;
                        break;
                    case 's':
                        cursor.y = (cursor.y + 1) % 5;
                        break;
                    case 'a':
                        cursor.x = abs((cursor.x - 1) % 2);
                        break;
                    case 'd':
                        cursor.x = (cursor.x + 1) % 2;
                        break;
                    case 'n':
                        editMode = (editMode + 1) % 2;
                        enteredValue = 0;
                        break;
                }
            }
        }

            usElapsed(&t_now);
            if(t_now >= t_lastRender+(1e6/(app.targetFPS*1.0))) ///Draw :)
            {
                /// DRAW
                draw();
                t_lastRender = t_now;
                app.cyclesPerFrame=0;
            }
            else app.cyclesPerFrame++;
            msDelay(1); ///Let the CPU sleep for a bit
    }


    exit_handler(0);
}

