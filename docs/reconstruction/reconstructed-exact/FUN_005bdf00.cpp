// =============================================================================
// FUN_005bdf00
// -----------------------------------------------------------------------------
// Stable ID: aa_005bdf00
// Address:   0x005bdf00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005bdf00 @ 0x005bdf00
// Stable ID: aa_005bdf00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~130 non-empty decompiler lines.
//  - Control keywords: for×7, if×1, return×1.
//  - Notable callees: FUN_005bdea0, FUN_005bdf00.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005bdf00(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  *param_1 = *param_2;

  param_1[1] = param_2[1];

  param_1[2] = param_2[2];

  param_1[3] = param_2[3];

  param_1[4] = param_2[4];

  puVar2 = param_2 + 5;

  puVar3 = param_1 + 5;

  for (iVar1 = 0xf9; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar2 = param_2 + 0xfe;

  puVar3 = param_1 + 0xfe;

  for (iVar1 = 0xf9; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar2 = param_2 + 0x1f7;

  puVar3 = param_1 + 0x1f7;

  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  *(uint8_t *)(param_1 + 0x1fe) = *(uint8_t *)(param_2 + 0x1fe);

  *(uint8_t *)((int)param_1 + 0x7f9) = *(uint8_t *)((int)param_2 + 0x7f9);

  *(uint8_t *)((int)param_1 + 0x7fa) = *(uint8_t *)((int)param_2 + 0x7fa);

  *(uint8_t *)((int)param_1 + 0x7fb) = *(uint8_t *)((int)param_2 + 0x7fb);

  *(uint8_t *)(param_1 + 0x1ff) = *(uint8_t *)(param_2 + 0x1ff);

  *(uint8_t *)((int)param_1 + 0x7fd) = *(uint8_t *)((int)param_2 + 0x7fd);

  *(uint8_t *)((int)param_1 + 0x7fe) = *(uint8_t *)((int)param_2 + 0x7fe);

  *(uint8_t *)((int)param_1 + 0x7ff) = *(uint8_t *)((int)param_2 + 0x7ff);

  param_1[0x200] = param_2[0x200];

  param_1[0x201] = param_2[0x201];

  param_1[0x202] = param_2[0x202];

  param_1[0x203] = param_2[0x203];

  param_1[0x204] = param_2[0x204];

  param_1[0x205] = param_2[0x205];

  param_1[0x206] = param_2[0x206];

  param_1[0x207] = param_2[0x207];

  param_1[0x208] = param_2[0x208];

  param_1[0x209] = param_2[0x209];

  param_1[0x20a] = param_2[0x20a];

  param_1[0x20b] = param_2[0x20b];

  param_1[0x20c] = param_2[0x20c];

  param_1[0x20d] = param_2[0x20d];

  param_1[0x20e] = param_2[0x20e];

  param_1[0x20f] = param_2[0x20f];

  param_1[0x210] = param_2[0x210];

  param_1[0x211] = param_2[0x211];

  param_1[0x212] = param_2[0x212];

  param_1[0x213] = param_2[0x213];

  param_1[0x214] = param_2[0x214];

  param_1[0x215] = param_2[0x215];

  param_1[0x216] = param_2[0x216];

  param_1[0x217] = param_2[0x217];

  param_1[0x218] = param_2[0x218];

  param_1[0x219] = param_2[0x219];

  param_1[0x21a] = param_2[0x21a];

  param_1[0x21b] = param_2[0x21b];

  param_1[0x21c] = param_2[0x21c];

  param_1[0x21d] = param_2[0x21d];

  param_1[0x21e] = param_2[0x21e];

  param_1[0x21f] = param_2[0x21f];

  param_1[0x220] = param_2[0x220];

  param_1[0x221] = param_2[0x221];

  param_1[0x222] = param_2[0x222];

  param_1[0x223] = param_2[0x223];

  param_1[0x224] = param_2[0x224];

  param_1[0x225] = param_2[0x225];

  param_1[0x226] = param_2[0x226];

  param_1[0x227] = param_2[0x227];

  param_1[0x228] = param_2[0x228];

  param_1[0x229] = param_2[0x229];

  param_1[0x22a] = param_2[0x22a];

  param_1[0x22b] = param_2[0x22b];

  param_1[0x22c] = param_2[0x22c];

  param_1[0x22d] = param_2[0x22d];

  param_1[0x22e] = param_2[0x22e];

  param_1[0x22f] = param_2[0x22f];

  param_1[0x230] = param_2[0x230];

  param_1[0x231] = param_2[0x231];

  param_1[0x232] = param_2[0x232];

  param_1[0x233] = param_2[0x233];

  puVar2 = param_2 + 0x234;

  puVar3 = param_1 + 0x234;

  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar2 = param_2 + 0x264;

  puVar3 = param_1 + 0x264;

  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  param_1[0x26d] = param_2[0x26d];

  param_1[0x26e] = param_2[0x26e];

  param_1[0x26f] = param_2[0x26f];

  param_1[0x270] = param_2[0x270];

  param_1[0x271] = param_2[0x271];

  param_1[0x272] = param_2[0x272];

  puVar2 = param_2 + 0x273;

  puVar3 = param_1 + 0x273;

  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar2 = param_2 + 0x27c;

  puVar3 = param_1 + 0x27c;

  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  if (param_1 + 0x288 != param_2 + 0x288) {

    FUN_005bdea0(*(uint32_t /* width from decompiler */ *)param_2[0x289],(uint32_t /* width from decompiler */ *)param_2[0x289],param_2);

  }

  return param_1;

}
