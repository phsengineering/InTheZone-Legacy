#pragma config(Sensor, dgtl1,  green1,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  green2,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  green3,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  green4,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl5,  yellow1,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  yellow2,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  yellow3,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  yellow4,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl9,  red1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, red2,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, red3,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, red4,           sensorLEDtoVCC)
#pragma config(Motor,  port2,           Backrightwheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           Frontrightwheel, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           Backleftwheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Frontleftwheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           Rightflywheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           Leftflywheel,  tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
/*#pragma autonomousDuration(20)
#pragma userControlDuration(120)*/
int flywheelspeed = 62;
float lednum = 7;

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	bStopTasksBetweenModes = true;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
/////////////////////////////////////////////////////////////////////////////////////////

int click_to_autonomous = 0;

task autonomous()
{
	startMotor(Leftflywheel, 50);//Start flywheels up to speed
	startMotor(Rightflywheel, 50);//Start flywheels up to speed
	wait(3.75);//Start flywheels up to speed wait for 1st ball
	startMotor(Intake, 100);//Load first ball
	wait(0.5);//Launch 1
	stopMotor(Intake);
	startMotor(Leftflywheel, 52);//Start flywheels up to speed
	startMotor(Rightflywheel, 52);//Start flywheels up to speed
	wait(2.25);//Wait for 2nd ball
	startMotor(Intake, 100);//2nd ball
	wait(1);//Shoot 2nd ball
	stopMotor(Intake);
	startMotor(Leftflywheel, 50);//Start flywheels up to speed
	startMotor(Rightflywheel, 50);//Start flywheels up to speed
	wait(2.5);//Wait for 3rd ball
	startMotor(Intake, 100);
	wait(0.5);
	stopMotor(Intake);
	wait(3);
	startMotor(Intake, 100);
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
/////////////////////////////////////////////////////////////////////////////////////////
task ledees()
{
	turnLEDOff(green1 ); turnLEDOff(green2); turnLEDOff(green3 );
	turnLEDOff(green4 ); turnLEDOff(yellow1 ); turnLEDOff(yellow2 );
	turnLEDOff(yellow3); turnLEDOff(yellow4 ); turnLEDOff(red1 );
	turnLEDOff(red2 ); turnLEDOff(red3 ); turnLEDOff(red4 ); turnLEDOff(yellow3);

	if(lednum>0 && lednum<2 )//1
	{	turnLEDOn(red4);
	}
	if(lednum>1 && lednum<3)//2
	{	turnLEDOn(red3);
	}
	if(lednum>2 && lednum<4)//3
	{	turnLEDOn(red2);
	}
	if(lednum>3 && lednum<5)//4
	{ turnLEDOn(red1);
	}
	if(lednum>4 && lednum<6)//5
	{turnLEDOn(yellow4);
	}
	if(lednum>5 && lednum<7)//6
	{turnLEDOn(yellow3);
	}
	if(lednum>6 && lednum<8)//7
	{turnLEDOn(yellow2);
	}
	if(lednum>7 && lednum<9)//8
	{turnLEDOn(yellow1);
	}
	if(lednum>8 && lednum<10)//9
	{turnLEDOn(green4);
	}
	if(lednum>9 && lednum<11)//10
	{turnLEDOn(green3);
	}
	if(lednum>10 && lednum<12)//11
	{turnLEDOn(green2);
	}
	if(lednum>11 && lednum<12.4)//12
	{turnLEDOn(green1);
	}
	if(lednum>12.5)
	{
		turnLEDOn(green1);
		wait(0.5);
		turnLEDOff(green1);
	}
	if(lednum<0.5)
	{
		turnLEDOn(red4);
		wait(0.5);
		turnLEDOff(red4);
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




task basicflywheel()
{

	if(vexRT[Btn8R]==1)
	{
		motor(Leftflywheel) = flywheelspeed+3;
		motor(Rightflywheel) = flywheelspeed;


		if(vexRT[Btn7R]==1)
		{/////////////Hold down 7R while also holding 8R for burst of speed//////////////
			motor(Leftflywheel) = 127;
			motor(Rightflywheel) = 127;
			wait(0.1);
			motor(Leftflywheel) = flywheelspeed;
			motor(Rightflywheel) = flywheelspeed;

		}

	}






	if(vexRT[Btn8U]==1)
	{
		while(vexRT[Btn8U]==1){}//DO NOTHING
		flywheelspeed=flywheelspeed+2;
		lednum=lednum+1;
	}
	else if(vexRT[Btn8D]==1)
	{
		while(vexRT[Btn8D]==1){}
		flywheelspeed=flywheelspeed-2;
		lednum=lednum-1;
	}
	else if(vexRT[Btn8L]==1)
	{
		while(vexRT[Btn8L]==1){}
		//////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////
		///////HOME SPEED SETTING//////////////////
		/////////////////////////////////////////////
		flywheelspeed=50;//
		lednum=7;
	}

	else if(vexRT[Btn7U]==1)
	{
		while(vexRT[Btn7U]==1){}
		flywheelspeed=flywheelspeed+1;
		lednum=lednum+0.5;
	}

	else if(vexRT[Btn7D]==1)
	{
		while(vexRT[Btn7D]==1){}
		flywheelspeed=flywheelspeed-1;
		lednum=lednum-0.5;
	}

}

task usercontrol()//main task runs and starts sub tasks which run simultaneously
{

	while(1==1)
	{

		startTask(ledees);


		if(vexRT(Btn5U) ==1)
		{
			startMotor(Leftflywheel, 52);//Start flywheels up to speed
			startMotor(Rightflywheel, 52);//Start flywheels up to speed
			wait(3.75);//Start flywheels up to speed wait for 1st ball
			startMotor(Intake, 100);//Load first ball
			wait(.5);//Launch 1
			stopMotor(Intake);
			startMotor(Leftflywheel, 54);//Start flywheels up to speed
			startMotor(Rightflywheel, 54);//Start flywheels up to speed
			wait(2.25);//Wait for 2nd ball
			startMotor(Intake, 100);//2nd ball
			wait(1);//Shoot 2nd ball
			stopMotor(Intake);
			startMotor(Leftflywheel, 52);//Start flywheels up to speed
			startMotor(Rightflywheel, 52);//Start flywheels up to speed
			wait(2.5);//Wait for 3rd ball
			startMotor(Intake, 100);
			wait(.5);
			stopMotor(Intake);
			wait(3);
			startMotor(Intake, 100);
			wait(1);


		}


		if(vexRT[Btn8U]==1 || vexRT[Btn8D]==1 || vexRT[Btn8R]==1 || vexRT[Btn8L]==1 || vexRT[Btn7U]==1 || vexRT[Btn7D]==1)
		{//if the flywheel button is being used then run the flywheel code
			startTask(basicflywheel);



		}

		if(vexRT[Btn8U]==0 && vexRT[Btn8D]==0 && vexRT[Btn8R]==0 && vexRT[Btn8L]==0)
		{//if the flywheel button is not being used then turn off the led
			stopMotor(Rightflywheel);
			stopMotor(Leftflywheel);
		}

		if(vexRT[Ch2]>0 || vexRT[Ch2]<0 || vexRT[Ch3]>0 || vexRT[Ch3]<0)
		{//if the joysticks are moved, then run the drive code
			motor[Frontrightwheel] = vexRT[Ch2];
			motor[Backrightwheel] = vexRT[Ch2];
			motor[Frontleftwheel] = vexRT[Ch3];
			motor[Backleftwheel] = vexRT[Ch3];
		}

		if(vexRT[Ch2]==0 && vexRT[Ch2]==0 && vexRT[Ch3]==0 && vexRT[Ch3]==0)
		{//if the joysticks are not being moved, then turn off the motors

			stopMotor(Backleftwheel);
			stopMotor(Backrightwheel);
			stopMotor(Frontleftwheel);
			stopMotor(Frontrightwheel);

		}


		if(vexRT[Btn6U]==1 || vexRT[Btn6D]==1)
		{//if the intakes are being used, then use the intake code
			startTask(intakes);
		}

		if(vexRT[Btn6U]==0 && vexRT[Btn6D]==0)
		{//if the intakes are not being used, then turn off the led
			stopMotor(Intake);
		}
	}
}
