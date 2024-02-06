#include "robot-config.h"


// vex::motor M_FL = vex::motor(vex::PORT1, vex::gearSetting::ratio18_1, bool reversed);
vex::motor M_FL = vex::motor(vex::PORT20, vex::ratio18_1, false);
vex::motor M_FR = vex::motor(vex::PORT19, vex::ratio18_1, true);
vex::motor M_BL = vex::motor(vex::PORT10, vex::ratio18_1, false);
vex::motor M_BR = vex::motor(vex::PORT9, vex::ratio18_1, true);


vex::encoder leftEncoder = vex::encoder(Brain.ThreeWirePort.C); // Top wire is in port C, the bottom is in port D
vex::encoder rightEncoder = vex::encoder(Brain.ThreeWirePort.A);  // Top wire is in port B, the bottom is in port A

vex::controller Controller1 = vex::controller(vex::controllerType::primary);


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit() {
  std::cout << "Initialising...\n";
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // Clear the log file
  Brain.Screen.print("Clearing log file...");
  Brain.Screen.setCursor(3, 1);
  Vinculum::clearLogFile();
  // Reset the Encoders
  Brain.Screen.print("Resetting Encoders...");
  Brain.Screen.setCursor(4, 1);
  leftEncoder.resetRotation();
  rightEncoder.resetRotation();
  // calibrate the drivetrain gyro
  //wait(200, msec);
  //TurnGyroSmart.startCalibration(1);
  //Brain.Screen.print("Calibrating Gyro for Drivetrain");
  // wait for the gyro calibration process to finish
  //while (TurnGyroSmart.isCalibrating()) {
    //wait(25, msec);
  //}
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, vex::timeUnits::msec);
  Brain.Screen.clearScreen();
  // Initialise the robot's position
  Vinculum::Robot::position = vector2(0, 0);
  Vinculum::Robot::angle = 0;
}