#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define PAC0 (((struct mcu_pac *)0x40000000)
#define PAC0 (((struct mcu_pac *)0x40000000)
#define PAC1 (((struct mcu_pac *)0x41000000)
#define PAC1 (((struct mcu_pac *)0x41000000)
#define PAC2 (((struct mcu_pac *)0x42000000)
#define PAC2 (((struct mcu_pac *)0x42000000)

struct mcu_pac {

	/* 0x00: Write Protect Clear */
	uint32_t volatile WPCLR;
#define PAC0_WPCLR_EIC				(1u << 6)
#define PAC0_WPCLR_RTC				(1u << 5)
#define PAC0_WPCLR_WDT				(1u << 4)
#define PAC0_WPCLR_GCLK				(1u << 3)
#define PAC0_WPCLR_SYSCTRL			(1u << 2)
#define PAC0_WPCLR_PM				(1u << 1)
#define PAC1_WPCLR_MTB				(1u << 6)
#define PAC1_WPCLR_USB				(1u << 5)
#define PAC1_WPCLR_DMAC				(1u << 4)
#define PAC1_WPCLR_PORT				(1u << 3)
#define PAC1_WPCLR_NVMCTRL			(1u << 2)
#define PAC1_WPCLR_DSU				(1u << 1)
#define PAC2_WPCLR_AC1				(1u << 21)
#define PAC2_WPCLR_I2S				(1u << 20)
#define PAC2_WPCLR_PTC				(1u << 19)
#define PAC2_WPCLR_DAC				(1u << 18)
#define PAC2_WPCLR_AC				(1u << 17)
#define PAC2_WPCLR_ADC				(1u << 16)
#define PAC2_WPCLR_SERCOM(x)			((x) << 2)
#define PAC2_WPCLR_EVSYS			(1u << 1)

	/* 0x04: Write Protect Set */
	uint32_t volatile WPSET;
#define PAC0_WPSET_EIC				(1u << 6)
#define PAC0_WPSET_RTC				(1u << 5)
#define PAC0_WPSET_WDT				(1u << 4)
#define PAC0_WPSET_GCLK				(1u << 3)
#define PAC0_WPSET_SYSCTRL			(1u << 2)
#define PAC0_WPSET_PM				(1u << 1)
#define PAC1_WPSET_MTB				(1u << 6)
#define PAC1_WPSET_USB				(1u << 5)
#define PAC1_WPSET_DMAC				(1u << 4)
#define PAC1_WPSET_PORT				(1u << 3)
#define PAC1_WPSET_NVMCTRL			(1u << 2)
#define PAC1_WPSET_DSU				(1u << 1)
#define PAC2_WPSET_AC1				(1u << 21)
#define PAC2_WPSET_I2S				(1u << 20)
#define PAC2_WPSET_PTC				(1u << 19)
#define PAC2_WPSET_DAC				(1u << 18)
#define PAC2_WPSET_AC				(1u << 17)
#define PAC2_WPSET_ADC				(1u << 16)
#define PAC2_WPSET_EVSYS			(1u << 1)

};
