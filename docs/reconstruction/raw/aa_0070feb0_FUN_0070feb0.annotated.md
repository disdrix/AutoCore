# Annotated low-level: FUN_0070feb0

| Field | Value |
|---|---|
| Stable ID | `aa_0070feb0` |
| VA | `0x0070feb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0070feb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0070feb0(int param_1,float *param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  
  if (param_3 != 0) {
    iVar6 = param_4 - param_3;
    pfVar5 = (float *)(param_1 + 8 + param_3 * 4);
    do {
      param_3 = param_3 + -1;
      iVar6 = iVar6 + 1;
      pfVar5 = pfVar5 + -1;
      iVar8 = param_3;
      fVar2 = g_flZero;
      if (3 < iVar6) {
        iVar3 = ((param_4 - param_3) - 4U >> 2) + 1;
        iVar8 = param_3 + iVar3 * 4;
        pfVar4 = pfVar5;
        pfVar7 = (float *)(param_1 + 8);
        do {
          iVar3 = iVar3 + -1;
          fVar2 = pfVar7[1] * pfVar4[1] +
                  *pfVar7 * *pfVar4 + pfVar7[-1] * pfVar4[-1] + pfVar7[-2] * pfVar4[-2] + fVar2;
          pfVar4 = pfVar4 + 4;
          pfVar7 = pfVar7 + 4;
        } while (iVar3 != 0);
      }
      if (iVar8 < param_4) {
        pfVar4 = (float *)(param_1 + (iVar8 - param_3) * 4);
        do {
          iVar3 = iVar8 * 4;
          iVar8 = iVar8 + 1;
          fVar1 = *pfVar4;
          pfVar4 = pfVar4 + 1;
          fVar2 = *(float *)(param_1 + iVar3) * fVar1 + fVar2;
        } while (iVar8 < param_4);
      }
      param_2[param_3] = fVar2;
    } while (param_3 != 0);
  }
  *param_2 = *param_2 + DAT_00a110d8;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
