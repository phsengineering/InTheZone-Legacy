#pragma config(Sensor, dgtl2,  button,         sensorTouch)
#pragma config(Motor,  port2,           memes,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           memes2,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           memes3,        tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
while (true) {
	if(SensorValue[button] == 1) {
		motor[memes] = -63;
		motor[memes2] = 63;
		motor[memes3] = 63;
	}
	else {
		motor[memes] = 0;
		motor[memes2] = 0;
		motor[memes3] = 0;
	}
}

}
