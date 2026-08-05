# Annotated low-level: FUN_007fb4d0

| Field | Value |
|---|---|
| Stable ID | `aa_007fb4d0` |
| VA | `0x007fb4d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fb4d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_007fb4d0(int param_1,int param_2,char param_3)

{
  int in_EAX;
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  
  if (*(code **)(in_EAX + 0xdd4) == (code *)0x0) {
    return 0;
  }
  fVar2 = ((float)param_1 / (float)param_2) * DAT_00aaa690;
  if (g_flOne < fVar2) {
    fVar2 = g_flOne;
  }
  if (param_3 == '\0') {
    _param_3 = DAT_00a0f708;
    fVar3 = 0.0;
  }
  else {
    _param_3 = DAT_00aaa68c;
    fVar3 = fVar2;
  }
  uVar1 = (**(code **)(in_EAX + 0xdd4))(fVar3,fVar2,_param_3);
  return uVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
