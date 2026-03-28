#pragma once

#include "KB/Types.h"

namespace KB {

class InputRouter {
public:
    FInputFrame BuildFrameFromTouch(float leftStickX, float leftStickY, bool shootTap, bool passTap,
                                    bool sprintHold, bool defendHold) const;
};

} // namespace KB
