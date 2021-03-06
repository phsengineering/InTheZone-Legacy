#pragma config(Sensor, in5,    Accel,          sensorAccelerometer)
#pragma config(Sensor, in6,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  Bump,           sensorTouch)
#pragma config(Motor,  port9,           LeftMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port6,           Arm,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           Claw,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port2,          RightMotor,    tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float dx = 0;
float Vo = 0;
float a = 0;
float t = 0;

void moveTo(float x, float y, float correction){

	motor(RightMotor) = 127;
	motor(LeftMotor) = 127;
	clearTimer(timer1);
	while((43.07142857/30)*dx<=x){
	t = time1(timer1)*.001;
	a = SensorValue(Accel) - correction;
	dx = (dx+Vo*t+.5*a*pow(t, 2));
	Vo = Vo+a*t;
	clearTimer(timer1);
	wait1Msec(1);
}
motor(RightMotor) = 0;
motor(LeftMotor) = 0;
}

task main()
{

while(1==1)

{
	motor(RightMotor)= vexRT(Ch3);
	motor(LeftMotor)= vexRT(Ch2);

	if(vexRT(Btn7U) == 1){

		moveTo(30,0, SensorValue(Accel));
		dx = 0;
		Vo = 0;
		a = 0;
		t = 0;
	}


	}
}
