# Raw capture: thunk_FUN_005b2ba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d640` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043d640` |
| **Canonical name** | `thunk_FUN_005b2ba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall thunk_FUN_005b2ba0(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  while (iVar2 != 0) {
    if ((*(int *)(param_1 + 0x10) != 0) &&
       (iVar2 = *(int *)(param_1 + 0x10) + -1, *(int *)(param_1 + 0x10) = iVar2, iVar2 == 0)) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x10);
  }
  iVar2 = *(int *)(param_1 + 8);
  while (iVar2 != 0) {
    pvVar1 = *(void **)(*(int *)(param_1 + 4) + -4 + iVar2 * 4);
    iVar2 = iVar2 + -1;
    if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
  }
  if (*(void **)(param_1 + 4) == (void *)0x0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 4));
}
```
