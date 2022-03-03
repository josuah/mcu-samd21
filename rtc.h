#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define RTC ((struct sdk_rtc *)0x40001400)
#define RTC ((struct sdk_rtc *)0x40001400)

struct sdk_rtc {

	/* 0x00: Control - MODE0 */
	uint16_t volatile CTRL;
#define RTC_CTRL_PRESCALER(x)			((x) << 8)
#define RTC_CTRL_PRESCALER_MASK			RTC_CTRL_PRESCALER(B00001111)
#define RTC_CTRL_MATCHCLR			(1u << 7)
#define RTC_CTRL_MODE(x)			((x) << 2)
#define RTC_CTRL_MODE_MASK			RTC_CTRL_MODE(B00000011)
#define RTC_CTRL_ENABLE				(1u << 1)
#define RTC_CTRL_SWRST				(1u << 0)

};

struct sdk_rtc {

	/* 0x00: Control - MODE1 */
	uint16_t volatile CTRL;
#define RTC_CTRL_PRESCALER(x)			((x) << 8)
#define RTC_CTRL_PRESCALER_MASK			RTC_CTRL_PRESCALER(B00001111)
#define RTC_CTRL_MODE(x)			((x) << 2)
#define RTC_CTRL_MODE_MASK			RTC_CTRL_MODE(B00000011)
#define RTC_CTRL_ENABLE				(1u << 1)
#define RTC_CTRL_SWRST				(1u << 0)

};

struct sdk_rtc {

	/* 0x00: Control - MODE2 */
	uint16_t volatile CTRL;
#define RTC_CTRL_PRESCALER(x)			((x) << 8)
#define RTC_CTRL_PRESCALER_MASK			RTC_CTRL_PRESCALER(B00001111)
#define RTC_CTRL_MATCHCLR			(1u << 7)
#define RTC_CTRL_CLKREP				(1u << 6)
#define RTC_CTRL_MODE(x)			((x) << 2)
#define RTC_CTRL_MODE_MASK			RTC_CTRL_MODE(B00000011)
#define RTC_CTRL_ENABLE				(1u << 1)
#define RTC_CTRL_SWRST				(1u << 0)

	/* 0x02: Read Request */
	uint16_t volatile READREQ;
#define RTC_READREQ_RREQ			(1u << 15)
#define RTC_READREQ_RCONT			(1u << 14)
#define RTC_READREQ_ADDR(x)			((x) << 0)
#define RTC_READREQ_ADDR_MASK			RTC_READREQ_ADDR(B00111111)

	/* 0x04: Event Control - MODE0 */
	uint16_t volatile EVCTRL;
#define RTC_EVCTRL_OVFEO			(1u << 15)
#define RTC_EVCTRL_CMPEO0			(1u << 8)
#define RTC_EVCTRL_PEREOx			(1u << 7,6,5,4,3,2,1,0)

	/* 0x04: Event Control - MODE1 */
	uint16_t volatile EVCTRL;
#define RTC_EVCTRL_OVFEO			(1u << 15)
#define RTC_EVCTRL_CMPEOx			(1u << 9,8)
#define RTC_EVCTRL_PEREOx			(1u << 7,6,5,4,3,2,1,0)

	/* 0x04: Event Control - MODE2 */
	uint16_t volatile EVCTRL;
#define RTC_EVCTRL_OVFEO			(1u << 15)
#define RTC_EVCTRL_ALARMEO0			(1u << 8)
#define RTC_EVCTRL_PEREOx			(1u << 7,6,5,4,3,2,1,0)

	/* 0x06: Interrupt Enable Clear - MODE0 */
	uint8_t volatile INTENCLR;
#define RTC_INTENCLR_OVF			(1u << 7)
#define RTC_INTENCLR_SYNCRDY			(1u << 6)
#define RTC_INTENCLR_CMP0			(1u << 0)

	/* 0x06: Interrupt Enable Clear - MODE1 */
	uint8_t volatile INTENCLR;
#define RTC_INTENCLR_OVF			(1u << 7)
#define RTC_INTENCLR_SYNCRDY			(1u << 6)
#define RTC_INTENCLR_CMPx			(1u << 1,0)

	/* 0x06: Interrupt Enable Clear - MODE2 */
	uint8_t volatile INTENCLR;
#define RTC_INTENCLR_OVF			(1u << 7)
#define RTC_INTENCLR_SYNCRDY			(1u << 6)
#define RTC_INTENCLR_ALARM0			(1u << 0)

	/* 0x07: Interrupt Enable Set - MODE0 */
	uint8_t volatile INTENSET;
#define RTC_INTENSET_OVF			(1u << 7)
#define RTC_INTENSET_SYNCRDY			(1u << 6)
#define RTC_INTENSET_CMP0			(1u << 0)

	/* 0x07: Interrupt Enable Set - MODE1 */
	uint8_t volatile INTENSET;
#define RTC_INTENSET_OVF			(1u << 7)
#define RTC_INTENSET_SYNCRDY			(1u << 6)
#define RTC_INTENSET_CMPx			(1u << 1,0)

	/* 0x07: Interrupt Enable Set - MODE2 */
	uint8_t volatile INTENSET;
#define RTC_INTENSET_OVF			(1u << 7)
#define RTC_INTENSET_SYNCRDY			(1u << 6)
#define RTC_INTENSET_ALARM0			(1u << 0)

	/* 0x08: Interrupt Flag Status and Clear - MODE0 */
	uint8_t volatile INTFLAG;
#define RTC_INTFLAG_OVF				(1u << 7)
#define RTC_INTFLAG_SYNCRDY			(1u << 6)
#define RTC_INTFLAG_CMP0			(1u << 0)

	/* 0x08: Interrupt Flag Status and Clear - MODE1 */
	uint8_t volatile INTFLAG;
#define RTC_INTFLAG_OVF				(1u << 7)
#define RTC_INTFLAG_SYNCRDY			(1u << 6)
#define RTC_INTFLAG_CMPx			(1u << 1,0)

	/* 0x08: Interrupt Flag Status and Clear - MODE2 */
	uint8_t volatile INTFLAG;
#define RTC_INTFLAG_OVF				(1u << 7)
#define RTC_INTFLAG_SYNCRDY			(1u << 6)
#define RTC_INTFLAG_ALARM0			(1u << 0)

	/* 0x09 */
	uint8_t volatile RESERVED0[0x0A-0x09];

	/* 0x0A: Status */
	uint8_t volatile STATUS;
#define RTC_STATUS_SYNCBUSY			(1u << 7)

	/* 0x0B: Debug Control */
	uint8_t volatile DBGCTRL;
#define RTC_DBGCTRL_DBGRUN			(1u << 0)

	/* 0x0C: Frequency Correction */
	uint8_t volatile FREQCORR;
#define RTC_FREQCORR_SIGN			(1u << 7)
#define RTC_FREQCORR_VALUE(x)			((x) << 0)
#define RTC_FREQCORR_VALUE_MASK			RTC_FREQCORR_VALUE(B01111111)

	/* 0x0D */
	uint8_t volatile RESERVED1[0x10-0x0D];

	/* 0x10: Counter Value - MODE0 */
	uint32_t volatile COUNT;
#define RTC_COUNT_COUNT(x)			((x) << 0)

	/* 0x10: Counter Value - MODE1 */
	uint16_t volatile COUNT;
#define RTC_COUNT_COUNT(x)			((x) << 0)

	/* 0x10: Clock Value - MODE2 */
	uint32_t volatile CLOCK;
#define RTC_CLOCK_YEAR(x)			((x) << 26)
#define RTC_CLOCK_YEAR_MASK			RTC_CLOCK_YEAR(B00111111)
#define RTC_CLOCK_MONTH(x)			((x) << 22)
#define RTC_CLOCK_MONTH_MASK			RTC_CLOCK_MONTH(B00001111)
#define RTC_CLOCK_DAY(x)			((x) << 17)
#define RTC_CLOCK_DAY_MASK			RTC_CLOCK_DAY(B00011111)
#define RTC_CLOCK_HOUR(x)			((x) << 12)
#define RTC_CLOCK_HOUR_MASK			RTC_CLOCK_HOUR(B00011111)
#define RTC_CLOCK_MINUTE(x)			((x) << 6)
#define RTC_CLOCK_MINUTE_MASK			RTC_CLOCK_MINUTE(B00111111)
#define RTC_CLOCK_SECOND(x)			((x) << 0)
#define RTC_CLOCK_SECOND_MASK			RTC_CLOCK_SECOND(B00111111)

	/* 0x14: Counter Period - MODE1 */
	uint16_t volatile PER;
#define RTC_PER_PER(x)				((x) << 0)

	/* 0x16 */
	uint8_t volatile RESERVED2[0x18-0x16];

	/* 0x18: Compare n Value - MODE0 */
	uint32_t volatile COMP;
#define RTC_COMP_COMP(x)			((x) << 0)

	/* 0x18: Compare n Value - MODE1 */
	uint16_t volatile COMPn;
#define RTC_COMPn_COMP(x)			((x) << 0)

	/* 0x18: Alarm 0 Value - MODE2 */
	uint32_t volatile ALARM0;
#define RTC_ALARM0_YEAR(x)			((x) << 26)
#define RTC_ALARM0_YEAR_MASK			RTC_ALARM0_YEAR(B00111111)
#define RTC_ALARM0_MONTH(x)			((x) << 22)
#define RTC_ALARM0_MONTH_MASK			RTC_ALARM0_MONTH(B00001111)
#define RTC_ALARM0_DAY(x)			((x) << 17)
#define RTC_ALARM0_DAY_MASK			RTC_ALARM0_DAY(B00011111)
#define RTC_ALARM0_HOUR(x)			((x) << 12)
#define RTC_ALARM0_HOUR_MASK			RTC_ALARM0_HOUR(B00011111)
#define RTC_ALARM0_MINUTE(x)			((x) << 6)
#define RTC_ALARM0_MINUTE_MASK			RTC_ALARM0_MINUTE(B00111111)
#define RTC_ALARM0_SECOND(x)			((x) << 0)
#define RTC_ALARM0_SECOND_MASK			RTC_ALARM0_SECOND(B00111111)

	/* 0x1C: Alarm n Mask - MODE2 */
	uint8_t volatile MASK;
#define RTC_MASK_SEL(x)				((x) << 0)
#define RTC_MASK_SEL_MASK			RTC_MASK_SEL(B00000111)

};
