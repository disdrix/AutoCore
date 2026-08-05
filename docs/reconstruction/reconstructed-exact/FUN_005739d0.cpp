// =============================================================================
// FUN_005739d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005739d0
// Address:   0x005739d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005739d0 @ 0x005739d0
// Stable ID: aa_005739d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_005739d0.
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

uint32_t /* width from decompiler */ __thiscall FUN_005739d0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  while( true ) {

    if (*(int *)(param_1 + 8) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2;

    }

    if (iVar1 <= iVar2) break;

    iVar1 = *(int *)(*(int *)(param_1 + 8) + iVar2 * 4);

    if ((*(int *)(iVar1 + 8) == param_2) && (*(int *)(iVar1 + 0xc) == param_3)) {

      return *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + iVar2 * 4);

    }

    iVar2 = iVar2 + 1;

  }

  return 0;

}
