# Raw capture: Client_RecvBroadcast

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810a80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00810a80` |
| **Canonical name** | `Client_RecvBroadcast` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall Client_RecvBroadcast(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  DWORD DVar7;
  void *pvVar8;
  void *pvVar9;
  char *_Dest;
  int iVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
  undefined2 *puVar14;
  undefined4 uVar15;
  uint uVar16;
  int local_444;
  undefined1 local_428 [20];
  void *local_414;
  undefined2 local_410;
  undefined4 local_40e [252];
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009b80c3;
  local_1c = ExceptionList;
  if (*(int *)(param_2 + 0x109c) != 0) {
    local_428[0] = 0;
    ExceptionList = &local_1c;
    if ((DAT_00d1d8c8 != 0) && (ExceptionList = &local_1c, DAT_00d1b225 != '\0')) {
      ExceptionList = &local_1c;
      FUN_0079d560(DAT_00d1d8c8,param_1 + 0x25);
    }
    local_444 = *(int *)(param_1 + 4);
    if (local_444 == 3) {
      piVar4 = (int *)CVOGReaction_ResolveObjectTarget
                                (1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
      if (piVar4 != (int *)0x0) {
        uVar5 = (**(code **)(*piVar4 + 0x160))(0x11);
        FUN_00793aa0(local_428,uVar5);
      }
      uVar5 = *(undefined4 *)(param_1 + 4);
      uVar15 = 0;
      param_1 = param_1 + 0x25;
      puVar13 = local_428;
      uVar6 = __RTDynamicCast(*(undefined4 *)(param_2 + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,
                              &CDlgChatLog::RTTI_Type_Descriptor,0,uVar5,puVar13,param_1,0);
      FUN_008f8200(uVar6,uVar5,puVar13,param_1,uVar15);
      ExceptionList = local_1c;
      return;
    }
    if ((*(uint *)(param_1 + 8) & *(uint *)(param_1 + 0xc)) == 0xffffffff) {
      FUN_00793aa0(local_428,"[System]",0x11);
      local_444 = 6;
    }
    else {
      iVar10 = *(int *)(param_2 + 0xe98);
      if (((iVar10 == 0) ||
          (iVar2 = *(int *)(*(int *)(iVar10 + 4) + 4),
          *(uint *)(param_1 + 8) != *(uint *)(iVar2 + 0x164 + iVar10))) ||
         (*(int *)(param_1 + 0xc) != *(int *)(iVar2 + 0x168 + iVar10))) {
        FUN_00793aa0(local_428,param_1 + 0x14,0x11);
        if (*(int *)(param_1 + 4) == 2) {
          Client_MaybeShowFirstTimeTip(0x22);
        }
      }
      else {
        uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10) + 0x160))
                          (0x11);
        FUN_00793aa0(local_428,uVar5);
        DVar7 = GetTickCount();
        *(DWORD *)(param_2 + 0x30f0) = DVar7 - *(int *)(param_2 + 0x30e8);
        *(undefined4 *)(param_2 + 0x30e8) = 0;
        *(undefined4 *)(param_2 + 0x30ec) = 0;
      }
    }
    if ((*(int *)(param_2 + 0xe04) == 0) || (*(char *)(*(int *)(param_2 + 0xe04) + 0xf6) == '\0')) {
      bVar3 = *(byte *)(param_1 + 0x10);
      puVar14 = (undefined2 *)(param_1 + 0x25);
      uVar5 = *(undefined4 *)(param_2 + 0x109c);
    }
    else {
      local_410 = 0;
      puVar12 = local_40e;
      for (iVar10 = 0xf9; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
      *(undefined2 *)puVar12 = 0;
      puVar14 = &local_410;
      FUN_007a75e0();
      bVar3 = *(byte *)(param_1 + 0x10);
      uVar5 = *(undefined4 *)(param_2 + 0x109c);
    }
    uVar16 = (uint)bVar3;
    puVar13 = local_428;
    uVar5 = __RTDynamicCast(uVar5,0,&CVOGDialog::RTTI_Type_Descriptor,
                            &CDlgChatLog::RTTI_Type_Descriptor,0,local_444,puVar13,puVar14,uVar16);
    FUN_008f8200(uVar5,local_444,puVar13,puVar14,uVar16);
    pvVar8 = Client_LookupObjectByTfid_Inferred(1,*(uint *)(param_1 + 8),*(uint *)(param_1 + 0xc));
    if ((pvVar8 != (void *)0x0) &&
       (iVar10 = *(int *)(*(int *)((int)pvVar8 + 4) + 4),
       iVar10 = FUN_00573a90(*(undefined4 *)(iVar10 + 0x164 + (int)pvVar8),
                             *(undefined4 *)(iVar10 + 0x168 + (int)pvVar8)), iVar10 == 0)) {
      piVar11 = (int *)0x0;
      piVar4 = (int *)FUN_00404c90();
      iVar10 = *piVar4;
      fVar1 = (float)piVar4[1];
      iVar2 = piVar4[2];
      pvVar9 = operator_new(0x60);
      local_14 = 0;
      if (pvVar9 != (void *)0x0) {
        piVar11 = (int *)FUN_004050f0();
      }
      local_14 = 0xffffffff;
      _Dest = operator_new__((int)*(short *)(param_1 + 0x12) + 1);
      *piVar11 = (int)_Dest;
      strncpy(_Dest,(char *)(param_1 + 0x25),(int)*(short *)(param_1 + 0x12));
      *(undefined1 *)((int)*(short *)(param_1 + 0x12) + *piVar11) = 0;
      piVar11[9] = *(int *)(&DAT_00d1e4a0 + *(int *)(param_1 + 4) * 4);
      piVar11[7] = *(int *)(param_2 + 0x9b4);
      piVar11[8] = *(int *)(param_2 + 0x9b4);
      piVar11[1] = iVar10;
      piVar11[2] = (int)(fVar1 + DAT_00aaa688);
      piVar11[3] = iVar2;
      piVar11[10] = 0;
      piVar11[0xb] = 0;
      piVar11[0xc] = 0;
      piVar4 = (int *)(*(int *)(*(int *)((int)pvVar8 + 4) + 4) + 0x164 + (int)pvVar8);
      piVar11[0xe] = *piVar4;
      piVar11[0xf] = piVar4[1];
      piVar11[0x10] = piVar4[2];
      piVar11[0x11] = piVar4[3];
      piVar11[0x12] = 3;
      local_414 = operator_new(0xd0);
      local_14 = 1;
      if (local_414 == (void *)0x0) {
        iVar10 = 0;
      }
      else {
        iVar10 = FUN_007972f0(local_414,0,1);
      }
      local_14 = 0xffffffff;
      piVar11[0x17] = iVar10;
      *(undefined1 *)(iVar10 + 0xb6) = 0;
      FUN_00797a10(piVar11[0x17]);
      FUN_007a75e0();
      FUN_00798720(piVar11[0x17],&local_410,piVar11[9],&DAT_00d1e7e0 + piVar11[0x12],0x3f800000,0);
      FUN_007979c0(piVar11[0x17]);
      FUN_00405e20(param_2 + 0xac0);
    }
  }
  ExceptionList = local_1c;
  return;
}
```
