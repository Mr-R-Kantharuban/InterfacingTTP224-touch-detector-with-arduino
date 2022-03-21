# InterfacingTTP224-touch-detector-with-arduino
Interfacing TTP224 Touch sensor with arduino


In this circuit, we power the LEDs through a 3v Arduino pin, but if an external power source is used, 
one must connect the ground of the Arduino to the ground of the power. The TTP224 module has respective status pins for its touchpad keys.
The inbuilt status pin will indicate which key is touched.  After making connections, upload the Arduino code. 
When any key is touched, the LED flashes a color according to the code, and the serial monitor will display the current state of the key.
The results can be seen through the LED and Serial Monitor as well.
