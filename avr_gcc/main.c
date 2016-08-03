#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>

#include "hardware.h"
#include "bit_operations.h"

static inline void init() {
    DDRB = DDRB_STATE;
    DDRD = DDRD_STATE;

    PORTB = PORTB_STATE;
    PORTD = PORTD_STATE;

    _delay_ms(500);
}

static inline void soft_reset()
{
    wdt_enable(WDTO_30MS);
    for(;;);
}


int main()
{
    init();

    for (;;) {
        clearbit(LED_PORT, LED_BIT);
        _delay_ms(500);
        clearbit(LED_PORT, LED_BIT);
        _delay_ms(500);
    }
    return 0;
}
