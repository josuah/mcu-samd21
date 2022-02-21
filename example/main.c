#include <port.h>

#define LED	17

int
main(void)
{
	/* turn led on */
	PORT->DIRSET = 1 << LED;
	PORT->OUTCLR = 1 << LED;

	return 0;
}
