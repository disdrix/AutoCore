# Annotated low-level: FUN_005ebc50

| Field | Value |
|---|---|
| Stable ID | `aa_005ebc50` |
| VA | `0x005ebc50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ebc50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005ebc50(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc4) + -1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xcc);
  if (-1 < iVar3) {
    do {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc0) + iVar3 * 8);
      (**(code **)(*(int *)*puVar1 + 8))(param_1 + 0xc,puVar1[1],uVar2,param_2);
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
