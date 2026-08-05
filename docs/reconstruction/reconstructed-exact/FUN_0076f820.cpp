// =============================================================================
// FUN_0076f820
// -----------------------------------------------------------------------------
// Stable ID: aa_0076f820
// Address:   0x0076f820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076f820 @ 0x0076f820
// Stable ID: aa_0076f820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076f820.
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

void __fastcall FUN_0076f820(float *param_1,float *param_2)



{

  float *in_EAX;

  float *unaff_ESI;

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar1 = (unaff_ESI[2] - param_1[2]) * (*param_2 - *param_1) -

          (param_2[2] - param_1[2]) * (*unaff_ESI - *param_1);

  fVar3 = (param_2[2] - param_1[2]) * (unaff_ESI[1] - param_1[1]) -

          (param_2[1] - param_1[1]) * (unaff_ESI[2] - param_1[2]);

  fVar2 = (param_2[1] - param_1[1]) * (*unaff_ESI - *param_1) -

          (*param_2 - *param_1) * (unaff_ESI[1] - param_1[1]);

  in_EAX[1] = fVar1;

  in_EAX[2] = fVar2;

  *in_EAX = fVar3;

  in_EAX[3] = 0.0 - (param_1[2] * fVar2 + *param_1 * fVar3 + fVar1 * param_1[1]);

  return;

}
