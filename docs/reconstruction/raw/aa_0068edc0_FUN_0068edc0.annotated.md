# Annotated low-level: FUN_0068edc0

| Field | Value |
|---|---|
| Stable ID | `aa_0068edc0` |
| VA | `0x0068edc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0068edc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0068edc0(int param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int local_1c;
  
  pfVar1 = param_2;
  if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    local_1c = 0;
    if (*(short *)(param_1 + 0x28) != 0) {
      param_2 = (float *)0x0;
      do {
        iVar15 = *(int *)(param_1 + 0x2c) + (int)param_2;
        iVar14 = 0;
        if (*(short *)(iVar15 + 0xc) != 0) {
          iVar16 = 0;
          do {
            fVar2 = *(float *)(*(int *)(iVar15 + 0x18) + iVar16);
            pfVar13 = (float *)(*(int *)(iVar15 + 0x18) + iVar16);
            fVar3 = pfVar13[1];
            fVar4 = pfVar13[2];
            fVar5 = pfVar1[1];
            fVar6 = pfVar1[9];
            fVar7 = pfVar1[5];
            fVar8 = pfVar1[0xd];
            fVar9 = pfVar1[2];
            fVar10 = pfVar1[10];
            fVar11 = pfVar1[6];
            fVar12 = pfVar1[0xe];
            *pfVar13 = fVar2 * *pfVar1 + fVar3 * pfVar1[4] + fVar4 * pfVar1[8] + pfVar1[0xc];
            pfVar13[1] = fVar3 * fVar7 + fVar4 * fVar6 + fVar2 * fVar5 + fVar8;
            pfVar13[2] = fVar3 * fVar11 + fVar4 * fVar10 + fVar2 * fVar9 + fVar12;
            if (*(char *)(param_1 + 1) != '\0') {
              fVar2 = *(float *)(*(int *)(iVar15 + 0x40) + iVar16);
              pfVar13 = (float *)(*(int *)(iVar15 + 0x40) + iVar16);
              fVar3 = pfVar13[1];
              fVar4 = pfVar13[2];
              fVar5 = pfVar1[1];
              fVar6 = pfVar1[9];
              fVar7 = pfVar1[5];
              fVar8 = pfVar1[0xd];
              fVar9 = pfVar1[2];
              fVar10 = pfVar1[10];
              fVar11 = pfVar1[6];
              fVar12 = pfVar1[0xe];
              *pfVar13 = fVar2 * *pfVar1 + fVar3 * pfVar1[4] + fVar4 * pfVar1[8] + pfVar1[0xc];
              pfVar13[1] = fVar3 * fVar7 + fVar4 * fVar6 + fVar2 * fVar5 + fVar8;
              pfVar13[2] = fVar3 * fVar11 + fVar4 * fVar10 + fVar2 * fVar9 + fVar12;
            }
            iVar14 = iVar14 + 1;
            iVar16 = iVar16 + 0xc;
          } while (iVar14 < (int)(uint)*(ushort *)(iVar15 + 0xc));
        }
        local_1c = local_1c + 1;
        param_2 = (float *)((int)param_2 + 0x44);
      } while (local_1c < (int)(uint)*(ushort *)(param_1 + 0x28));
    }
    fVar2 = *pfVar1;
    iVar14 = 0;
    if (*(short *)(param_1 + 0x1c) != 0) {
      iVar15 = 0;
      do {
        pfVar1 = (float *)(*(int *)(param_1 + 0x20) + iVar15);
        pfVar13 = (float *)(*(int *)(param_1 + 0x20) + iVar15);
        iVar14 = iVar14 + 1;
        iVar15 = iVar15 + 0xc;
        *pfVar13 = fVar2 * *pfVar1;
        pfVar13[1] = fVar2 * pfVar13[1];
        pfVar13[2] = fVar2 * pfVar13[2];
      } while (iVar14 < (int)(uint)*(ushort *)(param_1 + 0x1c));
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
