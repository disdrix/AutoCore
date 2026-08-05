# Annotated low-level: FUN_0094dab0

| Field | Value |
|---|---|
| Stable ID | `aa_0094dab0` |
| VA | `0x0094dab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0094dab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0094dab0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  
  if ((*(int *)(in_EAX + 0xe98) != 0) &&
     (iVar1 = *(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0), iVar1 != 0)) {
    FUN_004bb970(1,*(undefined4 *)(iVar1 + 0x160),*(undefined4 *)(iVar1 + 0x164));
    FUN_00575200();
    puVar2 = *(undefined4 **)(*(int *)(in_EAX + 0xe98) + 0xcb0);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    FUN_00520330(0);
    if (*(int *)(in_EAX + 0x10a0) != 0) {
      FUN_008ea880();
      FUN_008e8b50(0xffffffff,0xffffffff,1);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
