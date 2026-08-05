# Raw capture: FUN_004c7fd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c7fd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c7fd0` |
| **Canonical name** | `FUN_004c7fd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004c7fd0(int param_1)

{
  int iVar1;
  char cVar2;
  int local_4;
  
  local_4 = 0;
  cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) + 0x228
                      ))();
  if (cVar2 != '\0') {
    FUN_004e2600(&LAB_00513060,&local_4,0);
  }
  if (((local_4 == 0) && (iVar1 = *(int *)(param_1 + -0x2b0), iVar1 != 0)) &&
     (*(char *)(param_1 + -500) != '\0')) {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x224))();
  }
  return;
}
```
