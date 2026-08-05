# Raw capture: FUN_008edae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008edae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008edae0` |
| **Canonical name** | `FUN_008edae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008edae0(int *param_1)

{
  int *piVar1;
  void *pvVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  undefined2 uStack_108;
  undefined4 auStack_106 [64];
  
  if ((int *)param_1[0x19f] != (int *)0x0) {
    iVar4 = (**(code **)(*(int *)param_1[0x19f] + 700))();
    if (iVar4 != 0) {
      uStack_108 = 0;
      puVar7 = auStack_106;
      for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      piVar1 = (int *)param_1[0x19f];
      *(undefined2 *)puVar7 = 0;
      iVar4 = (**(code **)(*piVar1 + 0x2b8))();
      if (iVar4 != 0) {
        pcVar5 = (char *)(**(code **)(*(int *)param_1[0x19f] + 0x2b8))();
        pcVar6 = (char *)&uStack_108;
        do {
          cVar3 = *pcVar5;
          *pcVar6 = cVar3;
          pcVar5 = pcVar5 + 1;
          pcVar6 = pcVar6 + 1;
        } while (cVar3 != '\0');
      }
      (**(code **)(*(int *)param_1[0x19f] + 0x58))();
      (**(code **)(*(int *)param_1[0x19f] + 0xcc))(0);
      if ((char)uStack_108 != '\0') {
        puVar8 = &uStack_108;
        FUN_007b6a20(puVar8);
        FUN_007b70b0(puVar8);
      }
    }
    (**(code **)(*(int *)param_1[0x19f] + 0x34c))();
    (**(code **)(*(int *)param_1[0x19f] + 0x440))();
    (**(code **)(*param_1 + 0xb0))(param_1[0x19f]);
  }
  cVar3 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar3 != '\0') {
    (**(code **)(*param_1 + 0x3b8))(param_1[0x15e]);
    (**(code **)(*param_1 + 0x3b8))(param_1[0x15d]);
    (**(code **)(*param_1 + 0x3b8))(param_1[0x16a]);
  }
  (**(code **)(*param_1 + 0x3ac))();
  FUN_00792490();
  iVar4 = FUN_0040e490(param_1 + 0x16c);
  while (iVar4 != 0) {
    iVar4 = FUN_0040e490(param_1 + 0x16c);
  }
  param_1[0x16f] = 0;
  FUN_007fea50();
  if (DAT_00d1b780 != (int *)0x0) {
    *(undefined4 *)(*DAT_00d1b780 + 0x498) = 0x4e2a;
    *(undefined4 *)(*DAT_00d1b780 + 0x49c) = 0x4e2b;
  }
  pvVar2 = (void *)param_1[0x1a0];
  if (pvVar2 == (void *)0x0) {
    param_1[0x1a0] = 0;
    return;
  }
  FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar2);
}
```
