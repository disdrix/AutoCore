# Annotated low-level: FUN_0094dba0

| Field | Value |
|---|---|
| Stable ID | `aa_0094dba0` |
| VA | `0x0094dba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0094dba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0094dba0(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char *_Str;
  undefined4 local_c;
  undefined1 local_8;
  int local_4;
  
  local_c = 0x9021;
  _Str = strtok((char *)0x0,param_3);
  local_8 = 0;
  if (_Str == (char *)0x0) {
    local_4 = -1;
  }
  else {
    local_4 = atoi(_Str);
  }
  if (*(int *)(param_1 + 0xc7c) != 0) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0xc7c) + 8))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(param_1 + 0xc7c) + 0x18))(0xffffffff,&local_c,0xc,0);
    }
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
