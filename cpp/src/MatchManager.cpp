#include "KB/MatchManager.h"

#include <algorithm>

namespace KB {

void MatchManager::Initialize(FGameState& gameState, const FMatchSettings& settings) {
    Settings = settings;
    gameState.MatchFlow = EMatchFlowState::PreTipOff;
    gameState.Clock.QuarterIndex = 1;
    gameState.Clock.QuarterSecondsRemaining = Settings.QuarterLengthSeconds;
    gameState.Clock.ShotClockRemaining = static_cast<float>(Settings.ShotClockSeconds);
    gameState.Score = {};
}

void MatchManager::StartTipOff(FGameState& gameState) {
    gameState.MatchFlow = EMatchFlowState::LiveBall;
}

void MatchManager::Tick(FGameState& gameState, float deltaSeconds) {
    if (gameState.MatchFlow != EMatchFlowState::LiveBall) {
        return;
    }

    gameState.Clock.ShotClockRemaining = std::max(0.0f, gameState.Clock.ShotClockRemaining - deltaSeconds);

    const int quarterDelta = static_cast<int>(deltaSeconds);
    if (quarterDelta <= 0 || gameState.Clock.QuarterSecondsRemaining == 0) {
        return;
    }

    if (gameState.Clock.QuarterSecondsRemaining > quarterDelta) {
        gameState.Clock.QuarterSecondsRemaining -= static_cast<std::uint16_t>(quarterDelta);
        return;
    }

    if (gameState.Clock.QuarterIndex >= Settings.QuarterCount) {
        gameState.Clock.QuarterSecondsRemaining = 0;
        gameState.MatchFlow = EMatchFlowState::Final;
        return;
    }

    gameState.MatchFlow = EMatchFlowState::QuarterBreak;
    gameState.Clock.QuarterIndex++;
    gameState.Clock.QuarterSecondsRemaining = Settings.QuarterLengthSeconds;
    gameState.Clock.ShotClockRemaining = static_cast<float>(Settings.ShotClockSeconds);
}

} // namespace KB
