// =============================================================================
// FUN_00626460
// -----------------------------------------------------------------------------
// Stable ID: aa_00626460
// Address:   0x00626460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00626460 @ 0x00626460
// Stable ID: aa_00626460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00578430, FUN_00626460, FUN_00797170.
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

void __thiscall FUN_00626460(int param_1,int param_2,int *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x40);

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x44);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d0) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d4) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6dc) = 0;

  FUN_00797170(param_1 + 0x6e0);

  *(uint8_t *)(param_1 + 0x6c8) = *(uint8_t *)(param_2 + 0x38);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4) = 0;

  uVar2 = (**(code **)(*param_3 + 0x1d8))();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c0) = uVar2;

  FUN_00578430(param_2,param_3);

  return;

}
