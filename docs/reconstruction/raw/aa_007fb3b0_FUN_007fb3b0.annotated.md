# Annotated low-level: FUN_007fb3b0

| Field | Value |
|---|---|
| Stable ID | `aa_007fb3b0` |
| VA | `0x007fb3b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fb3b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_007fb3b0(float param_1)

{
  bool bVar1;
  uint in_EAX;
  uint uVar2;
  float in_XMM1_Da;
  float local_4;
  
  if (*(code **)(in_EAX + 0xdd4) != (code *)0x0) {
    bVar1 = false;
    local_4 = g_flOne;
    if (DAT_00aaa688 <= in_XMM1_Da) {
      if (DAT_00a0f6a4 <= in_XMM1_Da) {
        bVar1 = true;
      }
      else {
        local_4 = DAT_00a0f71c;
      }
    }
    else {
      local_4 = g_flOverheatCoolFrac;
    }
    switch(param_1) {
    case 2.8026e-45:
      local_4 = local_4 * _DAT_00aaa684;
      break;
    case 4.2039e-45:
      local_4 = local_4 * DAT_00a0f704;
      break;
    case 5.60519e-45:
      local_4 = local_4 * DAT_00aaa680;
      break;
    case 7.00649e-45:
      local_4 = local_4 * DAT_00a0f734;
      break;
    case 8.40779e-45:
      local_4 = local_4 * DAT_00a0f298;
    }
    param_1 = local_4;
    if (!bVar1) {
      param_1 = 0.0;
    }
    uVar2 = (**(code **)(in_EAX + 0xdd4))(param_1,local_4,local_4 * g_flLevelUpUiBase_Inferred);
    return uVar2;
  }
  return in_EAX & 0xffffff00;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
