// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CVOGReaction_RelockContinentObject, FUN_004d1d00, FUN_004d9ec0, FUN_00538c80.
//  - Return sites: 2.

// =============================================================================
// CVOGReaction_RelockContinentObject
// -----------------------------------------------------------------------------
// Stable ID: aa_0052a1b0
// Address:   0x0052a1b0  (autoassault.exe, image base 0x400000)
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

void __thiscall CVOGReaction_RelockContinentObject(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_13c;

  uint8_t local_138 [28];

  uint32_t /* width from decompiler */ local_11c;

  

  local_13c = (void *)0x0;

  FUN_00538c80(param_2,&local_13c);

  if (local_13c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_13c);

  }

  param_1 = param_1 + *(int *)(*(int *)(param_1 + 4) + 4);

  if (param_1 + 4 == *(int *)(*(int *)(param_1 + 0xa8) + 0xe8a0)) {

    FUN_004d1d00();

    local_11c = 0x2a;

    FUN_004d9ec0(local_138,1);

  }

  return;

}
