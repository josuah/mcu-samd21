#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define SERCOM0 ((struct zmcu_sercom *)0x42000800)
#define SERCOM1 ((struct zmcu_sercom *)0x42000C00)
#define SERCOM2 ((struct zmcu_sercom *)0x42001000)
#define SERCOM3 ((struct zmcu_sercom *)0x42001400)
#define SERCOM4 ((struct zmcu_sercom *)0x42001800)
#define SERCOM5 ((struct zmcu_sercom *)0x42001C00)

struct zmcu_sercom {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define SERCOM_CTRLA_DORD			(1u << 30)
#define SERCOM_CTRLA_CPOL			(1u << 29)
#define SERCOM_CTRLA_CPHA			(1u << 28)
#define SERCOM_CTRLA_FORM(x)			((x) << 24)
#define SERCOM_CTRLA_DIPO(x)			((x) << 20)
#define SERCOM_CTRLA_DOPO(x)			((x) << 16)
#define SERCOM_CTRLA_IBON			(1u << 8)
#define SERCOM_CTRLA_RUNSTDBY			(1u << 7)
#define SERCOM_CTRLA_MODE(x)			((x) << 2)
#define SERCOM_CTRLA_ENABLE			(1u << 1)
#define SERCOM_CTRLA_SWRST			(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define SERCOM_CTRLB_FIFOCLR(x)			((x) << 22)
#define SERCOM_CTRLB_RXEN			(1u << 17)
#define SERCOM_CTRLB_AMODE(x)			((x) << 14)
#define SERCOM_CTRLB_MSSEN			(1u << 13)
#define SERCOM_CTRLB_SSDE			(1u << 9)
#define SERCOM_CTRLB_PLOADEN			(1u << 6)
#define SERCOM_CTRLB_CHSIZE(x)			((x) << 0)

	/* 0x08 */
	uint8_t volatile RESERVED0[0x0C-0x08];

	/* 0x0C: Baud Rate */
	uint8_t volatile BAUD;
#define SERCOM_BAUD_BAUD(x)			((x) << 0)

	/* 0x0D */
	uint8_t volatile RESERVED1[0x14-0x0D];

	/* 0x14: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define SERCOM_INTENCLR_ERROR			(1u << 7)
#define SERCOM_INTENCLR_SSL			(1u << 3)
#define SERCOM_INTENCLR_RXC			(1u << 2)
#define SERCOM_INTENCLR_TXC			(1u << 1)
#define SERCOM_INTENCLR_DRE			(1u << 0)

	/* 0x15 */
	uint8_t volatile RESERVED2[0x16-0x15];

	/* 0x16: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define SERCOM_INTENSET_ERROR			(1u << 7)
#define SERCOM_INTENSET_SSL			(1u << 3)
#define SERCOM_INTENSET_RXC			(1u << 2)
#define SERCOM_INTENSET_TXC			(1u << 1)
#define SERCOM_INTENSET_DRE			(1u << 0)

	/* 0x17 */
	uint8_t volatile RESERVED3[0x18-0x17];

	/* 0x18: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define SERCOM_INTFLAG_ERROR			(1u << 7)
#define SERCOM_INTFLAG_SSL			(1u << 3)
#define SERCOM_INTFLAG_RXC			(1u << 2)
#define SERCOM_INTFLAG_TXC			(1u << 1)
#define SERCOM_INTFLAG_DRE			(1u << 0)

	/* 0x19 */
	uint8_t volatile RESERVED4[0x1A-0x19];

	/* 0x1A: Status */
	uint16_t volatile STATUS;
#define SERCOM_STATUS_BUFOVF			(1u << 2)

	/* 0x1C: Synchronization Busy */
	uint32_t volatile SYNCBUSY;
#define SERCOM_SYNCBUSY_CTRLB			(1u << 2)
#define SERCOM_SYNCBUSY_ENABLE			(1u << 1)
#define SERCOM_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint8_t volatile RESERVED5[0x24-0x20];

	/* 0x24: Address */
	uint32_t volatile ADDR;
#define SERCOM_ADDR_ADDRMASK(x)			((x) << 16)
#define SERCOM_ADDR_ADDR(x)			((x) << 0)

	/* 0x28: Data */
	uint16_t volatile DATA;
#define SERCOM_DATA_DATA(x)			((x) << 0)

	/* 0x2A */
	uint8_t volatile RESERVED6[0x30-0x2A];

	/* 0x30: Debug Control */
	uint8_t volatile DBGCTRL;
#define SERCOM_DBGCTRL_DBGSTOP			(1u << 0)

	/* 0x31 */
	uint8_t volatile RESERVED7[0x34-0x31];

	/* 0x34: FIFO Space */
	uint16_t volatile FIFOSPACE;
#define SERCOM_FIFOSPACE_RXSPACE(x)		((x) << 8)
#define SERCOM_FIFOSPACE_TXSPACE(x)		((x) << 0)

	/* 0x36: FIFO CPU Pointers */
	uint16_t volatile FIFOPTR;
#define SERCOM_FIFOPTR_CPURDPTR(x)		((x) << 8)
#define SERCOM_FIFOPTR_CPUWRPTR(x)		((x) << 0)

};
