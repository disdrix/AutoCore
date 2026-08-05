// =============================================================================
// FUN_005b82b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b82b0
// Address:   0x005b82b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b82b0 @ 0x005b82b0
// Stable ID: aa_005b82b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00404d80, FUN_005b82b0.
//  - Return sites: 1.

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

void __thiscall FUN_005b82b0(int param_1,int param_2)



{

  void *pvVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6b2b;

  local_c = ExceptionList;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    *(int *)(param_1 + 0xc) = param_2;

    pvVar1 = operator_new__(param_2 * 0xc);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      pvVar1 = (void *)0x0;

    }

    else {

      FUN_00404d80(pvVar1,0xc,param_2,FUN_005edf20);

    }

    local_4 = 0xffffffff;

    *(void **)(param_1 + 4) = pvVar1;

    pvVar1 = operator_new(4);

    *(void **)(param_1 + 8) = pvVar1;

  }

  ExceptionList = local_c;

  return;

}
