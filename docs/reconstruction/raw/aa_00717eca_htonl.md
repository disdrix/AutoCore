# Raw capture: htonl

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717eca` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00717eca` |
| **Canonical name** | `htonl` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
u_long htonl(u_long hostlong)

{
  u_long uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00717eca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = htonl(hostlong);
  return uVar1;
}
```
