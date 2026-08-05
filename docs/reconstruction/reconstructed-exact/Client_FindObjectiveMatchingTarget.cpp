// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×8, for×4, return×3, while×1.
//  - Notable callees: FUN_007a4480×4, Client_FindObjectiveMatchingTarget, Client_SendUseObject, hash.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 3.

// =============================================================================
// Client_FindObjectiveMatchingTarget
// -----------------------------------------------------------------------------
// Purpose:  Walk the character's **active objectives** hash (char+0x548) and
//           return the first objective definition whose evaluators accept the
//           given **target key** (vtable+0x38 MatchTarget). Used by
//           Client_SendUseObject (C2S 0x2072) to fill IDObjective at packet+0x18
//           (−1 if none). Sole production caller (xref 2026-07-29).
//
// Address:  0x00525bd0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00525bd0
// System:   missions-progression (UseObject consumer)
//
// Convention: MSVC __thiscall
//   this / param_1  — CVOGCharacter*
//   param_2         — target match key (often clonebase field from object+0xa8+0x34)
//
// Returns:  objective definition* (payload at hash node+8) on first match,
//           else 0. Caller reads objective id at def+0x10 (not this return).
//
// Prerequisites:
//   - Pending-objectives container count at *(char+0x55c)+0xc must be ≥ 1
//     (early-out 0 if empty — gate only; does not walk +0x55c).
//   - Hash traversal uses lock byte at hash+0x1d (asserts if already locked).
//
// Per-objective evaluator walk:
//   def+0x158 begin / def+0x15c end of evaluator* array
//   MatchTarget: (**evaluator)->vtable[+0x38](targetKey, character)
//
// Contrast (do not merge):
//   FindActiveObjectiveIdForInteract 0x00524520 — returns id; eval +0x40; no pending gate
//   MatchTargetEvaluators 0x0059d9c0 — helper for +0x40 object match
//   UseItem MatchTarget 0x0060d7f0 JMP FUN_0060d460 — object (char, worldObj) ABI;
//     not sealed as pure key match under this walker's call shape
//
// Exactness: Control flow mirrors raw Ghidra decompile (live recheck 2026-07-29).
// Dual reviews (residual refresh 2026-07-29):
//   reviews/A_aa_00525bd0_Client_FindObjectiveMatchingTarget.md
//   reviews/B_aa_00525bd0_Client_FindObjectiveMatchingTarget.md
//   reviews/a_00525bd0.md (scratch)
// =============================================================================

#include <cstdint>

void FUN_007a4480(int level, const char* msg);

/// @param thisCharacter  CVOGCharacter* (param_1 / ECX)
/// @param targetKey      Target match key (param_2) — clonebase / object type id
/// @return               Objective def* with matching evaluator, or 0
int __thiscall Client_FindObjectiveMatchingTarget(int thisCharacter, std::uint32_t targetKey)
{
    int iEvalBegin;  // evaluator array begin (def+0x158)
    char cMatch;
    int pHashNode;   // hash chain cursor (node); 0 before first step
    int pObjDef;     // objective definition* (node+8 payload) / temp hash*
    unsigned uEval;

    // Bail if pending-objectives container is empty (count at container+0xc)
    pHashNode = 0;
    if (*(int*)(*(int*)(thisCharacter + 0x55c) + 0xc) < 1) {
        return 0;
    }

    // Lock active-objectives hash for traversal
    pObjDef = *(int*)(thisCharacter + 0x548);
    if (*(char*)(pObjDef + 0x1d) != '\0') {
        FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    *(std::uint8_t*)(pObjDef + 0x1d) = 1;

    while (true) {
        pObjDef = *(int*)(thisCharacter + 0x548);
        if (*(char*)(pObjDef + 0x1d) == '\0') {
            FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }

        // First visit: head at hash+0x14; thereafter next = node+0x14
        if (pHashNode == 0) {
            pHashNode = *(int*)(pObjDef + 0x14);
        } else {
            pHashNode = *(int*)(pHashNode + 0x14);
        }

        if (pHashNode == 0) {
            pObjDef = 0;
        } else {
            pObjDef = *(int*)(pHashNode + 8); // payload = objective def*
        }
        if (pObjDef == 0) {
            break;
        }

        // For each evaluator on this objective: MatchTarget (vtable +0x38)
        for (uEval = 0;
             (iEvalBegin = *(int*)(pObjDef + 0x158),
              iEvalBegin != 0 &&
              (uEval < (unsigned)(*(int*)(pObjDef + 0x15c) - iEvalBegin >> 2)));
             uEval = uEval + 1)
        {
            cMatch = (**(char (**)(std::uint32_t, int))(
                **(int**)(iEvalBegin + uEval * 4) + 0x38))(targetKey, thisCharacter);
            if (cMatch != '\0') {
                // Unlock and return matching objective def
                *(std::uint8_t*)(*(int*)(thisCharacter + 0x548) + 0x1d) = 0;
                return pObjDef;
            }
        }
    }

    // No match — unlock and fail
    *(std::uint8_t*)(*(int*)(thisCharacter + 0x548) + 0x1d) = 0;
    return 0;
}
