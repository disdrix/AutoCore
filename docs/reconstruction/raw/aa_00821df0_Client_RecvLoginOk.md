# Raw capture: Client_RecvLoginOk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00821df0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00821df0` |
| **Canonical name** | `Client_RecvLoginOk` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall Client_RecvLoginOk(int param_1,undefined4 param_2,undefined4 param_3)

{
  OutputDebugStringA("RecvLoginOk\n");
  *(undefined1 *)(param_1 + 0x4a) = 2;
  *(undefined4 *)(param_1 + 0x50) = param_2;
  *(undefined4 *)(param_1 + 0x54) = param_3;
  if (*(int *)(param_1 + 4) != 0) {
    FUN_00728840(*(int *)(param_1 + 4),param_2,param_3);
  }
  return;
}
```
