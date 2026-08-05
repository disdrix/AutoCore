// =============================================================================
// FUN_00659640
// -----------------------------------------------------------------------------
// Stable ID: aa_00659640
// Address:   0x00659640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00659640 @ 0x00659640
// Stable ID: aa_00659640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~166 non-empty decompiler lines.
//  - Control keywords: if×7, do×4, while×4, return×1.
//  - Notable callees: FUN_005b3300, FUN_00659640.
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

void __thiscall FUN_00659640(int param_1,int *param_2)



{

  short *psVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int *piVar11;

  

  piVar4 = param_2;

  iVar2 = param_2[4];

  iVar10 = *(int *)(param_1 + 0xc);

  iVar5 = 0;

  if (0 < iVar2) {

    do {

      psVar1 = (short *)(*(int *)(param_2[3] + iVar5 * 4) + 6);

      *psVar1 = *psVar1 + 1;

      iVar5 = iVar5 + 1;

    } while (iVar5 < iVar2);

  }

  if (0 < iVar10) {

    iVar5 = 0;

    param_2 = (int *)iVar10;

    do {

      puVar3 = *(uint32_t /* width from decompiler */ **)(iVar5 + *(int *)(param_1 + 8));

      *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

      if (*(short *)((int)puVar3 + 6) == 0) {

        (**(code **)*puVar3)(1);

      }

      iVar5 = iVar5 + 0x50;

      param_2 = (int *)((int)param_2 + -1);

    } while (param_2 != (int *)0x0);

  }

  piVar11 = (int *)(param_1 + 8);

  uVar6 = *(uint *)(param_1 + 0x10) & 0x7fffffff;

  if ((int)uVar6 < iVar2) {

    iVar10 = uVar6 * 2;

    if (iVar10 <= iVar2) {

      iVar10 = iVar2;

    }

    FUN_005b3300(piVar11,iVar10,0x50);

  }

  iVar10 = 0;

  *(int *)(param_1 + 0xc) = iVar2;

  if (3 < iVar2) {

    iVar5 = 0;

    param_2 = (int *)0x0;

    do {

      puVar7 = (uint32_t /* width from decompiler */ *)(*piVar4 + (int)param_2);

      puVar3 = (uint32_t /* width from decompiler */ *)(*piVar11 + 0x10 + iVar5);

      *puVar3 = *puVar7;

      puVar3[1] = puVar7[1];

      puVar3[2] = puVar7[2];

      puVar3[3] = puVar7[3];

      puVar3[4] = puVar7[4];

      puVar3[5] = puVar7[5];

      puVar3[6] = puVar7[6];

      puVar3[7] = puVar7[7];

      puVar3[8] = puVar7[8];

      puVar3[9] = puVar7[9];

      puVar3[10] = puVar7[10];

      puVar3[0xb] = puVar7[0xb];

      puVar3[0xc] = puVar7[0xc];

      puVar3[0xd] = puVar7[0xd];

      puVar3[0xe] = puVar7[0xe];

      puVar3[0xf] = puVar7[0xf];

      *(uint32_t /* width from decompiler */ *)(iVar5 + *piVar11) = *(uint32_t /* width from decompiler */ *)(piVar4[3] + iVar10 * 4);

      iVar9 = *piVar4 + 0x40 + (int)param_2;

      iVar8 = *piVar11;

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x60 + iVar5) = *(uint32_t /* width from decompiler */ *)(*piVar4 + 0x40 + (int)param_2);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 100 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar9 + 4);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x68 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar9 + 8);

      iVar8 = iVar8 + 0x60 + iVar5;

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0xc) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0xc);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x10);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x14);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x1c);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x20);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x24);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x28);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x2c);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x30) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x30);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x34) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x34);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x38) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x38);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x3c) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x3c);

      *(uint32_t /* width from decompiler */ *)(*piVar11 + 0x50 + iVar5) = *(uint32_t /* width from decompiler */ *)(piVar4[3] + 4 + iVar10 * 4);

      iVar9 = (int)param_2 + 0x80 + *piVar4;

      iVar8 = *piVar11;

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0xb0 + iVar5) = *(uint32_t /* width from decompiler */ *)((int)param_2 + 0x80 + *piVar4);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0xb4 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar9 + 4);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0xb8 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar9 + 8);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0xbc + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0xc);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0xc0 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x10);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0xc4 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x14);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 200 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0xcc + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x1c);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0xd0 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x20);

      iVar8 = iVar8 + 0xb0 + iVar5;

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x24);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x28);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x2c);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x30) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x30);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x34) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x34);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x38) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x38);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x3c) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x3c);

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xa0 + *piVar11) = *(uint32_t /* width from decompiler */ *)(piVar4[3] + 8 + iVar10 * 4);

      iVar8 = *piVar4 + (int)param_2 + 0xc0;

      iVar9 = *piVar11;

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x100 + iVar5) = *(uint32_t /* width from decompiler */ *)(*piVar4 + (int)param_2 + 0xc0);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x104 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar8 + 4);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x108 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar8 + 8);

      iVar9 = iVar9 + 0x100 + iVar5;

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0xc) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0xc);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x10);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x14);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x18);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x1c);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x20);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x24);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x28);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x2c);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x30) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x30);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x34) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x34);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x38) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x38);

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x3c) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x3c);

      param_2 = (int *)((int)param_2 + 0x100);

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xf0 + *piVar11) = *(uint32_t /* width from decompiler */ *)(piVar4[3] + 0xc + iVar10 * 4);

      iVar10 = iVar10 + 4;

      iVar5 = iVar5 + 0x140;

    } while (iVar10 < iVar2 + -3);

  }

  if (iVar10 < iVar2) {

    iVar5 = iVar10 * 0x50;

    iVar9 = iVar10 << 6;

    do {

      puVar7 = (uint32_t /* width from decompiler */ *)(*piVar4 + iVar9);

      puVar3 = (uint32_t /* width from decompiler */ *)(iVar5 + 0x10 + *piVar11);

      *puVar3 = *puVar7;

      puVar3[1] = puVar7[1];

      puVar3[2] = puVar7[2];

      puVar3[3] = puVar7[3];

      puVar3[4] = puVar7[4];

      puVar3[5] = puVar7[5];

      puVar3[6] = puVar7[6];

      puVar3[7] = puVar7[7];

      puVar3[8] = puVar7[8];

      puVar3[9] = puVar7[9];

      puVar3[10] = puVar7[10];

      puVar3[0xb] = puVar7[0xb];

      puVar3[0xc] = puVar7[0xc];

      puVar3[0xd] = puVar7[0xd];

      puVar3[0xe] = puVar7[0xe];

      puVar3[0xf] = puVar7[0xf];

      *(uint32_t /* width from decompiler */ *)(iVar5 + *piVar11) = *(uint32_t /* width from decompiler */ *)(piVar4[3] + iVar10 * 4);

      iVar10 = iVar10 + 1;

      iVar9 = iVar9 + 0x40;

      iVar5 = iVar5 + 0x50;

    } while (iVar10 < iVar2);

  }

  return;

}
