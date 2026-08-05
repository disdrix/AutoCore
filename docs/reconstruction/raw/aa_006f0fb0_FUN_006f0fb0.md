# Raw capture: FUN_006f0fb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f0fb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f0fb0` |
| **Canonical name** | `FUN_006f0fb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006f0fb0(undefined1 *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar3 = *(float *)(param_2 + 0x10) - *(float *)(param_2 + 0x20);
  fVar6 = *(float *)(param_2 + 0x14) - *(float *)(param_2 + 0x24);
  fVar4 = *(float *)(param_2 + 0x18) - *(float *)(param_2 + 0x28);
  fVar1 = *(float *)(param_2 + 0x10) - *(float *)(param_2 + 0x30);
  fVar2 = *(float *)(param_2 + 0x14) - *(float *)(param_2 + 0x34);
  fVar7 = *(float *)(param_2 + 0x18) - *(float *)(param_2 + 0x38);
  fVar5 = fVar7 * fVar6 - fVar2 * fVar4;
  fVar4 = fVar4 * fVar1 - fVar7 * fVar3;
  fVar1 = fVar2 * fVar3 - fVar6 * fVar1;
  if (fVar5 * fVar5 + fVar4 * fVar4 + fVar1 * fVar1 < _DAT_00af58bc) {
    *param_1 = 1;
    return;
  }
  *param_1 = 0;
  return;
}
```
