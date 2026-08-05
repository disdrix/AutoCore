# Annotated low-level: FUN_006ed2f0

| Field | Value |
|---|---|
| Stable ID | `aa_006ed2f0` |
| VA | `0x006ed2f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ed2f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_006ed2f0(undefined4 *param_1)

{
  if (-1 < (int)param_1[5]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[3],param_1[5] << 3,0x12);
  }
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
