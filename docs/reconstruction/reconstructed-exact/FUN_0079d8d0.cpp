// =============================================================================
// FUN_0079d8d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079d8d0
// Address:   0x0079d8d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079d8d0 @ 0x0079d8d0
// Stable ID: aa_0079d8d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×6, goto×5, return×2, for×2, switch×1.
//  - Notable callees: CONCAT31, FUN_0079d8d0.
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

uint __thiscall

FUN_0079d8d0(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,float *param_6,

            float *param_7,float *param_8,float *param_9,uint32_t /* width from decompiler */ param_10)



{

  float *pfVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  switch(param_10) {

  case 1:

    uVar2 = *(uint *)(param_1 + 0x17c);

    if (*(int *)(param_1 + 0x178) < (int)(uVar2 + 6)) {

LAB_0079d99e:

      return uVar2 & 0xffffff00;

    }

    iVar4 = *(int *)(param_1 + 0x180);

    *(uint *)(param_1 + 0x17c) = uVar2 + 6;

    break;

  case 2:

    uVar2 = *(uint *)(param_1 + 400);

    if (*(int *)(param_1 + 0x18c) < (int)(uVar2 + 6)) goto LAB_0079d99e;

    iVar4 = *(int *)(param_1 + 0x194);

    *(uint *)(param_1 + 400) = uVar2 + 6;

    break;

  case 3:

    uVar2 = *(uint *)(param_1 + 0x1b8);

    if (*(int *)(param_1 + 0x1b4) < (int)(uVar2 + 6)) goto LAB_0079d99e;

    iVar4 = *(int *)(param_1 + 0x1bc);

    *(uint *)(param_1 + 0x1b8) = uVar2 + 6;

    break;

  case 4:

    uVar2 = *(uint *)(param_1 + 0x1a4);

    if (*(int *)(param_1 + 0x1a0) < (int)(uVar2 + 6)) goto LAB_0079d99e;

    iVar4 = *(int *)(param_1 + 0x1a8);

    *(uint *)(param_1 + 0x1a4) = uVar2 + 6;

    break;

  case 5:

    uVar2 = *(uint *)(param_1 + 0x1cc);

    if (*(int *)(param_1 + 0x1c8) < (int)(uVar2 + 6)) goto LAB_0079d99e;

    iVar4 = *(int *)(param_1 + 0x1d0);

    *(uint *)(param_1 + 0x1cc) = uVar2 + 6;

    break;

  default:

    uVar2 = *(uint *)(param_1 + 0x168);

    if (*(int *)(param_1 + 0x164) < (int)(uVar2 + 6)) goto LAB_0079d99e;

    iVar4 = *(int *)(param_1 + 0x16c);

    *(uint *)(param_1 + 0x168) = uVar2 + 6;

  }

  pfVar1 = (float *)(iVar4 + uVar2 * 0x1c);

  *pfVar1 = *param_6 + *param_2;

  pfVar1[1] = param_6[1] + param_2[1];

  pfVar1[2] = param_6[2] + param_2[2];

  pfVar1[4] = *param_5;

  pfVar1[5] = param_5[1];

  pfVar1[6] = 0.0;

  pfVar1[3] = *param_3;

  iVar3 = uVar2 + 1;

  *(float *)(iVar4 + iVar3 * 0x1c) = *param_7 + *param_2;

  *(float *)(iVar4 + 4 + iVar3 * 0x1c) = param_7[1] + param_2[1];

  *(float *)(iVar4 + 8 + iVar3 * 0x1c) = param_7[2] + param_2[2];

  *(float *)(iVar4 + 0x10 + iVar3 * 0x1c) = param_5[2];

  *(float *)(iVar4 + 0x14 + iVar3 * 0x1c) = param_5[1];

  iVar3 = iVar4 + iVar3 * 0x1c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18) = 0;

  *(float *)(iVar3 + 0xc) = *param_3;

  pfVar1 = (float *)(iVar4 + (uVar2 + 2) * 0x1c);

  *pfVar1 = *param_8 + *param_2;

  pfVar1[1] = param_8[1] + param_2[1];

  pfVar1[2] = param_8[2] + param_2[2];

  pfVar1[4] = *param_5;

  pfVar1[5] = param_5[3];

  pfVar1[6] = 0.0;

  pfVar1[3] = *param_4;

  puVar5 = (uint32_t /* width from decompiler */ *)(iVar4 + (uVar2 + 1) * 0x1c);

  puVar6 = (uint32_t /* width from decompiler */ *)(iVar4 + (uVar2 + 3) * 0x1c);

  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  pfVar1 = (float *)(iVar4 + (uVar2 + 4) * 0x1c);

  *pfVar1 = *param_9 + *param_2;

  pfVar1[1] = param_9[1] + param_2[1];

  pfVar1[2] = param_9[2] + param_2[2];

  pfVar1[4] = param_5[2];

  pfVar1[5] = param_5[3];

  pfVar1[6] = 0.0;

  pfVar1[3] = *param_4;

  puVar5 = (uint32_t /* width from decompiler */ *)(iVar4 + (uVar2 + 2) * 0x1c);

  puVar6 = (uint32_t /* width from decompiler */ *)(iVar4 + (uVar2 + 5) * 0x1c);

  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  return CONCAT31((int3)(uVar2 + 5 >> 8),1);

}
