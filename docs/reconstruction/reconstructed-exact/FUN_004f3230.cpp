// =============================================================================
// FUN_004f3230
// -----------------------------------------------------------------------------
// Stable ID: aa_004f3230
// Address:   0x004f3230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f3230 @ 0x004f3230
// Stable ID: aa_004f3230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_004f3230, malloc.
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

uint32_t /* width from decompiler */ * __thiscall FUN_004f3230(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar3 = param_2;

  puVar4 = param_1;

  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  param_1[9] = param_2[9];

  param_1[10] = param_2[10];

  param_1[0xb] = param_2[0xb];

  param_1[0xc] = param_2[0xc];

  param_1[0xd] = param_2[0xd];

  param_1[0xe] = param_2[0xe];

  *(uint16_t *)(param_1 + 0xf) = *(uint16_t *)(param_2 + 0xf);

  param_1[0x10] = param_2[0x10];

  param_1[0x11] = param_2[0x11];

  param_1[0x12] = param_2[0x12];

  param_1[0x13] = param_2[0x13];

  puVar1 = malloc(((int)(param_2[0x15] - param_2[0x14]) >> 2) * 4);

  param_1[0x14] = puVar1;

  puVar3 = (uint32_t /* width from decompiler */ *)param_2[0x15];

  for (puVar4 = (uint32_t /* width from decompiler */ *)param_2[0x14]; puVar4 != puVar3; puVar4 = puVar4 + 1) {

    *puVar1 = *puVar4;

    puVar1 = puVar1 + 1;

  }

  param_1[0x15] = puVar1;

  param_1[0x16] = puVar1;

  return param_1;

}
