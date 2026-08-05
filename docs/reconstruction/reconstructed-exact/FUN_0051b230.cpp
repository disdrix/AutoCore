// =============================================================================
// FUN_0051b230
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b230
// Address:   0x0051b230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051b230 @ 0x0051b230
// Stable ID: aa_0051b230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGReaction_GiveItemByCbid, FUN_00516720, FUN_0051b230.
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

int * __fastcall FUN_0051b230(int param_1)



{

  int *piVar1;

  

  piVar1 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(*(int *)(param_1 + 0xa8) + 0x34));

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))

              (*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xa8) + 0x34),*(uint32_t /* width from decompiler */ *)(param_1 + 0xa4),1);

    (**(code **)(*piVar1 + 0xb8))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8));

    FUN_00516720(*(uint32_t /* width from decompiler */ *)(param_1 + 0x158));

    piVar1[0x31] = *(int *)(param_1 + 0xc4);

  }

  return piVar1;

}
