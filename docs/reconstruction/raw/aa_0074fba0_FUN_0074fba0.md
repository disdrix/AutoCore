# Raw capture: FUN_0074fba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074fba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074fba0` |
| **Canonical name** | `FUN_0074fba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0074fba0(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x20) != param_2) {
    if ((&DAT_00afe010)[*(int *)(param_1 + 0x28) * 3] != 0) {
      FUN_0074f360();
    }
    piVar2 = *(int **)(param_1 + 0xc);
    if (piVar2 == (int *)0x0) {
      iVar3 = -0x7789f794;
    }
    else {
      iVar3 = (**(code **)(*piVar2 + 0xe8))(piVar2,*(undefined4 *)(param_2 + 4));
      if (-1 < iVar3) {
        *(int *)(param_1 + 0x20) = param_2;
        goto LAB_0074fc3f;
      }
    }
    uVar4 = FUN_006b7a5a(iVar3,"Can\'t Set Technique");
    uVar4 = FUN_006a5dac(iVar3,uVar4);
    uVar4 = FUN_0076cec0(&stack0xfffffffc,"%s - %s\r\n%s",uVar4);
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp",
                   0x142,3,uVar4);
    return 0xffffffff;
  }
LAB_0074fc3f:
  cVar1 = *(char *)(DAT_00d1f048 + 0xc);
  if (*(char *)(param_2 + 0x10) != cVar1) {
    *(bool *)(DAT_00d1f048 + 0xc) = cVar1 == '\0';
    if (DAT_00d1f044[0x1df] == 1) {
      (**(code **)(*(int *)*DAT_00d1f044 + 0x134))((int *)*DAT_00d1f044,cVar1 == '\0');
    }
    puVar5 = &DAT_00d0e128;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    puVar5 = &DAT_00d0e0e8;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    DAT_00d1a558 = 0;
    DAT_00d1a55c = 0;
  }
  return 0;
}
```
