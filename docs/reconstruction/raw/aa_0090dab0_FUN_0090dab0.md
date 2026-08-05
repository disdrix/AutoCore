# Raw capture: FUN_0090dab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090dab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0090dab0` |
| **Canonical name** | `FUN_0090dab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0090dab0(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_00d09a38;
  do {
    FUN_0090d400();
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0xd09a4c);
  return;
}
```
