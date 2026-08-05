# Annotated low-level: FUN_0067bce0

| Field | Value |
|---|---|
| Stable ID | `aa_0067bce0` |
| VA | `0x0067bce0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0067bce0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __fastcall FUN_0067bce0(SOCKET *param_1)

{
  int iVar1;
  SOCKET *local_4;
  
  local_4 = param_1;
  iVar1 = ioctlsocket(*param_1,0x4004667f,(u_long *)&local_4);
  if (iVar1 == -1) {
    if (*param_1 != 0xffffffff) {
      closesocket(*param_1);
      *param_1 = 0xffffffff;
    }
    *param_1 = 0xffffffff;
  }
  return ~-(uint)(iVar1 != 0) & (uint)local_4;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
