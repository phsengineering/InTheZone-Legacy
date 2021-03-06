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

	startMotor(Leftflywheel, 80);
	startMotor(Rightflywheel, 80);
	wait(3);
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
	wait(2);
	startMotor(Intake, 127);
	wait(1);
	startMotor(Intake, 0);
	wait(2);
	startMotor(Intake, 127);
	wait(1);
	startMotor(Intake, 0);
	wait(2);
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









task basicflywheel()
{

	if(vexRT[Btn8U]==1)
	{
		motor(Leftflywheel) = 80;
		motor(Rightflywheel) = 80;
	}

	else if (vexRT[Btn8U]==1 && vexRT[Btn8R]==1)
	{
		motor(Leftflywheel) = 75;
		motor(Rightflywheel) = 75;

	}

	else if(vexRT[Btn8R]==1)
	{
		motor(Leftflywheel) = 70;
		motor(Rightflywheel) = 70;
	}

	else if(vexRT[Btn8L]==1)
	{
		motor(Leftflywheel) = 52;
		motor(Rightflywheel) = 52;
	}

	else if(vexRT[Btn8D]==1)
	{
		motor(Leftflywheel) = 40;
		motor(Rightflywheel) = 40;
	}

	else
	{
		motor(Leftflywheel) = 0;
		motor(Rightflywheel) = 0;
	}

}





task usercontrol()//main task runs and starts the three sub tasks which run simultaneously
{

	while(vexRT[Btn8U]==1 || vexRT[Btn8D]==1 || vexRT[Btn8R]==1 || vexRT[Btn8L]==1)
	{//if only the flywheel button is being used then only run the flywheel code
		startTask(basicflywheel);
	}

		while(vexRT[Ch2]>0 || vexRT[Ch2]<0 || vexRT[Ch3]>0 || vexRT[Ch3]<0)
	{//if only the joysticks are moved, then only run the drive code
		startTask(drivetrain);
	}


	while((vexRT[Ch2]>0 || vexRT[Ch2]<0 || vexRT[Ch3]>0 || vexRT[Ch3]<0)&&(vexRT[Btn6U]==1 || vexRT[Btn6D]==1))
	{//if the joysticks are being moved and the intake button is being pressed then only run both those codes

	startTask(drivetrain);
	startTask(intakes);

	}

	while(vexRT[Btn5D]==1 || vexRT[Btn5U]==1)
	{//if only the aim button is being pressed, then only use the aim code

	startTask(aimcontrol);

	}

	while(vexRT[Btn6U]==1 || vexRT[Btn6D]==1)
	{//if only the intakes are being used, then only use the intake code

		startTask(intakes);

	}

		while((vexRT[Btn6U]==1 || vexRT[Btn6D]==1) && (vexRT[Btn8U]==1 || vexRT[Btn8D]==1 || vexRT[Btn8R]==1 || vexRT[Btn8L]==1))
	{//if only the intakes and the flywheel are being used, then only run those codes
		startTask(intakes);
		startTask(basicflywheel);
	}

			while((vexRT[Btn6U]==1 || vexRT[Btn6D]==1) && (vexRT[Btn8U]==1 || vexRT[Btn8D]==1 || vexRT[Btn8R]==1 || vexRT[Btn8L]==1) &&(vexRT[Btn5D]==1 || vexRT[Btn5U]==1))
	{//etc I think you get it
		startTask(intakes);
		startTask(basicflywheel);
		startTask(aimcontrol);

	}



	while((vexRT[Btn6U]==1 || vexRT[Btn6D]==1) && (vexRT[Btn5D]==1 || vexRT[Btn5U]==1))
	{//intakes and aiming
		startTask(intakes);
		startTask(aimcontrol);

	}

	while((vexRT[Btn6U]==1 || vexRT[Btn6D]==1) && (vexRT[Btn5D]==1 || vexRT[Btn5U]==1) && (vexRT[Ch2]>0 || vexRT[Ch2]<0 || vexRT[Ch3]>0 || vexRT[Ch3]<0))
	{ //intakes moving and aiming
		startTask(intakes);
		startTask(aimcontrol);
		startTask(drivetrain);
	}






}
