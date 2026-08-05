# Raw capture: FUN_005d4bd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4bd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d4bd0` |
| **Canonical name** | `FUN_005d4bd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_005d4bd0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + -0xd8);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x40) != '\0')) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x34 + param_1) + 0x3c);
  if (((*(byte *)(iVar1 + 0x3f2) >> 1 & 1) == 0) && (*(float *)(iVar1 + 0x3e4) != g_flZero)) {
    return 0;
  }
  return 1;
}
```
