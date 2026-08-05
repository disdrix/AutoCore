# Annotated low-level: FUN_0068eca0

| Field | Value |
|---|---|
| Stable ID | `aa_0068eca0` |
| VA | `0x0068eca0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0068eca0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0068eca0(undefined4 *param_1,float param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_24 [36];
  
  fcos((float10)param_2 * (float10)DAT_009d9908);
  fsin((float10)(float)((float10)param_2 * (float10)DAT_009d9908));
  puVar1 = (undefined4 *)FUN_0068ea90(local_24,param_1);
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *puVar1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
