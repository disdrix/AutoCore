# Raw capture: Client_RecvLoginCallback_6

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821c70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00821c70` |
| **Canonical name** | `Client_RecvLoginCallback_6` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvLoginCallback_6(undefined1 param_1)

{
  if (((DAT_00d1b77c != 0) && (DAT_00d1b780 != (int *)0x0)) && (*DAT_00d1b780 == DAT_00d1b77c)) {
    OutputDebugStringA("RecvServerFail\n");
    FUN_007a4480(1,"RecvServerFail: code(%d)",param_1);
  }
  return;
}
```
