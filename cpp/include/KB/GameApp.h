#pragma once

#include "KB/CourtSpawner.h"
#include "KB/GameState.h"
#include "KB/InputRouter.h"
#include "KB/MatchManager.h"
#include "KB/PossessionManager.h"
#include "KB/SaveManager.h"
#include "KB/Types.h"

namespace KB {

class GameApp {
public:
    void Boot();
    void Tick(float deltaSeconds);
    [[nodiscard]] const FGameState& GetGameState() const;

private:
    FGameState State{};
    FTeamData HomeTeam{};
    FTeamData AwayTeam{};
    MatchManager Match{};
    PossessionManager Possession{};
    SaveManager Save{};
    InputRouter Input{};
    CourtSpawner Spawner{};
    EUiScreen ActiveScreen = EUiScreen::Splash;
};

} // namespace KB
