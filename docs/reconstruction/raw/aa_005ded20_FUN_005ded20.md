# Raw capture: FUN_005ded20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ded20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ded20` |
| **Canonical name** | `FUN_005ded20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_005ded20(undefined4 *param_1)

{
  short *psVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  *(undefined2 *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_009dbae4;
  uVar3 = (**(code **)(*DAT_00d030f0 + 4))(1);
  FUN_00631fd0(uVar3);
  uVar3 = (**(code **)(*DAT_00d030f0 + 4))(2);
  FUN_00631fd0(uVar3);
  puVar2 = (undefined4 *)param_1[4];
  psVar1 = (short *)((int)puVar2 + 6);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    (**(code **)*puVar2)(1);
  }
  puVar2 = (undefined4 *)param_1[7];
  *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;
  if (*(short *)((int)puVar2 + 6) == 0) {
    (**(code **)*puVar2)(1);
  }
  return param_1;
}
```
