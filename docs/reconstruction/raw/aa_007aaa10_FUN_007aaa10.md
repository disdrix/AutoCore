# Raw capture: FUN_007aaa10

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aaa10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007aaa10` |
| **Canonical name** | `FUN_007aaa10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007aaa10(int *param_1)

{
  int iVar1;
  float fVar2;
  int *in_EAX;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int local_8;
  int local_4;
  
  fVar2 = DAT_00aaa670;
  if (DAT_00d17944 != 0) {
    fVar3 = (float)DAT_00d1e818;
    fVar5 = (float)param_1[2] * DAT_00aaa674;
    fVar4 = (float)DAT_00d1e81c;
    fVar6 = (float)param_1[1] * DAT_00aaa670;
    iVar1 = param_1[3];
    *in_EAX = (int)(((float)*param_1 * DAT_00aaa674) / fVar3);
    in_EAX[1] = (int)(fVar6 / fVar4);
    in_EAX[2] = (int)(fVar5 / fVar3);
    in_EAX[3] = (int)(((float)iVar1 * fVar2) / fVar4);
    return;
  }
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = local_8;
  in_EAX[3] = local_4;
  return;
}
```
