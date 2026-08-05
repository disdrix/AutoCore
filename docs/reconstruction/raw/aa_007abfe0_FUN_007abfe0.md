# Raw capture: FUN_007abfe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007abfe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007abfe0` |
| **Canonical name** | `FUN_007abfe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007abfe0(void)

{
  int in_EAX;
  
  *(uint *)(in_EAX + 0xf8) = (uint)*(byte *)(in_EAX + 0x22b);
  *(uint *)(in_EAX + 0xfc) = (uint)*(byte *)(in_EAX + 0x22f);
  *(uint *)(in_EAX + 0x100) = (uint)*(byte *)(in_EAX + 0x233);
  return;
}
```
