/*This work is licensed under the Creative Commons
 *Attribution-NonCommercial-ShareAlike 4.0 International License.
 *To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/
 *or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
 */

#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "PCA9685/PCA9685.h"

class Actuator {
public:
    Actuator(int cameraWidth, int cameraHeight);
    Actuator();
    ~Actuator();
    void setCameraParameters(int cameraWidth, int cameraHeight);
    void goTo(int x, int y);
    void reset();
    std::pair<int, int> getCurrentPosition();
    std::pair<int, int> getCurrentAngle();

private:
    int _convertToPosition(int angle);
    int _convertToAngle(int angle);

    uint16_t _angleServo1;
    uint16_t _angleServo2;
    uint8_t _channelServo1;
    uint8_t _channelServo2;
    int _cameraWidth;
    int _cameraHeight;
    int _positionX;
    int _positionY;
    ServoDriver _driver;
};

#endif // ACTUATOR_H