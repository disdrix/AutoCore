# Annotated low-level: Client_RecvLoginCallback_9

| Field | Value |
|---|---|
| Stable ID | `aa_008226b0` |
| VA | `0x008226b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008226b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void Client_RecvLoginCallback_9(void)

{
  if (((DAT_00d1b77c != 0) && (DAT_00d1b780 != (int *)0x0)) && (*DAT_00d1b780 == DAT_00d1b77c)) {
    OutputDebugStringA("RecvAccountKicked\n");
    FUN_00944b20();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
