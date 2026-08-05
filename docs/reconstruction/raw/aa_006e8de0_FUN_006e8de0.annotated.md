# Annotated low-level: FUN_006e8de0

| Field | Value |
|---|---|
| Stable ID | `aa_006e8de0` |
| VA | `0x006e8de0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006e8de0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006e8de0(void)

{
  code *local_10;
  code *local_c;
  code *local_8;
  code *local_4;
  
  local_10 = FUN_006e8d10;
  local_c = FUN_006e8800;
  local_8 = FUN_006e8840;
  local_4 = FUN_006e89f0;
  FUN_006cb390(&local_10,0xffffffff,0x15);
  local_10 = FUN_006e8920;
  local_c = FUN_006e86b0;
  local_8 = FUN_006e8560;
  local_4 = FUN_006e8400;
  FUN_006cb390(&local_10,0x15,0xffffffff);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
