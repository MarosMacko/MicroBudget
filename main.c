#include "main.h"



unsigned long long t_now=0, t_lastRender=0;

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
    app.targetFPS = 3;
    app.state = 1;

    player.freeCash = 1000;
    player.netWorth = calculateNetWorth();



    //random init
    pcg32_srandom((uint64_t) time(0), (uint64_t) time(0)/2);

    //GAME INIT

    initTermios(0);


    //GAME LOOP
    while(app.state==1)
    {
            usElapsed(&t_now);
            if(t_now >= t_lastRender+(1e6/(app.targetFPS*1.0))) ///Draw :)
            {
                /// DRAW
                draw(&app, &player, &stocks);
                t_lastRender = t_now;
                app.cyclesPerFrame=0;
            }
            else app.cyclesPerFrame++;
            msDelay(1); ///Let the CPU sleep for a bit
    }


    exit_handler(0);
}

