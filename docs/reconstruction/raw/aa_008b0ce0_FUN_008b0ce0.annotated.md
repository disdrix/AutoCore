# Annotated low-level: FUN_008b0ce0

| Field | Value |
|---|---|
| Stable ID | `aa_008b0ce0` |
| VA | `0x008b0ce0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008b0ce0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * FUN_008b0ce0(int *param_1)

{
  char cVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b650c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = (int)&PTR_FUN_00a49e2c;
  *(undefined1 *)((int)param_1 + 0x56e) = 0xff;
  *(undefined1 *)((int)param_1 + 0x56d) = 0xff;
  *(undefined1 *)(param_1 + 0x15b) = 0xff;
  *(undefined1 *)((int)param_1 + 0x56f) = 0xff;
  *(undefined1 *)((int)param_1 + 0x572) = 0xff;
  *(undefined1 *)((int)param_1 + 0x571) = 0xff;
  *(undefined1 *)(param_1 + 0x15c) = 0xff;
  *(undefined1 *)((int)param_1 + 0x573) = 0xff;
  *(undefined1 *)((int)param_1 + 0x576) = 0xff;
  *(undefined1 *)((int)param_1 + 0x575) = 0xff;
  *(undefined1 *)(param_1 + 0x15d) = 0xff;
  *(undefined1 *)((int)param_1 + 0x577) = 0xff;
  *(undefined1 *)((int)param_1 + 0x57a) = 0xff;
  *(undefined1 *)((int)param_1 + 0x579) = 0xff;
  *(undefined1 *)(param_1 + 0x15e) = 0xff;
  *(undefined1 *)((int)param_1 + 0x57b) = 0xff;
  param_1[0x152] = 0;
  param_1[0x15d] = DAT_00afdf0c;
  param_1[0x15c] = DAT_00afdf0c;
  param_1[0x15b] = DAT_00afdf0c;
  param_1[0x15e] = DAT_00afdf0c;
  param_1[0x143] = 0x5e;
  param_1[0x144] = 0x5e;
  param_1[0x145] = 0x5e;
  param_1[0x146] = 0;
  param_1[0x147] = 0;
  param_1[0x148] = 0;
  param_1[0x149] = 0;
  param_1[0x14a] = 0;
  param_1[0x14b] = 0;
  param_1[0x14c] = 0;
  param_1[0x14d] = 0;
  param_1[0x14e] = 0;
  param_1[0x14f] = 0;
  param_1[0x150] = 0;
  param_1[0x151] = 0;
  param_1[0x153] = 0;
  param_1[0x154] = 0;
  param_1[0x155] = 0;
  param_1[0x156] = 0;
  param_1[0x15f] = 0;
  param_1[0x160] = 0;
  param_1[0x161] = 0;
  param_1[0x162] = 0;
  DAT_00af92d8 = 0xffffffff;
  NDUIWindow_ReloadInterface("i_d_notify.xml");
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar1 != '\0') {
    FUN_008af180(1);
    if (param_1[0xac] != 0) {
      FUN_008a0370();
    }
  }
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
