#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define DAC ((struct mcu_dac *)0x42004800)
#define DAC ((struct mcu_dac *)0x42004800)

struct mcu_dac {

	/* 0x00: Control A */
	uint8_t volatile CTRLA;
#define DAC_CTRLA_RUNSTDBY			(1u << 2)
#define DAC_CTRLA_ENABLE			(1u << 1)
#define DAC_CTRLA_SWRST				(1u << 0)

	/* 0x01: Control B */
	uint8_t volatile CTRLB;
#define DAC_CTRLB_REFSEL(x)			((x) << 6)
#define DAC_CTRLB_REFSEL_MASK			DAC_CTRLB_REFSEL(B00000011)
#define DAC_CTRLB_BDWP				(1u << 4)
#define DAC_CTRLB_VPD				(1u << 3)
#define DAC_CTRLB_LEFTADJ			(1u << 2)
#define DAC_CTRLB_IOEN				(1u << 1)
#define DAC_CTRLB_EOEN				(1u << 0)

	/* 0x02: Event Control */
	uint8_t volatile EVCTRL;
#define DAC_EVCTRL_EMPTYEO			(1u << 1)
#define DAC_EVCTRL_STARTEI			(1u << 0)

	/* 0x03 */
	uint8_t volatile RESERVED0[0x04-0x03];

	/* 0x04: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define DAC_INTENCLR_SYNCRDY			(1u << 2)
#define DAC_INTENCLR_EMPTY			(1u << 1)
#define DAC_INTENCLR_UNDERRUN			(1u << 0)

	/* 0x05: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define DAC_INTENSET_SYNCRDY			(1u << 2)
#define DAC_INTENSET_EMPTY			(1u << 1)
#define DAC_INTENSET_UNDERRUN			(1u << 0)

	/* 0x06: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define DAC_INTFLAG_SYNCRDY			(1u << 2)
#define DAC_INTFLAG_EMPTY			(1u << 1)
#define DAC_INTFLAG_UNDERRUN			(1u << 0)

	/* 0x07: Status */
	uint8_t volatile STATUS;
#define DAC_STATUS_SYNCBUSY			(1u << 7)

	/* 0x08: Data DAC */
	uint16_t volatile DATA;
#define DAC_DATA_DATA(x)			((x) << 0)

	/* 0x0A */
	uint8_t volatile RESERVED1[0x0C-0x0A];

	/* 0x0C: Data Buffer */
	uint16_t volatile DATABUF;
#define DAC_DATABUF_DATABUF(x)			((x) << 0)

};
