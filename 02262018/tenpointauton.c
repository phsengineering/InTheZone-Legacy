#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    mogoTrack,      sensorPotentiometer)
#pragma config(Sensor, dgtl1,  mogoLimit,      sensorTouch)
#pragma config(Sensor, I2C_1,  rightEncoder,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  leftEncoder,    sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           mogoLift,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           liftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           internalStack, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           DriveRight_1,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           DriveRight_2,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           DriveLeft_1,   tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port9,           DriveLeft_2,   tmotorServoContinuousRotation, openLoop, reversed)

task fullspeed() {

  motor[DriveLeft_1] = 63;
  motor[DriveLeft_2] = 63;
  motor[DriveRight_1] = 63;
  motor[DriveRight_2] = 63;
}
task fullreverse() {

  motor[DriveLeft_1] = -63;
  motor[DriveLeft_2] = -63;
  motor[DriveRight_1] = -63;
  motor[DriveRight_2] = -63;
}
task stopmotors() {

  motor[DriveLeft_1] = 0;
  motor[DriveLeft_2] = 0;
  motor[DriveRight_1] = 0;
  motor[DriveRight_2] = 0;
}
task main() {
	motor[mogoLift] = -63;
wait(2);
motor[mogoLift] = 0;
 SensorValue[leftEncoder] = 0;
 SensorValue[rightEncoder] = 0;
 while(SensorValue[rightEncoder] < 1050) {
 startTask(fullspeed);
}
 startTask(stopmotors);
 motor[mogoLift] = 63;
 wait(1.5);
 motor[mogoLift] = 0;
 while(SensorValue[rightEncoder] > 442) {
   startTask(fullreverse);
 }
 startTask(stopmotors);
 SensorValue[rightEncoder] = 0;
 SensorValue[leftEncoder] = 0;
 while(SensorValue[rightEncoder] > -500) {
   motor[DriveLeft_1] = 50;
   motor[DriveLeft_2] = 50;
   motor[DriveRight_1] = -50;
   motor[DriveRight_2] = -50;
 }
 startTask(stopmotors);
 while(SensorValue[rightEncoder] < 450) {
   startTask(fullspeed);
 }
 startTask(stopmotors);
 motor[mogoLift] = -63;
 wait(1.5);
 motor[mogoLift] = 0;
 startTask(fullreverse);
 wait(2);
 motor[mogoLift] = 63;
 wait(1.5);
 motor[mogoLift] = 0;
 startTask(stopmotors);
}
