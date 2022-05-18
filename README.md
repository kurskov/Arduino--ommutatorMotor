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

## Compatibility

Compatible with all Arduino platforms (using Arduino functions).

Supported drivers: L298N, L9110S, MX1508, TA6586, TB6612.

## How to use

### Include library

```c
#include <BrushedMotor.h>
```

### Initialization

#### For 2-wire connection:

```c
BrushedMotor motor(IN1, IN2);
```

IN1 - PWM pin  
IN2 - digital or PWM pin


#### For 3-wire connection:

```c
BrushedMotor motor(IN1, IN2, EN);
```

IN1, IN2 - digital or PWM pins  
EN - PWM pin


### Basic functions

#### Run

#### Stop

#### Brake

#### Set motor speed

### Get state of motor

#### Get direction of rotation

## Example

```c
#include <BrushedMotor.h>

BrushedMotor motor(5, 6);
// or motor(5, 6, 11) for 3-wire connection

void setup() {
}

void loop() {
    motor.setSpeed(150);
    motor.run();
    delay(1000);
    motor.setSpeed(50);
    motor.run();
    delay(1000);
    motor.setSpeed(-100);
    motor.run();
    delay(1000);
    motor.brake();
    delay.(1000);
    motor.run();
    delay(1000);
    motor.stop();
    delay(3000);
}

```

## If you find bugs
When you find bugs, create an issue, or write to the mail info@kurskov.ru.  
The library is open for revision and your Pull Requests.

## License
Brushed motor by [Dmitrii Kurskov](https://kurskov.ru) is licensed under a MIT License.