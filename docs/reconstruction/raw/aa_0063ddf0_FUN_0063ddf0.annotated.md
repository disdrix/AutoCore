# Annotated low-level: FUN_0063ddf0

| Field | Value |
|---|---|
| Stable ID | `aa_0063ddf0` |
| VA | `0x0063ddf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0063ddf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0063ddf0(int param_1,float *param_2,float *param_3)

{
  int extraout_ECX;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  fVar3 = *param_2;
  fVar1 = *(float *)(param_1 + 0x2c) * fVar3;
  *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0xf0) * fVar1 + *(float *)(param_1 + 0x40);
  *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0xf4) * fVar1 + *(float *)(param_1 + 0x44);
  *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0xf8) * fVar1 + *(float *)(param_1 + 0x48);
  *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 0xfc) * fVar1 + *(float *)(param_1 + 0x4c);
  fVar1 = g_flOne;
  fVar4 = 0.0;
  *(float *)(param_1 + 0x40) = *param_3 * fVar3 + *(float *)(param_1 + 0x40);
  *(float *)(param_1 + 0x44) = param_3[1] * fVar3 + *(float *)(param_1 + 0x44);
  *(float *)(param_1 + 0x48) = param_3[2] * fVar3 + *(float *)(param_1 + 0x48);
  *(float *)(param_1 + 0x4c) = param_3[3] * fVar3 + *(float *)(param_1 + 0x4c);
  fVar2 = fVar1 - *(float *)(param_1 + 0x14) * fVar3;
  if (fVar2 < 0.0) {
    fVar2 = 0.0;
  }
  *(float *)(param_1 + 0x40) = fVar2 * *(float *)(param_1 + 0x40);
  *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x44) * fVar2;
  *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x48) * fVar2;
  *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 0x4c) * fVar2;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  if (*(float *)(param_1 + 0x10c) != 0.0) {
    local_14 = *param_2;
    local_20 = *(float *)(param_1 + 0x100) * local_14;
    local_1c = *(float *)(param_1 + 0x104) * local_14;
    local_18 = *(float *)(param_1 + 0x108) * local_14;
    local_14 = *(float *)(param_1 + 0x10c) * local_14;
    FUN_0063d7d0(&local_20);
    fVar1 = g_flOne;
    *(float *)(extraout_ECX + 0x10c) = fVar4;
    *(float *)(extraout_ECX + 0x108) = fVar4;
    *(float *)(extraout_ECX + 0x104) = fVar4;
    *(float *)(extraout_ECX + 0x100) = fVar4;
    param_1 = extraout_ECX;
  }
  fVar1 = fVar1 - *(float *)(param_1 + 0x18) * fVar3;
  if (fVar1 < fVar4) {
    fVar1 = fVar4;
  }
  *(float *)(param_1 + 0x50) = *(float *)(param_1 + 0x50) * fVar1;
  *(float *)(param_1 + 0x54) = *(float *)(param_1 + 0x54) * fVar1;
  *(float *)(param_1 + 0x58) = *(float *)(param_1 + 0x58) * fVar1;
  *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x5c) * fVar1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
