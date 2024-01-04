#pragma once
#include <vex.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "robot-config.h"


//vex::timer Timer;   // This creates a reference to the clock

    struct vector2 {
        vector2(float x, float y)
        : x(x), y(y) {}

        vector2() {}
        ~vector2() {}
        float x;
        float y;

        // This overloads the data type to allow for vector addition.
        vector2 operator+(vector2 const &obj) {
            vector2 res;
            res.x = x + obj.x;
            res.y = y + obj.y;
            return res;
        }

        // This overloads the data type to allow for vector subtraction.
        vector2 operator-(vector2 const &obj) {
            vector2 res;
            res.x = x - obj.x;
            res.y = y - obj.y;
            return res;
        }

        float magnetude() {
            return sqrt(pow(x, 2) + pow(y, 2));
        }

        float direction() {
            return atan2(y, x);
        }

        vector2 operator*(float const &obj) {
            vector2 res;
            res.x = x * obj;
            res.y = y * obj;
            return res;
        }

        void normalise() {
            x /= magnetude();
            y /= magnetude();
        }

        vector2 normalised() {
            vector2 res;
            res.x = x / magnetude();
            res.y = y / magnetude();
            return res;
        }
    }; // struct vector2


// Ports

namespace Vinculum {

    // ------------------------------------- Global constant information -----------------------------------------------------
    namespace Robot {
        // This is the bias of the mecanum wheels. The more powerful direction is the lower number, which acts as a multiplier 
        // for the motor movements in that direction in order to make the robot move perfectly. This accounts for the friction in 
        // the wheels that our calculation does not account for.
        extern const float xBias;
        extern const float yBias;

        // This is the diameter of the mecanum wheels in centimetres
        extern const float wheelDiameter;

        // These are the locations of the wheels relative to the centre of the robot in centimetres
        extern const vector2 FrontLeftWheel;
        extern const vector2 FrontRightWheel;
        extern const vector2 BackLeftWheel;
        extern const vector2 BackRightWheel;

        // These are the locations of the odeometry wheels relative to the centre of the robot in centimetres
        extern const vector2 LeftOdoWheel;
        extern const vector2 RightOdoWheel;
        extern const vector2 BackOdoWheel;

        // This is the diameter of the odeometry wheels in centimetres
        extern const float odeometryWheelDiameter;

        // This the mas of the robot in kg
        extern const float mass;
    } // namespace Robot



    struct relativePathNode { 
        // The position and angle are both relative to the robot
        relativePathNode(vector2 pos, float angle)
        : pos(pos), angle(angle) {}

        relativePathNode() {}
        ~relativePathNode() {}
        vector2 pos;
        float angle;    // In Degrees
    }; // struct relativePathNode

    struct absolutePathNode { 
        // The position and angle are both relative to the field
        absolutePathNode(vector2 pos, float angle)
        : pos(pos), angle(angle) {}

        absolutePathNode() {}
        ~absolutePathNode() {}
        vector2 pos;
        float angle;    // In degrees
    }; // struct absolutePathNode

} // namespace Vinculum