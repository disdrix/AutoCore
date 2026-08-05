// =============================================================================
// Named_CalleeOf_Named_gfxView_0075e7e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075e7e0
// Callee of Named_gfxView
// Address:   0x0075e7e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_0075e7e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxView
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

uint Named_CalleeOf_Named_gfxView_0075e7e0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int *piVar2;

  uint in_EAX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  piVar2 = DAT_00d1f048;

  if (*DAT_00d1f048 == unaff_ESI[2]) {

    return in_EAX & 0xffffff00;

  }

  (**(code **)(*(int *)*unaff_ESI + 0x94))((int *)*unaff_ESI,param_1,unaff_ESI[2]);

  (**(code **)(*(int *)*unaff_ESI + 0x9c))((int *)*unaff_ESI,unaff_ESI[3]);

  *piVar2 = unaff_ESI[2];

  iVar1 = unaff_ESI[3];

  piVar2[1] = iVar1;

  piVar2[2] = unaff_ESI[4];

  return CONCAT31((int3)((uint)iVar1 >> 8),1);

}
