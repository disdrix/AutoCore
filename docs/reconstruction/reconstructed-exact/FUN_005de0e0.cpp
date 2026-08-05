// =============================================================================
// FUN_005de0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005de0e0
// Address:   0x005de0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005de0e0 @ 0x005de0e0
// Stable ID: aa_005de0e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004cb1d0, FUN_005dd920, FUN_005de0e0.
//  - Return sites: 2.

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

void __thiscall FUN_005de0e0(int param_1,uint param_2)



{

  void *pvVar1;

  uint uVar2;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a7270;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  if (0xfffffff < param_2) {

    ExceptionList = &local_10;

    param_2 = FUN_004cb1d0();

  }

  if (*(int *)(param_1 + 4) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) >> 4;

  }

  if (uVar2 < param_2) {

    param_2 = param_2 * 0x10;

    pvVar1 = operator_new(param_2);

    local_8 = 0;

    FUN_005dd920(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8),pvVar1,param_1,param_2);

    if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 4));

    }

    *(void **)(param_1 + 0xc) = (void *)(param_2 + (int)pvVar1);

    *(void **)(param_1 + 8) = pvVar1;

    *(void **)(param_1 + 4) = pvVar1;

  }

  ExceptionList = local_10;

  return;

}
