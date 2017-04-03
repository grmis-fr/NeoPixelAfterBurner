# NeoPixelAfterBurner
Arduino + Neopixel/WS2812B LED strip + RC throttle channel input (pwm) => after burner effect for EDF jets
This has been tested on a Arduino Pro mini, but it should work with most arduinos
Very simple hardware:
  - +5V power for the Arduino and the NeoPixel LED strip
  - PWM signal (coming from a RC receiver, the throttle channel usually) on pin 5 (PWM_PIN) the arduino
  - Data (ouput) from pin 6 (PIN) of the arduino to the data input of the led strip
Note: to program an Arduino Pro mini you need an USB-Serial adapter.  Or you can use an Arduino nano,
with integrated USB connection.
