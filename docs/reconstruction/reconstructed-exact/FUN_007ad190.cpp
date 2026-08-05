// =============================================================================
// FUN_007ad190
// -----------------------------------------------------------------------------
// Stable ID: aa_007ad190
// Address:   0x007ad190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ad190 @ 0x007ad190
// Stable ID: aa_007ad190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: ROUND×4, FUN_007ad190.
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

void __fastcall FUN_007ad190(int *param_1)



{

  int iVar1;

  int *piVar2;

  float fVar3;

  float fVar4;

  

  if (*(char *)((int)param_1 + 0xd7) != '\0') {

    iVar1 = (**(code **)(*param_1 + 700))();

    if (iVar1 != 0) {

      piVar2 = (int *)(**(code **)(*param_1 + 700))();

      iVar1 = *(int *)(*piVar2 + 0x20);

      fVar3 = (float)*(int *)(*piVar2 + 0x1c);

      if ((char)param_1[0x72] == '\0') {

        fVar4 = (float)iVar1;

        param_1[0x60] = (int)ROUND((float)param_1[0x73] * fVar3);

        param_1[0x61] = (int)ROUND((float)param_1[0x75] * fVar4);

        param_1[0x62] = (int)ROUND((float)param_1[0x74] * fVar3);

        param_1[99] = (int)ROUND((float)param_1[0x76] * fVar4);

        return;

      }

      param_1[0x73] = (int)((float)param_1[0x60] / fVar3);

      fVar4 = (float)iVar1;

      param_1[0x75] = (int)((float)param_1[0x61] / fVar4);

      param_1[0x74] = (int)((float)param_1[0x62] / fVar3);

      param_1[0x76] = (int)((float)param_1[99] / fVar4);

    }

  }

  return;

}
