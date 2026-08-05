// =============================================================================
// Named_CalleeOf_Skill_LookupActiveCastBinding_0051c150
// -----------------------------------------------------------------------------
// Stable ID: aa_0051c150
// Canonical: Map_ExactFindByIntKey (see FUN_0051c150.cpp dual seal)
// Callees of: Skill_LookupActiveCastBinding AND Skill_ClearCastBindingAndMaybeRestartCd
// Address:   0x0051c150  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Alias clean kept for xref-seeded name; prefer Map_ExactFindByIntKey / FUN_0051c150.

void __thiscall Named_CalleeOf_Skill_LookupActiveCastBinding_0051c150(
    int param_1, uint32_t *param_2, int *param_3)
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
