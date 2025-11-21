#pragma once
#include <vector>
#include <string>

class SlotMachine {
public:
    SlotMachine();
    // Spin with a bet amount, returns payout (not net change)
    int Spin(int bet);
    const std::vector<std::string>& GetReels() const;

private:
    std::vector<std::string> reels;
    std::vector<std::string> symbols;
    void Randomize();
};
