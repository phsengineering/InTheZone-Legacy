#pragma config(Sensor, dgtl1,  solenoid,       sensorDigitalOut)
#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl11, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           DriveLeft_1,   tmotorNormal, openLoop)
#pragma config(Motor,  port3,           DriveLeft_2,   tmotorNormal, openLoop)
#pragma config(Motor,  port4,           DriveRight_1,  tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port5,           DriveRight_2,  tmotorNormal, openLoop, reversed)
task main()
{
	while(true) {
		if(vexRT[Btn6U] ==1) {
			while(SensorValue[leftEncoder] < 1000) {//total shot in the dark
				motor[DriveLeft_1] = 27;
				motor[DriveLeft_2] = 27;
			}
		}
	}
}

/*

while(SensorValue[leftEncoder] < 360 || SensorValue[rightEncoder] < -360) {
		motor[DriveLeft_1] = 63;
		motor[DriveLeft_2] = 63;
		motor[DriveRight_1] = 63;
		motor[DriveRight_2] = 63;
	}
	startTask(resetMotors);
	SensorValue[solenoid] = 0;

	/*
