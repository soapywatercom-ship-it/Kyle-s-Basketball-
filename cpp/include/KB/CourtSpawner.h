#pragma once

#include <string>
#include <vector>

namespace KB {

struct FSpawnedActor {
    int Id = -1;
    std::string Type;
};

class CourtSpawner {
public:
    std::vector<FSpawnedActor> SpawnCoreScene();

private:
    int NextId = 1;
};

} // namespace KB
