#pragma config(Sensor, dgtl1,  solenoid,       sensorDigitalOut)
#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl11, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           DriveLeft_1,   tmotorNormal, openLoop)
#pragma config(Motor,  port3,           DriveLeft_2,   tmotorNormal, openLoop)
#pragma config(Motor,  port4,           DriveRight_1,  tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port5,           DriveRight_2,  tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,           armAngle,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightArm,      tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           leftArm,       tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           servoGrab,     tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void pre_auton()
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	SensorValue[solenoid] = 0;
}
task resetEverything() { //this is a subroutine that will reset the motors and encoders in one go
	motor[DriveLeft_1] = 0;
	motor[DriveLeft_2] = 0;
	motor[DriveRight_1] = 0;
	motor[DriveRight_2] = 0;
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

task resetMotors() { //this will stop all of the motors
	motor[DriveLeft_1] = 0;
	motor[DriveLeft_2] = 0;
	motor[DriveRight_1] = 0;
	motor[DriveRight_2] = 0;
}

task autonomous() {
	startTask(resetEverything); //start out by resetting all of the motors/sensors
	SensorValue[solenoid] = 0; //reset the pneumatics controller
	while(SensorValue[rightEncoder] > -220) { //move the robot slightly to the left in order to get a clear path
		motor[DriveRight_1] = 27;               //to the mobile goal
		motor[DriveRight_2] = 27;
	}
	startTask(resetEverything);
	while(SensorValue[rightEncoder] >-900 || SensorValue[leftEncoder] < 900) { //move the robot to the mobile goal
		motor[DriveLeft_1] = 63; //move at half speed
		motor[DriveLeft_2] = 63;
		motor[DriveRight_1] = 63;
		motor[DriveRight_2] = 63;
	}
	startTask(resetEverything);
	SensorValue[solenoid] = 1; //when the robot has reached the mobile goal, bring the pneumatics pistons up
	wait1Msec(1000); //wait 1 second
	while(SensorValue[leftEncoder] < -500 || SensorValue[rightEncoder] < 500) { //back out of the mobile goal area
		motor[DriveLeft_1] = -63;
		motor[DriveLeft_2] = -63;
		motor[DriveRight_1] = -63;
		motor[DriveRight_2] = -63;
	}
	startTask(resetEverything);

	while(SensorValue[leftEncoder] < 300 || SensorValue[rightEncoder] < 430) { //make a small turn to angle the robot
		motor[DriveLeft_1] = 63;                                                 //towards the scoring areas
		motor[DriveLeft_2] = 63;
		motor[DriveRight_1] = -63;
		motor[DriveRight_2] = -63;
	}
	startTask(resetMotors);
	while(SensorValue[leftEncoder] < -100 || SensorValue[rightEncoder] > 260) { //move the robot into the mobile goal area
		motor[DriveLeft_1] = 127;
		motor[DriveLeft_2] = 127;
		motor[DriveRight_1] = 127;
		motor[DriveRight_2] = 127;
	}
	startTask(resetEverything);
	while(SensorValue[rightEncoder] > -100 || SensorValue[leftEncoder] < 540) { //make another small adjustment
		motor[DriveLeft_1] = 63;
		motor[DriveLeft_2] = 63;
	}
	startTask(resetEverything);
	while(SensorValue[leftEncoder] < 350 || SensorValue[rightEncoder] > -350) { //run into the ten point scoring area
		motor[DriveLeft_1] = 127;
		motor[DriveLeft_2] = 127;
		motor[DriveRight_1] = 127;
		motor[DriveRight_2] = 127;
	}
	startTask(resetEverything);
	SensorValue[solenoid] = 0; //drop the pistons in order to score

	motor[DriveLeft_1] = -120; //back out of the scoring area for two seconds
	motor[DriveLeft_2] = -120;
	motor[DriveRight_1] = -120;
	motor[DriveRight_2] = -120;
	wait1Msec(2000);
	startTask(resetMotors); //stop all of the motors. In the competition template,
	//manual driver control takes over after this sequence
}

#define     JOY_DRIVE_V     vexJSLeftV
#define     JOY_DRIVE_H     vexJSLeftH
#define     JOY_THRESHOLD   15

#define MOTOR_NUM               kNumbOfTotalMotors
#define MOTOR_MAX_VALUE         127
#define MOTOR_MIN_VALUE         (-127)
#define MOTOR_DEFAULT_SLEW_RATE 10      // Default will cause 375mS from full fwd to rev
#define MOTOR_FAST_SLEW_RATE    256     // essentially off
#define MOTOR_TASK_DELAY        15      // task 1/frequency in mS (about 66Hz)
#define MOTOR_DEADBAND          10

const int joy_threshold = 10; // maximum error +/- of joysticks when released

// compensates for non-linearity of control value vs speed curve
const unsigned int TrueSpeed[128] =
{
	0,  9,  9,  9, 10, 10, 10, 10, 11, 11,
	11, 11, 12, 12, 12, 12, 12, 13, 13, 13,
	13, 14, 14, 14, 14, 15, 15, 15, 15, 16,
	16, 16, 17, 17, 17, 18, 18, 18, 18, 19,
	19, 19, 20, 20, 20, 21, 21, 21, 22, 22,
	22, 23, 23, 23, 24, 24, 24, 25, 25, 26,
	26, 27, 27, 27, 28, 28, 28, 29, 29, 30,
	30, 31, 31, 32, 32, 33, 33, 34, 34, 35,
	36, 36, 37, 37, 38, 38, 39, 40, 40, 41,
	42, 43, 44, 45, 45, 46, 47, 48, 49, 50,
	51, 52, 54, 55, 55, 57, 59, 61, 63, 65,
	67, 70, 72, 74, 76, 80, 84, 88, 93, 97,
	101,106,108,111,114,119,124,127
};

task userDrive()
{
	float left_drive_pwr;
	float right_drive_pwr;

	while(true)
	{
		left_drive_pwr = vexRT[Ch3];
		right_drive_pwr = vexRT[Ch2];

		//** linear speed control with threshold

		// left
		if(left_drive_pwr > joy_threshold)
			left_drive_pwr = TrueSpeed[left_drive_pwr];
		else if(left_drive_pwr < -joy_threshold)
			left_drive_pwr = -TrueSpeed[-left_drive_pwr];
		else
			left_drive_pwr = 0;

		// right
		if(right_drive_pwr > joy_threshold)
			right_drive_pwr = TrueSpeed[right_drive_pwr];
		else if(right_drive_pwr < -joy_threshold)
			right_drive_pwr = -TrueSpeed[-right_drive_pwr];
		else
			right_drive_pwr = 0;

		//** antijerk

		// left
		if(left_drive_pwr > motor[DriveLeft_1])
			motor[DriveLeft_1] += 1;
		else if(left_drive_pwr < motor[DriveLeft_1])
			motor[DriveLeft_1] -= 1;

		// right
		if(right_drive_pwr > motor[DriveRight_1])
			motor[DriveRight_1] += 1;
		else if(right_drive_pwr < motor[DriveRight_1])
			motor[DriveRight_1] -= 1;

		wait1Msec(1);
	}
}
task armAngleControl() {
	while(true) {
		if(vexRT[Btn6UXmtr2] == 1) {
			motor[armAngle] = 63;
		}
		else {
			motor[armAngle] = 0;
		}
		if(vexRT[Btn5UXmtr2] == 1) {
			motor[armAngle] = -63;
		}
		else {
			motor[armAngle] = 0;
		}
	}
}
task overrideControl() {
	while(true) {
		if(vexRT[Btn8U] == 1) {
			motor[armAngle] = 63;
		}
		else {
			motor[armAngle] = 0;
		}
		if(vexRT[Btn8D] == 1) {
			motor[armAngle] = -63;
		}
		else {
			motor[armAngle] = 0;
		}
		if(vexRT[Btn7L] == 1) {
			motor[leftArm] = 63;
		}
		else {
			motor[leftArm] = 0;
		}
		if(vexRT[Btn7R] == 1) {
			motor[rightArm] = 63;
		}
		else {
			motor[rightArm] = 0;
		}
	}
}
task liftControl() {
	while(true) {
		if(vexRT[Btn6D] == 1) {
			motor[leftArm] = vexRT[Ch2]/2; //get input from the right side controller joystick and assign it to the left side arm
			motor[rightArm] = vexRT[Ch2]/2; //same as above but for the right side of the lift system
			startTask(overrideControl);
		}
		else if (vexRT[Btn6D] == 0) {
			motor[leftArm] = vexRT[Ch3Xmtr2]/2; //get input from the right side controller joystick and assign it to the left side arm
			motor[rightArm] = vexRT[Ch2Xmtr2]/2; //same as above but for the right side of the lift system
			startTask(armAngleControl);
		}
		if(vexRT[Btn5U] == 1 || vexRT[Btn5UXmtr2] == 1) { //if the left shoulder button is enabled
			setServo(servoGrab, 48); //set the servo's position to 127 (this may be changed based on required clearance)
		}
		else if (vexRT[Btn5U] == 0 && vexRT[Btn5UXmtr2] == 0) {
			setServo(servoGrab, 3);
		}
	}
}

task main()
{
	startTask(userDrive);

	// Start driver lift control
	startTask(liftControl);

	// Everything done in other tasks
	while( true )
	{
		SensorValue[solenoid] = vexRT[Btn6U]; //pneumatics systems here
		wait1Msec( 100 );
	}
}
