# Raw capture: FUN_0040ada0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ada0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040ada0` |
| **Canonical name** | `FUN_0040ada0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0040ada0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x68) + 1;
  *(int *)(param_1 + 0x68) = iVar1;
  *(float *)(param_1 + 0x74) = (float)-iVar1;
  if (*(int *)(param_1 + 0x70) < iVar1) {
    *(int *)(param_1 + 0x70) = iVar1;
  }
  return;
}
```
