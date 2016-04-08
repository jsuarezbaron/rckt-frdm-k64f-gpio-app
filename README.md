# GPIO output on the Freedom K64F board

This application demonstrates GPIO input and output on the Freedom K64F board. The on-board RGB LED cycles through color combinations and reads the state of switch SW3.

The application sets the on-board RGB LED to display its color combinations. While switch SW3 is pressed, the LED does not change the LED color.

## Sample Output

The application's serial output confirms the GPIO pin configuration and describes the color combination shown on the RGB LED, such as:

```
Pin 4 of GPIO Port A configured
Pin 22 of GPIO Port B configured
Pin 21 of GPIO Port B configured
Pin 26 of GPIO Port E configured
LED is OFF
LED is Red
LED is Blue
LED is Green
LED is Red+Blue
LED is Red+Green
LED is Blue+Green
LED is Red+Blue+Green
LED is OFF
```

The current LED color combination is continually updated.

##More Information

Instructions for running this example are available from the [example wiki](https://github.com/wind-river-rocket/rckt-frdm-k64f-gpio-app/wiki).
