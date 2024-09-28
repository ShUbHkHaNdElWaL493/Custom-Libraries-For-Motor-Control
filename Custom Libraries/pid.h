/*
  Shubh Khandelwal
*/

#ifndef PID_H
#define PID_H

#include "actuator.h"

#ifndef PWMLimit
#define PWMLimit 255
#endif

class MD10C_PID
{

  private:

  // Motor for which the PID is implemented
  MD10C_integrated_encoder_motor *motor;

  // Variables required for PID
  float Kp, Ki, Kd;
  int target;
  float component_p, component_i, component_d;

  public:

  float speed_pwm;

  MD10C_PID(MD10C_integrated_encoder_motor *Motor, float Kp, float Ki, float Kd)
  {
    this->motor = motor;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->target = 0;
    this->speed_pwm = 0;
    this->component_p = 0;
    this->component_i = 0;
    this->component_d = 0;
  }

  void set_target(int target)
  {
    this->target = target;
    this->component_p = 0;
    this->component_i = 0;
    this->component_d = 0;
  }

  void implement_position_PID()
  {
    this->component_d = this->component_p;
    this->component_p = this->component_i;
    this->component_i = this->target - this->motor->getPosition();
    this->component_p = this->component_i - this->component_p;
    this->component_d = this->component_p - this->component_d;
    this->speed_pwm += Kp * this->component_p + Ki * this->component_i + Kd * this->component_d;
    if (speed_pwm < -(PWMLimit))
    {
      speed_pwm = -(PWMLimit);
    }
    if (speed_pwm > PWMLimit)
    {
      speed_pwm = PWMLimit;
    }
  }

  void implement_velocity_PID()
  {
    this->component_d = this->component_p;
    this->component_p = this->target - this->motor->getSpeed();
    this->component_d = this->component_p - this->component_d;
    this->component_i += this->component_p;
    this->speed_pwm += Kp * this->component_p + Ki * this->component_i + Kd * this->component_d;
    if (speed_pwm < -(PWMLimit))
    {
      speed_pwm = -(PWMLimit);
    }
    if (speed_pwm > PWMLimit)
    {
      speed_pwm = PWMLimit;
    }
  }

};

class ZK5AD_PID
{

  private:

  // Motor for which the PID is implemented
  ZK5AD_integrated_encoder_motor *motor;

  // Variables required for PID
  float Kp, Ki, Kd;
  int target;
  float component_p, component_i, component_d;

  public:

  float speed_pwm;

  ZK5AD_PID(ZK5AD_integrated_encoder_motor *Motor, float Kp, float Ki, float Kd)
  {
    this->motor = motor;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->target = 0;
    this->speed_pwm = 0;
    this->component_p = 0;
    this->component_i = 0;
    this->component_d = 0;
  }

  void set_target(int target)
  {
    this->target = target;
    this->component_p = 0;
    this->component_i = 0;
    this->component_d = 0;
  }

  void implement_position_PID()
  {
    this->component_d = this->component_p;
    this->component_p = this->component_i;
    this->component_i = this->target - this->motor->getPosition();
    this->component_p = this->component_i - this->component_p;
    this->component_d = this->component_p - this->component_d;
    this->speed_pwm += Kp * this->component_p + Ki * this->component_i + Kd * this->component_d;
    if (speed_pwm < -(PWMLimit))
    {
      speed_pwm = -(PWMLimit);
    }
    if (speed_pwm > PWMLimit)
    {
      speed_pwm = PWMLimit;
    }
  }

  void implement_velocity_PID()
  {
    this->component_d = this->component_p;
    this->component_p = this->target - this->motor->getSpeed();
    this->component_d = this->component_p - this->component_d;
    this->component_i += this->component_p;
    this->speed_pwm += Kp * this->component_p + Ki * this->component_i + Kd * this->component_d;
    if (speed_pwm < -(PWMLimit))
    {
      speed_pwm = -(PWMLimit);
    }
    if (speed_pwm > PWMLimit)
    {
      speed_pwm = PWMLimit;
    }
  }

};

class L298N_PID
{

  private:

  // Motor for which the PID is implemented
  L298N_integrated_encoder_motor *motor;

  // Variables required for PID
  float Kp, Ki, Kd;
  int target;
  float component_p, component_i, component_d;

  public:

  float speed_pwm;

  L298N_PID(L298N_integrated_encoder_motor *Motor, float Kp, float Ki, float Kd)
  {
    this->motor = motor;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->target = 0;
    this->speed_pwm = 0;
    this->component_p = 0;
    this->component_i = 0;
    this->component_d = 0;
  }

  void set_target(int target)
  {
    this->target = target;
    this->component_p = 0;
    this->component_i = 0;
    this->component_d = 0;
  }

  void implement_position_PID()
  {
    this->component_d = this->component_p;
    this->component_p = this->component_i;
    this->component_i = this->target - this->motor->getPosition();
    this->component_p = this->component_i - this->component_p;
    this->component_d = this->component_p - this->component_d;
    this->speed_pwm += Kp * this->component_p + Ki * this->component_i + Kd * this->component_d;
    if (speed_pwm < -(PWMLimit))
    {
      speed_pwm = -(PWMLimit);
    }
    if (speed_pwm > PWMLimit)
    {
      speed_pwm = PWMLimit;
    }
  }

  void implement_velocity_PID()
  {
    this->component_d = this->component_p;
    this->component_p = this->target - this->motor->getSpeed();
    this->component_d = this->component_p - this->component_d;
    this->component_i += this->component_p;
    this->speed_pwm += Kp * this->component_p + Ki * this->component_i + Kd * this->component_d;
    if (speed_pwm < -(PWMLimit))
    {
      speed_pwm = -(PWMLimit);
    }
    if (speed_pwm > PWMLimit)
    {
      speed_pwm = PWMLimit;
    }
  }

};

#endif