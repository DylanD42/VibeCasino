#pragma once
#include <raylib.h>
#include "SlotMachine.h"

class Casino {
public:
    Casino(int w = 800, int h = 600);
    ~Casino();
    void Run();

private:
    int screenWidth, screenHeight;
    int balance;
    SlotMachine slot;
    int bet;
    bool spinning;
    float spinTimer;

    void Update();
    void Draw();
};
