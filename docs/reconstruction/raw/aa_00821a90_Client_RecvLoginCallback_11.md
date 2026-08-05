# Raw capture: Client_RecvLoginCallback_11

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821a90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00821a90` |
| **Canonical name** | `Client_RecvLoginCallback_11` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvLoginCallback_11(void)

{
  OutputDebugStringA("RecvSCCheckReq\n");
  return;
}
```
