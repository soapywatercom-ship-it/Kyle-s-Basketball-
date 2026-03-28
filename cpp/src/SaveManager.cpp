#include "KB/SaveManager.h"

#include <fstream>
#include <sstream>

namespace KB {

bool SaveManager::SaveProfile(const FSaveGameData& data, const std::string& path) const {
    std::ofstream output(path, std::ios::trunc);
    if (!output.is_open()) {
        return false;
    }

    output << data.ProfileName << '\n';
    output << data.UserTeam.TeamName << '\n';
    output << data.LastKnownDifficulty << '\n';
    output << data.PreferredMatchSettings.QuarterCount << ' '
           << data.PreferredMatchSettings.QuarterLengthSeconds << ' '
           << static_cast<int>(data.PreferredMatchSettings.ShotClockSeconds) << '\n';
    output << data.UserTeam.Roster.size() << '\n';
    for (const auto& player : data.UserTeam.Roster) {
        output << player.PlayerId << '|' << player.DisplayName << '|' << static_cast<int>(player.JerseyNumber) << '\n';
    }

    return true;
}

bool SaveManager::LoadProfile(FSaveGameData& outData, const std::string& path) const {
    std::ifstream input(path);
    if (!input.is_open()) {
        return false;
    }

    std::getline(input, outData.ProfileName);
    std::getline(input, outData.UserTeam.TeamName);

    input >> outData.LastKnownDifficulty;
    int shotClock = 24;
    input >> outData.PreferredMatchSettings.QuarterCount
          >> outData.PreferredMatchSettings.QuarterLengthSeconds
          >> shotClock;
    outData.PreferredMatchSettings.ShotClockSeconds = static_cast<std::uint8_t>(shotClock);

    std::size_t rosterSize = 0;
    input >> rosterSize;
    std::string line;
    std::getline(input, line);

    outData.UserTeam.Roster.clear();
    outData.UserTeam.Roster.reserve(rosterSize);

    for (std::size_t i = 0; i < rosterSize; ++i) {
        if (!std::getline(input, line)) {
            break;
        }
        std::stringstream row(line);
        std::string token;
        FPlayerData player{};

        if (std::getline(row, token, '|')) {
            player.PlayerId = std::stoi(token);
        }
        if (std::getline(row, token, '|')) {
            player.DisplayName = token;
        }
        if (std::getline(row, token, '|')) {
            player.JerseyNumber = static_cast<std::uint8_t>(std::stoi(token));
        }

        outData.UserTeam.Roster.push_back(player);
    }

    return true;
}

} // namespace KB
