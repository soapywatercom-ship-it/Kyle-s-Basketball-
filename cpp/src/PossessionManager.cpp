#include "KB/PossessionManager.h"

namespace KB {

void PossessionManager::Initialize(FGameState& gameState, int homeTeamId, int awayTeamId) {
    HomeTeamId = homeTeamId;
    AwayTeamId = awayTeamId;
    gameState.PossessionTeamId = HomeTeamId;
}

void PossessionManager::ChangePossession(FGameState& gameState) {
    if (gameState.PossessionTeamId == HomeTeamId) {
        gameState.PossessionTeamId = AwayTeamId;
    } else {
        gameState.PossessionTeamId = HomeTeamId;
    }
}

void PossessionManager::SetPossession(FGameState& gameState, int teamId) {
    gameState.PossessionTeamId = teamId;
}

} // namespace KB
