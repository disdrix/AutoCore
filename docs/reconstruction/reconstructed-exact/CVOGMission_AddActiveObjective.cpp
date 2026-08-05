// READABILITY (auto CF):
//  - Body size: ~40 non-empty lines (human plate + asm this restores).
//  - Control keywords: if×3, return×1, for×1.
//  - Notable callees: FUN_0053c460 (def hash +0x548), FUN_0053c760 (pending +0x55c),
//    operator_new / operator_delete, evaluator vtbl+0x28.
//  - Return sites: 1 (void).

// =============================================================================
// CVOGMission_AddActiveObjective
// -----------------------------------------------------------------------------
// Purpose:  Register an objective definition as active on the character:
//           insert def into active-objectives hash (char+0x548 via FUN_0053c460),
//           optionally allocate a 0x14-byte runtime state node and insert it into
//           the pending-objectives hash (char+0x55c via FUN_0053c760), then run
//           each evaluator's vtable+0x28 setup hook.
//           Sets dirty flag char+0x634 |= 0x10 when evaluators exist.
//
// Address:  0x00531b00  (autoassault.exe, image base 0x400000)
// Stable:   aa_00531b00
// System:   missions-progression
//
// Convention: MSVC __thiscall  (this / param_1 = CVOGCharacter* in ECX)
//
// Callers (asm-sealed thiscall ECX=character, stack=objectiveDef):
//   CVOGReaction_GiveMission      @ 0x005328b2
//   CVOGReaction_CompleteObjective @ 0x005348a2
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 / recheck 2026-07-29).
// Asm corrections (decompiler drops hash `this`):
//   FUN_0053c460 this = *(CNDHash**)(character + 0x548)   // asm 0x00531b0d
//   FUN_0053c760 this = *(CNDHash**)(character + 0x55c)   // asm 0x00531b6f
// Delete-on-fail falls through into evaluator loop (Ghidra noreturn WARNING is false).
// Dual reviews:
//   reviews/A_aa_00531b00_CVOGMission_AddActiveObjective.md
//   reviews/B_aa_00531b00_CVOGMission_AddActiveObjective.md
//   reviews/a_00531b00.md  (tighten scratch)
// =============================================================================

#include <cstdint>

// Objective def offsets (missionState.md + raw + asm)
//   +0x10  objective id (hash key)
//   +0x158 evaluator array begin (void**)
//   +0x15c evaluator array end
// Character:
//   +0x548  active objectives CNDHash*   (def insert)
//   +0x55c  pending objectives CNDHash*  (state-node insert)
//   +0x634  dirty flags; bit 0x10 set on activate with evaluators

// Hash insert helpers (twin bodies; distinct node vtables only).
// Real sig: __thiscall (CNDHash* this, uint key, int value, char skipIfExists) → HRESULT-like.
// Returns: 0 ok; 1 already (skipIfExists); 0x80004003 null value; 0x80004005 duplicate.
std::uint32_t __thiscall FUN_0053c460(void* hashThis, std::uint32_t objectiveId,
                                      int value, char skipIfExists);
std::uint32_t __thiscall FUN_0053c760(void* hashThis, std::uint32_t objectiveId,
                                      int* stateNode, char skipIfExists);
void* operator_new(std::size_t size);
void  operator_delete(void* p);

/// @param thisCharacter  CVOGCharacter* (param_1 / ECX)
/// @param objectiveDef   Objective definition* (param_2 / stack)
void __thiscall CVOGMission_AddActiveObjective(int thisCharacter, int objectiveDef)
{
    int*          stateNode;
    int           iVar2;
    unsigned      uVar3;
    void*         activeObjHash;
    void*         pendingObjHash;
    std::uint32_t objectiveId;

    objectiveId = *(std::uint32_t*)(objectiveDef + 0x10);

    // Insert objective def into active-objectives hash (char+0x548).
    // Asm @ 0x00531b0b–0x00531b15:
    //   MOV EBP, ECX
    //   MOV ECX, dword ptr [EBP + 0x548]
    //   push 0; push ESI=def; push EAX=id; call FUN_0053c460
    // Decompiler shows FUN_0053c460(id, def, 0) and drops hash this — restored here.
    // Return value intentionally ignored (matches body).
    activeObjHash = *(void**)(thisCharacter + 0x548);
    FUN_0053c460(activeObjHash, objectiveId, objectiveDef, 0);

    // Only allocate runtime state if evaluator array non-empty:
    //   begin != 0 && (end - begin) >> 2 != 0
    if ((*(int*)(objectiveDef + 0x158) != 0) &&
        (*(int*)(objectiveDef + 0x15c) - *(int*)(objectiveDef + 0x158) >> 2 != 0))
    {
        stateNode = (int*)operator_new(0x14);
        if (stateNode == (int*)0x0) {
            stateNode = (int*)0x0;
        } else {
            *stateNode     = 0;
            stateNode[1]   = 0;
            stateNode[2]   = 0;
            stateNode[3]   = 0;
            stateNode[4]   = 0;
        }

        // stateNode[0] = objective def back-pointer (crash-parity if new failed)
        *stateNode = objectiveDef;

        // Insert state node into pending-objectives hash (char+0x55c).
        // Asm @ 0x00531b6f–0x00531b77: MOV ECX, [EBP+0x55c]; push 0; push node; push id
        pendingObjHash = *(void**)(thisCharacter + 0x55c);
        iVar2 = (int)FUN_0053c760(pendingObjHash, objectiveId, stateNode, 0);
        if (iVar2 != 0) {
            // Asm: CALL operator_delete then falls through — NOT noreturn.
            // Freed pointer may still be passed to evaluator hooks (original UAF parity).
            operator_delete(stateNode);
        }

        // For each evaluator: call vtable +0x28(thisCharacter, stateNode)
        // Raw shape: iVar2 = begin each iteration; count = (end-begin)>>2
        for (uVar3 = 0;
             (iVar2 = *(int*)(objectiveDef + 0x158),
              iVar2 != 0 &&
              (uVar3 < (unsigned)(*(int*)(objectiveDef + 0x15c) - iVar2 >> 2)));
             uVar3 = uVar3 + 1)
        {
            // evaluator = *(begin + u*4); (**evaluator + 0x28)(char, state)
            (**(void (**)(int, int*))(**(int**)(iVar2 + uVar3 * 4) + 0x28))
                (thisCharacter, stateNode);
        }

        // Dirty mission state (journal / UI refresh consumers — shared bit with FailMission).
        *(unsigned*)(thisCharacter + 0x634) =
            *(unsigned*)(thisCharacter + 0x634) | 0x10;
    }
    return;
}
