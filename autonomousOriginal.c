#pragma config(Sensor, dgtl1,  solenoid,       sensorDigitalOut)
#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl11, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           DriveLeft_1,   tmotorNormal, openLoop)
#pragma config(Motor,  port3,           DriveLeft_2,   tmotorNormal, openLoop)
#pragma config(Motor,  port4,           DriveRight_1,  tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port5,           DriveRight_2,  tmotorNormal, openLoop, reversed)
task resetEverything() {
	motor[DriveLeft_1] = 0;
	motor[DriveLeft_2] = 0;
	motor[DriveRight_1] = 0;
	motor[DriveRight_2] = 0;
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

task resetMotors() {
	motor[DriveLeft_1] = 0;
	motor[DriveLeft_2] = 0;
	motor[DriveRight_1] = 0;
	motor[DriveRight_2] = 0;
}

task autonomous() {
	startTask(resetEverything);
	SensorValue[solenoid] = 0;
	while(SensorValue[rightEncoder] > -200) {
		motor[DriveRight_1] = 50;
		motor[DriveRight_2] = 50;
	}
	startTask(resetMotors);
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(SensorValue[rightEncoder] >-900 || SensorValue[leftEncoder] < 900) {
		motor[DriveLeft_1] = 63;
		motor[DriveLeft_2] = 63;
		motor[DriveRight_1] = 63;
		motor[DriveRight_2] = 63;
	}
	startTask(resetMotors);
	SensorValue[solenoid] = 1;
	wait1Msec(1000);


	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(SensorValue[leftEncoder] < -500 || SensorValue[rightEncoder] > 500) {
		motor[DriveLeft_1] = -63;
		motor[DriveLeft_2] = -63;
		motor[DriveRight_1] = -63;
		motor[DriveRight_2] = -63;
	}
	startTask(resetEverything);
	while(SensorValue[leftEncoder] < 300 || SensorValue[rightEncoder] < 430) {//total shot in the dark
		motor[DriveLeft_1] = 63;
		motor[DriveLeft_2] = 63;
		motor[DriveRight_1] = -63;
		motor[DriveRight_2] = -63;
	}
	startTask(resetEverything);
	wait1Msec(1000);
	while(SensorValue[rightEncoder] > -200 || SensorValue[leftEncoder] < 200) {
		motor[DriveLeft_1] = 63;
		motor[DriveLeft_2] = 63;
		motor[DriveRight_1] = 63;
		motor[DriveRight_2] = 63;
	}
	startTask(resetEverything);
	while(SensorValue[leftEncoder] < -100 || SensorValue[rightEncoder] > 260) {
		motor[DriveLeft_1] = 63;
		motor[DriveLeft_2] = 63;
		motor[DriveRight_1] = 63;
		motor[DriveRight_2] = 63;
	}
	startTask(resetEverything);
	while(SensorValue[rightEncoder] > -100 || SensorValue[leftEncoder] < 540) {
		motor[DriveLeft_1] = 63;
		motor[DriveLeft_2] = 63;
	}
	startTask(resetEverything);
	while(SensorValue[leftEncoder] < 345 || SensorValue[rightEncoder] > -345) {
		motor[DriveLeft_1] = 63;
		motor[DriveLeft_2] = 63;
		motor[DriveRight_1] = 63;
		motor[DriveRight_2] = 63;
	}
	startTask(resetEverything);
	SensorValue[solenoid] = 0;

	motor[DriveLeft_1] = -63;
	motor[DriveLeft_2] = -63;
	motor[DriveRight_1] = -63;
	motor[DriveRight_2] = -63;
	wait1Msec(2000);
	startTask(resetMotors);
}



task main() {
	while(true) {
		if(vexRT[Btn6U] == 1) {
			startTask(autonomous);
		}
	}
}
