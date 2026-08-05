# Raw capture: FUN_0084dac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0084dac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0084dac0` |
| **Canonical name** | `FUN_0084dac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0084dac0(int *param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  int *piVar2;
  int unaff_retaddr;
  undefined1 local_8 [4];
  int *piStack_4;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x140))(local_8,1);
  iVar1 = *piVar2;
  if (param_4 == '\0') {
    piVar2 = (int *)(**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&stack0x00000000,1);
    if (*piVar2 < iVar1 / 2 + unaff_retaddr) {
      (**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&stack0x00000000,1);
    }
    if (DAT_00d1b25c / 2 < (int)param_1) {
      (**(code **)(*piStack_4 + 0x140))(&param_2,1);
    }
  }
  (**(code **)(*piStack_4 + 0x118))(&stack0xffffffe0);
  return;
}
```
