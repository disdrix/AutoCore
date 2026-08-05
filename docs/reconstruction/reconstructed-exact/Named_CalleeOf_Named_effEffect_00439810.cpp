// =============================================================================
// Named_CalleeOf_Named_effEffect_00439810
// -----------------------------------------------------------------------------
// Stable ID: aa_00439810
// Callee of Named_effEffect (+5 other named callers)
// Address:   0x00439810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_effEffect (+5 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00439810, FUN_00767160.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_effEffect (+5 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_effEffect_00439810(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = *in_EAX;

  if (unaff_ESI[7] == 0) {

    uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&local_4,4);

    unaff_ESI[1] = unaff_ESI[1] | uVar1;

    return unaff_ESI[1];

  }

  uVar1 = FUN_00767160(&DAT_00a9d718,local_4);

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  unaff_ESI[8] = 0;

  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&DAT_00a97b84,2);

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  return unaff_ESI[1];

}
