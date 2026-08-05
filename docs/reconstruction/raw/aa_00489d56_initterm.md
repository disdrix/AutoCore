# Raw capture: initterm

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489d56` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00489d56` |
| **Canonical name** | `initterm` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __cdecl initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00489d56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  initterm();
  return;
}
```
