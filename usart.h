#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define USART0 ((struct zmcu_usart *)SERCOM0_BASE)
#define USART1 ((struct zmcu_usart *)SERCOM1_BASE)
#define USART2 ((struct zmcu_usart *)SERCOM2_BASE)
#define USART3 ((struct zmcu_usart *)SERCOM3_BASE)
#define USART4 ((struct zmcu_usart *)SERCOM4_BASE)
#define USART5 ((struct zmcu_usart *)SERCOM5_BASE)

struct zmcu_usart {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define SERCOM_CTRLA_DORD			(1u << 30)
#define SERCOM_CTRLA_CPOL			(1u << 29)
#define SERCOM_CTRLA_CMODE			(1u << 28)
#define SERCOM_CTRLA_FORM(x)			((x) << 24)
#define SERCOM_CTRLA_SAMPA(x)			((x) << 22)
#define SERCOM_CTRLA_RXPO(x)			((x) << 20)
#define SERCOM_CTRLA_TXPO(x)			((x) << 16)
#define SERCOM_CTRLA_SAMPR(x)			((x) << 13)
#define SERCOM_CTRLA_IBON			(1u << 8)
#define SERCOM_CTRLA_RUNSTDBY			(1u << 7)
#define SERCOM_CTRLA_MODE(x)			((x) << 2)
#define SERCOM_CTRLA_ENABLE			(1u << 1)
#define SERCOM_CTRLA_SWRST			(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define SERCOM_CTRLB_FIFOCLR(x)			((x) << 22)
#define SERCOM_CTRLB_RXEN			(1u << 17)
#define SERCOM_CTRLB_TXEN			(1u << 16)
#define SERCOM_CTRLB_PMODE			(1u << 13)
#define SERCOM_CTRLB_ENC			(1u << 10)
#define SERCOM_CTRLB_SFDE			(1u << 9)
#define SERCOM_CTRLB_COLDEN			(1u << 8)
#define SERCOM_CTRLB_SBMODE			(1u << 6)
#define SERCOM_CTRLB_CHSIZE(x)			((x) << 0)

	/* 0x08 */
	uint8_t volatile RESERVED0[0x0C-0x08];

	/* 0x0C: Baud */
	uint16_t volatile BAUD;

	/* 0x0E: Receive Pulse Length Register */
	uint8_t volatile RXPL;
#define SERCOM_RXPL_RXPL(x)			((x) << 0)

	/* 0x0F */
	uint8_t volatile RESERVED1[0x14-0x0F];

	/* 0x14: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define SERCOM_INTENCLR_ERROR			(1u << 7)
#define SERCOM_INTENCLR_RXBRK			(1u << 5)
#define SERCOM_INTENCLR_CTSIC			(1u << 4)
#define SERCOM_INTENCLR_RXS			(1u << 3)
#define SERCOM_INTENCLR_RXC			(1u << 2)
#define SERCOM_INTENCLR_TXC			(1u << 1)
#define SERCOM_INTENCLR_DRE			(1u << 0)

	/* 0x15 */
	uint8_t volatile RESERVED2[0x16-0x15];

	/* 0x16: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define SERCOM_INTENSET_ERROR			(1u << 7)
#define SERCOM_INTENSET_RXBRK			(1u << 5)
#define SERCOM_INTENSET_CTSIC			(1u << 4)
#define SERCOM_INTENSET_RXS			(1u << 3)
#define SERCOM_INTENSET_RXC			(1u << 2)
#define SERCOM_INTENSET_TXC			(1u << 1)
#define SERCOM_INTENSET_DRE			(1u << 0)

	/* 0x17 */
	uint8_t volatile RESERVED3[0x18-0x17];

	/* 0x18: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define SERCOM_INTFLAG_ERROR			(1u << 7)
#define SERCOM_INTFLAG_RXBRK			(1u << 5)
#define SERCOM_INTFLAG_CTSIC			(1u << 4)
#define SERCOM_INTFLAG_RXS			(1u << 3)
#define SERCOM_INTFLAG_RXC			(1u << 2)
#define SERCOM_INTFLAG_TXC			(1u << 1)
#define SERCOM_INTFLAG_DRE			(1u << 0)

	/* 0x19 */
	uint8_t volatile RESERVED4[0x1A-0x19];

	/* 0x1A: Status */
	uint16_t volatile STATUS;
#define SERCOM_STATUS_TXE			(1u << 6)
#define SERCOM_STATUS_COLL			(1u << 5)
#define SERCOM_STATUS_ISF			(1u << 4)
#define SERCOM_STATUS_CTS			(1u << 3)
#define SERCOM_STATUS_BUFOVF			(1u << 2)
#define SERCOM_STATUS_FERR			(1u << 1)
#define SERCOM_STATUS_PERR			(1u << 0)

	/* 0x1C: Synchronization Busy */
	uint32_t volatile SYNCBUSY;
#define SERCOM_SYNCBUSY_CTRLB			(1u << 2)
#define SERCOM_SYNCBUSY_ENABLE			(1u << 1)
#define SERCOM_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint8_t volatile RESERVED5[0x28-0x20];

	/* 0x28: Data */
	uint16_t volatile DATA;

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
