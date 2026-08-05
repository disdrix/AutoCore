# Raw capture: FUN_0076bff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076bff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0076bff0` |
| **Canonical name** | `FUN_0076bff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0076bff0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_00a9d184;
  if (*(char *)(unaff_ESI + 5) != '\0') {
    free((void *)unaff_ESI[1]);
  }
  *unaff_ESI = &PTR_LAB_00a9d774;
  return;
}
```
