# Raw capture: thunk_FUN_0040d9c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040fd50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040fd50` |
| **Canonical name** | `thunk_FUN_0040d9c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void thunk_FUN_0040d9c0(void)

{
  void *pvVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0x10);
  while (iVar2 != 0) {
    if ((*(int *)(unaff_ESI + 0x10) != 0) &&
       (iVar2 = *(int *)(unaff_ESI + 0x10) + -1, *(int *)(unaff_ESI + 0x10) = iVar2, iVar2 == 0)) {
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
    iVar2 = *(int *)(unaff_ESI + 0x10);
  }
  iVar2 = *(int *)(unaff_ESI + 8);
  while (iVar2 != 0) {
    pvVar1 = *(void **)(*(int *)(unaff_ESI + 4) + -4 + iVar2 * 4);
    iVar2 = iVar2 + -1;
    if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
  }
  if (*(void **)(unaff_ESI + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 4) = 0;
  return;
}
```
