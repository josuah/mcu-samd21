#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define AC ((struct zmcu_ac *)0x42004400)
#define AC ((struct zmcu_ac *)0x42004400)
#define AC1 ((struct zmcu_ac *)0x42005400)
#define AC1 ((struct zmcu_ac *)0x42005400)

struct zmcu_ac {

	/* 0x00: Control A */
	uint8_t volatile CTRLA;
#define AC_CTRLA_LPMUX				(1u << 7)
#define AC_CTRLA_RUNSTDBY			(1u << 2)
#define AC_CTRLA_ENABLE				(1u << 1)
#define AC_CTRLA_SWRST				(1u << 0)

	/* 0x01: Control B */
	uint8_t volatile CTRLB;
#define AC_CTRLB_STARTx				(1u << 3,2,1,0)

	/* 0x02: Event Control */
	uint16_t volatile EVCTRL;
#define AC_EVCTRL_COMPEIx			(1u << 11,10,9,8)
#define AC_EVCTRL_WINEOx			(1u << 5,4)
#define AC_EVCTRL_COMPEOx			(1u << 3,2,1,0)

	/* 0x04: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define AC_INTENCLR_WINx			(1u << 5,4)
#define AC_INTENCLR_COMPx			(1u << 3,2,1,0)

	/* 0x05: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define AC_INTENSET_WINx			(1u << 5,4)
#define AC_INTENSET_COMPx			(1u << 3,2,1,0)

	/* 0x06: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define AC_INTFLAG_WINx				(1u << 5,4)
#define AC_INTFLAG_COMPx			(1u << 3,2,1,0)

	/* 0x07 */
	uint8_t volatile RESERVED0[0x08-0x07];

	/* 0x08: Status A */
	uint8_t volatile STATUSA;
#define AC_STATUSA_WSTATE1(x)			((x) << 6)
#define AC_STATUSA_WSTATE1_MASK			AC_STATUSA_WSTATE1(B00000011)
#define AC_STATUSA_WSTATE0(x)			((x) << 4)
#define AC_STATUSA_WSTATE0_MASK			AC_STATUSA_WSTATE0(B00000011)
#define AC_STATUSA_STATEx			(1u << 3,2,1,0)

	/* 0x09: Status B */
	uint8_t volatile STATUSB;
#define AC_STATUSB_SYNCBUSY			(1u << 7)
#define AC_STATUSB_READYx			(1u << 3,2,1,0)

	/* 0x0A: Status C */
	uint8_t volatile STATUSC;
#define AC_STATUSC_WSTATE1(x)			((x) << 6)
#define AC_STATUSC_WSTATE1_MASK			AC_STATUSC_WSTATE1(B00000011)
#define AC_STATUSC_WSTATE0(x)			((x) << 4)
#define AC_STATUSC_WSTATE0_MASK			AC_STATUSC_WSTATE0(B00000011)
#define AC_STATUSC_STATEx			(1u << 3,2,1,0)

	/* 0x0B */
	uint8_t volatile RESERVED1[0x0C-0x0B];

	/* 0x0C: Window Control */
	uint8_t volatile WINCTRL;
#define AC_WINCTRL_WINTSEL1(x)			((x) << 5)
#define AC_WINCTRL_WINTSEL1_MASK		AC_WINCTRL_WINTSEL1(B00000011)
#define AC_WINCTRL_WEN1				(1u << 4)
#define AC_WINCTRL_WINTSEL0(x)			((x) << 1)
#define AC_WINCTRL_WINTSEL0_MASK		AC_WINCTRL_WINTSEL0(B00000011)
#define AC_WINCTRL_WEN0				(1u << 0)

	/* 0x0D */
	uint8_t volatile RESERVED2[0x10-0x0D];

	/* 0x10: Comparator Control n */
	uint32_t volatile COMPCTRL;
#define AC_COMPCTRL_FLEN(x)			((x) << 24)
#define AC_COMPCTRL_FLEN_MASK			AC_COMPCTRL_FLEN(B00000111)
#define AC_COMPCTRL_HYST			(1u << 19)
#define AC_COMPCTRL_OUT(x)			((x) << 16)
#define AC_COMPCTRL_OUT_MASK			AC_COMPCTRL_OUT(B00000011)
#define AC_COMPCTRL_SWAP			(1u << 15)
#define AC_COMPCTRL_MUXPOS(x)			((x) << 12)
#define AC_COMPCTRL_MUXPOS_MASK			AC_COMPCTRL_MUXPOS(B00000011)
#define AC_COMPCTRL_MUXNEG(x)			((x) << 8)
#define AC_COMPCTRL_MUXNEG_MASK			AC_COMPCTRL_MUXNEG(B00000111)
#define AC_COMPCTRL_INTSEL(x)			((x) << 5)
#define AC_COMPCTRL_INTSEL_MASK			AC_COMPCTRL_INTSEL(B00000011)
#define AC_COMPCTRL_SPEED(x)			((x) << 2)
#define AC_COMPCTRL_SPEED_MASK			AC_COMPCTRL_SPEED(B00000011)
#define AC_COMPCTRL_SINGLE			(1u << 1)
#define AC_COMPCTRL_ENABLE			(1u << 0)

	/* 0x14 */
	uint8_t volatile RESERVED3[0x20-0x14];

	/* 0x20: Scaler n */
	uint8_t volatile SCALER;
#define AC_SCALER_VALUE(x)			((x) << 0)
#define AC_SCALER_VALUE_MASK			AC_SCALER_VALUE(B00111111)

};
