# Annotated low-level: FUN_0081fbe0

| Field | Value |
|---|---|
| Stable ID | `aa_0081fbe0` |
| VA | `0x0081fbe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0081fbe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0081fbe0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 0x548) = 0;
  *(undefined4 *)(param_1 + 0xe70) = 0;
  *(undefined4 *)(param_1 + 0xe74) = 0;
  *(undefined4 *)(param_1 + 0xe78) = 0;
  *(undefined4 *)(param_1 + 0xe7c) = 0;
  *(undefined4 *)(param_1 + 0xe80) = 0;
  *(undefined4 *)(param_1 + 0xe84) = 0;
  *(undefined4 *)(param_1 + 0xe88) = 0;
  *(undefined4 *)(param_1 + 0xebc) = 0;
  *(undefined4 *)(param_1 + 0xec0) = 0;
  *(undefined4 *)(param_1 + 0xecc) = 0;
  *(undefined4 *)(param_1 + 0xed0) = 0;
  *(undefined4 *)(param_1 + 0xed4) = 0;
  *(undefined4 *)(param_1 + 0xed8) = 0;
  *(undefined4 *)(param_1 + 0xedc) = 0;
  *(undefined4 *)(param_1 + 0xee0) = 0;
  *(undefined4 *)(param_1 + 0xeb8) = 0;
  puVar2 = (undefined4 *)(param_1 + 0xeec);
  iVar1 = 9;
  do {
    puVar2[-2] = 0;
    if ((void *)*puVar2 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar2);
    }
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2 = puVar2 + 5;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(param_1 + 0xec8) = 0;
  *(undefined4 *)(param_1 + 0xeb0) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
