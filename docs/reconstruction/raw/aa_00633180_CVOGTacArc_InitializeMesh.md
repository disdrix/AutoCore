# Raw capture: CVOGTacArc_InitializeMesh

| Field | Value |
|---|---|
| **Stable ID** | `aa_00633180` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00633180` |
| **Canonical name** | `CVOGTacArc_InitializeMesh` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall CVOGTacArc_InitializeMesh(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  void *pvVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  void *local_38 [4];
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a8c11;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
    ExceptionList = &pvStack_c;
    operator_delete__(*(void **)(param_1 + 0x2c));
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x18))(1);
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_00989e00(local_38,"NDTacArc.fx");
  FUN_009701d0(local_38);
  FUN_00989e00(local_38,"veh_tacarc.dds");
  FUN_0096f3e0(local_38,0);
  FUN_00989e00(local_38,"veh_tacarc_effect.dds");
  FUN_0096f3e0(local_38,0);
  pvVar6 = operator_new__(*(int *)(param_1 + 0x28) * 0x60);
  *(void **)(param_1 + 0x2c) = pvVar6;
  local_38[0] = operator_new(0x14c);
  uStack_4 = 0;
  if (local_38[0] == (void *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = FUN_00764030();
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = uVar7;
  local_38[0] = operator_new(0xc4);
  uStack_4 = 1;
  if (local_38[0] == (void *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = FUN_00748960();
  }
  *(undefined4 *)(param_1 + 0x1c) = uVar7;
  uStack_4 = 0xffffffff;
  uVar7 = (**(code **)(**(int **)(param_1 + 0x18) + 0xc))();
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 100) = uVar7;
  iVar8 = **(int **)(param_1 + 0x1c);
  uVar7 = (**(code **)(**(int **)(param_1 + 0x18) + 100))();
  (**(code **)(iVar8 + 0x34))(uVar7);
  piVar3 = *(int **)(param_1 + 0x5c);
  piVar9 = (int *)(*(int *)(param_1 + 0x1c) + 0x20);
  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {
    (**(code **)(*piVar3 + 4))();
  }
  piVar4 = (int *)*piVar9;
  if (piVar4 != (int *)0x0) {
    piVar1 = piVar4 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*piVar4 + 8))();
    }
  }
  *piVar9 = (int)piVar3;
  FUN_00970140("TacArcTextureBase",*(undefined4 *)(param_1 + 0x54));
  FUN_00970140("TacArcTextureEffect",*(undefined4 *)(param_1 + 0x58));
  FUN_009733d0(param_1 + 0x34);
  FUN_009700f0("MatZFailColor",local_38);
  puVar2 = (uint *)(*(int *)(param_1 + 0x1c) + 0xbc);
  *puVar2 = *puVar2 | 1;
  pvStack_24 = (void *)0x0;
  uStack_20 = 0;
  uStack_1c = 0;
  puStack_8 = (undefined1 *)0x2;
  uStack_18 = 0;
  uStack_14 = 0;
  FUN_007478c0(0x242);
  puStack_8 = (undefined1 *)0x3;
  iVar8 = FUN_00414c20(*(int *)(param_1 + 0x28) * 3,auStack_28,3,0);
  puStack_8 = (undefined1 *)0xffffffff;
  uStack_18 = 0;
  uStack_14 = 0;
  if (pvStack_24 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvStack_24);
  }
  puVar5 = *(undefined4 **)(param_1 + 0x1c);
  pvStack_24 = (void *)0x0;
  uStack_20 = 0;
  uStack_1c = 0;
  if (iVar8 < 0) {
    if (puVar5 != (undefined4 *)0x0) {
      (**(code **)*puVar5)(1);
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
    if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x18))(1);
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    ExceptionList = pvStack_10;
    return iVar8;
  }
  puVar5[0x2a] = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xac) = 4;
  puVar2 = (uint *)(*(int *)(param_1 + 0x1c) + 0xbc);
  *puVar2 = *puVar2 & 0xfffffffe;
  FUN_007647c0(*(undefined4 *)(param_1 + 0x1c));
  ExceptionList = pvStack_10;
  return iVar8;
}
```
