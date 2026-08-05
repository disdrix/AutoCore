# Raw capture: FUN_006d1ee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006d1ee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006d1ee0` |
| **Canonical name** | `FUN_006d1ee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006d1ee0(int param_1,float *param_2,undefined4 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = fVar1 * *(float *)(param_1 + 0x20) +
          fVar2 * *(float *)(param_1 + 0x24) + fVar3 * *(float *)(param_1 + 0x28);
  fVar5 = fVar1 * *(float *)(param_1 + 0x30) +
          fVar2 * *(float *)(param_1 + 0x34) + fVar3 * *(float *)(param_1 + 0x38);
  if (fVar5 <= fVar4) {
    uVar6 = 0x10;
  }
  else {
    uVar6 = 0x20;
    fVar4 = fVar5;
  }
  if (fVar4 < fVar1 * *(float *)(param_1 + 0x10) +
              fVar2 * *(float *)(param_1 + 0x14) + fVar3 * *(float *)(param_1 + 0x18)) {
    uVar6 = 0;
  }
  *param_3 = *(undefined4 *)(uVar6 + 0x10 + param_1);
  param_3[1] = *(undefined4 *)(uVar6 + 0x14 + param_1);
  param_3[2] = *(undefined4 *)(uVar6 + 0x18 + param_1);
  param_3[3] = *(undefined4 *)(uVar6 + 0x1c + param_1);
  param_3[3] = uVar6 | 0x3f000000;
  return;
}
```
