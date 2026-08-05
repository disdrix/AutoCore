// =============================================================================
// FUN_005a6630
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6630
// Address:   0x005a6630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a6630 @ 0x005a6630
// Stable ID: aa_005a6630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_005a6630.
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

void __thiscall FUN_005a6630(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0x14) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2;

    }

    if (iVar1 <= iVar2) break;

    if (*(int *)(*(int *)(param_1 + 0x14) + iVar2 * 4) == param_2) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + iVar2 * 4) = 0;

    }

    iVar2 = iVar2 + 1;

  }

  return;

}
