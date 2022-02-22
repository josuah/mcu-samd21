#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define SERCOM0_BASE 0x42000800
#define SERCOM1_BASE 0x42000C00
#define SERCOM2_BASE 0x42001000
#define SERCOM3_BASE 0x42001400
#define SERCOM4_BASE 0x42001800
#define SERCOM5_BASE 0x42001C00

#define SERCOM0 ((struct zmcu_sercom *)SERCOM0_BASE)
#define SERCOM1 ((struct zmcu_sercom *)SERCOM1_BASE)
#define SERCOM2 ((struct zmcu_sercom *)SERCOM2_BASE)
#define SERCOM3 ((struct zmcu_sercom *)SERCOM3_BASE)
#define SERCOM4 ((struct zmcu_sercom *)SERCOM4_BASE)
#define SERCOM5 ((struct zmcu_sercom *)SERCOM5_BASE)

struct zmcu_sercom {

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
#define SERCOM_CTRLA_MODE_MASK			SERCOM_CTRLA_MODE(B00000111)
#define SERCOM_CTRLA_MODE_USART_EXT		0x0
#define SERCOM_CTRLA_MODE_USART_INT		0x1
#define SERCOM_CTRLA_MODE_SPI_SLAVE		0x2
#define SERCOM_CTRLA_MODE_SPI_MASTER		0x3
#define SERCOM_CTRLA_MODE_I2C_SLAVE		0x4
#define SERCOM_CTRLA_MODE_I2C_MASTER		0x5
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

};
