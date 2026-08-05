# Annotated low-level: FUN_006c2ff0

| Field | Value |
|---|---|
| Stable ID | `aa_006c2ff0` |
| VA | `0x006c2ff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006c2ff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006c2ff0(int param_1,int param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  undefined4 *puVar8;
  
  fVar1 = *(float *)(param_1 + 0x18);
  fVar2 = *(float *)(param_2 + 0x14);
  fVar3 = *(float *)(param_1 + 0x10);
  fVar4 = *(float *)(param_2 + 8);
  iVar7 = *param_3;
  fVar5 = *(float *)(param_1 + 0x14);
  fVar6 = *(float *)(param_2 + 8);
  puVar8 = (undefined4 *)param_3[1];
  puVar8[3] = *(undefined4 *)(param_1 + 0x1c);
  puVar8[1] = fVar3 * fVar4;
  *puVar8 = 0x41004;
  puVar8[2] = fVar5 * fVar6;
  *param_3 = iVar7 + 0x20;
  param_3[1] = (int)(puVar8 + 4);
  *(float *)(iVar7 + 0x1c) = fVar1 * fVar2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
