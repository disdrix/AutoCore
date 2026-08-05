// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069ffe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0069ffe0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069ffe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0069ffe0, FUN_006a1be0, FUN_006a1cd0, FUN_006a3db0, _atexit.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069ffe0(int param_1)



{

  float fVar1;

  int iVar2;

  float10 fVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  fVar3 = (float10)g_flZero;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab02e;

  local_c = ExceptionList;

  if ((*(int *)(param_1 + 0x40) != 0) &&

     ((*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40)) / 0x18 == 500)) {

    ExceptionList = &local_c;

    iVar2 = FUN_006a3db0();

    fVar1 = *(float *)(*(int *)(param_1 + 0x40) + iVar2 * 0x18 + 4);

    if ((_DAT_00d08f88 & 1) == 0) {

      _DAT_00d08f88 = _DAT_00d08f88 | 1;

      local_4 = 0;

      FUN_006a1cd0();

      _atexit((_func_4879 *)&LAB_009c5580);

      local_4 = 0xffffffff;

    }

    fVar1 = fVar1 * *(float *)(param_1 + 8);

    fVar3 = (float10)FUN_006a1be0(-fVar1,fVar1);

  }

  ExceptionList = local_c;

  return fVar3;

}
