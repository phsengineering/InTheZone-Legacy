#pragma config(Sensor, dgtl3,  solenoid,            sensorDigitalOut)
task main()
{
SensorValue[dgtl3] = 0;
wait(1);
SensorValue[dgtl3] = 1;
wait(1);
SensorValue[dgtl3] = 0;
}
