// =============================================================================
// FUN_006028a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006028a0
// Address:   0x006028a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006028a0 @ 0x006028a0
// Stable ID: aa_006028a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, return×1.
//  - Notable callees: FUN_006028a0.
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

void FUN_006028a0(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  

  iVar1 = param_2;

  while( true ) {

    iVar2 = iVar1 * 2 + 2;

    if (param_3 <= iVar2) break;

    if (*(int *)(param_1 + iVar2 * 4) < *(int *)(param_1 + -4 + iVar2 * 4)) {

      iVar2 = iVar1 * 2 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar1 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 4);

    iVar1 = iVar2;

  }

  if (iVar2 == param_3) {

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar1 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + -4 + param_3 * 4);

    iVar1 = param_3 + -1;

  }

  while ((param_2 < iVar1 && (iVar2 = (iVar1 + -1) / 2, *(int *)(param_1 + iVar2 * 4) < param_4))) {

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar1 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 4);

    iVar1 = iVar2;

  }

  *(int *)(param_1 + iVar1 * 4) = param_4;

  return;

}
