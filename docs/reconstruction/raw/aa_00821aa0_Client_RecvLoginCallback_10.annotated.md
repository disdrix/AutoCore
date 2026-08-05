# Annotated low-level: Client_RecvLoginCallback_10

| Field | Value |
|---|---|
| Stable ID | `aa_00821aa0` |
| VA | `0x00821aa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00821aa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void Client_RecvLoginCallback_10(void)

{
                    /* WARNING: Could not recover jumptable at 0x00821aa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OutputDebugStringA("RecvBlockedAccountMsg\n");
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
