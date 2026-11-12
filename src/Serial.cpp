/**
 * Source: https://projectslearner.com/avr-microcontroller/usart-serial-communication
 */

#define F_CPU 16000000UL
#define BAUD 9600UL

#include <Serial.h>

#include <stdint.h> // unit16_t, utin8_t, unit32_t
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// Solution to FDEV_SETUP_STREAM not working on C++
// url: https://github.com/avrdudes/avr-libc/issues/898
#undef FDEV_SETUP_STREAM
#define FDEV_SETUP_STREAM(PU, GE, FL) \
    {                                 \
        0  /* buf */,                 \
        0  /* unget */,               \
        FL /* flags */,               \
        0  /* size */,                \
        0  /* len */,                 \
        PU /* put */,                 \
        GE /* get */,                 \
        0  /* udata */                \
    }

#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)
#define RX_SIZE 32

static volatile uint8_t rx_buf[RX_SIZE];
static volatile uint8_t rx_head = 0, rx_tail = 0;


static void uart_init(void)
{
    UBRR0  = UBRR_VALUE;                       /* 103 for 9600 baud */
    UCSR0A = 0;                                /* normal speed */
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);    /* 8N1 */
}

static void uart_putc(char c)
{
    while (!(UCSR0A & (1 << UDRE0)))           /* wait for empty buffer */
        ;
    UDR0 = c;
}

/* Called for every character printf produces */
static int uart_putchar(char c, FILE *stream)
{
    if (c == '\n')
        uart_putc('\r');                       /* terminals expect CR LF */
    uart_putc(c);
    return 0;
}

static FILE uart_out = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

/* RX complete interrupt: store byte in ring buffer */
ISR(USART_RX_vect)
{
    uint8_t c = UDR0;                          /* reading clears RXC0 */
    uint8_t next = (rx_head + 1) & (RX_SIZE - 1);
    if (next != rx_tail) {                     /* drop byte if full */
        rx_buf[rx_head] = c;
        rx_head = next;
    }
}

/* Returns -1 if no data, otherwise the next byte */
static int uart_getc(void)
{
    if (rx_head == rx_tail)
        return -1;
    uint8_t c = rx_buf[rx_tail];
    rx_tail = (rx_tail + 1) & (RX_SIZE - 1);
    return c;
}