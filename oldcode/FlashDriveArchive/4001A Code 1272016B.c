#pragma config(Sensor, dgtl6,  Switch,         sensorTouch)
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
#pragma config(Motor,  port9,           Angler,        tmotorVex393_MC29, openLoop)
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

	if(vexRT[Btn7L]==1)
	{
		motor[Frontrightwheel] = -30;
		motor[Backrightwheel] = -30;
		motor[Frontleftwheel] = 30;
		motor[Backleftwheel] = 30;

	}


	else if(vexRT[Btn7R]==1)
	{
		motor[Frontrightwheel] = 30;
		motor[Backrightwheel] = 30;
		motor[Frontleftwheel] = -30;
		motor[Backleftwheel] = -30;

	}
	else
	{
		motor[Frontrightwheel] = 0;
		motor[Backrightwheel] = 0;
		motor[Frontleftwheel] = 0;
		motor[Backleftwheel] = 0;

	}
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





task AngleAdjust()
{

	if(vexRT[Btn5U]==1)
	{
		motor(Angler) = -50;
	}


	else
	{
		motor(Angler) = 0;
	}
}



task feedmodecode()//toggles if the robot is being designed to shoot balls from home plate
{

	int feedmodeon;


	while(feedmodeon==0)
	{

		if(vexRT[Btn7U]==1)
		{

			motor(Leftflywheel) = 79;
			motor(Rightflywheel) = 79;


			feedmodeon = 1;//controls toggle
		}
	}

	while(feedmodeon==1)
	{

		if(vexRT[Btn7U]==1)
		{

			motor(Leftflywheel) = 0;
			motor(Rightflywheel) = 0;


			feedmodeon = 0;
		}
	}
}


task notifications()
{

int shootmode;//1 = hold to fire. 0 = press to toggle
int feedmodeon;

	while(shootmode==0)
	{
		turnLEDOn(RED);

	}

while(shootmode==1)
	{
		turnLEDOn(GREEN);

	}
while(feedmodeon==1)
{
	turnLEDOn(YELLOW);
}
while(feedmodeon==0)
{
	turnLEDOff(YELLOW);
}

}





  //////////////////////////////////////////////////////
////////////////*****FLYWHEELCODE******////////////////////
  /////////////////////////////////////////////////////

task flywheel()
{
	int shootmode;//1 = hold to fire. 0 = press to toggle



	////////////TOGGLE MODE////////////////

	while (shootmode==0)
	{


	int flywheelon; //it is used

		while(flywheelon==0)
		{
			int shootmode;//1 = hold to fire. 0 = press to toggle
			int flywheelon; //it is used

			if (vexRT[Btn7D]==1)
			{

				shootmode = 1;

			}



			if(vexRT[Btn8U]==1)
			{

				motor(Leftflywheel) = 80;
				motor(Rightflywheel) = 80;



				flywheelon = 1;
			}

			if(vexRT[Btn8D]==1)
			{

				motor(Leftflywheel) = 50;
				motor(Rightflywheel) = 50;



				flywheelon = 1;
			}

			if(vexRT[Btn8R]==1)
			{

				motor(Leftflywheel) = 75;
				motor(Rightflywheel) = 75;



				flywheelon = 1;
			}

			if(vexRT[Btn8L]==1)
			{

				motor(Leftflywheel) = 64;
				motor(Rightflywheel) = 64;



				flywheelon = 1;
			}

		}
		/////////////////////////////////TOGGLE MODE CONT/////////////////////
		while(flywheelon==1)
		{
			int shootmode;//1 = hold to fire. 0 = press to toggle
			int flywheelon; //it is used

			if (vexRT[Btn7D]==1)
			{

				shootmode = 1;

			}

			if(vexRT[Btn8R]==1)
			{

				motor(Leftflywheel) = 0;
				motor(Rightflywheel) = 0;



				flywheelon = 0;
			}
			if(vexRT[Btn8U]==1)
			{

				motor(Leftflywheel) = 0;
				motor(Rightflywheel) = 0;



				flywheelon = 0;
			}
			if(vexRT[Btn8L]==1)
			{

				motor(Leftflywheel) = 0;
				motor(Rightflywheel) = 0;



				flywheelon = 0;
			}
			if(vexRT[Btn8D]==1)
			{

				motor(Leftflywheel) = 0;
				motor(Rightflywheel) = 0;



				flywheelon = 0;
			}

		}

}

	//////////////PRESS AND HOLD MODE///////////////////////////

	while (shootmode==1)//when it is in push and hold mode
	{
		int shootmode;//1 = hold to fire. 0 = press to toggle


		if (vexRT[Btn7D]==1)//if the toggle button is pushed in this mode do this
		{

			shootmode = 0;

		}

		if(vexRT[Btn8U]==1)
		{
			motor(Leftflywheel) = 80;
			motor(Rightflywheel) = 80;
		}
		else if(vexRT[Btn8D]==1)
		{
			motor(Leftflywheel) = 50;
			motor(Rightflywheel) = 50;
		}
		else if(vexRT[Btn8R]==1)
		{
			motor(Leftflywheel) = 75;
			motor(Rightflywheel) = 75;
		}
		else if(vexRT[Btn8L]==1)
		{
			motor(Leftflywheel) = 64;
			motor(Rightflywheel) = 64;
		}
		else
		{
			motor(Leftflywheel) = 0;
			motor(Rightflywheel) = 0;
		}
	}

}

task tiltstop()
{

		if(vexRT[Btn5D]==1 && SensorValue(Switch)==0) //when the button isnt pushed do this
		{
		motor(Angler) = 55;
		}
		else if(vexRT[Btn5D]==1 && SensorValue(Switch)==1)//when the switch is pressed down, the down button does nothing
		{
		motor(Angler) = 0;
		}
	}


task usercontrol()//main task runs and starts the many sub tasks which run simultaneously
{
	int shootmode;//1 = hold to fire. 0 = press to toggle
	int flywheelon; //it is used
	int feedmodeon;

	shootmode=1;
	flywheelon=0;
	feedmodeon=0;

	while(1==1)
	{

		startTask(tiltstop);
		startTask(drivetrain);
		startTask(flywheel);
		startTask(intakes);
		startTask(AngleAdjust);
		startTask(feedmodecode);
		startTask(notifications);

	}
}






//NOTES TO SELF
//
//If the mode toggle doesnt work again be sure to make each mode a differant task and each button toggles wether which task runs or not
//
//
//
//
//
//
//
//
//
//
