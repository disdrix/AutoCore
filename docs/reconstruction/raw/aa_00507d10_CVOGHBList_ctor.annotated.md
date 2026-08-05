# Annotated low-level: CVOGHBList_ctor

| Field | Value |
|---|---|
| Stable ID | `aa_00507d10` |
| VA | `0x00507d10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00507d10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall CVOGHBList_ctor(undefined4 *param_1)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  
  *param_1 = &PTR_FUN_009cda94;
  param_1[9] = 0x80000000;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xc] = 0x80000000;
  param_1[10] = 0;
  param_1[0xb] = 0;
  uVar2 = param_1[9] & 0x7fffffff;
  if (uVar2 < 1000) {
    iVar3 = uVar2 * 2;
    if (uVar2 == 500 || iVar3 < 1000) {
      iVar3 = 1000;
    }
    FUN_005b3300(param_1 + 7,iVar3,4);
  }
  uVar2 = param_1[0xc] & 0x7fffffff;
  if (uVar2 < 100) {
    iVar3 = uVar2 * 2;
    if (uVar2 == 0x32 || iVar3 < 100) {
      iVar3 = 100;
    }
    FUN_005b3300(param_1 + 10,iVar3,4);
  }
  _DAT_00b041c0 = _DAT_00b041c0 + 1;
  g_dwClientTickMs = GetTickCount();
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 1),4000);
  if ((DAT_00b041c8 == 0) && (DAT_00b041c4 != '\0')) {
    pvVar1 = operator_new(0x34);
    if (pvVar1 != (void *)0x0) {
      DAT_00b041c8 = FUN_00507ee0(4);
      return param_1;
    }
    DAT_00b041c8 = 0;
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
