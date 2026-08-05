# Raw capture: FUN_008d3ee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008d3ee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008d3ee0` |
| **Canonical name** | `FUN_008d3ee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008d3ee0(int param_1)

{
  int iVar1;
  
  FUN_008d7800(param_1);
  if ((*(int *)(param_1 + 0x548) != 0) && (*(int *)(*(int *)(param_1 + 0x548) + 0x48) != 0)) {
    iVar1 = *(int *)(param_1 + 0x568);
    if (iVar1 == 0) {
      FUN_008d3a70();
      return;
    }
    if (iVar1 == 1) {
      FUN_008d3c90();
      return;
    }
    if (iVar1 == 2) {
      FUN_008d3b30();
      return;
    }
  }
  return;
}
```
