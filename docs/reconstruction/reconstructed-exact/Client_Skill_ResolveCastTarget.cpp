// READABILITY (auto CF):
//  - Body size: ~150 non-empty decompiler lines.
//  - Control keywords: if×26, goto×18, return×3.
//  - Notable callees: Skill_FormatFailureMessage×3, FUN_007a6de0×2, FUN_008f8200×2,
//    TFID_EqualsObjectId×2, Vehicle_ResolveFirstHardpointOccupantTfid_Inferred,
//    FUN_007a69d0, Skill_LookupActiveCastBinding, TFID_NotEquals.
//  - Strings: "No enemies found."; "Can't find a target!"; "Nothing is targeted.".
//  - Return sites: 3.

// =============================================================================
// Client_Skill_ResolveCastTarget
// -----------------------------------------------------------------------------
// Purpose:  Player-side cast-target resolver. Seeds a 16-byte out-TFID from
//           Skill_ResolveTargetList + skill flags, with fallbacks to related/
//           self / hardpoint occupant TFID. On failure may emit a chat toast
//           (when bReportFailure) and always writes the invalid-TFID sentinel
//           into the out buffer on hard fail paths.
//
// Address:  0x0093b3a0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0093b3a0
// System:   skills-abilities
//
// Convention: Client object in EAX (decomp in_EAX). Stack formals below.
//             Call sites (RequestCast / QuickBarActivate) rely on client-in-EAX;
//             clean keeps that register convention (not a sixth stack arg).
//
// Formals:
//   pOutTfid         16-byte TFID write-back (byte*)
//   pSkill           skill runtime object
//   pSeedTfid        4×u32 seed / aim TFID region (ResolveTargetList in-args)
//   pAimOrContext    5th arg into Skill_ResolveTargetList (often aim/zero vec)
//   bReportFailure   non-zero → chat on hard fails
//
// Control flow summary:
//   1) client+0xe98 null → write invalid TFID; return
//   2) FUN_007a69d0(); seed locals from pSeedTfid[0..3]
//   3) if skill+0x614 == 1: copy seed TFID to out; return  (force-seed path)
//   4) resolveSource = local entity dual-base; if on-foot (+0x6b9) and
//      selection (+0xa4) non-null → use selection as resolve source
//   5) Skill_ResolveTargetList(&resolved, client+0xe04, resolveSource,
//      seed dwords, pAimOrContext, &outFlags)
//   6) outFlags dispatch (writers sealed 2026-07-29):
//        bit2 set → fail path (code 0xd toast if report)  [range helper]
//        bit2 clear:
//          bit4 → related/self if skill+0x614&2; else hardpoint if &8;
//                 else invalid+toast code 0xe
//                 [bit4 from Skill_FilterTargetForResolveList_Inferred]
//          bit8 → related if &2; else fail toast code 3
//                 [bit8 from same filter]
//          bit1 clear → use resolved TFID if valid; else active-binding
//                 silent-invalid gate / on-foot silent-invalid /
//                 "Can't find a target!"
//          bit1 set → related if &2; else "Nothing is targeted."
//   7) failure labels write g_abTfidInvalid_A15870 into pOutTfid
//
// Key offsets:
//   client+0xe98   local character root
//   client+0xe04   world/sim object (ResolveTargetList arg)
//   char+0x6b9     on-foot flag
//   entity+0xa4    selected object
//   skill+0x614    mode / flags dword (==1 force-seed; bits 1,2,3 used below)
//   skill+0x615    secondary flag byte (bit1 active-binding path)
//   skill+0x5fc    skill queue / cast id (active-binding lookup)
//   object+0x164.. TFID region used when taking related entity
//   vehicle+0x250  this for hardpoint occupant TFID helper
//
// Callees:
//   Skill_ResolveTargetList                          0x00550300
//   Skill_FilterTargetForResolveList_Inferred        0x0054ff00  (via list; bits 4/8/0x10)
//   Skill_FormatFailureMessage                       eSkillResponses → string
//   Skill_LookupActiveCastBinding                    active cast TFID → scratch
//   TFID_EqualsObjectId / TFID_NotEquals
//   Vehicle_ResolveFirstHardpointOccupantTfid_Inferred  0x004f8b80  (was FUN_004f8b80)
//   FUN_007a6de0                                     localize string key
//   FUN_008f8200                                     chat UI append
//
// Callers:
//   Client_RequestCastSkill           0x00941590
//   Client_QuickBarActivateSkillSlot  0x00921b50
//   FUN_00829190, FUN_00941d50        (secondary; not refined here)
//
// Dual residual close (2026-07-29) + hardpoint strengthen:
//   - FUN_004f8b80 sealed (hardpoint occupant TFID).
//   - Hardpoint this: ECX = *(char+0x250) @ 0x0093b570/576 Confirmed.
//   - Hardpoint reload: EDI/EBP/EBX/[ESP+0x24] from *ret @ 0x0093b581+ Confirmed.
//   - DAT_009cd0f8 content ≡ g_abTfidInvalid_A15870 (16B read_memory Confirmed).
//   - Related (skill&2) before hardpoint (skill&8) on bit4 Confirmed.
//   - outFlags bit4/8 writers sealed (filter helper).
//   - pA/unaffReg = activeBindScratch (Lookup out); asm Confirmed.
//     Sticky gate does NOT copy binding TFID into out — write_seed uses
//     listOut regs (invalid at that gate) → silent invalid out.
// Exactness: CF mirrors raw; param/local names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual reviews:
//   reviews/A_aa_0093b3a0_Client_Skill_ResolveCastTarget.md
//   reviews/B_aa_0093b3a0_Client_Skill_ResolveCastTarget.md
// Scratch: reviews/a_0093b3a0.md (tmp/a_0093b3a0.md twin)
// =============================================================================

#include <cstdint>

extern "C" void  FUN_007a69d0();
extern "C" void  Skill_ResolveTargetList(void* pOutResolved, void* pWorld,
                                         void* pSource, std::uint32_t a,
                                         std::uint32_t b, std::uint32_t c,
                                         std::uint32_t d, void* pAimOrCtx,
                                         unsigned* pOutFlags);
extern "C" char* Skill_FormatFailureMessage(int code, char* buf, void* src);
// was FUN_004f8b80 — sole caller of this unit; vehicle this in ECX (+0x250).
extern "C" void* Vehicle_ResolveFirstHardpointOccupantTfid_Inferred();
extern "C" int   TFID_EqualsObjectId(void* a, void* b);
extern "C" void  Skill_LookupActiveCastBinding(void* out16, int skillQueueId);
extern "C" int   TFID_NotEquals(void* a, void* b);
extern "C" char* FUN_007a6de0(const char* key, unsigned mask);
extern "C" void  FUN_008f8200(int host, unsigned channel, void* prefix,
                              char* msg, int z);
extern "C" std::uint8_t g_abTfidInvalid_A15870[];
extern "C" int   DAT_00d1b8dc;
extern "C" char  DAT_00a156cc;

/// @param pOutTfid       16-byte TFID write-back.
/// @param pSkill         Skill runtime.
/// @param pSeedTfid      4×u32 seed TFID / position region.
/// @param pAimOrContext  Passed through to Skill_ResolveTargetList.
/// @param bReportFailure Non-zero → chat on hard failure paths.
/// @note client arrives in EAX (retail / decomp in_EAX).
void Client_Skill_ResolveCastTarget(
    std::uint8_t* pOutTfid,
    int pSkill,
    std::uint32_t* pSeedTfid,
    std::uint32_t pAimOrContext,
    char bReportFailure)
{
    int client = 0; // in_EAX - client object at entry
    char* failMsg;
    int relatedOrSelf;
    std::uint32_t* relatedTfid;
    // write_seed plate (asm Confirmed): EDI/EBP/EBX/[ESP+0x24] hold out TFID
    // dwords after ResolveTargetList (or after related/hardpoint reload).
    std::uint32_t seed2;
    std::uint32_t seed1;
    std::uint32_t seed0;
    void* resolveSource;
    std::uint32_t resolved3;
    std::uint32_t resolved0;
    std::uint32_t resolved1;
    std::uint32_t resolved2;
    unsigned outFlags;
    // decomp local_750 — LookupActiveCastBinding out; TFID_NotEquals first arg
    // (decomp pA/unaffReg). Sealed 2026-07-29 via asm @ 0x0093b74d/0x0093b75e.
    std::uint8_t activeBindScratch[16];
    char failBuf[256];
    std::uint32_t listOut0;
    std::uint32_t listOut1;
    std::uint32_t listOut2;
    std::uint32_t listOut3;

    if (*(int*)(client + 0xe98) == 0) {
        goto write_invalid;
    }

    FUN_007a69d0();

    resolved3 = pSeedTfid[3];
    seed2 = pSeedTfid[2];
    seed1 = pSeedTfid[1];
    seed0 = pSeedTfid[0];

    // skill+0x614 == 1 → force-copy seed TFID to out (skip resolve)
    if (*(int*)(pSkill + 0x614) == 1) {
        goto write_seed;
    }

    outFlags = 0;
    if (*(int*)(client + 0xe98) == 0) {
        resolveSource = nullptr;
    } else {
        resolveSource = (void*)(*(int*)(client + 0xe98) + 4
                                + *(int*)(*(int*)(*(int*)(client + 0xe98) + 4)
                                          + 4));
    }

    // On-foot with selection → resolve from selected object
    if ((*(char*)(*(int*)(client + 0xe98) + 0x6b9) != '\0')
        && (*(int*)(*(int*)(*(int*)(*(int*)(client + 0xe98) + 4) + 4) + 0xa4
                    + *(int*)(client + 0xe98))
            != 0))
    {
        int root = *(int*)(client + 0xe98);
        resolveSource =
            *(void**)(*(int*)(*(int*)(root + 4) + 4) + 0xa4 + root);
    }

    Skill_ResolveTargetList(
        &listOut0,
        *(void**)(client + 0xe04),
        resolveSource,
        pSeedTfid[0],
        pSeedTfid[1],
        pSeedTfid[2],
        pSeedTfid[3],
        (void*)(std::uintptr_t)pAimOrContext,
        &outFlags);

    resolved3 = listOut3;
    resolved0 = listOut0;
    resolved1 = listOut1;
    resolved2 = listOut2;

    if ((outFlags & 2) == 0) {
        if ((outFlags & 4) != 0) {
            if ((*(unsigned*)(pSkill + 0x614) & 2) != 0) {
take_related:
                relatedOrSelf =
                    (**(int(***)())(
                        *(int*)(*(int*)(*(int*)(*(int*)(client + 0xe98) + 4) + 4)
                                + 4 + *(int*)(client + 0xe98))
                        + 0x19c))();
take_related_tfid:
                relatedTfid = (std::uint32_t*)(
                    *(int*)(*(int*)(relatedOrSelf + 4) + 4) + 0x164
                    + relatedOrSelf);
                resolved3 = relatedTfid[3];
                seed2 = relatedTfid[2];
                seed1 = relatedTfid[1];
                seed0 = relatedTfid[0];
write_seed:
                *(std::uint32_t*)pOutTfid = seed0;
                *(std::uint32_t*)(pOutTfid + 4) = seed1;
                *(std::uint32_t*)(pOutTfid + 8) = seed2;
                *(std::uint32_t*)(pOutTfid + 0xc) = resolved3;
                return;
            }

            if ((*(unsigned*)(pSkill + 0x614) & 8) == 0) {
                if (bReportFailure != '\0') {
                    failMsg = Skill_FormatFailureMessage(0xe, failBuf,
                                                         resolveSource);
                    if (DAT_00d1b8dc != 0) {
                        FUN_008f8200(DAT_00d1b8dc, 0x18, &DAT_00a156cc, failMsg,
                                     0);
                    }
                }
                *(std::uint32_t*)pOutTfid =
                    *(std::uint32_t*)&g_abTfidInvalid_A15870[0];
                *(std::uint32_t*)(pOutTfid + 4) =
                    *(std::uint32_t*)&g_abTfidInvalid_A15870[4];
                *(std::uint32_t*)(pOutTfid + 8) =
                    *(std::uint32_t*)&g_abTfidInvalid_A15870[8];
                *(std::uint32_t*)(pOutTfid + 0xc) =
                    *(std::uint32_t*)&g_abTfidInvalid_A15870[12];
                return;
            }

            // this = *(localChar+0x250) into ECX (asm 0x0093b570/576);
            // returns TFID* or &DAT_009cd0f8 (content ≡ g_abTfidInvalid_A15870).
            relatedTfid = (std::uint32_t*)
                Vehicle_ResolveFirstHardpointOccupantTfid_Inferred();
            seed0 = relatedTfid[0];
            seed1 = relatedTfid[1];
            seed2 = relatedTfid[2];
            resolved3 = relatedTfid[3];
            resolved0 = seed0;
            resolved1 = seed1;
            resolved2 = seed2;
            relatedOrSelf =
                TFID_EqualsObjectId(&resolved0, g_abTfidInvalid_A15870);
            if ((char)relatedOrSelf == '\0') {
                goto write_seed; // hardpoint TFID reloaded into seed regs
            }
            if ((bReportFailure == '\0')
                || (*(char*)(*(int*)(client + 0xe98) + 0x6b9) != '\0')) {
                goto write_invalid;
            }
            failMsg = "No enemies found.";
localize_and_toast:
            failMsg = FUN_007a6de0(failMsg, 0xffffffff);
            goto toast_channel_0x18;
        }

        if ((outFlags & 8) != 0) {
            if ((*(std::uint8_t*)(pSkill + 0x614) & 2) != 0) {
                relatedOrSelf =
                    (**(int(***)())(
                        *(int*)(*(int*)(*(int*)(*(int*)(client + 0xe98) + 4) + 4)
                                + 4 + *(int*)(client + 0xe98))
                        + 0x19c))();
                goto take_related_tfid;
            }
            if (bReportFailure == '\0') {
                goto write_invalid;
            }
            failMsg = Skill_FormatFailureMessage(3, failBuf, resolveSource);
            goto toast_channel_0x18;
        }

        if ((outFlags & 1) == 0) {
            relatedOrSelf =
                TFID_EqualsObjectId(&resolved0, g_abTfidInvalid_A15870);
            seed2 = listOut2;
            seed1 = listOut1;
            seed0 = listOut0;
            if ((char)relatedOrSelf == '\0') {
                goto write_seed;
            }
            // skill+0x615 bit1: sticky / active-cast gate.
            // Lookup fills activeBindScratch; NotEquals(scratch, invalid).
            // If binding present → write_seed with *listOut regs* (still
            // invalid here) — silent fail, no toast. Does NOT promote the
            // binding TFID into out (asm: no reload of local_750 into EDI…).
            if ((*(std::uint8_t*)(pSkill + 0x615) & 2) != 0) {
                std::uint8_t* invalidTfid = g_abTfidInvalid_A15870;
                Skill_LookupActiveCastBinding(activeBindScratch,
                                              *(int*)(pSkill + 0x5fc));
                relatedOrSelf =
                    TFID_NotEquals(activeBindScratch, invalidTfid);
                if ((char)relatedOrSelf != '\0') {
                    goto write_seed;
                }
            }
            // on-foot: same silent write_seed with invalid listOut
            if (*(char*)(*(int*)(client + 0xe98) + 0x6b9) != '\0') {
                goto write_seed;
            }
            if (bReportFailure == '\0') {
                goto write_invalid;
            }
            failMsg = "Can't find a target!";
            goto localize_and_toast;
        }

        if ((*(std::uint8_t*)(pSkill + 0x614) & 2) != 0) {
            goto take_related;
        }
        if ((bReportFailure == '\0')
            || (*(char*)(*(int*)(client + 0xe98) + 0x6b9) != '\0')) {
            goto write_invalid;
        }
        failMsg = FUN_007a6de0("Nothing is targeted.", 0xffffffff);
        if (DAT_00d1b8dc == 0) {
            goto write_invalid;
        }
        seed0 = 6;
    } else {
        if ((bReportFailure == '\0')
            || (*(char*)(*(int*)(client + 0xe98) + 0x6b9) != '\0')) {
            goto write_invalid;
        }
        failMsg = Skill_FormatFailureMessage(0xd, failBuf, resolveSource);
toast_channel_0x18:
        if (DAT_00d1b8dc == 0) {
            goto write_invalid;
        }
        seed0 = 0x18;
    }

    FUN_008f8200(DAT_00d1b8dc, seed0, &DAT_00a156cc, failMsg, 0);

write_invalid:
    *(std::uint32_t*)pOutTfid = *(std::uint32_t*)&g_abTfidInvalid_A15870[0];
    *(std::uint32_t*)(pOutTfid + 4) = *(std::uint32_t*)&g_abTfidInvalid_A15870[4];
    *(std::uint32_t*)(pOutTfid + 8) = *(std::uint32_t*)&g_abTfidInvalid_A15870[8];
    *(std::uint32_t*)(pOutTfid + 0xc) =
        *(std::uint32_t*)&g_abTfidInvalid_A15870[12];
    return;
}
