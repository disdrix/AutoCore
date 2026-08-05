// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00774c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00774c50
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00774c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007701d0, FUN_00770490, FUN_00773600, FUN_00774c50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ecc_sys
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

void Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00774c50(int *param_1)



{

  int iVar1;

  int *in_EAX;

  int iVar2;

  int iVar3;

  

  iVar1 = *param_1;

  FUN_007701d0();

  iVar2 = (iVar1 * 0x38) / 0x1c;

  iVar3 = FUN_00770490();

  if (iVar3 == 0) {

    *in_EAX = iVar2 + 1;

    *(int *)(in_EAX[3] + iVar2 * 4) = 1 << ((byte)((iVar1 * 0x38) % 0x1c) & 0x1f);

    FUN_00773600();

  }

  return;

}
