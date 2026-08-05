# Raw capture: FUN_004d9ec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d9ec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004d9ec0` |
| **Canonical name** | `FUN_004d9ec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004d9ec0(int param_1,int param_2,char param_3)

{
  int iVar1;
  
  if (param_3 != '\0') {
    iVar1 = *(int *)(param_1 + 0xe8bc);
    if (iVar1 != *(int *)(param_1 + 0xe8c0)) {
      do {
        if (*(int *)(param_2 + 0x1c) == *(int *)(iVar1 + 0x1c)) {
          return;
        }
        iVar1 = iVar1 + 0x138;
      } while (iVar1 != *(int *)(param_1 + 0xe8c0));
    }
  }
  Client_SendLogicUiPacket(param_2);
  return;
}
```
