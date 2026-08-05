# Annotated low-level: FUN_005ecbc0

| Field | Value |
|---|---|
| Stable ID | `aa_005ecbc0` |
| VA | `0x005ecbc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ecbc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005ecbc0(int *param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float local_c;
  float local_8;
  float local_4;
  
  iVar6 = *param_1;
  iVar4 = param_1[1] - iVar6 >> 0x1f;
  uVar5 = 0;
  if ((param_1[1] - iVar6) / 0x1c + iVar4 != iVar4) {
    iVar4 = 0;
    do {
      iVar7 = *(int *)param_1[4];
      iVar2 = *(int *)(iVar4 + iVar6) * 0xc;
      iVar6 = *(int *)(iVar4 + 4 + iVar6) * 0xc;
      fVar8 = *(float *)(iVar6 + 4 + iVar7) * param_3 + *(float *)(iVar6 + 8 + iVar7) * param_4 +
              *(float *)(iVar6 + iVar7) * param_2 + param_5;
      fVar1 = param_2 * *(float *)(iVar7 + iVar2) +
              param_4 * *(float *)(iVar7 + 8 + iVar2) + param_3 * *(float *)(iVar7 + 4 + iVar2) +
              param_5;
      if ((float)_DAT_009dcfb0 <= fVar1) {
        if ((double)fVar1 <= _DAT_009dcfa8) {
          iVar7 = 0;
        }
        else {
          iVar7 = 1;
        }
      }
      else {
        iVar7 = -1;
      }
      if ((float)_DAT_009dcfb0 <= fVar8) {
        if ((double)fVar8 <= _DAT_009dcfa8) {
          iVar3 = 0;
        }
        else {
          iVar3 = 1;
        }
      }
      else {
        iVar3 = -1;
      }
      iVar7 = iVar7 + iVar3 * 10;
      if ((iVar7 == -9) || (iVar7 == 9)) {
        iVar7 = *(int *)param_1[4];
        fVar8 = g_flOne / (fVar1 - fVar8);
        local_c = *(float *)(iVar7 + iVar2) +
                  (*(float *)(iVar7 + iVar6) - *(float *)(iVar7 + iVar2)) * fVar1 * fVar8;
        local_8 = *(float *)(iVar7 + 4 + iVar2) +
                  (*(float *)(iVar7 + 4 + iVar6) - *(float *)(iVar7 + 4 + iVar2)) * fVar1 * fVar8;
        local_4 = *(float *)(iVar7 + 8 + iVar2) +
                  (*(float *)(iVar7 + 8 + iVar6) - *(float *)(iVar7 + 8 + iVar2)) * fVar1 * fVar8;
        FUN_005ee310(&local_c);
      }
      iVar6 = *param_1;
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x1c;
    } while (uVar5 < (uint)((param_1[1] - iVar6) / 0x1c));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
