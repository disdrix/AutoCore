// =============================================================================
// FUN_005c4e30
// -----------------------------------------------------------------------------
// Stable ID: aa_005c4e30
// Address:   0x005c4e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c4e30 @ 0x005c4e30
// Stable ID: aa_005c4e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005c4e30.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005c4e30(int param_1,uint param_2)



{

  int iVar1;

  

  if (((-1 < (int)param_2) && (iVar1 = *(int *)(param_1 + 4), iVar1 != 0)) &&

     (param_2 < (uint)((*(int *)(param_1 + 8) - iVar1) / 0xc))) {

    return (uint32_t /* width from decompiler */ *)(iVar1 + param_2 * 0xc);

  }

  return &DAT_00d1a6c0;

}
