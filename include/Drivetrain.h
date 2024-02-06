#pragma once
#include "Core.h"
#include "robot-config.h"

namespace Vinculum {

    int MotionCalculator (relativePathNode& target, uint8_t speedPct, float driveTime = 0);
    int PositioningComputer (vex::encoder& leftEncoder, vex::encoder& rightEncoder, vector2* position, float* angle);
}