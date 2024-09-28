/*
	Shubh Khandelwal
*/

#ifndef ACTUATOR_H
#define ACTUATOR_H

class MD10C_integrated_encoder_motor
{

  private:

  // Motor and Encoder Pins
  uint8_t direction, pwm, encoderA, encoderB;
  
  // Pulses of the encoder
  volatile int pulseCount;

  // Function to stop the motor
  void stop()
  {
    analogWrite(pwm, 0);
  }

  // Function to rotate the motor anti-clockwise
  void rotateAntiClockwise(int speed)
  {
    digitalWrite(direction, LOW);
    analogWrite(pwm, speed);
  }

  // Function to rotate the motor clockwise
  void rotateClockwise(int speed)
  {
    digitalWrite(direction, HIGH);
    analogWrite(pwm, speed);
  }

  public:

  // Constructor for this class
  MD10C_integrated_encoder_motor(uint8_t direction, uint8_t pwm, uint8_t encoderA = 0, uint8_t encoderB = 0)
  {
    this->direction = direction;
    this->pwm = pwm;
    this->encoderA = encoderA;
    this->encoderB = encoderB;
    this->pulseCount = 0;
    pinMode(this->direction, OUTPUT);
    pinMode(this->pwm, OUTPUT);
    pinMode(this->encoderA, INPUT_PULLUP);
    pinMode(this->encoderB, INPUT_PULLUP);
  }

  // Function to rotate the motor
  void rotate(float speed)
  {
    if (speed > 0 && speed <= 255)
    {
      rotateAntiClockwise(speed);
    } else if (speed < 0 && speed >= -255)
    {
      rotateClockwise((-1) * speed);
    } else
    {
      stop();
    }
  }

  // Functions for changing the pulse count

  void changePulseCount0()
  {
    if (digitalRead(encoderB) == LOW)
    {
      pulseCount++;
    } else
    {
      pulseCount--;
    }
  }

  void changePulseCount1()
  {
    if (digitalRead(encoderA) == LOW)
    {
      pulseCount--;
    } else
    {
      pulseCount++;
    }
  }
  
  // Function to get the position of the motor
  float getPosition()
  {
    return pulseCount;
  }

  // Function to get the speed of the motor
  float getSpeed()
  {
    long pulseCountI = this->pulseCount;
    delay(10);
    long pulseCountF = this->pulseCount;
    return (pulseCountF - pulseCountI) * 100;
  }

};

class ZK5AD_integrated_encoder_motor
{

  private:

  // Motor and Encoder Pins
  uint8_t motorA, motorB, encoderA, encoderB;
  
  // Pulses of the encoder
  volatile int pulseCount;
  
  // Function to stop the motor
  void stop()
  {
    analogWrite(motorA, 0);
    analogWrite(motorB, 0);
  }

  // Function to rotate the motor anti-clockwise
  void rotateAntiClockwise(int speed)
  {
    analogWrite(motorB, 0);
    analogWrite(motorA, speed);
  }

  // Function to rotate the motor clockwise
  void rotateClockwise(int speed)
  {
  	analogWrite(motorA, 0);
    analogWrite(motorB, speed);
  }

  public:

  // Constructor for this class
  ZK5AD_integrated_encoder_motor(uint8_t motorA, uint8_t motorB, uint8_t encoderA = 0, uint8_t encoderB = 0)
  {
    this->motorA = motorA;
    this->motorB = motorB;
    this->encoderA = encoderA;
    this->encoderB = encoderB;
    this->pulseCount = 0;
    pinMode(this->motorA, OUTPUT);
    pinMode(this->motorB, OUTPUT);
    pinMode(this->encoderA, INPUT_PULLUP);
    pinMode(this->encoderB, INPUT_PULLUP);
  }

  // Function to rotate the motor
  void rotate(float speed)
  {
    if (speed > 0 && speed <= 255)
    {
      rotateAntiClockwise(speed);
    } else if (speed < 0 && speed >= -255)
    {
      rotateClockwise((-1) * speed);
    } else
    {
      stop();
    }
  }

  // Functions for changing the pulse count

  void changePulseCount0()
  {
    if (digitalRead(encoderB) == LOW)
    {
      pulseCount++;
    } else
    {
      pulseCount--;
    }
  }

  void changePulseCount1()
  {
    if (digitalRead(encoderA) == LOW)
    {
      pulseCount--;
    } else
    {
      pulseCount++;
    }
  }
  
  // Function to get the position of the motor
  float getPosition()
  {
    return pulseCount;
  }
  
  // Function to get the speed of the motor
  float getSpeed()
  {
    long pulseCountI = this->pulseCount;
    delay(10);
    long pulseCountF = this->pulseCount;
    return (pulseCountF - pulseCountI) * 100;
  }

};

class L298N_integrated_encoder_motor
{

  private:

  // Motor and Encoder Pins
  uint8_t enable, motorA, motorB, encoderA, encoderB;
  
  // Pulses of the encoder
  volatile int pulseCount;
  
  // Function to stop the motor
  void stop()
  {
    analogWrite(enable, 0);
  }

  // Function to rotate the motor anti-clockwise
  void rotateAntiClockwise(int speed)
  {
    digitalWrite(motorB, LOW);
    digitalWrite(motorA, HIGH);
    analogWrite(enable, speed);
  }

  // Function to rotate the motor clockwise
  void rotateClockwise(int speed)
  {
  	digitalWrite(motorA, LOW);
    digitalWrite(motorB, HIGH);
    analogWrite(enable, speed);
  }

  public:

  // Constructor for this class
  L298N_integrated_encoder_motor(uint8_t enable, uint8_t motorA, uint8_t motorB, uint8_t encoderA = 0, uint8_t encoderB = 0)
  {
    this->enable = enable;
    this->motorA = motorA;
    this->motorB = motorB;
    this->encoderA = encoderA;
    this->encoderB = encoderB;
    this->pulseCount = 0;
    pinMode(this->enable, OUTPUT);
    pinMode(this->motorA, OUTPUT);
    pinMode(this->motorB, OUTPUT);
    pinMode(this->encoderA, INPUT_PULLUP);
    pinMode(this->encoderB, INPUT_PULLUP);
  }

  // Function to rotate the motor
  void rotate(float speed)
  {
    if (speed > 0 && speed <= 255)
    {
      rotateAntiClockwise(speed);
    } else if (speed < 0 && speed >= -255)
    {
      rotateClockwise((-1) * speed);
    } else
    {
      stop();
    }
  }

  // Functions for changing the pulse count

  void changePulseCount0()
  {
    if (digitalRead(encoderB) == LOW)
    {
      pulseCount++;
    } else
    {
      pulseCount--;
    }
  }

  void changePulseCount1()
  {
    if (digitalRead(encoderA) == LOW)
    {
      pulseCount--;
    } else
    {
      pulseCount++;
    }
  }
  
  // Function to get the position of the motor
  float getPosition()
  {
    return pulseCount;
  }
  
  // Function to get the speed of the motor
  float getSpeed()
  {
    long pulseCountI = this->pulseCount;
    delay(10);
    long pulseCountF = this->pulseCount;
    return (pulseCountF - pulseCountI) * 100;
  }

};

class TB6600_stepper
{

  private:
  
  // Motor Pins
  uint8_t direction, pulse;
  
  // Duration of one step
  int step_duration;
  
  // Function to rotate the motor anti-clockwise
  void rotateAntiClockwise(int steps)
  {
    digitalWrite(direction, LOW);
    for (int i = 0; i < steps; i++)
    {
      digitalWrite(pulse, HIGH);
      delayMicroseconds(step_duration);
      digitalWrite(pulse, LOW);
      delayMicroseconds(step_duration);
    }
  }

  // Function to rotate the motor clockwise
  void rotateClockwise(int steps)
  {
    digitalWrite(direction, HIGH);
    for (int i = 0; i < steps; i++)
    {
      digitalWrite(pulse, HIGH);
      delayMicroseconds(step_duration);
      digitalWrite(pulse, LOW);
      delayMicroseconds(step_duration);
    }
  }
  
  public:
  
  TB6600_stepper(uint8_t direction, uint8_t pulse, int step_duration)
  {
    this->direction = direction;
    this->pulse = pulse;
    this->step_duration = step_duration;
    pinMode(this->direction, OUTPUT);
    pinMode(this->pulse, OUTPUT);
  }
  
  void rotate(int steps)
  {
    if (steps > 0)
    {
      rotateAntiClockwise(steps);
    } else if (steps < 0)
    {
      rotateClockwise((-1) * steps);
    }
  }

};

#endif
