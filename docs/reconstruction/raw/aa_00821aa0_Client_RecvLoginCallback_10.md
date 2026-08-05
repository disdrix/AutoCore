# Raw capture: Client_RecvLoginCallback_10

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821aa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00821aa0` |
| **Canonical name** | `Client_RecvLoginCallback_10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvLoginCallback_10(void)

{
                    /* WARNING: Could not recover jumptable at 0x00821aa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OutputDebugStringA("RecvBlockedAccountMsg\n");
  return;
}
```
