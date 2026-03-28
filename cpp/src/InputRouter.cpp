#include "KB/InputRouter.h"

#include <algorithm>

namespace KB {

FInputFrame InputRouter::BuildFrameFromTouch(float leftStickX, float leftStickY, bool shootTap, bool passTap,
                                             bool sprintHold, bool defendHold) const {
    FInputFrame frame{};
    frame.MoveX = std::clamp(leftStickX, -1.0f, 1.0f);
    frame.MoveY = std::clamp(leftStickY, -1.0f, 1.0f);
    frame.ShootPressed = shootTap;
    frame.PassPressed = passTap;
    frame.SprintHeld = sprintHold;
    frame.DefendHeld = defendHold;
    return frame;
}

} // namespace KB
