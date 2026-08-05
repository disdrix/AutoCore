# Annotated low-level: FUN_0099caa0

| Field | Value |
|---|---|
| Stable ID | `aa_0099caa0` |
| VA | `0x0099caa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0099caa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall
FUN_0099caa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  
  FUN_0071e6e0(param_3,param_4,param_6,param_7,param_2,param_1,in_EAX);
  *unaff_ESI = &PTR_FUN_00aa98fc;
  puVar2 = unaff_ESI + 0x94;
  for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
