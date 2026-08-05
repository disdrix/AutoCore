// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, for×1, do×1, while×1.
//  - Notable callees: CNDHash_LookupByKey, CVOGReaction_CompleteObjective, FUN_0053fff0.
//  - Return sites: 2.
//  - Convention: __thiscall (listing RET 8); decompiler falsely emits __cdecl.

// =============================================================================
// CVOGCharacter_CompleteMissionObjectives
// -----------------------------------------------------------------------------
// Purpose:  Bulk force-complete every objective on a mission definition by id.
//           Looks up mission def (FUN_0053fff0(DAT_00b041fc) + CNDHash_LookupByKey),
//           then for each entry in def+0x13c (count = byte at +0x130) calls
//           CVOGReaction_CompleteObjective(this, objId, -1, -1, forceComplete).
//           Note: args 2/3 are 0xFFFFFFFF reward-COID wildcards; arg 4 is the
//           forceComplete flag (raw name uReason; NOT -1). CompleteObjective
//           return is ignored. Count 0 still returns 1.
//
// Address:  0x00536080  (autoassault.exe, image base 0x400000)
// Stable:   aa_00536080
// System:   missions-progression
//
// Convention: MSVC __thiscall (character this + 2 stack formals; RET 8)
//
// Callers:  CVOGCharacter_CheckMissionPrerequisites only (2 sites), both
//           forceComplete=1 (asm PUSH 1) with live MOV ECX,ESI. No
//           EvaluatePending xref (2026-07-29).
//
// Returns:  1 if mission def found (even if 0 objectives), 0 if not.
//           Does not itself write completed-mission hashes (callee-owned).
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch);
//            re-verified live decompile 2026-07-29 ≡ raw CF. Listing seals
//            thiscall/this/force (decomp prototype still wrong). Dual A/B
//            accept-with-gaps residual strengthen 2026-07-29.
// =============================================================================

#include <cstdint>

// Global owner object used as ECX for FUN_0053fff0 (mission table lazy slot +0xf18).
extern std::uint32_t* DAT_00b041fc;

std::uint32_t* __fastcall FUN_0053fff0(void* owner); // returns *(owner+0xf18)
void* CNDHash_LookupByKey(void* hash, unsigned missionId);
// Callee is __thiscall; forceComplete is char at boundary (pushed as 32-bit).
std::uint32_t __thiscall CVOGReaction_CompleteObjective(
    void* thisCharacter,
    std::uint32_t objectiveId,
    std::uint32_t rewardCoidLo,
    std::uint32_t rewardCoidHi,
    std::uint32_t forceComplete);

char __thiscall CVOGCharacter_CompleteMissionObjectives(
    void* thisCharacter,
    unsigned uMissionID,
    std::uint32_t forceComplete /* raw: uReason */)
{
    std::uint8_t bCount;
    std::uint32_t* puTableRoot;
    void* missionDef;
    int i;

    // FUN_0053fff0(DAT_00b041fc) — ECX = global owner; lazy hash object at +0xf18
    puTableRoot = FUN_0053fff0(DAT_00b041fc);

    if (((void*)*puTableRoot != (void*)0x0) &&
        (missionDef = CNDHash_LookupByKey((void*)*puTableRoot, uMissionID),
         missionDef != (void*)0x0))
    {
        // Objectives count (byte at mission+0x130)
        bCount = *(std::uint8_t*)((int)missionDef + 0x130);
        i = 0;
        if (bCount != 0) {
            do {
                // objectiveDef = *(*(mission+0x13c) + i*4)
                // CompleteObjective(this, objectiveDef+0x10, -1, -1, forceComplete)
                CVOGReaction_CompleteObjective(
                    thisCharacter,
                    *(std::uint32_t*)(
                        *(int*)(*(int*)((int)missionDef + 0x13c) + i * 4) + 0x10),
                    0xffffffffu,
                    0xffffffffu,
                    forceComplete);
                i = i + 1;
            } while (i < (int)(unsigned)bCount);
        }
        return '\x01';
    }
    return '\0';
}
