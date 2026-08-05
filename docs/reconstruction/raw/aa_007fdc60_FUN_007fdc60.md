# Raw capture: FUN_007fdc60

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fdc60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fdc60` |
| **Canonical name** | `FUN_007fdc60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fdc60(void)

{
  int *piVar1;
  int in_EAX;
  int *piVar2;
  
  piVar2 = (int *)**(int **)(in_EAX + 0x3c08);
  if (piVar2 != *(int **)(in_EAX + 0x3c08)) {
    do {
      FUN_007fca10();
      piVar1 = (int *)*piVar2;
      if (piVar2 != *(int **)(in_EAX + 0x3c08)) {
        *(int **)piVar2[1] = piVar1;
        *(int *)(*piVar2 + 4) = piVar2[1];
                    /* WARNING: Subroutine does not return */
        operator_delete(piVar2);
      }
      piVar2 = piVar1;
    } while (piVar1 != (int *)*(int *)(in_EAX + 0x3c08));
  }
  return;
}
```
