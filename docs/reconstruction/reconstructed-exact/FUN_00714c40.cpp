// =============================================================================
// FUN_00714c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00714c40
// Address:   0x00714c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714c40 @ 0x00714c40
// Stable ID: aa_00714c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00714cc0×2, FUN_00714c40.
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

void FUN_00714c40(float *param_1,int param_2,float param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float10 fVar3;

  

  fVar1 = param_3 * *param_1;

  fVar3 = (float10)FUN_00714cc0(fVar1);

  *param_4 = (float)fVar3;

  param_2 = param_2 + -1;

  if (0 < param_2) {

    do {

      param_1 = param_1 + 1;

      fVar2 = param_3 * *param_1;

      if (fVar2 == fVar1) {

        fVar3 = (float10)*param_4;

      }

      else {

        fVar3 = (float10)FUN_00714cc0(fVar2);

      }

      param_4[1] = (float)fVar3;

      param_2 = param_2 + -1;

      fVar1 = fVar2;

      param_4 = param_4 + 1;

    } while (param_2 != 0);

  }

  return;

}
