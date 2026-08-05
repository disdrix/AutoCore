// =============================================================================
// FUN_00712f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00712f60
// Address:   0x00712f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712f60 @ 0x00712f60
// Stable ID: aa_00712f60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_00712f60.
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

void FUN_00712f60(float *param_1,int param_2,int param_3,float *param_4,int param_5)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  int iVar5;

  

  if (0 < param_5) {

    do {

      fVar3 = g_flZero;

      if (0 < param_2) {

        pfVar4 = param_1;

        iVar5 = param_2;

        do {

          pfVar1 = (float *)((param_3 - (int)param_1) + (int)pfVar4);

          fVar2 = *pfVar4;

          pfVar4 = pfVar4 + 1;

          iVar5 = iVar5 + -1;

          fVar3 = *pfVar1 * fVar2 + fVar3;

        } while (iVar5 != 0);

      }

      *param_4 = fVar3;

      param_4 = param_4 + 1;

      param_3 = param_3 + param_2 * 4;

      param_5 = param_5 + -1;

    } while (param_5 != 0);

  }

  return;

}
