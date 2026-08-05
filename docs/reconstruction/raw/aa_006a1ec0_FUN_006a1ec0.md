# Raw capture: FUN_006a1ec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a1ec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a1ec0` |
| **Canonical name** | `FUN_006a1ec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_006a1ec0(int param_1)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_1 + 0x58);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x5c);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x54);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x50);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x6c);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 100);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x68);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x60);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x70);
  if (pvVar1 != (void *)0x0) {
    FUN_006a1100();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  return;
}
```
