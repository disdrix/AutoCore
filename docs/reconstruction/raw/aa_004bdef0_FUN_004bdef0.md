# Raw capture: FUN_004bdef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bdef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bdef0` |
| **Canonical name** | `FUN_004bdef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_004bdef0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);
  iVar1 = *(int *)(iVar2 + 0x38);
  if (((((*(short *)(*(int *)(iVar2 + 0x3c) + 0x3f4) != 3) && (iVar1 != 0x36)) && (iVar1 != 0x38))
      && ((iVar1 != 0x1e && (iVar1 != 0x3c)))) &&
     ((iVar2 = *(int *)(*(int *)(param_1 + 4) + 4),
      (*(byte *)(*(int *)(*(int *)(iVar2 + 0xac + param_1) + 0x3c) + 0x3f2) & 4) == 0 &&
      (*(int *)(param_1 + 0x1c) == 0)))) {
    if ((*(char *)(*(int *)(iVar2 + param_1 + 0xa8) + 0xf5) == '\0') &&
       (iVar2 = FUN_004bde80(*(undefined4 *)(param_1 + 8)), 20000 < iVar2)) {
      return 0;
    }
    return 1;
  }
  return 0;
}
```
