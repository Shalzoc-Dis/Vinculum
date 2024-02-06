#include "Core.h"

namespace Vinculum { namespace Robot {

    // This is the bias of the mecanum wheels. The more powerful direction is the lower number, which acts as a multiplier 
    // for the motor movements in that direction in order to make the robot move perfectly. This accounts for the friction in 
    // the wheels that our calculation does not account for.
    const float xBias = 0;
    const float yBias = 0;

    // This is the diameter of the mecanum wheels in centimetres
    const float wheelDiameter = 10.16;

    // These are the locations of the wheels relative to the centre of the robot in centimetres
    const vector2 FrontLeftWheel;
    const vector2 FrontRightWheel;
    const vector2 BackLeftWheel;
    const vector2 BackRightWheel;

    // These are the locations of the odeometry wheels relative to the centre of the robot in centimetres
    const vector2 LeftOdoWheel;
    const vector2 RightOdoWheel;
    const vector2 BackOdoWheel;

    // This is the diameter of the odeometry wheels in centimetres
    const float odeometryWheelDiameter = 6.9;

    // This the mas of the robot in kg
    const float mass = 2;

    // The robot's current position
    vector2 position = vector2(0, 0);
    float angle = 0;    // In degrees, 0 degrees is right, 90 is up
}}