#pragma once

#include "KB/GameState.h"
#include "KB/Types.h"

#include <string>

namespace KB {

struct FSaveGameData {
    std::string ProfileName;
    FTeamData UserTeam{};
    FMatchSettings PreferredMatchSettings{};
    int LastKnownDifficulty = 1;
};

class SaveManager {
public:
    bool SaveProfile(const FSaveGameData& data, const std::string& path) const;
    bool LoadProfile(FSaveGameData& outData, const std::string& path) const;
};

} // namespace KB
