// =============================================================================
// FUN_004ead30
// -----------------------------------------------------------------------------
// Stable ID: aa_004ead30
// Address:   0x004ead30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ead30 @ 0x004ead30
// Stable ID: aa_004ead30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004935b0, FUN_004ba670, FUN_004ead30.
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

void __thiscall FUN_004ead30(int param_1,uint param_2)



{

  uint uVar1;

  void *pvVar2;

  uint extraout_EDX;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a25d0;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  if (0x3fffffff < param_2) {

    ExceptionList = &local_10;

    FUN_004ba670();

    param_2 = extraout_EDX;

  }

  if (*(int *)(param_1 + 4) == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) >> 2;

  }

  if (uVar1 < param_2) {

    param_2 = param_2 * 4;

    pvVar2 = operator_new(param_2);

    local_8 = 0;

    FUN_004935b0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8),pvVar2,param_1,param_2);

    if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 4));

    }

    *(void **)(param_1 + 0xc) = (void *)(param_2 + (int)pvVar2);

    *(void **)(param_1 + 8) = pvVar2;

    *(void **)(param_1 + 4) = pvVar2;

  }

  ExceptionList = local_10;

  return;

}
