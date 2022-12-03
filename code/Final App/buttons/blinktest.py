from gpiozero import LED
from signal import pause
button = LED(2)
button.blink(2,1,5) # 2 seconds on, 1 second off, 5 blinks