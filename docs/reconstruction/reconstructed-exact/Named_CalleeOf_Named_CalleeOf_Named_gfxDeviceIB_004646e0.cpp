// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceIB_004646e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004646e0
// Callee of Named_CalleeOf_Named_gfxDeviceIB
// Address:   0x004646e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceIB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00436ef0, FUN_004540b0, FUN_004646e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDeviceIB
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceIB_004646e0(int param_1,uint param_2)



{

  uint uVar1;

  void *pvVar2;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd530;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  if (param_2 != 0) {

    uVar1 = param_2;

    if (0x3fffffff < param_2) {

      uVar1 = FUN_004540b0();

    }

    uVar1 = uVar1 * 4;

    pvVar2 = operator_new(uVar1);

    local_8 = 0;

    *(void **)(param_1 + 0xc) = (void *)(uVar1 + (int)pvVar2);

    *(void **)(param_1 + 4) = pvVar2;

    *(void **)(param_1 + 8) = pvVar2;

    FUN_00436ef0(param_2);

    *(void **)(param_1 + 8) = (void *)(uVar1 + (int)pvVar2);

  }

  ExceptionList = local_10;

  return;

}
