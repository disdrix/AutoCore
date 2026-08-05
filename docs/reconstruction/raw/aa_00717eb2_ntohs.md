# Raw capture: ntohs

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717eb2` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717eb2` |
| **Canonical name** | `ntohs` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
u_short ntohs(u_short netshort)

{
  u_short uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717eb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = ntohs(netshort);
  return uVar1;
}
```
