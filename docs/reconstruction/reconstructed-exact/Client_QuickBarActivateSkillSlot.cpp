// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×13, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, Client_QuickBarActivateSkillSlot, Client_Skill_ResolveCastTarget, FUN_00411900, FUN_0089ff80, Skill_ClearActiveCastCounterAndQueueId, XYZ, send.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Client_QuickBarActivateSkillSlot
// -----------------------------------------------------------------------------
// Purpose:  Activate by visible skill-list index nSlotIndex (not persisted QB
//           skill-id slot). Walks entity+0x74 list (skip skill+0x615 bit0),
//           LocalCastValidates, optional cast-again HB, builds C2S 0x2030
//           size 0x28, sends on sector net connection vtable+0x18.
//
// Address:  0x00921b50  (autoassault.exe, image base 0x400000)
// Stable:   aa_00921b50
// System:   skills-abilities
//
// Callers (observed): Client_QuickBar_ActivateSlot on-foot slots 0/1;
//   Client_Input_DriveControlTick paths — both pass literal 0 or 1.
//   Standard QB type-1 uses CastSkillFromQuickBarSlot(skillId) instead.
//
// Packet at send (conn vtable+0x18):
//   +0=0x2030; +4 pad; +8 TFID16 from Client_Skill_ResolveCastTarget;
//   +0x18=skill+0x5fc; +0x1C aim XYZ (stack residual — not sealed).
// Note: LEA buf after PUSH size/flag → recompute ESP; opcode store is 8B
//       before resolve[0].
//
// Control flow summary:
//   1) Resolve local player/character; seed pos TFID (self or selection +0xa4)
//   2) Walk skill list @ entity+0x74 under traversal lock; skip bit0@+0x615
//      until visible-slot counter == nSlotIndex
//   3) Skill_LocalCastValidate == 0 (OK):
//        optional Skill_StartCastAgainHeartbeat (world+0x7e / skill+0x61c gates)
//        optional charge FX when skill+0x14 != 0
//        pack 0x2030 (skill id + resolved TFID + aim) → sector net vtbl+0x18
//        optional QB visible refresh FUN_0089ff80
//
// Key offsets:
//   skill+0x5fc  skill queue / cast id (packet +0x18)
//   skill+0x615  skip-count bit0; skill+0x61c blocks optimistic HB
//   skill+0x14   charge delay short
//
// Related: Client_RequestCastSkill (parallel packer — different send/fail UX)
// Exactness: Behavior-preserving decompiler CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime / differential: OPEN.
// Dual reviews (2026-07-29 residual):
//   reviews/A_aa_00921b50_Client_QuickBarActivateSkillSlot.md
//   reviews/B_aa_00921b50_Client_QuickBarActivateSkillSlot.md
// =============================================================================

#include <cstdint>

extern "C" void  FUN_007a4480(int, const char*); // hash-traversal assert log
extern "C" void* FUN_00411900(int* nodeOut);     // first skill node payload
extern "C" int   Skill_LocalCastValidate(void*, void*, void*, void*);
extern "C" void  Skill_ClearActiveCastCounterAndQueueId(int);
extern "C" void  Skill_StartCastAgainHeartbeat(void*, void*, void*, int);
extern "C" void* Client_Skill_ResolveCastTarget(void*, void*, void*, void*, int);
extern "C" void  FUN_0089ff80();
extern "C" int   DAT_00d1b6d8;
extern "C" void* g_pSectorNetConnection_INFERRED;
extern "C" int*  DAT_00d1b8f0;
extern "C" std::uint8_t DAT_00d1a640[]; // default aim / zero vec region

void Client_QuickBarActivateSkillSlot(char nSlotIndex)
{
    int* playerObj;
    int iVar;
    char qbVis;
    int character;
    void* pSkillRuntime;
    int skillIdOrNode;
    std::uint32_t* resolved;
    int hbExtra; // unaff_EDI

    int slotCounter = 0;
    int traverseNode = 0;

    // Position seed (self TFID region / override from +0xa4)
    std::uint32_t pos0, pos1, pos2, pos3;
    std::uint32_t aim0 = 0, aim1 = 0, aim2 = 0; // often zeroed for QB

    std::uint8_t resolveScratch[16];
    std::uint32_t packet[10]; // 0x28-byte 0x2030 buffer (auStack_38 region)

    // playerObj = *( *(DAT_00d1b6d8 link) + 0xa4 )
    playerObj =
        *(int**)(*(int*)(*(int*)(DAT_00d1b6d8 + 4) + 4) + 0xa4 + DAT_00d1b6d8);

    if (playerObj == nullptr) {
        return;
    }

    character = (**(int(***)())(*playerObj + 0x1d8))();
    if (character == 0) {
        return;
    }

    // Entity-relative base for character
    int charEntity = *(int*)(*(int*)(character + 4) + 4) + character;

    pos0 = *(std::uint32_t*)(charEntity + 0x164);
    pos1 = *(std::uint32_t*)(charEntity + 0x168);
    pos2 = *(std::uint32_t*)(charEntity + 0x16c);
    pos3 = *(std::uint32_t*)(charEntity + 0x170);

    iVar = *(int*)(charEntity + 0xa4);
    if (iVar != 0) {
        pos0 = *(std::uint32_t*)(iVar + 0x160);
        pos1 = *(std::uint32_t*)(iVar + 0x164);
        pos2 = *(std::uint32_t*)(iVar + 0x168);
        pos3 = *(std::uint32_t*)(iVar + 0x16c);
    }

    // Skill list head at entity+0x74
    skillIdOrNode = *(int*)(charEntity + 0x74);
    slotCounter = 0;
    traverseNode = 0;

    // Traversal lock
    if (*(char*)(skillIdOrNode + 0x1d) != '\0') {
        FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    *(std::uint8_t*)(skillIdOrNode + 0x1d) = 1;

    pSkillRuntime = FUN_00411900(&traverseNode);
    skillIdOrNode = traverseNode;

    while (pSkillRuntime != nullptr) {
        // Skip skills with hidden/passive bit0 at +0x615
        if ((*(std::uint8_t*)((int)pSkillRuntime + 0x615) & 1) == 0) {
            if (slotCounter == nSlotIndex) {
                break;
            }
            slotCounter = slotCounter + 1;
        }

        // Advance linked list under lock
        iVar = *(int*)(*(int*)(*(int*)(character + 4) + 4) + 0x74 + character);
        if (*(char*)(iVar + 0x1d) == '\0') {
            FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }

        if (skillIdOrNode == 0) {
            skillIdOrNode = *(int*)(iVar + 0x14);
        } else {
            skillIdOrNode = *(int*)(skillIdOrNode + 0x14);
        }

        if (skillIdOrNode == 0) {
            pSkillRuntime = nullptr;
        } else {
            pSkillRuntime = *(void**)(skillIdOrNode + 8);
        }
    }

    // Unlock
    *(std::uint8_t*)(
        *(int*)(*(int*)(*(int*)(character + 4) + 4) + 0x74 + character) + 0x1d) = 0;

    if ((pSkillRuntime != nullptr)
        && (skillIdOrNode = Skill_LocalCastValidate(
                                (void*)(*(int*)(*(int*)(character + 4) + 4) + 4 + character),
                                nullptr,
                                pSkillRuntime,
                                nullptr),
            skillIdOrNode == 0))
    {
        int skillId = *(int*)((int)pSkillRuntime + 0x5fc);

        // Optimistic cast-again HB when world+0x7e == 0 && skill+0x61c == 0
        if ((*(char*)(*(int*)(*(int*)(*(int*)(character + 4) + 4) + 0xa8 + character) + 0x7e)
             == '\0')
            && (Skill_ClearActiveCastCounterAndQueueId(skillId),
                *(char*)((int)pSkillRuntime + 0x61c) == '\0'))
        {
            Skill_StartCastAgainHeartbeat(
                (void*)(*(int*)(*(int*)(character + 4) + 4) + 4 + character),
                pSkillRuntime,
                (void*)(int)*(std::int16_t*)((int)pSkillRuntime + 0x14),
                hbExtra);
        }

        // Charge FX when charge delay != 0
        if (*(std::int16_t*)((int)pSkillRuntime + 0x14) != 0) {
            (**(void(***)(int, int, int, int, int, int, int, int))(
                *(int*)(*(int*)(*(int*)(character + 4) + 4) + 4 + character) + 0x238))(
                3,
                skillId,
                (int)(std::int16_t)(
                    *(std::int16_t*)((int)pSkillRuntime + 0x5f6)
                    + *(std::int16_t*)((int)pSkillRuntime + 0x174)),
                (int)*(std::int16_t*)((int)pSkillRuntime + 0x14),
                0, 0, 0, 0);
        }

        // Build 0x2030
        aim2 = 0;
        aim1 = 0;
        aim0 = 0;
        packet[0] = 0x2030;
        // skill id at +0x18
        int* pktSkillId = (int*)((std::uint8_t*)packet + 0x18);
        *pktSkillId = skillId;

        resolved = (std::uint32_t*)Client_Skill_ResolveCastTarget(
            resolveScratch, pSkillRuntime, &pos0, &DAT_00d1a640, 1);

        // TFID at +8
        packet[2] = resolved[0];
        packet[3] = resolved[1];
        packet[4] = resolved[2];
        packet[5] = resolved[3];

        // Aim at +0x1c (decomp copies from uStack_60 region - often 0)
        packet[7] = aim0;
        packet[8] = aim1;
        packet[9] = aim2;

        if (g_pSectorNetConnection_INFERRED != nullptr) {
            (**(void(***)(int, void*, int, int))(
                *(int*)g_pSectorNetConnection_INFERRED + 0x18))(
                (int)0xffffffff, packet, 0x28, 0);
        }

        if ((DAT_00d1b8f0 != nullptr)
            && (qbVis = (**(char(***)())(*DAT_00d1b8f0 + 0x3d8))(), qbVis != '\0'))
        {
            FUN_0089ff80();
        }
    }
}
