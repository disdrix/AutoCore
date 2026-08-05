// =============================================================================
// FUN_005c8eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c8eb0
// Address:   0x005c8eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c8eb0 @ 0x005c8eb0
// Stable ID: aa_005c8eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00512af0, FUN_005c8eb0.
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

void __fastcall FUN_005c8eb0(int param_1)



{

  byte *pbVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  

  FUN_00512af0();

  uVar3 = (uint)*(ushort *)

                 (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -100 + param_1) +

                          0x3c) + 0x3f8);

  *(uint *)(param_1 + -0x2c) = uVar3;

  *(uint *)(param_1 + -0x30) = uVar3;

  if (uVar3 == 0) {

    pbVar1 = (byte *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x71 + param_1);

    *pbVar1 = *pbVar1 | 4;

  }

  uVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -100 + param_1

                                          ) + 0x3c) + 0x14))();

  *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xfc + param_1) = uVar2;

  return;

}
