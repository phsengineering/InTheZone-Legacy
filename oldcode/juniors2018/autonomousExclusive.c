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

//arjun is the dankest coder
task Quadreset()
{
	SensorValue[Quad]=0;
	SensorValue[Quad2]=0;
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task main()
{
	if(SensorValue[Jumper1]==0) //run if jumper in port 1
	{
		startTask(Quadreset);
		motor(bottom)=90;//lift
		motor(top)=90;//lift
		wait(1);
		motor(top)=60;//stoplift
		motor(bottom)=60;
		motor(mobile)=-127;//drop mobile
		wait(.8);
		motor(mobile)=0;//stop mobile
		while(SensorValue[Quad] < 360*4 || SensorValue[Quad2] < 360*4)
		{
			motor(leftside)=63;
			motor(rightside)=63; //drive to mobile
		}
		//startTask(Quadreset);

		//motor(leftside)=0;
		//motor(rightside)=0;//stop driving
		//while(SensorValue[Quad] < 100|| sensorValue[Quad2] < 100)
		//{
		//	motor(leftside)=63;
		//	motor(rightside)=63; //drive to mobile
		//}









		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;//stop drive
		motor(mobile)=127;//pick up mobile goal
		wait(.25);
		motor(mobile)=0;//stop mobile
		motor(top)=-30;
		motor(bottom)=-30;//drop lift
		wait(.5);
		motor(top)=0;
		motor(bottom)=0;//stop drop lift
		motor(fly)=-127;//drop cone
		wait(.3);
		motor(fly)=0;//stop fly
//	wait(5); for testing
		while(SensorValue[Quad] > -1300|| SensorValue[Quad2] > -1300)
		{
			motor(left)=-63;
			motor(rightside)=-63;
		}
		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;
		while( SensorValue[Quad] < 480 || SensorValue[Quad2] > -480)
		{

			motor(rightside)=-63; // complete turn towards drop zone
			motor(leftside)=63;

		}
		startTask(Quadreset);
		while(SensorValue[Quad] < 60 || SensorValue[Quad2] < 60)
		{
			motor(leftside)=63; //drive to zone
		}
		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;
		motor(mobile)=-127;// drop off mobile
		wait(.3);
		motor(mobile)=0;

		while(SensorValue[Quad] > -60 || SensorValue[Quad2] > -60)
		{
			motor(leftside)=-63; //back up
			motor(rightside)=-63;
		}
		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;
	}
	//left side
	{
		if(SensorValue[Jumper2]==0) //run if jumper in port 2
	{
		startTask(Quadreset);
		motor(bottom)=63;
		motor(top)=63;
		wait(1);
		motor(top)=0;
		motor(bottom)=0;
		motor(mobile)=-127;//pick up mobile
		wait(.8);
		motor(mobile)=0;
		while(SensorValue[Quad] < 100 || SensorValue[Quad2] < 100)
		{
			motor(leftside)=63;
			motor(rightside)=63; //drive to mobile
		}
		startTask(Quadreset);

		motor(leftside)=0;
		motor(rightside)=0;
		motor(top)=80;
		motor(bottom)=80;
		while(SensorValue[Quad] < 100|| sensorValue[Quad2] < 100)
		{
			motor(leftside)=63;
			motor(rightside)=63; //drive to mobile
			//dan sucks
		}
		startTask(Quadreset);
		wait(2); //pick up mobile and drop fly to drop cone
		motor(leftside)=0;
		motor(rightside)=0;
		motor(mobile)=127;
		wait(1.2);
		motor(mobile)=0;
		motor(top)=-63;
		motor(bottom)=-63
		wait(
		motor(fly)=-127;
		wait(1);
		motor(fly)=0;
		motor(top)=0;
		motor(bottom)=0;
		while(SensorValue[Quad] > -200|| SensorValue[Quad2] > -200)
		{
			motor(leftside)=-63;
			motor(rightside)=-63;
		}
		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;
		while( SensorValue[Quad] < 100)
		{

			motor(leftside)=63; // complete turn towards drop zone
		}
		startTask(Quadreset);
		while(SensorValue[Quad] < 60 || SensorValue[Quad2] < 60)
		{
			motor(leftside)=63; //drive to zone
		}
		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;

		motor(mobile)=-127;// drop off mobile
		wait(.3);
		motor(mobile)=0;

		while(SensorValue[Quad] > -60 || SensorValue[Quad2] > -60)
		{
			motor(leftside)=-63; //back up
			motor(rightside)=-63;
		}
		startTask(Quadreset);
		motor(leftside)=0;
		motor(rightside)=0;
	}
	//dan sucks at coding
	//dan has the big gay
	}
}
