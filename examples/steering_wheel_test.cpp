#include "steering_wheel_shield.h"

void setup() {
    steering_wheel_shield::begin();
    steering_wheel_shield::fill_screen();
}

void loop() {
    delay(1000);
}

int main() {
    setup();
    while (1) { loop(); }
}
