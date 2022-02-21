#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define I2S ((struct zmcu_i2s *)0x42005000)
#define I2S ((struct zmcu_i2s *)0x42005000)

struct zmcu_i2s {

	/* 0x00: Control A */
	uint8_t volatile CTRLA;
#define I2S_CTRLA_SERENx			(1u << 5,4)
#define I2S_CTRLA_CKENx				(1u << 3,2)
#define I2S_CTRLA_ENABLE			(1u << 1)
#define I2S_CTRLA_SWRST				(1u << 0)

	/* 0x01 */
	uint8_t volatile RESERVED0[0x04-0x01];

	/* 0x04: Clock Unit n Control */
	uint32_t volatile CLKCTRLn;
#define I2S_CLKCTRLn_MCKOUTINV			(1u << 31)
#define I2S_CLKCTRLn_SCKOUTINV			(1u << 30)
#define I2S_CLKCTRLn_FSOUTINV			(1u << 29)
#define I2S_CLKCTRLn_MCKOUTDIV(x)		((x) << 24)
#define I2S_CLKCTRLn_MCKDIV(x)			((x) << 19)
#define I2S_CLKCTRLn_MCKEN			(1u << 18)
#define I2S_CLKCTRLn_MCKSEL			(1u << 16)
#define I2S_CLKCTRLn_SCKSEL			(1u << 12)
#define I2S_CLKCTRLn_FSINV			(1u << 11)
#define I2S_CLKCTRLn_FSSEL			(1u << 8)
#define I2S_CLKCTRLn_BITDELAY			(1u << 7)
#define I2S_CLKCTRLn_FSWIDTH(x)			((x) << 5)
#define I2S_CLKCTRLn_NBSLOTS(x)			((x) << 2)
#define I2S_CLKCTRLn_SLOTSIZE(x)		((x) << 0)

	/* 0x08 */
	uint8_t volatile RESERVED1[0x0C-0x08];

	/* 0x0C: Interrupt Enable Clear */
	uint16_t volatile INTENCLR;
#define I2S_INTENCLR_TXURx			(1u << 13,12)
#define I2S_INTENCLR_TXRDYx			(1u << 9,8)
#define I2S_INTENCLR_RXORx			(1u << 4,5)
#define I2S_INTENCLR_RXRDYx			(1u << 1,0)

	/* 0x0E */
	uint8_t volatile RESERVED2[0x10-0x0E];

	/* 0x10: Interrupt Enable Set */
	uint16_t volatile INTENSET;
#define I2S_INTENSET_TXURx			(1u << 13,12)
#define I2S_INTENSET_TXRDYx			(1u << 9,8)
#define I2S_INTENSET_RXORx			(1u << 4,5)
#define I2S_INTENSET_RXRDYx			(1u << 1,0)

	/* 0x12 */
	uint8_t volatile RESERVED3[0x14-0x12];

	/* 0x14: Interrupt Flag Status and Clear */
	uint16_t volatile INTFLAG;
#define I2S_INTFLAG_TXURx			(1u << 13,12)
#define I2S_INTFLAG_TXRDYx			(1u << 9,8)
#define I2S_INTFLAG_RXORx			(1u << 4,5)
#define I2S_INTFLAG_RXRDYx			(1u << 1,0)

	/* 0x16 */
	uint8_t volatile RESERVED4[0x18-0x16];

	/* 0x18: Synchronization Busy */
	uint16_t volatile SYNCBUSY;
#define I2S_SYNCBUSY_DATAx			(1u << 8,9)
#define I2S_SYNCBUSY_SERENx			(1u << 4,5)
#define I2S_SYNCBUSY_CKENx			(1u << 2,3)
#define I2S_SYNCBUSY_ENABLE			(1u << 1)
#define I2S_SYNCBUSY_SWRST			(1u << 0)

	/* 0x1A */
	uint8_t volatile RESERVED5[0x20-0x1A];

	/* 0x20: Serializer n Control */
	uint32_t volatile SERCTRLn;
#define I2S_SERCTRLn_RXLOOP			(1u << 26)
#define I2S_SERCTRLn_DMA			(1u << 25)
#define I2S_SERCTRLn_MONO			(1u << 24)
#define I2S_SERCTRLn_SLOTDISx			(1u << 23,22,21,20,18,19,18,17,16)
#define I2S_SERCTRLn_BITREV			(1u << 15)
#define I2S_SERCTRLn_EXTEND(x)			((x) << 13)
#define I2S_SERCTRLn_WORDADJ			(1u << 12)
#define I2S_SERCTRLn_DATASIZE(x)		((x) << 8)
#define I2S_SERCTRLn_SLOTADJ			(1u << 7)
#define I2S_SERCTRLn_CLKSEL			(1u << 5)
#define I2S_SERCTRLn_TXSAME			(1u << 4)
#define I2S_SERCTRLn_TXDEFAULT(x)		((x) << 2)
#define I2S_SERCTRLn_SERMODE(x)			((x) << 0)

	/* 0x24 */
	uint8_t volatile RESERVED6[0x30-0x24];

	/* 0x30: Data Holding m */
	uint32_t volatile DATAm;
#define I2S_DATAm_DATA(x)			((x) << 0)

	/* 0x34: Rx Data */
	uint32_t volatile RXDATA;
#define I2S_RXDATA_DATA(x)			((x) << 0)

};

