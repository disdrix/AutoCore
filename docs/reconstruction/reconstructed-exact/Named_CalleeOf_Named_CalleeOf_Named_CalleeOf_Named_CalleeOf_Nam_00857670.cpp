// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00857670
// -----------------------------------------------------------------------------
// Stable ID: aa_00857670
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis
// Address:   0x00857670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00857670.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00857670(void)



{

  int *piVar1;

  int iVar2;

  int *unaff_ESI;

  uint8_t *puStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint8_t local_8 [8];

  

  puStack_10 = local_8;

  uStack_c = 1;

  uStack_14 = 0x857684;

  piVar1 = (int *)(**(code **)(*unaff_ESI + 0x140))();

  unaff_ESI[0x15c] = *piVar1 / 2;

  uStack_14 = 1;

  uStack_1c = 0x8576a2;

  puStack_18 = (uint8_t *)&puStack_10;

  iVar2 = (**(code **)(*unaff_ESI + 0x140))();

  unaff_ESI[0x15d] = *(int *)(iVar2 + 4) / 2;

  unaff_ESI[0x15a] = unaff_ESI[0x15c];

  unaff_ESI[0x15b] = unaff_ESI[0x15d];

  if ((int *)unaff_ESI[0x1a5] != (int *)0x0) {

    uStack_1c = 1;

    puStack_20 = (uint8_t *)&puStack_18;

    piVar1 = (int *)(**(code **)(*(int *)unaff_ESI[0x1a5] + 0x140))();

    unaff_ESI[0x15e] = *piVar1 / 2;

    iVar2 = (**(code **)(*(int *)unaff_ESI[0x1a5] + 0x140))(&puStack_20,1);

    unaff_ESI[0x15f] = *(int *)(iVar2 + 4) / 2;

    return;

  }

  unaff_ESI[0x15e] = 0;

  unaff_ESI[0x15f] = 0;

  return;

}
