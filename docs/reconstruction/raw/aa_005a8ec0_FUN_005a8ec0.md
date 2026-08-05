# Raw capture: FUN_005a8ec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a8ec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a8ec0` |
| **Canonical name** | `FUN_005a8ec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005a8ec0(int param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined4 *puVar3;
  int local_4;
  
  puVar3 = *(undefined4 **)(param_1 + 0x124);
  if (puVar3 != *(undefined4 **)(param_1 + 0x128)) {
    do {
      pvVar1 = (void *)*puVar3;
      if (pvVar1 != (void *)0x0) {
        FUN_004b7150();
        FUN_004b99c0();
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar1);
      }
      puVar3 = puVar3 + 1;
    } while (puVar3 != *(undefined4 **)(param_1 + 0x128));
  }
  if (*(void **)(param_1 + 0x124) == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x124) = 0;
    *(undefined4 *)(param_1 + 0x128) = 0;
    *(undefined4 *)(param_1 + 300) = 0;
    piVar2 = (int *)(param_1 + 0x134);
    local_4 = 2;
    while( true ) {
      puVar3 = (undefined4 *)*piVar2;
      if (puVar3 != (undefined4 *)piVar2[1]) {
        do {
          pvVar1 = (void *)*puVar3;
          if (pvVar1 != (void *)0x0) {
            FUN_004b7150();
            FUN_004b99c0();
                    /* WARNING: Subroutine does not return */
            operator_delete(pvVar1);
          }
          puVar3 = puVar3 + 1;
        } while (puVar3 != (undefined4 *)piVar2[1]);
      }
      if ((void *)*piVar2 != (void *)0x0) break;
      *piVar2 = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
      piVar2 = piVar2 + 4;
      local_4 = local_4 + -1;
      if (local_4 == 0) {
        return;
      }
    }
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)*piVar2);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 0x124));
}
```
