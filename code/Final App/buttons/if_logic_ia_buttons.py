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

#R
ledR = 15
buttonR = 14

GPIO.setup(ledR, GPIO.OUT)
GPIO.setup(buttonR, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
    buttonState = GPIO.input(buttonR)
    if buttonState == False:
        GPIO.output(ledR, GPIO.HIGH)
    else:
        GPIO.output(ledR, GPIO.LOW)
        
#RG
ledRG = 17
buttonRG = 18

GPIO.setup(ledRG, GPIO.OUT)
GPIO.setup(buttonRG, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
    buttonState = GPIO.input(buttonRG)
    if buttonState == False:
        GPIO.output(ledRG, GPIO.HIGH)
    else:
        GPIO.output(ledRG, GPIO.LOW)

#P
ledP = 22
buttonP = 23

GPIO.setup(ledP, GPIO.OUT)
GPIO.setup(buttonP, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
    buttonState = GPIO.input(buttonP)
    if buttonState == False:
        GPIO.output(ledP, GPIO.HIGH)
    else:
        GPIO.output(ledP, GPIO.LOW)

#B
ledB = 9
buttonB = 10

GPIO.setup(ledB, GPIO.OUT)
GPIO.setup(buttonB, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
    buttonState = GPIO.input(buttonB)
    if buttonState == False:
        GPIO.output(ledB, GPIO.HIGH)
    else:
        GPIO.output(ledB, GPIO.LOW)
        
#G
ledG = 7
buttonG = 8

GPIO.setup(ledG, GPIO.OUT)
GPIO.setup(buttonG, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
    buttonState = GPIO.input(buttonG)
    if buttonState == False:
        GPIO.output(ledG, GPIO.HIGH)
    else:
        GPIO.output(ledG, GPIO.LOW)
        
#create a function called check button or led state
#put buttons in a list
#maybe need to add code if multiple buttons are pressed at once
#for button in, set list, will go through all of them
