# Raw capture: FUN_0054fec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054fec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0054fec0` |
| **Canonical name** | `FUN_0054fec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0054fec0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00627be0();
  if (*(uint *)(param_1 + 0x620) == 0) {
    *(uint *)(param_1 + 0x624) = uVar1;
  }
  else {
    *(uint *)(param_1 + 0x624) = uVar1 | 4;
    if (*(char *)(param_1 + 0x148) == '\0') {
      *(uint *)(param_1 + 0x620) = *(uint *)(param_1 + 0x620) | 0x100000;
      return;
    }
  }
  return;
}
```
