// =============================================================================
// FUN_00530550
// -----------------------------------------------------------------------------
// Stable ID: aa_00530550
// Address:   0x00530550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00530550 @ 0x00530550
// Stable ID: aa_00530550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0051a0e0×2, CVOGReaction_FailMissionNotify, FUN_005304a0, FUN_00530550.
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

uint32_t /* width from decompiler */ __thiscall FUN_00530550(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  

  uVar1 = param_2;

  iVar2 = FUN_0051a0e0(param_2);

  if (iVar2 != 0) {

    CVOGReaction_FailMissionNotify(&param_2);

    *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x20;

    iVar2 = FUN_0051a0e0(uVar1);

    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x14) != -1)) {

      FUN_005304a0(*(int *)(iVar2 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x18),0);

    }

    return 1;

  }

  return 0;

}
