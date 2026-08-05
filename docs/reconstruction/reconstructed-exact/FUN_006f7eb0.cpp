// =============================================================================
// FUN_006f7eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f7eb0
// Address:   0x006f7eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f7eb0 @ 0x006f7eb0
// Stable ID: aa_006f7eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_006f7eb0.
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

void __thiscall FUN_006f7eb0(int param_1,uint8_t *param_2,short *param_3)



{

  int iVar1;

  short *psVar2;

  

  iVar1 = *(int *)(param_1 + 0x54) + -1;

  if (-1 < iVar1) {

    psVar2 = (short *)(param_1 + 0x22 + iVar1 * 6);

    do {

      if ((psVar2[-1] == *param_3) && (*psVar2 == param_3[1])) {

        *param_2 = 1;

        return;

      }

      iVar1 = iVar1 + -1;

      psVar2 = psVar2 + -3;

    } while (-1 < iVar1);

  }

  *param_2 = 0;

  return;

}
