# Annotated low-level: FUN_006cafd0

| Field | Value |
|---|---|
| Stable ID | `aa_006cafd0` |
| VA | `0x006cafd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006cafd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_006cafd0(int param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int local_4;
  
  puVar1 = (undefined4 *)(param_1 + 0x118c);
  puVar2 = (undefined1 *)(param_1 + 0x418e);
  local_4 = 0x20;
  do {
    iVar3 = 0x20;
    do {
      puVar1[-0x400] = *(undefined4 *)(param_1 + 8);
      *puVar1 = FUN_0056f570;
      puVar1[0x400] = FUN_0056f570;
      puVar1[0x800] = FUN_0056f570;
      *puVar2 = 100;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
