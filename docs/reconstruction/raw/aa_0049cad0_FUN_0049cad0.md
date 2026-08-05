# Raw capture: FUN_0049cad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0049cad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0049cad0` |
| **Canonical name** | `FUN_0049cad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0049cad0(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00b035e4;
  do {
    pvVar1 = (void *)*puVar2;
    if (pvVar1 != (void *)0x0) {
      FUN_004b99c0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0xb035fc);
  return;
}
```
