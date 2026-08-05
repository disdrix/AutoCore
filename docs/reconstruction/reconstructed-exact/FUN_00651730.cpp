// =============================================================================
// FUN_00651730
// -----------------------------------------------------------------------------
// Stable ID: aa_00651730
// Address:   0x00651730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00651730 @ 0x00651730
// Stable ID: aa_00651730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_005b3370, FUN_00651730.
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

int __thiscall FUN_00651730(int *param_1,uint8_t param_2)



{

  int iVar1;

  

  iVar1 = param_1[1] - 1;

  if (-1 < iVar1) {

    do {

      if (*(char *)(*param_1 + iVar1) == -1) {

        *(uint8_t *)(*param_1 + iVar1) = param_2;

        return iVar1;

      }

      iVar1 = iVar1 + -1;

    } while (-1 < iVar1);

  }

  if (param_1[1] == (param_1[2] & 0x7fffffffU)) {

    FUN_005b3370(param_1,1);

  }

  *(uint8_t *)(*param_1 + param_1[1]) = param_2;

  param_1[1] = param_1[1] + 1;

  return param_1[1] + -1;

}
