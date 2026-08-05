# Annotated low-level: FUN_008e3bd0

| Field | Value |
|---|---|
| Stable ID | `aa_008e3bd0` |
| VA | `0x008e3bd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008e3bd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008e3bd0(void)

{
  int iVar1;
  int in_EAX;
  int *extraout_EAX;
  int unaff_ESI;
  int *unaff_EDI;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  if ((in_EAX != 0) && (*(int *)(*(int *)(in_EAX + 0xa8) + 0x38) == 0x1a)) {
    local_8 = *(undefined4 *)(*(int *)(in_EAX + 0xa8) + 0x34);
    Map_LowerBoundFindByIntKey((void *)(unaff_ESI + 0x7f4),local_4,&local_8,unaff_EDI);
    iVar1 = *extraout_EAX;
    *(int *)(unaff_ESI + 0x800) = iVar1;
    if (iVar1 != *(int *)(unaff_ESI + 0x7f8)) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
      if (*(int *)(*(int *)(unaff_ESI + 0x800) + 0x10) < 1) {
        FUN_0040ee20(local_4,*(int *)(unaff_ESI + 0x800));
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
