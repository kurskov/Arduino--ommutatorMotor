[![GitHub](https://img.shields.io/github/license/kurskov/Arduino-BrushedMotor)](https://github.com/kurskov/Arduino-BrushedMotor/blob/main/LICENSE)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/kurskov/Arduino-BrushedMotor)](https://github.com/kurskov/Arduino-BrushedMotor/releases/latest)

# Brushed motor

Library for controlling a brushed motor on the Arduino platform.

The library supports two driver modes:

### 2-wire

| Mode | IN1 | IN2 | 
| - | - | - | 
| Forward | HIGH / PWM | LOW | 
| Backward | LOW / PWM | HIGH | 
| Stop | LOW | LOW | 
| Brake | HIGH | HIGH | 

### 3-wire

| Mode | IN1 | IN2 | EN |
| - | - | - | - |
| Forward | HIGH | LOW | PWM |
| Backward | LOW | HIGH | PWM |
| Stop | LOW | LOW | 0 |
| Brake | HIGH | HIGH | PWM |

The rotation speed is controlled by a PWM channel with a resolution of 8 bits (0-255).  
The direction of rotation is determined by the sign of the speed value.

## Compatibility

Compatible with all Arduino platforms (using Arduino functions).

Supported drivers: L298N, L9110S, MX1508, TA6586, TB6612.

## How to use

### Include library

```c++
#include "BrushedMotor.h"
```

### Initialization

#### For 2-wire connection:

```c++
BrushedMotor motor(IN1, IN2);
```

IN1 - PWM pin  
IN2 - digital or PWM pin


#### For 3-wire connection:

```c++
BrushedMotor motor(IN1, IN2, EN);
```

IN1, IN2 - digital or PWM pins  
EN - PWM pin


### Basic functions

#### Run

Runs motor with set speed.  
Changes speed if motor is running.
```c++
void run(int16_t speed);
```
If you set the value as 0, the motor will stop.  
Sign of speed value sets turn direction:
- positive is forward
- negative is backward

If you do not specify a speed, the motor will run at the last set speed. See [example](#example).

#### Stop

Smooth motor stop.
```c++
void stop();
```
Calling this function does not change the set speed.  
This function is also called when the rotation speed is set to 0.

#### Brake

Motor blocking.
```c++
void brake();
```
Calling this function does not change the set speed.

### Get state of motor

#### Get direction of rotation

State of the motor.
```c++
int8_t getState();
```
Returns one of three chooses:
- 1 - motor rotates forward
- 0 - motor stopped
- -1 - motor rotates backward

## Example

```c++
#include <BrushedMotor.h>

BrushedMotor motor(5, 6);
// or motor(5, 6, 11) for 3-wire connection

void setup() {
}

void loop() {
    motor.run(150);     // duty cycle 150, direction forward
    delay(1000);
    motor.run(50);      // duty cycle 50, direction forward
    delay(1000);
    motor.run(-100);    // duty cycle 100, direction backward
    delay(1000);
    motor.brake();      // motor blocking
    delay(1000);
    motor.run();        // duty cycle 100, direction backward
    delay(1000);
    motor.stop();       // smooth motor stop
    delay(3000);
}

```

## If you find bugs
When you find bugs, create an issue, or write to the mail info@kurskov.ru.  
The library is open for revision and your pull requests.

## License
Brushed motor by [Dmitrii Kurskov](https://kurskov.ru) is licensed under a MIT License.