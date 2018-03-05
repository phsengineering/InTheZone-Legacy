#pragma config(Sensor, in1,    Gyro,           sensorNone)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in3,    p,              sensorPotentiometer)
#pragma config(Sensor, in4,    h,              sensorLineFollower)
#pragma config(Sensor, in5,    g,              sensorReflection)
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
#pragma config(Motor,  port3,           bottom,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           mobile,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           fly,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightside,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           top,           tmotorVex393_MC29, openLoop)
task main()
{
	SensorValue[Quad] = 0;
	SensorValue[Quad2] = 0;
while(SensorValue[Quad] > -1905 || SensorValue[Quad2] > -1905)
		{
			motor(left)=-63;
			motor(rightside)=-63;
	}
}
