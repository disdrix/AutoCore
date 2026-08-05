// =============================================================================
// FUN_0040d0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d0e0
// Address:   0x0040d0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040d0e0 @ 0x0040d0e0
// Stable ID: aa_0040d0e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0040d0e0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040d0e0; evidence only — no invented semantics):
//  - Entry: `void __thiscall FUN_0040d0e0(float *param_1,float *param_2)`.
//  - Branches: if ((_DAT_00a240ec <= fVar3) || (fVar3 <= DAT_00aaa640)).
//  - Writes: *param_1 = 0.0 - *param_2; param_1[1] = 0.0 - fVar1; param_1[2] = 0.0 - param_2[2].
//  - Returns (1 site(s)): `void`.




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



void __thiscall FUN_0040d0e0(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar3 = *param_2 * *param_2 + param_2[1] * param_2[1] + param_2[2] * param_2[2] +

          param_2[3] * param_2[3];

  if ((_DAT_00a240ec <= fVar3) || (fVar3 <= DAT_00aaa640)) {

    *param_1 = 0.0 - *param_2;

    fVar1 = param_2[1];

    param_1[1] = 0.0 - fVar1;

    param_1[2] = 0.0 - param_2[2];

    fVar2 = param_2[3];

    fVar3 = g_flOne / fVar3;

    *param_1 = *param_1 * fVar3;

    param_1[1] = (0.0 - fVar1) * fVar3;

    param_1[3] = fVar2;

    param_1[2] = param_1[2] * fVar3;

    param_1[3] = param_1[3] * fVar3;

  }

  return;

}
