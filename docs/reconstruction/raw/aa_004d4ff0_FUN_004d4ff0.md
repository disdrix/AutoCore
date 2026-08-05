# Raw capture: FUN_004d4ff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d4ff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004d4ff0` |
| **Canonical name** | `FUN_004d4ff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004d4ff0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0xe720);
  if ((iVar1 != 0) &&
     ((uint)(*(int *)(param_1 + 0xe724) - iVar1 >> 2) <
      (uint)(*(int *)(param_1 + 0xe728) - iVar1 >> 2))) {
    puVar2 = *(undefined4 **)(param_1 + 0xe724);
    *puVar2 = param_2;
    *(undefined4 **)(param_1 + 0xe724) = puVar2 + 1;
    return;
  }
  FUN_004e39d0(*(undefined4 *)(param_1 + 0xe724),1,&param_2);
  return;
}
```
