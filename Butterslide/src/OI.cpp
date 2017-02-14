// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ChangeMode.h"
#include "Commands/Feed.h"
#include "Commands/Suck.h"
#include "Commands/Shooting.h"
#include "Commands/UnSuck.h"
#include "Commands/RotateToAngle.h"
#include "Commands/EnableDriving.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driver.reset(new Joystick(0));
    captain.reset(new Joystick(1));
    
    int tractionModeBtn = 3,
    	fieldOrientBtn = 7,
		gyroResetBtn = 11,
		fireAwayBtn = 1,
		suckItUpBtn = 2,
		getItOutBtn = 9,
		loadItUpBtn = 4,
		rotateToAngleBtn = 10,
		enableDrivingBtn = 12;

    if(captain->GetAxisCount() == 0){
    	captain = driver;
    }


    if(driver->GetType() == GenericHID::HIDType::kHIDGamepad || driver->GetType() == GenericHID::HIDType::kXInputGamepad || driver->GetType() == GenericHID::HIDType::kXInputArcadePad){
    	tractionModeBtn = 1, //A
 	   	fieldOrientBtn = 4,  //Y
    	gyroResetBtn = 2, //B
    	rotateToAngleBtn = 7, //Back
    	enableDrivingBtn = 9; //Pushing in/clicking left stick
    	driverIsXbox = true;
    	if(captain == driver){
    		fireAwayBtn = 6, //RB
    		suckItUpBtn = 5, //LB
    		getItOutBtn = 8, //Start
    		loadItUpBtn = 3; //X
    	}
    }

    tractionMode.reset(new JoystickButton(driver.get(), tractionModeBtn));
    tractionMode->WhenPressed(new ChangeMode(7));

    fieldOrient.reset(new JoystickButton(driver.get(), fieldOrientBtn));
    fieldOrient->WhenPressed(new ChangeMode(9));

    gyroReset.reset(new JoystickButton(driver.get(), gyroResetBtn));
    gyroReset->WhenPressed(new ChangeMode(8));

    fireAway.reset(new JoystickButton(captain.get(), fireAwayBtn));
    fireAway->WhenPressed(new Shooting());

    suckItUp.reset(new JoystickButton(captain.get(), suckItUpBtn));
    suckItUp->WhenPressed(new Suck());

    getItOut.reset(new JoystickButton(captain.get(), getItOutBtn));
    getItOut->WhenPressed(new UnSuck());

    loadItUp.reset(new JoystickButton(captain.get(), loadItUpBtn));
    loadItUp->WhenPressed(new Feed());

    rotateToAngle.reset(new JoystickButton(driver.get(), rotateToAngleBtn));
    rotateToAngle->WhenPressed(new RotateToAngle(10));

    enableDriving.reset(new JoystickButton(driver.get(), enableDrivingBtn));
    enableDriving->WhenPressed(new EnableDriving());





    // SmartDashboard Buttons
    SmartDashboard::PutData("Traction Mode", new ChangeMode(7));
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getDriver() {
   return driver;
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
