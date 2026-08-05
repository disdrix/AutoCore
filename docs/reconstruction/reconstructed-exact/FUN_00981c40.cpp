// =============================================================================
// FUN_00981c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00981c40
// Address:   0x00981c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00981c40 @ 0x00981c40
// Stable ID: aa_00981c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: SQRT×2, FUN_00981c40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_00981c40(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  int unaff_ESI;

  

  *(float *)(unaff_ESI + 8) = *param_1;

  *(float *)(unaff_ESI + 0xc) = param_1[1];

  *(float *)(unaff_ESI + 0x10) = param_1[2];

  *(float *)(unaff_ESI + 0x14) = *param_2;

  *(float *)(unaff_ESI + 0x18) = param_2[1];

  *(float *)(unaff_ESI + 0x1c) = param_2[2];

  fVar1 = *(float *)(unaff_ESI + 0x14);

  fVar2 = *(float *)(unaff_ESI + 8);

  *(float *)(unaff_ESI + 4) =

       SQRT(*(float *)(unaff_ESI + 0x10) * *(float *)(unaff_ESI + 0x10) +

            *(float *)(unaff_ESI + 0xc) * *(float *)(unaff_ESI + 0xc) + fVar2 * fVar2) +

       SQRT(*(float *)(unaff_ESI + 0x1c) * *(float *)(unaff_ESI + 0x1c) +

            *(float *)(unaff_ESI + 0x18) * *(float *)(unaff_ESI + 0x18) + fVar1 * fVar1);

  return;

}
