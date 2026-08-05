// =============================================================================
// Map_LowerBoundFindByIntKey
// -----------------------------------------------------------------------------
// Stable ID: aa_0050f940
// Address:   0x0050f940  (autoassault.exe, image base 0x400000)
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

/* Map_LowerBoundFindByIntKey — ordered map lower_bound (INFERRED)
   
   Variant used by quest XP/credit lookups (node flag at +0x15 vs +0x1d
   in StdMap_LowerBoundByIntKey_INFERRED — slightly different node layout).
   INFERRED: both are MSVC std::map lower_bound for int keys.
   Session dependency for Mission_ComputeObjectiveXp. */

void __thiscall Map_LowerBoundFindByIntKey(void *this,void *pMap,void *pOutIt,int *pKey)

{
  uint32_t /* width from decompiler */ *puVar1;
  uint32_t /* width from decompiler */ *puVar2;
  uint32_t /* width from decompiler */ *puVar3;
  
  puVar3 = *(uint32_t /* width from decompiler */ **)((int)this + 4);
  if (*(char *)((int)puVar3[1] + 0x15) == '\0') {
    puVar1 = (uint32_t /* width from decompiler */ *)puVar3[1];
    do {
      if ((int)puVar1[3] < *(int *)pOutIt) {
        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];
      }
      else {
        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  if ((puVar3 != *(uint32_t /* width from decompiler */ **)((int)this + 4)) && ((int)puVar3[3] <= *(int *)pOutIt)) {
    *(uint32_t /* width from decompiler */ **)pMap = puVar3;
    return;
  }
  *(uint32_t /* width from decompiler */ **)pMap = *(uint32_t /* width from decompiler */ **)((int)this + 4);
  return;
}
