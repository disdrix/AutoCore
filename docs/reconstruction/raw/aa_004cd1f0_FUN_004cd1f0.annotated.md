# Annotated low-level: FUN_004cd1f0

| Field | Value |
|---|---|
| Stable ID | `aa_004cd1f0` |
| VA | `0x004cd1f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cd1f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004cd1f0(int param_1)

{
  if (*(undefined4 **)(param_1 + 0xe4fc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xe4fc))(1);
  }
  *(undefined4 *)(param_1 + 0xe4fc) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
