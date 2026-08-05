// =============================================================================
// StdMap_LowerBoundByIntKey_INFERRED
// -----------------------------------------------------------------------------
// Stable ID: aa_004054f0
// Address:   0x004054f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* StdMap_LowerBoundByIntKey_INFERRED
   
   INFERRED MSVC std::map lower_bound for int keys.
   this = map object; writes *ppOutNode to matching node or end sentinel.
   Used by Experience_GetCumulativeThreshold and LevelUp table lookups.
   Dependency of session XP RE only — not fully verified against STL symbols. */

void __thiscall StdMap_LowerBoundByIntKey_INFERRED(void *this,void **ppOutNode,int *pKey)

{
  uint32_t /* width from decompiler */ *puVar1;
  uint32_t /* width from decompiler */ *puVar2;
  uint32_t /* width from decompiler */ *puVar3;
  
  puVar3 = *(uint32_t /* width from decompiler */ **)((int)this + 4);
  if (*(char *)((int)puVar3[1] + 0x1d) == '\0') {
    puVar1 = (uint32_t /* width from decompiler */ *)puVar3[1];
    do {
      if ((int)puVar1[3] < *pKey) {
        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];
      }
      else {
        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x1d) == '\0');
  }
  if ((puVar3 != *(uint32_t /* width from decompiler */ **)((int)this + 4)) && ((int)puVar3[3] <= *pKey)) {
    *ppOutNode = puVar3;
    return;
  }
  *ppOutNode = *(uint32_t /* width from decompiler */ **)((int)this + 4);
  return;
}
