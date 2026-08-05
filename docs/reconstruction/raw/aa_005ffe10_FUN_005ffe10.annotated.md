# Annotated low-level: FUN_005ffe10

| Field | Value |
|---|---|
| Stable ID | `aa_005ffe10` |
| VA | `0x005ffe10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ffe10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005ffe10(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uStack_4;
  
  *param_1 = &PTR_FUN_009dde58;
  uStack_4 = param_1;
  uVar1 = FUN_00650190();
  FUN_0065ad10((int)&uStack_4 + 3,uVar1);
  while (uStack_4._3_1_ != '\0') {
    uVar2 = FUN_0065acb0(uVar1);
    (**(code **)(*DAT_00b05060 + 4))(uVar2);
    uVar1 = FUN_006501e0(uVar1);
    FUN_0065ad10((int)&uStack_4 + 3,uVar1);
  }
  FUN_00650420();
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
