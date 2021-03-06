#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    LeftEncoder,    sensorNone)
#pragma config(Sensor, dgtl1,  LeftEn,         sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  RightEn,        sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  LeftLiftEN,     sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  RightLiftEN,    sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  Solenoid1,      sensorDigitalOut)
#pragma config(Sensor, I2C_1,  RightLiftEn,    sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           Left1,         tmotorVex393_MC29, openLoop, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port3,           Left2,         tmotorVex393_MC29, openLoop, reversed, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port4,           Left3,         tmotorVex393_MC29, openLoop, reversed, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port5,           Right1,        tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port6,           Right2,        tmotorVex393_MC29, openLoop, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port7,           Right3,        tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port8,           LeftLift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           RightLift,     tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, I2C_1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
/////////////////////////////////////////////////////////////////////////////////////////

//Methods:

bool claw = true

void RemoteControl()
{
while(1==1)
{

//Movement System: Use the two joysticks to drive the robot
		motor(Left1) = vexRT[Ch3];
		motor(Left2) = vexRT[Ch3];
		motor(Left3) = vexRT[Ch3];
		motor(Right1) = vexRT[Ch2];
		motor(Right2) = vexRT[Ch2];
		motor(Right3) = vexRT[Ch2];

//Lift System: Use Buttons 5U and 5D to operate lift
	if(vexRT[Btn5U]==1)
	{
		motor(LeftLift)=127;
		motor(RightLift)=127;
	}
	else if(vexRT[Btn5D]==1)
	{
		motor(RightLift)=-127;
		motor(LeftLift)=-127;
	}
	else
	{
		motor(RightLift)=0;
		motor(LeftLift)=0;
	}

//Pneumatic Claw System: Use the buttons 6U and 6D to operate the claw

	SensorValue[Solenoid1]=1;
	if (vexRT[Btn6D])
	{
	claw = true;
	}
	if (vexRT[Btn6U])
	{
	claw = false;
	}
	if (claw)
	{
	SensorValue[Solenoid1]=1;
	}
	else
	{
	SensorValue[Solenoid1]=0;
	claw = false;
	}
}
}







/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
SensorValue[RightEn]=0;
SensorValue[RightLiftEn]=0;
}

/////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{

SensorValue[Solenoid1]=0;

//lift up
	motor(LeftLift)=127;
	motor(RightLift)=127;
	wait1Msec(1350);
	motor(LeftLift)=0;
	motor(RightLift)=0;
	wait1Msec(100);

//go down a bit
	motor(LeftLift)=-127;
	motor(RightLift)=-127;
	wait1Msec(150);
	motor(LeftLift)=0;
	motor(RightLift)=0;
	wait1Msec(100);

//drop off cube
SensorValue[Solenoid1]=1;
wait1Msec(100);


//back off
	motor(Left1)=-127;
	motor(Left2)=-127;
	motor(Left3)=-127;
	motor(Right1)=-127;
	motor(Right2)=-127;
	motor(Right3)=-127;
	wait1Msec(200);
	motor(Left1)=0;
	motor(Left2)=0;
	motor(Left3)=0;
	motor(Right1)=0;
	motor(Right2)=0;
	motor(Right3)=0;
	wait1Msec(100);

}

/////////////////////////////////////////////////////////////////////////////////////////








/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
RemoteControl();
}
