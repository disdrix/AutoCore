# Raw capture: FUN_004bcda0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcda0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bcda0` |
| **Canonical name** | `FUN_004bcda0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004bcda0(int param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_4;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (*(char *)(param_1 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:remove, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4);
  puVar3 = (undefined4 *)FUN_004e23d0(param_2,param_3,&param_4);
  if (puVar3 != (undefined4 *)0x0) {
    if (param_4 == (undefined4 *)0x0) {
      *(undefined4 *)(iVar1 + 4) = puVar3[4];
    }
    else {
      param_4[4] = puVar3[4];
    }
  }
  FUN_004e2360();
  if (puVar3 != (undefined4 *)0x0) {
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = puVar3[3];
    }
    puVar3[3] = 0;
    if (puVar3 == *(undefined4 **)(param_1 + 0x14)) {
      *(undefined4 *)(param_1 + 0x14) = puVar3[8];
    }
    else {
      *(undefined4 *)(puVar3[9] + 0x20) = puVar3[8];
    }
    if (puVar3 == *(undefined4 **)(param_1 + 0x18)) {
      *(undefined4 *)(param_1 + 0x18) = puVar3[9];
    }
    else {
      *(undefined4 *)(puVar3[8] + 0x24) = puVar3[9];
    }
    *puVar3 = &PTR_FUN_009cb360;
    if ((undefined4 *)puVar3[3] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar3[3])(1);
    }
    puVar3[3] = 0;
    *puVar3 = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 **)(param_1 + 0x20) = puVar3;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
    return 0;
  }
  return 0x80004005;
}
```
