# Raw capture: FUN_0052cec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052cec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052cec0` |
| **Canonical name** | `FUN_0052cec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0052cec0(int param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  float10 fVar7;
  float fVar8;
  
  if (((char)param_2[0x40] != '\0') || (((uint)param_2[0x5f] >> 0x14 & 1) != 0)) {
    return (float10)g_flZero;
  }
  pcVar2 = (char *)((int)param_2 + 0x101);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (pcVar2 != (char *)((int)param_2 + 0x102)) {
    pcVar2 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) +
                                 0x160))();
    iVar3 = _stricmp((char *)((int)param_2 + 0x101),pcVar2);
    if (iVar3 != 0) goto LAB_0052cf29;
  }
  (**(code **)(*param_2 + 0x60))();
  iVar3 = *(int *)(param_2[0x2a] + 0x3c);
  iVar4 = FUN_0052ada0(*(undefined4 *)(iVar3 + 0x4ac));
  uVar5 = iVar4 - *(int *)(iVar3 + 0x4b0);
  if (-1 < (int)uVar5) {
    param_2 = (int *)(uint)*(byte *)(param_1 + 0x59a);
    fVar8 = (float)(int)param_2 * DAT_00a10e78 + DAT_00a0f74c;
    uVar6 = uVar5;
    if (9 < (int)uVar5) {
      uVar6 = 10;
    }
    if (((int)uVar6 < (int)param_2) && (param_2 = (int *)uVar5, 9 < (int)uVar5)) {
      param_2 = (int *)0xa;
    }
    fVar7 = (float10)_CIpow();
    fVar7 = (float10)(int)param_2 * (float10)DAT_00a0f718 + (float10)fVar8 / fVar7;
    param_2 = (int *)(float)fVar7;
    if (fVar7 <= (float10)_DAT_009cfa18) {
      if ((float)param_2 < 0.0) {
        param_2 = (int *)0x0;
      }
      return (float10)(float)param_2;
    }
    return (float10)g_flInferredThreatScale;
  }
LAB_0052cf29:
  return (float10)g_flZero;
}
```
