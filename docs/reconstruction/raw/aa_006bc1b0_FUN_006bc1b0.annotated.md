# Annotated low-level: FUN_006bc1b0

| Field | Value |
|---|---|
| Stable ID | `aa_006bc1b0` |
| VA | `0x006bc1b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bc1b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_006bc1b0(int param_1)

{
  undefined4 uVar1;
  
  if (**(ushort **)(param_1 + 0x14) < **(ushort **)(param_1 + 0x10)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    *(ushort **)(param_1 + 0x10) = *(ushort **)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = uVar1;
  }
  if (**(ushort **)(param_1 + 0x18) < **(ushort **)(param_1 + 0x14)) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18) = uVar1;
  }
  if (**(ushort **)(param_1 + 0x14) < **(ushort **)(param_1 + 0x10)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    *(ushort **)(param_1 + 0x10) = *(ushort **)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = uVar1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
