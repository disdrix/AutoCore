# Annotated low-level: Vehicle_CreateWeaponTrackAction

| Field | Value |
|---|---|
| Stable ID | `aa_005a4f60` |
| VA | `0x005a4f60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005a4f60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_CreateWeaponTrackAction — separate timed action (period = 30 ms) for weapon
   tracking / secondary systems. NOT the combat pool.
   
   Countdown special -1000; period +0x08 = 0x1E (30). */

undefined4 * __thiscall Vehicle_CreateWeaponTrackAction(undefined4 *param_1,int param_2)

{
  void *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a6358;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CVOGHBBase_ctor(param_1);
  local_4 = 0;
  *param_1 = &PTR_FUN_009d81b8;
  CVOGHBBase_SetPeriodAndCounter(param_1,-1000,true);
  param_1[2] = 0x1e;
  param_1[7] = 4;
  if (param_2 == 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
    FUN_005083f0(1,1);
    ExceptionList = unaff_ESI;
    return param_1;
  }
  param_1[9] = param_2;
  CVOGHBBase_AttachOwnerObject(param_1,(void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2));
  if (*(int *)(*(int *)(param_1[9] + 0x260) + 4) != 0) {
    FUN_004f8430();
  }
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
