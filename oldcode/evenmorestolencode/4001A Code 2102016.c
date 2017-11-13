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

int mode = 1;


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

	startMotor(Leftflywheel, 80);
	startMotor(Rightflywheel, 80);
	wait(1);
	startMotor(Intake, 100);

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////





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

task aimcontrol()
{
	if(vexRT[Btn5U]==1)
	{
		motor(Angler) = -40;
	}

	else
	{
			motor(Angler) = 0;
	}

	if(vexRT[Btn5D]==1 && SensorValue(Switch)==0) //when the button isnt pushed do this
	{
	motor(Angler) = 45;
	}
	else if(vexRT[Btn5D]==1 && SensorValue(Switch)==1)//when the switch is pressed down, the down button does nothing
	{
	motor(Angler) = 0;
	}



}

task togglewheel()
{

mode = 0;

if(vexRT[Btn7U]==1)
{
	motor(Leftflywheel) = 82;
	motor(Rightflywheel) = 82;
}

if(vexRT[Btn7R]==1)
{
	motor(Leftflywheel) = 80;
	motor(Rightflywheel) = 80;
}

if(vexRT[Btn7D]==1)
{
	motor(Leftflywheel) = 78;
	motor(Rightflywheel) = 78;
}

if(vexRT[Btn7L]==1)
{
	motor(Leftflywheel) = 0;
	motor(Rightflywheel) = 0;
}
}



task basicflywheel()
{

	mode = 1;

	if(vexRT[Btn8U]==1)
	{
		motor(Leftflywheel) = 80;
		motor(Rightflywheel) = 80;
	}

	else if (vexRT[Btn8U]==1 && vexRT[Btn8R]==1)
	{
		motor(Leftflywheel) = 73;
		motor(Rightflywheel) = 73;

	}

	else if(vexRT[Btn8R]==1)
	{
		motor(Leftflywheel) = 65;
		motor(Rightflywheel) = 65;
	}

	else if(vexRT[Btn8L]==1)
	{
		motor(Leftflywheel) = 52;
		motor(Rightflywheel) = 52;
	}

	else if(vexRT[Btn8D]==1)
	{
		motor(Leftflywheel) = 42;
		motor(Rightflywheel) = 42;
	}

	else
	{
		motor(Leftflywheel) = 0;
		motor(Rightflywheel) = 0;
	}

}





task usercontrol()//main task runs and starts sub tasks which run simultaneously
{
	while(1==1)
	{
		if(vexRT[Btn8U]==1 || vexRT[Btn8D]==1 || vexRT[Btn8R]==1 || vexRT[Btn8L]==1)
	{//if the flywheel button is being used then run the flywheel code
		startTask(basicflywheel);
		turnLEDOn(YELLOW);
	}

		else if(vexRT[Btn8U]==0 && vexRT[Btn8D]==0 && vexRT[Btn8R]==0 && vexRT[Btn8L]==0)
	{//if the flywheel button is not being used then turn off the led

		stopTask(basicflywheel);
		turnLEDOff(YELLOW);

		if(mode==1)
		{
			stopMotor(Rightflywheel);
			stopMotor(Leftflywheel);

		}


	}

		if(vexRT[Btn7U]==1 || vexRT[Btn7D]==1 || vexRT[Btn7R]==1 || vexRT[Btn7L]==1)
	{//if the flywheel button is being used then run the flywheel code
		startTask(togglewheel);
		turnLEDOn(YELLOW);
	}


		else if(vexRT[Btn7U]==0 && vexRT[Btn7D]==0 && vexRT[Btn7R]==0 && vexRT[Btn7L]==0)
	{//if the flywheel button is not being used then dont run the flywheel code

		stopTask(togglewheel);
		turnLEDOff(YELLOW);
	}


	if(vexRT[Ch2]>0 || vexRT[Ch2]<0 || vexRT[Ch3]>0 || vexRT[Ch3]<0 || vexRT[Ch4]>0 || vexRT[Ch4]<0 || vexRT[Ch1]>0 || vexRT[Ch1]<0)
	{//if the joysticks are moved, then run the drive code
		motor[Frontrightwheel] = vexRT[Ch2];
		motor[Backrightwheel] = vexRT[Ch2];
		motor[Frontleftwheel] = vexRT[Ch3];
		motor[Backleftwheel] = vexRT[Ch3];

		turnLEDOn(GREEN);
	}

		else if(vexRT[Ch2]==0 && vexRT[Ch3]==0)
	{//if the joysticks are not being moved, then turn off the led
		turnLEDOff(GREEN);
	}

	if(vexRT[Btn5D]==1 || vexRT[Btn5U]==1)
	{//if the aim button is being pressed, then use the aim code

	startTask(aimcontrol);

	}

	else if(vexRT[Btn5D]==1 || vexRT[Btn5U]==1)
	{//if the aim button is being pressed, then use the aim code

	stopTask(aimcontrol);
	stopMotor(Angler);

	}


	if(vexRT[Btn6U]==1 || vexRT[Btn6D]==1)
	{//if the intakes are being used, then use the intake code

	startTask(intakes);
	turnLEDOn(RED);

	}

	else if(vexRT[Btn6U]==0 && vexRT[Btn6D]==0)
	{//if the intakes are not being used, then turn off the led

	stopTask(intakes);

	motor(Intake)=0;

	turnLEDOff(RED);

	}




}

}
