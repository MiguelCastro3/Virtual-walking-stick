# Virtual-walking-stick
**PROJECT:** 

Implementation of an embedded system capable of measuring the accelerations resulting from a person's leg, using an accelerometer.


**STEPS:** 

* Construction of the acquisition circuit for the accelerometer
* Programming the 324A microcontroller for signal processing
* Development of an interface for viewing acquired signals

**SCHEMATIC CIRCUIT:**
![ATMEGA324A ligações](https://user-images.githubusercontent.com/66881028/84780506-90c9d100-afdd-11ea-9515-69c7dad7ffc9.PNG)

**FILES:** 

* [Interface_BA.m](https://github.com/MiguelCastro3/Monitoring-a-person-s-acceleration/blob/master/Interface_BA.m) - code for the acquisition of the accelerometer signals (3 channels), processing and conversion of the signals and sending to the computer via the serial port.
* [main.asm](https://github.com/MiguelCastro3/Monitoring-a-person-s-acceleration/blob/master/main.asm) - code referring to the processing of signals received from the microntroller and repetitive display through a previously created interface.


**RESULTS:** 

[video_project_real_time.zip](https://github.com/MiguelCastro3/Monitoring-a-person-s-acceleration/files/4782737/video_project_real_time.zip) - short video showing the operation of the interface, in real time, in the acquisition and respective display of the acquired signals from the accelerometer.

![Sem Título](https://user-images.githubusercontent.com/66881028/84701968-cf17af80-af4d-11ea-9e2f-c6169008d918.png)
