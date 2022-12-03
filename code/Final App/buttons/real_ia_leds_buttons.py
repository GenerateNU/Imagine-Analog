from gpiozero import LED, Button
from signal import pause

ledRG = LED(2)
buttonRG = Button(3)

buttonRG.when_pressed = ledRG.on
buttonRG.when_released = ledRG.off
pause()