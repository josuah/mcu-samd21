#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define TCC0 ((struct sdk_tcc *)0x42002000)
#define TCC0 ((struct sdk_tcc *)0x42002000)
#define TCC1 ((struct sdk_tcc *)0x42002400)
#define TCC1 ((struct sdk_tcc *)0x42002400)
#define TCC2 ((struct sdk_tcc *)0x42002800)
#define TCC2 ((struct sdk_tcc *)0x42002800)

struct sdk_tcc {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define TCC_CTRLA_ALOCK				(1u << 14)
#define TCC_CTRLA_PRESCYNC(x)			((x) << 12)
#define TCC_CTRLA_PRESCYNC_MASK			TCC_CTRLA_PRESCYNC(B00000011)
#define TCC_CTRLA_RUNSTDBY			(1u << 11)
#define TCC_CTRLA_PRESCALER(x)			((x) << 8)
#define TCC_CTRLA_PRESCALER_MASK		TCC_CTRLA_PRESCALER(B00000111)
#define TCC_CTRLA_RESOLUTION(x)			((x) << 5)
#define TCC_CTRLA_RESOLUTION_MASK		TCC_CTRLA_RESOLUTION(B00000011)
#define TCC_CTRLA_ENABLE			(1u << 1)
#define TCC_CTRLA_SWRST				(1u << 0)

	/* 0x04: Control B Clear */
	uint8_t volatile CTRLBCLR;
#define TCC_CTRLBCLR_CMD(x)			((x) << 5)
#define TCC_CTRLBCLR_CMD_MASK			TCC_CTRLBCLR_CMD(B00000111)
#define TCC_CTRLBCLR_IDXCMD(x)			((x) << 3)
#define TCC_CTRLBCLR_IDXCMD_MASK		TCC_CTRLBCLR_IDXCMD(B00000011)
#define TCC_CTRLBCLR_ONESHOT			(1u << 2)
#define TCC_CTRLBCLR_LUPD			(1u << 1)
#define TCC_CTRLBCLR_DIR			(1u << 0)

	/* 0x05: Control B Set */
	uint8_t volatile CTRLBSET;
#define TCC_CTRLBSET_CMD(x)			((x) << 5)
#define TCC_CTRLBSET_CMD_MASK			TCC_CTRLBSET_CMD(B00000111)
#define TCC_CTRLBSET_IDXCMD(x)			((x) << 3)
#define TCC_CTRLBSET_IDXCMD_MASK		TCC_CTRLBSET_IDXCMD(B00000011)
#define TCC_CTRLBSET_ONESHOT			(1u << 2)
#define TCC_CTRLBSET_LUPD			(1u << 1)
#define TCC_CTRLBSET_DIR			(1u << 0)

	/* 0x06 */
	uint8_t volatile RESERVED0[0x08-0x06];

	/* 0x08: Synchronization Busy */
	uint32_t volatile SYNCBUSY;
#define TCC_SYNCBUSY_PERB			(1u << 18)
#define TCC_SYNCBUSY_WAVEB			(1u << 17)
#define TCC_SYNCBUSY_PATTB			(1u << 16)
#define TCC_SYNCBUSY_PER			(1u << 7)
#define TCC_SYNCBUSY_WAVE			(1u << 6)
#define TCC_SYNCBUSY_PATT			(1u << 5)
#define TCC_SYNCBUSY_COUNT			(1u << 4)
#define TCC_SYNCBUSY_STATUS			(1u << 3)
#define TCC_SYNCBUSY_CTRLB			(1u << 2)
#define TCC_SYNCBUSY_ENABLE			(1u << 1)
#define TCC_SYNCBUSY_SWRST			(1u << 0)

	/* 0x0C: Fault Control A and B */
	uint32_t volatile FCTRLA,;
#define TCC_FCTRLA,_FILTERVAL(x)		((x) << 24)
#define TCC_FCTRLA,_FILTERVAL_MASK		TCC_FCTRLA,_FILTERVAL(B00001111)
#define TCC_FCTRLA,_BLANKVAL(x)			((x) << 16)
#define TCC_FCTRLA,_BLANKVAL_MASK		TCC_FCTRLA,_BLANKVAL(B11111111)
#define TCC_FCTRLA,_CAPTURE(x)			((x) << 12)
#define TCC_FCTRLA,_CAPTURE_MASK		TCC_FCTRLA,_CAPTURE(B00000111)
#define TCC_FCTRLA,_CHSEL(x)			((x) << 10)
#define TCC_FCTRLA,_CHSEL_MASK			TCC_FCTRLA,_CHSEL(B00000011)
#define TCC_FCTRLA,_HALT(x)			((x) << 8)
#define TCC_FCTRLA,_HALT_MASK			TCC_FCTRLA,_HALT(B00000011)
#define TCC_FCTRLA,_RESTART			(1u << 7)
#define TCC_FCTRLA,_BLANK(x)			((x) << 5)
#define TCC_FCTRLA,_BLANK_MASK			TCC_FCTRLA,_BLANK(B00000011)
#define TCC_FCTRLA,_QUAL			(1u << 4)
#define TCC_FCTRLA,_KEEP			(1u << 3)
#define TCC_FCTRLA,_SRC(x)			((x) << 0)
#define TCC_FCTRLA,_SRC_MASK			TCC_FCTRLA,_SRC(B00000011)

	/* 0x10 */
	uint8_t volatile RESERVED1[0x14-0x10];

	/* 0x14: Waveform Extension Control */
	uint32_t volatile WEXCTRL;
#define TCC_WEXCTRL_DTHS(x)			((x) << 24)
#define TCC_WEXCTRL_DTHS_MASK			TCC_WEXCTRL_DTHS(B11111111)
#define TCC_WEXCTRL_DTLS(x)			((x) << 16)
#define TCC_WEXCTRL_DTLS_MASK			TCC_WEXCTRL_DTLS(B11111111)
#define TCC_WEXCTRL_DTIENx			(1u << 11,10,9,8)
#define TCC_WEXCTRL_OTMX(x)			((x) << 0)
#define TCC_WEXCTRL_OTMX_MASK			TCC_WEXCTRL_OTMX(B00000011)

	/* 0x18: Driver Control */
	uint32_t volatile DRVCTRL;
#define TCC_DRVCTRL_FILTERVAL1(x)		((x) << 28)
#define TCC_DRVCTRL_FILTERVAL1_MASK		TCC_DRVCTRL_FILTERVAL1(B00001111)
#define TCC_DRVCTRL_FILTERVAL0(x)		((x) << 24)
#define TCC_DRVCTRL_FILTERVAL0_MASK		TCC_DRVCTRL_FILTERVAL0(B00001111)
#define TCC_DRVCTRL_INVENx			(1u << 23,22,21,20,19,18,17,16)
#define TCC_DRVCTRL_NRVx			(1u << 15,14,13,12,11,10,9,8)
#define TCC_DRVCTRL_NREx			(1u << 7,6,5,4,3,2,1,0)

	/* 0x1C */
	uint8_t volatile RESERVED2[0x1E-0x1C];

	/* 0x1E: Debug control */
	uint8_t volatile DBGCTRL;
#define TCC_DBGCTRL_FDDBD			(1u << 2)
#define TCC_DBGCTRL_DBGRUN			(1u << 0)

	/* 0x1F */
	uint8_t volatile RESERVED3[0x20-0x1F];

	/* 0x20: Event Control */
	uint32_t volatile EVCTRL;
#define TCC_EVCTRL_MCEOx			(1u << 27,26,25,24)
#define TCC_EVCTRL_MCEIx			(1u << 19,18,17,16)
#define TCC_EVCTRL_TCEIx			(1u << 15,14)
#define TCC_EVCTRL_TCINVx			(1u << 13,12)
#define TCC_EVCTRL_CNTEO			(1u << 10)
#define TCC_EVCTRL_TRGEO			(1u << 9)
#define TCC_EVCTRL_OVFEO			(1u << 8)
#define TCC_EVCTRL_CNTSEL(x)			((x) << 6)
#define TCC_EVCTRL_CNTSEL_MASK			TCC_EVCTRL_CNTSEL(B00000011)
#define TCC_EVCTRL_EVACT1(x)			((x) << 3)
#define TCC_EVCTRL_EVACT1_MASK			TCC_EVCTRL_EVACT1(B00000111)
#define TCC_EVCTRL_EVACT0(x)			((x) << 0)
#define TCC_EVCTRL_EVACT0_MASK			TCC_EVCTRL_EVACT0(B00000111)

	/* 0x24: Interrupt Enable Clear */
	uint32_t volatile INTENCLR;
#define TCC_INTENCLR_MCx			(1u << 19,18,17,16)
#define TCC_INTENCLR_FAULT1			(1u << 15)
#define TCC_INTENCLR_FAULT0			(1u << 14)
#define TCC_INTENCLR_FAULTB			(1u << 13)
#define TCC_INTENCLR_FAULTA			(1u << 12)
#define TCC_INTENCLR_DFS			(1u << 11)
#define TCC_INTENCLR_UFS			(1u << 10)
#define TCC_INTENCLR_ERR			(1u << 3)
#define TCC_INTENCLR_CNT			(1u << 2)
#define TCC_INTENCLR_TRG			(1u << 1)
#define TCC_INTENCLR_OVF			(1u << 0)

	/* 0x28: Interrupt Enable Set */
	uint32_t volatile INTENSET;
#define TCC_INTENSET_MCx			(1u << 19,18,17,16)
#define TCC_INTENSET_FAULT1			(1u << 15)
#define TCC_INTENSET_FAULT0			(1u << 14)
#define TCC_INTENSET_FAULTB			(1u << 13)
#define TCC_INTENSET_FAULTA			(1u << 12)
#define TCC_INTENSET_DFS			(1u << 11)
#define TCC_INTENSET_UFS			(1u << 10)
#define TCC_INTENSET_ERR			(1u << 3)
#define TCC_INTENSET_CNT			(1u << 2)
#define TCC_INTENSET_TRG			(1u << 1)
#define TCC_INTENSET_OVF			(1u << 0)

	/* 0x2C: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
#define TCC_INTFLAG_MCx				(1u << 19,18,17,16)
#define TCC_INTFLAG_FAULT1			(1u << 15)
#define TCC_INTFLAG_FAULT0			(1u << 14)
#define TCC_INTFLAG_FAULTB			(1u << 13)
#define TCC_INTFLAG_FAULTA			(1u << 12)
#define TCC_INTFLAG_DFS				(1u << 11)
#define TCC_INTFLAG_UFS				(1u << 10)
#define TCC_INTFLAG_ERR				(1u << 3)
#define TCC_INTFLAG_CNT				(1u << 2)
#define TCC_INTFLAG_TRG				(1u << 1)
#define TCC_INTFLAG_OVF				(1u << 0)

	/* 0x30: Status */
	uint32_t volatile STATUS;
#define TCC_STATUS_CMPx				(1u << 27,26,25,24)
#define TCC_STATUS_CCBVx			(1u << 19,18,17,16)
#define TCC_STATUS_FAULTx			(1u << 15,14)
#define TCC_STATUS_FAULTB			(1u << 13)
#define TCC_STATUS_FAULTA			(1u << 12)
#define TCC_STATUS_FAULT1IN			(1u << 11)
#define TCC_STATUS_FAULT0IN			(1u << 10)
#define TCC_STATUS_FAULTBIN			(1u << 9)
#define TCC_STATUS_FAULTAIN			(1u << 8)
#define TCC_STATUS_PERBV			(1u << 7)
#define TCC_STATUS_WAVEBV			(1u << 6)
#define TCC_STATUS_PATTBV			(1u << 5)
#define TCC_STATUS_DFS				(1u << 3)
#define TCC_STATUS_UFS				(1u << 2)
#define TCC_STATUS_IDX				(1u << 1)
#define TCC_STATUS_STOP				(1u << 0)

	/* 0x34: Counter Value */
	uint32_t volatile COUNT;
#define TCC_COUNT_COUNT(x)			((x) << 0)

	/* 0x38: Pattern */
	uint16_t volatile PATT;

	/* 0x3A */
	uint8_t volatile RESERVED4[0x3C-0x3A];

	/* 0x3C: Waveform */
	uint32_t volatile WAVE;
#define TCC_WAVE_CIPEREN			(1u << 7)
#define TCC_WAVE_RAMP(x)			((x) << 4)
#define TCC_WAVE_RAMP_MASK			TCC_WAVE_RAMP(B00000011)
#define TCC_WAVE_WAVEGEN(x)			((x) << 0)
#define TCC_WAVE_WAVEGEN_MASK			TCC_WAVE_WAVEGEN(B00000111)

	/* 0x40: Period Value */
	uint32_t volatile PER;
#define TCC_PER_PER(x)				((x) << 6)
#define TCC_PER_DITHER(x)			((x) << 0)
#define TCC_PER_DITHER_MASK			TCC_PER_DITHER(B00111111)

	/* 0x44: Compare/Capture Channel x */
	uint32_t volatile CC;
#define TCC_CC_CC(x)				((x) << 6)
#define TCC_CC_DITHER(x)			((x) << 0)
#define TCC_CC_DITHER_MASK			TCC_CC_DITHER(B00111111)

	/* 0x48 */
	uint8_t volatile RESERVED5[0x64-0x48];

	/* 0x64: Pattern Buffer */
	uint16_t volatile PATTB;

	/* 0x66 */
	uint8_t volatile RESERVED6[0x68-0x66];

	/* 0x68: Waveform Buffer */
	uint32_t volatile WAVEB;
#define TCC_WAVEB_CIPERENB			(1u << 7)
#define TCC_WAVEB_RAMPB(x)			((x) << 4)
#define TCC_WAVEB_RAMPB_MASK			TCC_WAVEB_RAMPB(B00000011)
#define TCC_WAVEB_WAVEGENB(x)			((x) << 0)
#define TCC_WAVEB_WAVEGENB_MASK			TCC_WAVEB_WAVEGENB(B00000111)

	/* 0x6C: Period Buffer Value */
	uint32_t volatile PERB;
#define TCC_PERB_PERB(x)			((x) << 6)
#define TCC_PERB_DITHERB(x)			((x) << 0)
#define TCC_PERB_DITHERB_MASK			TCC_PERB_DITHERB(B00111111)

	/* 0x70: Channel x Compare/Capture Buffer Value */
	uint32_t volatile CCB;
#define TCC_CCB_CCB(x)				((x) << 6)
#define TCC_CCB_DITHERB(x)			((x) << 0)
#define TCC_CCB_DITHERB_MASK			TCC_CCB_DITHERB(B00111111)

};
