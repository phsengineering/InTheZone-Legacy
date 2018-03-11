#pragma config(Motor,  port2,           Left1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           Left2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Right1,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Right2,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true)
	{
		while (vexRT[Btn7D] == 1)
		{
			motor[port2] = -50;
			motor[port3] = -50;
			motor[port4] = 50;
			motor[port5] = 50;
		}
		while (vexRT[Btn7L] == 1)
		{
			motor[port2] = 50;
			motor[port3] = 50;
			motor[port4] = -50;
			motor[port5] = -50;
		}
		while (vexRT[Btn7U] == 1)
		{
			motor[port2] = 0;
			motor[port3] = 0;
			motor[port4] = 0;
			motor[port5] = 0;
		}
	}
}