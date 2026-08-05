# Raw capture: __RTDynamicCast

| Field | Value |
|---|---|
| **Stable ID** | `aa_004898a4` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004898a4` |
| **Canonical name** | `__RTDynamicCast` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __RTDynamicCast(void)

{
                    /* WARNING: Could not recover jumptable at 0x004898a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __RTDynamicCast();
  return;
}
```
