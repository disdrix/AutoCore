// =============================================================================
// FUN_00635270
// -----------------------------------------------------------------------------
// Stable ID: aa_00635270
// Address:   0x00635270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00635270 @ 0x00635270
// Stable ID: aa_00635270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c2fb0×2, FUN_00635270, FUN_006c2f60, FUN_006c2f90.
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

void __thiscall FUN_00635270(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  

  uVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))();

  (**(code **)(**(int **)(param_1 + 0x20) + 0x18))();

  FUN_006c2fb0(param_2,param_3,uVar1,8);

  FUN_006c2f60(*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),*(uint32_t /* width from decompiler */ *)(param_1 + 0x28),param_3);

  (**(code **)(**(int **)(param_1 + 0x20) + 0x24))(param_2,param_3);

  FUN_006c2fb0(param_2,param_3,uVar1,8);

  FUN_006c2f90(param_3);

  return;

}
