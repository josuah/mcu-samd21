#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define I2C0M ((struct zmcu_i2c_master *)SERCOM0_BASE)
#define I2C0S ((struct zmcu_i2c_slave *)SERCOM0_BASE)
#define I2C1M ((struct zmcu_i2c_master *)SERCOM1_BASE)
#define I2C1S ((struct zmcu_i2c_slave *)SERCOM1_BASE)
#define I2C2M ((struct zmcu_i2c_master *)SERCOM2_BASE)
#define I2C2S ((struct zmcu_i2c_slave *)SERCOM2_BASE)
#define I2C3M ((struct zmcu_i2c_master *)SERCOM3_BASE)
#define I2C3S ((struct zmcu_i2c_slave *)SERCOM3_BASE)
#define I2C4M ((struct zmcu_i2c_master *)SERCOM4_BASE)
#define I2C4S ((struct zmcu_i2c_slave *)SERCOM4_BASE)
#define I2C5M ((struct zmcu_i2c_master *)SERCOM5_BASE)
#define I2C5S ((struct zmcu_i2c_slave *)SERCOM5_BASE)

struct zmcu_i2c_slave {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define I2C_CTRLA_LOWTOUT			(1u << 30)
#define I2C_CTRLA_SCLSM				(1u << 27)
#define I2C_CTRLA_SPEED(x)			((x) << 24)
#define I2C_CTRLA_SEXTTOEN			(1u << 23)
#define I2C_CTRLA_SDAHOLD(x)			((x) << 20)
#define I2C_CTRLA_PINOUT			(1u << 16)
#define I2C_CTRLA_RUNSTDBY			(1u << 7)
#define I2C_CTRLA_MODE(x)			((x) << 2)
#define I2C_CTRLA_ENABLE			(1u << 1)
#define I2C_CTRLA_SWRST				(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define I2C_CTRLB_FIFOCLR(x)			((x) << 22)
#define I2C_CTRLB_ACKACT			(1u << 18)
#define I2C_CTRLB_CMD(x)			((x) << 16)
#define I2C_CTRLB_AMODE(x)			((x) << 14)
#define I2C_CTRLB_AACKEN			(1u << 10)
#define I2C_CTRLB_GCMD				(1u << 9)
#define I2C_CTRLB_SMEN				(1u << 8)

	/* 0x08 */
	uint8_t volatile RESERVED0[0x14-0x08];

	/* 0x14: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define I2C_INTENCLR_ERROR			(1u << 7)
#define I2C_INTENCLR_RXFF			(1u << 4)
#define I2C_INTENCLR_TXFE			(1u << 3)
#define I2C_INTENCLR_DRDY			(1u << 2)
#define I2C_INTENCLR_AMATCH			(1u << 1)
#define I2C_INTENCLR_PREC			(1u << 0)

	/* 0x15 */
	uint8_t volatile RESERVED1[0x16-0x15];

	/* 0x16: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define I2C_INTENSET_ERROR			(1u << 7)
#define I2C_INTENSET_RXFF			(1u << 4)
#define I2C_INTENSET_TXFE			(1u << 3)
#define I2C_INTENSET_DRDY			(1u << 2)
#define I2C_INTENSET_AMATCH			(1u << 1)
#define I2C_INTENSET_PREC			(1u << 0)

	/* 0x17 */
	uint8_t volatile RESERVED2[0x18-0x17];

	/* 0x18: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define I2C_INTFLAG_ERROR			(1u << 7)
#define I2C_INTFLAG_RXFF			(1u << 4)
#define I2C_INTFLAG_TXFE			(1u << 3)
#define I2C_INTFLAG_DRDY			(1u << 2)
#define I2C_INTFLAG_AMATCH			(1u << 1)
#define I2C_INTFLAG_PREC			(1u << 0)

	/* 0x19 */
	uint8_t volatile RESERVED3[0x1A-0x19];

	/* 0x1A: Status */
	uint16_t volatile STATUS;
#define I2C_STATUS_LENERR			(1u << 11)
#define I2C_STATUS_HS				(1u << 10)
#define I2C_STATUS_SEXTTOUT			(1u << 9)
#define I2C_STATUS_CLKHOLD			(1u << 7)
#define I2C_STATUS_LOWTOUT			(1u << 6)
#define I2C_STATUS_SR				(1u << 4)
#define I2C_STATUS_DIR				(1u << 3)
#define I2C_STATUS_RXNACK			(1u << 2)
#define I2C_STATUS_COLL				(1u << 1)
#define I2C_STATUS_BUSERR			(1u << 0)

	/* 0x1C: Synchronization Busy */
	uint32_t volatile SYNCBUSY;
#define I2C_SYNCBUSY_SYSOP			(1u << 2)
#define I2C_SYNCBUSY_ENABLE			(1u << 1)
#define I2C_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint8_t volatile RESERVED4[0x24-0x20];

	/* 0x24: Address */
	uint32_t volatile ADDR;
#define I2C_ADDR_ADDRMASK(x)			((x) << 17)
#define I2C_ADDR_TENBITEN			(1u << 15)
#define I2C_ADDR_ADDR(x)			((x) << 1)
#define I2C_ADDR_GENCEN				(1u << 0)

	/* 0x28: Data */
	uint16_t volatile DATA;
#define I2C_DATA_DATA(x)			((x) << 0)

	/* 0x2A */
	uint8_t volatile RESERVED5[0x34-0x2A];

	/* 0x34: FIFO Space */
	uint16_t volatile FIFOSPACE;
#define I2C_FIFOSPACE_RXSPACE(x)		((x) << 8)
#define I2C_FIFOSPACE_TXSPACE(x)		((x) << 0)

	/* 0x36: FIFO CPU Pointers */
	uint16_t volatile FIFOPTR;
#define I2C_FIFOPTR_CPURDPTR(x)			((x) << 8)
#define I2C_FIFOPTR_CPUWRPTR(x)			((x) << 0)

};

struct zmcu_i2c_master {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define I2C_CTRLA_LOWTOUT			(1u << 30)
#define I2C_CTRLA_INACTOUT(x)			((x) << 28)
#define I2C_CTRLA_SCLSM				(1u << 27)
#define I2C_CTRLA_SPEED(x)			((x) << 24)
#define I2C_CTRLA_SEXTTOEN			(1u << 23)
#define I2C_CTRLA_MEXTTOEN			(1u << 22)
#define I2C_CTRLA_SDAHOLD(x)			((x) << 20)
#define I2C_CTRLA_PINOUT			(1u << 16)
#define I2C_CTRLA_RUNSTDBY			(1u << 7)
#define I2C_CTRLA_MODE(x)			((x) << 2)
#define I2C_CTRLA_ENABLE			(1u << 1)
#define I2C_CTRLA_SWRST				(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define I2C_CTRLB_FIFOCLR(x)			((x) << 22)
#define I2C_CTRLB_ACKACT			(1u << 18)
#define I2C_CTRLB_CMD(x)			((x) << 16)
#define I2C_CTRLB_QCEN				(1u << 9)
#define I2C_CTRLB_SMEN				(1u << 8)

	/* 0x08 */
	uint8_t volatile RESERVED0[0x0C-0x08];

	/* 0x0C: Baud Rate */
	uint32_t volatile BAUD;
#define I2C_BAUD_HSBAUDLOW(x)			((x) << 24)
#define I2C_BAUD_HSBAUD(x)			((x) << 16)
#define I2C_BAUD_BAUDLOW(x)			((x) << 8)
#define I2C_BAUD_BAUD(x)			((x) << 0)

	/* 0x10 */
	uint8_t volatile RESERVED1[0x14-0x10];

	/* 0x14: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define I2C_INTENCLR_ERROR			(1u << 7)
#define I2C_INTENCLR_RXFF			(1u << 4)
#define I2C_INTENCLR_TXFE			(1u << 3)
#define I2C_INTENCLR_SB				(1u << 1)
#define I2C_INTENCLR_MB				(1u << 0)

	/* 0x15 */
	uint8_t volatile RESERVED2[0x16-0x15];

	/* 0x16: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define I2C_INTENSET_ERROR			(1u << 7)
#define I2C_INTENSET_RXFF			(1u << 4)
#define I2C_INTENSET_TXFE			(1u << 3)
#define I2C_INTENSET_SB				(1u << 1)
#define I2C_INTENSET_MB				(1u << 0)

	/* 0x17 */
	uint8_t volatile RESERVED3[0x18-0x17];

	/* 0x18: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define I2C_INTFLAG_ERROR			(1u << 7)
#define I2C_INTFLAG_RXFF			(1u << 4)
#define I2C_INTFLAG_TXFE			(1u << 3)
#define I2C_INTFLAG_SB				(1u << 1)
#define I2C_INTFLAG_MB				(1u << 0)

	/* 0x19 */
	uint8_t volatile RESERVED4[0x1A-0x19];

	/* 0x1A: Status */
	uint16_t volatile STATUS;
#define I2C_STATUS_LENERR			(1u << 10)
#define I2C_STATUS_SEXTTOUT			(1u << 9)
#define I2C_STATUS_MEXTTOUT			(1u << 8)
#define I2C_STATUS_CLKHOLD			(1u << 7)
#define I2C_STATUS_LOWTOUT			(1u << 6)
#define I2C_STATUS_BUSSTATE(x)			((x) << 4)
#define I2C_STATUS_RXNACK			(1u << 2)
#define I2C_STATUS_ARBLOST			(1u << 1)
#define I2C_STATUS_BUSERR			(1u << 0)

	/* 0x1C: Synchronization Busy */
	uint32_t volatile SYNCBUSY;
#define I2C_SYNCBUSY_SYSOP			(1u << 2)
#define I2C_SYNCBUSY_ENABLE			(1u << 1)
#define I2C_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint8_t volatile RESERVED5[0x24-0x20];

	/* 0x24: Address */
	uint32_t volatile ADDR;
#define I2C_ADDR_LEN(x)				((x) << 16)
#define I2C_ADDR_TENBITEN			(1u << 15)
#define I2C_ADDR_HS				(1u << 14)
#define I2C_ADDR_LENEN				(1u << 13)
#define I2C_ADDR_ADDR(x)			((x) << 0)

	/* 0x18: Data */
	uint16_t volatile DATA;
#define I2C_DATA_DATA(x)			((x) << 0)

	/* 0x1A */
	uint8_t volatile RESERVED6[0x30-0x1A];

	/* 0x30: Debug Control */
	uint8_t volatile DBGCTRL;
#define I2C_DBGCTRL_DBGSTOP			(1u << 0)

	/* 0x31 */
	uint8_t volatile RESERVED7[0x34-0x31];

	/* 0x34: FIFO Space */
	uint16_t volatile FIFOSPACE;
#define I2C_FIFOSPACE_RXSPACE(x)		((x) << 8)
#define I2C_FIFOSPACE_TXSPACE(x)		((x) << 0)

	/* 0x36: FIFO CPU Pointers */
	uint16_t volatile FIFOPTR;
#define I2C_FIFOPTR_CPURDPTR(x)			((x) << 8)
#define I2C_FIFOPTR_CPUWRPTR(x)			((x) << 0)

};
