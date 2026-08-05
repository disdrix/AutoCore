# Raw capture: FUN_007a7eb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a7eb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007a7eb0` |
| **Canonical name** | `FUN_007a7eb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint __fastcall FUN_007a7eb0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0xd8))();
  if (((char)uVar1 != '\0') && (param_1[0xac] != 0)) {
    uVar1 = (**(code **)(*(int *)param_1[0xac] + 0x338))(0x15,param_1[0x3b]);
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}
```
