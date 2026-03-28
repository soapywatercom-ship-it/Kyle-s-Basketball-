#pragma once

#include "KB/GameState.h"

namespace KB {

class PossessionManager {
public:
    void Initialize(FGameState& gameState, int homeTeamId, int awayTeamId);
    void ChangePossession(FGameState& gameState);
    void SetPossession(FGameState& gameState, int teamId);

private:
    int HomeTeamId = -1;
    int AwayTeamId = -1;
};

} // namespace KB
