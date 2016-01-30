/*
 * init.h
 *
 *  Created on: Jan 28, 2016
 *      Author: Matthew
 */

#ifndef INIT_H_
#define INIT_H_
#define ducksperpulse 0.08707563025
#include "WPILib.h"
#include <string>
#include <iostream>

class Robot: public IterativeRobot {
private:
	Joystick *stick; // Joystick plugged in first
	Joystick *stick2; //Joystick plugged in second

	RobotDrive *drive;	// Pointer to a drive

	JoystickButton *buttonA; // All the button pointers!
	JoystickButton *buttonB;
	JoystickButton *buttonX;
	JoystickButton *buttonY;
	JoystickButton *buttonLB;
	JoystickButton *buttonRB;
	JoystickButton *buttonBack;
	JoystickButton *buttonStart;
	JoystickButton *buttonLS;
	JoystickButton *buttonRS;
	JoystickButton *buttonA2; // Button pointers for joystick 2
	JoystickButton *buttonB2;
	JoystickButton *buttonX2;
	JoystickButton *buttonY2;
	JoystickButton *buttonLB2;
	JoystickButton *buttonRB2;
	JoystickButton *buttonBack2;
	JoystickButton *buttonStart2;
	JoystickButton *buttonLS2;
	JoystickButton *buttonRS2; // End button pointers

	Encoder *LEnc; // Pointer to left encoder
	Encoder *REnc; // Pointer to right encoder
	Encoder *ArmEnc; // Pointer to Arm encoder

	DoubleSolenoid *sArm;
	DoubleSolenoid *sLifter;
	DoubleSolenoid *sPoker;
	DoubleSolenoid *sLever;

	DigitalInput *PhoSen;

	VictorSP *winchmot; // PROPERLY NAMED pointer to winch motor

	Compressor *compress; // Pointer to compressor

	bool bA, bB, bX, bY, bLB, bRB, bBack, bStart, bLS, bRS, bA2, bB2, bX2, bY2, bLB2, bRB2, bBack2, bStart2, bLS2, bRS2; // Booleans on the states of each button

	float RTrig, LTrig, Trig; // Trigger variable values

	double LaxisX, LaxisY; // Declaring variables for joystick axes
	double RaxisX, RaxisY;

	bool yn; // Boolean for state machine
	bool arms, lever, poker, lifter; // Variables to display where their respective parts are
	bool sensor;
	int currentState;

	enum states {
		IDLE,
		MV_TO_CAP,
		WT_FOR_BALL,
		HOLD_BALL,
		UNLOAD
	};

	float setWinch;
	float winchHold;

	void RobotInit(); // Scopes/initialization for robot functions
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void checkbuttons();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif /* INIT_H_ */