// =============================================================================
// FUN_0070ff80
// -----------------------------------------------------------------------------
// Stable ID: aa_0070ff80
// Address:   0x0070ff80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070ff80 @ 0x0070ff80
// Stable ID: aa_0070ff80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×7, return×6, while×2, do×1.
//  - Notable callees: FUN_0070ff80.
//  - Return sites: 6.

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

int FUN_0070ff80(float param_1,float *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar1 = 0;

  iVar2 = param_3 + -1;

  if (3 < iVar2) {

    do {

      if (param_1 <= *param_2) {

        return iVar1;

      }

      if (param_1 <= param_2[1]) {

        return iVar1 + 1;

      }

      if (param_1 <= param_2[2]) {

        return iVar1 + 2;

      }

      if (param_1 <= param_2[3]) {

        return iVar1 + 3;

      }

      iVar1 = iVar1 + 4;

      param_2 = param_2 + 4;

    } while (iVar1 < param_3 + -4);

  }

  if (iVar1 < iVar2) {

    while (*param_2 < param_1) {

      param_2 = param_2 + 1;

      iVar1 = iVar1 + 1;

      if (iVar2 <= iVar1) {

        return iVar1;

      }

    }

  }

  return iVar1;

}
