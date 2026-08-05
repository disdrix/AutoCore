// =============================================================================
// FUN_00521510
// -----------------------------------------------------------------------------
// Stable ID: aa_00521510
// Address:   0x00521510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00521510 @ 0x00521510
// Stable ID: aa_00521510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT44×2, FUN_00521510, FUN_00575870.
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

longlong __thiscall FUN_00521510(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  longlong lVar2;

  

  if (*(int *)(param_1 + 0xcb0) == 0) {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

    return CONCAT44(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1),

                    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_1));

  }

  lVar2 = FUN_00575870(param_1,param_2);

  if (lVar2 == -1) {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

    lVar2 = CONCAT44(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1),

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_1));

  }

  return lVar2;

}
