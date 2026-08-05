# Raw capture: FUN_006f3bb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f3bb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f3bb0` |
| **Canonical name** | `FUN_006f3bb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006f3bb0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =
       (char)param_2;
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 8) <= iVar1) {
    FUN_006f3900();
  }
  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =
       (char)((uint)param_2 >> 8);
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 8) <= iVar1) {
    FUN_006f3900();
  }
  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =
       (char)((uint)param_2 >> 0x10);
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 8) <= iVar1) {
    FUN_006f3900();
  }
  return;
}
```
