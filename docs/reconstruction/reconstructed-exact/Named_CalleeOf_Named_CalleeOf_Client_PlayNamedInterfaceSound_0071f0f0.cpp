// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_0071f0f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f0f0
// Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
// Address:   0x0071f0f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PlayNamedInterfaceSound: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0071f060, FUN_0071f0f0, ov_pcm_seek, ov_raw_seek.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_0071f0f0(void)



{

  int iVar1;

  int unaff_ESI;

  

  iVar1 = ov_raw_seek(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40),0,0);

  if (iVar1 != 0) {

    FUN_0071f060();

    return 0x80004005;

  }

  iVar1 = *(int *)(unaff_ESI + 0x40);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc) = 0;

  ov_pcm_seek(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40),0,0);

  return 0;

}
