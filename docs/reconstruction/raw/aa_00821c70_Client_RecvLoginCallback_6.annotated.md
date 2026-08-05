# Annotated low-level: Client_RecvLoginCallback_6

| Field | Value |
|---|---|
| Stable ID | `aa_00821c70` |
| VA | `0x00821c70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00821c70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void Client_RecvLoginCallback_6(undefined1 param_1)

{
  if (((DAT_00d1b77c != 0) && (DAT_00d1b780 != (int *)0x0)) && (*DAT_00d1b780 == DAT_00d1b77c)) {
    OutputDebugStringA("RecvServerFail\n");
    FUN_007a4480(1,"RecvServerFail: code(%d)",param_1);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
