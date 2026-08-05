# Annotated low-level: FUN_008cb8c0

| Field | Value |
|---|---|
| Stable ID | `aa_008cb8c0` |
| VA | `0x008cb8c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cb8c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * FUN_008cb8c0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_009b6d4c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_00a4183c;
  puVar1 = param_1 + 0x158;
  iVar2 = 0x10;
  do {
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0;
    *(undefined2 *)(puVar1 + 3) = 0;
    *(undefined1 *)(puVar1 + 5) = 0;
    *(undefined1 *)((int)puVar1 + 3) = 0;
    *(undefined1 *)((int)puVar1 + 2) = 0;
    *(undefined1 *)((int)puVar1 + 1) = 0;
    *(undefined1 *)puVar1 = 0;
    puVar1 = puVar1 + 0xf;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x13f] = 0xf;
  param_1[0x140] = 0;
  param_1[0x252] = 0;
  param_1[0x253] = 0;
  FUN_008cafd0();
  param_1[0x154] = 0xffffffff;
  param_1[0x155] = 0xffffffff;
  param_1[0x248] = 0;
  *(undefined1 *)((int)param_1 + 0xbf) = 0;
  param_1[0x156] = 0;
  param_1[0x157] = 0;
  puVar1 = param_1 + 0x15d;
  iVar2 = 0x10;
  do {
    puVar1[-4] = 0xffffffff;
    *(undefined1 *)puVar1 = 0;
    *(undefined2 *)(puVar1 + -2) = 0;
    puVar1 = puVar1 + 0xf;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  NDUIWindow_ReloadInterface("i_d_fesh.xml");
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
