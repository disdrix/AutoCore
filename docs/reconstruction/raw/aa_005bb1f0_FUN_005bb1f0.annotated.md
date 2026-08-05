# Annotated low-level: FUN_005bb1f0

| Field | Value |
|---|---|
| Stable ID | `aa_005bb1f0` |
| VA | `0x005bb1f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005bb1f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005bb1f0(int param_1,float *param_2,undefined4 param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined1 local_28 [12];
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_1c = *(float *)(param_1 + 0x838);
  pfVar1 = (float *)(param_1 + 0x838);
  local_18 = *(float *)(param_1 + 0x83c);
  local_14 = *(float *)(param_1 + 0x840);
  if ((*(byte *)(*(int *)(param_1 + 0x10) + 0x1e4) & 8) != 0) {
    FUN_005c36f0(pfVar1,param_1 + 0x880,*(int *)(param_1 + 0x10),param_1 + 0x9b4,param_3,
                 param_1 + 0x88c,param_1 + 0x8a4,param_1 + 0x898,*param_2);
  }
  if ((*(byte *)(*(int *)(param_1 + 0x10) + 0x1e4) & 0x10) != 0) {
    FUN_005c2de0(pfVar1,*(int *)(param_1 + 0x10),param_1 + 0x990,param_3,param_1 + 0x88c,
                 param_1 + 0x8a4,param_1 + 0x898,*param_2);
  }
  fVar5 = g_flOne;
  if ((*(byte *)(*(int *)(param_1 + 0x10) + 0x1e4) & 0x40) != 0) {
    pfVar2 = (float *)(param_1 + 0x844);
    FUN_0076e240(local_28,pfVar2,(float *)(param_1 + 0x850));
    FUN_0099b8b0(pfVar2,local_28);
    cVar4 = FUN_005c2030(*(undefined4 *)(param_1 + 4),pfVar1,&local_10,
                         *(undefined4 *)(param_1 + 0x10),param_1 + 0x9f0,param_3,param_1 + 0x88c,
                         param_1 + 0x8a4,param_1 + 0x898,*param_2);
    fVar3 = g_flLevelUpUiBase_Inferred;
    fVar5 = g_flOne;
    if ((cVar4 != '\0') && ((*(byte *)(param_1 + 0x989) & 8) == 0)) {
      *(undefined1 *)(param_1 + 0x7f9) = 1;
      return;
    }
    fVar6 = (local_8 * local_c - local_4 * local_10) * g_flLevelUpUiBase_Inferred;
    fVar7 = g_flOne - (local_10 * local_10 + local_c * local_c) * g_flLevelUpUiBase_Inferred;
    *pfVar2 = (local_8 * local_10 + local_4 * local_c) * g_flLevelUpUiBase_Inferred;
    *(float *)(param_1 + 0x848) = fVar6;
    *(float *)(param_1 + 0x850) = fVar5 - (local_8 * local_8 + local_c * local_c) * fVar3;
    *(float *)(param_1 + 0x84c) = fVar7;
    *(float *)(param_1 + 0x854) = (local_4 * local_8 + local_c * local_10) * fVar3;
    *(float *)(param_1 + 0x858) = (local_8 * local_10 - local_4 * local_c) * fVar3;
  }
  if ((*(char *)(param_1 + 0x7fd) != '\0') && (*(char *)(param_1 + 0x7fe) == '\0')) {
    fVar3 = *param_2;
    *pfVar1 = *pfVar1 + *(float *)(param_1 + 0x8b0) * fVar3;
    *(float *)(param_1 + 0x83c) = *(float *)(param_1 + 0x83c) + *(float *)(param_1 + 0x8b4) * fVar3;
    *(float *)(param_1 + 0x840) = *(float *)(param_1 + 0x840) + *(float *)(param_1 + 0x8b8) * fVar3;
  }
  fVar5 = fVar5 / *param_2;
  *(float *)(param_1 + 0x85c) = (*pfVar1 - local_1c) * fVar5;
  *(float *)(param_1 + 0x860) = (*(float *)(param_1 + 0x83c) - local_18) * fVar5;
  *(float *)(param_1 + 0x864) = (*(float *)(param_1 + 0x840) - local_14) * fVar5;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
