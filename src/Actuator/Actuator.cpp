/*This work is licensed under the Creative Commons
 *Attribution-NonCommercial-ShareAlike 4.0 International License.
 *To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/
 *or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
 */

#include <iostream>

#include "Actuator.h"
#include "PCA9685/PCA9685.h"

#define CHANNEL_SERVO_1 0
#define CHANNEL_SERVO_2 1
#define DEFAULT_ANGLE_SERVO_1 90
#define DEFAULT_ANGLE_SERVO_2 90

Actuator::Actuator(int cameraWidth, int cameraHeight)
{
    Actuator();
    setCameraParameters(cameraWidth, cameraHeight);
}

Actuator::Actuator()
{
    std::cout << "begin Actuator Creation" << std::endl;
    std::cout << "attach PCA9685 breakout board" << std::endl;
    _driver = ServoDriver();
    _driver.init();

    std::cout << "reset servos position" << std::endl;
    reset();
    std::cout << "end Actuator Creation" << std::endl;
}

Actuator::~Actuator()
{
    std::cout << "begin Actuator Destruction" << std::endl;
    std::cout << "end Actuator Destruction" << std::endl;
}

void Actuator::setCameraParameters(int cameraWidth, int cameraHeight)
{
    _cameraWidth = cameraWidth;
    _cameraHeight = cameraHeight;
}

void Actuator::goTo(int x, int y)
{
    // convert coordinates to angle
    int deltaX, deltaY;
    int newPositionX, newPositionY;
    _positionX = x;
    _positionY = y;
    deltaX = _positionX - _cameraWidth/2;
    deltaY = _positionY - _cameraHeight/2;
    newPositionX = _positionX + deltaX;
    newPositionY = _positionY + deltaY;
    _angleServo1 = _convertToAngle(newPositionX);
    _angleServo2 = _convertToAngle(newPositionY);
    _driver.setAngle(CHANNEL_SERVO_1, _angleServo1);
    _driver.setAngle(CHANNEL_SERVO_2, _angleServo2);
}

void Actuator::reset()
{
    _positionX = _convertToPosition(DEFAULT_ANGLE_SERVO_1);
    _positionY = _convertToPosition(DEFAULT_ANGLE_SERVO_2);
    goTo(_positionX, _positionY);
}

std::pair<int, int> Actuator::getCurrentPosition()
{
    return std::make_pair(_positionX, _positionY);
}

std::pair<int, int> Actuator::getCurrentAngle()
{
    return std::make_pair(_angleServo1, _angleServo2);
}

int Actuator::_convertToAngle(int position)
{
    return position/180;
}

int Actuator::_convertToPosition(int angle)
{
    return angle*180;
}