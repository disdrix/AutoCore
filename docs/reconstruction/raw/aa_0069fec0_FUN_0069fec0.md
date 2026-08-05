# Raw capture: FUN_0069fec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0069fec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0069fec0` |
| **Canonical name** | `FUN_0069fec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0069fec0(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float10 fVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ab00e;
  local_c = ExceptionList;
  fVar6 = (float10)g_flZero;
  if ((param_1[0x10] != 0.0) && (((int)param_1[0x11] - (int)param_1[0x10]) / 0x18 == 500)) {
    ExceptionList = &local_c;
    iVar5 = FUN_006a3db0();
    if (iVar5 == 499) {
      fVar1 = *(float *)((int)param_1[0x10] + 0x2ecc);
    }
    else {
      fVar1 = *(float *)(iVar5 * 0x18 + 4 + (int)param_1[0x10]);
      fVar1 = fVar1 + (*(float *)(iVar5 * 0x18 + 0x1c + (int)param_1[0x10]) - fVar1) *
                      (param_2 - (float)iVar5 * _DAT_009eb514) * _DAT_009eb518;
    }
    fVar2 = param_1[1];
    fVar3 = *param_1;
    fVar4 = *param_1;
    if ((_DAT_00d08f80 & 1) == 0) {
      _DAT_00d08f80 = _DAT_00d08f80 | 1;
      local_4 = 0;
      FUN_006a1cd0();
      _atexit((_func_4879 *)&LAB_009c5570);
      local_4 = 0xffffffff;
    }
    fVar6 = (float10)FUN_006a1be0(-param_1[2],param_1[2]);
    fVar6 = fVar6 + (float10)((fVar2 - fVar3) * fVar1 + fVar4);
  }
  ExceptionList = local_c;
  return fVar6;
}
```
