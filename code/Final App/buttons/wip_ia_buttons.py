import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

#leds = [lRG, lRB, lR, lG, lB, lP]
#buttons = [bRG, bRB, bR, bG, bB, bP]

#RB
#ledRB = 2
#buttonRB = 3

ledChannel = [17,2,14,7,9,22] #[lRG, lRB, lR, lG, lB, lP]
buttonChannel = [18,3,15,8,10,23] #[bRG, bRB, bR, bG, bB, bP]

GPIO.setup(ledChannel, GPIO.OUT)
GPIO.setup(buttonChannel, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
    for x in buttonChannel:
        buttonState = GPIO.input(x) #x = output pin for buttons, scrolling through list
        if buttonState == False:
            GPIO.output((x-1), GPIO.HIGH) #x-1 = LED for corresponding button (i.e. lR for bR)
        else:
            GPIO.output((x-1), GPIO.LOW)

#create a function called check button or led state
#put buttons in a list
#maybe need to add code if multiple buttons are pressed at once
#for button in, set list, will go through all of them