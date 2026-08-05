# Annotated low-level: FUN_006eed60

| Field | Value |
|---|---|
| Stable ID | `aa_006eed60` |
| VA | `0x006eed60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006eed60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006eed60(void)

{
  undefined1 *local_10;
  code *local_c;
  code *local_8;
  code *local_4;
  
  local_10 = &LAB_006eeac0;
  local_c = (code *)&LAB_006ee880;
  local_8 = FUN_006ee8c0;
  local_4 = FUN_006eeb00;
  FUN_006cb390(&local_10,0xffffffff,0x14);
  local_10 = &LAB_006ee800;
  local_c = FUN_006ee5c0;
  local_8 = FUN_006ee680;
  local_4 = FUN_006ee740;
  FUN_006cb390(&local_10,0x14,0xffffffff);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
