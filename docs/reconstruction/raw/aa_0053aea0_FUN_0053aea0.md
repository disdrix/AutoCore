# Raw capture: FUN_0053aea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053aea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0053aea0` |
| **Canonical name** | `FUN_0053aea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0053aea0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) &&
     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0xc) <
      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0xc))) {
    iVar1 = *(int *)(param_1 + 8);
    FUN_00538710(iVar1,1,param_2,param_1,param_2);
    *(int *)(param_1 + 8) = iVar1 + 0xc;
    return;
  }
  FUN_0053a870(&param_2,*(undefined4 *)(param_1 + 8),param_2);
  return;
}
```
