#define MCB1700

#include "mbed.h"
#include "rtos.h"
 
DigitalOut led1(LED1);
DigitalOut led2(LED2);

struct Leds {
    void led1_loop() {
        while (true) {
            led1 = !led1;
            Thread::wait(500);
        }
    }

    void led2_loop() {
        while (true) {
            led2 = !led2;
            Thread::wait(300);
        }
    }
};

typedef void (*voidfunc)();

int main() {
    Thread::wait(5000);

    Leds leds;

    Thread thread;
    thread.start(&leds, &Leds::led2_loop);

    leds.led1_loop();
}
