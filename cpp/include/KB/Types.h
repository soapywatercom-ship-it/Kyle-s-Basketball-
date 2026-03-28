#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace KB {

enum class EMatchFlowState : std::uint8_t {
    Boot,
    MainMenu,
    PreTipOff,
    LiveBall,
    DeadBall,
    QuarterBreak,
    Final
};

enum class EUiScreen : std::uint8_t {
    Splash,
    Title,
    MainMenu,
    MatchHud,
    PauseMenu
};

struct FPlayerAttributes {
    float Speed = 50.0f;
    float Acceleration = 50.0f;
    float Stamina = 50.0f;
    float BallHandling = 50.0f;
    float Passing = 50.0f;
    float Shooting = 50.0f;
    float PerimeterDefense = 50.0f;
    float InteriorDefense = 50.0f;
};

struct FPlayerData {
    std::int32_t PlayerId = -1;
    std::string DisplayName;
    std::uint8_t JerseyNumber = 0;
    FPlayerAttributes Attributes{};
};

struct FTeamData {
    std::int32_t TeamId = -1;
    std::string TeamName;
    std::vector<FPlayerData> Roster;
};

struct FMatchSettings {
    std::uint8_t QuarterCount = 4;
    std::uint16_t QuarterLengthSeconds = 300;
    std::uint8_t ShotClockSeconds = 24;
};

struct FInputFrame {
    float MoveX = 0.0f;
    float MoveY = 0.0f;
    bool ShootPressed = false;
    bool PassPressed = false;
    bool SprintHeld = false;
    bool DefendHeld = false;
};

} // namespace KB
