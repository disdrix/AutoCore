# Annotated low-level: FUN_0064cce0

| Field | Value |
|---|---|
| Stable ID | `aa_0064cce0` |
| VA | `0x0064cce0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064cce0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0064cce0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  iVar3 = param_2;
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 != *(int *)(param_1 + 4)) {
    if (iVar1 == 0) {
      return;
    }
    for (iVar2 = *(int *)(iVar1 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
      iVar1 = iVar2;
    }
    if (*(int *)(iVar1 + 0x20) == 0) {
      return;
    }
    pcVar4 = (char *)FUN_0064b270(&param_2,0x1000);
    if (*pcVar4 == '\0') {
      return;
    }
  }
  *(undefined4 *)(iVar3 + 0xc) = 1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
