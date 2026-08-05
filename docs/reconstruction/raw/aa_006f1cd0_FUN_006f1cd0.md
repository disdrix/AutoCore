# Raw capture: FUN_006f1cd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f1cd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f1cd0` |
| **Canonical name** | `FUN_006f1cd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_006f1cd0(int param_1)

{
  byte bVar1;
  
  bVar1 = (byte)*(undefined4 *)(param_1 + 0x24);
  *(int *)(param_1 + 0x48) = (*(int *)(param_1 + 0xc) >> (bVar1 & 0x1f)) << (bVar1 & 0x1f);
  *(int *)(param_1 + 0x54) = (*(int *)(param_1 + 0x10) >> (bVar1 & 0x1f)) + 1 << (bVar1 & 0x1f);
  bVar1 = (byte)*(undefined4 *)(param_1 + 0x24);
  *(int *)(param_1 + 0x4c) = (*(int *)(param_1 + 0x14) >> (bVar1 & 0x1f)) << (bVar1 & 0x1f);
  *(int *)(param_1 + 0x58) = (*(int *)(param_1 + 0x18) >> (bVar1 & 0x1f)) + 1 << (bVar1 & 0x1f);
  bVar1 = (byte)*(undefined4 *)(param_1 + 0x24);
  *(int *)(param_1 + 0x50) = (*(int *)(param_1 + 0x1c) >> (bVar1 & 0x1f)) << (bVar1 & 0x1f);
  *(int *)(param_1 + 0x5c) = (*(int *)(param_1 + 0x20) >> (bVar1 & 0x1f)) + 1 << (bVar1 & 0x1f);
  return;
}
```
