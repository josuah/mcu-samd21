#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define USB ((struct zmcu_usb *)0x41005000)
#define USB ((struct zmcu_usb *)0x41005000)

struct zmcu_usb {

	/* 0x00: Control A */
	uint8_t volatile CTRLA;
#define USB_CTRLA_MODE				(1u << 7)
#define USB_CTRLA_RUNSTDBY			(1u << 2)
#define USB_CTRLA_ENABLE			(1u << 1)
#define USB_CTRLA_SWRST				(1u << 0)

	/* 0x01 */
	uint8_t volatile RESERVED0[0x02-0x01];

	/* 0x02: Synchronization Busy */
	uint8_t volatile SYNCBUSY;
#define USB_SYNCBUSY_ENABLE			(1u << 1)
#define USB_SYNCBUSY_SWRST			(1u << 0)

	/* 0x03: QOS Control */
	uint8_t volatile QOSCTRL;
#define USB_QOSCTRL_DQOS(x)			((x) << 2)
#define USB_QOSCTRL_CQOS(x)			((x) << 0)

	/* 0x04 */
	uint8_t volatile RESERVED1[0x0D-0x04];

	/* 0x0D: Finite State Machine Status */
	uint8_t volatile FSMSTATUS;
#define USB_FSMSTATUS_FSMSTATE(x)		((x) << 0)

	/* 0x0E */
	uint8_t volatile RESERVED2[0x24-0x0E];

	/* 0x24: Descriptor Address */
	uint32_t volatile DESCADD;
#define USB_DESCADD_DESCADD(x)			((x) << 0)

	/* 0x28: Pad Calibration */
	uint16_t volatile PADCAL;
#define USB_PADCAL_TRIM(x)			((x) << 12)
#define USB_PADCAL_TRANSN(x)			((x) << 6)
#define USB_PADCAL_TRANSP(x)			((x) << 0)

	/* 0x08: Control B */
	uint16_t volatile CTRLB;
#define USB_CTRLB_LPMHDSK(x)			((x) << 10)
#define USB_CTRLB_GNAK				(1u << 9)
#define USB_CTRLB_NREPLY			(1u << 4)
#define USB_CTRLB_SPDCONF(x)			((x) << 2)
#define USB_CTRLB_UPRSM				(1u << 1)
#define USB_CTRLB_DETACH			(1u << 0)

	/* 0x0A: Device Address */
	uint8_t volatile DADD;
#define USB_DADD_ADDEN				(1u << 7)
#define USB_DADD_DADD(x)			((x) << 0)

	/* 0x0B */
	uint8_t volatile RESERVED3[0x0C-0x0B];

	/* 0x0C: Status */
	uint8_t volatile STATUS;
#define USB_STATUS_LINESTATE(x)			((x) << 6)
#define USB_STATUS_SPEED(x)			((x) << 2)

	/* 0x0D */
	uint8_t volatile RESERVED4[0x10-0x0D];

	/* 0x10: Device Frame Number */
	uint16_t volatile FNUM;
#define USB_FNUM_FNCERR				(1u << 15)
#define USB_FNUM_FNUM(x)			((x) << 3)
#define USB_FNUM_MFNUM(x)			((x) << 0)

	/* 0x12 */
	uint8_t volatile RESERVED5[0x14-0x12];

	/* 0x14: Device Interrupt Enable Clear */
	uint16_t volatile INTENCLR;
#define USB_INTENCLR_LPMSUSP			(1u << 9)
#define USB_INTENCLR_LPMNYET			(1u << 8)
#define USB_INTENCLR_RAMACER			(1u << 7)
#define USB_INTENCLR_UPRSM			(1u << 6)
#define USB_INTENCLR_EORSM			(1u << 5)
#define USB_INTENCLR_WAKEUP			(1u << 4)
#define USB_INTENCLR_EORST			(1u << 3)
#define USB_INTENCLR_SOF			(1u << 2)
#define USB_INTENCLR_SUSPEND			(1u << 0)

	/* 0x16 */
	uint8_t volatile RESERVED6[0x18-0x16];

	/* 0x18: Device Interrupt Enable Set */
	uint16_t volatile INTENSET;
#define USB_INTENSET_LPMSUSP			(1u << 9)
#define USB_INTENSET_LPMNYET			(1u << 8)
#define USB_INTENSET_RAMACER			(1u << 7)
#define USB_INTENSET_UPRSM			(1u << 6)
#define USB_INTENSET_EORSM			(1u << 5)
#define USB_INTENSET_WAKEUP			(1u << 4)
#define USB_INTENSET_EORST			(1u << 3)
#define USB_INTENSET_SOF			(1u << 2)
#define USB_INTENSET_SUSPEND			(1u << 0)

	/* 0x1A */
	uint8_t volatile RESERVED7[0x1C-0x1A];

	/* 0x1C: Device Interrupt Flag Status and Clear */
	uint16_t volatile INTFLAG;
#define USB_INTFLAG_LPMSUSP			(1u << 9)
#define USB_INTFLAG_LPMNYET			(1u << 8)
#define USB_INTFLAG_RAMACER			(1u << 7)
#define USB_INTFLAG_UPRSM			(1u << 6)
#define USB_INTFLAG_EORSM			(1u << 5)
#define USB_INTFLAG_WAKEUP			(1u << 4)
#define USB_INTFLAG_EORST			(1u << 3)
#define USB_INTFLAG_SOF				(1u << 2)
#define USB_INTFLAG_SUSPEND			(1u << 0)

	/* 0x1E */
	uint8_t volatile RESERVED8[0x20-0x1E];

	/* 0x20: Endpoint Interrupt Summary */
	uint16_t volatile EPINTSMRY;
#define USB_EPINTSMRY_EPINT(x)			((x) << 0)

	/* 0x22 */
	uint8_t volatile RESERVED9[0x100-0x22];

	/* 0x100: Device Endpoint Configuration register n */
	uint8_t volatile EPCFGn;
#define USB_EPCFGn_EPTYPE1(x)			((x) << 4)
#define USB_EPCFGn_EPTYPE0(x)			((x) << 0)

	/* 0x101 */
	uint8_t volatile RESERVED10[0x104-0x101];

	/* 0x104: EndPoint Status Clear n */
	uint8_t volatile EPSTATUSCLRn;
#define USB_EPSTATUSCLRn_BK1RDY			(1u << 7)
#define USB_EPSTATUSCLRn_BK0RDY			(1u << 6)
#define USB_EPSTATUSCLRn_STALLRQ1		(1u << 5)
#define USB_EPSTATUSCLRn_STALLRQ0		(1u << 4)
#define USB_EPSTATUSCLRn_CURBK			(1u << 2)
#define USB_EPSTATUSCLRn_DTGLIN			(1u << 1)
#define USB_EPSTATUSCLRn_DTGLOUT		(1u << 0)

	/* 0x105: EndPoint Status Set n */
	uint8_t volatile EPSTATUSSETn;
#define USB_EPSTATUSSETn_BK1RDY			(1u << 7)
#define USB_EPSTATUSSETn_BK0RDY			(1u << 6)
#define USB_EPSTATUSSETn_STALLRQ1		(1u << 5)
#define USB_EPSTATUSSETn_STALLRQ0		(1u << 4)
#define USB_EPSTATUSSETn_CURBK			(1u << 2)
#define USB_EPSTATUSSETn_DTGLIN			(1u << 1)
#define USB_EPSTATUSSETn_DTGLOUT		(1u << 0)

	/* 0x106: EndPoint Status n */
	uint8_t volatile EPSTATUSn;
#define USB_EPSTATUSn_BK1RDY			(1u << 7)
#define USB_EPSTATUSn_BK0RDY			(1u << 6)
#define USB_EPSTATUSn_STALLRQ			(1u << 4)
#define USB_EPSTATUSn_CURBK			(1u << 2)
#define USB_EPSTATUSn_DTGLIN			(1u << 1)
#define USB_EPSTATUSn_DTGLOUT			(1u << 0)

	/* 0x107: Device EndPoint Interrupt Flag n */
	uint8_t volatile EPINTFLAGn;
#define USB_EPINTFLAGn_STALL			(1u << 5)
#define USB_EPINTFLAGn_RXSTP			(1u << 4)
#define USB_EPINTFLAGn_TRFAIL			(1u << 2)
#define USB_EPINTFLAGn_TRCPT			(1u << 0)

	/* 0x108: Device EndPoint Interrupt Enable n */
	uint8_t volatile EPINTENCLRn;
#define USB_EPINTENCLRn_STALL			(1u << 5)
#define USB_EPINTENCLRn_RXSTP			(1u << 4)
#define USB_EPINTENCLRn_TRFAIL			(1u << 2)
#define USB_EPINTENCLRn_TRCPT			(1u << 0)

	/* 0x109: Device Interrupt EndPoint Set n */
	uint8_t volatile EPINTENSETn;
#define USB_EPINTENSETn_STALL			(1u << 5)
#define USB_EPINTENSETn_RXSTP			(1u << 4)
#define USB_EPINTENSETn_TRFAIL			(1u << 2)
#define USB_EPINTENSETn_TRCPT			(1u << 0)

};

#include <stddef.h>
#include <stdint.h>
#include <binary.h>

struct zmcu_usb {

	/* 0x00: Address of Data Buffer */
	uint32_t volatile ADDR;
#define USB_ADDR_ADDR(x)			((x) << 0)

	/* 0x04: Packet Size */
	uint32_t volatile PCKSIZE;
#define USB_PCKSIZE_AUTO_ZLP			(1u << 31)
#define USB_PCKSIZE_SIZE(x)			((x) << 28)
#define USB_PCKSIZE_MULTI_PACKET_SIZE(x)	((x) << 14)
#define USB_PCKSIZE_BYTE_COUNT(x)		((x) << 0)

	/* 0x08: Extended Register */
	uint16_t volatile EXTREG;
#define USB_EXTREG_VARIABLE(x)			((x) << 4)
#define USB_EXTREG_SUBPID(x)			((x) << 0)

	/* 0x0A: Device Status Bank */
	uint8_t volatile STATUS_BK;
#define USB_STATUS_BK_ERRORFLOW			(1u << 1)
#define USB_STATUS_BK_CRCERR			(1u << 0)

	/* 0x08: Control B */
	uint16_t volatile CTRLB;
#define USB_CTRLB_L1RESUME			(1u << 11)
#define USB_CTRLB_VBUSOK			(1u << 10)
#define USB_CTRLB_BUSRESET			(1u << 9)
#define USB_CTRLB_SOFE				(1u << 8)
#define USB_CTRLB_SPDCONF(x)			((x) << 2)
#define USB_CTRLB_RESUME			(1u << 1)

	/* 0x0A: Host Start-of-Frame Control */
	uint8_t volatile HSOFC;
#define USB_HSOFC_FLENCE			(1u << 7)
#define USB_HSOFC_FLENC(x)			((x) << 0)

	/* 0x0B */
	uint8_t volatile RESERVED0[0x0C-0x0B];

	/* 0x0C: Status */
	uint8_t volatile STATUS;
#define USB_STATUS_LINESTATE(x)			((x) << 6)
#define USB_STATUS_SPEED(x)			((x) << 2)

	/* 0x0D */
	uint8_t volatile RESERVED1[0x10-0x0D];

	/* 0x10: Host Frame Number */
	uint16_t volatile FNUM;
#define USB_FNUM_FNUM(x)			((x) << 3)

	/* 0x12: Host Frame Length */
	uint8_t volatile FLENHIGH;
#define USB_FLENHIGH_FLENHIGH(x)		((x) << 0)

	/* 0x13 */
	uint8_t volatile RESERVED2[0x14-0x13];

	/* 0x14: Host Interrupt Enable Register Clear */
	uint16_t volatile INTENCLR;
#define USB_INTENCLR_DDISC			(1u << 9)
#define USB_INTENCLR_DCONN			(1u << 8)
#define USB_INTENCLR_RAMACER			(1u << 7)
#define USB_INTENCLR_UPRSM			(1u << 6)
#define USB_INTENCLR_DNRSM			(1u << 5)
#define USB_INTENCLR_WAKEUP			(1u << 4)
#define USB_INTENCLR_RST			(1u << 3)
#define USB_INTENCLR_HSOF			(1u << 2)

	/* 0x16 */
	uint8_t volatile RESERVED3[0x18-0x16];

	/* 0x18: Host Interrupt Enable Register Set */
	uint16_t volatile INTENSET;
#define USB_INTENSET_DDISC			(1u << 9)
#define USB_INTENSET_DCONN			(1u << 8)
#define USB_INTENSET_RAMACER			(1u << 7)
#define USB_INTENSET_UPRSM			(1u << 6)
#define USB_INTENSET_DNRSM			(1u << 5)
#define USB_INTENSET_WAKEUP			(1u << 4)
#define USB_INTENSET_RST			(1u << 3)
#define USB_INTENSET_HSOF			(1u << 2)

	/* 0x1A */
	uint8_t volatile RESERVED4[0x1C-0x1A];

	/* 0x1C: Host Interrupt Flag Status and Clear */
	uint16_t volatile INTFLAG;
#define USB_INTFLAG_DDISC			(1u << 9)
#define USB_INTFLAG_DCONN			(1u << 8)
#define USB_INTFLAG_RAMACER			(1u << 7)
#define USB_INTFLAG_UPRSM			(1u << 6)
#define USB_INTFLAG_DNRSM			(1u << 5)
#define USB_INTFLAG_WAKEUP			(1u << 4)
#define USB_INTFLAG_RST				(1u << 3)
#define USB_INTFLAG_HSOF			(1u << 2)

	/* 0x1E */
	uint8_t volatile RESERVED5[0x20-0x1E];

	/* 0x20: Pipe Interrupt Summary */
	uint16_t volatile PINTSMRY;
#define USB_PINTSMRY_PINT(x)			((x) << 0)

	/* 0x22 */
	uint8_t volatile RESERVED6[0x100-0x22];

	/* 0x100: Host Pipe n Configuration */
	uint8_t volatile PCFGn;
#define USB_PCFGn_PTYPE(x)			((x) << 3)
#define USB_PCFGn_BK				(1u << 2)
#define USB_PCFGn_PTOKEN(x)			((x) << 0)

	/* 0x101 */
	uint8_t volatile RESERVED7[0x103-0x101];

	/* 0x103: Interval for the Bulk-Out/Ping Transaction */
	uint8_t volatile BINTERVAL;
#define USB_BINTERVAL_BINTERVAL(x)		((x) << 0)

	/* 0x104: Pipe Status Clear n */
	uint8_t volatile PSTATUSCLR;
#define USB_PSTATUSCLR_BK1RDY			(1u << 7)
#define USB_PSTATUSCLR_BK0RDY			(1u << 6)
#define USB_PSTATUSCLR_PFREEZE			(1u << 4)
#define USB_PSTATUSCLR_CURBK			(1u << 2)
#define USB_PSTATUSCLR_DTGL			(1u << 0)

	/* 0x105: Pipe Status Set Register n */
	uint8_t volatile PSTATUSSET;
#define USB_PSTATUSSET_BK1RDY			(1u << 7)
#define USB_PSTATUSSET_BK0RDY			(1u << 6)
#define USB_PSTATUSSET_PFREEZE			(1u << 4)
#define USB_PSTATUSSET_CURBK			(1u << 2)
#define USB_PSTATUSSET_DTGL			(1u << 0)

	/* 0x106: Pipe Status Register n */
	uint8_t volatile PSTATUS;
#define USB_PSTATUS_BK1RDY			(1u << 7)
#define USB_PSTATUS_BK0RDY			(1u << 6)
#define USB_PSTATUS_PFREEZE			(1u << 4)
#define USB_PSTATUS_CURBK			(1u << 2)
#define USB_PSTATUS_DTGL			(1u << 0)

	/* 0x107: Host Pipe Interrupt Flag Register */
	uint8_t volatile PINTFLAG;
#define USB_PINTFLAG_STALL			(1u << 5)
#define USB_PINTFLAG_TXSTP			(1u << 4)
#define USB_PINTFLAG_PERR			(1u << 3)
#define USB_PINTFLAG_TRFAIL			(1u << 2)
#define USB_PINTFLAG_TRCPT			(1u << 0)

	/* 0x108: Host Pipe Interrupt Clear Register */
	uint8_t volatile PINTENCLR;
#define USB_PINTENCLR_STALL			(1u << 5)
#define USB_PINTENCLR_TXSTP			(1u << 4)
#define USB_PINTENCLR_PERR			(1u << 3)
#define USB_PINTENCLR_TRFAIL			(1u << 2)
#define USB_PINTENCLR_TRCPT			(1u << 0)

	/* 0x109: Host Interrupt Pipe Set Register */
	uint8_t volatile PINTENSET;
#define USB_PINTENSET_STALL			(1u << 5)
#define USB_PINTENSET_TXSTP			(1u << 4)
#define USB_PINTENSET_PERR			(1u << 3)
#define USB_PINTENSET_TRFAIL			(1u << 2)
#define USB_PINTENSET_TRCPT			(1u << 0)

};

#include <stddef.h>
#include <stdint.h>
#include <binary.h>

struct zmcu_usb {

	/* 0x00: Address of the Data Buffer */
	uint32_t volatile ADDR;
#define USB_ADDR_ADDR(x)			((x) << 0)

	/* 0x04: Packet Size */
	uint32_t volatile PCKSIZE;
#define USB_PCKSIZE_AUTO_ZLP			(1u << 31)
#define USB_PCKSIZE_SIZE(x)			((x) << 28)
#define USB_PCKSIZE_MULTI_PACKET_SIZE(x)	((x) << 14)
#define USB_PCKSIZE_BYTE_COUNT(x)		((x) << 8)

	/* 0x08: Extended Register */
	uint16_t volatile EXTREG;
#define USB_EXTREG_VARIABLE(x)			((x) << 4)
#define USB_EXTREG_SUBPID(x)			((x) << 0)

	/* 0x0A: Host Status Bank */
	uint8_t volatile STATUS_BK;
#define USB_STATUS_BK_ERRORFLOW			(1u << 1)
#define USB_STATUS_BK_CRCERR			(1u << 0)

	/* 0x0B */
	uint8_t volatile RESERVED0[0x0C-0x0B];

	/* 0x0C: Host Control Pipe */
	uint16_t volatile CTRL_PIPE;
#define USB_CTRL_PIPE_PERMAX(x)			((x) << 12)
#define USB_CTRL_PIPE_PEPNUM(x)			((x) << 8)
#define USB_CTRL_PIPE_PDADDR(x)			((x) << 0)

	/* 0x0E: Host Status Pipe */
	uint16_t volatile STATUS_PIPE;
#define USB_STATUS_PIPE_ERCNT(x)		((x) << 5)
#define USB_STATUS_PIPE_CRC16ER			(1u << 4)
#define USB_STATUS_PIPE_TOUTER			(1u << 3)
#define USB_STATUS_PIPE_PIDER			(1u << 2)
#define USB_STATUS_PIPE_DAPIDER			(1u << 1)
#define USB_STATUS_PIPE_DTGLER			(1u << 0)

};

