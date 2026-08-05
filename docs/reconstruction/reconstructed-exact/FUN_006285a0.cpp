// =============================================================================
// FUN_006285a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006285a0
// Address:   0x006285a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006285a0 @ 0x006285a0
// Stable ID: aa_006285a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006285a0.
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

void __thiscall FUN_006285a0(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_1[0xf] + *(int *)(param_2 + 0x58) * 4) =

       *(uint32_t /* width from decompiler */ *)(param_1[0xf] + -4 + param_1[0x10] * 4);

  *(int *)(*(int *)(param_1[0xf] + *(int *)(param_2 + 0x58) * 4) + 0x58) = *(int *)(param_2 + 0x58);

  param_1[0x10] = param_1[0x10] + -1;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x58) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x44) = 0;

  iVar1 = *param_1;

  iVar2 = (**(code **)(**(int **)(param_2 + 0x3c) + 0x14))();

  (**(code **)(iVar1 + 0x10))(-iVar2);

  *(uint8_t *)(param_1 + 10) = 1;

  return;

}
