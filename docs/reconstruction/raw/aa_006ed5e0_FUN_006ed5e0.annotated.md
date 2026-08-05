# Annotated low-level: FUN_006ed5e0

| Field | Value |
|---|---|
| Stable ID | `aa_006ed5e0` |
| VA | `0x006ed5e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ed5e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006ed5e0(void)

{
  undefined1 *local_10;
  code *local_c;
  code *local_8;
  code *local_4;
  
  local_10 = &LAB_006ed5a0;
  local_c = FUN_006ecf40;
  local_8 = FUN_006ecf80;
  local_4 = FUN_006ecfc0;
  FUN_006cb390(&local_10,0xffffffff,9);
  local_10 = &LAB_006ed410;
  local_c = FUN_006ecdb0;
  local_8 = FUN_006ec7f0;
  local_4 = FUN_006ecad0;
  FUN_006cb390(&local_10,9,0xffffffff);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
