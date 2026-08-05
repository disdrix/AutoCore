# Annotated low-level: FUN_007abe20

| Field | Value |
|---|---|
| Stable ID | `aa_007abe20` |
| VA | `0x007abe20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007abe20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007abe20(int *param_1)

{
  undefined4 *puVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  local_c = 0;
  *(undefined1 *)((int)param_1 + 0xcf) = 1;
  if (param_1[0xa5] == 0) {
    local_10 = 0;
  }
  else {
    puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x140))(local_8,1);
    local_10 = *puVar1;
    local_c = puVar1[1];
  }
  (**(code **)(*param_1 + 0x2cc))(&local_10);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
