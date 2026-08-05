# Annotated low-level: FUN_0086efc0

| Field | Value |
|---|---|
| Stable ID | `aa_0086efc0` |
| VA | `0x0086efc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0086efc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0086efc0(void)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  undefined4 local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  
  FUN_0086ed60();
  local_20[0] = 0x9016;
  iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);
  local_18 = *(undefined4 *)(iVar1 + 0x164 + DAT_00d1b6d8);
  local_14 = *(undefined4 *)(iVar1 + 0x168 + DAT_00d1b6d8);
  local_8 = *(undefined1 *)(in_EAX + 0x510);
  local_10 = 0xffffffff;
  local_c = 0xffffffff;
  if (DAT_00d1b4bc != (int *)0x0) {
    cVar2 = (**(code **)(*DAT_00d1b4bc + 8))();
    if (cVar2 != '\0') {
      (**(code **)(*DAT_00d1b4bc + 0x18))(0xffffffff,local_20,0x20,0);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
