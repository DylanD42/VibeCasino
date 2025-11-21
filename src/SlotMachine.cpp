#include "SlotMachine.h"
#include <random>

SlotMachine::SlotMachine() {
    symbols = {"7", "BAR", "Cherry", "Diamond", "Lemon"};
    reels = {"?", "?", "?"};
}

void SlotMachine::Randomize() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, (int)symbols.size() - 1);
    for (int i = 0; i < 3; ++i) reels[i] = symbols[dist(gen)];
}

int SlotMachine::Spin(int bet) {
    Randomize();
    // three of a kind
    if (reels[0] == reels[1] && reels[1] == reels[2]) {
        if (reels[0] == "7") return bet * 10;
        if (reels[0] == "BAR") return bet * 5;
        if (reels[0] == "Diamond") return bet * 4;
        return bet * 2;
    }
    // two of a kind -> refund bet
    if (reels[0] == reels[1] || reels[1] == reels[2] || reels[0] == reels[2]) return bet;
    // nothing
    return 0;
}

const std::vector<std::string>& SlotMachine::GetReels() const { return reels; }
