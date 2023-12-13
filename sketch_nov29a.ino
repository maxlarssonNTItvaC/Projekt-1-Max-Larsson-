#include <IRremote.h>
#include <Servo.h>
#define IR_RECEIVE_PIN 8

Servo myservo;

bool state = false;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
  int value = 0;
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    value = IrReceiver.decodedIRData.command;
  }

  if (value == 64) {
    state = !state;
    delay(1000);
    Serial.println(state);
  }

  if (state == true) {
delay (1000);
     myservo.write(180);

  } else {

     myservo.write(0);
  }
}
