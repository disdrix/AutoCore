// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_00453030
// -----------------------------------------------------------------------------
// Stable ID: aa_00453030
// Callee of Named_CalleeOf_Named_gfxShadowVolume
// Address:   0x00453030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00453030.
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_00453030(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EBX;

  int iVar3;

  

  puVar1 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 8);

  iVar3 = 7;

  puVar2 = in_EAX;

  do {

    *puVar2 = puVar1[-2];

    puVar2[1] = puVar1[-1];

    *(uint32_t /* width from decompiler */ *)(((int)in_EAX - unaff_EBX) + (int)puVar1) = *puVar1;

    puVar2 = puVar2 + 3;

    puVar1 = puVar1 + 3;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  in_EAX[0x15] = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x54);

  in_EAX[0x16] = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x58);

  return;

}
