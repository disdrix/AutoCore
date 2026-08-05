# Raw capture: DirectInput8Create

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a4214` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a4214` |
| **Canonical name** | `DirectInput8Create` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void DirectInput8Create(void)

{
                    /* WARNING: Could not recover jumptable at 0x006a4214. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectInput8Create();
  return;
}
```
