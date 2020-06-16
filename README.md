# Virtual-walking-stick
**PROJECT:** 

Creation of a virtual cane (embedded system), without contact with the ground, in order to assist the gait of a blind person.

**STEPS:** 

* Construction of the schematic circuit of the project, which included: Arduino, ultrasonic sensor, two types of alarms (audible and vibrating) and power supply
* Arduino programming, in C ++, for signal processing and respective appropriate response
* Development of a prototype case to protect the entire circuit

**SCHEMATIC CIRCUIT:**
![Sem Título](https://user-images.githubusercontent.com/66881028/84805183-c67db280-affb-11ea-938a-ba4f84767e89.png)

**FILES:** 

* [Interface_BA.m](https://github.com/MiguelCastro3/Monitoring-a-person-s-acceleration/blob/master/Interface_BA.m) - code for the acquisition of the accelerometer signals (3 channels), processing and conversion of the signals and sending to the computer via the serial port.
* [main.asm](https://github.com/MiguelCastro3/Monitoring-a-person-s-acceleration/blob/master/main.asm) - code referring to the processing of signals received from the microntroller and repetitive display through a previously created interface.


**RESULTS:** 

[video_project_real_time.zip](https://github.com/MiguelCastro3/Monitoring-a-person-s-acceleration/files/4782737/video_project_real_time.zip) - short video showing the operation of the interface, in real time, in the acquisition and respective display of the acquired signals from the accelerometer.

![Sem Título](https://user-images.githubusercontent.com/66881028/84701968-cf17af80-af4d-11ea-9e2f-c6169008d918.png)
