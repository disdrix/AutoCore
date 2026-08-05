// =============================================================================
// FUN_00476c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00476c70
// Address:   0x00476c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00476c70 @ 0x00476c70
// Stable ID: aa_00476c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_00476c70.
//  - Return sites: 3.

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

uint8_t __fastcall FUN_00476c70(int param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  

  if (((param_1 != 0) || (param_2 != (int *)0x0)) && (0 < *(int *)(param_1 + 0x220))) {

    iVar1 = *(int *)(param_1 + 0x220);

    piVar2 = (int *)(iVar1 * 5 + -5 + *(int *)(param_1 + 0x224));

    while( true ) {

      if (iVar1 == 0) {

        return 0;

      }

      if (*param_2 == *piVar2) break;

      iVar1 = iVar1 + -1;

      piVar2 = (int *)((int)piVar2 + -5);

    }

    return (char)piVar2[1];

  }

  return 0;

}
