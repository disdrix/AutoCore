# Raw capture: FUN_004c4aa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4aa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c4aa0` |
| **Canonical name** | `FUN_004c4aa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_004c4aa0(int param_1)

{
  float fVar1;
  int iVar2;
  uint3 uVar3;
  float fVar4;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
  fVar1 = *(float *)(iVar2 + 100 + param_1);
  iVar2 = (**(code **)(*(int *)(iVar2 + param_1 + 4) + 0x244))();
  fVar4 = (float)iVar2 * (float)_DAT_00aaa6e0;
  if (g_flZero <= fVar4) {
    fVar4 = fVar4 + g_flMissionXpRoundBias;
  }
  else {
    fVar4 = fVar4 - g_flMissionXpRoundBias;
  }
  uVar3 = (uint3)((uint)(int)fVar4 >> 8);
  if (fVar1 < (float)(int)fVar4) {
    return (uint)uVar3 << 8;
  }
  return CONCAT31(uVar3,*(undefined1 *)(param_1 + 0x309));
}
```
