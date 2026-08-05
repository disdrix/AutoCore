// =============================================================================
// FUN_0048d8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048d8e0
// Address:   0x0048d8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048d8e0 @ 0x0048d8e0
// Stable ID: aa_0048d8e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, do×1, while×1.
//  - Notable callees: FUN_0048d230, FUN_0048d8e0.
//  - Return sites: 4.

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

byte * FUN_0048d8e0(byte *param_1,byte *param_2,int *param_3,int param_4)



{

  byte *pbVar1;

  byte *pbVar2;

  int iVar3;

  

  if (param_4 == 1) {

    iVar3 = *(int *)(&DAT_009c7030 + (uint)*param_1 * 4);

    *param_3 = iVar3;

    if (iVar3 != 1) {

      if (iVar3 == 0) {

        return (byte *)0x0;

      }

      iVar3 = 0;

      if (*param_1 != 0) {

        pbVar2 = param_1;

        do {

          if (*param_3 <= iVar3) break;

          pbVar2[(int)param_2 - (int)param_1] = *pbVar2;

          pbVar1 = pbVar2 + 1;

          iVar3 = iVar3 + 1;

          pbVar2 = pbVar2 + 1;

        } while (*pbVar1 != 0);

      }

      return param_1 + *param_3;

    }

  }

  else {

    *param_3 = 1;

  }

  if (*param_1 != 0x26) {

    *param_2 = *param_1;

    return param_1 + 1;

  }

  pbVar2 = (byte *)FUN_0048d230(param_1,param_2,param_3,param_4);

  return pbVar2;

}
