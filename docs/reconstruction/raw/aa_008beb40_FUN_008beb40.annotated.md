# Annotated low-level: FUN_008beb40

| Field | Value |
|---|---|
| Stable ID | `aa_008beb40` |
| VA | `0x008beb40` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008beb40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_008beb40(ushort param_1)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  
  if (*(int *)(in_EAX + 0x52c) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_EAX + 0x530) - *(int *)(in_EAX + 0x52c) >> 3;
  }
  iVar1 = *(int *)(in_EAX + 0x52c);
  if (uVar2 <= param_1) {
    if ((iVar1 != 0) && (*(int *)(in_EAX + 0x530) - iVar1 >> 3 != 0)) {
      if (iVar1 == 0) {
        return uRamfffffffc;
      }
      return *(undefined4 *)
              (*(int *)(in_EAX + 0x52c) + (*(int *)(in_EAX + 0x530) - iVar1 >> 3) * 8 + -4);
    }
    return 0;
  }
  return *(undefined4 *)(iVar1 + (uint)param_1 * 8 + 4);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
