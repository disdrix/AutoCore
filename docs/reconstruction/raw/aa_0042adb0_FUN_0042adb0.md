# Raw capture: FUN_0042adb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042adb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0042adb0` |
| **Canonical name** | `FUN_0042adb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0042adb0(void)

{
  code *pcVar1;
  char *in_EAX;
  
  if (*in_EAX != '\0') {
    FUN_00780060();
    return;
  }
  if ((DAT_00afddd4 == '\0') && (DAT_00afddd0 < DAT_00d179e8)) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}
```
