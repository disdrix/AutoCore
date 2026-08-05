# Raw capture: FUN_008fee00

| Field | Value |
|---|---|
| **Stable ID** | `aa_008fee00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008fee00` |
| **Canonical name** | `FUN_008fee00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008fee00(int *param_1)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  int iVar11;
  undefined4 *puVar12;
  char *pcVar13;
  char acStack_2c [28];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  piVar3 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b7b59;
  local_c = ExceptionList;
  if (((DAT_00d1b6d8 != 0) && (param_1[0x130] != 0)) &&
     (ExceptionList = &local_c, FUN_008fc740(), *(int *)(DAT_00d1b6d8 + 0x250) != 0)) {
    FUN_008fd160();
    if (0 < param_1[0x145]) {
      pvVar5 = operator_new__(param_1[0x147] * 4);
      param_1[0x1cf] = (int)pvVar5;
      pvVar5 = operator_new__(param_1[0x147] * 4);
      param_1[0x1cb] = (int)pvVar5;
      pvVar5 = operator_new__(param_1[0x145] * 4);
      param_1[0x180] = (int)pvVar5;
      if (0 < param_1[0x147]) {
        iVar11 = 0;
        do {
          pvVar5 = operator_new(0x4cc);
          uVar6 = 0;
          local_4 = 0;
          if (pvVar5 != (void *)0x0) {
            uVar6 = FUN_0079c860();
          }
          local_4 = 0xffffffff;
          *(undefined4 *)(param_1[0x1cf] + iVar11 * 4) = uVar6;
          (**(code **)(*param_1 + 0xa8))();
          (**(code **)(**(int **)(param_1[0x1cf] + iVar11 * 4) + 0x28))("i_d_body_2d_btn_trim.xml");
          (**(code **)(**(int **)(param_1[0x1cf] + iVar11 * 4) + 0x74))(iVar11 + 0x9c4d);
          (**(code **)(**(int **)(param_1[0x1cf] + iVar11 * 4) + 0x3b4))(1);
          (**(code **)(**(int **)(param_1[0x1cf] + iVar11 * 4) + 8))(param_1 + 0x173);
          (**(code **)(**(int **)(param_1[0x1cf] + iVar11 * 4) + 0x118))(&stack0xffffffb8);
          (**(code **)(**(int **)(param_1[0x1cf] + iVar11 * 4) + 0xcc))(0);
          iVar11 = iVar11 + 1;
        } while (iVar11 < param_1[0x147]);
      }
      iVar11 = param_1[0x1a] + 1;
      param_1[0x1a] = iVar11;
      param_1[0x1d] = (int)(float)-iVar11;
      if (param_1[0x1c] < iVar11) {
        param_1[0x1c] = iVar11;
      }
      (**(code **)(*param_1 + 0x3f4))();
      iVar11 = 0;
      if (0 < param_1[0x147]) {
        do {
          pvVar5 = operator_new(0x488);
          local_4 = 1;
          if (pvVar5 == (void *)0x0) {
            uVar6 = 0;
          }
          else {
            uVar6 = FUN_007b5dd0(pvVar5);
          }
          local_4 = 0xffffffff;
          *(undefined4 *)(param_1[0x1cb] + iVar11 * 4) = uVar6;
          (**(code **)(*param_1 + 0xa8))();
          (**(code **)(**(int **)(param_1[0x1cb] + iVar11 * 4) + 0x28))
                    ("i_d_body_2d_wnd_trim_icon.xml");
          (**(code **)(**(int **)(param_1[0x1cb] + iVar11 * 4) + 8))(param_1 + 0x175);
          (**(code **)(**(int **)(param_1[0x1cb] + iVar11 * 4) + 0x118))(&stack0xffffffc0);
          (**(code **)(**(int **)(param_1[0x1cb] + iVar11 * 4) + 0xcc))(0);
          iVar11 = iVar11 + 1;
        } while (iVar11 < param_1[0x147]);
      }
      if (0 < param_1[0x145]) {
        iVar11 = 0;
        param_1 = (int *)0x1;
        do {
          pvVar5 = operator_new__(0x104);
          *(void **)(iVar11 + piVar3[0x180]) = pvVar5;
          *(undefined1 *)(*(int *)(iVar11 + piVar3[0x180]) + 3) = 0;
          if ((int)param_1 < 10) {
            pcVar13 = "_0%i_t";
          }
          else {
            pcVar13 = "_%i_t";
          }
          sprintf(acStack_2c,pcVar13);
          iVar7 = __RTDynamicCast(piVar3[0x1cc],0,&CNDUIWndBuffered::RTTI_Type_Descriptor,
                                  &CWndVehicle::RTTI_Type_Descriptor);
          if ((iVar7 != 0) && (*(int *)(iVar7 + 0x508) != 0)) {
            FUN_004fc4c0();
            pcVar13 = acStack_2c;
            do {
              cVar1 = *pcVar13;
              pcVar13 = pcVar13 + 1;
            } while (cVar1 != '\0');
            uVar8 = (int)pcVar13 - (int)acStack_2c;
            pcVar13 = (char *)(*(int *)(iVar11 + piVar3[0x180]) + -1);
            do {
              pcVar10 = pcVar13 + 1;
              pcVar13 = pcVar13 + 1;
            } while (*pcVar10 != '\0');
            pcVar10 = acStack_2c;
            for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined4 *)pcVar13 = *(undefined4 *)pcVar10;
              pcVar10 = pcVar10 + 4;
              pcVar13 = pcVar13 + 4;
            }
            for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
              *pcVar13 = *pcVar10;
              pcVar10 = pcVar10 + 1;
              pcVar13 = pcVar13 + 1;
            }
            puVar4 = (undefined4 *)(*(int *)(iVar11 + piVar3[0x180]) + -1);
            do {
              puVar12 = puVar4;
              puVar4 = (undefined4 *)((int)puVar12 + 1);
            } while (*(char *)((int)puVar12 + 1) != '\0');
            *(undefined4 *)((int)puVar12 + 1) = DAT_00a2c53c;
            *(undefined1 *)((int)puVar12 + 5) = DAT_00a2c540;
          }
          iVar11 = iVar11 + 4;
          bVar2 = (int)param_1 < piVar3[0x145];
          param_1 = (int *)((int)param_1 + 1);
        } while (bVar2);
      }
    }
    if (piVar3[0x145] <= piVar3[0x147]) {
      (**(code **)(*(int *)piVar3[0x1d3] + 0xd4))();
      ExceptionList = pvStack_10;
      return;
    }
    (**(code **)(*(int *)piVar3[0x1d3] + 0x460))();
    (**(code **)(*(int *)piVar3[0x1d3] + 0xd4))();
  }
  ExceptionList = local_c;
  return;
}
```
