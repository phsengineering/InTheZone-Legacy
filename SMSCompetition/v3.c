#pragma config(Motor,  port10,           armAngle,      tmotorVex393_MC29, openLoop)

task main()
{
	while(true) {
	if(vexRT[Btn6U] == 1) {
		motor[armAngle] = 63;

	}
	else {
		motor[armAngle] = 0;

	}
}

}
