# Annotated low-level: FUN_0040ddf0

| Field | Value |
|---|---|
| Stable ID | `aa_0040ddf0` |
| VA | `0x0040ddf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040ddf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __fastcall FUN_0040ddf0(int param_1)

{
  int iVar1;
  
  iVar1 = (int)*(short *)(param_1 + 0x140);
  if (199 < *(short *)(param_1 + 0x140)) {
    iVar1 = 200;
  }
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
