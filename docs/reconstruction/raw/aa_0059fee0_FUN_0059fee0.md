# Raw capture: FUN_0059fee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059fee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0059fee0` |
| **Canonical name** | `FUN_0059fee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0059fee0(int param_1,undefined4 param_2)

{
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00975720(param_2);
  param_2 = *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0xa8);
  BitStream_writeBits(0x20,&param_2);
  param_2 = *(undefined4 *)(param_1 + 0x250);
  BitStream_writeBits(0x20,&param_2);
  local_8 = *(undefined4 *)(param_1 + 600);
  local_4 = *(undefined4 *)(param_1 + 0x25c);
  BitStream_writeBits(0x40,&local_8);
  return;
}
```
