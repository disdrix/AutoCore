// =============================================================================
// Phys_CommitPairListStorage_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_006297e0
// Address:   0x006297e0  (autoassault.exe, image base 0x400000)
// System:    physics / collision pair storage
// Generated: 2026-07-29 W27-M dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// PURPOSE: Commit dual pair-lists into host pair buffer (+0x68/+0x6c/+0x70, stride 0x10).
// Grow via DAT_00b05060 tag 0x12. Callers: BindLinks/UnbindLinks, island FUN_00629d90.
// ABI: thiscall; ret 0x10. Gate: listA_count!=0 || listB_count!=0.
// Name: Ghidra FUN_006297e0; inferred Phys_CommitPairListStorage_Inferred.
//

void __thiscall
Phys_CommitPairListStorage_Inferred(int param_1,uint32_t param_2,int param_3,uint32_t param_4,int param_5)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  uint uVar3;
  uint32_t uVar4;
  uint32_t *puVar5;
  int iVar6;
  int local_14;
  
  if ((param_3 != 0) || (param_5 != 0)) {
    FUN_006cad30(param_2,param_3);
    FUN_006cad30(param_4,param_5);
    FUN_0055f520(*(int *)(param_1 + 0x6c) + param_3);
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x68);
    *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0x6c) * 0x10 + *(int *)(param_1 + 0x68);
    *(int *)(param_1 + 0xa4) = local_14;
    *(uint32_t *)(param_1 + 0x98) = *(uint32_t *)(*(int *)(param_1 + 0x20) + 0xcc);
    *(int *)(*(int *)(*(int *)(param_1 + 0x20) + 0x138) + 0x24) = param_1 + 0x1c;
    iVar6 = *(int *)(*(int *)(param_1 + 0x20) + 0xd0);
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = iVar6 + 8;
    }
    FUN_006caaa0(param_2,param_3,param_4,param_5,iVar6);
    iVar6 = *(int *)(*(int *)(param_1 + 0x20) + 0x138);
    *(int *)(iVar6 + 0x24) = iVar6 + 0x100;
    if (*(uint *)(param_1 + 0x9c) < *(uint *)(param_1 + 0xa0)) {
      do {
        puVar2 = *(uint32_t **)(param_1 + 0x9c);
        puVar5 = *(uint32_t **)(param_1 + 0xa4);
        *puVar5 = *puVar2;
        puVar5[1] = puVar2[1];
        puVar5[2] = puVar2[2];
        puVar5[3] = puVar2[3];
        *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + 0x10;
        *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + 0x10;
      } while (*(uint *)(param_1 + 0x9c) < *(uint *)(param_1 + 0xa0));
    }
    iVar6 = *(int *)(param_1 + 0xa4) - local_14 >> 4;
    uVar3 = *(uint *)(param_1 + 0x70) & 0x7fffffff;
    if ((int)uVar3 < iVar6) {
      if (-1 < (int)*(uint *)(param_1 + 0x70)) {
        (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t *)(param_1 + 0x68),uVar3 << 4,0x12);
      }
      uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(iVar6 << 4,0x12);
      *(uint32_t *)(param_1 + 0x68) = uVar4;
      *(int *)(param_1 + 0x70) = iVar6;
    }
    *(int *)(param_1 + 0x6c) = iVar6;
    puVar2 = *(uint32_t **)(param_1 + 0x68);
    if (0 < iVar6) {
      puVar5 = puVar2;
      do {
        puVar1 = (uint32_t *)((local_14 - (int)puVar2) + (int)puVar5);
        *puVar5 = *puVar1;
        puVar5[1] = puVar1[1];
        puVar5[2] = puVar1[2];
        iVar6 = iVar6 + -1;
        puVar5[3] = puVar1[3];
        puVar5 = puVar5 + 4;
      } while (iVar6 != 0);
    }
    FUN_0055f590();
  }
  return;
}

