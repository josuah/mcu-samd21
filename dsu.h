#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define DSU ((struct zmcu_dsu *)0x41002000)
#define DSU ((struct zmcu_dsu *)0x41002000)

struct zmcu_dsu {

	/* 0x00: Control */
	uint8_t volatile CTRL;
#define DSU_CTRL_CE				(1u << 4)
#define DSU_CTRL_MBIST				(1u << 3)
#define DSU_CTRL_CRC				(1u << 2)
#define DSU_CTRL_SWRST				(1u << 0)

	/* 0x01: Status A */
	uint8_t volatile STATUSA;
#define DSU_STATUSA_PERR			(1u << 4)
#define DSU_STATUSA_FAIL			(1u << 3)
#define DSU_STATUSA_BERR			(1u << 2)
#define DSU_STATUSA_CRSTEXT			(1u << 1)
#define DSU_STATUSA_DONE			(1u << 0)

	/* 0x02: Status B */
	uint8_t volatile STATUSB;
#define DSU_STATUSB_HPE				(1u << 4)
#define DSU_STATUSB_DBGPRES			(1u << 1)
#define DSU_STATUSB_PROT			(1u << 0)

	/* 0x03 */
	uint8_t volatile RESERVED0[0x04-0x03];

	/* 0x04: Address */
	uint32_t volatile ADDR;
#define DSU_ADDR_ADDR(x)			((x) << 2)
#define DSU_ADDR_AMOD(x)			((x) << 0)

	/* 0x08: Length */
	uint32_t volatile LENGTH;
#define DSU_LENGTH_LENGTH(x)			((x) << 2)

	/* 0x0C: Data */
	uint32_t volatile DATA;
#define DSU_DATA_DATA(x)			((x) << 0)

	/* 0x10: Debug Communication Channel 0 */
	uint32_t volatile DCC0;
#define DSU_DCC0_DATA(x)			((x) << 0)

	/* 0x14: Debug Communication Channel 1 */
	uint32_t volatile DCC1;
#define DSU_DCC1_DATA(x)			((x) << 0)

	/* 0x18: Device Identification */
	uint32_t volatile DID;
#define DSU_DID_PROCESSOR(x)			((x) << 28)
#define DSU_DID_FAMILY(x)			((x) << 23)
#define DSU_DID_SERIES(x)			((x) << 16)
#define DSU_DID_DIE(x)				((x) << 12)
#define DSU_DID_REVISION(x)			((x) << 8)
#define DSU_DID_DEVSEL(x)			((x) << 0)

	/* 0x1C */
	uint8_t volatile RESERVED1[0x1000-0x1C];

	/* 0x1000: CoreSight ROM Table Entry 0 */
	uint32_t volatile ENTRY0;
#define DSU_ENTRY0_ADDOFF(x)			((x) << 12)
#define DSU_ENTRY0_FMT				(1u << 1)
#define DSU_ENTRY0_EPRES			(1u << 0)

	/* 0x1004: CoreSight ROM Table Entry 1 */
	uint32_t volatile ENTRY1;
#define DSU_ENTRY1_ADDOFF(x)			((x) << 12)
#define DSU_ENTRY1_FMT				(1u << 1)
#define DSU_ENTRY1_EPRES			(1u << 0)

	/* 0x1008: CoreSight ROM Table End */
	uint32_t volatile END;
#define DSU_END_END(x)				((x) << 0)

	/* 0x100C */
	uint8_t volatile RESERVED2[0x1FCC-0x100C];

	/* 0x1FCC: CoreSight ROM Table Memory Type */
	uint32_t volatile MEMTYPE;
#define DSU_MEMTYPE_SMEMP			(1u << 0)

	/* 0x1FD0: Peripheral Identification 4 */
	uint32_t volatile PID4;
#define DSU_PID4_FKBC(x)			((x) << 4)
#define DSU_PID4_JEPCC(x)			((x) << 0)

	/* 0x1FD4 */
	uint8_t volatile RESERVED3[0x1FE0-0x1FD4];

	/* 0x1FE0: Peripheral Identification 0 */
	uint32_t volatile PID0;
#define DSU_PID0_PARTNBL(x)			((x) << 0)

	/* 0x1FE4: Peripheral Identification 1 */
	uint32_t volatile PID1;
#define DSU_PID1_JEPIDCL(x)			((x) << 4)
#define DSU_PID1_PARTNBH(x)			((x) << 0)

	/* 0x1FE8: Peripheral Identification 2 */
	uint32_t volatile PID2;
#define DSU_PID2_REVISION(x)			((x) << 4)
#define DSU_PID2_JEPU				(1u << 3)
#define DSU_PID2_JEPIDCH(x)			((x) << 0)

	/* 0x1FEC: Peripheral Identification 3 */
	uint32_t volatile PID3;
#define DSU_PID3_REVAND(x)			((x) << 4)
#define DSU_PID3_CUSMOD(x)			((x) << 0)

	/* 0x1FF0: Component Identification 0 */
	uint32_t volatile CID0;
#define DSU_CID0_PREAMBLEB0(x)			((x) << 0)

	/* 0x1FF4: Component Identification 1 */
	uint32_t volatile CID1;
#define DSU_CID1_CCLASS(x)			((x) << 4)
#define DSU_CID1_PREAMBLE(x)			((x) << 0)

	/* 0x1FF8: Component Identification 2 */
	uint32_t volatile CID2;
#define DSU_CID2_PREAMBLEB2(x)			((x) << 0)

	/* 0x1FFC: Component Identification 3 */
	uint32_t volatile CID3;
#define DSU_CID3_PREAMBLEB3(x)			((x) << 0)

};

