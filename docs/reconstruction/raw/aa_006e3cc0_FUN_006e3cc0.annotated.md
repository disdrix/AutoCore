# Annotated low-level: FUN_006e3cc0

| Field | Value |
|---|---|
| Stable ID | `aa_006e3cc0` |
| VA | `0x006e3cc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006e3cc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006e3cc0(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TtSphereSphere";
    uVar3 = rdtsc();
    DAT_00bc5644[1] = (int)uVar3;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  iVar1 = param_2[2];
  iVar2 = param_1[2];
  fVar4 = *(float *)(iVar1 + 0x50) - *(float *)(iVar2 + 0x50);
  fVar7 = *(float *)(iVar1 + 0x54) - *(float *)(iVar2 + 0x54);
  fVar6 = *(float *)(iVar1 + 0x58) - *(float *)(iVar2 + 0x58);
  fVar5 = *(float *)(*param_1 + 0xc) + *(float *)(*param_2 + 0xc);
  if (fVar4 * fVar4 + fVar7 * fVar7 + fVar6 * fVar6 < fVar5 * fVar5) {
    (**(code **)(*param_4 + 4))(param_1,param_2);
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d2878;
    uVar3 = rdtsc();
    DAT_00bc5644[1] = (int)uVar3;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
