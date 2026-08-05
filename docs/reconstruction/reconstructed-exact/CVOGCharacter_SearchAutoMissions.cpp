// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×15, for×5, goto×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0053fff0×4, FUN_007a4480×4, FUN_00786990×2,
//    CVOGCharacter_CheckMissionRequirements, CVOGReaction_GiveMission, FUN_00786a00.
//  - Strings: "CVOGCharacter::SearchAutoMissions";
//    "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP";
//    "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

// =============================================================================
// CVOGCharacter_SearchAutoMissions
// -----------------------------------------------------------------------------
// Purpose:  Walk the mission-definition hash table and auto-award eligible
//           auto-missions. Skips already-active (+0x540) and completed (+0x538)
//           entries. For each candidate with auto flag (u16 at def+0xF8 != 0),
//           calls CheckMissionRequirements; on return 0, GiveMission.
//
// Address:  0x00532b60  (autoassault.exe, image base 0x400000)
// Stable:   aa_00532b60
// System:   missions-progression
//
// Convention: character this in ECX at entry; body stashes in EBP (0x00532b78).
//
// Hash traversal: lock byte at hash+0x1d; chain via +0x14 nodes, value at +0x8.
// Character active hash at +0x540, completed at +0x538.
//
// Dual A/B residual-2 (2026-07-29):
//   Requirements: ECX=missionDef, stack0=character (NO third arg; unaff_ESI falsified).
//   GiveMission: ECX=character, stack0=*def; return ignored; JMP continues scan (multi-grant).
//   Auto flag: CMP word [def+0xF8],0  (decompiler dword-index 0x3e).
//   Same field as GiveMission toast (toast when ==0; auto when !=0).
//   FUN_0053fff0(ECX=DAT_00b041fc) → wrapper*(owner+0xf18); hash = *wrapper.
//   Callers gate via *(*( *(this+4)+4 ) + this + 0xa8 ) + 0x7e (not bare this+0x7e).
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23) +
// live re-decompile (2026-07-29). Prototype corrected vs residual formals.
// =============================================================================

#include <cstdint>

// SEH / profile helpers
extern void* ExceptionList;
void FUN_00786a00(const char* name); // profile / zone enter
void FUN_00786990();                 // profile / zone leave
void FUN_007a4480(int level, const char* fmt, ...);

// Global owner for mission-def table; live: MOV ECX,[0x00b041fc] before call.
extern int DAT_00b041fc;

// Lazy mission-def table wrapper at owner+0xf18 (0x10 ctor FUN_0060b870). Product name open.
// Search uses hash = *wrapper (first dword). Null wrapper → early return.
int* FUN_0053fff0(); // ECX = DAT_00b041fc

// ECX = missionDef; stack0 = character. Return 0 = pass (grant).
int __thiscall CVOGCharacter_CheckMissionRequirements(
    void* missionDef, int* character);

// ECX = character; stack0 = mission id.
void __thiscall CVOGReaction_GiveMission(void* character, unsigned missionId);

void __fastcall CVOGCharacter_SearchAutoMissions(int* thisCharacter)
{
    unsigned missionId;
    int iHash;
    int* pTable;
    unsigned* pMissionDef;
    int node;
    void* l_prevException;
    std::uint8_t* puStack_8;
    std::uint32_t l_excGuard;

    // SEH frame (MSVC)
    l_excGuard = 0xffffffffu;
    puStack_8  = (std::uint8_t*)&l_excGuard; // placeholder for LAB_009a3ca1 in raw
    (void)puStack_8;
    l_prevException = ExceptionList;
    ExceptionList   = &l_prevException;

    FUN_00786a00("CVOGCharacter::SearchAutoMissions");
    l_excGuard = 0;
    node = 0;

    // Live: ECX = DAT_00b041fc before FUN_0053fff0
    iHash = (int)FUN_0053fff0();
    if (iHash == 0) {
        // No mission table root
        l_excGuard    = 0xffffffffu;
        FUN_00786990();
        ExceptionList = l_prevException;
        return;
    }

    pTable = (int*)FUN_0053fff0();
    iHash  = *pTable;
    if (*(char*)(iHash + 0x1d) != '\0') {
        FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    // Lock hash for safe traversal
    *(std::uint8_t*)(iHash + 0x1d) = 1;

LAB_00532c00:
    do {
        pTable = (int*)FUN_0053fff0();
        iHash  = *pTable;
        if (*(char*)(iHash + 0x1d) == '\0') {
            FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }

        // First visit: start at hash+0x14 head; else node = node+0x14 next
        if (node == 0) {
            node = *(int*)(iHash + 0x14);
            if (node == 0) goto LAB_00532c4a;
            pMissionDef = *(unsigned**)(node + 8);
        } else {
            node = *(int*)(node + 0x14);
            if (node == 0) {
            LAB_00532c4a:
                pMissionDef = (unsigned*)0x0;
            } else {
                pMissionDef = *(unsigned**)(node + 8);
            }
        }

        // End of table → unlock and return
        if (pMissionDef == (unsigned*)0x0) {
            pTable = (int*)FUN_0053fff0();
            *(std::uint8_t*)(*pTable + 0x1d) = 0;
            l_excGuard    = 0xffffffffu;
            FUN_00786990();
            ExceptionList = l_prevException;
            return;
        }

        // Auto-mission candidates: u16 at def+0xF8 != 0
        // (decompiler: (short)pMissionDef[0x3e]; dword index 0x3e → byte 0xF8)
        // GiveMission toast path uses same field when == 0 ("Received Mission").
        if (*(std::int16_t*)((std::uint8_t*)pMissionDef + 0xF8) != 0) {
            missionId = *pMissionDef; // def key / mission id at +0

            // Skip if already active (manual hash walk of character+0x540)
            // decompiler: thisCharacter[0x150] with dword indices (== +0x540)
            for (iHash = *(int*)(*(int*)(*(int*)(thisCharacter[0x150] + 0x10) +
                                        (*(unsigned*)(thisCharacter[0x150] + 8) & missionId) * 4) +
                                 4);
                 iHash != 0;
                 iHash = *(int*)(iHash + 0xc))
            {
                if (missionId == *(unsigned*)(iHash + 0x10)) {
                    if ((iHash != 0) && (*(int*)(iHash + 0x8) != 0)) goto LAB_00532c00;
                    break;
                }
            }

            // Skip if already completed (character+0x538 == thisCharacter[0x14e])
            for (iHash = *(int*)(*(int*)(*(int*)(thisCharacter[0x14e] + 0x10) +
                                        (*(unsigned*)(thisCharacter[0x14e] + 8) & missionId) * 4) +
                                 4);
                 iHash != 0;
                 iHash = *(int*)(iHash + 0xc))
            {
                if (missionId == *(unsigned*)(iHash + 0x10)) {
                    if ((iHash != 0) && (*(int*)(iHash + 0x8) != 0)) goto LAB_00532c00;
                    break;
                }
            }

            // Live: PUSH character; MOV ECX, missionDef; CALL Requirements
            iHash = CVOGCharacter_CheckMissionRequirements(pMissionDef, thisCharacter);
            if (iHash == 0) {
                // Live: PUSH *def; MOV ECX, character; CALL GiveMission
                CVOGReaction_GiveMission(thisCharacter, *pMissionDef);
            }
        }
    } while (true);
}
