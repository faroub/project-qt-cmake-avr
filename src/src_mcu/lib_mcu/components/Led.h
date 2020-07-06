/**
 * @file Led.h
 * @brief Header file of the Led class
 *
 * class to control a Led
 * @author Farid Oubbati (https://github.com/faroub)
 * @date March 2020
*/
#ifndef LED_H
#define LED_H
#include "Pin.h"


namespace component
{
class Led
{

public:
    /** Constructor. Initalizes the led object
         *
         *  @param ar_pin constant reference to pin object
         */
    Led(const io::Pin &ar_pin);
    /** Destructor.
        */
    ~Led();
    /** Turn led On.
         */
    void on();
    /** Turn led Off.
         */
    void off();
    /** Toggle led state.
         */
    void toggle();
    /** Is led On.
         */
    uint8_t isOn();
    /** Is led Off.
         */
    uint8_t isOff();

protected:

private:

    io::Pin mr_pin; /**< pin object */



};

}


#endif
