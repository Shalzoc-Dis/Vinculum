/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       hypatia                                                   */
/*    Created:      14/12/2023, 20:11:22                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include <vex.h>
#include "robot-config.h"
#include "Core.h"
#include "Drivetrain.h"
#include "Logger.h"

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {
    vexcodeInit();

    M_FR.spinFor(vex::directionType::fwd, 100, vex::rotationUnits::deg, 10, vex::velocityUnits::pct);
    M_FL.spinFor(vex::directionType::fwd, 100, vex::rotationUnits::deg, 10, vex::velocityUnits::pct);
    M_BR.spinFor(vex::directionType::fwd, 100, vex::rotationUnits::deg, 10, vex::velocityUnits::pct);
    M_BL.spinFor(vex::directionType::fwd, 100, vex::rotationUnits::deg, 10, vex::velocityUnits::pct);


    while(1) {
        
        printf("Right encoder: %f\n", -rightEncoder.rotation(vex::rotationUnits::deg));
        printf("Left encoder: %f\n\n", -leftEncoder.rotation(vex::rotationUnits::deg));
        // Allow other tasks to run
        vex::this_thread::sleep_for(10);
    }
}
