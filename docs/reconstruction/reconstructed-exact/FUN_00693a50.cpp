// =============================================================================
// FUN_00693a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00693a50
// Address:   0x00693a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00693a50 @ 0x00693a50
// Stable ID: aa_00693a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006914a0, FUN_006933c0, FUN_00693a50.
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

void __thiscall FUN_00693a50(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x2c) <

      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x2c))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_006914a0(iVar1,1,param_2,param_1,param_2);

    *(int *)(param_1 + 8) = iVar1 + 0x2c;

    return;

  }

  FUN_006933c0(&param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

  return;

}
