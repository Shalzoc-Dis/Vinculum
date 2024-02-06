#include "Drivetrain.h"


namespace Vinculum {
    int MotionCalculator()
    {
        float xDist, yDist;
        float angleDifference;  // The angle is the angle from the robot's front to a line pointing at the target, in radians
        absolutePathNode location(Robot::position, 0); // The robot's location at the time of the function call

        if (Robot::speed > 1) {
            //fileLog("\nWARNING: Speed cannot be greater than 1. speedPct adjusted to be 1.\n");
            Robot::speed = 1;
        } else if (Robot::speed == 0) {
            //fileLog("\nERROR: Speed cannot be 0. speedP adjusted to be 1.\n");
            Robot::speed = 1;
        }

        while (true)
        {
            // Calculate the x and y distances to the target
            xDist = Vinculum::Robot::targetingPosition.x - Vinculum::Robot::position.x;
            yDist = Vinculum::Robot::targetingPosition.y - Vinculum::Robot::position.y;
            // Calculate the angle difference between the target and the robot
            angleDifference = Vinculum::Robot::targetingPosition.angle - Robot::angle;   // All degrees
            angleDifference *= M_PI / 180;  // Convert to radians

            // Calculate how the wheels must spin to follow the straight line path to the target
            // Rotate the whole plane of vectors by the difference in angle such that we just need to cancel out the y velocity of each wheel vector
            //  Here are the angles of the wheel's power vectors
            vector2 PowerFL(cos(M_PI/4), sin(M_PI/4));
            vector2 PowerFR(-cos(M_PI/4), sin(M_PI/4));
            vector2 PowerBL(-cos(M_PI/4), sin(M_PI/4));
            vector2 PowerBR(cos(M_PI/4), sin(M_PI/4));

            //  Rotate the vectors by the angle
            vector2 FL_Transformed = PowerFL.rotate(angleDifference);
            vector2 FR_Transformed = PowerFR.rotate(angleDifference);
            vector2 BL_Transformed = PowerBL.rotate(angleDifference);
            vector2 BR_Transformed = PowerBR.rotate(angleDifference);

            // Scale down the larger y-components ones such that the smaller ones can cancel with them
            float biggestFront, biggestBack, biggest;
            abs(FL_Transformed.y) > abs(FR_Transformed.y) ? biggestFront = abs(FL_Transformed.y) : biggestFront = abs(FR_Transformed.y);
            abs(BL_Transformed.y) > abs(BR_Transformed.y) ? biggestBack = abs(BL_Transformed.y) : biggestBack = abs(BR_Transformed.y);
            biggestFront > biggestBack ? biggest = biggestFront : biggest = biggestBack;

            FL_Transformed = FL_Transformed / biggest;
            FR_Transformed = FR_Transformed / biggest;
            BL_Transformed = BL_Transformed / biggest;
            BR_Transformed = BR_Transformed / biggest;

            // Rotate the motors
            M_FL.spin(vex::directionType::fwd, Vinculum::Robot::speed * FL_Transformed.magnetude(), vex::velocityUnits::pct);
            M_FR.spin(vex::directionType::fwd, Vinculum::Robot::speed * FR_Transformed.magnetude(), vex::velocityUnits::pct);
            M_BL.spin(vex::directionType::fwd, Vinculum::Robot::speed * BL_Transformed.magnetude(), vex::velocityUnits::pct);
            M_BR.spin(vex::directionType::fwd, Vinculum::Robot::speed * BR_Transformed.magnetude(), vex::velocityUnits::pct);



            vex::task::sleep(25);
        }
        return 0;
    }

    int PositioningComputer (vex::encoder& leftEncoder, vex::encoder& rightEncoder, vector2* position, float* angle)
    { /*
        // TODO: Review this code
        while (true)
        {
            // Calculate the distance travelled by each wheel
            float leftDist = leftEncoder.rotation(vex::rotationUnits::deg) * M_PI * Robot::wheelDiameter / 360;
            float rightDist = rightEncoder.rotation(vex::rotationUnits::deg) * M_PI * Robot::wheelDiameter / 360;
            // Calculate the angle travelled by the robot
            //float angleChange = (rightDist - leftDist) / (Robot::FrontLeftWheel - Robot::FrontRightWheel).magnetude();
            // Calculate the distance travelled by the robot
            float dist = (leftDist + rightDist) / 2;
            // Calculate the change in x and y
            float xChange = dist * cos(angleChange);
            float yChange = dist * sin(angleChange);
            // Calculate the change in x and y relative to the robot
            float xChangeRelative = xChange * cos(*angle) - yChange * sin(*angle);
            float yChangeRelative = xChange * sin(*angle) + yChange * cos(*angle);
            // Update the robot's position
            position->x += xChangeRelative;
            position->y += yChangeRelative;
            // Update the robot's angle
            *angle += angleChange;
            vex::task::sleep(25);
        }
        // Return 0 to indicate success
        */return 0; 
    }
}