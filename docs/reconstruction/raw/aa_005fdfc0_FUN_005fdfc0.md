# Raw capture: FUN_005fdfc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdfc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fdfc0` |
| **Canonical name** | `FUN_005fdfc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005fdfc0(int param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = g_flOne;
  *(undefined4 *)(param_1 + 0x28) = *param_2;
  *(undefined4 *)(param_1 + 0x38) = param_2[2];
  fVar2 = *(float *)(param_1 + 0x28) - *(float *)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x2c) = param_2[1];
  fVar3 = *(float *)(param_1 + 0x2c) * fVar2;
  *(undefined1 *)(param_1 + 0x3c) = *(undefined1 *)(param_2 + 3);
  *(float *)(param_1 + 0x34) = fVar3;
  *(float *)(param_1 + 0x30) = (fVar1 - fVar3) / ((fVar1 - *(float *)(param_1 + 0x38)) - fVar2);
  return;
}
```
