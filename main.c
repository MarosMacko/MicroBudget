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
    while(app.state==1 || app.state == 2 || app.state == 3)
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
                    editMode = 0;
                }
                else if(key == '`')
                {
                    enteredValue /= 10;
                }
                
                if(enteredValue < 10000)
                {
                    if((key >= '0') && (key <= '9'))
                        enteredValue = (enteredValue * 10) + (key - '0');
                }
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
                        cursor.x = (cursor.x - 1) % 3;
                        if(cursor.x < 0) cursor.x = 2;
                        break;
                    case 'd':
                        cursor.x = (cursor.x + 1) % 3;
                        break;
                    case 'n':
                        if(app.state == 3) // graf
                        {
                            app.state = 1;
                        }
                        else if((app.state == 1) && (cursor.x == 2)) // chcem graf
                        {
                            app.state = 3;
                        }
                        else
                        {
                            editMode = (editMode + 1) % 2;
                            enteredValue = 0;
                        }
                        break;
                }
            }
        }

            usElapsed(&t_now);
            if(t_now >= t_lastRender+(1e6/(app.targetFPS*1.0))) ///Draw :)
            {
                /// DRAW
                if (app.state == 2)
                    draw_quest();
                /// GRAPH
                if (app.state == 3)
                    draw_graph();
                else
                    draw();
                t_lastRender = t_now;
                app.cyclesPerFrame=0;
            }
            else app.cyclesPerFrame++;
            msDelay(1); ///Let the CPU sleep for a bit
    }


    exit_handler(0);
}

