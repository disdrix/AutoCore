# Annotated low-level: FUN_0067bdf0

| Field | Value |
|---|---|
| Stable ID | `aa_0067bdf0` |
| VA | `0x0067bdf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0067bdf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_0067bdf0(SOCKET *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = setsockopt(*param_1,param_2,param_3,(char *)&param_4,4);
  return -(uint)(iVar1 != 0);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
