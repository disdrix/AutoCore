# Raw capture: FUN_006a41ac

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a41ac` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a41ac` |
| **Canonical name** | `FUN_006a41ac` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006a41ac(int param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = param_2 + 8U & 0xfffffff8;
  piVar1 = (int *)(**(code **)**(undefined4 **)(param_1 + 4))(uVar2 * param_3 + 0x10);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = 0;
    *piVar1 = param_1;
    piVar1[3] = 1;
    piVar1[2] = uVar2 - 1;
  }
  return;
}
```
