# Annotated low-level: FUN_006cb7f0

| Field | Value |
|---|---|
| Stable ID | `aa_006cb7f0` |
| VA | `0x006cb7f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006cb7f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006cb7f0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *local_8;
  
  local_8 = (undefined1 *)((uint)local_8 & 0xffffff00);
  (**(code **)(*param_1 + 0x24))(param_3,0);
  *local_8 = 0xf0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
