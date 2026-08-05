// =============================================================================
// FUN_00435040
// -----------------------------------------------------------------------------
// Stable ID: aa_00435040
// Address:   0x00435040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00435040 @ 0x00435040
// Stable ID: aa_00435040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×2.
//  - Notable callees: FUN_00435040, FUN_004351f0.
//  - Return sites: 4.

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

int __thiscall FUN_00435040(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,int param_4)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (*(int *)(param_1 + 4) == 0) {

    return 0;

  }

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    return 0;

  }

  uVar2 = param_3 * param_4;

  if (uVar2 == 0) {

    return 0;

  }

  if (*(int *)(param_1 + 0x14) < (int)(*(int *)(param_1 + 0x10) + uVar2)) {

    FUN_004351f0();

  }

  puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 4));

  for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

    *puVar3 = *param_2;

    param_2 = param_2 + 1;

    puVar3 = puVar3 + 1;

  }

  for (uVar1 = uVar2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

    *(uint8_t *)puVar3 = *(uint8_t *)param_2;

    param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

  }

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar2;

  if (*(int *)(param_1 + 8) < *(int *)(param_1 + 0x10)) {

    *(int *)(param_1 + 8) = *(int *)(param_1 + 0x10);

  }

  return param_4;

}
