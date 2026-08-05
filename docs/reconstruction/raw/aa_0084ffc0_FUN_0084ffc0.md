# Raw capture: FUN_0084ffc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0084ffc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0084ffc0` |
| **Canonical name** | `FUN_0084ffc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0084ffc0(void)

{
  void *pvVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  
  pvVar1 = *(void **)(in_EAX + 0x5a0);
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(in_EAX + 0x5a4);
  *(undefined4 *)(in_EAX + 0x5a0) = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(in_EAX + 0x5a8);
  *(undefined4 *)(in_EAX + 0x5a4) = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(in_EAX + 0x5ac);
  *(undefined4 *)(in_EAX + 0x5a8) = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *(undefined4 *)(in_EAX + 0x5ac) = 0;
  puVar3 = (undefined4 *)(in_EAX + 0x5b0);
  iVar2 = 0x14;
  do {
    pvVar1 = (void *)*puVar3;
    if (pvVar1 != (void *)0x0) {
      FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar3 = (undefined4 *)(in_EAX + 0x600);
  iVar2 = 9;
  do {
    pvVar1 = (void *)*puVar3;
    if (pvVar1 != (void *)0x0) {
      FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}
```
