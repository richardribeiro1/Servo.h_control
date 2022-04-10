/* Created by Richard Ribeiro
    richard.ribeiro1@gmail.com

    Code to be used with <Servo.h> library to control the movement speed and range of servos.
*/

#include <Servo.h>

Servo servo1; //create servo object to control a servo

int actualPosition = 0;

void setup() {
  servo1.attach(9); //attaches the servo on pin 9 to the servo object
  servo1.writeMicroseconds(1500); //set servo to mid-point
  //On standard servos a parameter value is between 700 to 2300. Check the datasheet of your servo for more information.
}

void loop() {
  actualPosition = servo1.readMicroseconds(); //reading the actual position of the servo in microseconds
  servoControl(actualPosition, 2300, 10); //moving from actual position to 2300 in speed of 10
  actualPosition = servo1.readMicroseconds(); //reading the actual position of the servo in microseconds
  servoControl(actualPosition, 1500, 5); //moving from actual position to 1500 in speed of 10
  
  /*
     this function is useful when you want to control de speed of movement using the <Servo.h> library
     
      pros:
      total control of the movement speed
      can read the actual position

      cons:
      limited number of servos
      uses a lot of pins in the board

      Depending of the aplication you can use the PCA9685 to control 16+ servos
      For this case, check my github.
      www.github.com/richardribeiro1
  */
  
}

void servoControl(int posInitial, int posFinal, int speed) {
  int position;
  position = posInitial;

  if (posInitial < posFinal) { //increasing
    for (position; position < posFinal; position += speed) {
      if (position >= posFinal - speed) { //avoid overflow
        servo1.writeMicroseconds(posFinal);
        delay(5);
      }
      else {
        servo1.writeMicroseconds(position);
        delay(5);
      }
    }
  }
  else { //decreasing
    for (position; position > posFinal; position -= speed) {
      if (position <= posFinal + speed) { //avoid overflow
        servo1.writeMicroseconds(posFinal);
        delay(5);
      }
      else {
        servo1.writeMicroseconds(position);
        delay(5);
      }
    }
  }
}
