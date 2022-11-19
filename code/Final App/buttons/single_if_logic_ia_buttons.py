import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

#RB
ledRB = 2
buttonRB = 3

GPIO.setup(ledRB, GPIO.OUT)
GPIO.setup(buttonRB, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
    buttonState = GPIO.input(buttonRB)
    if buttonState == False:
        GPIO.output(ledRB, GPIO.HIGH)
    else:
        GPIO.output(ledRB, GPIO.LOW)
