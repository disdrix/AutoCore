# Annotated low-level: FUN_0059fee0

| Field | Value |
|---|---|
| Stable ID | `aa_0059fee0` |
| VA | `0x0059fee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0059fee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0059fee0(int param_1,undefined4 param_2)

{
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00975720(param_2);
  param_2 = *(undefined4 *)(*(int *)(param_1 + 0x1a8) + 0xa8);
  BitStream_writeBits(0x20,&param_2);
  param_2 = *(undefined4 *)(param_1 + 0x250);
  BitStream_writeBits(0x20,&param_2);
  local_8 = *(undefined4 *)(param_1 + 600);
  local_4 = *(undefined4 *)(param_1 + 0x25c);
  BitStream_writeBits(0x40,&local_8);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
