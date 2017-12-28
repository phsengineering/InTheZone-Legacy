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

		// "precise control" buttons
		if(vexRT[Btn5D] + vexRT[Btn5U] + vexRT[Btn6D] + vexRT[Btn6U] > 0)
		{
			left_drive_pwr *= 0.7;
			right_drive_pwr *= 0.7;
		}

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
