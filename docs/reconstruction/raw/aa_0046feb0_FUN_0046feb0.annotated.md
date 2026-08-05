# Annotated low-level: FUN_0046feb0

| Field | Value |
|---|---|
| Stable ID | `aa_0046feb0` |
| VA | `0x0046feb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0046feb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046feb0(double param_1)

{
  int in_EAX;
  int unaff_EDI;
  undefined4 local_c;
  
  if ((in_EAX != 0) && (unaff_EDI != 0)) {
    if (_DAT_00aaa610 < param_1) {
      FUN_00476d60();
      param_1 = _DAT_00aaa610;
    }
    *(uint *)(unaff_EDI + 8) = *(uint *)(unaff_EDI + 8) | 1;
    *(float *)(unaff_EDI + 0x28) = (float)param_1;
    local_c = (undefined4)(longlong)ROUND(_DAT_00aaa5e8 * param_1 + _DAT_00aaa5e0);
    *(undefined4 *)(unaff_EDI + 0xfc) = local_c;
    if (param_1 == _DAT_00aaa608) {
      FUN_00476d60();
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
