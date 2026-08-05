# Annotated low-level: FUN_0054fec0

| Field | Value |
|---|---|
| Stable ID | `aa_0054fec0` |
| VA | `0x0054fec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0054fec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0054fec0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00627be0();
  if (*(uint *)(param_1 + 0x620) == 0) {
    *(uint *)(param_1 + 0x624) = uVar1;
  }
  else {
    *(uint *)(param_1 + 0x624) = uVar1 | 4;
    if (*(char *)(param_1 + 0x148) == '\0') {
      *(uint *)(param_1 + 0x620) = *(uint *)(param_1 + 0x620) | 0x100000;
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
