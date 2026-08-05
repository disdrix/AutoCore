# Annotated low-level: FUN_0049cad0

| Field | Value |
|---|---|
| Stable ID | `aa_0049cad0` |
| VA | `0x0049cad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0049cad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0049cad0(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00b035e4;
  do {
    pvVar1 = (void *)*puVar2;
    if (pvVar1 != (void *)0x0) {
      FUN_004b99c0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0xb035fc);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
