// =============================================================================
// FUN_00734550
// -----------------------------------------------------------------------------
// Stable ID: aa_00734550
// Address:   0x00734550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00734550 @ 0x00734550
// Stable ID: aa_00734550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00734550.
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

uint32_t /* width from decompiler */ __fastcall FUN_00734550(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  

  iVar2 = DAT_00d1f614;

  if (DAT_00d1f614 != 0) {

    piVar1 = (int *)(DAT_00d1f614 + 0xe0 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

    *piVar1 = *piVar1 + 1;

  }

  if (*(int *)(unaff_ESI + 0xc) != param_2) {

    *(int *)(unaff_ESI + 0xc) = param_2;

    if (iVar2 != 0) {

      piVar1 = (int *)(iVar2 + 0xdc + *(int *)(iVar2 + 0xc4) * 0x4c);

      *piVar1 = *piVar1 + 1;

    }

    uVar3 = (**(code **)(**(int **)(unaff_ESI + 8) + 0x15c))(*(int **)(unaff_ESI + 8),param_2);

    return uVar3;

  }

  return 0;

}
