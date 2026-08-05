// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_00452f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00452f40
// Callee of Named_CalleeOf_Named_gfxShadowVolume
// Address:   0x00452f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00452f40, FUN_00453070.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxShadowVolume
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_00452f40(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  *unaff_ESI = *param_1;

  unaff_ESI[1] = param_1[1];

  unaff_ESI[2] = param_1[2];

  unaff_ESI[3] = param_1[3];

  unaff_ESI[4] = param_1[4];

  unaff_ESI[5] = param_1[5];

  unaff_ESI[6] = *in_EAX;

  unaff_ESI[7] = in_EAX[1];

  unaff_ESI[8] = in_EAX[2];

  unaff_ESI[9] = in_EAX[3];

  unaff_ESI[10] = in_EAX[4];

  FUN_00453070(unaff_ESI + 0xb);

  return;

}
