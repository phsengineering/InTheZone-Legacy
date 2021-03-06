#pragma config(Sensor, dgtl1,  solenoid1,      sensorDigitalOut)
#pragma config(Sensor, dgtl2,  solenoid2,      sensorDigitalOut)
#pragma config(Sensor, dgtl3,  motenc1,        sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  motenc2,        sensorQuadEncoder)
#pragma config(Motor,  port3,           LeftBase,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RightBase,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LiftRight1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftRight2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LiftLeft1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           LiftLeft2,     tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/



#pragma platform(VEX)
//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	motor[port2] = 0;       //drive system using channels 2 and 3
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	SensorValue(solenoid1) = 1;
	SensorValue(solenoid2) = 1;
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


task autonomous()
{
	while(SensorValue[motenc1] == 435 && SensorValue[motenc2] == 0)
	{
		motor[LeftBase] = 127;
		motor[RightBase] = 0;
	}
	nMotorEncoder[motenc1] = 0;
	nMotorEncoder[motenc2] = 0;
	while(SensorValue[motenc1] == 1833 && SensorValue[motenc2] == 1833)
	{
		motor[LeftBase] = 127;
		motor[RightBase] = 127;
	}
	nMotorEncoder[motenc1] = 0;
	nMotorEncoder[motenc2] = 0;
	while(SensorValue[motenc1] == 1740 && SensorValue[motenc2] == -1740)
	{
		motor[LeftBase] = 127;
		motor[RightBase] = -127;
	}
	nMotorEncoder[motenc1] = 0;
	nMotorEncoder[motenc2] = 0;
	while(SensorValue[motenc1] == 1833 && SensorValue[motenc2] == 1833)
	{
		motor[LeftBase] = 127;
		motor[RightBase] = 127;
	}
	nMotorEncoder[motenc1] = 0;
	nMotorEncoder[motenc2] = 0;
	while(SensorValue[motenc1] == 435 && SensorValue[motenc2] == 0)
	{
		motor[LeftBase] = 127;
		motor[RightBase] = 0;
	}
	nMotorEncoder[motenc1] = 0;
	nMotorEncoder[motenc2] = 0;
	while(SensorValue[motenc1] == 1296 && SensorValue[motenc2] == 1296)
	{
		motor[LeftBase] = 127;
		motor[RightBase] = 127;
	}
	nMotorEncoder[motenc1] = 0;
	nMotorEncoder[motenc2] = 0;
	while(SensorValue[motenc1] == 870 && SensorValue[motenc2] == 0)
	{
		motor[LeftBase] = 127;
		motor[RightBase] = 0;
	}
	nMotorEncoder[motenc1] = 0;
	nMotorEncoder[motenc2] = 0;
	while(SensorValue[motenc1] == 1146 && SensorValue[motenc2] == 1146)
	{
		motor[LeftBase] = 127;
		motor[RightBase] = 127;
	}
	//motor[port5] = 127;
	//untilPotentiometerGreaterThan(1023,in1);
	SensorValue(solenoid1) = 1;// remember that flipped 0 and 1 in lines 61,62,70,71
	//motor[port5] = 0;
	SensorValue(solenoid2) = 1; //drive system using channels 2 and 3
	wait(0.5);
	motor[port3]  = 127;
	motor[port4] = 127;
	wait(2.5);       //drive system using channels 2 and 3
	motor[port3] = 0;
	motor[port4] = 0;
	wait(0.5);
	SensorValue(solenoid1) = 0;
	SensorValue(solenoid2) = 0; //drive system using channels 2 and 3
	motor[port3] = 0;
	motor[port4] = 0;

}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// User control code here, inside the loop

	while(true)
	{
		motor[port3]  = vexRT [Ch2];//drive system using channels 2 and 3
		motor[port4] = vexRT [Ch3];
		if(vexRT[Btn6U] == 1)       	// If button 6U is pressed:
		{
			SensorValue[solenoid2] = 1;			// activate the solenoid.
			SensorValue[solenoid1] = 1;
		}
		if(vexRT[Btn5U] == 1)							// If button 5U is pressed
		{
			SensorValue[solenoid2] = 0;			// ...deactivate the solenoid.
			SensorValue[solenoid1] = 0;
		}
		while(1==1)//while loop for lift system
		{
			if(vexRT[Btn6D] == 1)//move up lift
			{
				motor(port6) = 127;
				motor(port7) = 127;
				motor(port8) = -127;
				motor(port9) = -127;
			}
			else if (vexRT[Btn5D] == 1)//move down lift
			{
				motor(port6) = -127;
				motor(port7) = -127;
				motor(port8) = 127;
				motor(port9) = 127;
			}
			else //pause if no button is pressed
			{
				motor(port6) = 0;
				motor(port7) = 0;
				motor(port8) = 0;
				motor(port9) = 0;
			}
		}
		while(1==1){ //C;aw while loop
			if(vexRT[Btn8L] == 1){
				motor(port5) = 127;
			}
			if(vexRT[Btn8U] == 1){
				motor(port5) = -127;
			}
			if(vexRT[Btn8U] == 0 && vexRT[Btn8L] == 0){
				motor(port5) = 0; 
			}
		}
	}
}
