#include "Casino.h"
#include <string>
#include <algorithm>

Casino::Casino(int w, int h)
    : screenWidth(w), screenHeight(h), balance(1000), bet(10), spinning(false), spinTimer(0.0f) {
    InitWindow(screenWidth, screenHeight, "VibeCasino - Simple Raylib Demo");
    SetTargetFPS(60);
}

Casino::~Casino() { CloseWindow(); }

void Casino::Run() {
    while (!WindowShouldClose()) {
        Update();
        BeginDrawing();
        ClearBackground(DARKGRAY);
        Draw();
        EndDrawing();
    }
}

void Casino::Update() {
    if (!spinning) {
        if (IsKeyPressed(KEY_RIGHT)) bet += 10;
        if (IsKeyPressed(KEY_LEFT)) bet = std::max(1, bet - 10);

        if (IsKeyPressed(KEY_SPACE) && balance >= bet) {
            balance -= bet;
            int payout = slot.Spin(bet);
            // simple spin timing to show message
            spinning = true;
            spinTimer = 0.6f;
            balance += payout;
        }
    } else {
        spinTimer -= GetFrameTime();
        if (spinTimer <= 0) spinning = false;
    }
}

void Casino::Draw() {
    std::string bal = "Balance: $" + std::to_string(balance);
    DrawText(bal.c_str(), 20, 20, 20, RAYWHITE);
    std::string betText = "Bet: $" + std::to_string(bet) + "  (Left/Right to change)";
    DrawText(betText.c_str(), 20, 50, 20, RAYWHITE);
    DrawText("Press SPACE to Spin", 20, 80, 18, RAYWHITE);

    // draw reels
    auto reels = slot.GetReels();
    int rw = 180, rh = 180;
    int startX = (screenWidth - (3 * rw + 20 * 2)) / 2;
    for (int i = 0; i < 3; ++i) {
        Rectangle rec = {(float)(startX + i * (rw + 20)), 150.0f, (float)rw, (float)rh};
        DrawRectangleRec(rec, LIGHTGRAY);
        DrawText(reels[i].c_str(), (int)rec.x + 40, (int)rec.y + 70, 40, MAROON);
    }

    if (spinning) DrawText("Spinning...", screenWidth - 180, 20, 20, RAYWHITE);
}
