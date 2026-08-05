# Annotated low-level: FUN_005caf50

| Field | Value |
|---|---|
| Stable ID | `aa_005caf50` |
| VA | `0x005caf50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005caf50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005caf50(int param_1)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  FUN_005c9710(&local_8);
  FUN_005c9780(&local_4);
  FUN_005ca540(local_8,1);
  FUN_005ca5e0(local_4,1);
  *(undefined1 *)(param_1 + -0x1f) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
