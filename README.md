# NeoPixelAfterBurner
Arduino + Neopixel/WS2812B LED strip + RC throttle channel input (PWM) => after burner effect for EDF RC jets.

Related hread on RC Groups: https://www.rcgroups.com/forums/showthread.php?2864213-DIY-afterburner-led-ring-for-EDF-jets-with-arduino-WS2812B

This has been tested on a Arduino Pro mini, but it should work with most arduinos
Very simple hardware:
  - +5V power for the Arduino and the NeoPixel LED strip.
  - PWM signal (coming from a RC receiver, the throttle channel usually) connected to the pin 5 (PWM_PIN) of the arduino.
  - Data (ouput) from pin 6 (PIN) of the arduino to the data input of the led strip.
  
Note: to program an Arduino Pro mini you need an USB-Serial adapter.  Or you can use an Arduino nano,
with integrated USB connection.
