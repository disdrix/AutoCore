# Raw capture: inet_addr

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717ed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717ed0` |
| **Canonical name** | `inet_addr` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
ulong inet_addr(char *cp)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717ed0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = inet_addr(cp);
  return uVar1;
}
```
