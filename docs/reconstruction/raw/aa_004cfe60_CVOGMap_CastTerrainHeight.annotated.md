# Annotated low-level: CVOGMap_CastTerrainHeight

| Field | Value |
|---|---|
| Stable ID | `aa_004cfe60` |
| VA | `0x004cfe60` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cfe60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Terrain height raycast used by CreateCreature / FindTerrainHeight.
   Casts down from (x,z,yStart) against map collision. */

float10 __thiscall
CVOGMap_CastTerrainHeight
          (int param_1,undefined4 param_2,undefined4 param_3,float param_4,char param_5)

{
  float10 fVar1;
  undefined4 local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50;
  int local_4c;
  undefined1 local_40 [20];
  float local_2c;
  int local_20;
  
  if (*(int *)(param_1 + 0xe4e0) == 0) {
    return (float10)g_flZero;
  }
  fVar1 = (float10)FUN_005a58c0(param_2,param_3);
  local_5c = (float)fVar1 + DAT_00a0f718;
  local_2c = g_flOne;
  local_6c = param_4;
  local_4c = (-(uint)(param_5 != '\0') & 0xd) + 5;
  local_20 = 0;
  local_70 = param_2;
  local_68 = param_3;
  local_64 = 0;
  local_50 = 0;
  local_60 = param_2;
  local_58 = param_3;
  local_54 = 0;
  FUN_0055e530(&local_70,local_40);
  if (local_20 != 0) {
    return (float10)(local_6c * (g_flOne - local_2c) + local_5c * local_2c);
  }
  return (float10)(float)fVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
