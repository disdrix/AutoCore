# Annotated low-level: thunk_FUN_0076c4d0

| Field | Value |
|---|---|
| Stable ID | `aa_0076c5c0` |
| VA | `0x0076c5c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0076c5c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall thunk_FUN_0076c4d0(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = rdtsc();
  *(int *)(param_1 + 8) = (int)uVar1;
  *(int *)(param_1 + 0xc) = (int)((ulonglong)uVar1 >> 0x20);
  *(undefined1 *)(param_1 + 0x18) = 1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
