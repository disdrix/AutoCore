// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_matD3DXMathEmu_007663b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007663b0
// Callee of Named_CalleeOf_Named_matD3DXMathEmu
// Address:   0x007663b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_matD3DXMathEmu: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_007663b0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_matD3DXMathEmu
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

void Named_CalleeOf_Named_CalleeOf_Named_matD3DXMathEmu_007663b0(float *param_1)



{

  float *pfVar1;

  float *in_EAX;

  float *pfVar2;

  float *pfVar3;

  float *unaff_ESI;

  

  pfVar2 = unaff_ESI;

  if ((*unaff_ESI < *in_EAX || *unaff_ESI == *in_EAX) &&

     (pfVar2 = param_1, *in_EAX < *param_1 || *in_EAX == *param_1)) {

    pfVar2 = in_EAX;

  }

  *in_EAX = *pfVar2;

  pfVar2 = in_EAX + 1;

  pfVar1 = param_1 + 1;

  pfVar3 = unaff_ESI + 1;

  if ((unaff_ESI[1] < in_EAX[1] || unaff_ESI[1] == in_EAX[1]) &&

     (pfVar3 = pfVar1, *pfVar2 < *pfVar1 || *pfVar2 == *pfVar1)) {

    pfVar3 = pfVar2;

  }

  *pfVar2 = *pfVar3;

  pfVar2 = in_EAX + 2;

  pfVar1 = param_1 + 2;

  pfVar3 = unaff_ESI + 2;

  if ((unaff_ESI[2] < in_EAX[2] || unaff_ESI[2] == in_EAX[2]) &&

     (pfVar3 = pfVar1, *pfVar2 < *pfVar1 || *pfVar2 == *pfVar1)) {

    pfVar3 = pfVar2;

  }

  *pfVar2 = *pfVar3;

  if (unaff_ESI[3] < in_EAX[3] || unaff_ESI[3] == in_EAX[3]) {

    if (in_EAX[3] < param_1[3] || in_EAX[3] == param_1[3]) {

      in_EAX[3] = in_EAX[3];

      return;

    }

    in_EAX[3] = param_1[3];

    return;

  }

  in_EAX[3] = unaff_ESI[3];

  return;

}
