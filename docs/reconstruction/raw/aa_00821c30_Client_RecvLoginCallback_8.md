# Raw capture: Client_RecvLoginCallback_8

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821c30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00821c30` |
| **Canonical name** | `Client_RecvLoginCallback_8` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall Client_RecvLoginCallback_8(int param_1,undefined4 param_2,undefined4 param_3)

{
  OutputDebugStringA("RecvPlayOk\n");
  *(undefined4 *)(param_1 + 0x6c) = param_2;
  *(undefined1 *)(param_1 + 0x4b) = 1;
  *(undefined4 *)(param_1 + 0x70) = param_3;
  FUN_009332b0();
  if (DAT_00d1a90c != 0) {
    FUN_007290e0(DAT_00d1a90c);
  }
  return;
}
```
