#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define TC3 ((struct sdk_tc *)0x42002C00)
#define TC3 ((struct sdk_tc *)0x42002C00)
#define TC4 ((struct sdk_tc *)0x42003000)
#define TC4 ((struct sdk_tc *)0x42003000)
#define TC5 ((struct sdk_tc *)0x42003400)
#define TC5 ((struct sdk_tc *)0x42003400)
#define TC6 ((struct sdk_tc *)0x42003800)
#define TC6 ((struct sdk_tc *)0x42003800)
#define TC7 ((struct sdk_tc *)0x42003C00)
#define TC7 ((struct sdk_tc *)0x42003C00)

struct sdk_tc {

	/* 0x00: Control A */
	uint16_t volatile CTRLA;
#define TC_CTRLA_PRESCSYNC(x)			((x) << 12)
#define TC_CTRLA_PRESCSYNC_MASK			TC_CTRLA_PRESCSYNC(B00000011)
#define TC_CTRLA_RUNSTDBY			(1u << 11)
#define TC_CTRLA_PRESCALER(x)			((x) << 8)
#define TC_CTRLA_PRESCALER_MASK			TC_CTRLA_PRESCALER(B00000111)
#define TC_CTRLA_WAVEGEN(x)			((x) << 5)
#define TC_CTRLA_WAVEGEN_MASK			TC_CTRLA_WAVEGEN(B00000011)
#define TC_CTRLA_MODE(x)			((x) << 2)
#define TC_CTRLA_MODE_MASK			TC_CTRLA_MODE(B00000011)
#define TC_CTRLA_ENABLE				(1u << 1)
#define TC_CTRLA_SWRST				(1u << 0)

	/* 0x02: Read Request */
	uint16_t volatile READREQ;
#define TC_READREQ_RREQ				(1u << 15)
#define TC_READREQ_RCONT			(1u << 14)
#define TC_READREQ_ADDR(x)			((x) << 0)
#define TC_READREQ_ADDR_MASK			TC_READREQ_ADDR(B00011111)

	/* 0x04: Control B Clear */
	uint8_t volatile CTRLBCLR;
#define TC_CTRLBCLR_CMD(x)			((x) << 6)
#define TC_CTRLBCLR_CMD_MASK			TC_CTRLBCLR_CMD(B00000011)
#define TC_CTRLBCLR_ONESHOT			(1u << 2)
#define TC_CTRLBCLR_DIR				(1u << 0)

	/* 0x05: Control B Set */
	uint8_t volatile CTRLBSET;
#define TC_CTRLBSET_CMD(x)			((x) << 6)
#define TC_CTRLBSET_CMD_MASK			TC_CTRLBSET_CMD(B00000011)
#define TC_CTRLBSET_ONESHOT			(1u << 2)
#define TC_CTRLBSET_DIR				(1u << 0)

	/* 0x06: Control C */
	uint8_t volatile CTRLC;
#define TC_CTRLC_CPTENx				(1u << 5,4)
#define TC_CTRLC_INVENx				(1u << 1,0)

	/* 0x07 */
	uint8_t volatile RESERVED0[0x08-0x07];

	/* 0x08: Debug Control */
	uint8_t volatile DBGCTRL;
#define TC_DBGCTRL_DBGRUN			(1u << 0)

	/* 0x09 */
	uint8_t volatile RESERVED1[0x0A-0x09];

	/* 0x0A: Event Control */
	uint16_t volatile EVCTRL;
#define TC_EVCTRL_MCEOx				(1u << 13,12)
#define TC_EVCTRL_OVFEO				(1u << 8)
#define TC_EVCTRL_TCEI				(1u << 5)
#define TC_EVCTRL_TCINV				(1u << 4)
#define TC_EVCTRL_EVACT(x)			((x) << 0)
#define TC_EVCTRL_EVACT_MASK			TC_EVCTRL_EVACT(B00000111)

	/* 0x0C: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define TC_INTENCLR_MCx				(1u << 5,4)
#define TC_INTENCLR_SYNCRDY			(1u << 3)
#define TC_INTENCLR_ERR				(1u << 1)
#define TC_INTENCLR_OVF				(1u << 0)

	/* 0x0D: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define TC_INTENSET_MCx				(1u << 5,4)
#define TC_INTENSET_SYNCRDY			(1u << 3)
#define TC_INTENSET_ERR				(1u << 1)
#define TC_INTENSET_OVF				(1u << 0)

	/* 0x0E: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define TC_INTFLAG_MCx				(1u << 5,4)
#define TC_INTFLAG_SYNCRDY			(1u << 3)
#define TC_INTFLAG_ERR				(1u << 1)
#define TC_INTFLAG_OVF				(1u << 0)

	/* 0x0F: Status */
	uint8_t volatile STATUS;
#define TC_STATUS_SYNCBUSY			(1u << 7)
#define TC_STATUS_SLAVE				(1u << 4)
#define TC_STATUS_STOP				(1u << 3)

	/* 0x10: Counter Value, 8-bit Mode */
	uint8_t volatile COUNT;
#define TC_COUNT_COUNT(x)			((x) << 0)
#define TC_COUNT_COUNT_MASK			TC_COUNT_COUNT(B11111111)

	/* 0x10: Counter Value, 16-bit Mode */
	uint16_t volatile COUNT;
#define TC_COUNT_COUNT(x)			((x) << 0)

	/* 0x10: Counter Value, 32-bit Mode */
	uint32_t volatile COUNT;
#define TC_COUNT_COUNT(x)			((x) << 0)

	/* 0x14: Period Value, 8-bit Mode */
	uint8_t volatile PER;
#define TC_PER_PER(x)				((x) << 0)
#define TC_PER_PER_MASK				TC_PER_PER(B11111111)

	/* 0x15 */
	uint8_t volatile RESERVED2[0x18-0x15];

	/* 0x18: Channel x Compare/Capture Value, 8-bit Mode */
	uint8_t volatile CCx;
#define TC_CCx_CC(x)				((x) << 0)
#define TC_CCx_CC_MASK				TC_CCx_CC(B11111111)

	/* 0x18: Channel x Compare/Capture Value, 16-bit Mode */
	uint16_t volatile CCx;
#define TC_CCx_CC(x)				((x) << 0)

	/* 0x18: Channel x Compare/Capture Value, 32-bit Mode */
	uint32_t volatile CCx;
#define TC_CCx_CC(x)				((x) << 0)

};
