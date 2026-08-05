# Raw capture: FUN_0084fcc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0084fcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0084fcc0` |
| **Canonical name** | `FUN_0084fcc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0084fcc0(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = DAT_00aaa8dc;
  fVar1 = g_flOne;
  fVar3 = (float)param_1[0x141] + g_flOne;
  param_1[0x141] = (int)fVar3;
  if (fVar2 < fVar3) {
    param_1[0x141] = (int)fVar2;
  }
  fVar2 = DAT_00af9328;
  param_1[0x143] = (int)((float)param_1[0x142] * (fVar1 / (float)param_1[0x141]));
  fVar3 = DAT_00af932c;
  if (fVar2 < DAT_00af932c) {
    fVar3 = fVar2;
  }
  _DAT_00af9330 = fVar3 * DAT_00a0f298 * (fVar1 / (float)param_1[0x141]);
  if (_DAT_00af9330 < fVar1) {
    _DAT_00af9330 = fVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x0084fd4b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x34c))();
  return;
}
```
