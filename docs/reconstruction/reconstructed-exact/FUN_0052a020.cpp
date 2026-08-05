// =============================================================================
// FUN_0052a020 / CVOGCharacter_IsObjectiveReady (proposed)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052a020
// Address:   0x0052a020  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      reviews/A|B_aa_0052a020_CVOGCharacter_IsObjectiveReady.md (accept-with-gaps)
// =============================================================================

// PURPOSE:
//   Character-side objective readiness. Used by turn-in (FUN_0052b420, mode 1)
//   and journal (FUN_0052b3b0, mode 0).
//   - Non-empty evaluators [obj+0x158, obj+0x15c): AND all virtuals.
//       mode 0 → vtbl+0xc(); mode nonzero → vtbl+0x8(character, pending*)
//   - Pending node: CNDHash_LookupByKey(*(char+0x55c), *(obj+0x10))
//   - Empty evaluators: ready iff *(obj+0x138) != 0  (English for +0x138 OPEN)
//   - Does NOT apply CompleteCount (+0x164); see EvaluatePendingObjectives.

// ABI (sealed 2026-07-29 read_memory):
//   thiscall ECX = character; stack objectiveDef*, mode char; RET 8; AL 0/1.

// READABILITY:
//  - Control flow preserved from Ghidra decompile / raw.
//  - Types refined in comments only; identifiers remain FUN_* for bit-exact porting.

extern void* CNDHash_LookupByKey(void* hash, unsigned int key);

bool __thiscall FUN_0052a020(int param_1, int param_2, char param_3)
{
  int iVar1;
  int *piVar2;
  char cVar3;
  void *pvVar4;
  unsigned int uVar5;

  if (param_2 == 0) {
    return false;
  }
  if ((*(int *)(param_2 + 0x158) != 0) &&
     (*(int *)(param_2 + 0x15c) - *(int *)(param_2 + 0x158) >> 2 != 0)) {
    pvVar4 = CNDHash_LookupByKey(*(void **)(param_1 + 0x55c), *(unsigned int *)(param_2 + 0x10));
    uVar5 = 0;
    while (true) {
      iVar1 = *(int *)(param_2 + 0x158);
      if ((iVar1 == 0) || ((unsigned int)(*(int *)(param_2 + 0x15c) - iVar1 >> 2) <= uVar5)) {
        return true;
      }
      piVar2 = *(int **)(iVar1 + uVar5 * 4);
      if (param_3 == '\0') {
        cVar3 = (**(code **)(*piVar2 + 0xc))();
      }
      else {
        cVar3 = (**(code **)(*piVar2 + 8))(param_1, pvVar4);
      }
      if (cVar3 == '\0') break;
      uVar5 = uVar5 + 1;
    }
    return false;
  }
  return *(int *)(param_2 + 0x138) != 0;
}
