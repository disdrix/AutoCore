# Raw capture: FUN_0053cfa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053cfa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0053cfa0` |
| **Canonical name** | `FUN_0053cfa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint __fastcall FUN_0053cfa0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00785ca0(*(undefined4 *)(param_1 + -0x48));
  if ((char)uVar1 != '\0') {
    return uVar1 & 0xffffff00;
  }
  uVar1 = FUN_00517680();
  return uVar1;
}
```
