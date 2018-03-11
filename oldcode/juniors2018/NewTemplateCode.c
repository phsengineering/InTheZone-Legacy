#pragma config(Sensor, in1,    Gyro,           sensorNone)
#pragma config(Sensor, in2,    potentiometer,  sensorNone)
#pragma config(Sensor, dgtl1,  Jumper1,        sensorDigitalIn)
#pragma config(Sensor, dgtl2,  Jumper2,        sensorDigitalIn)
#pragma config(Sensor, dgtl3,  Jumper3,        sensorDigitalIn)
#pragma config(Sensor, dgtl4,  Jumper4,        sensorDigitalIn)
#pragma config(Sensor, dgtl5,  Jumper5,        sensorDigitalIn)
#pragma config(Sensor, dgtl6,  Quad,           sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  mobileGoal,     sensorDigitalOut)
#pragma config(Sensor, dgtl9,  mobileGoal2,    sensorDigitalOut)
#pragma config(Sensor, dgtl10, Quad2,          sensorQuadEncoder)
#pragma config(Motor,  port2,           leftside,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightside,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           fly,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           top,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           bottom,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Four,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/


int mobile;
int four;
task Quadreset()
{
	SensorValue[Quad]=0;
	SensorValue[Quad2]=0;
}
void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	// ..........................................................................
	// Insert user code here.
	// ..........................................................................
	// Remove this function call once you have "real" code.
	if(SensorValue[Jumper1]==0)
	{
		motor(top)=127;
		motor(bottom)=127;
		wait(1);//change
		motor(top)=0;
		motor(bottom)=0;
		motor(leftside)=127;
		motor(rightside)=127;
		untilEncoderCounts( SensorValue[Quad] > 60 || SensorValue[Quad2] > 60); //change
		motor(leftside)=0;
		motor(rightside)=0;
		motor(fly)=127;
		wait(.5);
		motor(fly)=0;
		startTask(Quadreset);
		motor(leftside)=-127;
		motor(rightside)=-127;
		untilEncoderCounts( SensorValue[Quad] < -60 || SensorValue[Quad2] < -60); //change
		motor(top)=-127;
		motor(bottom)=-127;
		wait(1); //change
		motor(top)=0;
		motor(bottom)=0;
		startTask(Quadreset);
		motor(rightside)=127;
		untilEncoderCounts( SensorValue[Quad] < -60 || SensorValue[Quad2] > 60); //change
		startTask(Quadreset);
		motor(leftside)=127;
		untilEncoderCounts( SensorValue[Quad] > 60 || SensorValue[Quad2] > 60); //change
		startTask(Quadreset);
		SensorValue[mobileGoal]=1;
		SensorValue[mobileGoal2]=1;
		motor(leftside)=-127;
		motor(rightside)=-127;
		untilEncoderCounts( SensorValue[Quad] < -60 || SensorValue[Quad2] < -60); //change
		startTask(Quadreset);
		motor(rightside)=127;
		untilEncoderCounts( SensorValue[Quad] < -120 || SensorValue[Quad2] > 120); //change
		startTask(Quadreset);
		motor(leftside)=127;
		untilEncoderCounts( SensorValue[Quad] > 60 || SensorValue[Quad2] > 60); //change
		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;
		SensorValue[mobileGoal]=0;
		SensorValue[mobileGoal2]=0;
		motor(leftside)=-127;
		motor(rightside)=-127;
		untilEncoderCounts(SensorValue[Quad] < -60 || SensorValue[Quad2] < -60); //change
		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;
	}
	if(SensorValue[Jumper2]==0)
	{
		motor(top)=127;
		motor(bottom)=127;
		wait(1);//change
		motor(top)=0;
		motor(bottom)=0;
		motor(leftside)=127;
		motor(rightside)=127;
		untilEncoderCounts( SensorValue[Quad] > 60 || SensorValue[Quad2] > 60); //change
		motor(leftside)=0;
		motor(rightside)=0;
		motor(fly)=-127;
		wait(.5);
		motor(fly)=0;
		startTask(Quadreset);
		motor(leftside)=-127;
		motor(rightside)=-127;
		untilEncoderCounts( SensorValue[Quad] < -60 || SensorValue[Quad2] < -60); //change
		startTask(Quadreset);
		motor(top)=-127;
		motor(bottom)=-127;
		wait(1); //change
		motor(top)=0;
		motor(bottom)=0;
		motor(rightside)=127;
		untilEncoderCounts( SensorValue[Quad] < -60 || SensorValue[Quad2] > 60); //change
		startTask(Quadreset);
		motor(leftside)=127;
		untilEncoderCounts( SensorValue[Quad] > 60 || SensorValue[Quad2] > 60); //change
		startTask(Quadreset);
		SensorValue[mobileGoal]=1;
		SensorValue[mobileGoal2]=1;
		motor(leftside)=-127;
		motor(rightside)=-127;
		untilEncoderCounts( SensorValue[Quad] < -60 || SensorValue[Quad2] < -60); //change
		startTask(Quadreset);
		motor(rightside)=127;
		untilEncoderCounts( SensorValue[Quad] < -120 || SensorValue[Quad2] > 120); //change
		startTask(Quadreset);
		motor(leftside)=127;
		untilEncoderCounts( SensorValue[Quad] > 60 || SensorValue[Quad2] > 60); //change
		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;
		SensorValue[mobileGoal]=0;
		SensorValue[mobileGoal2]=0;
		motor(leftside)=-127;
		motor(rightside)=-127;
		untilEncoderCounts( SensorValue[Quad] < -60 || SensorValue [Quad2] < -60); //change
		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;
	}

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

	mobile=1;
	four=1;
	while(1==1)
	{

		motor[rightside] = vexRT[Ch2];
		motor[leftside] = vexRT[Ch3];
		if(vexRT[Btn5UXmtr2]==1)
		{
			motor(fly)=127;
		}

		else if(vexRT[Btn5DXmtr2]==1)
		{
			motor(fly)=-127;

		}
		else
		{
			motor(fly)=0;
		}

		if(vexRT[Btn6UXmtr2]==1)
		{
			motor(top)=127;
			motor(bottom)=-127;
		}

		else if(vexRT[Btn6DXmtr2]==1)
		{
			motor(top)=-127;
			motor(bottom)=127;
		}
		else
		{
			motor(top)=0;
			motor(bottom)=0;
		}

		//Rhea is my best friend :)
		//elephants are great & Dan is a butt
		//zezak I don't know how to code
		//MobileGoalDown
		if(vexRT[Btn7D]==1)
		{
			SensorValue[mobileGoal]=0;
			SensorValue[mobileGoal2]=0;

		}
		//MobileGoalUp
		if(vexRT[Btn7U]==1)
		{
			SensorValue[mobileGoal]=1;
			SensorValue[mobileGoal2]=1;
		}
		/*	if(vexRT[Btn8D]==1)
		{
		if(four==1)
		{
		motor(Four)=127;
		untilPotentiometerGreaterThan(4000, potentiometer);
		four=0;
		}
		if(four==0)
		{
		motor(Four)=-127;
		untilPotentiometerLessThan(2000, potentiometer);
		four=0;

		}
		} */
	}

}