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
	while(SensorValue[rightEncoder] > -230) {
		motor[DriveRight_1] = 27;
		motor[DriveRight_2] = 27;
	}
	startTask(resetMotors);
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(SensorValue[rightEncoder] >-850 || SensorValue[leftEncoder] < 850) {
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
	while(SensorValue[leftEncoder] < -400 || SensorValue[rightEncoder] < 400) {
		motor[DriveLeft_1] = -63;
		motor[DriveLeft_2] = -63;
		motor[DriveRight_1] = -63;
		motor[DriveRight_2] = -63;
	}
	startTask(resetEverything);

	while(SensorValue[leftEncoder] < 1550 || SensorValue[rightEncoder] < 0) {//total shot in the dark
		motor[DriveLeft_1] = 63;
		motor[DriveLeft_2] = 63;
		motor[DriveRight_1] = -63;
		motor[DriveRight_2] = -63;
	}
	startTask(resetEverything);
	while(SensorValue[leftEncoder] < 700 || SensorValue[rightEncoder] > -700) {
		motor[DriveLeft_1] = 63;
		motor[DriveLeft_2] = 63;
		motor[DriveRight_1] = 63;
		motor[DriveRight_2] = 63;
	}
	startTask(resetEverything);
	SensorValue[solenoid] = 0;
	//while(SensorValue[leftEncoder] > -300 || SensorValue[rightEncoder] > 300) {
		//motor[DriveLeft_1] = -63;
		//motor[DriveLeft_2] = -63;
		//motor[DriveRight_1] = -63;
		//motor[DriveRight_2] = -63;
	//}
}



task main() {
	while(true) {
		if(vexRT[Btn6U] == 1) {
			startTask(autonomous);
		}
	}
}
