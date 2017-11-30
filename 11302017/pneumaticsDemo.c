#pragma config(Sensor, dgtl7,  solenoid,            sensorDigitalOut)
task main()
{
while(true)                   // Loop Forever
{
if(vexRT[Btn6U] == 1)           // If upper right shoulder button is pressed:
{
SensorValue[solenoid] = 1;  //activate said solenoid
}
else // If button 6U (upper right shoulder button) is  NOT pressed:
{
SensorValue[solenoid] = 0;  // ..deactivate the solenoid.
}
}
}
