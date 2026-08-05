// =============================================================================
// thunk_FUN_005fb100
// -----------------------------------------------------------------------------
// Stable ID: aa_0064fec0
// Address:   0x0064fec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void __thiscall thunk_FUN_005fb100(int param_1,uint32_t /* width from decompiler */ *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint32_t /* width from decompiler */ uVar4;
  uint32_t /* width from decompiler */ *puVar5;
  uint32_t /* width from decompiler */ *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);
  uVar3 = param_2[6] & 0x7fffffff;
  if ((int)uVar3 < *(int *)(param_1 + 0x14)) {
    if (-1 < (int)param_2[6]) {
      (**(code **)(*DAT_00b05060 + 0x14))(param_2[4],uVar3 * 4,0x12);
    }
    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_1 + 0x14) * 4,0x12);
    param_2[4] = uVar4;
    param_2[6] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);
  }
  param_2[5] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);
  iVar9 = *(int *)(param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = param_2[4];
  iVar7 = 0;
  if (3 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xc);
    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);
    iVar8 = (iVar9 - 4U >> 2) + 1;
    iVar7 = iVar8 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar1 - iVar2));
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  if (iVar7 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar7 * 4);
    iVar9 = iVar9 - iVar7;
    do {
      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar1 - iVar2));
      puVar6 = puVar6 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  uVar3 = param_2[9] & 0x7fffffff;
  if ((int)uVar3 < *(int *)(param_1 + 0x20)) {
    if (-1 < (int)param_2[9]) {
      (**(code **)(*DAT_00b05060 + 0x14))(param_2[7],uVar3 * 4,0x12);
    }
    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_1 + 0x20) * 4,0x12);
    param_2[7] = uVar4;
    param_2[9] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);
  }
  param_2[8] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);
  iVar9 = *(int *)(param_1 + 0x20);
  iVar1 = *(int *)(param_1 + 0x1c);
  iVar2 = param_2[7];
  iVar7 = 0;
  if (3 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xc);
    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);
    iVar8 = (iVar9 - 4U >> 2) + 1;
    iVar7 = iVar8 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar1 - iVar2));
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  if (iVar7 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar7 * 4);
    iVar9 = iVar9 - iVar7;
    do {
      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar1 - iVar2));
      puVar6 = puVar6 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  uVar3 = param_2[0xc] & 0x7fffffff;
  if ((int)uVar3 < *(int *)(param_1 + 0x2c)) {
    if (-1 < (int)param_2[0xc]) {
      (**(code **)(*DAT_00b05060 + 0x14))(param_2[10],uVar3 * 4,0x12);
    }
    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_1 + 0x2c) * 4,0x12);
    param_2[10] = uVar4;
    param_2[0xc] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);
  }
  param_2[0xb] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);
  iVar9 = *(int *)(param_1 + 0x2c);
  iVar1 = *(int *)(param_1 + 0x28);
  iVar2 = param_2[10];
  iVar7 = 0;
  if (3 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xc);
    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);
    iVar8 = (iVar9 - 4U >> 2) + 1;
    iVar7 = iVar8 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar1 - iVar2));
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  if (iVar7 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar7 * 4);
    iVar9 = iVar9 - iVar7;
    do {
      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar1 - iVar2));
      puVar6 = puVar6 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  uVar3 = param_2[0xf] & 0x7fffffff;
  if ((int)uVar3 < *(int *)(param_1 + 0x38)) {
    if (-1 < (int)param_2[0xf]) {
      (**(code **)(*DAT_00b05060 + 0x14))(param_2[0xd],uVar3 * 4,0x12);
    }
    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_1 + 0x38) * 4,0x12);
    param_2[0xd] = uVar4;
    param_2[0xf] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x38);
  }
  param_2[0xe] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x38);
  iVar9 = *(int *)(param_1 + 0x38);
  iVar1 = *(int *)(param_1 + 0x34);
  iVar2 = param_2[0xd];
  iVar7 = 0;
  if (3 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xc);
    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);
    iVar8 = (iVar9 - 4U >> 2) + 1;
    iVar7 = iVar8 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar1 - iVar2));
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  if (iVar7 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar7 * 4);
    iVar9 = iVar9 - iVar7;
    do {
      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar1 - iVar2));
      puVar6 = puVar6 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  uVar3 = param_2[0x12] & 0x7fffffff;
  if ((int)uVar3 < *(int *)(param_1 + 0x44)) {
    if (-1 < (int)param_2[0x12]) {
      (**(code **)(*DAT_00b05060 + 0x14))(param_2[0x10],uVar3 * 4,0x12);
    }
    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_1 + 0x44) * 4,0x12);
    param_2[0x10] = uVar4;
    param_2[0x12] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);
  }
  param_2[0x11] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);
  iVar9 = *(int *)(param_1 + 0x44);
  iVar1 = *(int *)(param_1 + 0x40);
  iVar2 = param_2[0x10];
  iVar7 = 0;
  if (3 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xc);
    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);
    iVar8 = (iVar9 - 4U >> 2) + 1;
    iVar7 = iVar8 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar1 - iVar2));
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  if (iVar7 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar7 * 4);
    iVar9 = iVar9 - iVar7;
    do {
      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar1 - iVar2));
      puVar6 = puVar6 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  uVar3 = param_2[0x15] & 0x7fffffff;
  if ((int)uVar3 < *(int *)(param_1 + 0x50)) {
    if (-1 < (int)param_2[0x15]) {
      (**(code **)(*DAT_00b05060 + 0x14))(param_2[0x13],uVar3 * 4,0x12);
    }
    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_1 + 0x50) * 4,0x12);
    param_2[0x13] = uVar4;
    param_2[0x15] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);
  }
  param_2[0x14] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);
  iVar9 = *(int *)(param_1 + 0x50);
  iVar1 = *(int *)(param_1 + 0x4c);
  iVar2 = param_2[0x13];
  iVar7 = 0;
  if (3 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xc);
    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);
    iVar8 = (iVar9 - 4U >> 2) + 1;
    iVar7 = iVar8 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar1 - iVar2));
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  if (iVar7 < iVar9) {
    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar7 * 4);
    iVar9 = iVar9 - iVar7;
    do {
      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar1 - iVar2));
      puVar6 = puVar6 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  iVar7 = *(int *)(param_1 + 0xc);
  if ((int)(param_2[3] & 0x7fffffff) < iVar7) {
    iVar9 = (param_2[3] & 0x7fffffff) * 2;
    if (iVar9 <= iVar7) {
      iVar9 = iVar7;
    }
    FUN_005b3300(param_2 + 1,iVar9,4);
  }
  param_2[2] = iVar7;
  iVar7 = *(int *)(param_1 + 0xc);
  if ((int)(param_2[0x18] & 0x7fffffff) < iVar7) {
    iVar9 = (param_2[0x18] & 0x7fffffff) * 2;
    if (iVar9 <= iVar7) {
      iVar9 = iVar7;
    }
    FUN_005b3300(param_2 + 0x16,iVar9,4);
  }
  iVar9 = 0;
  param_2[0x17] = iVar7;
  if (0 < *(int *)(param_1 + 0xc)) {
    iVar7 = 0;
    do {
      *(uint32_t /* width from decompiler */ *)(param_2[1] + iVar9 * 4) =
           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x58) + iVar9 * 4);
      *(uint32_t /* width from decompiler */ *)(param_2[0x16] + iVar9 * 4) =
           *(uint32_t /* width from decompiler */ *)(iVar7 + 0x84 + *(int *)(param_1 + 0x80));
      iVar9 = iVar9 + 1;
      iVar7 = iVar7 + 0xc0;
    } while (iVar9 < *(int *)(param_1 + 0xc));
  }
  return;
}
