# Raw capture: FUN_004fcc40

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fcc40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fcc40` |
| **Canonical name** | `FUN_004fcc40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004fcc40(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x330);
  if (puVar2 != *(undefined4 **)(param_1 + 0x334)) {
    do {
      pvVar1 = (void *)*puVar2;
      FUN_004b7150();
      if (pvVar1 != (void *)0x0) {
        FUN_004b99c0();
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar1);
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != *(undefined4 **)(param_1 + 0x334));
  }
  if (*(void **)(param_1 + 0x330) == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x330) = 0;
    *(undefined4 *)(param_1 + 0x334) = 0;
    *(undefined4 *)(param_1 + 0x338) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 0x330));
}
```
