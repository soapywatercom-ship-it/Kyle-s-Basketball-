#include "KB/GameApp.h"

#include <iostream>

namespace KB {

namespace {
FTeamData BuildStarterTeam(int id, const std::string& teamName, const std::string& captainName, std::uint8_t captainNumber) {
    FTeamData team{};
    team.TeamId = id;
    team.TeamName = teamName;

    FPlayerData captain{};
    captain.PlayerId = (id * 100) + 1;
    captain.DisplayName = captainName;
    captain.JerseyNumber = captainNumber;
    team.Roster.push_back(captain);
    return team;
}
} // namespace

void GameApp::Boot() {
    ActiveScreen = EUiScreen::Splash;

    HomeTeam = BuildStarterTeam(1, "Neon Storm", "Kyle Carter", 7);
    AwayTeam = BuildStarterTeam(2, "Voltage Tide", "Dante Flux", 3);

    Match.Initialize(State, FMatchSettings{});
    Possession.Initialize(State, HomeTeam.TeamId, AwayTeam.TeamId);

    const auto scene = Spawner.SpawnCoreScene();
    std::cout << "Spawned actors: " << scene.size() << '\n';

    FSaveGameData saveData{};
    saveData.ProfileName = "DefaultProfile";
    saveData.UserTeam = HomeTeam;
    Save.SaveProfile(saveData, "kb_profile.sav");

    ActiveScreen = EUiScreen::MainMenu;
    State.MatchFlow = EMatchFlowState::MainMenu;
}

void GameApp::Tick(float deltaSeconds) {
    if (State.MatchFlow == EMatchFlowState::MainMenu) {
        Match.StartTipOff(State);
    }

    const auto frame = Input.BuildFrameFromTouch(0.35F, 0.12F, false, false, false, false);
    if (frame.PassPressed) {
        Possession.ChangePossession(State);
    }

    Match.Tick(State, deltaSeconds);
}

const FGameState& GameApp::GetGameState() const {
    return State;
}

} // namespace KB
