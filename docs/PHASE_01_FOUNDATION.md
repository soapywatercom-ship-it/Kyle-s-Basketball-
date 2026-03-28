# KYLE'S BASKETBALL — Phase 1 Foundation (Implemented)

This document defines and records the **Phase 1** implementation for a mobile-first 3D basketball simulation architecture in modern C++.

## 1) Purpose

Phase 1 establishes the minimum shippable foundation for every gameplay feature that follows:

- Core match loop with deterministic state progression.
- Team/player data model for roster-driven gameplay.
- Possession authority and game flow ownership.
- Core scene bootstrap (court, hoops, ball, players).
- Input abstraction for touch-first controls.
- Save/load profile skeleton.
- UI shell state model (splash/title/menu/hud/pause).

## 2) Systems Implemented

- **Game Application Orchestrator** (`GameApp`)
- **Match State & Clock System** (`FGameState`, `MatchManager`)
- **Possession System** (`PossessionManager`)
- **Core Scene Spawner** (`CourtSpawner`)
- **Touch Input Frame Router** (`InputRouter`)
- **Save/Load Persistence Foundation** (`SaveManager`, `FSaveGameData`)
- **Shared Data Types** (`Types.h`)

## 3) C++ Modules and Classes

### Core Data
- `KB::FPlayerAttributes`
- `KB::FPlayerData`
- `KB::FTeamData`
- `KB::FMatchSettings`
- `KB::FInputFrame`
- `KB::FGameClock`
- `KB::FScoreState`
- `KB::FGameState`
- `KB::FSaveGameData`

### Runtime Managers
- `KB::GameApp`
- `KB::MatchManager`
- `KB::PossessionManager`
- `KB::CourtSpawner`
- `KB::InputRouter`
- `KB::SaveManager`

## 4) Key Methods and Data Structures

### `GameApp`
- `Boot()`
  - Creates starter teams and initial roster.
  - Initializes match settings and possession state.
  - Spawns foundation scene actors.
  - Saves first profile snapshot.
  - Transitions from splash to main menu flow.
- `Tick(float deltaSeconds)`
  - Promotes main menu into live game (temporary bootstrap behavior).
  - Produces one input frame from touch proxy data.
  - Advances match clock.

### `MatchManager`
- `Initialize(FGameState&, const FMatchSettings&)`
- `StartTipOff(FGameState&)`
- `Tick(FGameState&, float)`
  - Advances shot clock and game clock.
  - Handles quarter transitions.
  - Enters final state when regulation ends.

### `PossessionManager`
- `Initialize(FGameState&, homeTeamId, awayTeamId)`
- `ChangePossession(FGameState&)`
- `SetPossession(FGameState&, teamId)`

### `SaveManager`
- `SaveProfile(const FSaveGameData&, path)`
- `LoadProfile(FSaveGameData&, path)`

### `CourtSpawner`
- `SpawnCoreScene()` returns spawned actor descriptors:
  - `CourtFloor`
  - `HomeHoop`
  - `AwayHoop`
  - `Ball`
  - `PlayerGroup`

## 5) Cross-System Interaction (Implemented)

- `GameApp` is the orchestration root.
- `MatchManager` owns match clock state transitions.
- `PossessionManager` mutates possession inside the shared `FGameState`.
- `InputRouter` emits sanitized input frames for gameplay systems.
- `CourtSpawner` bootstraps the runtime scene descriptor list.
- `SaveManager` persists foundational profile + team data.

## 6) Mobile Performance Considerations (Phase 1)

- Stack/value-based core structs to avoid heap churn in gameplay loops.
- Lightweight manager classes (minimal per-frame allocation).
- Input clamping in a single normalized stage (`InputRouter`).
- Keep frame-tick responsibilities narrow in foundation stage.
- Scene spawn done once in boot path.

## 7) Test Cases / Acceptance Criteria (Phase 1)

1. **Boot test**
   - Given `GameApp::Boot()` is called, scene contains at least 5 core actors.
2. **Clock progression test**
   - Given live match and `Tick(1.0f)`, shot clock decreases.
3. **Quarter rollover test**
   - Given quarter time expires before final quarter, state enters `QuarterBreak` and increments quarter.
4. **Final state test**
   - Given last quarter expires, match enters `Final`.
5. **Possession swap test**
   - `ChangePossession` toggles between home and away team IDs.
6. **Save/load test**
   - Saving then loading profile preserves profile name, team name, difficulty, and roster rows.
7. **Input sanitization test**
   - Values outside [-1, 1] clamp correctly in `FInputFrame`.

## 8) What Was Built vs What Remains

### Built in Phase 1
- Foundational game loop and match state machine.
- Team/player data containers.
- Possession ownership system.
- Boot scene spawner scaffold.
- Input frame abstraction (touch-ready).
- Save/load profile baseline.
- Minimal UI shell state enum for splash/title/menu/hud/pause.

### Deferred to Phase 2+
- True 3D character movement and basketball locomotion.
- Ball physics ownership and dribble handoff.
- Full HUD/menu implementation bound to runtime UI framework.
- Real input bindings per mobile platform.
- Full Unreal subsystem/module wiring.

## 9) Immediate Next Steps (Phase 2 Entry)

1. Add `PlayerCharacter` locomotion state machine (offense/defense stance layers).
2. Add `BallComponent` ownership and hand-binding points.
3. Integrate stamina decay with movement velocity curves.
4. Implement mobile camera rig bootstrap (broadcast + gameplay follow).
5. Add collision capsules and basic body-up interactions.

## 10) Branding Guidance (Logo Integration)

The uploaded **Kyle's Basketball logo** is designated as source-of-truth branding for:

- App icon
- Splash screen
- Title screen
- Main menu neon palette

Implementation hooks are staged for UI skinning in upcoming UI module integration.
