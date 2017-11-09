#pragma config(Sensor, in1,    greeksensor,    sensorGyro)
#pragma config(Sensor, in7,    clawwidth,      sensorPotentiometer)
#pragma config(Sensor, in8,    Leverangle,     sensorPotentiometer)
#pragma config(Sensor, dgtl5,  Green,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  Yellow,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  Red,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl9,  Encoderright,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, Encoderleft,    sensorQuadEncoder)
#pragma config(Motor,  port2,           Rightside,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           Leftside,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           claw2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Leftarm2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Leftarm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           Rightarm,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           Rightarm2,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(300)
#pragma userControlDuration(900)
#include "Vex_Competition_Includes.c"   //Main competit
//ion background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////
int 	dumbpotentiometerthignalisonwants;
void pre_auton()
{

////////////////////////////////////////////////////////////////////////
// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
/////////////////////////////////////////////////////////////////////////
dumbpotentiometerthignalisonwants = SensorValue(Leverangle);



}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

	int dunderedoneclawpotendontdunworkin;

int greekfoodlevel = SensorValue(in1);



//====================================================//
//																										//
//					HEY LOOK! IT'S AUTONOMOUS!                //
//																										//
//																										//
//====================================================//



int gotoautonomous = 2;

int chooseautonomous = 2;
//// 1 = LEFT SIDE ( TURN RIGHT)
//// 2 = RIGHT SIDE (TURN LEFT)
//// 0 = DO NOTHING
//// 3 = KABOOM
////SIDES ARE POINTED TOWARDS FENCE
///////GREEN LED = Leftside on
///////RED LED = Rightside on

void autonomousexe() ////Autonomous is in a void to ease calling it to action
{
motor(claw) = -60; ////Close CLAW SPEED
motor(claw2) = -60;

wait(0.4);
if(chooseautonomous == 1)
{
	motor(Leftside) = 127;
	motor(Rightside) = -127;
}
else{
motor(Leftside) = -127;
motor(Rightside) = 127;}

wait(0.8);
motor(Leftside) = 0;
motor(Rightside) = 0;
wait(0.4);


motor(claw) = 0;
motor(claw2) = 0;

motor(Leftside) = 127;//////////STARS PICKUP/////LENGH: .7 SECONDS/////
motor(Rightside) = 127;

motor[Leftarm] = -0; //////This lifts arm so arm does not immediantly hit floor////
motor[port6] = -0; //bottom left
motor[Rightarm] = 0;
motor[port9]= 0; //bo

 //bottom right

wait(0.3);///////Stop opening the claw after ____ seconds////



wait(0.4);

motor(Leftside) = 127;
motor(Rightside) = 127; //////////////////////PICKUP PART 2 (Closeing the claw)

motor(claw) = -85; ///negative is close
motor(claw2) = -85;

wait(0.4);

motor(Leftside) = -127;
motor(Rightside) = -127;

wait(0.6);

if(chooseautonomous == 1) ////This decides the direction.
	//DO NOT MODIFY THIS DIRECTLY!//
{
motor(Leftside) = 0;
motor(Rightside) = -127; /////TURNING BACKUP///////
}
else
{
	motor(Leftside) = -127;
	motor(Rightside) = 0;
}

motor(claw) = -30; /////This holds the claw tighter in while turning
motor(claw2) = -30; ////so stars dont slip

	motor[Leftarm] = -30;
		motor[port6] = -30; //bottom left
		motor[Rightarm] = 30;
		motor[port9]= 30; //bottom right

		wait(1.05);

		motor(Leftside) = -127; ///// This makes us simply move closer to the fence
		motor(Rightside) = -127;

			motor[Leftarm] = -40;
		motor[port6] = -40; //bottom left
		motor[Rightarm] = 40;
		motor[port9]= 40; //bottom right

		wait(1);

		if(chooseautonomous == 1) ////This section allows us to compensate if the turn is too sharp; realigns robot
		{
		motor(Leftside) = 0;
		motor(Rightside) = -50;
	}
	else
	{
		motor(Leftside) = -50;
		motor(Rightside) = 0;
	}

while(SensorValue(in8)>1300)
{
		motor[Leftarm] = -100; /////////SCORE THE STARS//LENGTH: 1.4 Secs///////////
		motor[port6] = -100;
		motor[Rightarm] = 100; ////speed at which the arm dumps stars
		motor[port9]= 100;
}

				motor[Leftarm] = -0; ////Slowly lower arm more in case of errors
		motor[port6] = -0; //bottom left
		motor[Rightarm] = 0;
		motor[port9]= 0; //bottom right




		motor(claw) = 127; ////open the claw
		motor(claw2) = 127; ///negative is close

		wait (0.5);

			motor(claw) = 20;
		motor(claw2) = 20;

		wait (0.3);

		motor(Rightside) = 0;
		motor(Leftside) = 0;
///Stop everything
		motor(claw) = 0;
		motor(claw2) = 0;
		///Fin
		wait(0.4);
			motor[Leftarm] = 100; /////stop the arm
		motor[port6] = 100; //bottom left
		motor[Rightarm] = -100;
		motor[port9]= -100; //bottom right
		wait(1);
				motor[Leftarm] = -0; /////stop the arm
		motor[port6] = -00; //bottom left
		motor[Rightarm] = 0;
		motor[port9]= 00;

}







task autonomous()
{

if(chooseautonomous==0)
{
	motor(claw) = -30;
motor(claw2) = -30;  ///////SETUP SECTION///LENGTH: .15 SECODNS////

motor[Leftarm] = -90; //////This lifts arm so arm does not immediantly hit floor////
motor[port6] = -90; //bottom left
motor[Rightarm] = 90;
motor[port9]= 90; //bottom right

motor(Leftside) = -50; //////This moves us back slightly so arm doesnt hit stars
motor(Rightside) = -50;
wait(0.3);
motor(claw) = 0;
motor(claw2) = 0;

wait(0.4);
motor[Leftarm] = -0; //////This lifts arm so arm does not immediantly hit floor////
motor[port6] = -0; //bottom left
motor[Rightarm] = 0;
motor[port9]= 0; //bottom right

motor(Leftside) = -0; //////This moves us back slightly so arm doesnt hit stars
motor(Rightside) = -0;

}

else if(chooseautonomous==3)
{
	motor[Leftarm] = -100; //////This lifts arm so arm does not immediantly hit floor////
motor[port6] = -100; //bottom left
motor[Rightarm] = 100;
motor[port9]= 100;

wait(0.3);

repeat(30){
	motor[Leftarm] = 0; //////This lifts arm so arm does not immediantly hit floor////
motor[port6] = 0; //bottom left
motor[Rightarm] = 0;
motor[port9]= 0;
wait(0.3);
motor[Leftarm] = -100; //////This lifts arm so arm does not immediantly hit floor////
motor[port6] = -100; //bottom left
motor[Rightarm] = 100;
motor[port9]= 100;
wait(0.3);
motor[Leftarm] = 0; //////This lifts arm so arm does not immediantly hit floor////
motor[port6] = 0; //bottom left
motor[Rightarm] = 0;
motor[port9]= 0;
wait(0.3);
motor[Leftarm] = 100; //////This lifts arm so arm does not immediantly hit floor////
motor[port6] = 100; //bottom left
motor[Rightarm] = -100;
motor[port9]= -100;
wait(0.3);
}

motor[Leftarm] = 0; //////This lifts arm so arm does not immediantly hit floor////
motor[port6] = 0; //bottom left
motor[Rightarm] = -0;
motor[port9]= -0;

}
else
{
autonomousexe();

}

	/*
Just call the void for autonomous
Its easier to call it if it isnt
in two places at once

	*/
}


/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////




task movement()
{

	motor[Rightside] = vexRT[Ch2]; /////The wheels directly spin
	motor[Leftside] = vexRT[Ch3];//////With the imput of the joysticks

	if(vexRT[Btn8L]==1)
	{
		motor[Rightside] = 30;
		motor[Leftside] = -30;

	}

	if(vexRT[Btn8R]==1)
	{
		motor[Rightside] = -30;
		motor[Leftside] = 30;
	}

	else
	{
	motor[Rightside] = vexRT[Ch2]; /////The wheels directly spin
	motor[Leftside] = vexRT[Ch3];//////With the imput of the joysticks

	}



}

int gotoarm = 0; /////This int is not being used on purpose
																////////It is here to use the debug menu to quickly
																////////Navigate through the code by double clicking
void launchforme()
{
	stopTask(usercontrol);

	motor(Leftside)=-127;
	motor(Rightside)=-127;
	motor[Leftarm] = -127; //////This lifts arm so arm does not immediantly hit floor////
  motor[port6] = -127; //bottom left
  motor[Rightarm] = 127;
  motor[port9]= 127;
  wait(1);
  motor(claw)=127;
  motor(claw)=127;
  wait(0.6);
  motor(Leftside)=-0;
	motor(Rightside)=-0;

	motor[Leftarm] = -0; //////This lifts arm so arm does not immediantly hit floor////
  motor[port6] = -0; //bottom left
  motor[Rightarm] = 0;
  motor[port9]= 0;

  motor(claw)=0;
  motor(claw)=0;

  startTask(usercontrol);
}




task shooting()
{

	if (vexRT[Btn6D]==1 )
	{
		motor[Leftarm] = -127;
		motor[port6] = -127; //bottom left
		motor[Rightarm] = 127;
		motor[port9]= 127; //bottom right
	}
	else if (vexRT[Btn5D]==1 && SensorValue(in8)<2300)
	{
		motor[Leftarm] = 127;
		motor[port6]=127; //bottom left
		motor[Rightarm] = -127;
		motor[port9]= -127; //bottom right
		turnLEDOff(Yellow);
	}

	else if (vexRT[Btn5D]==1 && (SensorValue(in8)<4000 && SensorValue(in8)>2300))
	{
	turnLEDOn(Yellow);
		motor[Leftarm] = 30;
		motor[port6]=30; //bottom left
		motor[Rightarm] = -30;
		motor[port9]= -30;
	}

	else if (vexRT[Btn7R]==1)
	{
			motor[Leftarm] = 127;
		motor[port6]=127; //bottom left
		motor[Rightarm] = -127;
		motor[port9]= -127; //bottom right
	}

	else
	{
		motor[Leftarm] = 0;
		motor[port6] = 0; //bottom left
		motor[Rightarm] = 0;
		motor[port9] = 0; //bottom right
	}

	if(vexRT[Btn7L]==1)
	{
		launchforme();
	}


}

int gotoclaw = 0;
//used to quickly navigate to claw code////
int toggleclawspeed = 0;




task theclaaaaawwww()
{
	if(vexRT[Btn6U]==1)
	{
		motor[claw] = 127; //left side claw
		motor[claw2] = 127; // right side claw
	}


	else if(vexRT[Btn5U]==1)
	{

		motor[claw] = -127; //left side claw
		motor[claw2] = -127; //right side claw
	}

	else if(vexRT[Btn7U]==1)
	{
		toggleclawspeed = 40;
	}

		else if(vexRT[Btn7D]==1)
	{
		toggleclawspeed = 0;
	}

	else
	{
	if(dunderedoneclawpotendontdunworkin > 775)
	{
			motor[claw] = toggleclawspeed*-1;
		motor[claw2] = toggleclawspeed*-1;
	}

	else if(dunderedoneclawpotendontdunworkin < 774)
	{
	motor[claw] = 0;
	motor[claw] =0;
	}

	}


}
int gotointstuff = 0;


task intstuff()
{
	dumbpotentiometerthignalisonwants = SensorValue(Leverangle);
	////////For testing if the encoder is working in the debug menu
	dunderedoneclawpotendontdunworkin = SensorValue(clawwidth);
greekfoodlevel = SensorValue(greeksensor);

	if(nLCDButtons==1)
	{
		chooseautonomous = 1;

	}

	if(nLCDButtons==2)
	{
		chooseautonomous = 2;
	}


}

task batterytest()
{

bLCDBacklight = true;                                    // Turn on LCD Backlight
string mainBattery, backupBattery;

clearLCDLine(0);                                            // Clear line 1 (0) of the LCD
clearLCDLine(1);                                            // Clear line 2 (1) of the LCD

//Display the Primary Robot battery voltage
displayLCDString(0, 0, "Primary: ");
sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
displayNextLCDString(mainBattery);

//Display the Backup battery voltage
displayLCDString(1, 0, "Backup: ");
sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
displayNextLCDString(backupBattery);

//Short delay for the LCD refresh rate
wait1Msec(100);



}


task displayautonomous()
{

	if(chooseautonomous==1) ////GREEN IS Leftside (Go right)
	{
		turnLEDOn(Green);
		turnLEDOff(Red);

	}

	else if(chooseautonomous==0)
	{
		turnLEDOn(Green);
		turnLEDOn(Red);

	}

	else
	{
		turnLEDOff(Green); ///RED IS rightside (go left)
		turnLEDOn(Red);


	}
}




task usercontrol()
{
	SensorType[in1] = sensorNone;
	wait(1);
	SensorType[in1] = sensorGyro;
	wait(2);
	// User control code here, inside the loop //
	while(1==1)
	{
		///All the tasks run at the same time, to remove
	 ////accidental priority with the code reading
  	///also it's easier to manage

		startTask (movement);
		startTask (shooting);
		startTask (theclaaaaawwww);
		startTask (intstuff);

	startTask(batterytest);
	startTask(displayautonomous);


	//	startTask (autonomousbutton);

	}
}
int stuffstorage = 0;

/*
old autonomous startup
motor(claw) = -30;
motor(claw2) = -30;  ///////SETUP SECTION///LENGTH: .15 SECODNS////

motor[Leftarm] = -85; //////This lifts arm so arm does not immediantly hit floor////
motor[port6] = -85; //bottom left
motor[Rightarm] = 85;
motor[port9]= 85; //bottom right

motor(Leftside) = -50; //////This moves us back slightly so arm doesnt hit stars
motor(Rightside) = -50;
*/

	/*
void autonomousexe2() /////////////OLD AUTONOMOUS/////////////////
{

	motor(Leftside) = 127;
	motor(Rightside) = 127;
	motor(Rightarm) = 35;
	motor(Leftarm) = -35;

	wait(2.4); /////This code simply moves forward and attempts to knock
						////// off a star

	motor(Leftside)=0;
	motor(Rightside) = 0;

	motor(Rightarm) = 0;
	motor(Leftarm) = 0;



	wait(3);
}
*/
