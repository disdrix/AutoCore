# Annotated low-level: FUN_008bce40

| Field | Value |
|---|---|
| Stable ID | `aa_008bce40` |
| VA | `0x008bce40` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bce40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * FUN_008bce40(int *param_1)

{
  char cVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b683b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = (int)&PTR_FUN_00a45e94;
  param_1[0x13f] = 3;
  param_1[0x140] = 2;
  param_1[0x146] = 0;
  param_1[0x147] = 0;
  param_1[0x149] = 0;
  param_1[0x148] = 0;
  *(undefined1 *)(param_1 + 0x143) = 0;
  param_1[0x144] = 0;
  *(undefined1 *)(param_1 + 0x145) = 0;
  NDUIWindow_ReloadInterface("i_d_kb.xml");
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar1 != '\0') {
    *(undefined1 *)(param_1 + 0x145) = 0;
    FUN_008bc5c0();
  }
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
