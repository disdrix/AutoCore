# Annotated low-level: FUN_0055ecb0

| Field | Value |
|---|---|
| Stable ID | `aa_0055ecb0` |
| VA | `0x0055ecb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0055ecb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0055ecb0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (0 < *(int *)(param_1 + 0x10c)) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x108) + iVar3 * 4) + 0x44);
      if ((iVar1 != 0) && (*(char *)(iVar1 + 0x29) != '\0')) {
        FUN_0055eb10(iVar1);
      }
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x108) + iVar3 * 4);
      *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;
      if (*(short *)((int)puVar2 + 6) == 0) {
        (**(code **)*puVar2)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x10c));
  }
  *(undefined4 *)(param_1 + 0x10c) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
