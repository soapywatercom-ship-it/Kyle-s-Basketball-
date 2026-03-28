#pragma once

#include "KB/GameState.h"
#include "KB/Types.h"

namespace KB {

class MatchManager {
public:
    void Initialize(FGameState& gameState, const FMatchSettings& settings);
    void StartTipOff(FGameState& gameState);
    void Tick(FGameState& gameState, float deltaSeconds);

private:
    FMatchSettings Settings{};
};

} // namespace KB
