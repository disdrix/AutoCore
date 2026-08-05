# Annotated low-level: FUN_0084fbd0

| Field | Value |
|---|---|
| Stable ID | `aa_0084fbd0` |
| VA | `0x0084fbd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0084fbd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0084fbd0(void)

{
  int in_EAX;
  float in_XMM0_Da;
  float in_XMM1_Da;
  float fVar1;
  
  fVar1 = in_XMM0_Da;
  if (in_XMM0_Da <= in_XMM1_Da) {
    fVar1 = in_XMM1_Da;
  }
  DAT_00af9328 = in_XMM0_Da;
  DAT_00af932c = in_XMM1_Da;
  *(float *)(in_EAX + 0x500) = fVar1;
  if (in_XMM1_Da <= in_XMM0_Da) {
    in_XMM0_Da = in_XMM1_Da;
  }
  _DAT_00af9330 = (in_XMM0_Da * DAT_00a0f298) / *(float *)(in_EAX + 0x504);
  if (_DAT_00af9330 < g_flOne) {
    _DAT_00af9330 = g_flOne;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
