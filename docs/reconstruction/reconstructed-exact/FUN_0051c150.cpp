// =============================================================================
// Map_ExactFindByIntKey  (Ghidra: FUN_0051c150)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051c150
// Address:   0x0051c150  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      reviews/A_aa_0051c150_Map_ExactFindByIntKey.md
//            reviews/B_aa_0051c150_Map_ExactFindByIntKey.md
// =============================================================================

// PURPOSE:
//   Read-only exact find on int-keyed ordered map (active-cast binding tree).
//   Node nil @ +0x29, key int @ +0x10, left +0, right +8, end = *(map+4).
//   Writes matching node* or end to *pOutNode. No insert/erase/value copy.
//
// CALLERS:
//   Skill_LookupActiveCastBinding @ 0x00518d07
//   Skill_ClearCastBindingAndMaybeRestartCd @ 0x0051a717
//
// NOTE: Distinct layout from Map_LowerBoundFindByIntKey (+0x15) and
//       StdMap_LowerBoundByIntKey_INFERRED (+0x1d). Do not conflate.

/*
 * Behavioral notes:
 * - Walk is lower_bound-shaped; post-check enforces exact key match.
 * - ret 8: two stack formals cleaned by callee; thiscall ECX = map header.
 * - Runtime / differential verification: OPEN.
 */

void __thiscall FUN_0051c150(int param_1, uint32_t *param_2, int *param_3)
{
  uint32_t *puVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;

  puVar3 = *(uint32_t **)(param_1 + 4);
  if (*(char *)((int)puVar3[1] + 0x29) == '\0') {
    puVar1 = (uint32_t *)puVar3[1];
    do {
      if ((int)puVar1[4] < *param_3) {
        puVar2 = (uint32_t *)puVar1[2];
      }
      else {
        puVar2 = (uint32_t *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x29) == '\0');
  }
  if ((puVar3 != *(uint32_t **)(param_1 + 4)) && ((int)puVar3[4] <= *param_3)) {
    *param_2 = puVar3;
    return;
  }
  *param_2 = *(uint32_t **)(param_1 + 4);
  return;
}
