# Annotated low-level: FUN_0067bac0

| Field | Value |
|---|---|
| Stable ID | `aa_0067bac0` |
| VA | `0x0067bac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0067bac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_0067bac0(SOCKET *param_1,byte param_2)

{
  int iVar1;
  
  _param_2 = (uint)param_2;
  iVar1 = ioctlsocket(*param_1,-0x7ffb9982,(u_long *)&param_2);
  return -(uint)(iVar1 != 0);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
