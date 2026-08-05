# Annotated low-level: FUN_0060bed0

| Field | Value |
|---|---|
| Stable ID | `aa_0060bed0` |
| VA | `0x0060bed0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0060bed0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __fastcall FUN_0060bed0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x14);
  do {
    if (iVar3 == 0) {
      return 0;
    }
    puVar1 = (undefined4 *)(iVar3 + 8);
    puVar2 = (undefined4 *)(iVar3 + 0x10);
    iVar3 = *(int *)(iVar3 + 0x14);
    iVar4 = FUN_0060bf10(*puVar2,*puVar1,0);
  } while (-1 < iVar4);
  return iVar4;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
