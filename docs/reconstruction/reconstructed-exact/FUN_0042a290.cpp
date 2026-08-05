// =============================================================================
// FUN_0042a290
// -----------------------------------------------------------------------------
// Stable ID: aa_0042a290
// Address:   0x0042a290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042a290 @ 0x0042a290
// Stable ID: aa_0042a290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_0042a290, FUN_005b3300.
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

int * __thiscall FUN_0042a290(int *param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  iVar1 = param_1[1];

  iVar2 = 0;

  if (0 < iVar1) {

    piVar4 = (int *)*param_1;

    do {

      if (*piVar4 == *param_2) {

        return (int *)*param_1 + iVar2 * 2 + 1;

      }

      iVar2 = iVar2 + 1;

      piVar4 = piVar4 + 2;

    } while (iVar2 < param_1[1]);

  }

  iVar2 = iVar1 + 1;

  if ((int)(param_1[2] & 0x7fffffffU) < iVar2) {

    iVar3 = (param_1[2] & 0x7fffffffU) * 2;

    if (iVar3 <= iVar2) {

      iVar3 = iVar2;

    }

    FUN_005b3300(param_1,iVar3,8);

  }

  param_1[1] = iVar2;

  piVar4 = (int *)(*param_1 + iVar1 * 8);

  *piVar4 = *param_2;

  return piVar4 + 1;

}
