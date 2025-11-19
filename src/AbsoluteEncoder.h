#ifndef D7CA8930_2765_4C08_8437_B603C1A124A6
#define D7CA8930_2765_4C08_8437_B603C1A124A6
#include <Arduino.h>



class AbsoluteEncoder
{
private:
    int _pinClock;
    int _pinData;
    uint8_t _rotaryRes;
    uint8_t _stepRes;
    uint8_t _pinSet;
    uint8_t _errorRes = 3;

    uint16_t gray2bin(uint16_t);

public:

/** @brief read parameters from absolute encoder usin SSI
 *  @param pinClock
 *  @param pinData
 *  @param rotaryRes
 *  @param stepRes
 *  @param pinSet
 *  @return Void. 
*/
    AbsoluteEncoder(int pinClock, int pinData, uint8_t rotaryRes, uint8_t stepRes, int pinSet);
    ~AbsoluteEncoder();

/** @brief read parameters from absolute encoder usin SSI
 *  @param typeResult 0->gray code, 1->binary code
 *  @param[out] rotations
 *  @param[out] step
 *  @param[out] error
 *  @return Void. 
*/
    void read(uint16_t &rotations, uint16_t &step, uint8_t &error,  uint8_t typeResult);


/** @brief set IO ports as INPUT or OTPUT
 *  @return Void. 
*/
    void begin(void);
};


#endif /* D7CA8930_2765_4C08_8437_B603C1A124A6 */
