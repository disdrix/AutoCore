// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004620b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004620b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice
// Address:   0x004620b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_004620b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004620b0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  int *piVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint8_t local_8;

  undefined3 uStack_7;

  

  puStack_c = &LAB_009be5a1;

  local_10 = ExceptionList;

  uStack_7 = 0;

  ExceptionList = &local_10;

  for (; param_1 != param_2; param_1 = param_1 + 7) {

    local_8 = 1;

    if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

      *param_3 = *param_1;

      param_3[1] = param_1[1];

      param_3[2] = param_1[2];

      param_3[3] = param_1[3];

      piVar1 = (int *)param_1[4];

      if ((piVar1 != (int *)0x0) && (piVar1[1] = piVar1[1] + 1, piVar1[1] == 1)) {

        (**(code **)(*piVar1 + 4))();

      }

      param_3[4] = param_1[4];

      *(uint8_t *)(param_3 + 5) = *(uint8_t *)(param_1 + 5);

      *(uint8_t *)((int)param_3 + 0x15) = *(uint8_t *)((int)param_1 + 0x15);

      *(uint8_t *)((int)param_3 + 0x16) = *(uint8_t *)((int)param_1 + 0x16);

      param_3[6] = param_1[6];

    }

    param_3 = param_3 + 7;

  }

  ExceptionList = local_10;

  return param_3;

}
