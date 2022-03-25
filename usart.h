#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define USART0 ((struct mcu_usart *)SERCOM0_BASE)
#define USART1 ((struct mcu_usart *)SERCOM1_BASE)
#define USART2 ((struct mcu_usart *)SERCOM2_BASE)
#define USART3 ((struct mcu_usart *)SERCOM3_BASE)
#define USART4 ((struct mcu_usart *)SERCOM4_BASE)
#define USART5 ((struct mcu_usart *)SERCOM5_BASE)

struct mcu_usart {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define USART_CTRLA_DORD			(1u << 30)
#define USART_CTRLA_CPOL			(1u << 29)
#define USART_CTRLA_CMODE			(1u << 28)
#define USART_CTRLA_FORM(x)			((x) << 24)
#define USART_CTRLA_FORM_MASK			USART_CTRLA_FORM(B00001111)
#define USART_CTRLA_SAMPA(x)			((x) << 22)
#define USART_CTRLA_SAMPA_MASK			USART_CTRLA_SAMPA(B00000011)
#define USART_CTRLA_RXPO(x)			((x) << 20)
#define USART_CTRLA_RXPO_MASK			USART_CTRLA_RXPO(B00000011)
#define USART_CTRLA_RXPO_RX0			0x0
#define USART_CTRLA_RXPO_RX1			0x1
#define USART_CTRLA_RXPO_RX2			0x2
#define USART_CTRLA_RXPO_RX3			0x3
#define USART_CTRLA_TXPO(x)			((x) << 16)
#define USART_CTRLA_TXPO_MASK			USART_CTRLA_TXPO(B00000011)
#define USART_CTRLA_TXPO_TX0_CK1		0x0
#define USART_CTRLA_TXPO_TX2_CK3		0x1
#define USART_CTRLA_TXPO_TX0_RTS2_CTS3		0x2
#define USART_CTRLA_SAMPR(x)			((x) << 13)
#define USART_CTRLA_SAMPR_MASK			USART_CTRLA_SAMPR(B00000111)
#define USART_CTRLA_IBON			(1u << 8)
#define USART_CTRLA_RUNSTDBY			(1u << 7)
#define USART_CTRLA_MODE(x)			((x) << 2)
#define USART_CTRLA_MODE_MASK			USART_CTRLA_MODE(B00000111)
#define USART_CTRLA_MODE_EXTERNAL_CLK		0x0
#define USART_CTRLA_MODE_INTERNAL_CLK		0x1
#define USART_CTRLA_ENABLE			(1u << 1)
#define USART_CTRLA_SWRST			(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define USART_CTRLB_FIFOCLR(x)			((x) << 22)
#define USART_CTRLB_FIFOCLR_MASK		USART_CTRLB_FIFOCLR(B00000011)
#define USART_CTRLB_RXEN			(1u << 17)
#define USART_CTRLB_TXEN			(1u << 16)
#define USART_CTRLB_PMODE			(1u << 13)
#define USART_CTRLB_ENC				(1u << 10)
#define USART_CTRLB_SFDE			(1u << 9)
#define USART_CTRLB_COLDEN			(1u << 8)
#define USART_CTRLB_SBMODE			(1u << 6)
#define USART_CTRLB_CHSIZE(x)			((x) << 0)
#define USART_CTRLB_CHSIZE_MASK			USART_CTRLB_CHSIZE(B00000111)

	/* 0x08 */
	uint8_t volatile RESERVED0[0x0C-0x08];

	/* 0x0C: Baud */
	uint16_t volatile BAUD;
#define USART_BAUD_BAUD(x)			((x) << 0)

	/* 0x0E: Receive Pulse Length Register */
	uint8_t volatile RXPL;
#define USART_RXPL_RXPL(x)			((x) << 0)
#define USART_RXPL_RXPL_MASK			USART_RXPL_RXPL(B11111111)

	/* 0x0F */
	uint8_t volatile RESERVED1[0x14-0x0F];

	/* 0x14: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define USART_INTENCLR_ERROR			(1u << 7)
#define USART_INTENCLR_RXBRK			(1u << 5)
#define USART_INTENCLR_CTSIC			(1u << 4)
#define USART_INTENCLR_RXS			(1u << 3)
#define USART_INTENCLR_RXC			(1u << 2)
#define USART_INTENCLR_TXC			(1u << 1)
#define USART_INTENCLR_DRE			(1u << 0)

	/* 0x15 */
	uint8_t volatile RESERVED2[0x16-0x15];

	/* 0x16: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define USART_INTENSET_ERROR			(1u << 7)
#define USART_INTENSET_RXBRK			(1u << 5)
#define USART_INTENSET_CTSIC			(1u << 4)
#define USART_INTENSET_RXS			(1u << 3)
#define USART_INTENSET_RXC			(1u << 2)
#define USART_INTENSET_TXC			(1u << 1)
#define USART_INTENSET_DRE			(1u << 0)

	/* 0x17 */
	uint8_t volatile RESERVED3[0x18-0x17];

	/* 0x18: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define USART_INTFLAG_ERROR			(1u << 7)
#define USART_INTFLAG_RXBRK			(1u << 5)
#define USART_INTFLAG_CTSIC			(1u << 4)
#define USART_INTFLAG_RXS			(1u << 3)
#define USART_INTFLAG_RXC			(1u << 2)
#define USART_INTFLAG_TXC			(1u << 1)
#define USART_INTFLAG_DRE			(1u << 0)

	/* 0x19 */
	uint8_t volatile RESERVED4[0x1A-0x19];

	/* 0x1A: Status */
	uint16_t volatile STATUS;
#define USART_STATUS_TXE			(1u << 6)
#define USART_STATUS_COLL			(1u << 5)
#define USART_STATUS_ISF			(1u << 4)
#define USART_STATUS_CTS			(1u << 3)
#define USART_STATUS_BUFOVF			(1u << 2)
#define USART_STATUS_FERR			(1u << 1)
#define USART_STATUS_PERR			(1u << 0)

	/* 0x1C: Synchronization Busy */
	uint32_t volatile SYNCBUSY;
#define USART_SYNCBUSY_CTRLB			(1u << 2)
#define USART_SYNCBUSY_ENABLE			(1u << 1)
#define USART_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint8_t volatile RESERVED5[0x28-0x20];

	/* 0x28: Data */
	uint16_t volatile DATA;
#define USART_DATA_DATA(x)			((x) << 0)

	/* 0x2A */
	uint8_t volatile RESERVED6[0x30-0x2A];

	/* 0x30: Debug Control */
	uint8_t volatile DBGCTRL;
#define USART_DBGCTRL_DBGSTOP			(1u << 0)

	/* 0x31 */
	uint8_t volatile RESERVED7[0x34-0x31];

	/* 0x34: FIFO Space */
	uint16_t volatile FIFOSPACE;
#define USART_FIFOSPACE_RXSPACE(x)		((x) << 8)
#define USART_FIFOSPACE_RXSPACE_MASK		USART_FIFOSPACE_RXSPACE(B00011111)
#define USART_FIFOSPACE_TXSPACE(x)		((x) << 0)
#define USART_FIFOSPACE_TXSPACE_MASK		USART_FIFOSPACE_TXSPACE(B00011111)

	/* 0x36: FIFO CPU Pointers */
	uint16_t volatile FIFOPTR;
#define USART_FIFOPTR_CPURDPTR(x)		((x) << 8)
#define USART_FIFOPTR_CPURDPTR_MASK		USART_FIFOPTR_CPURDPTR(B00001111)
#define USART_FIFOPTR_CPUWRPTR(x)		((x) << 0)
#define USART_FIFOPTR_CPUWRPTR_MASK		USART_FIFOPTR_CPUWRPTR(B00001111)

};
