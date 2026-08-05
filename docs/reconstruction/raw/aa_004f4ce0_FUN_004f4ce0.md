# Raw capture: FUN_004f4ce0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4ce0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f4ce0` |
| **Canonical name** | `FUN_004f4ce0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_004f4ce0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0);
  if ((iVar1 != 0) || (uVar2 = 0xc, *(char *)(param_1 + 0x103) != '\0')) {
    uVar2 = 10;
  }
  return uVar2;
}
```
