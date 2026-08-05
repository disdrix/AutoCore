// =============================================================================
// FUN_0090db30
// -----------------------------------------------------------------------------
// Stable ID: aa_0090db30
// Address:   0x0090db30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090db30 @ 0x0090db30
// Stable ID: aa_0090db30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007907b0, FUN_0090db30.
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

uint8_t __thiscall FUN_0090db30(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint8_t uVar1;

  uint32_t /* width from decompiler */ uStack_20;

  uint8_t auStack_10 [8];

  uint8_t local_8 [8];

  

  uStack_20 = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x554) = 0;

  *(uint8_t *)(param_1 + 0x50c) = 1;

  uVar1 = FUN_007907b0();

  if ((DAT_00d1b1f8 != (int *)0x0) && (DAT_00d1b1f8[0xac] != 0)) {

    uStack_20 = 1;

    (**(code **)(*DAT_00d1b1f8 + 0x140))(local_8);

    (**(code **)(*DAT_00d1b1f8 + 0x140))(auStack_10,1);

    (**(code **)(*DAT_00d1b1f8 + 0x11c))(&uStack_20);

  }

  return uVar1;

}
