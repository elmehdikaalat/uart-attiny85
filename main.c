#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define TX PB4
#define BIT_US 3333

void send_c(char c)
{
    // start
    PORTB &= ~(1 << TX);
    _delay_us(BIT_US);

    for (int i = 0; i < 8; i++)
    {
        if (c & 1)
            PORTB |= (1 << TX);
        else
            PORTB &= ~(1 << TX);

        _delay_us(BIT_US);

        c = c >> 1;
    }

    // stop
    PORTB |= (1 << TX);
    _delay_us(BIT_US);
}

void send_str(char str[])
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        send_c(str[i]);
    }
}

int main(void)
{
    DDRB |= (1 << TX);
    PORTB |= (1 << TX);

    while (1)
    {
        send_str("coucou\r\n");
        _delay_ms(1000);
    }
}

