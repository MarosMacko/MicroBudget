#include "main.h"

struct app
{
    int consoleHeight;
    int consoleWidth;
    int cyclesPerFrame;
    int targetFPS;
    int state;
} app;

unsigned long long t_now=0, t_lastRender=0;

int main()
{
    signal(SIGINT, exit_handler);
    app.consoleHeight = getConsoleHeight();
    app.consoleWidth  = getConsoleWidth();
    app.targetFPS = 60;
    app.state = 1;


    //random init
    pcg32_srandom((uint64_t) time(NULL), (uint64_t) time(NULL)/2);

    //GAME INIT

    initTermios(0);


    //GAME LOOP
    while(app.state==1)
    {
            usElapsed(&t_now);
            if(t_now >= t_lastRender+(1e6/(app.targetFPS*1.0))) ///Draw :)
            {
                /// DRAW

                t_lastRender = t_now;
                app.cyclesPerFrame=0;
            }
            else app.cyclesPerFrame++;
            msDelay(2); ///Let the CPU sleep for a bit
    }


    exit_handler(0);
}

