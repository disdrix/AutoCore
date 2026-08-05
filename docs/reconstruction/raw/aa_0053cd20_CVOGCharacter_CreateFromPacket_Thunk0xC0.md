# Raw capture: CVOGCharacter_CreateFromPacket_Thunk0xC0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053cd20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0053cd20` |
| **Canonical name** | `CVOGCharacter_CreateFromPacket_Thunk0xC0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void CVOGCharacter_CreateFromPacket_Thunk0xC0(void)

{
  CVOGCharacter_ApplyCreateFromPacket();
  return;
}
```
