# Raw capture: hkDefaultAnalogDriverInput_calcReverse

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe0b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fe0b0` |
| **Canonical name** | `hkDefaultAnalogDriverInput_calcReverse` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall hkDefaultAnalogDriverInput_calcReverse(int param_1,char *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  if (*(char *)(param_1 + 0x3c) == '\0') {
    cVar7 = *(char *)(param_1 + 0x25);
LAB_005fe0c4:
    *param_2 = cVar7;
    return;
  }
  iVar4 = *(int *)(param_1 + 8);
  iVar5 = *(int *)(*(int *)(iVar4 + 0x30) + 0x3c);
  fVar14 = SQRT(*(float *)(iVar5 + 0x48) * *(float *)(iVar5 + 0x48) +
                *(float *)(iVar5 + 0x44) * *(float *)(iVar5 + 0x44) +
                *(float *)(iVar5 + 0x40) * *(float *)(iVar5 + 0x40));
  if (*(float *)(param_1 + 0x20) <= g_flMultiKillCountBlend) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
    if (DAT_009dd34c < fVar14) {
      iVar6 = *(int *)(iVar4 + 0x10);
      fVar1 = *(float *)(iVar6 + 0x10);
      fVar2 = *(float *)(iVar6 + 0x18);
      fVar9 = *(float *)(iVar6 + 0x14);
      fVar8 = *(float *)(iVar5 + 0x80) * fVar1 + *(float *)(iVar5 + 0xa0) * fVar2 +
              *(float *)(iVar5 + 0x90) * fVar9;
      fVar3 = *(float *)(iVar5 + 0x44);
      fVar10 = *(float *)(iVar5 + 0x88) * fVar1 + *(float *)(iVar5 + 0xa8) * fVar2 +
               *(float *)(iVar5 + 0x98) * fVar9;
      fVar9 = *(float *)(iVar5 + 0x84) * fVar1 + *(float *)(iVar5 + 0xa4) * fVar2 +
              *(float *)(iVar5 + 0x94) * fVar9;
      fVar1 = *(float *)(iVar5 + 0x48);
      fVar2 = *(float *)(iVar5 + 0x40);
      fVar11 = fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2;
      if (fVar11 == 0.0) {
        fVar11 = 0.0;
      }
      else {
        fVar11 = g_flOne / SQRT(fVar11);
      }
      fVar12 = fVar8 * fVar8 + fVar10 * fVar10 + fVar9 * fVar9;
      fVar13 = 0.0;
      if (fVar12 != 0.0) {
        fVar13 = g_flOne / SQRT(fVar12);
      }
      if (fVar10 * fVar13 * fVar11 * fVar1 + fVar9 * fVar13 * fVar11 * fVar3 +
          fVar13 * fVar8 * fVar11 * fVar2 < DAT_009dd34c) goto LAB_005fe4f6;
    }
  }
  if (*(char *)(*(int *)(iVar4 + 0x20) + 0x14) == '\0') {
    if ((fVar14 < _DAT_009dd380) && (cVar7 != '\0')) {
LAB_005fe4f6:
      *param_2 = '\x01';
      return;
    }
  }
  else {
    if (fVar14 < _DAT_009dd380) goto LAB_005fe0c4;
    iVar4 = *(int *)(iVar4 + 0x10);
    fVar14 = *(float *)(iVar4 + 0x10);
    fVar1 = *(float *)(iVar5 + 0x48);
    fVar2 = *(float *)(iVar5 + 0x44);
    fVar9 = *(float *)(iVar4 + 0x14);
    fVar8 = *(float *)(iVar5 + 0x80) * fVar14 + *(float *)(iVar5 + 0xa0) * *(float *)(iVar4 + 0x18)
            + *(float *)(iVar5 + 0x90) * fVar9;
    fVar10 = *(float *)(iVar5 + 0x88) * fVar14 + *(float *)(iVar5 + 0xa8) * *(float *)(iVar4 + 0x18)
             + *(float *)(iVar5 + 0x98) * fVar9;
    fVar3 = *(float *)(iVar5 + 0x40);
    fVar9 = *(float *)(iVar5 + 0x84) * fVar14 + *(float *)(iVar5 + 0xa4) * *(float *)(iVar4 + 0x18)
            + *(float *)(iVar5 + 0x94) * fVar9;
    fVar14 = 0.0;
    fVar11 = fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2;
    if (fVar11 == 0.0) {
      fVar11 = 0.0;
    }
    else {
      fVar11 = g_flOne / SQRT(fVar11);
    }
    fVar13 = fVar8 * fVar8 + fVar10 * fVar10 + fVar9 * fVar9;
    if (fVar13 != 0.0) {
      fVar14 = g_flOne / SQRT(fVar13);
    }
    if (fVar14 * fVar8 * fVar11 * fVar3 + fVar10 * fVar14 * fVar1 * fVar11 +
        fVar9 * fVar14 * fVar2 * fVar11 <= DAT_009dd34c) {
      *param_2 = '\x01';
      return;
    }
  }
  *param_2 = '\0';
  return;
}
```
