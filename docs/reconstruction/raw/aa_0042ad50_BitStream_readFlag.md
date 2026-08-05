# Raw capture: BitStream_readFlag

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042ad50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0042ad50` |
| **Canonical name** | `BitStream_readFlag` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
bool __thiscall BitStream_readFlag(int param_1,undefined1 *param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x18);
  if (*(uint *)(param_1 + 0x2c) < uVar2) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
    *param_2 = 0;
    return *(char *)(param_1 + 0x1c) == '\0';
  }
  bVar1 = *(byte *)((uVar2 >> 3) + *(int *)(param_1 + 0xc));
  *(uint *)(param_1 + 0x18) = uVar2 + 1;
  *param_2 = (bVar1 & (byte)(1 << ((byte)uVar2 & 7))) != 0;
  return *(char *)(param_1 + 0x1c) == '\0';
}
```
