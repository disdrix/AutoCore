// =============================================================================
// FUN_00717d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00717d60
// Address:   0x00717d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00717d60 @ 0x00717d60
// Stable ID: aa_00717d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00717d60, ROUND.
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

void FUN_00717d60(float param_1,float param_2,float param_3,float *param_4,int param_5,

                 float *param_6,float param_7,int param_8,float *param_9)



{

  float fVar1;

  float *pfVar2;

  int iVar3;

  

  for (; param_2 <= param_3; param_2 = param_1 + param_2) {

    fVar1 = param_7;

    if (0 < param_5) {

      pfVar2 = param_6;

      iVar3 = param_5;

      do {

        iVar3 = iVar3 + -1;

        fVar1 = *(float *)(PTR_DAT_00af8b14 +

                          (*(int *)((param_8 - (int)param_6) + (int)pfVar2) *

                           (int)ROUND(param_2 * DAT_00a1401c) + 0x800000U >> 0x18) * 4) * *pfVar2 +

                fVar1;

        pfVar2 = pfVar2 + 1;

      } while (iVar3 != 0);

    }

    if (*param_4 < fVar1) {

      *param_4 = fVar1;

      *param_9 = param_2;

    }

  }

  return;

}
