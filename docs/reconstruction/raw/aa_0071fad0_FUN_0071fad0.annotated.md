# Annotated low-level: FUN_0071fad0

| Field | Value |
|---|---|
| Stable ID | `aa_0071fad0` |
| VA | `0x0071fad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071fad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0071fad0(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (*(int *)(in_EAX + 0x14) != 0) {
    uVar1 = FUN_0071f0f0();
    return uVar1;
  }
  return 0x80004005;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
