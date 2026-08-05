// =============================================================================
// FUN_006425c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006425c0
// Address:   0x006425c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006425c0 @ 0x006425c0
// Stable ID: aa_006425c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00641680, FUN_006416b0, FUN_00641860, FUN_00641870, FUN_00641900, FUN_00641ad0, FUN_006425c0.
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

uint32_t /* width from decompiler */ __thiscall FUN_006425c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint extraout_ECX;

  

  FUN_006416b0(0);

  FUN_00641900(param_2);

  uVar1 = FUN_00641ad0();

  if (*(int *)(param_1 + 0x24) != 0) {

    FUN_00641870(*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),extraout_ECX & 0xffffff00);

    FUN_00641860(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    FUN_00641680();

  }

  return uVar1;

}
