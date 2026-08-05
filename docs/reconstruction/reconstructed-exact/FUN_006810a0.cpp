// =============================================================================
// FUN_006810a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006810a0
// Address:   0x006810a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006810a0 @ 0x006810a0
// Stable ID: aa_006810a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_00680e80, FUN_006810a0.
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

uint32_t /* width from decompiler */ __thiscall FUN_006810a0(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if ((uint)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) - *(int *)(param_1 + 0x10)) < param_3

     ) {

    FUN_00680e80(*(int *)(param_1 + 0xc) + param_3);

  }

  puVar2 = (uint32_t /* width from decompiler */ *)

           (*(int *)(param_1 + 4) + *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10));

  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

    *puVar2 = *param_2;

    param_2 = param_2 + 1;

    puVar2 = puVar2 + 1;

  }

  for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

    *(uint8_t *)puVar2 = *(uint8_t *)param_2;

    param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

  }

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

}
