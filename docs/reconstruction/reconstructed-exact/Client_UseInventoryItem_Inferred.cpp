// =============================================================================
// Client_UseInventoryItem_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00941d50
// Address:   0x00941d50  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / skills-abilities
// Generated: 2026-07-29 dual A/B seal (from raw 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Activate an inventory item from client UI / quickbar / COID helper.
//   Convention: client in ESI, item* in EDI, stack mode param_1 (callers pass 1).
//
//   Arm A — cloneMeta+0x3f2 bit 0x80 CLEAR:
//     FUN_00941b20(item, mode, 1)  // equip / permanent-customize confirm (no 0x2045)
//
//   Arm B — bit 0x80 SET (skill-bearing usable):
//     req check → resolve item skill → LocalCastValidate → ResolveCastTarget
//     → C2S InventoryUseItem opcode 0x2045 size 0x28
//
// SEALED PACKET (Arm B) — dual A/B 2026-07-29
//   +0x00 u32  opcode           = 0x2045
//   +0x04 u32  pad              (unwritten)
//   +0x08 u64  coidItem         = item+0x160 / +0x164
//   +0x10 TFID fidTarget        = ResolveCastTarget out (16B)
//   +0x20 u8   ucSkillNumber    = 0  (constant in this builder)
//   +0x21..27  pad to 0x28
//
// CALLERS
//   Client_QuickBar_ActivateSlot (type-2 cargo) @ 0x009436c0
//   FUN_00941f50 (COID resolve then use)         @ 0x00941f50
//   FUN_008be900 (UI event 0xe)                  @ 0x008be900
//
// CALLEES (skill-use arm)
//   FUN_00514390                 item use/equip requirements (thiscall item)
//   item vtbl +0x234             skill lookup from cloneMeta+0x3bc
//   Skill_LocalCastValidate      0x0051a790
//   Client_Skill_ResolveCastTarget 0x0093b3a0
//   TFID_EqualsObjectId          vs g_abTfidInvalid_A15870
//   Client_SendSectorPacket
// =============================================================================

#include <cstdint>

extern "C" {
std::uint32_t FUN_00941b20(int* item, std::uint32_t mode, char confirmFlag);
char          FUN_00514390(/*thiscall item*/ int* item, void* character, int flag);
int           Skill_LocalCastValidate(void* entity, void* a, void* pSkill, void* b);
void*         Client_Skill_ResolveCastTarget(void* outTfid, void* pSkill, void* seedTfid,
                                             void* pAimOrCtx, int bReportFailure);
int           TFID_EqualsObjectId(void* a, void* b);
void          Client_SendSectorPacket(void* client, int size, void* buf);

extern std::uint8_t g_abTfidInvalid_A15870[]; // 0x00a15870: ff..ff ff..ff 00.. 00..
extern std::uint8_t DAT_00d1a630[];           // zero aim/context placeholder
}

// Returns 1 if equip arm succeeded or 0x2045 was sent; else 0.
std::uint32_t Client_UseInventoryItem_Inferred(std::uint32_t mode)
{
    // unaff_ESI = client, unaff_EDI = item*  (register convention)
    void* client = nullptr; // ESI
    int*  item   = nullptr; // EDI

    int character = *(int*)((int)client + 0xe98);
    if (character == 0 || *(int*)(character + 0x250) == 0 || item == nullptr) {
        return 0;
    }
    // item+0x17c bit 19 = Broken (sealed elsewhere)
    if ((((std::uint32_t)item[0x5f] >> 0x13) & 1) != 0) {
        return 0;
    }
    // item[0x2a] = item+0xa8 type meta; +0x38 type code; +0x3c clonebase*
    int* typeMeta = (int*)item[0x2a];
    if (*(int*)((int)typeMeta + 0x38) == 0xe) {
        return 0;
    }

    // Seed scratch used as ResolveCastTarget formal homes (decomp residual on which
    // buffer is seed vs out — out TFID consumed into packet is sealed).
    std::uint32_t seedOrOut[4];
    seedOrOut[0] = *(std::uint32_t*)(*(int*)(*(int*)(character + 4) + 4) + character + 0x170);

    int cloneMeta = *(int*)((int)typeMeta + 0x3c);
    if ((*(std::uint8_t*)(cloneMeta + 0x3f2) & 0x80) == 0) {
        // Arm A: equip / confirm customize — NOT opcode 0x2045
        return FUN_00941b20(item, mode, 1);
    }

    // Arm B: skill-use → 0x2045
    if (*(char*)(*(int*)((int)client + 0xe04) + 0xf6) != 0) {
        return 0;
    }
    if (FUN_00514390(item, (void*)character, 1) == 0) {
        return 0;
    }

    character = *(int*)((int)client + 0xe98);
    int selection = *(int*)(*(int*)(*(int*)(character + 4) + 4) + 0xa4 + character);
    if (selection != 0) {
        seedOrOut[0] = *(std::uint32_t*)(selection + 0x16c);
    }

    // pSkill = item->vtbl[+0x234](*(cloneMeta + 0x3bc))
    int pSkill = (**(int(***)(int))(*item + 0x234))(*(int*)(cloneMeta + 0x3bc));
    if (pSkill == 0) {
        return 0;
    }

    void* entity = (void*)(*(int*)(*(int*)(character + 4) + 4) + 4 + character);
    int validate = Skill_LocalCastValidate(entity, (void*)0x1, (void*)pSkill, (void*)0x0);
    if (validate != 0) {
        return 0;
    }

    std::uint8_t seedScratch[16];
    std::uint32_t* resolved = (std::uint32_t*)Client_Skill_ResolveCastTarget(
        seedOrOut, (void*)pSkill, seedScratch, &DAT_00d1a630, 1);

    std::uint32_t t0 = resolved[0];
    std::uint32_t t1 = resolved[1];
    std::uint32_t t2 = resolved[2];
    std::uint32_t t3 = resolved[3];

    // Decomp checks stack seed/out home vs invalid; intent: abort if target invalid.
    if ((char)TFID_EqualsObjectId(seedScratch, g_abTfidInvalid_A15870) != 0) {
        return 0;
    }

    // Contiguous 0x28-byte send buffer
    std::uint32_t packet[10]; // 40 bytes
    packet[0] = 0x2045;                 // +0x00 opcode
    // packet[1] pad +0x04 unwritten
    packet[2] = (std::uint32_t)item[0x58]; // +0x08 coid lo  (item+0x160)
    packet[3] = (std::uint32_t)item[0x59]; // +0x0c coid hi  (item+0x164)
    packet[4] = t0;                       // +0x10 fidTarget
    packet[5] = t1;
    packet[6] = t2;
    packet[7] = t3;
    // +0x20 ucSkillNumber = 0 (low byte); remainder pad
    packet[8] = 0;

    Client_SendSectorPacket(client, 0x28, packet);
    return 1;
}
