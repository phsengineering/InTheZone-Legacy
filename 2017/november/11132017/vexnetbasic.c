#pragma config(Sensor, dgtl5,  BumpSwitch,     sensorTouch)
#pragma config(Motor,  port2,           BackLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           FrontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           BackRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           FrontLeft,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
while(true) {
		motor[FrontLeft] = vexRT[Ch3];
		motor[FrontRight] = vexRT[Ch2];
		motor[BackLeft] = vexRT[Ch1];
		motor[BackRight] = vexRT[Ch4];
	}
}
