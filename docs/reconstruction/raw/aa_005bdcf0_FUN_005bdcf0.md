# Raw capture: FUN_005bdcf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bdcf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bdcf0` |
| **Canonical name** | `FUN_005bdcf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_005bdcf0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(DAT_00b037f0 + 0x15) != '\0') {
    return 0;
  }
  uVar1 = FUN_005be460(param_2);
  FUN_005bdf00(param_1);
  if (*param_1 != 0) {
    iVar2 = FUN_0049a120();
    if (iVar2 != 0) {
      FUN_004b92b0(iVar2);
      FUN_005b8230(iVar2);
    }
  }
  return uVar1;
}
```
