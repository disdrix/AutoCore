# Raw capture: FUN_005df0d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005df0d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005df0d0` |
| **Canonical name** | `FUN_005df0d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005df0d0(int param_1)

{
  if ((*(FILE **)(param_1 + 8) != (FILE *)0x0) && (*(char *)(param_1 + 0xc) != '\0')) {
    fclose(*(FILE **)(param_1 + 8));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}
```
