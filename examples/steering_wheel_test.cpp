#include "steering_wheel_shield.h"

void setup() {
    steering_wheel_shield::begin();
}

void loop() {}

int main() {
    setup();
    while (1) { loop(); }
}
