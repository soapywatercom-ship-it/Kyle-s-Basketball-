#include "KB/GameApp.h"

#include <iostream>

int main() {
    KB::GameApp app{};
    app.Boot();

    for (int frame = 0; frame < 5; ++frame) {
        app.Tick(1.0F);
    }

    const auto& state = app.GetGameState();
    std::cout << "MatchFlow=" << static_cast<int>(state.MatchFlow)
              << " Quarter=" << static_cast<int>(state.Clock.QuarterIndex)
              << " QuarterTime=" << state.Clock.QuarterSecondsRemaining
              << " ShotClock=" << state.Clock.ShotClockRemaining << '\n';

    return 0;
}
