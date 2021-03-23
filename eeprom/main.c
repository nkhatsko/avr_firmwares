#define F_CPU  800000UL

#include <stdint.h>

#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/sfr_defs.h>

#include <util/delay.h>

#define LED1   PC0
#define LED2   PC1
#define BUTTON PD0


void init(void) {

	DDRD |= (1 << BUTTON);
	DDRC |= (1 << LED1) | (1 << LED2);

	PORTD |= (1 << BUTTON);

};


uint8_t switch_led(uint8_t i) {

	return ((i == 1) ? 2 : 1);

};


int32_t main(void) {

	init();

	uint8_t i;
	i = eeprom_read_byte(0x00);
	PORTC = i;;

	while (1) {
		if (bit_is_clear(PIND, BUTTON)) {
			while (bit_is_clear(PIND, BUTTON));
			i = switch_led(i);
			eeprom_write_byte(0x00, i);
		} else {
			while (bit_is_set(PIND, BUTTON));
			i = switch_led(i);
			eeprom_write_byte(0x00, i);
		};

		PORTC = i;
	};

	return (0);

};
