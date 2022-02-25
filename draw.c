//
// Created by marosm on 25. 2. 2022.
//

#include "draw.h"

void draw()
{
    static unsigned long frame = 0;
    static unsigned frames=0;
    static double fps=0;
    static unsigned long long lastDraw_us=0, now_us=0;
    ///FPS measure
    long long old_now = now_us;
    usElapsed(&now_us);
    if (now_us > lastDraw_us+50)
    {
        fps = (double)frames*1000000 / (double)(now_us-lastDraw_us);
        frames = 0;
        lastDraw_us = now_us;
    }
    frames++;
    if ((frame++)==0) clearScreen();

    gotoXY(0, 0);
    printf("%3.1f FPS (%5.2fms)       ", fps, (now_us-old_now)/1000.0);

}
