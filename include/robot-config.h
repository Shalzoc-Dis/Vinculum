#pragma once
#include <vex.h>
#include "Logger.h"
#include "Core.h"


// VEXcode devices
extern vex::brain Brain;
extern vex::controller Controller1;
extern vex::motor M_FL;
extern vex::motor M_FR;
extern vex::motor M_BL;
extern vex::motor M_BR;
extern vex::encoder leftEncoder;
extern vex::encoder rightEncoder;


extern vex::competition Competition;

void vexcodeInit();