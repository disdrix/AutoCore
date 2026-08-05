# Raw capture: Client_RecvLoginCallback_9

| Field | Value |
|---|---|
| **Stable ID** | `aa_008226b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008226b0` |
| **Canonical name** | `Client_RecvLoginCallback_9` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvLoginCallback_9(void)

{
  if (((DAT_00d1b77c != 0) && (DAT_00d1b780 != (int *)0x0)) && (*DAT_00d1b780 == DAT_00d1b77c)) {
    OutputDebugStringA("RecvAccountKicked\n");
    FUN_00944b20();
    return;
  }
  return;
}
```
