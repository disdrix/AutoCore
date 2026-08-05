# Raw capture: FUN_005ee8e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ee8e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ee8e0` |
| **Canonical name** | `FUN_005ee8e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005ee8e0(float param_1,int param_2)

{
  *(float *)(param_2 + 4) = param_1 * *(float *)(param_2 + 4);
  *(float *)(param_2 + 0x20) = param_1 * *(float *)(param_2 + 0x20);
  *(float *)(param_2 + 0x30) = param_1 * *(float *)(param_2 + 0x30);
  *(float *)(param_2 + 0x40) = param_1 * *(float *)(param_2 + 0x40);
  *(float *)(param_2 + 0x24) = param_1 * *(float *)(param_2 + 0x24);
  *(float *)(param_2 + 0x34) = param_1 * *(float *)(param_2 + 0x34);
  *(float *)(param_2 + 0x44) = param_1 * *(float *)(param_2 + 0x44);
  *(float *)(param_2 + 0x28) = param_1 * *(float *)(param_2 + 0x28);
  *(float *)(param_2 + 0x38) = param_1 * *(float *)(param_2 + 0x38);
  *(float *)(param_2 + 0x48) = param_1 * *(float *)(param_2 + 0x48);
  return;
}
```
