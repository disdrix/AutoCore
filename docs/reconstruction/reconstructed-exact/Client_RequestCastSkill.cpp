// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: TFID_EqualsObjectId×3, Skill_LookupActiveCastBinding×2, Client_MaybeShowFirstTimeTip, Client_RequestCastSkill, Client_SendSectorPacket, Client_Skill_ResolveCastTarget, Confirmed, FUN_007fb690.
//  - Strings: "...Activating Skill...".
//  - Return sites: 2.

// =============================================================================
// Client_RequestCastSkill
// -----------------------------------------------------------------------------
// Purpose:  Player cast intent → C2S RequestCastSkill 0x2030 size 0x28
//           (WI-SKL-001 Confirmed). Validates skill, resolves target TFID,
//           optionally starts optimistic cast-again heartbeat, packs and sends
//           the sector packet, then notifies quick-bar UI / first-time tip.
//
// Address:  0x00941590  (autoassault.exe, image base 0x400000)
// Stable:   aa_00941590
// System:   skills-abilities
//
// Convention: Retail binds client in EAX (decomp in_EAX). Clean form takes
//             client as an explicit first argument for readability; CF of the
//             body is otherwise unchanged.
//
// Packet layout (0x28 send buffer) — WI-SKL-001 Confirmed (asm residual 2026-07-29):
//   +0x00 msgId 0x2030 · +0x04 pad · +0x08 target TFID 16B
//   +0x18 skillId = formal nSkillId (arg0 home; decomp surface omitted this store)
//   +0x1C aim float3 (from pAimPos; body holds pointer in EBP)
//
// Control flow summary:
//   1) Guard client+0xe98 non-null
//   2) entity = dual-base from +0xe98; pSkill = vtbl+0x234(nSkillId)
//      null skill or rank short skill+0x5f6 == 0 → return
//   3) validateCode = Skill_LocalCastValidate(entity, 0, pSkill, 0)
//   4) if validateCode == 0 (OK):
//        resolve TFID via Client_Skill_ResolveCastTarget(scratch, skill, &tfid0, aim, 1)
//        if TFID not invalid:
//          if world+0x7e==0 && active binding invalid && skill+0x61c==0:
//            Skill_StartCastAgainHeartbeat thiscall(entity, skill, chargeMs)
//          if skill+0x14 > 0: charge FX vtbl+0x238(3, nSkillId, rank, 0,…)
//          pack 0x2030 (TFID + nSkillId + aim) → Client_SendSectorPacket(client, 0x28, pkt)
//          optional QB UI vtbl+0x450; tip 0x23 when cost fields set
//   5) else: Skill_FormatFailureMessage → chat UI if DAT_00d1b8dc
//
// Key offsets:
//   client+0xe98  local character root
//   client+0xe04  world/sim object (gate +0x7e for optimistic HB)
//   client+0x10b0 quick-bar UI controller
//   skill+0x5f6   rank short (must be non-zero)
//   skill+0x5fc   skill queue / cast id (QB path writes this at packet +0x18)
//   skill+0x61c   flag blocking optimistic cast-again HB
//   skill+0x14    charge / cast-time short (ms-scale for UI / HB)
//
// Callees (addresses known from siblings / headers):
//   Client_SendSectorPacket           (sector net send)
//   Client_Skill_ResolveCastTarget    target TFID resolve (seed TFID in; scratch out)
//   Skill_LocalCastValidate           local cast gates
//   Skill_StartCastAgainHeartbeat     optimistic cast-again HB (thiscall 3-arg)
//   Client_MaybeShowFirstTimeTip      tip id 0x23
// Related callers:
//   Client_CastSkillFromQuickBarSlot  0x009418e0
//   FUN_00941ac0                      0x00941ac0
// Sibling packer (does not call this unit):
//   Client_QuickBarActivateSkillSlot  0x00921b50
//
// Exactness: Behavior-preserving decompiler CF + asm residual seals. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime / differential: OPEN.
// Dual residual: reviews/a_00941590.md
// Dual reviews:
//   reviews/A_aa_00941590_Client_RequestCastSkill.md
//   reviews/B_aa_00941590_Client_RequestCastSkill.md
// =============================================================================

#include <cstdint>

extern "C" int   Skill_LocalCastValidate(void*, void*, void*, void*);
extern "C" void* Client_Skill_ResolveCastTarget(void* outTfid, void* pSkill, void* seedTfid, void* pAim, int bReport);
extern "C" int   TFID_EqualsObjectId(void*, void*);
extern "C" void  Skill_LookupActiveCastBinding(void*, int);
extern "C" void  Skill_ClearActiveCastCounterAndQueueId(int);
extern "C" void  Skill_StartCastAgainHeartbeat(void* entity, void* pSkill, int nChargeDelayMs);
extern "C" void  Client_SendSectorPacket(void*, int, void*);
extern "C" char* Skill_FormatFailureMessage(int, char*, void*);
extern "C" void  Client_MaybeShowFirstTimeTip(int);
extern "C" void  FUN_007fb690(int, float, int, const char*, int, int, int, int);
extern "C" void  FUN_008f8200(int, int, void*, char*, int);
extern "C" std::uint8_t g_abTfidInvalid_A15870[];
extern "C" float g_flMsToSeconds_Inferred;
extern "C" float g_flZero;
extern "C" int   DAT_00d1b8dc;
extern "C" int   DAT_00afdf08;
extern "C" char  DAT_00a156cc;

// Entity from client root +0xe98: *( *( *(root+4)+4 ) + root + 4 )
static void* ClientEntity(void* client)
{
    int root = *(int*)((int)client + 0xe98);
    return (void*)(*(int*)(*(int*)(root + 4) + 4) + 4 + root);
}

/// @param client   Client object (retail: EAX at entry → EDI).
/// @param nSkillId Skill id (arg0; packed at packet +0x18; not clobbered by resolve).
/// @param tfid0..3 Seed TFID for ResolveCastTarget (arg1..4); results held for pack.
/// @param pAimPos  Aim / target position float3.
void Client_RequestCastSkill(
    void* client,
    int nSkillId,
    int tfid0,
    int tfid1,
    int tfid2,
    int tfid3,
    void* pAimPos)
{
    char qbVisible;
    void* pSkill;
    int validateCode;
    char* failMsg;
    int* resolvedTfid;
    int eq;
    void* aim = pAimPos;
    const int skillIdForPacket = nSkillId; // arg0 home; sealed → packet +0x18
    std::uint8_t* invalidTfid;
    std::uint8_t resolveScratch[16];
    int seedTfid[4] = { tfid0, tfid1, tfid2, tfid3 };
    char failBuf[260];

    // Contiguous 0x28-byte send buffer (auStack_13c region)
    std::uint32_t packet[10];

    if (*(int*)((int)client + 0xe98) == 0) {
        return;
    }

    void* entity = ClientEntity(client);

    // pSkill = entity->vtbl[+0x234](nSkillId)
    pSkill = (void*)(**(int(***)(int))(*(int*)entity + 0x234))(nSkillId);
    if (pSkill == nullptr || *(std::int16_t*)((int)pSkill + 0x5f6) == 0) {
        return;
    }

    // LocalCastValidate(entity, bSkipBusy=0, pSkill, extra=0)
    // Ghidra typed pSkill slot as char - body uses full pointer.
    validateCode = Skill_LocalCastValidate(entity, nullptr, pSkill, nullptr);

    if (validateCode == 0) {
        // Resolve third arg is &seed TFID (arg1..4), NOT &nSkillId.
        // Out TFID written to resolveScratch; EAX returns that buffer.
        resolvedTfid = (int*)Client_Skill_ResolveCastTarget(
            resolveScratch, pSkill, seedTfid, aim, 1);

        // Contiguous TFID copy for equals + pack (retail holds dwords in regs/stack homes).
        int outTfid[4] = {
            resolvedTfid[0], resolvedTfid[1], resolvedTfid[2], resolvedTfid[3]
        };
        tfid0 = outTfid[0];
        tfid1 = outTfid[1];
        tfid2 = outTfid[2];
        tfid3 = outTfid[3];

        eq = TFID_EqualsObjectId(outTfid, g_abTfidInvalid_A15870);
        if ((char)eq == '\0') {
            // Skip optimistic cast-again HB when world+0x7e (server/sim mode);
            // inbound SkillStatusEffect creates it instead.
            if (*(char*)(*(int*)((int)client + 0xe04) + 0x7e) == '\0') {
                invalidTfid = g_abTfidInvalid_A15870;
                Skill_LookupActiveCastBinding(
                    resolveScratch, *(int*)((int)pSkill + 0x5fc));
                eq = TFID_EqualsObjectId(resolveScratch, invalidTfid);

                if (((char)eq != '\0')
                    && (Skill_ClearActiveCastCounterAndQueueId(
                            *(int*)((int)pSkill + 0x5fc)),
                        *(char*)((int)pSkill + 0x61c) == '\0'))
                {
                    // thiscall(entity, pSkill, chargeMs) — no 4th arg (unaff_EBX was phantom).
                    Skill_StartCastAgainHeartbeat(
                        entity,
                        pSkill,
                        (int)*(std::int16_t*)((int)pSkill + 0x14));
                }
            }

            if (0 < *(std::int16_t*)((int)pSkill + 0x14)) {
                invalidTfid = g_abTfidInvalid_A15870;
                Skill_LookupActiveCastBinding(
                    resolveScratch, *(int*)((int)pSkill + 0x5fc));
                eq = TFID_EqualsObjectId(resolveScratch, invalidTfid);

                if ((char)eq != '\0') {
                    // vtbl+0x238(3, nSkillId, rankSum, /*charge*/0, 0,0,0,0)
                    // unaff_retaddr was phantom; 2nd arg = skill id (asm).
                    (**(void(***)(int, int, int, int, int, int, int, int))(
                        *(int*)entity + 0x238))(
                        3,
                        skillIdForPacket,
                        (int)(std::int16_t)(
                            *(std::int16_t*)((int)pSkill + 0x174)
                            + *(std::int16_t*)((int)pSkill + 0x5f6)),
                        0, 0, 0, 0, 0);

                    FUN_007fb690(
                        0,
                        (float)(int)*(std::int16_t*)((int)pSkill + 0x14)
                            * g_flMsToSeconds_Inferred,
                        (int)pSkill + 0x184,
                        "...Activating Skill...",
                        DAT_00afdf08,
                        (int)0xff400000,
                        0,
                        0);
                }
            }

            // --- 0x2030 stores (asm-confirmed slot map) ---
            // +0x00 opcode, +0x08 TFID16, +0x18 nSkillId, +0x1C aim float3
            packet[0] = 0x2030;                          // +0x00
            // +0x04 pad intentionally unset
            ((int*)packet)[2] = tfid0;                   // +0x08
            ((int*)packet)[3] = tfid1;                   // +0x0c
            ((int*)packet)[4] = tfid2;                   // +0x10
            ((int*)packet)[5] = tfid3;                   // +0x14
            ((int*)packet)[6] = skillIdForPacket;        // +0x18 Confirmed
            packet[7] = *(std::uint32_t*)aim;            // +0x1c aim.x
            packet[8] = *(std::uint32_t*)((int)aim + 4); // +0x20 aim.y
            packet[9] = *(std::uint32_t*)((int)aim + 8); // +0x24 aim.z

            Client_SendSectorPacket(client, 0x28, packet);

            int* qbUi = *(int**)((int)client + 0x10b0);
            if ((qbUi != nullptr)
                && (qbVisible = (**(char(***)())(*qbUi + 0x3d8))(),
                    qbVisible != '\0'))
            {
                (**(void(***)(void*))(*qbUi + 0x450))(pSkill);
            }

            if ((0 < *(std::int16_t*)((int)pSkill + 8))
                || (g_flZero < *(float*)((int)pSkill + 0x44))
                || (0 < *(std::int16_t*)((int)pSkill + 10)))
            {
                Client_MaybeShowFirstTimeTip(0x23);
            }
        }
    } else {
        void* casterForMsg;
        if (*(int*)((int)client + 0xe98) == 0) {
            casterForMsg = nullptr;
        } else {
            casterForMsg = ClientEntity(client);
        }

        failMsg = Skill_FormatFailureMessage(validateCode, failBuf, casterForMsg);
        if (DAT_00d1b8dc != 0) {
            FUN_008f8200(DAT_00d1b8dc, 0x18, &DAT_00a156cc, failMsg, 0);
            return;
        }
    }
}
