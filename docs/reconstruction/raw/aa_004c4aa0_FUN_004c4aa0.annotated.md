# Annotated low-level: FUN_004c4aa0

| Field | Value |
|---|---|
| Stable ID | `aa_004c4aa0` |
| VA | `0x004c4aa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c4aa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_004c4aa0(int param_1)

{
  float fVar1;
  int iVar2;
  uint3 uVar3;
  float fVar4;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
  fVar1 = *(float *)(iVar2 + 100 + param_1);
  iVar2 = (**(code **)(*(int *)(iVar2 + param_1 + 4) + 0x244))();
  fVar4 = (float)iVar2 * (float)_DAT_00aaa6e0;
  if (g_flZero <= fVar4) {
    fVar4 = fVar4 + g_flMissionXpRoundBias;
  }
  else {
    fVar4 = fVar4 - g_flMissionXpRoundBias;
  }
  uVar3 = (uint3)((uint)(int)fVar4 >> 8);
  if (fVar1 < (float)(int)fVar4) {
    return (uint)uVar3 << 8;
  }
  return CONCAT31(uVar3,*(undefined1 *)(param_1 + 0x309));
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
