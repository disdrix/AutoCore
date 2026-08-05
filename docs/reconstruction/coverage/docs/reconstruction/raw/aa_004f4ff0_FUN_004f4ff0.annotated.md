# Annotated low-level: FUN_004f4ff0

| Field | Value |
|---|---|
| Stable ID | `aa_004f4ff0` |
| VA | `0x004f4ff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f4ff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004f4ff0(int param_1,char param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  bVar2 = false;
  iVar5 = 0;
  do {
    piVar1 = *(int **)(*(int *)(param_1 + 0x260) + iVar5);
    if (piVar1 != (int *)0x0) {
      cVar3 = (**(code **)(*piVar1 + 0x40))();
      if (cVar3 != '\0') {
        if ((param_2 == '\0') || (*(char *)(param_1 + 0x108) == '\0')) {
          iVar4 = (**(code **)(*piVar1 + 0x5c))
                            (*(undefined4 *)
                              (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 +
                                                param_1) + 0xe4e8) + 0x1c),param_3);
          bVar2 = (bool)(bVar2 | 0 < iVar4);
        }
        else {
          FUN_0056bf70();
          bVar2 = false;
        }
      }
    }
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0xc);
  if ((!bVar2) && (param_3 == 0)) {
    *(undefined1 *)(param_1 + 0x108) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 0x108) = 1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
