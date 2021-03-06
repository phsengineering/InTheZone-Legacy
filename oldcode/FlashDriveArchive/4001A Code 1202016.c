#pragma config(Sensor, dgtl10, GREEN,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, YELLOW,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, RED,            sensorLEDtoVCC)
#pragma config(Motor,  port2,           Rightflywheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           Leftflywheel,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           Frontleftwheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Backleftwheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Frontrightwheel, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           Backrightwheel, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           Intake,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{

	startMotor(Leftflywheel, 82);
	startMotor(Rightflywheel, 82);
	wait(4);
	startMotor(Intake, 127);
	wait(1);
	startMotor(Intake, 0);
	wait(4);
	startMotor(Intake, 127);
	wait(2);
	startMotor(Intake, 0);
	wait(1);
	startMotor(Intake, 127);
	wait(3);
	startMotor(Intake, 0);
	wait(1);
	startMotor(Intake, 127);
	wait(1);
	startMotor(Intake, 0);
	wait(1);
	startMotor(Intake, 127);
	wait(1);
	startMotor(Intake, 0);
	wait(1);
	startMotor(Intake, 127);
	wait(1);
	startMotor(Intake, 0);
	wait(1);
	startMotor(Intake, 127);
	wait(1);

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////



task drivetrain()//drive train controls

{
	motor[Frontrightwheel] = vexRT[Ch2];
	motor[Backrightwheel] = vexRT[Ch2];
	motor[Frontleftwheel] = vexRT[Ch3];
	motor[Backleftwheel] = vexRT[Ch3];
}

task intakes ()// controller for intake runs as a seperate task
{
	if(vexRT[Btn6U]==1)
	{
		motor(Intake) = 127;
	}
	else if(vexRT[Btn6D]==1)
	{
		motor(Intake) = -127;
	}
	else
	{
		motor(Intake) = 0;
	}
}

	int flywheelspeed;
	int shootmode;//1 = hold to fire. 0 = press to toggle
	int flywheelon; //it is used



task flywheel()//remote controllers for fly wheel
{

	int flywheelspeed;
	int shootmode;//1 = hold to fire. 0 = press to toggle
	int flywheelon;







	if(vexRT[Btn8U]==1)
	{
		flywheelspeed++;
		flywheelspeed++;
	}

	if(vexRT[Btn8D]==1)
	{
		flywheelspeed--;
		flywheelspeed--;
	}

	if(vexRT[Btn8L]==1)
	{
		flywheelspeed--;


	}

	//FAILSAFES! YAY EXPECTING ERRORS!

	if(flywheelspeed==28)//minimum speed
	{
		flywheelspeed = 30;
	}

	else if(flywheelspeed==129)
	{
		flywheelspeed = 127;
	}


	if(flywheelspeed>65)
	{
		turnLEDOn(RED);

		turnLEDOff(GREEN);
		turnLEDOff(YELLOW);
	}

	else if(flywheelspeed<76)
	{
		turnLEDOn(GREEN);

		turnLEDOff(RED);
		turnLEDOff(YELLOW);
	}

	else
	{
		turnLEDOn(YELLOW);

		turnLEDOff(GREEN);
		turnLEDOff(RED);
	}

	if (vexRT[Btn5U]==1)
	{
	shootmode = 0;
	}

	if (vexRT[Btn5D]==1)
	{
	shootmode = 1;
	}




	while (shootmode==0)
	{
		startTask(flywheel);


		while(flywheelon==0)
		{

			startTask(flywheel);

			if(vexRT[Btn8R]==1)
			{

				motor(Leftflywheel) = flywheelspeed;
				motor(Rightflywheel) = flywheelspeed;

				flywheelon = 1;
			}
		}

		while(flywheelon==1)
		{
			startTask(flywheel);

			if(vexRT[Btn8R]==1)
			{


				motor(Leftflywheel) = 0;
				motor(Rightflywheel) = 0;

				flywheelon = 0;
			}

		}
	}


	while (shootmode==1)
	{
		startTask(flywheel);

		if(vexRT[Btn8R]==1)
		{
			motor(Leftflywheel) = flywheelspeed;
			motor(Rightflywheel) = flywheelspeed;
		}
		else
		{
			motor(Leftflywheel) = 0;
			motor(Rightflywheel) = 0;
		}
	}

}

task usercontrol()//main task runs and starts the three sub tasks which run simultaneously
{

	shootmode=1 ;
	flywheelspeed = 74;

	while(1==1)
	{
		startTask(drivetrain);
		startTask(flywheel);
		startTask(intakes);



	}
}
