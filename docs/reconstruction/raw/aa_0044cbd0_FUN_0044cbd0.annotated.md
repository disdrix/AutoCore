# Annotated low-level: FUN_0044cbd0

| Field | Value |
|---|---|
| Stable ID | `aa_0044cbd0` |
| VA | `0x0044cbd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0044cbd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_0044cbd0(undefined4 param_1)

{
  undefined1 *in_EAX;
  uint uVar1;
  undefined4 *unaff_ESI;
  undefined4 local_4;
  
  if (unaff_ESI[7] == 0) {
    local_4 = CONCAT31((int3)((uint)param_1 >> 8),*in_EAX);
    uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&local_4,1);
    unaff_ESI[1] = unaff_ESI[1] | uVar1;
    return unaff_ESI[1];
  }
  local_4 = param_1;
  uVar1 = FUN_00767160(&DAT_00a9d718,*in_EAX);
  unaff_ESI[1] = unaff_ESI[1] | uVar1;
  unaff_ESI[8] = 0;
  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&DAT_00a97b84,2);
  unaff_ESI[1] = unaff_ESI[1] | uVar1;
  return unaff_ESI[1];
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
