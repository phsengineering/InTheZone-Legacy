
#pragma config(Motor,  port2,           leftside,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightside,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           arm2,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           arm3,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(3.0)
#pragma userControlDuration(9.0)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{

	/*
	motor[leftside]=-127;
	motor[rightside]=-127;
	wait(0.15);

	motor[leftside]=0;
	motor[rightside]=0;

	motor[arm]=-127;
	motor[arm2]=-127;
	motor[arm3]=-127;
	wait(.1); //unknown time//

	motor[arm]=0;
	motor[arm2]=0;
	motor[arm3]=0;

	motor[claw]=127;
	wait(0.5); //unknown time//

	motor[claw]=0;

	motor[leftside]=-127;
	motor[rightside]=-127;
	wait(1.45); //unknown time//

	motor[leftside]=0;
	motor[rightside]=0;

	motor[arm]=-127;
	motor[arm2]=-127;
	motor[arm3]=-127;
	wait(1.9); //unknown time//

	motor[arm]=0;
	motor[arm2]=0;
	motor[arm3]=0;

	motor[arm]=127;
	motor[arm2]=127;
	motor[arm3]=127;
	wait(.33); //unknown time//

	motor[leftside]=127;
	motor[rightside]=127;
	wait(1.35); //unknown time same as above//

	motor[leftside]=0;
	motor[rightside]=0;

	motor[claw]=-127; //first back//

	motor[leftside]=-127;
	motor[rightside]=-127;
	wait(1.45); //unknown time//

	motor[leftside]=0;
	motor[rightside]=0;

	motor[arm]=-127;
	motor[arm2]=-127;
	motor[arm3]=-127;
	wait(2.1); //unknown time//

	motor[arm]=0;
	motor[arm2]=0;
	motor[arm3]=0;
	motor[claw]=-127;
	wait(0.5);
	motor[claw]=0;

	motor[arm]=127;
	motor[arm2]=127;
	motor[arm3]=127;
	wait(.33); //unknown time//

	motor[claw]=127;
	wait(0.5);

	motor[leftside]=127;
	motor[rightside]=127;
	wait(1.35); //unknown time same as above//

	motor[leftside]=0;
	motor[rightside]=0;

	motor[claw]=-127; //2 back//

	motor[leftside]=-127;
	motor[rightside]=-127;
	wait(1.45); //unknown time//

	motor[leftside]=0;
	motor[rightside]=0;

	motor[arm]=-127;
	motor[arm2]=-127;
	motor[arm3]=-127;
	wait(2.1); //unknown time//

	motor[arm]=0;
	motor[arm2]=0;
	motor[arm3]=0;
	motor[claw]=-127;
	wait(0.5);
	motor[claw]=0;

	motor[arm]=127;
	motor[arm2]=127;
	motor[arm3]=127;
	wait(.33); //unknown time//

	motor[claw]=127;
	wait(0.5);

	motor[leftside]=127;
	motor[rightside]=127;
	wait(1.35); //unknown time same as above//

	motor[leftside]=0;
	motor[rightside]=0;

	motor[claw]=-127; //2 back//

	motor[leftside]=-127;
	motor[rightside]=-127;
	wait(1.45); //unknown time//

	motor[leftside]=0;
	motor[rightside]=0;

	motor[arm]=-127;
	motor[arm2]=-127;
	motor[arm3]=-127;
	wait(1.9); //unknown time//

	motor[arm]=0;
	motor[arm2]=0;
	motor[arm3]=0;
	motor[claw]=-127;
	wait(0.5);
	motor[claw]=0;

	motor[arm]=127;
	motor[arm2]=127;
	motor[arm3]=127;
	wait(.33); //unknown time//[claw

	motor[claw]=127;
	wait(0.5);

	motor[leftside]=127;
	motor[rightside]=127;
	wait(1.35); //unknown time same as above//

	motor[leftside]=0;
	motor[rightside]=0;
	*/


	wait(1.0);
	motor[leftside]=-127;
	motor[rightside]=-127;
	wait(0.1);

	motor[claw]=127;
	wait(0.5); //unknown time//

	motor[claw]=0;


	motor[leftside]= 127;
	motor[rightside]= 127;

	wait(1.5);

	motor[leftside]=0;
	motor[rightside]= 0;


	motor[claw]=-127;
	wait(0.5); //unknown time//

	motor[claw]=0;

	motor[rightside]=127;
	motor[leftside]=-127;
	wait(0.9/2);

	motor[rightside]=127;
	motor[leftside]=127;
	wait(0.9);
/*
	motor[rightside]=0;
	motor[leftside]=0;

	motor[rightside]=127;
	motor[leftside]=-127;
	wait(0.9);

	motor[rightside]=-127;
	motor[leftside]=-127;
	wait(0.7);

	motor[arm]=-127;
	motor[arm2]=-127;
	motor[arm3]=-127;
	wait(1.9); //unknown time//

	motor[arm]=0;
	motor[arm2]=0;
	motor[arm3]=0;

	motor[claw]=127;
	wait(0.5);

	motor[claw]=0;

*/

	/*
	motor[leftside]=-127;
	motor[rightside]=-127;
	wait(0.15);

	motor[leftside]=0;
	motor[rightside]=0;

	motor[arm]=-127;
	motor[arm2]=-127;
	motor[arm3]=-127;
	wait(.1); //unknown time//

	motor[arm]=0;
	motor[arm2]=0;
	motor[arm3]=0;

	motor[claw]=127;
	wait(0.5); //unknown time//

	motor[claw]=0;

	motor[leftside]=-127;
	motor[rightside]=-127;
	wait(1.35); //unknown time//

	motor[leftside]=0;
	motor[rightside]=0;

	motor[arm]=-127;
	motor[arm2]=-127;
	motor[arm3]=-127;
	wait(1.9); //unknown time//

	motor[arm]=0;
	motor[arm2]=0;
	motor[arm3]=0;

	motor[arm]=127;
	motor[arm2]=127;
	motor[arm3]=127;
	wait(.33); //unknown time//

	motor[leftside]=127;
	motor[rightside]=127;
	wait(0.6); //unknown time same as above//

	motor[leftside]=0;
	motor[rightside]=0;

	motor[rightside]=-127;
	motor[leftside]=127;
	wait(1.2/2); //quarter turn//


	motor[leftside]=127;
	motor[rightside]=127;
	wait(1.6);

	motor[rightside]=0;
	motor[leftside]=0;

	motor[claw]=-127;
	wait(0.5); //same as earlier but opposite//

	motor[arm]=-127;
	motor[arm2]=-127;
	motor[arm3]=-127;
	wait(2.0);

	motor[arm]=0;
	motor[arm2]=0;
	motor[arm3]=0;


	motor[rightside]=127;
	motor[leftside]=-127;
	wait(1.0/2); //quarter turn//


	motor[leftside]=0;
	motor[rightside]=0;



	motor[rightside]=-127;
	motor[leftside]=-127;
	wait(1.0);

	motor[leftside]=0;
	motor[rightside]=0;
	motor[arm]=-127;
	motor[arm2]=-127;
	motor[arm3]=-127;
	wait(1.3);

	motor[arm]=0;
	motor[arm2]=0;
	motor[arm3]=0;
	motor[claw]=127;
	wait(0.5);

	motor[claw]=0; */
}

//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop //

	while(1==1)
	{

		motor[rightside] = vexRT[Ch2];
		motor[leftside] = vexRT[Ch3];


		if(vexRT[Btn6UXmtr2]==1)
		{
			motor[claw]=127;
		}


		else if(vexRT[Btn5UXmtr2]==1)
		{
			motor[claw]=-127;
		}
		else if(vexRT[Btn5UXmtr2]==0)
		{
			motor[claw]=0;
		}
		////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////

		if(vexRT[Btn6DXmtr2]==1) ///claw goes up//
		{
			motor[arm]=127;
			motor[arm2]=127;
			motor[arm3]=127;
		}


		else if(vexRT[Btn5DXmtr2]==1) ///claw goes down///
		{
			motor[arm]=-127;
			motor[arm2]=-127;
			motor[arm3]=-127;
		}
		else if(vexRT[Btn5DXmtr2]==0)
		{
			motor[arm]=0;
			motor[arm2]=0;
			motor[arm3]=0;///end claw goes down///
		}


		if(vexRT[Btn7UXmtr2]==1)
		{
			motor[arm] = -15;
			motor[arm2] = -15;
			motor[arm3] = -15;
		}
		if(vexRT[Btn7DXmtr2]==1)
		{
			motor[arm]=0;
			motor[arm2]=0;
			motor[arm3]=0;
		}

		if(vexRT[Btn8D]==1)
		{
			motor[leftside]=-127;
			motor[rightside]=-127;
			wait(0.15);

			motor[leftside]=0;
			motor[rightside]=0;

			motor[arm]=-127;
			motor[arm2]=-127;
			motor[arm3]=-127;
			wait(.1); //unknown time//

			motor[arm]=0;
			motor[arm2]=0;
			motor[arm3]=0;

			motor[claw]=127;
			wait(0.5); //unknown time//

			motor[claw]=0;

			motor[leftside]=-127;
			motor[rightside]=-127;
			wait(1.35); //unknown time//

			motor[leftside]=0;
			motor[rightside]=0;

			motor[arm]=-127;
			motor[arm2]=-127;
			motor[arm3]=-127;
			wait(1.7); //unknown time//

			motor[arm]=0;
			motor[arm2]=0;
			motor[arm3]=0;

			motor[arm]=127;
			motor[arm2]=127;
			motor[arm3]=127;
			wait(.33); //unknown time//

			motor[leftside]=127;
			motor[rightside]=127;
			wait(0.4); //unknown time same as above//

			motor[leftside]=0;
			motor[rightside]=0;

			motor[rightside]=-127;
			motor[leftside]=127;
			wait(0.90/2); //quarter turn//

			motor[leftside]=127;
			motor[rightside]=127;
			wait(1.6);

			motor[rightside]=0;
			motor[leftside]=0;

			motor[claw]=-127;
			wait(0.5); //same as earlier but opposite//

			motor[arm]=-127;
			motor[arm2]=-127;
			motor[arm3]=-127;
			wait(1.0);

			motor[arm]=0;
			motor[arm2]=0;
			motor[arm3]=0;


			motor[rightside]=127;
			motor[leftside]=-127;
			wait(1.6/2); //quarter turn//


			motor[leftside]=0;
			motor[rightside]=0;

			motor[rightside]=-127;
			motor[leftside]=-127;
			wait(1.0);
			motor[arm]=-127;
			motor[arm2]=-127;
			motor[arm3]=-127;



			motor[leftside]=0;
			motor[rightside]=0;

			wait(1.0);

			motor[arm]=0;
			motor[arm2]=0;
			motor[arm3]=0;
			motor[claw]=127;
			wait(0.5);

			motor[claw]=0;
		}


	}
}





/* if(exRT[Btn6U]==1)
{
motor[MiddleMotor]=127;

else if(vexRT[Btn6D]==1)
{
motor[MiddleMotor]=64;
}

else if(vexRT[Btn5U]==1)
{
motor[MiddleMotor]=-127;
}

else if(vexRT[Btn5D]==1)
{
motor[MiddleMotor]=-64;
}

else
{
motor[MiddleMotor]=-0;
}
*/
