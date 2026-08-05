// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_00497c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00497c80
// Callee of Named_CalleeOf_Drive_NDRiver_fx
// Address:   0x00497c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_00497900, FUN_00497c80, FUN_007874b0, FUN_00788db0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_NDRiver_fx
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_00497c80(uint8_t *param_1)



{

  int iVar1;

  void *pvVar2;

  

  iVar1 = *(int *)(param_1 + 0x10);

  while( true ) {

    if (iVar1 < 1) {

      FUN_00788db0(param_1 + 0x14,0xa0);

      *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

      FUN_007874b0(0,0);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

      *param_1 = 1;

      return 1;

    }

    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;

    pvVar2 = *(void **)(param_1 + *(int *)(param_1 + 0x10) * 4 + 0x14);

    if (pvVar2 != (void *)0x0) break;

    iVar1 = *(int *)(param_1 + 0x10);

  }

  FUN_00497900();

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
