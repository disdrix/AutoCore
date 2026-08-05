// =============================================================================
// Named_CalleeOf_Named_gfxShadowVolume_00990b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00990b80
// Callee of Named_gfxShadowVolume
// Address:   0x00990b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: FUN_0044c3c0×2, FUN_00746d00×2, FUN_00990b80.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxShadowVolume
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

void Named_CalleeOf_Named_gfxShadowVolume_00990b80(char param_1)



{

  int iVar1;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (param_1 != '\0') {

    FUN_0044c3c0(0,0);

    puVar2 = &DAT_00a241d8;

    puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 4);

    for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar3 = puVar3 + 1;

    }

    FUN_00746d00();

    return;

  }

  FUN_0044c3c0(0,0);

  puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 4);

  *puVar2 = DAT_00a24230;

  puVar2[1] = DAT_00a24234;

  puVar2[2] = DAT_00a24238;

  puVar2[3] = DAT_00a2423c;

  puVar2[4] = DAT_00a24240;

  puVar2[5] = DAT_00a24244;

  FUN_00746d00();

  return;

}
