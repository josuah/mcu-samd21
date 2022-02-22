#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define PORT ((struct zmcu_port *)0x41004400)

struct zmcu_port {

	/* 0x00: Data Direction */
	uint32_t volatile DIR;
#define PORT_DIR_DIR(x)				((x) << 0)

	/* 0x04: Data Direction Clear */
	uint32_t volatile DIRCLR;
#define PORT_DIRCLR_DIRCLR(x)			((x) << 0)

	/* 0x08: Data Direction Set */
	uint32_t volatile DIRSET;
#define PORT_DIRSET_DIRSET(x)			((x) << 0)

	/* 0x0C: Data Direction Toggle */
	uint32_t volatile DIRTGL;
#define PORT_DIRTGL_DIRTGL(x)			((x) << 0)

	/* 0x10: Data Output Value */
	uint32_t volatile OUT;
#define PORT_OUT_OUT(x)				((x) << 0)

	/* 0x14: Data Output Value Clear */
	uint32_t volatile OUTCLR;
#define PORT_OUTCLR_OUTCLR(x)			((x) << 0)

	/* 0x18: Data Output Value Set */
	uint32_t volatile OUTSET;
#define PORT_OUTSET_OUTSET(x)			((x) << 0)

	/* 0x1C: Data Output Value Toggle */
	uint32_t volatile OUTTGL;
#define PORT_OUTTGL_OUTTGL(x)			((x) << 0)

	/* 0x20: Data Input Value */
	uint32_t volatile IN;
#define PORT_IN_IN(x)				((x) << 0)

	/* 0x24: Control */
	uint32_t volatile CTRL;
#define PORT_CTRL_SAMPLING(x)			((x) << 0)

	/* 0x28: Write Configuration */
	uint32_t volatile WRCONFIG;
#define PORT_WRCONFIG_HWSEL			(1u << 31)
#define PORT_WRCONFIG_WRPINCFG			(1u << 30)
#define PORT_WRCONFIG_WRPMUX			(1u << 28)
#define PORT_WRCONFIG_PMUX(x)			((x) << 24)
#define PORT_WRCONFIG_PMUX_MASK			PORT_WRCONFIG_PMUX(B00001111)
#define PORT_WRCONFIG_PULLEN			(1u << 18)
#define PORT_WRCONFIG_INEN			(1u << 17)
#define PORT_WRCONFIG_PMUXEN			(1u << 16)
#define PORT_WRCONFIG_PINMASK(x)		((x) << 0)

	/* 0x2C */
	uint8_t volatile RESERVED0[0x30-0x2C];

	/* 0x30: Peripheral Multiplexing n */
	uint8_t volatile PMUX[16];
#define PORT_PMUX(pin, x)                       ((x) << ((pin) & 1) * 4)
#define PORT_PMUX_MASK(pin)			PORT_PMUX((pin), B00001111)
#define PORT_PMUX_FN_A				0
#define PORT_PMUX_FN_B				1
#define PORT_PMUX_FN_C				2
#define PORT_PMUX_FN_D				3
#define PORT_PMUX_FN_E				4
#define PORT_PMUX_FN_F				5
#define PORT_PMUX_FN_G				6
#define PORT_PMUX_FN_H				7

	/* 0x40: Pin Configuration */
	uint8_t volatile PINCFG[32];
#define PORT_PINCFG_PULLEN			(1u << 2)
#define PORT_PINCFG_INEN			(1u << 1)
#define PORT_PINCFG_PMUXEN			(1u << 0)

};
