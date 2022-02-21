#include <port.h>

#define LED	13

int
main(void)
{
	/* turn led on */
	PORT->DIRSET = 1 << LED;
	PORT->OUTSET = 1 << LED;

	return 0;
}
