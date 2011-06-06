/*
  pins_arduino.c - pin definitions for the Arduino board
  Part of Arduino / Wiring Lite

  Copyright (c) 2005 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id$
*/

#include <avr/io.h>
#include "wiring_private.h"
#include "pins_arduino.h"

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7


const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	&DDRA,
	&DDRB,
	&DDRC,
	&DDRD,
	&DDRE,
	&DDRF,
	&DDRG,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	&PORTA,
	&PORTB,
	&PORTC,
	&PORTD,
	&PORTE,
	&PORTF,
	&PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	&PINA,
	&PINB,
	&PINC,
	&PIND,
	&PINE,
	&PINF,
	&PING,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST		
	// -------------------------------------------		
	PE	, // PE 0 ** 0 ** USART0_RX	
	PE	, // PE 1 ** 1 ** USART0_TX	
	PE	, // PE 3 ** 2 ** PWM2	
	PE	, // PE 4 ** 3 ** PWM3	
	PE	, // PE 5 ** 4 ** PWM4	
	PB	, // PB 4 ** 5 ** PWM5	
	PB	, // PB 5 ** 6 ** PWM6	
	PB	, // PB 6 ** 7 ** PWM7	

	PE	, // PE 2 ** 8 ** D8	
	PE	, // PE 6 ** 9 ** D9	
	PE	, // PE 7 ** 10 ** D10	
	PD	, // PD 4 ** 11 ** D11	
	PD	, // PD 7 ** 12 ** D12	
	PB	, // PB 0 ** 13 ** BLUE	
	PB	, // PB 7 ** 14 ** GOLD

	PD	, // PD 6 ** 15 ** RXCAN	
	PD	, // PD 5 ** 16 ** TXCAN	

	PB	, // PB 0 ** 17 ** NONE!	

	PD	, // PD 3 ** 18 ** USART1_RX	
	PD	, // PD 2 ** 19 ** USART1_TX	
	PD	, // PD 1 ** 20 ** SDA	
	PD	, // PD 0 ** 21 ** SCL	

	PB	, // PB 0 ** 22 ** NONE!	
	PB	, // PB 0 ** 23 ** NONE!	
	PB	, // PB 0 ** 24 ** NONE!	
	PB	, // PB 0 ** 25 ** NONE!	
	PB	, // PB 0 ** 26 ** NONE!	
	PB	, // PB 0 ** 27 ** NONE!	
	PB	, // PB 0 ** 28 ** NONE!	
	PB	, // PB 0 ** 29 ** NONE!	
	PB	, // PB 0 ** 30 ** NONE!	
	PB	, // PB 0 ** 31 ** NONE!	
	PB	, // PB 0 ** 32 ** NONE!	
	PB	, // PB 0 ** 33 ** NONE!	
	PB	, // PB 0 ** 34 ** NONE!	
	PB	, // PB 0 ** 35 ** NONE!	
	PB	, // PB 0 ** 36 ** NONE!	
	PB	, // PB 0 ** 37 ** NONE!	
	PB	, // PB 0 ** 38 ** NONE!	
	PB	, // PB 0 ** 39 ** NONE!	
	PB	, // PB 0 ** 40 ** NONE!	
	PB	, // PB 0 ** 41 ** NONE!	
	PB	, // PB 0 ** 42 ** NONE!	
	PB	, // PB 0 ** 43 ** NONE!	
	PB	, // PB 0 ** 44 ** NONE!	
	PB	, // PB 0 ** 45 ** NONE!	
	PB	, // PB 0 ** 46 ** NONE!	
	PB	, // PB 0 ** 47 ** NONE!	
	PB	, // PB 0 ** 48 ** NONE!	
	PB	, // PB 0 ** 49 ** NONE!	

	PB	, // PB 3 ** 50 ** SPI_MISO	
	PB	, // PB 2 ** 51 ** SPI_MOSI	
	PB	, // PB 1 ** 52 ** SPI_SCK	
	PB	, // PB 0 ** 53 ** SPI_SS (also BLUE)

	PF	, // PF 0 ** 54 ** A0	
	PF	, // PF 1 ** 55 ** A1	
	PF	, // PF 2 ** 56 ** A2	
	PF	, // PF 3 ** 57 ** A3	
	PF	, // PF 4 ** 58 ** A4	
	PF	, // PF 5 ** 59 ** A5	
	PF	, // PF 6 ** 60 ** A6	
	PF	, // PF 7 ** 61 ** A7	
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------		
	_BV( 0 )	, // PE 0 ** 0 ** USART0_RX	
	_BV( 1 )	, // PE 1 ** 1 ** USART0_TX	
	_BV( 3 )	, // PE 3 ** 2 ** PWM2	
	_BV( 4 )	, // PE 4 ** 3 ** PWM3	
	_BV( 5 )	, // PE 5 ** 4 ** PWM4	
	_BV( 4 )	, // PB 4 ** 5 ** PWM5	
	_BV( 5 )	, // PB 5 ** 6 ** PWM6	
	_BV( 6 )	, // PB 6 ** 7 ** PWM7	

	_BV( 2 )	, // PE 2 ** 8 ** D8	
	_BV( 6 )	, // PE 6 ** 9 ** D9	
	_BV( 7 )	, // PE 7 ** 10 ** D10	
	_BV( 4 )	, // PD 4 ** 11 ** D11	
	_BV( 7 )	, // PD 7 ** 12 ** D12	
	_BV( 0 )	, // PB 0 ** 13 ** BLUE	
	_BV( 7 )	, // PB 7 ** 14 ** GOLD

	_BV( 6 )	, // PD 6 ** 15 ** RXCAN	
	_BV( 5 )	, // PD 5 ** 16 ** TXCAN	

	_BV( 0 )	, // PB 0 ** 17 ** NONE!	

	_BV( 3 )	, // PD 3 ** 18 ** USART1_RX	
	_BV( 2 )	, // PD 2 ** 19 ** USART1_TX	
	_BV( 1 )	, // PD 1 ** 20 ** SDA	
	_BV( 0 )	, // PD 0 ** 21 ** SCL	

	_BV( 0 )	, // PB 0 ** 22 ** NONE!	
	_BV( 0 )	, // PB 0 ** 23 ** NONE!	
	_BV( 0 )	, // PB 0 ** 24 ** NONE!	
	_BV( 0 )	, // PB 0 ** 25 ** NONE!	
	_BV( 0 )	, // PB 0 ** 26 ** NONE!	
	_BV( 0 )	, // PB 0 ** 27 ** NONE!	
	_BV( 0 )	, // PB 0 ** 28 ** NONE!	
	_BV( 0 )	, // PB 0 ** 29 ** NONE!	
	_BV( 0 )	, // PB 0 ** 30 ** NONE!	
	_BV( 0 )	, // PB 0 ** 31 ** NONE!	
	_BV( 0 )	, // PB 0 ** 32 ** NONE!	
	_BV( 0 )	, // PB 0 ** 33 ** NONE!	
	_BV( 0 )	, // PB 0 ** 34 ** NONE!	
	_BV( 0 )	, // PB 0 ** 35 ** NONE!	
	_BV( 0 )	, // PB 0 ** 36 ** NONE!	
	_BV( 0 )	, // PB 0 ** 37 ** NONE!	
	_BV( 0 )	, // PB 0 ** 38 ** NONE!	
	_BV( 0 )	, // PB 0 ** 39 ** NONE!	
	_BV( 0 )	, // PB 0 ** 40 ** NONE!	
	_BV( 0 )	, // PB 0 ** 41 ** NONE!	
	_BV( 0 )	, // PB 0 ** 42 ** NONE!	
	_BV( 0 )	, // PB 0 ** 43 ** NONE!	
	_BV( 0 )	, // PB 0 ** 44 ** NONE!	
	_BV( 0 )	, // PB 0 ** 45 ** NONE!	
	_BV( 0 )	, // PB 0 ** 46 ** NONE!	
	_BV( 0 )	, // PB 0 ** 47 ** NONE!	
	_BV( 0 )	, // PB 0 ** 48 ** NONE!	
	_BV( 0 )	, // PB 0 ** 49 ** NONE!	

	_BV( 3 )	, // PB 3 ** 50 ** SPI_MISO	
	_BV( 2 )	, // PB 2 ** 51 ** SPI_MOSI	
	_BV( 1 )	, // PB 1 ** 52 ** SPI_SCK	
	_BV( 0 )	, // PB 0 ** 53 ** SPI_SS (also BLUE)

	_BV( 0 )	, // PF 0 ** 54 ** A0	
	_BV( 1 )	, // PF 1 ** 55 ** A1	
	_BV( 2 )	, // PF 2 ** 56 ** A2	
	_BV( 3 )	, // PF 3 ** 57 ** A3	
	_BV( 4 )	, // PF 4 ** 58 ** A4	
	_BV( 5 )	, // PF 5 ** 59 ** A5	
	_BV( 6 )	, // PF 6 ** 60 ** A6	
	_BV( 7 )	, // PF 7 ** 61 ** A7	
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		
	// -------------------------------------------		
	NOT_ON_TIMER	, // PE 0 ** 0 ** USART0_RX	
	NOT_ON_TIMER	, // PE 1 ** 1 ** USART0_TX	
	TIMER3A	      , // PE 3 ** 2 ** PWM2	
	TIMER3B     	, // PE 4 ** 3 ** PWM3	
	TIMER3C     	, // PE 5 ** 4 ** PWM4	
	TIMER2A     	, // PB 4 ** 5 ** PWM5	
	TIMER1A     	, // PB 5 ** 6 ** PWM6	
	TIMER1B     	, // PB 6 ** 7 ** PWM7	

	NOT_ON_TIMER	, // PE 2 ** 8 ** D8	
	NOT_ON_TIMER	, // PE 6 ** 9 ** D9	
	NOT_ON_TIMER	, // PE 7 ** 10 ** D10	
	NOT_ON_TIMER	, // PD 4 ** 11 ** D11	
	NOT_ON_TIMER	, // PD 7 ** 12 ** D12	
	NOT_ON_TIMER	, // PB 0 ** 13 ** BLUE	
	TIMER0A     	, // PB 7 ** 14 ** GOLD

	NOT_ON_TIMER	, // PD 6 ** 15 ** RXCAN	
	NOT_ON_TIMER	, // PD 5 ** 16 ** TXCAN	

	NOT_ON_TIMER	, // PB 0 ** 17 ** NONE!	

	NOT_ON_TIMER	, // PD 3 ** 18 ** USART1_RX	
	NOT_ON_TIMER	, // PD 2 ** 19 ** USART1_TX	
	NOT_ON_TIMER	, // PD 1 ** 20 ** SDA	
	NOT_ON_TIMER	, // PD 0 ** 21 ** SCL	

	NOT_ON_TIMER	, // PB 0 ** 22 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 23 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 24 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 25 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 26 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 27 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 28 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 29 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 30 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 31 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 32 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 33 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 34 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 35 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 36 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 37 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 38 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 39 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 40 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 41 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 42 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 43 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 44 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 45 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 46 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 47 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 48 ** NONE!	
	NOT_ON_TIMER	, // PB 0 ** 49 ** NONE!	

	NOT_ON_TIMER	, // PB 3 ** 50 ** SPI_MISO	
	NOT_ON_TIMER	, // PB 2 ** 51 ** SPI_MOSI	
	NOT_ON_TIMER	, // PB 1 ** 52 ** SPI_SCK	
	NOT_ON_TIMER	, // PB 0 ** 53 ** SPI_SS (also BLUE)

	NOT_ON_TIMER	, // PF 0 ** 54 ** A0	
	NOT_ON_TIMER	, // PF 1 ** 55 ** A1	
	NOT_ON_TIMER	, // PF 2 ** 56 ** A2	
	NOT_ON_TIMER	, // PF 3 ** 57 ** A3	
	NOT_ON_TIMER	, // PF 4 ** 58 ** A4	
	NOT_ON_TIMER	, // PF 5 ** 59 ** A5	
	NOT_ON_TIMER	, // PF 6 ** 60 ** A6	
	NOT_ON_TIMER	, // PF 7 ** 61 ** A7	
};
