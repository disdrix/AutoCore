# Annotated low-level: FUN_004cd9a0

| Field | Value |
|---|---|
| Stable ID | `aa_004cd9a0` |
| VA | `0x004cd9a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cd9a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004cd9a0(int param_1,int *param_2)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a1ecc;
  local_c = ExceptionList;
  if (0x22 < *(int *)(param_1 + 0x8c)) {
    ExceptionList = &local_c;
    (**(code **)(*param_2 + 0x14))(&param_2,1);
    if ((char)param_2 != '\0') {
      pvVar2 = operator_new(0x30);
      uStack_4 = 0;
      if (pvVar2 == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_005b3f60();
      }
      uStack_4 = 0xffffffff;
      *(undefined4 *)(param_1 + 0xe4fc) = uVar3;
      FUN_005b42f0(piVar1,*(undefined4 *)(param_1 + 0x8c));
    }
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
