# Annotated low-level: Client_RecvLoginCallback_11

| Field | Value |
|---|---|
| Stable ID | `aa_00821a90` |
| VA | `0x00821a90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00821a90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void Client_RecvLoginCallback_11(void)

{
  OutputDebugStringA("RecvSCCheckReq\n");
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
