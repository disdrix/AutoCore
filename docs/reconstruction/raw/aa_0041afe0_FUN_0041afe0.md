# Raw capture: FUN_0041afe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041afe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0041afe0` |
| **Canonical name** | `FUN_0041afe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0041afe0(int param_1)

{
  int iVar1;
  undefined4 in_EAX;
  int local_4;
  
  iVar1 = *(int *)(param_1 + 4);
  local_4 = param_1;
  if ((iVar1 != 0) &&
     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x3d4) <
      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x3d4))) {
    iVar1 = *(int *)(param_1 + 8);
    FUN_004220f0(param_1);
    *(int *)(param_1 + 8) = iVar1 + 0x3d4;
    return;
  }
  FUN_0041ca90(&local_4,*(undefined4 *)(param_1 + 8),in_EAX);
  return;
}
```
