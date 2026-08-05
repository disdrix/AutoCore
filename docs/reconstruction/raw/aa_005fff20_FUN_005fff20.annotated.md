# Annotated low-level: FUN_005fff20

| Field | Value |
|---|---|
| Stable ID | `aa_005fff20` |
| VA | `0x005fff20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fff20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005fff20(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_EAX;
  int iVar4;
  
  iVar3 = in_EAX[1];
  while (iVar3 = iVar3 + -1, -1 < iVar3) {
    if ((*(int *)(*in_EAX + iVar3 * 4) == 0) &&
       (in_EAX[1] = in_EAX[1] + -1, iVar4 = iVar3, iVar3 < in_EAX[1])) {
      do {
        iVar2 = iVar4 * 4;
        iVar1 = iVar4 * 4;
        iVar4 = iVar4 + 1;
        *(undefined4 *)(*in_EAX + iVar1) = *(undefined4 *)(*in_EAX + 4 + iVar2);
      } while (iVar4 < in_EAX[1]);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
