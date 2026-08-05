# Raw capture: FUN_005cbc00

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cbc00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cbc00` |
| **Canonical name** | `FUN_005cbc00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005cbc00(int param_1)

{
  int iVar1;
  void *pvVar2;
  
  *(undefined ***)(param_1 + -0x110) = &PTR_FUN_009da70c;
  *(undefined ***)(param_1 + -0xd0) = &PTR_FUN_009da6d0;
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) = &PTR_LAB_009da40c;
  iVar1 = *(int *)(*(int *)(param_1 + -0x10c) + 4);
  *(int *)(iVar1 + -0x110 + param_1) = iVar1 + -0x10c;
  pvVar2 = *(void **)(param_1 + -0x40);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)((int)pvVar2 + 4));
    }
    *(undefined4 *)((int)pvVar2 + 4) = 0;
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar2);
  }
  pvVar2 = *(void **)(param_1 + -0x3c);
  *(undefined4 *)(param_1 + -0x40) = 0;
  if (pvVar2 == (void *)0x0) {
    *(undefined4 *)(param_1 + -0x3c) = 0;
    FUN_005d48f0();
    return;
  }
  if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)((int)pvVar2 + 4));
  }
  *(undefined4 *)((int)pvVar2 + 4) = 0;
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar2);
}
```
