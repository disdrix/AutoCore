# Raw capture: Client_RecvLoginCallback_12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821cb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00821cb0` |
| **Canonical name** | `Client_RecvLoginCallback_12` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall Client_RecvLoginCallback_12(int param_1)

{
  OutputDebugStringA("RecvServerList\n");
  *(undefined1 *)(param_1 + 0x4a) = 3;
  if (*(int *)(param_1 + 4) != 0) {
    FUN_00728990(*(int *)(param_1 + 4),*(undefined4 *)(param_1 + 0x50),
                 *(undefined4 *)(param_1 + 0x54),*(undefined1 *)(param_1 + 0x74));
  }
  return;
}
```
