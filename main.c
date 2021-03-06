#include "main.h"
#include "draw_otazky.h"

unsigned long long t_now=0, t_lastRender=0, t_lastStonks=0;

struct app app;
struct player player;
struct stocks stocks;
struct cursor cursor;
struct state* stonksState;

int editMode;
int enteredValue = 0;
int question = 0;
struct Otazka otazka[10];

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
    app.state = 2; // otazky

    player.freeCash = 1000;
    player.netWorth = 0;

    cursor.x = 0;
    cursor.y = 0;

    editMode = 0;

    //random init
    pcg32_srandom((uint64_t) time(0), (uint64_t) time(0)/2);

    //APP INIT
    initTermios(0);

    // INIT otazky
    otazky();

    /// STONKS INIT
    stonksState = initState();
    for(int i = 0; i < 5; i++)
    {
        updateInstrument(stonksState, i, (float)(50+pcg32_boundedrand(100)));
        setDirection(stonksState, i, ((i % 2) * 2) - 1);
    }

    setRiskLevel(stonksState, 0, CONSERVATIVE);
    setRiskLevel(stonksState, 1, BALANCED);
    setRiskLevel(stonksState, 2, DYNAMIC);
    setRiskLevel(stonksState, 3, CONSERVATIVE);
    setRiskLevel(stonksState, 4, BALANCED);

    setVolatility(stonksState, 0, HIGH);
    setVolatility(stonksState, 1, LOW);
    setVolatility(stonksState, 2, MEDIUM);
    setVolatility(stonksState, 3, MEDIUM);
    setVolatility(stonksState, 4, HIGH);

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
                        buyInstrumentMoney(stonksState, cursor.y, (float)enteredValue);
                    }
                    if(cursor.x == 1)
                    {
                        sellInstrumentMoney(stonksState, cursor.y, (float)enteredValue);
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
                int ROWS = 5;
                if (app.state == 2)
                    ROWS = 3;
                switch (key)
                {

                    case 'w':
                        cursor.y = (cursor.y - 1) % ROWS;
                        if(cursor.y < 0) cursor.y = 4;
                        break;
                    case 's':
                        cursor.y = (cursor.y + 1) % ROWS;
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
                        else if(app.state == 2){
                            if (cursor.y == otazka[question].correct)
                                question++;
                            if (question>3)
                                app.state = 1;
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
                    draw_otazky();
                /// GRAPH
                else if (app.state == 3)
                    draw_graph();
                else
                    draw();
                t_lastRender = t_now;
                app.cyclesPerFrame=0;
            }
            if(t_now >= t_lastStonks+(1e6)) ///Draw :)
            {
                updateInstruments(stonksState);
                t_lastStonks = t_now;
            }
            else app.cyclesPerFrame++;
            msDelay(1); ///Let the CPU sleep for a bit
    }


    exit_handler(0);
}

