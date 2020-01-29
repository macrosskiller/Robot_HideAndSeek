/*This work is licensed under the Creative Commons
 *Attribution-NonCommercial-ShareAlike 4.0 International License.
 *To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/
 *or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
 */

#ifndef INTERFACEDETECTOR_H
#define INTERFACEDETECTOR_H

class InterfaceDetector
{
public:
    virtual std::tuple<pair<int, int>, pair<int, int>, int> getDetectedObjects() override;
}

#endif // INTERFACEDETECTOR_H