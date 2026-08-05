// =============================================================================
// FUN_0076e540
// -----------------------------------------------------------------------------
// Stable ID: aa_0076e540
// Address:   0x0076e540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076e540 @ 0x0076e540
// Stable ID: aa_0076e540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0076e540, SQRT, fcos, fsin.
//  - Return sites: 2.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_0076e540(float *param_1)



{

  float fVar1;

  float *in_EAX;

  float10 fVar2;

  float fVar3;

  

  fVar2 = SQRT((float10)param_1[2] * (float10)param_1[2] +

               (float10)param_1[1] * (float10)param_1[1] + (float10)*param_1 * (float10)*param_1);

  fVar1 = (float)fVar2;

  fVar2 = (float10)fsin(fVar2);

  fVar3 = (float)fVar2;

  fVar2 = (float10)fcos((float10)fVar1);

  in_EAX[3] = (float)fVar2;

  if ((fVar3 < _DAT_00a240ec) && (DAT_00aaa640 < fVar3)) {

    *in_EAX = *param_1;

    in_EAX[1] = param_1[1];

    in_EAX[2] = param_1[2];

    return;

  }

  fVar3 = fVar3 / fVar1;

  *in_EAX = *param_1 * fVar3;

  in_EAX[1] = fVar3 * param_1[1];

  in_EAX[2] = fVar3 * param_1[2];

  return;

}
