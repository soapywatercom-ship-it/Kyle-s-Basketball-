#include "KB/CourtSpawner.h"

namespace KB {

std::vector<FSpawnedActor> CourtSpawner::SpawnCoreScene() {
    std::vector<FSpawnedActor> scene;
    scene.reserve(5);

    scene.push_back({NextId++, "CourtFloor"});
    scene.push_back({NextId++, "HomeHoop"});
    scene.push_back({NextId++, "AwayHoop"});
    scene.push_back({NextId++, "Ball"});
    scene.push_back({NextId++, "PlayerGroup"});

    return scene;
}

} // namespace KB
