# Raw capture: FUN_0078edf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078edf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0078edf0` |
| **Canonical name** | `FUN_0078edf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0078edf0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_8 [8];
  
  iVar2 = 1;
  iVar1 = 1;
  (**(code **)(*param_1 + 0x120))(local_8,1,1);
  if (*(char *)((int)param_1 + 0x4fd) == '\0') {
    iVar1 = (*(int *)(DAT_00d17948 + 0x10) - iVar2) - param_1[0x143];
    iVar2 = param_1[0x145] - param_1[0x143];
  }
  else {
    iVar1 = (*(int *)(DAT_00d17948 + 0xc) - iVar1) - param_1[0x142];
    iVar2 = param_1[0x144] - param_1[0x142];
  }
  (**(code **)(*param_1 + 0x454))((float)iVar1 / (float)iVar2,1);
  return;
}
```
