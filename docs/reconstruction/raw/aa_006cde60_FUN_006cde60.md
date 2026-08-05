# Raw capture: FUN_006cde60

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cde60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cde60` |
| **Canonical name** | `FUN_006cde60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 __thiscall FUN_006cde60(int *param_1,float *param_2)

{
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  undefined1 local_70 [4];
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_44 = 0;
  local_48 = 0;
  local_4c = 0;
  local_34 = 0;
  local_38 = 0;
  local_40 = 0;
  local_24 = 0;
  local_2c = 0;
  local_30 = 0;
  local_50 = 0x3f800000;
  local_3c = 0x3f800000;
  local_28 = 0x3f800000;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  (**(code **)(*param_1 + 0x18))(&local_50,0,local_70);
  return ((float10)(fStack_74 + fStack_64) * (float10)DAT_00a0f298 +
         (float10)(float)((uint)((fStack_64 - fStack_74) * DAT_00a0f298) ^
                         (uint)param_2[2] & 0x80000000)) * (float10)param_2[2] +
         (float10)((fStack_7c + fStack_6c) * DAT_00a0f298 +
                  (float)((uint)((fStack_6c - fStack_7c) * DAT_00a0f298) ^
                         (uint)*param_2 & 0x80000000)) * (float10)*param_2 +
         (float10)((fStack_78 + fStack_68) * DAT_00a0f298 +
                  (float)((uint)((fStack_68 - fStack_78) * DAT_00a0f298) ^
                         (uint)param_2[1] & 0x80000000)) * (float10)param_2[1];
}
```
