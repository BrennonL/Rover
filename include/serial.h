#pragma once
#include <stdio.h> // FDEV_SETUP_STREAM, FILE

static void uart_init(void);

static void uart_putc(char c);

static int uart_putchar(char c, FILE *stream);

void printfSetup();