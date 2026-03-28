#pragma once

#include "KB/Types.h"

namespace KB {

struct FGameClock {
    std::uint16_t QuarterSecondsRemaining = 0;
    float ShotClockRemaining = 0.0f;
    std::uint8_t QuarterIndex = 1;
};

struct FScoreState {
    std::uint16_t Home = 0;
    std::uint16_t Away = 0;
};

struct FGameState {
    EMatchFlowState MatchFlow = EMatchFlowState::Boot;
    FGameClock Clock{};
    FScoreState Score{};
    std::int32_t PossessionTeamId = -1;
};

} // namespace KB
