#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define DMAC ((struct zmcu_dmac *)0x41004800)
#define DMAC ((struct zmcu_dmac *)0x41004800)

struct zmcu_dmac {

	/* 0x00: Control */
	uint16_t volatile CTRL;
#define DMAC_CTRL_CRCENABLE			(1u << 2)
#define DMAC_CTRL_DMAENABLE			(1u << 1)
#define DMAC_CTRL_SWRST				(1u << 0)

	/* 0x02: CRC Control */
	uint16_t volatile CRCCTRL;
#define DMAC_CRCCTRL_CRCSRC(x)			((x) << 8)
#define DMAC_CRCCTRL_CRCPOLY(x)			((x) << 2)
#define DMAC_CRCCTRL_CRCBEATSIZE(x)		((x) << 0)

	/* 0x04: CRC Data Input */
	uint32_t volatile CRCDATAIN;
#define DMAC_CRCDATAIN_CRCDATAIN(x)		((x) << 0)

	/* 0x08: CRC Checksum */
	uint32_t volatile CRCCHKSUM;
#define DMAC_CRCCHKSUM_CRCCHKSUM(x)		((x) << 0)

	/* 0x0C: CRC Status */
	uint8_t volatile CRCSTATUS;
#define DMAC_CRCSTATUS_CRCZERO			(1u << 1)
#define DMAC_CRCSTATUS_CRCBUSY			(1u << 0)

	/* 0x0D: Debug Control */
	uint8_t volatile DBGCTRL;
#define DMAC_DBGCTRL_DBGRUN			(1u << 0)

	/* 0x0E: Quality of Service Control */
	uint8_t volatile QOSCTRL;
#define DMAC_QOSCTRL_DQOS(x)			((x) << 4)
#define DMAC_QOSCTRL_FQOS(x)			((x) << 2)
#define DMAC_QOSCTRL_WRBQOS(x)			((x) << 0)

	/* 0x0F */
	uint8_t volatile RESERVED0[0x10-0x0F];

	/* 0x10: Software Trigger Control */
	uint32_t volatile SWTRIGCTRL;
#define DMAC_SWTRIGCTRL_SWTRIGn(x)		((x) << 0)

	/* 0x14: Priority Control 0 */
	uint32_t volatile PRICTRL0;
#define DMAC_PRICTRL0_RRLVLEN3			(1u << 31)
#define DMAC_PRICTRL0_LVLPRI3(x)		((x) << 24)
#define DMAC_PRICTRL0_RRLVLEN2			(1u << 23)
#define DMAC_PRICTRL0_LVLPRI2(x)		((x) << 16)
#define DMAC_PRICTRL0_RRLVLEN1			(1u << 15)
#define DMAC_PRICTRL0_LVLPRI1(x)		((x) << 8)
#define DMAC_PRICTRL0_RRLVLEN0			(1u << 7)
#define DMAC_PRICTRL0_LVLPRI0(x)		((x) << 0)

	/* 0x18 */
	uint8_t volatile RESERVED1[0x20-0x18];

	/* 0x20: Interrupt Pending */
	uint16_t volatile INTPEND;
#define DMAC_INTPEND_PEND			(1u << 15)
#define DMAC_INTPEND_BUSY			(1u << 14)
#define DMAC_INTPEND_FERR			(1u << 13)
#define DMAC_INTPEND_SUSP			(1u << 10)
#define DMAC_INTPEND_TCMPL			(1u << 9)
#define DMAC_INTPEND_TERR			(1u << 8)
#define DMAC_INTPEND_ID(x)			((x) << 0)

	/* 0x22 */
	uint8_t volatile RESERVED2[0x24-0x22];

	/* 0x24: Interrupt Status */
	uint32_t volatile INTSTATUS;
#define DMAC_INTSTATUS_CHINTn(x)		((x) << 0)

	/* 0x28: Busy Channels */
	uint32_t volatile BUSYCH;
#define DMAC_BUSYCH_BUSYCHn(x)			((x) << 0)

	/* 0x2C: Pending Channels */
	uint32_t volatile PENDCH;

	/* 0x30: Active Channel and Levels */
	uint32_t volatile ACTIVE;
#define DMAC_ACTIVE_BTCNT(x)			((x) << 16)
#define DMAC_ACTIVE_ABUSY			(1u << 15)
#define DMAC_ACTIVE_ID(x)			((x) << 8)
#define DMAC_ACTIVE_LVLEXx			(1u << 3,2,1,0)

	/* 0x34: Descriptor Memory Section Base Address */
	uint32_t volatile BASEADDR;

	/* 0x38: Write-Back Memory Section Base Address */
	uint32_t volatile WRBADDR;

	/* 0x3C */
	uint8_t volatile RESERVED3[0x3F-0x3C];

	/* 0x3F: Channel ID */
	uint8_t volatile CHID;
#define DMAC_CHID_ID(x)				((x) << 0)

	/* 0x40: Channel Control A */
	uint8_t volatile CHCTRLA;
#define DMAC_CHCTRLA_ENABLE			(1u << 1)
#define DMAC_CHCTRLA_SWRST			(1u << 0)

	/* 0x41 */
	uint8_t volatile RESERVED4[0x44-0x41];

	/* 0x44: Channel Control B */
	uint32_t volatile CHCTRLB;
#define DMAC_CHCTRLB_CMD(x)			((x) << 24)
#define DMAC_CHCTRLB_TRIGACT(x)			((x) << 22)
#define DMAC_CHCTRLB_TRIGSRC(x)			((x) << 8)
#define DMAC_CHCTRLB_LVL(x)			((x) << 5)
#define DMAC_CHCTRLB_EVOE			(1u << 4)
#define DMAC_CHCTRLB_EVIE			(1u << 3)
#define DMAC_CHCTRLB_EVACT(x)			((x) << 0)

	/* 0x48 */
	uint8_t volatile RESERVED5[0x4C-0x48];

	/* 0x4C: Channel Interrupt Enable Clear */
	uint8_t volatile CHINTENCLR;
#define DMAC_CHINTENCLR_SUSP			(1u << 2)
#define DMAC_CHINTENCLR_TCMPL			(1u << 1)
#define DMAC_CHINTENCLR_TERR			(1u << 0)

	/* 0x4D: Channel Interrupt Enable Set */
	uint8_t volatile CHINTENSET;
#define DMAC_CHINTENSET_SUSP			(1u << 2)
#define DMAC_CHINTENSET_TCMPL			(1u << 1)
#define DMAC_CHINTENSET_TERR			(1u << 0)

	/* 0x4E: Channel Interrupt Flag Status and Clear */
	uint8_t volatile CHINTFLAG;
#define DMAC_CHINTFLAG_SUSP			(1u << 2)
#define DMAC_CHINTFLAG_TCMPL			(1u << 1)
#define DMAC_CHINTFLAG_TERR			(1u << 0)

	/* 0x4F: Channel Status */
	uint8_t volatile CHSTATUS;
#define DMAC_CHSTATUS_FERR			(1u << 2)
#define DMAC_CHSTATUS_BUSY			(1u << 1)
#define DMAC_CHSTATUS_PEND			(1u << 0)

};

#include <stddef.h>
#include <stdint.h>
#include <binary.h>

struct zmcu_dmac {

	/* 0x00: Block Transfer Control */
	uint16_t volatile BTCTRL;
#define DMAC_BTCTRL_STEPSIZE(x)			((x) << 13)
#define DMAC_BTCTRL_STEPSEL			(1u << 12)
#define DMAC_BTCTRL_DSTINC			(1u << 11)
#define DMAC_BTCTRL_SRCINC			(1u << 10)
#define DMAC_BTCTRL_BEATSIZE(x)			((x) << 8)
#define DMAC_BTCTRL_BLOCKACT(x)			((x) << 3)
#define DMAC_BTCTRL_EVOSEL(x)			((x) << 1)
#define DMAC_BTCTRL_VALID			(1u << 0)

	/* 0x02: Block Transfer Count */
	uint16_t volatile BTCNT;
#define DMAC_BTCNT_BTCNT(x)			((x) << 0)

	/* 0x04: Block Transfer Source Address */
	uint32_t volatile SRCADDR;
#define DMAC_SRCADDR_SRCADDR(x)			((x) << 0)

	/* 0x08: Block Transfer Destination Address */
	uint32_t volatile DSTADDR;
#define DMAC_DSTADDR_DSTADDR(x)			((x) << 0)

	/* 0x0C: Next Descriptor Address */
	uint32_t volatile DESCADDR;
#define DMAC_DESCADDR_DESCADDR(x)		((x) << 0)

};

