# Raw capture: FUN_0095cfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0095cfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0095cfb0` |
| **Canonical name** | `FUN_0095cfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x0095cfd8) */

void FUN_0095cfb0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_00aa99f0;
  if ((void *)unaff_ESI[5] == (void *)0x0) {
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
    FUN_00718c50();
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)unaff_ESI[5]);
}
```
