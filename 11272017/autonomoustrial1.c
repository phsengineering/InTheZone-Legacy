//Basic autonomous algorithm. Do not test unmodified code on actual robot. Bad things will happen.
//4001A - Arjun Vedantham. 

#pragma config(Motor,  port2,           mDriveL,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           mDriveL2,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           mDriveR,       tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           mDriveR2,      tmotorServoContinuousRotation, openLoop, reversed)
//add in the quad encoders as well. they are not presently configured. 
void autonomousDriveSegment1() {
		int quad1valueSeg1;
		int quad2valueSeg1;
		quad1valueSeg1 = 0;
		quad2valueSeg1 = 0;
    	while(quad1valueSeg1<= 120 && quad2valueSeg1<=120) {//however long this needs to go
    		quad1valueSeg1 = sensorValue(quadencoderL);
    		quad2valueSeg1 = sensorValue(quadencoderR);
				startMotor(mDriveL, 127);
				startMotor(mDriveR, 127);
			}
}
void autonomousDriveSegment3() {
	int quad1valueSeg3;
	int quad2valueSeg3;
	quad1valueSeg3 = 0;
	quad2valueSeg3 = 0;
	while(quad1valueSeg3 <= 120 && quad2valueSeg3<=120) {
		startTask(pneumaticsHold);
		quad1valueSeg3 = sensorValue(quadencoderL);
		quad2valueSeg3 = sensorValue(quadencoderR);
		startMotor(mDriveL, 127);
		startMotor(mDriveR, 127);
	}
	stopMotor(mDriveL);
	stopMotor(mDriveR);
}
void pneumaticsLift() {
	//fill in with pneumatics code. i have no idea how this is supposed to work
}
void pneumaticsHold() {
	//fill in with code to apply pneumatics pressure to the lift system so that we can keep ahold of things
}
void pneumaticsDrop() {
	//drop the cone
}
void aboutface() {
	startMotor(mDriveR, 40);
	startMotor(mDriveL, 20); //modify as needed
	wait(2);
	stopMotor(mDriveR);
	stopMotor(mDriveL);
}
task main()
{
startTask(autonomousDriveSegment1);
startTask(pneumaticsLift);
startTask(aboutface);
startTask(autonomousDriveSegment3);
startTask(pneumaticsDrop);
}
