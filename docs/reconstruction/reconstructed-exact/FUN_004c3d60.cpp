// =============================================================================
// FUN_004c3d60
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3d60
// Address:   0x004c3d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c3d60 @ 0x004c3d60
// Stable ID: aa_004c3d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: CONCAT31, FUN_00404dc0, FUN_004c3d60, FUN_007971b0.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_004c3d60(int *param_1,uint32_t /* width from decompiler */ *param_2,char param_3)



{

  int iVar1;

  float *pfVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  iVar1 = param_1[2];

  if (iVar1 == 0) {

    pfVar2 = (float *)(*(int *)(param_1[1] + 4) + 0x94 + (int)param_1);

  }

  else {

    pfVar2 = (float *)(*(int *)(iVar1 + 0x3c) + 0x30);

  }

  if (((*pfVar2 * *pfVar2 + pfVar2[1] * pfVar2[1] + pfVar2[2] * pfVar2[2] < DAT_009cb8d4) &&

      (iVar1 != 0)) && ((*(char *)(iVar1 + 0x40) == '\0' || (*(int *)(iVar1 + 8) == 0)))) {

    FUN_00404dc0(&DAT_00b037c0);

  }

  if (param_3 == '\0') {

    uVar3 = (**(code **)(*param_1 + 0x38))();

    if ((char)uVar3 == '\0') {

      return uVar3;

    }

  }

  *param_2 = 0x2008;

  puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1[1] + 4) + 0x164 + (int)param_1);

  param_2[2] = *puVar4;

  param_2[3] = puVar4[1];

  param_2[4] = puVar4[2];

  param_2[5] = puVar4[3];

  iVar1 = *(int *)(*(int *)(param_1[1] + 4) + 0xa4 + (int)param_1);

  if (iVar1 == 0) {

    param_2[0x18] = DAT_009cb8c0;

    param_2[0x19] = DAT_009cb8c4;

    param_2[0x1a] = DAT_009cb8c8;

    uVar3 = DAT_009cb8cc;

  }

  else {

    param_2[0x18] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x160);

    param_2[0x19] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164);

    param_2[0x1a] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168);

    uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x16c);

  }

  param_2[0x1b] = uVar3;

  if (param_1[2] == 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1[1] + 4) + 0x84 + (int)param_1);

  }

  else {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1[2] + 0x3c) + 0xb0);

  }

  param_2[6] = *puVar4;

  param_2[7] = puVar4[1];

  param_2[8] = puVar4[2];

  if (param_1[2] != 0) {

    FUN_007971b0(*(int *)(param_1[2] + 0x3c) + 0x30);

    iVar1 = *(int *)(param_1[2] + 0x3c);

    param_2[9] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x40);

    param_2[10] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x44);

    param_2[0xb] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x48);

  }

  if ((*(byte *)(*(int *)(param_1[1] + 4) + 0xb8 + (int)param_1) & 7) == 0) {

    param_1 = param_1 + 0x90;

  }

  else if (param_1[2] == 0) {

    param_1 = (int *)((int)param_1 + *(int *)(param_1[1] + 4) + 0x84);

  }

  else {

    param_1 = (int *)(*(int *)(param_1[2] + 0x3c) + 0xb0);

  }

  param_2[0x14] = *param_1;

  param_2[0x15] = param_1[1];

  iVar1 = param_1[2];

  param_2[0x16] = iVar1;

  return CONCAT31((int3)((uint)iVar1 >> 8),1);

}
