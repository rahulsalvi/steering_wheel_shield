#ifndef STEERING_WHEEL_SHIELD_H
#define STEERING_WHEEL_SHIELD_H

#include "WProgram.h"
#include <stdint.h>

namespace steering_wheel_shield {

    void begin();
    void reset();
    void write_command(uint8_t* data, uint8_t n);
    void fill_screen();

} // namespace steering_wheel_shield

#endif // STEERING_WHEEL_SHIELD_H
