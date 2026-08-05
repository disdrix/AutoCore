# Raw capture: FUN_005efcc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005efcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005efcc0` |
| **Canonical name** | `FUN_005efcc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005efcc0(undefined4 *param_1)

{
  int iVar1;
  float *in_EAX;
  float *pfVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  
  iVar1 = param_1[1];
  local_18 = 0.0;
  local_1c = 0.0;
  local_30 = DAT_009dd020;
  local_2c = DAT_009dd020;
  local_28 = DAT_009dd020;
  local_24 = DAT_009dd020;
  fVar4 = DAT_00aaa63c;
  fVar6 = DAT_00aaa63c;
  fVar7 = DAT_00aaa63c;
  fVar9 = DAT_00aaa63c;
  if (0 < iVar1) {
    pfVar2 = (float *)*param_1;
    iVar3 = iVar1;
    do {
      fVar5 = *pfVar2;
      if (fVar5 < local_30) {
        local_30 = fVar5;
      }
      if (pfVar2[1] < local_2c) {
        local_2c = pfVar2[1];
      }
      if (pfVar2[2] < local_28) {
        local_28 = pfVar2[2];
      }
      fVar8 = pfVar2[3];
      if (fVar8 < local_24) {
        local_24 = fVar8;
      }
      if (fVar4 < fVar5) {
        fVar4 = fVar5;
      }
      if (fVar6 < pfVar2[1]) {
        fVar6 = pfVar2[1];
      }
      if (fVar7 < pfVar2[2]) {
        fVar7 = pfVar2[2];
      }
      if (fVar9 < fVar8) {
        fVar9 = fVar8;
      }
      pfVar2 = pfVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  fVar5 = 0.0;
  fVar8 = 0.0;
  if (iVar1 != 0) {
    fVar5 = (fVar4 + local_30) * DAT_00a0f298;
    local_1c = (fVar6 + local_2c) * DAT_00a0f298;
    local_18 = (fVar7 + local_28) * DAT_00a0f298;
    fVar8 = (fVar9 + local_24) * DAT_00a0f298;
  }
  *in_EAX = 0.0 - fVar5;
  in_EAX[1] = 0.0 - local_1c;
  in_EAX[2] = 0.0 - local_18;
  in_EAX[3] = 0.0 - fVar8;
  return;
}
```
